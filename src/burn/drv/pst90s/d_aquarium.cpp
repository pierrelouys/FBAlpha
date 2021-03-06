// FB Alpha Aquarium driver module
// Based on MAME driver by David Haywood

#include "tiles_generic.h"
#include "burn_ym2151.h"
#include "msm6295.h"
#include "bitswap.h"

static unsigned char *AllMem;
static unsigned char *MemEnd;
static unsigned char *AllRam;
static unsigned char *RamEnd;
static unsigned char *Drv68KROM;
static unsigned char *Drv68KRAM;
static unsigned char *DrvZ80ROM;
static unsigned char *DrvZ80Bank;
static unsigned char *DrvZ80RAM;
static unsigned char *DrvSndROM;
static unsigned char *DrvGfxROM0;
static unsigned char *DrvGfxROM1;
static unsigned char *DrvGfxROM2;
static unsigned char *DrvGfxROM3;
static unsigned char *DrvPalRAM;
static unsigned char *DrvMidRAM;
static unsigned char *DrvBakRAM;
static unsigned char *DrvTxtRAM;
static unsigned char *DrvSprRAM;
static unsigned short *DrvScroll;
static unsigned int  *DrvPalette;

static unsigned char DrvRecalc;

static unsigned char DrvJoy1[16];
static unsigned char DrvJoy2[16];
static unsigned char DrvDips[3];
static unsigned char DrvReset;
static unsigned short DrvInputs[2];

static unsigned char *soundlatch;
static unsigned char *soundack;
static unsigned char *flipscreen;

static struct BurnInputInfo AquariumInputList[] = {
	{"P1 Coin",		BIT_DIGITAL,	DrvJoy2 + 1,	"p1 coin"	},
	{"P1 Start",		BIT_DIGITAL,	DrvJoy1 + 15,	"p1 start"	},
	{"P1 Up",		BIT_DIGITAL,	DrvJoy1 + 8,	"p1 up"		},
	{"P1 Down",		BIT_DIGITAL,	DrvJoy1 + 9,	"p1 down"	},
	{"P1 Left",		BIT_DIGITAL,	DrvJoy1 + 10,	"p1 left"	},
	{"P1 Right",		BIT_DIGITAL,	DrvJoy1 + 11,	"p1 right"	},
	{"P1 Button 1",		BIT_DIGITAL,	DrvJoy1 + 12,	"p1 fire 1"	},
	{"P1 Button 2",		BIT_DIGITAL,	DrvJoy1 + 13,	"p1 fire 2"	},

	{"P2 Coin",		BIT_DIGITAL,	DrvJoy2 + 0,	"p2 coin"	},
	{"P2 Start",		BIT_DIGITAL,	DrvJoy1 + 7,	"p2 start"	},
	{"P2 Up",		BIT_DIGITAL,	DrvJoy1 + 0,	"p2 up"		},
	{"P2 Down",		BIT_DIGITAL,	DrvJoy1 + 1,	"p2 down"	},
	{"P2 Left",		BIT_DIGITAL,	DrvJoy1 + 2,	"p2 left"	},
	{"P2 Right",		BIT_DIGITAL,	DrvJoy1 + 3,	"p2 right"	},
	{"P2 Button 1",		BIT_DIGITAL,	DrvJoy1 + 4,	"p2 fire 1"	},
	{"P2 Button 2",		BIT_DIGITAL,	DrvJoy1 + 5,	"p2 fire 2"	},

	{"Reset",		BIT_DIGITAL,	&DrvReset,	"reset"		},
	{"Service",		BIT_DIGITAL,	DrvJoy2 + 3,	"service"	},
	{"Dip A",		BIT_DIPSWITCH,	DrvDips + 0,	"dip"		},
	{"Dip B",		BIT_DIPSWITCH,	DrvDips + 1,	"dip"		},
	{"Dip C",		BIT_DIPSWITCH,	DrvDips + 2,	"dip"		},
};

STDINPUTINFO(Aquarium);

static struct BurnDIPInfo AquariumDIPList[]=
{
	{0x12, 0xff, 0xff, 0xff, NULL					},
	{0x13, 0xff, 0xff, 0xff, NULL					},
	{0x14, 0xff, 0xff, 0xff, NULL					},

	{0   , 0xfe, 0   ,    4, "Difficulty"				},
	{0x12, 0x01, 0x03, 0x02, "Easy"					},
	{0x12, 0x01, 0x03, 0x03, "Normal"				},
	{0x12, 0x01, 0x03, 0x01, "Hard"					},
	{0x12, 0x01, 0x03, 0x00, "Hardest"				},

	{0   , 0xfe, 0   ,    3, "Winning Rounds (Player VS CPU)"	},
	{0x12, 0x01, 0x0c, 0x0c, "1/1"					},
	{0x12, 0x01, 0x0c, 0x08, "2/3"					},
	{0x12, 0x01, 0x0c, 0x04, "3/5"					},

	{0   , 0xfe, 0   ,    3, "Winning Rounds (Player VS Player)"	},
	{0x12, 0x01, 0x30, 0x30, "1/1"					},
	{0x12, 0x01, 0x30, 0x20, "2/3"					},
	{0x12, 0x01, 0x30, 0x10, "3/5"					},

	{0   , 0xfe, 0   ,    8, "Coinage"				},	
	{0x13, 0x01, 0x07, 0x00, "5 Coins 1 Credits "			},
	{0x13, 0x01, 0x07, 0x01, "4 Coins 1 Credits "			},
	{0x13, 0x01, 0x07, 0x02, "3 Coins 1 Credits "			},
	{0x13, 0x01, 0x07, 0x03, "2 Coins 1 Credits "			},
	{0x13, 0x01, 0x07, 0x07, "1 Coin  1 Credits "			},
	{0x13, 0x01, 0x07, 0x06, "1 Coin  2 Credits "			},
	{0x13, 0x01, 0x07, 0x05, "1 Coin  3 Credits "			},
	{0x13, 0x01, 0x07, 0x04, "1 Coin  4 Credits "			},

	{0   , 0xfe, 0   ,    2, "Flip Screen"				},
	{0x13, 0x01, 0x10, 0x10, "Off"					},
	{0x13, 0x01, 0x10, 0x00, "On"					},

	{0   , 0xfe, 0   ,    2, "Demo Sounds"				},
	{0x13, 0x01, 0x20, 0x00, "Off"					},
	{0x13, 0x01, 0x20, 0x20, "On"					},

	{0   , 0xfe, 0   ,    2, "Language"				},
	{0x14, 0x01, 0xff, 0x00, "Japanese"				},
	{0x14, 0x01, 0xff, 0xff, "English"				},
};

STDDIPINFO(Aquarium);

unsigned char __fastcall aquarium_read_byte(unsigned int address)
{
	switch (address)
	{
		case 0xd80080:
			return DrvDips[1];

		case 0xd80081:
			return DrvDips[0];

		case 0xd80086:
		{
			int data = DrvInputs[1] | *soundack;
			*soundack = 0;
			return data;
		}
	}

	return 0;
}

unsigned short __fastcall aquarium_read_word(unsigned int address)
{
	switch (address)
	{
		case 0xd80084:
			return DrvInputs[0];
	}

	return 0;
}

void __fastcall aquarium_write_byte(unsigned int address, unsigned char data)
{
	switch (address)
	{
		case 0xd8008b:
			*soundlatch = data;
			ZetNmi();
		return;
	}
}

void __fastcall aquarium_write_word(unsigned int address, unsigned short data)
{
	switch (address)
	{
		case 0xd80014:
		case 0xd80016:
		case 0xd80018:
		case 0xd8001a:
		case 0xd8001c:
		case 0xd8001e:
			DrvScroll[(address - 0xd80014)/2] = data;
		return;

		case 0xd80056:
			*flipscreen = ~data & 1; // seems right?
		return;
	}
}

static void sound_bankswitch(int nBank)
{
	*DrvZ80Bank = nBank & 7;

	nBank = ((nBank & 7) + 1) * 0x8000;

	ZetMapArea(0x8000, 0xffff, 0, DrvZ80ROM + nBank);
	ZetMapArea(0x8000, 0xffff, 2, DrvZ80ROM + nBank);
}

void __fastcall aquarium_sound_out(unsigned short port, unsigned char data)
{
	switch (port & 0xff)
	{
		case 0x00:
			BurnYM2151SelectRegister(data);
		return;

		case 0x01:
			BurnYM2151WriteRegister(data);
		return;

		case 0x02:
			MSM6295Command(0, BITSWAP08(data, 0, 1, 2, 3, 4, 5, 6, 7));
		return;

		case 0x06:
			*soundack = 0x80;
		return;

		case 0x08:
			sound_bankswitch(data);
		return;
	}
}

unsigned char __fastcall aquarium_sound_in(unsigned short port)
{
	switch (port & 0xff)
	{
		case 0x01:
			return BurnYM2151ReadStatus();

		case 0x02:
			return BITSWAP08(MSM6295ReadStatus(0), 0, 1, 2, 3, 4, 5, 6, 7);

		case 0x04:
			return *soundlatch;
	}

	return 0;
}

void aquariumYM2151IrqHandler(int Irq)
{
	if (Irq) {
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
	BurnYM2151Reset();

	Drv68KROM[0x000a5c] = DrvDips[2]; // set region (hack)
	Drv68KROM[0x000a5d] = DrvDips[2];

	return 0;
}

static int DrvGfxDecode()
{
	int Plane0[5]  = { 0x400000, 0, 1, 2, 3 };
	int Plane2[4]  = { 48, 16, 32, 0 };
	int XOffs0[16] = { 8, 12, 0, 4, 24, 28, 16, 20, 40, 44, 32, 36, 56, 60, 48, 52 };
	int XOffs2[16] = { 8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7 };
	int YOffs0[16] = { 0, 64, 128, 192, 256, 320, 384, 448, 512, 576, 640, 704, 768, 832, 896, 960 };
	int YOffs1[8]  = { 0, 32, 64, 96, 128, 160, 192, 224 };

	unsigned char *tmp = (unsigned char*)malloc(0x100000);
	if (tmp == NULL) {
		return 1;
	}

	memcpy (tmp, DrvGfxROM0, 0x100000);

	GfxDecode(0x1000, 5, 16, 16, Plane0    , XOffs0, YOffs0, 0x400, tmp, DrvGfxROM0);

	memcpy (tmp, DrvGfxROM1, 0x020000);

	GfxDecode(0x1000, 4,  8,  8, Plane0 + 1, XOffs0, YOffs1, 0x100, tmp, DrvGfxROM1);

	memcpy (tmp, DrvGfxROM2, 0x100000);

	GfxDecode(0x2000, 4, 16, 16, Plane2    , XOffs2, YOffs0, 0x400, tmp, DrvGfxROM2);

	memcpy (tmp, DrvGfxROM3, 0x100000);

	GfxDecode(0x1000, 5, 16, 16, Plane0    , XOffs0, YOffs0, 0x400, tmp, DrvGfxROM3);

	free (tmp);

	return 0;
}

static int MemIndex()
{
	unsigned char *Next; Next = AllMem;

	Drv68KROM	= Next; Next += 0x080000;
	DrvZ80ROM	= Next; Next += 0x040000;

	DrvGfxROM0	= Next; Next += 0x100000;
	DrvGfxROM1	= Next; Next += 0x040000;
	DrvGfxROM2	= Next; Next += 0x200000;
	DrvGfxROM3	= Next; Next += 0x100000;

	MSM6295ROM	= Next;
	DrvSndROM	= Next; Next += 0x080000;

	DrvPalette	= (unsigned int*)Next; Next += 0x0800 * sizeof(int);

	AllRam		= Next;

	Drv68KRAM	= Next; Next += 0x010000;
	DrvPalRAM	= Next; Next += 0x001000;
	DrvMidRAM	= Next; Next += 0x001000;
	DrvBakRAM	= Next; Next += 0x001000;
	DrvTxtRAM	= Next; Next += 0x002000;
	DrvSprRAM	= Next; Next += 0x002000;

	DrvZ80RAM	= Next; Next += 0x000800;

	soundack	= Next; Next += 0x000001;
	soundlatch 	= Next; Next += 0x000001;
	flipscreen	= Next; Next += 0x000001;
	DrvZ80Bank	= Next; Next += 0x000001;

	DrvScroll	= (unsigned short*)Next; Next += 0x000008 * sizeof(short);

	RamEnd		= Next;

	MemEnd		= Next;

	return 0;
}

static int DrvLoad5bpp(unsigned char *gfx, int num)
{
	unsigned char *tmp = (unsigned char*)malloc(0x20000);
	if (tmp == NULL) {
		return 1;
	}

	if (BurnLoadRom(tmp, num, 1)) return 1;

	for (int len = 0; len < 0x020000; len++)
	{
		gfx[len*4+0] =  ((tmp[len] & 0x20) << 2) | ((tmp[len] & 0x10) >> 1);
		gfx[len*4+1] =  ((tmp[len] & 0x80) << 0) | ((tmp[len] & 0x40) >> 3);
		gfx[len*4+2] =  ((tmp[len] & 0x02) << 6) | ((tmp[len] & 0x01) << 3);
		gfx[len*4+3] =  ((tmp[len] & 0x08) << 4) | ((tmp[len] & 0x04) << 1);
	}

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
		if (BurnLoadRom(Drv68KROM,		0, 1)) return 1;

		if (BurnLoadRom(DrvZ80ROM,		1, 1)) return 1;

		if (BurnLoadRom(DrvGfxROM0,		2, 1)) return 1;
		if (DrvLoad5bpp(DrvGfxROM0 + 0x80000,	3   )) return 1;

		if (BurnLoadRom(DrvGfxROM1,		4, 1)) return 1;

		if (BurnLoadRom(DrvGfxROM2,		5, 1)) return 1;

		if (BurnLoadRom(DrvGfxROM3,		6, 1)) return 1;
		if (DrvLoad5bpp(DrvGfxROM3 + 0x80000,	7   )) return 1;

		if (BurnLoadRom(DrvSndROM,		8, 1)) return 1;

		DrvGfxDecode();
	}

	SekInit(0, 0x68000);
	SekOpen(0);
	SekMapMemory(Drv68KROM,		0x000000, 0x07ffff, SM_ROM);
	SekMapMemory(DrvMidRAM,		0xc00000, 0xc00fff, SM_RAM);
	SekMapMemory(DrvBakRAM,		0xc01000, 0xc01fff, SM_RAM);
	SekMapMemory(DrvTxtRAM,		0xc02000, 0xc03fff, SM_RAM);
	SekMapMemory(DrvSprRAM,		0xc80000, 0xc81fff, SM_RAM);
	SekMapMemory(DrvPalRAM,		0xd00000, 0xd00fff, SM_RAM);
	SekMapMemory(Drv68KRAM,		0xff0000, 0xffffff, SM_RAM);
	SekSetWriteByteHandler(0,	aquarium_write_byte);
	SekSetWriteWordHandler(0,	aquarium_write_word);
	SekSetReadByteHandler(0,	aquarium_read_byte);
	SekSetReadWordHandler(0,	aquarium_read_word);
	SekClose();

	ZetInit(1);
	ZetOpen(0);
	ZetMapArea(0x0000, 0x3fff, 0, DrvZ80ROM);
	ZetMapArea(0x0000, 0x3fff, 2, DrvZ80ROM);
	ZetMapArea(0x7800, 0x7fff, 0, DrvZ80RAM);
	ZetMapArea(0x7800, 0x7fff, 1, DrvZ80RAM);
	ZetMapArea(0x7800, 0x7fff, 2, DrvZ80RAM);
	ZetSetOutHandler(aquarium_sound_out);
	ZetSetInHandler(aquarium_sound_in);
	ZetMemEnd();
	ZetClose();

	MSM6295Init(0, 1122000 / 132, 100.0, 1);

	BurnYM2151Init(3579545, 100.0);
	BurnYM2151SetIrqHandler(&aquariumYM2151IrqHandler);

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

	return 0;
}

static inline void palette_write(int offset)
{
	unsigned char r,g,b;
	unsigned short data = *((unsigned short*)(DrvPalRAM + offset));

	r = ((data >> 11) & 0x1e) | ((data >> 3) & 0x01);
	g = ((data >>  7) & 0x1e) | ((data >> 2) & 0x01);
	b = ((data >>  3) & 0x1e) | ((data >> 1) & 0x01);

	r = (r << 3) | (r >> 2);
	g = (g << 3) | (g >> 2);
	b = (b << 3) | (b >> 2);

	DrvPalette[offset/2] = BurnHighCol(r, g, b, 0);
}

static void draw_bg_layer(unsigned char *src, unsigned char *gfx_base, int scrollx, int scrolly, int transp, int priority)
{
	unsigned short *vram = (unsigned short*)src;

	for (int offs = 0; offs < 32 * 32; offs++)
	{
		int color = vram[(offs * 2) + 1];
		int prior = (color & 0x0020) >> 5;
		if (prior != priority) continue;

		int sx = (offs & 0x1f) << 4;
		int sy = (offs >> 5) << 4;

		sx -= scrollx + 16;
		if (sx < -15) sx += 0x200;
		sy -= scrolly + 16;
		if (sy < -15) sy += 0x200;

		if (sx >= nScreenWidth || sy >= nScreenHeight) continue;

		int flipx = color & 0x0100;
		int flipy = color & 0x0200;
		int code  = vram[offs * 2] & 0x0fff;

		if (transp) {
			if (flipy) {
				if (flipx) {
					Render16x16Tile_Mask_FlipXY_Clip(pTransDraw, code, sx, sy, color & 0x001f, 5, 0, 0x400, gfx_base);
				} else {
					Render16x16Tile_Mask_FlipY_Clip(pTransDraw, code, sx, sy, color & 0x001f, 5, 0, 0x400, gfx_base);
				}
			} else {
				if (flipx) {
					Render16x16Tile_Mask_FlipX_Clip(pTransDraw, code, sx, sy, color & 0x001f, 5, 0, 0x400, gfx_base);
				} else {
					Render16x16Tile_Mask_Clip(pTransDraw, code, sx, sy, color & 0x001f, 5, 0, 0x400, gfx_base);
				}
			}
		} else {
			if (flipy) {
				if (flipx) {
					Render16x16Tile_FlipXY_Clip(pTransDraw, code, sx, sy, color & 0x001f, 5, 0x400, gfx_base);
				} else {
					Render16x16Tile_FlipY_Clip(pTransDraw, code, sx, sy, color & 0x001f, 5, 0x400, gfx_base);
				}
			} else {
				if (flipx) {
					Render16x16Tile_FlipX_Clip(pTransDraw, code, sx, sy, color & 0x001f, 5, 0x400, gfx_base);
				} else {
					Render16x16Tile_Clip(pTransDraw, code, sx, sy, color & 0x001f, 5, 0x400, gfx_base);
				}
			}
		}
	}
}

static void draw_tx_layer(int scrollx, int scrolly)
{
	unsigned short *vram = (unsigned short*)DrvTxtRAM;

	for (int offs = 0; offs < 64 * 64; offs++)
	{
		int sx = (offs & 0x3f) << 3;
		int sy = (offs >> 6) << 3;

		sx -= scrollx + 16;
		if (sx < -7) sx += 0x200;
		sy -= scrolly + 16;
		if (sy < -7) sy += 0x200;

		int code = vram[offs] & 0xfff;
		int color = vram[offs] >> 12;

		if (sx >= nScreenWidth || sy >= nScreenHeight || code == 0) continue;

		Render8x8Tile_Mask_Clip(pTransDraw, code, sx, sy, color, 4, 0, 0x200, DrvGfxROM1);
	}
}

static void draw_sprites()
{
	unsigned short *sram = (unsigned short*)DrvSprRAM;

	for (int offs = 0; offs < 0x0800; offs += 8)
	{
		int code = (sram[offs+5] & 0xff) | ((sram[offs+6] & 0x3f) << 8);

		if (~sram[offs+4] & 0x80)
		{
			int x = (((sram[offs+0] & 0xff) | ((sram[offs+1] & 0x7f) << 8)) - ((sram[offs+1] & 0x80) << 9)) - 16;
			int y = (((sram[offs+2] & 0xff) | ((sram[offs+3] & 0x7f) << 8)) - ((sram[offs+3] & 0x80) << 9)) - 16;

			int col  =  sram[offs+7] & 0x0f;
			int chain = sram[offs+4] & 0x07;
			int flipy = sram[offs+4] & 0x10;
			int flipx = sram[offs+4] & 0x20;

			if (~sram[offs+4] & 0x08) {
				if (flipy) y += chain << 4;
				if (flipx) x += chain << 4;
			}

			for (int pos = chain; pos >= 0; pos--)
			{
				if (flipy) {
					if (flipx) {
						Render16x16Tile_Mask_FlipXY_Clip(pTransDraw, code, x, y,       col, 4, 0, 0x300, DrvGfxROM2);
						Render16x16Tile_Mask_FlipXY_Clip(pTransDraw, code, x, y + 256, col, 4, 0, 0x300, DrvGfxROM2);
					} else {
						Render16x16Tile_Mask_FlipY_Clip(pTransDraw, code, x, y,       col, 4, 0, 0x300, DrvGfxROM2);
						Render16x16Tile_Mask_FlipY_Clip(pTransDraw, code, x, y + 256, col, 4, 0, 0x300, DrvGfxROM2);
					}
				} else {
					if (flipx) {
						Render16x16Tile_Mask_FlipX_Clip(pTransDraw, code, x, y,       col, 4, 0, 0x300, DrvGfxROM2);
						Render16x16Tile_Mask_FlipX_Clip(pTransDraw, code, x, y + 256, col, 4, 0, 0x300, DrvGfxROM2);
					} else {
						Render16x16Tile_Mask_Clip(pTransDraw, code, x, y,       col, 4, 0, 0x300, DrvGfxROM2);
						Render16x16Tile_Mask_Clip(pTransDraw, code, x, y + 256, col, 4, 0, 0x300, DrvGfxROM2);
					}
				}

				code++;

				if (sram[offs+4] & 0x08)
				{
					if (flipy) y -= 16;
					else y += 16;
				}
				else
				{
					if (flipx) x -= 16;
					else x += 16;
				}
			}
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

	draw_bg_layer(DrvBakRAM, DrvGfxROM3, DrvScroll[2] & 0x1ff, DrvScroll[3] & 0x1ff, 0, 0);
	draw_bg_layer(DrvMidRAM, DrvGfxROM0, DrvScroll[0] & 0x1ff, DrvScroll[1] & 0x1ff, 1, 0);

	draw_sprites();

	draw_bg_layer(DrvBakRAM, DrvGfxROM3, DrvScroll[2] & 0x1ff, DrvScroll[3] & 0x1ff, 1, 1);
	draw_bg_layer(DrvMidRAM, DrvGfxROM0, DrvScroll[0] & 0x1ff, DrvScroll[1] & 0x1ff, 1, 1);

	draw_tx_layer(DrvScroll[4] & 0x1ff, DrvScroll[5] & 0x1ff);

	if (*flipscreen) {
		int len = nScreenWidth * nScreenHeight;
		for (int i = 0; i < len / 2; i++) {
			int t = pTransDraw[i + 0];
			pTransDraw[i + 0] = pTransDraw[len-(1+i)];
			pTransDraw[len-(1+i)] = t;
		}
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
		memset (DrvInputs, 0xff, 4);
		for (int i = 0; i < 16; i++) {
			DrvInputs[0] ^= (DrvJoy1[i] & 1) << i;
			DrvInputs[1] ^= (DrvJoy2[i] & 1) << i;
		}
		DrvInputs[1] &= 0x7f;
	}

	int nSegment;
	int nInterleave = 10;
	int nSoundBufferPos = 0;
	int nCyclesTotal[2] = { 16000000 / 60, 6000000 / 60 };
	int nCyclesDone[2] = { 0, 0 };

	SekOpen(0);
	ZetOpen(0);

	SekNewFrame();
	ZetNewFrame();

	for (int i = 0; i < nInterleave; i++)
	{
		nSegment = (nCyclesTotal[0] - nCyclesDone[0]) / (nInterleave - i);
		nCyclesDone[0] += SekRun(nSegment);

		nSegment = (nCyclesTotal[1] - nCyclesDone[1]) / (nInterleave - i);
		nCyclesDone[1] += ZetRun(nSegment);

		if (pBurnSoundOut) {
			nSegment = nBurnSoundLen / nInterleave;

			BurnYM2151Render(pBurnSoundOut + nSoundBufferPos, nSegment);
			MSM6295Render(0, pBurnSoundOut + nSoundBufferPos, nSegment);

			nSoundBufferPos += nSegment << 1;
		}
	}

	SekSetIRQLine(1, SEK_IRQSTATUS_AUTO);

	if (pBurnSoundOut) {
		nSegment = nBurnSoundLen - nSoundBufferPos;
		if (nSegment > 0) {
			BurnYM2151Render(pBurnSoundOut + nSoundBufferPos, nSegment);
			MSM6295Render(0, pBurnSoundOut + nSoundBufferPos, nSegment);
		}
	}

	ZetClose();
	SekClose();

	if (pBurnDraw) {
		DrvDraw();
	}

	return 0;
}

static int DrvScan(int nAction, int *pnMin)
{
	struct BurnArea ba;
	
	if (pnMin != NULL) {
		*pnMin = 0x029698;
	}

	if (nAction & ACB_MEMORY_RAM) {
		memset(&ba, 0, sizeof(ba));
		ba.Data	  = AllRam;
		ba.nLen	  = RamEnd-AllRam;
		ba.szName = "All Ram";
		BurnAcb(&ba);
	}

	if (nAction & ACB_DRIVER_DATA) {
		SekScan(nAction);
		ZetScan(nAction);

		BurnYM2151Scan(nAction);
		MSM6295Scan(0, nAction);
	}

	if (nAction & ACB_WRITE) {
		ZetOpen(0);
		sound_bankswitch(*DrvZ80Bank);
		ZetClose();
	}

	return 0;
}


// Aquarium (Japan)

static struct BurnRomInfo aquariumRomDesc[] = {
	{ "aquar3",	0x080000, 0x344509a1, 1 | BRF_PRG | BRF_ESS }, //  0 68k Code

	{ "aquar5",	0x040000, 0xfa555be1, 2 | BRF_PRG | BRF_ESS }, //  1 Z80 Code

	{ "aquar1",	0x080000, 0x575df6ac, 3 | BRF_GRA },           //  2 Midground Tiles
	{ "aquar6",	0x020000, 0x9065b146, 3 | BRF_GRA },           //  3

	{ "aquar2",	0x020000, 0xaa071b05, 4 | BRF_GRA },           //  6 Foreground Tiles

	{ "aquarf1",	0x100000, 0x14758b3c, 5 | BRF_GRA },           //  7 Sprites

	{ "aquar8",	0x080000, 0x915520c4, 6 | BRF_GRA },           //  4 Background Tiles
	{ "aquar7",	0x020000, 0xb96b2b82, 6 | BRF_GRA },           //  5

	{ "aquar4",	0x080000, 0x9a4af531, 7 | BRF_SND },           //  8 MSM6295 Samples
};

STD_ROM_PICK(aquarium);
STD_ROM_FN(aquarium);

struct BurnDriver BurnDrvAquarium = {
	"aquarium", NULL, NULL, "1996",
	"Aquarium (Japan)\0", NULL, "Excellent System", "Miscellaneous",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING, 2, HARDWARE_MISC_POST90S, //GBF_PUZZLE, 0,
	NULL, aquariumRomInfo, aquariumRomName, AquariumInputInfo, AquariumDIPInfo,
	DrvInit, DrvExit, DrvFrame, DrvDraw, DrvScan, 0, NULL, NULL, NULL, &DrvRecalc,
	320, 256, 4, 3
};
