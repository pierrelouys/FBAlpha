// FB Alpha Deniam-16 Hardware driver module
// Based on MAME driver by Nicola Salmoria

#include "tiles_generic.h"
#include "burn_ym3812.h"
#include "msm6295.h"

static unsigned char *AllMem;
static unsigned char *MemEnd;
static unsigned char *AllRam;
static unsigned char *RamEnd;
static unsigned char *Drv68KROM;
static unsigned char *Drv68KRAM;
static unsigned char *DrvZ80ROM;
static unsigned char *DrvZ80RAM;
static unsigned char *DrvSndROM;
static unsigned char *DrvGfxROM0;
static unsigned char *DrvGfxROM1;
static unsigned char *DrvPalRAM;
static unsigned char *DrvSprRAM;
static unsigned char *DrvVidRAM;
static unsigned char *DrvTxtRAM;
static unsigned int  *DrvPalette;
static short *DrvTxtTable;
static short *DrvLayerTable;

static unsigned char DrvRecalc;

static unsigned char DrvJoy1[16];
static unsigned char DrvJoy2[16];
static unsigned char DrvJoy3[16];
static unsigned char DrvDips[1];
static unsigned char DrvReset;
static unsigned char DrvInputs[3];

static int nCyclesDone[2];

static unsigned char *soundlatch;
static unsigned char *coin_control;
static unsigned char *okibank;

static int bg_scrollx_offs;
static int bg_scrolly_offs;
static int fg_scrollx_offs;
static int fg_scrolly_offs;
static int bg_scrollx_reg;
static int bg_scrolly_reg;
static int bg_page_reg;
static int fg_scrollx_reg;
static int fg_scrolly_reg;
static int fg_page_reg;

static int nGame = 0;

static struct BurnInputInfo DrvInputList[] = {
	{"P1 Coin",		BIT_DIGITAL,	DrvJoy1 + 0,	"p1 coin"	},
	{"P1 Start",		BIT_DIGITAL,	DrvJoy1 + 4,	"p1 start"	},
	{"P1 Up",		BIT_DIGITAL,	DrvJoy2 + 5,	"p1 up"		},
	{"P1 Down",		BIT_DIGITAL,	DrvJoy2 + 4,	"p1 down"	},
	{"P1 Left",		BIT_DIGITAL,	DrvJoy2 + 7,	"p1 left"	},
	{"P1 Right",		BIT_DIGITAL,	DrvJoy2 + 6,	"p1 right"	},
	{"P1 Button 1",		BIT_DIGITAL,	DrvJoy2 + 0,	"p1 fire 1"	},
	{"P1 Button 2",		BIT_DIGITAL,	DrvJoy2 + 1,	"p1 fire 2"	},
	{"P1 Button 3",		BIT_DIGITAL,	DrvJoy2 + 2,	"p1 fire 3"	},

	{"P2 Coin",		BIT_DIGITAL,	DrvJoy1 + 1,	"p2 coin"	},
	{"P2 Start",		BIT_DIGITAL,	DrvJoy1 + 5,	"p2 start"	},
	{"P2 Up",		BIT_DIGITAL,	DrvJoy3 + 5,	"p2 up"		},
	{"P2 Down",		BIT_DIGITAL,	DrvJoy3 + 4,	"p2 down"	},
	{"P2 Left",		BIT_DIGITAL,	DrvJoy3 + 7,	"p2 left"	},
	{"P2 Right",		BIT_DIGITAL,	DrvJoy3 + 6,	"p2 right"	},
	{"P2 Button 1",		BIT_DIGITAL,	DrvJoy3 + 0,	"p2 fire 1"	},
	{"P2 Button 2",		BIT_DIGITAL,	DrvJoy3 + 1,	"p2 fire 2"	},
	{"P2 Button 3",		BIT_DIGITAL,	DrvJoy3 + 2,	"p2 fire 3"	},

	{"Reset",		BIT_DIGITAL,	&DrvReset,	"reset"		},
	{"Service",		BIT_DIGITAL,	DrvJoy1 + 3,	"service"	},
	{"Dip A",		BIT_DIPSWITCH,	DrvDips + 0,	"dip"		},
};

STDINPUTINFO(Drv);

static struct BurnDIPInfo KarianxDIPList[]=
{
	// Default Values
	{0x14, 0xff, 0xff, 0xff, NULL			},

	{0   , 0xfe, 0   ,    8, "Coinage"		},
	{0x14, 0x01, 0x07, 0x02, "3 Coins 1 Credits "	},
	{0x14, 0x01, 0x07, 0x01, "2 Coins 1 Credits "	},
	{0x14, 0x01, 0x07, 0x04, "3 Coins 2 Credits "	},
	{0x14, 0x01, 0x07, 0x07, "1 Coin  1 Credits "	},
	{0x14, 0x01, 0x07, 0x06, "2 Coins 3 Credits "	},
	{0x14, 0x01, 0x07, 0x03, "1 Coin  2 Credits "	},
	{0x14, 0x01, 0x07, 0x05, "1 Coin  3 Credits "	},
	{0x14, 0x01, 0x07, 0x00, "Free Play"		},

	{0   , 0xfe, 0   ,    4, "Difficulty"		},
	{0x14, 0x01, 0x18, 0x08, "Very Easy"		},
	{0x14, 0x01, 0x18, 0x10, "Easy"			},
	{0x14, 0x01, 0x18, 0x18, "Normal"		},
	{0x14, 0x01, 0x18, 0x00, "Hard"			},

	{0   , 0xfe, 0   ,    2, "Demo Music"		},
	{0x14, 0x01, 0x20, 0x00, "Off"			},
	{0x14, 0x01, 0x20, 0x20, "On"			},

	{0   , 0xfe, 0   ,    1, "Service Mode"		},
	{0x14, 0x01, 0x80, 0x80, "Off"			},
	{0x14, 0x01, 0x80, 0x00, "On"			},
};

STDDIPINFO(Karianx);

static struct BurnDIPInfo Logicpr2DIPList[]=
{
	// Default Values
	{0x14, 0xff, 0xff, 0xff, NULL			},

	{0   , 0xfe, 0   ,    8, "Coinage"		},
	{0x14, 0x01, 0x07, 0x02, "3 Coins 1 Credits "	},
	{0x14, 0x01, 0x07, 0x01, "2 Coins 1 Credits "	},
	{0x14, 0x01, 0x07, 0x04, "3 Coins 2 Credits "	},
	{0x14, 0x01, 0x07, 0x07, "1 Coin  1 Credits "	},
	{0x14, 0x01, 0x07, 0x06, "2 Coins 3 Credits "	},
	{0x14, 0x01, 0x07, 0x03, "1 Coin  2 Credits "	},
	{0x14, 0x01, 0x07, 0x05, "1 Coin  3 Credits "	},
	{0x14, 0x01, 0x07, 0x00, "Free Play"		},

	{0   , 0xfe, 0   ,    4, "Play Time"		},
	{0x14, 0x01, 0x18, 0x08, "Slow"			},
	{0x14, 0x01, 0x18, 0x18, "Normal"		},
	{0x14, 0x01, 0x18, 0x10, "Fast"			},
	{0x14, 0x01, 0x18, 0x00, "Fastest"		},

	{0   , 0xfe, 0   ,    4, "Difficulty"		},
	{0x14, 0x01, 0x60, 0x20, "Easy"			},
	{0x14, 0x01, 0x60, 0x60, "Normal"		},
	{0x14, 0x01, 0x60, 0x40, "Hard"			},
	{0x14, 0x01, 0x60, 0x00, "Hardest"		},

	{0   , 0xfe, 0   ,    2, "Demo Sounds"		},
	{0x14, 0x01, 0x80, 0x00, "Off"			},
	{0x14, 0x01, 0x80, 0x80, "On"			},
};

STDDIPINFO(Logicpr2);

static void deniam16_set_okibank(int bank)
{
	*okibank = bank;

	MSM6295ROM = DrvSndROM + (*okibank ? 0x40000 : 0x00000);
}

unsigned char __fastcall deniam16_read_byte(unsigned int address)
{
	switch (address)
	{
		case 0xc40001:
			return MSM6295ReadStatus(0); // logicpr2

		case 0xc40003:
			return *coin_control;

		case 0xc44001:
			return DrvInputs[0] & 0xff;

		case 0xc44003:
			return DrvInputs[1] & 0xff;

		case 0xc44005:
			return DrvInputs[2] & 0xff;

		case 0xc4400b:
			return DrvDips[0];
	}

	return 0;
}

void __fastcall deniam16_write_byte(unsigned int address, unsigned char data)
{
	switch (address)
	{
		case 0xc40000:
			if (nGame != 2) {
				*soundlatch = data;
				ZetNmi();
			}
		return;

		case 0xc40001:
			if (nGame == 2) {
				MSM6295Command(0, data);
			}
		return;

		case 0xc40003:
			*coin_control = data;
		return;

		case 0xc40007:
			deniam16_set_okibank(data & 0x01); // logicpr2
		return;

		case 0xc40008:
			BurnYM3812Write(0, data); // logicpr2
		return;

		case 0xc4000a:
			BurnYM3812Write(1, data); // logicpr2
		return;
	}
}

void __fastcall deniam16_sound_out(unsigned short port, unsigned char data)
{
	switch (port & 0xff)
	{
		case 0x02:
			BurnYM3812Write(0, data);
		return;

		case 0x03:
			BurnYM3812Write(1, data);
		return;

		case 0x05:
			MSM6295Command(0, data);
		return;

		case 0x07:
			deniam16_set_okibank(data & 0x40);
		return;
	}
}

unsigned char __fastcall deniam16_sound_in(unsigned short port)
{
	switch (port & 0xff)
	{
		case 0x01:
			return *soundlatch;

		case 0x05:
			return MSM6295ReadStatus(0);
	}

	return 0;
}

inline static int deniam16ZetSynchroniseStream(int nSoundRate)
{
	return (long long)(ZetTotalCycles() * nSoundRate / 6250000);
}

inline static int deniam16SekSynchroniseStream(int nSoundRate)
{
	return (long long)(SekTotalCycles() * nSoundRate / 12500000);
}

void deniam16YM3812IrqHandler(int, int nStatus)
{
	if (nStatus) {
		ZetSetIRQLine(0xff, ZET_IRQSTATUS_ACK);
	} else {
		ZetSetIRQLine(0,    ZET_IRQSTATUS_NONE);
	}
}

static int DrvDoReset()
{
	DrvReset = 0;

	memset (AllRam, 0, RamEnd - AllRam);

	SekOpen(0);
	SekReset();
	SekClose();

	ZetOpen(0);
	ZetReset();
	ZetClose();

	MSM6295Reset(0);
	BurnYM3812Reset();

	deniam16_set_okibank(0);

	return 0;
}

static int MemIndex()
{
	unsigned char *Next; Next = AllMem;

	Drv68KROM	= Next; Next += 0x100000;
	DrvZ80ROM	= Next; Next += 0x010000;

	DrvGfxROM0	= Next; Next += 0x400000;
	DrvGfxROM1	= Next; Next += 0x400000;

	MSM6295ROM	= Next;
	DrvSndROM	= Next; Next += 0x100000;

	DrvPalette	= (unsigned int*)Next; Next += 0x0800 * sizeof(int);

	DrvTxtTable	= (short*)Next; Next += 0x0800 * sizeof(short);
	DrvLayerTable	= (short*)Next; Next += 0x2000 * sizeof(short);

	AllRam		= Next;

	DrvSprRAM	= Next; Next += 0x000800;
	DrvTxtRAM	= Next; Next += 0x001000;
	Drv68KRAM	= Next; Next += 0x010000;
	DrvPalRAM	= Next; Next += 0x001000;
	DrvVidRAM	= Next; Next += 0x010000;

	DrvZ80RAM	= Next; Next += 0x000800;

	coin_control	= Next; Next += 0x000001;
	soundlatch	= Next; Next += 0x000001;
	okibank		= Next; Next += 0x000001;

	RamEnd		= Next;

	MemEnd		= Next;

	return 0;
}

static void create_offset_tables()
{
	for (int offs = 0; offs < 128 * 64; offs++)
	{
		int sx = (offs & 0x7f);
		int sy = (offs >> 7);

		DrvLayerTable[offs] =  (sx & 0x3f) + ((sy & 0x1f) << 6) + ((sx & 0x40) << 5) + ((sy & 0x20) << 7);
	}

	for (int offs = 0; offs < 64 * 32; offs++)
	{
		int sx = (offs & 0x3f);
		int sy = (offs >> 6);

		DrvTxtTable[offs] = (sx & 0x3f) + ((sy & 0x1f) << 6) + ((sx & 0x40) << 5) + ((sy & 0x20) << 7);
	}
}

static int DrvGfxDecode()
{
	int Plane[3] = { (0x80000 * 8) * 2, (0x80000 * 8) * 1, 0 };
	int XOffs[8] = { 0,  1,  2,  3,  4,  5,  6,  7 };
	int YOffs[8] = { 0,  8, 16, 24, 32, 40, 48, 56 };

	unsigned char *tmp = (unsigned char*)malloc(0x180000);
	if (tmp == NULL) {
		return 1;
	}

	memcpy (tmp, DrvGfxROM0, 0x180000);

	GfxDecode(0x10000, 3, 8, 8, Plane, XOffs, YOffs, 0x040, tmp, DrvGfxROM0);

	free (tmp);

	return 0;
}

static int DrvInit()
{
	AllMem = NULL;
	MemIndex();
	int nLen = MemEnd - (unsigned char *)0;
	if ((AllMem = (unsigned char *)malloc(nLen)) == NULL) return 1;
	memset(AllMem, 0, nLen);
	MemIndex();

	{
		if (BurnLoadRom(Drv68KROM + 0x000001,	 0, 2)) return 1;
		if (BurnLoadRom(Drv68KROM + 0x000000,	 1, 2)) return 1;

		switch (nGame)
		{
			case 0:
			{
				if (BurnLoadRom(DrvZ80ROM,		 2, 1)) return 1;
		
				if (BurnLoadRom(DrvGfxROM0 + 0x000000,	 3, 1)) return 1;
				if (BurnLoadRom(DrvGfxROM0 + 0x080000,	 4, 1)) return 1;
				if (BurnLoadRom(DrvGfxROM0 + 0x100000,	 5, 1)) return 1;

				if (BurnLoadRom(DrvGfxROM1 + 0x000000,	 6, 2)) return 1;
				if (BurnLoadRom(DrvGfxROM1 + 0x000001,	 7, 2)) return 1;
		
				if (BurnLoadRom(DrvSndROM + 0x000000,    8, 1)) return 1;
			}
			break;

			case 1:
			{
				if (BurnLoadRom(DrvZ80ROM,		 2, 1)) return 1;
		
				if (BurnLoadRom(DrvGfxROM0 + 0x000000,	 3, 1)) return 1;
				if (BurnLoadRom(DrvGfxROM0 + 0x080000,	 4, 1)) return 1;
				if (BurnLoadRom(DrvGfxROM0 + 0x100000,	 5, 1)) return 1;

				if (BurnLoadRom(DrvGfxROM1 + 0x000000,	 6, 2)) return 1;
				if (BurnLoadRom(DrvGfxROM1 + 0x000001,	 7, 2)) return 1;
				if (BurnLoadRom(DrvGfxROM1 + 0x100000,	 8, 2)) return 1;
				if (BurnLoadRom(DrvGfxROM1 + 0x100001,	 9, 2)) return 1;
				if (BurnLoadRom(DrvGfxROM1 + 0x200000,	10, 2)) return 1;
				if (BurnLoadRom(DrvGfxROM1 + 0x200001,	11, 2)) return 1;

				if (BurnLoadRom(DrvSndROM + 0x000000,   12, 1)) return 1;
			}
			break;

			case 2:
			{
				if (BurnLoadRom(DrvGfxROM0 + 0x000000,	 2, 1)) return 1;
				if (BurnLoadRom(DrvGfxROM0 + 0x080000,	 3, 1)) return 1;
				if (BurnLoadRom(DrvGfxROM0 + 0x100000,	 4, 1)) return 1;

				if (BurnLoadRom(DrvGfxROM1 + 0x000000,	 5, 1)) return 1;
				BurnByteswap(DrvGfxROM1, 0x400000);

				if (BurnLoadRom(DrvSndROM + 0x000000,    6, 1)) return 1;
			}
			break;
		}

		DrvGfxDecode();
		create_offset_tables();
	}

	SekInit(0, 0x68000);
	SekOpen(0);
	SekMapMemory(Drv68KROM,		0x000000, 0x0fffff, SM_ROM);
	SekMapMemory(DrvVidRAM,		0x400000, 0x40ffff, SM_RAM);
	SekMapMemory(DrvTxtRAM,		0x410000, 0x410fff, SM_RAM);
	SekMapMemory(DrvSprRAM,		0x440000, 0x4407ff, SM_WRITE);
	SekMapMemory(DrvPalRAM,		0x840000, 0x840fff, SM_RAM);
	SekMapMemory(Drv68KRAM,		0xff0000, 0xffffff, SM_RAM);
	SekSetWriteByteHandler(0,	deniam16_write_byte);
	SekSetReadByteHandler(0,	deniam16_read_byte);
	SekClose();

	ZetInit(1);
	ZetOpen(0);
	ZetMapArea(0x0000, 0xf7ff, 0, DrvZ80ROM);
	ZetMapArea(0x0000, 0xf7ff, 2, DrvZ80ROM);
	ZetMapArea(0xf800, 0xffff, 0, DrvZ80RAM);
	ZetMapArea(0xf800, 0xffff, 1, DrvZ80RAM);
	ZetMapArea(0xf800, 0xffff, 2, DrvZ80RAM);
	ZetSetOutHandler(deniam16_sound_out);
	ZetSetInHandler(deniam16_sound_in);
	ZetMemEnd();
	ZetClose();

	if (nGame != 2) {
		BurnYM3812Init(3125000, &deniam16YM3812IrqHandler, deniam16ZetSynchroniseStream, 0);
		BurnTimerAttachZet(6250000);
	} else {
		BurnYM3812Init(3125000, NULL, deniam16SekSynchroniseStream, 0);
		BurnTimerAttachSek(12500000);
	}

	MSM6295Init(0, 1056000 / 132, 100.0, 1);

	GenericTilesInit();

	DrvDoReset();

	return 0;
}

static int DrvExit()
{
	GenericTilesExit();

	MSM6295Exit(0);
	SekExit();
	ZetExit();

	free (AllMem);
	AllMem = NULL;

	MSM6295ROM = NULL;

	nGame = 0;

	return 0;
}

static void palette_write(int offset)
{
	unsigned char r,g,b;
	unsigned short data = *((unsigned short*)(DrvPalRAM + offset));

	r = ((data << 1) & 0x1e) | ((data >> 12) & 1);
	g = ((data >> 3) & 0x1e) | ((data >> 13) & 1);
	b = ((data >> 7) & 0x1e) | ((data >> 14) & 1);

	r = (r << 3) | (r >> 2);
	g = (g << 3) | (g >> 2);
	b = (b << 3) | (b >> 2);

	DrvPalette[offset/2] = BurnHighCol(r, g, b, 0);
}

static void draw_sprites(int priority)
{
	unsigned short *source = (unsigned short*)DrvSprRAM;

	for (int offs = 0;offs < 0x800/2;offs += 8)
	{
		if (priority != ((source[offs+4]&0xc0) >> 6)) continue;

		int sx = (source[offs+1] & 0x01ff) + 16*8 - 1;
		if (sx >= 512) sx -= 512;
		sx -= 192;
		int starty = source[offs+0] & 0xff;
		if (starty >= nScreenHeight) continue;
		int endy = source[offs+0] >> 8;
		if (endy >= nScreenHeight) endy = nScreenHeight-1;

		int width = source[offs+2] & 0x007f;
		int flipx = source[offs+2] & 0x0100;
		if (flipx) sx++;

		int color = (0x40 + (source[offs+4] & 0x3f)) << 4;

		int start = source[offs+3] + ((source[offs+4] & 0x1f00) << 8);
		unsigned char *rom = DrvGfxROM1 + start * 2;

		for (int y = starty+1;y <= endy;y++)
		{
			int drawing = 0;
			int i=0;

			rom += 2 * width;
			int x = 0;

			unsigned short *dest = pTransDraw + (y * nScreenWidth);

			while (i < 512)
			{
				if (flipx)
				{
					if ((rom[i] & 0x0f) == 0x0f)
					{
						if (!drawing) drawing = 1;
						else break;
					}
					else
					{
						if (rom[i] & 0x0f)
						{
							if (sx+x >= 0 && sx+x < nScreenWidth) {
								dest[(sx+x)] = color | (rom[i] & 0x0f);
							}
						}
						x++;
					}

					if ((rom[i] & 0xf0) == 0xf0)
					{
						if (!drawing) drawing = 1;
						else break;
					}
					else
					{
						if (rom[i] & 0xf0)
						{
							if (sx+x >= 0 && sx+x < nScreenWidth) {
								dest[(sx+x)] = color | (rom[i]>>4);
							}
						}
						x++;
					}

					i--;
				}
				else
				{
					if ((rom[i] & 0xf0) == 0xf0)
					{
						if (!drawing) drawing = 1;
						else break;
					}
					else
					{
						if (rom[i] & 0xf0)
						{
							if (sx+x >= 0 && sx+x < nScreenWidth) {
								dest[(sx+x)] = color | (rom[i]>>4);
							}
						}
						x++;
					}

					if ((rom[i] & 0x0f) == 0x0f)
					{
						if (!drawing) drawing = 1;
						else break;
					}
					else
					{
						if (rom[i] & 0x0f)
						{
							if (sx+x >= 0 && sx+x < nScreenWidth) {
								dest[(sx+x)] = color | (rom[i] & 0x0f);
							}
						}
						x++;
					}

					i++;
				}
			}
		}
	}
}

static void draw_layer(int *in_page, int scrollx, int scrolly, int transp)
{
	unsigned short *vram = (unsigned short*)DrvVidRAM;

	for (int offs = 0; offs < 128 * 64; offs++)
	{
		int sx = ((offs & 0x7f) << 3) - scrollx;
		int sy = ((offs >> 7) << 3) - scrolly;

		int ofst = DrvLayerTable[offs];

		int attr = vram[in_page[ofst>>11] * 0x0800 + (ofst & 0x7ff)];
		int code = attr;
		if (transp && !code) continue;
		int color = (attr & 0x1fc0) >> 6;

		if (sx >= nScreenWidth || sy >= nScreenHeight || sy < -7 || sx < -7) continue;

		if (sx >= 0 && sx < (nScreenWidth - 7) && sy >= 0 && sy < (nScreenHeight - 7)) {
			if (transp) {
				Render8x8Tile_Mask(pTransDraw, code, sx, sy, color, 3, 0, 0, DrvGfxROM0);
			} else {
				Render8x8Tile(pTransDraw, code, sx, sy, color, 3, 0, DrvGfxROM0);
			}
		} else {
			if (transp) {
				Render8x8Tile_Mask_Clip(pTransDraw, code, sx, sy, color, 3, 0, 0, DrvGfxROM0);
			} else {
				Render8x8Tile_Clip(pTransDraw, code, sx, sy, color, 3, 0, DrvGfxROM0);
			}
		}
	}
}

static void draw_text()
{
	unsigned short *vram = (unsigned short*)DrvTxtRAM;

	for (int offs = 0; offs < 64 * 32; offs++)
	{
		int sx = ((offs & 0x3f) << 3) - 192;
		int sy = (offs >> 6) << 3;

		int attr = vram[DrvTxtTable[offs]];
		int code = attr & 0xf1ff;
		int color = (attr & 0x0e00) >> 9;

		if (sx < 0 || sy >= nScreenHeight || sx >= nScreenWidth || !code) continue;

		if (sx >= 0 && sx < (nScreenWidth - 7) && sy >= 0 && sy < (nScreenHeight - 7)) {
			Render8x8Tile_Mask(pTransDraw, code, sx, sy, color, 3, 0, 0, DrvGfxROM0);
		} else {
			Render8x8Tile_Mask_Clip(pTransDraw, code, sx, sy, color, 3, 0, 0, DrvGfxROM0);
		}
	}
}

static int DrvDraw()
{
	if (DrvRecalc) {
		for (int i = 0; i < 0x1000; i+=2) {
			palette_write(i);
		}
	}

	if (~*coin_control & 0x20) return 0;

	{
		int pages[4];
		unsigned short *txtram = (unsigned short*)DrvTxtRAM;

	//	draw_sprites(0);

		int bg_scrollx = (txtram[bg_scrollx_reg] - bg_scrollx_offs) & 0x1ff;
		int bg_scrolly = ((txtram[bg_scrolly_reg] & 0xff) - bg_scrolly_offs) & 0xff;
		int page = txtram[bg_page_reg];
	
		pages[3] = (page >> 12) & 0x0f;
		pages[2] = (page >>  8) & 0x0f;
		pages[1] = (page >>  4) & 0x0f;
		pages[0] = (page >>  0) & 0x0f;

		draw_layer(pages, bg_scrollx+192, bg_scrolly, 0);

		draw_sprites(1);

		int fg_scrollx = (txtram[fg_scrollx_reg] - fg_scrollx_offs) & 0x1ff;
		int fg_scrolly = ((txtram[fg_scrolly_reg] & 0xff) - fg_scrolly_offs) & 0xff;
		page = txtram[fg_page_reg];
	
		pages[3] = (page >> 12) & 0x0f;
		pages[2] = (page >>  8) & 0x0f;
		pages[1] = (page >>  4) & 0x0f;
		pages[0] = (page >>  0) & 0x0f;
	
		draw_layer(pages, fg_scrollx+192, fg_scrolly, 1);

		draw_sprites(2);
		draw_text();
		draw_sprites(3);
	}

	BurnTransferCopy(DrvPalette);

	return 0;
}

static int DrvFrame()
{
	if (DrvReset) {
		DrvDoReset();
	}

	{
		memset (DrvInputs, 0xff, 3);
		for (int i = 0; i < 8; i++)
		{
			DrvInputs[0] ^= (DrvJoy1[i] & 1) << i;
			DrvInputs[1] ^= (DrvJoy2[i] & 1) << i;
			DrvInputs[2] ^= (DrvJoy3[i] & 1) << i;
		}
	}

	SekNewFrame();
	ZetNewFrame();

	int nInterleave = 10;
	int nCyclesSegment;
	int nCyclesTotal[2] = { 12500000 / 60, 6250000 / 60 };
	nCyclesDone[0] = nCyclesDone[1] = 0;

	SekOpen(0);
	ZetOpen(0);

	for (int i = 0; i < nInterleave; i++)
	{
		nCyclesSegment = nCyclesTotal[0] / nInterleave;

		nCyclesDone[0] = SekRun(nCyclesSegment);

		if (nGame == 2) continue;

		nCyclesSegment = nCyclesTotal[1] / nInterleave;

		nCyclesDone[1] = ZetRun(nCyclesSegment);
	}

	SekSetIRQLine(4, SEK_IRQSTATUS_AUTO);

	if (pBurnSoundOut) {
		if (nGame != 2) BurnTimerEndFrame(nCyclesTotal[1] - nCyclesDone[1]);
		BurnYM3812Update(pBurnSoundOut, nBurnSoundLen);
		MSM6295Render(0, pBurnSoundOut, nBurnSoundLen);
	}

	ZetClose();
	SekClose();

	if (pBurnDraw) {
		DrvDraw();
	}

	return 0;
}


static int DrvScan(int nAction,int *pnMin)
{
	struct BurnArea ba;

	if (pnMin) {
		*pnMin = 0x029698;
	}

	if (nAction & ACB_VOLATILE) {	
		memset(&ba, 0, sizeof(ba));

		ba.Data	  = AllRam;
		ba.nLen	  = RamEnd - AllRam;
		ba.szName = "All Ram";
		BurnAcb(&ba);

		SekScan(nAction);
		ZetScan(nAction);

		SCAN_VAR(nCyclesDone[0]);
		SCAN_VAR(nCyclesDone[1]);

		BurnYM3812Scan(nAction, pnMin);
		MSM6295Scan(0, nAction);

		deniam16_set_okibank(*okibank);
	}

	return 0;
}


// Logic Pro (Japan)

static struct BurnRomInfo logicproRomDesc[] = {
	{ "logicpro.r4",	0x40000, 0xc506d484, 1 | BRF_PRG | BRF_ESS  }, //  0 68k Code
	{ "logicpro.r3",	0x40000, 0xd5a4cf62, 1 | BRF_PRG | BRF_ESS  }, //  1

	{ "logicpro.r2",	0x10000, 0x000d624b, 2 | BRF_PRG | BRF_ESS  }, //  2 Z80 Code

	{ "logicpro.r5",	0x80000, 0xdedf18c9, 3 | BRF_GRA },            //  3 Graphics Tiles
	{ "logicpro.r6",	0x80000, 0x3ecbd1c2, 3 | BRF_GRA },            //  4
	{ "logicpro.r7",	0x80000, 0x47135521, 3 | BRF_GRA },            //  5

	{ "logicpro.r9",	0x80000, 0xa98bc1d2, 4 | BRF_GRA },            //  6 Sprites
	{ "logicpro.r8",	0x80000, 0x1de46298, 4 | BRF_GRA },            //  7

	{ "logicpro.r1",	0x80000, 0xa1fec4d4, 5 | BRF_SND },            //  8 Samples
};

STD_ROM_PICK(logicpro);
STD_ROM_FN(logicpro);

static int logicproInit()
{
	bg_scrollx_reg = 0x00a4/2;
	bg_scrolly_reg = 0x00a8/2;
	bg_page_reg    = 0x00ac/2;
	fg_scrollx_reg = 0x00a2/2;
	fg_scrolly_reg = 0x00a6/2;
	fg_page_reg    = 0x00aa/2;

	bg_scrollx_offs = 0x00d;
	bg_scrolly_offs = 0x000;
	fg_scrollx_offs = 0x009;
	fg_scrolly_offs = 0x000;

	return DrvInit();
}

struct BurnDriver BurnDrvLogicpro = {
	"logicpro", NULL, NULL, "1996",
	"Logic Pro (Japan)\0", NULL, "Deniam", "Deniam-16b Hardware",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING, 2, HARDWARE_MISC_POST90S, //GBF_PUZZLE, 0,
	NULL, logicproRomInfo, logicproRomName, DrvInputInfo, Logicpr2DIPInfo,
	logicproInit, DrvExit, DrvFrame, DrvDraw, DrvScan, 0, NULL, NULL, NULL, &DrvRecalc,
	320, 224, 4, 3
};


// Croquis (Germany)

static struct BurnRomInfo croquisRomDesc[] = {
	{ "r4.bin",		0x40000, 0x03c9055e, 1 | BRF_PRG | BRF_ESS  }, //  0 68k Code
	{ "r3.bin",		0x40000, 0xa98ae4f6, 1 | BRF_PRG | BRF_ESS  }, //  1

	{ "logicpro.r2",	0x10000, 0x000d624b, 2 | BRF_PRG | BRF_ESS  }, //  2 Z80 Code

	{ "logicpro.r5",	0x80000, 0xdedf18c9, 3 | BRF_GRA },            //  3 Graphics Tiles
	{ "logicpro.r6",	0x80000, 0x3ecbd1c2, 3 | BRF_GRA },            //  4
	{ "logicpro.r7",	0x80000, 0x47135521, 3 | BRF_GRA },            //  5

	{ "logicpro.r9",	0x80000, 0xa98bc1d2, 4 | BRF_GRA },            //  6 Sprites
	{ "logicpro.r8",	0x80000, 0x1de46298, 4 | BRF_GRA },            //  7

	{ "logicpro.r1",	0x80000, 0xa1fec4d4, 5 | BRF_SND },            //  8 Samples
};

STD_ROM_PICK(croquis);
STD_ROM_FN(croquis);

struct BurnDriver BurnDrvCroquis = {
	"croquis", "logicpro", NULL, "1996",
	"Croquis (Germany)\0", NULL, "Deniam", "Deniam-16b Hardware",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE, 2, HARDWARE_MISC_POST90S, //GBF_PUZZLE, 0,
	NULL, croquisRomInfo, croquisRomName, DrvInputInfo, Logicpr2DIPInfo,
	logicproInit, DrvExit, DrvFrame, DrvDraw, DrvScan, 0, NULL, NULL, NULL, &DrvRecalc,
	320, 224, 4, 3
};


// Karian Cross (Rev. 1.0)

static struct BurnRomInfo karianxRomDesc[] = {
	{ "even",	0x80000, 0xfd0ce238, 1 | BRF_PRG | BRF_ESS  }, //  0 68k Code
	{ "odd",	0x80000, 0xbe173cdc, 1 | BRF_PRG | BRF_ESS  }, //  1

	{ "snd",	0x10000, 0xfedd3375, 2 | BRF_PRG | BRF_ESS  }, //  2 Z80 Code

	{ "bkg1",	0x80000, 0x5cb8558a, 3 | BRF_GRA },            //  3 Graphics Tiles
	{ "bkg2",	0x80000, 0x95ff297c, 3 | BRF_GRA },            //  4
	{ "bkg3",	0x80000, 0x6c81f1b2, 3 | BRF_GRA },            //  5

	{ "obj4",	0x80000, 0x5f8d75a9, 4 | BRF_GRA },            //  6 Sprites
	{ "obj1",	0x80000, 0x967ee97d, 4 | BRF_GRA },            //  7
	{ "obj5",	0x80000, 0xe9fc22f9, 4 | BRF_GRA },            //  8
	{ "obj2",	0x80000, 0xd39eb04e, 4 | BRF_GRA },            //  9
	{ "obj6",	0x80000, 0xc1ec35a5, 4 | BRF_GRA },            // 10
	{ "obj3",	0x80000, 0x6ac1ac87, 4 | BRF_GRA },            // 11

	{ "voi",	0x80000, 0xc6506a80, 5 | BRF_SND },            // 12 Samples
};

STD_ROM_PICK(karianx);
STD_ROM_FN(karianx);

static int karianxInit()
{
	nGame = 1;

	bg_scrollx_reg = 0x00a4/2;
	bg_scrolly_reg = 0x00a8/2;
	bg_page_reg    = 0x00ac/2;
	fg_scrollx_reg = 0x00a2/2;
	fg_scrolly_reg = 0x00a6/2;
	fg_page_reg    = 0x00aa/2;

	bg_scrollx_offs = 0x10d;
	bg_scrolly_offs = 0x080;
	fg_scrollx_offs = 0x109;
	fg_scrolly_offs = 0x080;

	return DrvInit();
}

struct BurnDriver BurnDrvKarianx = {
	"karianx", NULL, NULL, "1996",
	"Karian Cross (Rev. 1.0)\0", NULL, "Deniam", "Deniam-16b Hardware",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING, 2, HARDWARE_MISC_POST90S, //GBF_PUZZLE, 0,
	NULL, karianxRomInfo, karianxRomName, DrvInputInfo, KarianxDIPInfo,
	karianxInit, DrvExit, DrvFrame, DrvDraw, DrvScan, 0, NULL, NULL, NULL, &DrvRecalc,
	320, 224, 4, 3
};


// Logic Pro 2 (Japan)

static struct BurnRomInfo logicpr2RomDesc[] = {
	{ "lp2-2",	0x080000, 0xcc1880bf, 1 | BRF_PRG | BRF_ESS  }, //  0 68k Code
	{ "lp2-1",	0x080000, 0x46d5e954, 1 | BRF_PRG | BRF_ESS  }, //  1

	{ "log2-b01",	0x080000, 0xfe789e07, 3 | BRF_GRA },            //  2 Graphics Tiles
	{ "log2-b02",	0x080000, 0x1e0c51cd, 3 | BRF_GRA },            //  3
	{ "log2-b03",	0x080000, 0x916f2928, 3 | BRF_GRA },            //  4

	{ "obj",	0x400000, 0xf221f305, 4 | BRF_GRA },            //  5 Sprites

	{ "log2-s01",	0x100000, 0x2875c435, 5 | BRF_SND },            //  6 Samples
};

STD_ROM_PICK(logicpr2);
STD_ROM_FN(logicpr2);

static int logicpr2Init()
{
	nGame = 2;

	return logicproInit();
}

struct BurnDriver BurnDrvLogicpr2 = {
	"logicpr2", NULL, NULL, "1997",
	"Logic Pro 2 (Japan)\0", NULL, "Deniam", "Deniam-16c Hardware",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING, 2, HARDWARE_MISC_POST90S, //GBF_PUZZLE, 0,
	NULL, logicpr2RomInfo, logicpr2RomName, DrvInputInfo, Logicpr2DIPInfo,
	logicpr2Init, DrvExit, DrvFrame, DrvDraw, DrvScan, 0, NULL, NULL, NULL, &DrvRecalc,
	320, 224, 4, 3
};
