// --- Op Funcs ---------------------------------
unsigned int n;
unsigned int m;

UINT32 RnL, RnH, RmL, RmH, Res0, Res1, Res2;
UINT32 temp, temp0, temp1, temp2, temp3;
INT32 tempm, tempn, fnLmL, templ;
INT32 HH, HL, LH, LL;
INT32 dest, src, ans, imm;

UINT32 tmp0, tmp1;
UINT32 old_q;



// NOP
Op____:
{
	goto SH2_RUN_CONTINUE;
}

// STC SR,Rn
Op0002:
{
	sh2->r[0] = sh2->sr;
	goto SH2_RUN_CONTINUE;
}

Op0102:
{
	sh2->r[1] = sh2->sr;
	goto SH2_RUN_CONTINUE;
}

Op0202:
{
	sh2->r[2] = sh2->sr;
	goto SH2_RUN_CONTINUE;
}

Op0302:
{
	sh2->r[3] = sh2->sr;
	goto SH2_RUN_CONTINUE;
}

Op0402:
{
	sh2->r[4] = sh2->sr;
	goto SH2_RUN_CONTINUE;
}

Op0502:
{
	sh2->r[5] = sh2->sr;
	goto SH2_RUN_CONTINUE;
}

Op0602:
{
	sh2->r[6] = sh2->sr;
	goto SH2_RUN_CONTINUE;
}

Op0702:
{
	sh2->r[7] = sh2->sr;
	goto SH2_RUN_CONTINUE;
}

Op0802:
{
	sh2->r[8] = sh2->sr;
	goto SH2_RUN_CONTINUE;
}

Op0902:
{
	sh2->r[9] = sh2->sr;
	goto SH2_RUN_CONTINUE;
}

Op0A02:
{
	sh2->r[10] = sh2->sr;
	goto SH2_RUN_CONTINUE;
}

Op0B02:
{
	sh2->r[11] = sh2->sr;
	goto SH2_RUN_CONTINUE;
}

Op0C02:
{
	sh2->r[12] = sh2->sr;
	goto SH2_RUN_CONTINUE;
}

Op0D02:
{
	sh2->r[13] = sh2->sr;
	goto SH2_RUN_CONTINUE;
}

Op0E02:
{
	sh2->r[14] = sh2->sr;
	goto SH2_RUN_CONTINUE;
}

Op0F02:
{
	sh2->r[15] = sh2->sr;
	goto SH2_RUN_CONTINUE;
}

// BSRF Rn
Op0003:
{
	sh2->pr = sh2->pc + 2;
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[0] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0103:
{
	sh2->pr = sh2->pc + 2;
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[1] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0203:
{
	sh2->pr = sh2->pc + 2;
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[2] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0303:
{
	sh2->pr = sh2->pc + 2;
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[3] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0403:
{
	sh2->pr = sh2->pc + 2;
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[4] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0503:
{
	sh2->pr = sh2->pc + 2;
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[5] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0603:
{
	sh2->pr = sh2->pc + 2;
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[6] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0703:
{
	sh2->pr = sh2->pc + 2;
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[7] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0803:
{
	sh2->pr = sh2->pc + 2;
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[8] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0903:
{
	sh2->pr = sh2->pc + 2;
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[9] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0A03:
{
	sh2->pr = sh2->pc + 2;
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[10] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0B03:
{
	sh2->pr = sh2->pc + 2;
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[11] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0C03:
{
	sh2->pr = sh2->pc + 2;
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[12] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0D03:
{
	sh2->pr = sh2->pc + 2;
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[13] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0E03:
{
	sh2->pr = sh2->pc + 2;
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[14] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0F03:
{
	sh2->pr = sh2->pc + 2;
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[15] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

// MOV.B Rm,@(R0,Rn)
Op0004:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WB( sh2->ea, sh2->r[0] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0014:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WB( sh2->ea, sh2->r[1] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0024:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WB( sh2->ea, sh2->r[2] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0034:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WB( sh2->ea, sh2->r[3] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0044:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WB( sh2->ea, sh2->r[4] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0054:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WB( sh2->ea, sh2->r[5] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0064:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WB( sh2->ea, sh2->r[6] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0074:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WB( sh2->ea, sh2->r[7] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0084:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WB( sh2->ea, sh2->r[8] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0094:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WB( sh2->ea, sh2->r[9] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op00A4:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WB( sh2->ea, sh2->r[10] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op00B4:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WB( sh2->ea, sh2->r[11] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op00C4:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WB( sh2->ea, sh2->r[12] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op00D4:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WB( sh2->ea, sh2->r[13] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op00E4:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WB( sh2->ea, sh2->r[14] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op00F4:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WB( sh2->ea, sh2->r[15] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0104:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WB( sh2->ea, sh2->r[0] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0114:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WB( sh2->ea, sh2->r[1] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0124:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WB( sh2->ea, sh2->r[2] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0134:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WB( sh2->ea, sh2->r[3] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0144:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WB( sh2->ea, sh2->r[4] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0154:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WB( sh2->ea, sh2->r[5] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0164:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WB( sh2->ea, sh2->r[6] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0174:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WB( sh2->ea, sh2->r[7] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0184:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WB( sh2->ea, sh2->r[8] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0194:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WB( sh2->ea, sh2->r[9] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op01A4:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WB( sh2->ea, sh2->r[10] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op01B4:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WB( sh2->ea, sh2->r[11] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op01C4:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WB( sh2->ea, sh2->r[12] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op01D4:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WB( sh2->ea, sh2->r[13] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op01E4:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WB( sh2->ea, sh2->r[14] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op01F4:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WB( sh2->ea, sh2->r[15] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0204:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WB( sh2->ea, sh2->r[0] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0214:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WB( sh2->ea, sh2->r[1] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0224:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WB( sh2->ea, sh2->r[2] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0234:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WB( sh2->ea, sh2->r[3] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0244:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WB( sh2->ea, sh2->r[4] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0254:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WB( sh2->ea, sh2->r[5] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0264:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WB( sh2->ea, sh2->r[6] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0274:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WB( sh2->ea, sh2->r[7] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0284:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WB( sh2->ea, sh2->r[8] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0294:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WB( sh2->ea, sh2->r[9] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op02A4:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WB( sh2->ea, sh2->r[10] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op02B4:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WB( sh2->ea, sh2->r[11] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op02C4:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WB( sh2->ea, sh2->r[12] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op02D4:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WB( sh2->ea, sh2->r[13] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op02E4:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WB( sh2->ea, sh2->r[14] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op02F4:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WB( sh2->ea, sh2->r[15] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0304:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WB( sh2->ea, sh2->r[0] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0314:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WB( sh2->ea, sh2->r[1] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0324:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WB( sh2->ea, sh2->r[2] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0334:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WB( sh2->ea, sh2->r[3] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0344:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WB( sh2->ea, sh2->r[4] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0354:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WB( sh2->ea, sh2->r[5] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0364:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WB( sh2->ea, sh2->r[6] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0374:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WB( sh2->ea, sh2->r[7] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0384:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WB( sh2->ea, sh2->r[8] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0394:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WB( sh2->ea, sh2->r[9] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op03A4:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WB( sh2->ea, sh2->r[10] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op03B4:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WB( sh2->ea, sh2->r[11] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op03C4:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WB( sh2->ea, sh2->r[12] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op03D4:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WB( sh2->ea, sh2->r[13] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op03E4:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WB( sh2->ea, sh2->r[14] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op03F4:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WB( sh2->ea, sh2->r[15] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0404:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WB( sh2->ea, sh2->r[0] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0414:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WB( sh2->ea, sh2->r[1] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0424:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WB( sh2->ea, sh2->r[2] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0434:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WB( sh2->ea, sh2->r[3] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0444:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WB( sh2->ea, sh2->r[4] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0454:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WB( sh2->ea, sh2->r[5] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0464:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WB( sh2->ea, sh2->r[6] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0474:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WB( sh2->ea, sh2->r[7] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0484:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WB( sh2->ea, sh2->r[8] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0494:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WB( sh2->ea, sh2->r[9] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op04A4:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WB( sh2->ea, sh2->r[10] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op04B4:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WB( sh2->ea, sh2->r[11] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op04C4:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WB( sh2->ea, sh2->r[12] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op04D4:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WB( sh2->ea, sh2->r[13] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op04E4:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WB( sh2->ea, sh2->r[14] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op04F4:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WB( sh2->ea, sh2->r[15] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0504:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WB( sh2->ea, sh2->r[0] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0514:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WB( sh2->ea, sh2->r[1] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0524:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WB( sh2->ea, sh2->r[2] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0534:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WB( sh2->ea, sh2->r[3] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0544:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WB( sh2->ea, sh2->r[4] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0554:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WB( sh2->ea, sh2->r[5] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0564:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WB( sh2->ea, sh2->r[6] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0574:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WB( sh2->ea, sh2->r[7] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0584:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WB( sh2->ea, sh2->r[8] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0594:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WB( sh2->ea, sh2->r[9] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op05A4:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WB( sh2->ea, sh2->r[10] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op05B4:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WB( sh2->ea, sh2->r[11] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op05C4:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WB( sh2->ea, sh2->r[12] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op05D4:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WB( sh2->ea, sh2->r[13] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op05E4:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WB( sh2->ea, sh2->r[14] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op05F4:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WB( sh2->ea, sh2->r[15] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0604:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WB( sh2->ea, sh2->r[0] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0614:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WB( sh2->ea, sh2->r[1] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0624:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WB( sh2->ea, sh2->r[2] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0634:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WB( sh2->ea, sh2->r[3] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0644:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WB( sh2->ea, sh2->r[4] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0654:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WB( sh2->ea, sh2->r[5] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0664:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WB( sh2->ea, sh2->r[6] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0674:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WB( sh2->ea, sh2->r[7] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0684:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WB( sh2->ea, sh2->r[8] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0694:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WB( sh2->ea, sh2->r[9] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op06A4:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WB( sh2->ea, sh2->r[10] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op06B4:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WB( sh2->ea, sh2->r[11] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op06C4:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WB( sh2->ea, sh2->r[12] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op06D4:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WB( sh2->ea, sh2->r[13] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op06E4:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WB( sh2->ea, sh2->r[14] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op06F4:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WB( sh2->ea, sh2->r[15] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0704:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WB( sh2->ea, sh2->r[0] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0714:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WB( sh2->ea, sh2->r[1] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0724:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WB( sh2->ea, sh2->r[2] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0734:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WB( sh2->ea, sh2->r[3] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0744:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WB( sh2->ea, sh2->r[4] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0754:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WB( sh2->ea, sh2->r[5] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0764:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WB( sh2->ea, sh2->r[6] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0774:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WB( sh2->ea, sh2->r[7] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0784:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WB( sh2->ea, sh2->r[8] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0794:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WB( sh2->ea, sh2->r[9] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op07A4:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WB( sh2->ea, sh2->r[10] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op07B4:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WB( sh2->ea, sh2->r[11] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op07C4:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WB( sh2->ea, sh2->r[12] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op07D4:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WB( sh2->ea, sh2->r[13] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op07E4:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WB( sh2->ea, sh2->r[14] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op07F4:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WB( sh2->ea, sh2->r[15] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0804:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WB( sh2->ea, sh2->r[0] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0814:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WB( sh2->ea, sh2->r[1] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0824:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WB( sh2->ea, sh2->r[2] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0834:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WB( sh2->ea, sh2->r[3] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0844:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WB( sh2->ea, sh2->r[4] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0854:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WB( sh2->ea, sh2->r[5] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0864:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WB( sh2->ea, sh2->r[6] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0874:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WB( sh2->ea, sh2->r[7] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0884:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WB( sh2->ea, sh2->r[8] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0894:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WB( sh2->ea, sh2->r[9] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op08A4:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WB( sh2->ea, sh2->r[10] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op08B4:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WB( sh2->ea, sh2->r[11] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op08C4:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WB( sh2->ea, sh2->r[12] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op08D4:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WB( sh2->ea, sh2->r[13] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op08E4:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WB( sh2->ea, sh2->r[14] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op08F4:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WB( sh2->ea, sh2->r[15] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0904:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WB( sh2->ea, sh2->r[0] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0914:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WB( sh2->ea, sh2->r[1] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0924:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WB( sh2->ea, sh2->r[2] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0934:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WB( sh2->ea, sh2->r[3] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0944:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WB( sh2->ea, sh2->r[4] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0954:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WB( sh2->ea, sh2->r[5] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0964:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WB( sh2->ea, sh2->r[6] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0974:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WB( sh2->ea, sh2->r[7] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0984:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WB( sh2->ea, sh2->r[8] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0994:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WB( sh2->ea, sh2->r[9] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op09A4:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WB( sh2->ea, sh2->r[10] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op09B4:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WB( sh2->ea, sh2->r[11] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op09C4:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WB( sh2->ea, sh2->r[12] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op09D4:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WB( sh2->ea, sh2->r[13] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op09E4:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WB( sh2->ea, sh2->r[14] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op09F4:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WB( sh2->ea, sh2->r[15] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0A04:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WB( sh2->ea, sh2->r[0] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0A14:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WB( sh2->ea, sh2->r[1] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0A24:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WB( sh2->ea, sh2->r[2] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0A34:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WB( sh2->ea, sh2->r[3] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0A44:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WB( sh2->ea, sh2->r[4] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0A54:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WB( sh2->ea, sh2->r[5] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0A64:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WB( sh2->ea, sh2->r[6] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0A74:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WB( sh2->ea, sh2->r[7] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0A84:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WB( sh2->ea, sh2->r[8] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0A94:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WB( sh2->ea, sh2->r[9] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0AA4:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WB( sh2->ea, sh2->r[10] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0AB4:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WB( sh2->ea, sh2->r[11] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0AC4:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WB( sh2->ea, sh2->r[12] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0AD4:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WB( sh2->ea, sh2->r[13] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0AE4:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WB( sh2->ea, sh2->r[14] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0AF4:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WB( sh2->ea, sh2->r[15] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0B04:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WB( sh2->ea, sh2->r[0] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0B14:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WB( sh2->ea, sh2->r[1] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0B24:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WB( sh2->ea, sh2->r[2] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0B34:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WB( sh2->ea, sh2->r[3] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0B44:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WB( sh2->ea, sh2->r[4] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0B54:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WB( sh2->ea, sh2->r[5] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0B64:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WB( sh2->ea, sh2->r[6] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0B74:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WB( sh2->ea, sh2->r[7] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0B84:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WB( sh2->ea, sh2->r[8] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0B94:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WB( sh2->ea, sh2->r[9] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0BA4:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WB( sh2->ea, sh2->r[10] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0BB4:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WB( sh2->ea, sh2->r[11] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0BC4:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WB( sh2->ea, sh2->r[12] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0BD4:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WB( sh2->ea, sh2->r[13] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0BE4:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WB( sh2->ea, sh2->r[14] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0BF4:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WB( sh2->ea, sh2->r[15] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0C04:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WB( sh2->ea, sh2->r[0] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0C14:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WB( sh2->ea, sh2->r[1] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0C24:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WB( sh2->ea, sh2->r[2] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0C34:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WB( sh2->ea, sh2->r[3] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0C44:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WB( sh2->ea, sh2->r[4] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0C54:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WB( sh2->ea, sh2->r[5] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0C64:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WB( sh2->ea, sh2->r[6] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0C74:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WB( sh2->ea, sh2->r[7] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0C84:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WB( sh2->ea, sh2->r[8] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0C94:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WB( sh2->ea, sh2->r[9] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0CA4:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WB( sh2->ea, sh2->r[10] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0CB4:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WB( sh2->ea, sh2->r[11] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0CC4:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WB( sh2->ea, sh2->r[12] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0CD4:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WB( sh2->ea, sh2->r[13] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0CE4:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WB( sh2->ea, sh2->r[14] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0CF4:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WB( sh2->ea, sh2->r[15] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0D04:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WB( sh2->ea, sh2->r[0] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0D14:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WB( sh2->ea, sh2->r[1] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0D24:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WB( sh2->ea, sh2->r[2] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0D34:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WB( sh2->ea, sh2->r[3] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0D44:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WB( sh2->ea, sh2->r[4] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0D54:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WB( sh2->ea, sh2->r[5] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0D64:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WB( sh2->ea, sh2->r[6] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0D74:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WB( sh2->ea, sh2->r[7] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0D84:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WB( sh2->ea, sh2->r[8] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0D94:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WB( sh2->ea, sh2->r[9] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0DA4:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WB( sh2->ea, sh2->r[10] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0DB4:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WB( sh2->ea, sh2->r[11] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0DC4:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WB( sh2->ea, sh2->r[12] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0DD4:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WB( sh2->ea, sh2->r[13] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0DE4:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WB( sh2->ea, sh2->r[14] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0DF4:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WB( sh2->ea, sh2->r[15] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0E04:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WB( sh2->ea, sh2->r[0] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0E14:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WB( sh2->ea, sh2->r[1] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0E24:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WB( sh2->ea, sh2->r[2] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0E34:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WB( sh2->ea, sh2->r[3] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0E44:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WB( sh2->ea, sh2->r[4] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0E54:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WB( sh2->ea, sh2->r[5] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0E64:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WB( sh2->ea, sh2->r[6] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0E74:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WB( sh2->ea, sh2->r[7] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0E84:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WB( sh2->ea, sh2->r[8] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0E94:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WB( sh2->ea, sh2->r[9] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0EA4:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WB( sh2->ea, sh2->r[10] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0EB4:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WB( sh2->ea, sh2->r[11] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0EC4:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WB( sh2->ea, sh2->r[12] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0ED4:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WB( sh2->ea, sh2->r[13] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0EE4:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WB( sh2->ea, sh2->r[14] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0EF4:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WB( sh2->ea, sh2->r[15] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0F04:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WB( sh2->ea, sh2->r[0] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0F14:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WB( sh2->ea, sh2->r[1] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0F24:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WB( sh2->ea, sh2->r[2] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0F34:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WB( sh2->ea, sh2->r[3] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0F44:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WB( sh2->ea, sh2->r[4] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0F54:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WB( sh2->ea, sh2->r[5] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0F64:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WB( sh2->ea, sh2->r[6] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0F74:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WB( sh2->ea, sh2->r[7] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0F84:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WB( sh2->ea, sh2->r[8] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0F94:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WB( sh2->ea, sh2->r[9] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0FA4:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WB( sh2->ea, sh2->r[10] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0FB4:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WB( sh2->ea, sh2->r[11] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0FC4:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WB( sh2->ea, sh2->r[12] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0FD4:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WB( sh2->ea, sh2->r[13] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0FE4:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WB( sh2->ea, sh2->r[14] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

Op0FF4:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WB( sh2->ea, sh2->r[15] & 0x000000ff );
	goto SH2_RUN_CONTINUE;
}

// MOV.W Rm,@(R0,Rn)
Op0005:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0015:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0025:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0035:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0045:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0055:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0065:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0075:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0085:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0095:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op00A5:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op00B5:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op00C5:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op00D5:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op00E5:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op00F5:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0105:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0115:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0125:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0135:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0145:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0155:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0165:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0175:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0185:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0195:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op01A5:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op01B5:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op01C5:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op01D5:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op01E5:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op01F5:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0205:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0215:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0225:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0235:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0245:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0255:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0265:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0275:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0285:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0295:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op02A5:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op02B5:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op02C5:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op02D5:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op02E5:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op02F5:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0305:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0315:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0325:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0335:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0345:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0355:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0365:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0375:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0385:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0395:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op03A5:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op03B5:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op03C5:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op03D5:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op03E5:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op03F5:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0405:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0415:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0425:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0435:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0445:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0455:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0465:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0475:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0485:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0495:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op04A5:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op04B5:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op04C5:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op04D5:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op04E5:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op04F5:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0505:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0515:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0525:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0535:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0545:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0555:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0565:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0575:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0585:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0595:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op05A5:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op05B5:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op05C5:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op05D5:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op05E5:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op05F5:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0605:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0615:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0625:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0635:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0645:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0655:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0665:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0675:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0685:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0695:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op06A5:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op06B5:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op06C5:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op06D5:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op06E5:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op06F5:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0705:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0715:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0725:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0735:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0745:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0755:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0765:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0775:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0785:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0795:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op07A5:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op07B5:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op07C5:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op07D5:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op07E5:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op07F5:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0805:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0815:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0825:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0835:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0845:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0855:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0865:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0875:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0885:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0895:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op08A5:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op08B5:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op08C5:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op08D5:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op08E5:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op08F5:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0905:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0915:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0925:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0935:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0945:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0955:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0965:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0975:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0985:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0995:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op09A5:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op09B5:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op09C5:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op09D5:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op09E5:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op09F5:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0A05:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0A15:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0A25:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0A35:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0A45:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0A55:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0A65:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0A75:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0A85:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0A95:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0AA5:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0AB5:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0AC5:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0AD5:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0AE5:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0AF5:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0B05:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0B15:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0B25:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0B35:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0B45:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0B55:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0B65:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0B75:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0B85:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0B95:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0BA5:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0BB5:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0BC5:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0BD5:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0BE5:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0BF5:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0C05:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0C15:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0C25:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0C35:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0C45:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0C55:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0C65:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0C75:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0C85:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0C95:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0CA5:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0CB5:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0CC5:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0CD5:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0CE5:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0CF5:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0D05:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0D15:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0D25:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0D35:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0D45:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0D55:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0D65:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0D75:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0D85:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0D95:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0DA5:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0DB5:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0DC5:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0DD5:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0DE5:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0DF5:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0E05:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0E15:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0E25:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0E35:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0E45:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0E55:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0E65:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0E75:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0E85:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0E95:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0EA5:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0EB5:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0EC5:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0ED5:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0EE5:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0EF5:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0F05:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0F15:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0F25:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0F35:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0F45:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0F55:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0F65:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0F75:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0F85:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0F95:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0FA5:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0FB5:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0FC5:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0FD5:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0FE5:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

Op0FF5:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff );
	goto SH2_RUN_CONTINUE;
}

// MOV.L Rm,@(R0,Rn)
Op0006:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op0016:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op0026:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op0036:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op0046:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op0056:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op0066:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op0076:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op0086:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op0096:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op00A6:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op00B6:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op00C6:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op00D6:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op00E6:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op00F6:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op0106:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op0116:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op0126:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op0136:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op0146:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op0156:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op0166:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op0176:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op0186:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op0196:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op01A6:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op01B6:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op01C6:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op01D6:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op01E6:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op01F6:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op0206:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op0216:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op0226:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op0236:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op0246:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op0256:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op0266:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op0276:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op0286:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op0296:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op02A6:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op02B6:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op02C6:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op02D6:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op02E6:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op02F6:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op0306:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op0316:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op0326:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op0336:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op0346:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op0356:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op0366:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op0376:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op0386:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op0396:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op03A6:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op03B6:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op03C6:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op03D6:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op03E6:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op03F6:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op0406:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op0416:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op0426:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op0436:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op0446:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op0456:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op0466:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op0476:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op0486:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op0496:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op04A6:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op04B6:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op04C6:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op04D6:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op04E6:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op04F6:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op0506:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op0516:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op0526:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op0536:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op0546:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op0556:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op0566:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op0576:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op0586:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op0596:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op05A6:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op05B6:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op05C6:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op05D6:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op05E6:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op05F6:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op0606:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op0616:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op0626:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op0636:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op0646:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op0656:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op0666:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op0676:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op0686:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op0696:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op06A6:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op06B6:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op06C6:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op06D6:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op06E6:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op06F6:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op0706:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op0716:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op0726:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op0736:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op0746:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op0756:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op0766:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op0776:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op0786:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op0796:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op07A6:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op07B6:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op07C6:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op07D6:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op07E6:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op07F6:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op0806:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op0816:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op0826:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op0836:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op0846:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op0856:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op0866:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op0876:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op0886:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op0896:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op08A6:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op08B6:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op08C6:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op08D6:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op08E6:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op08F6:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op0906:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op0916:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op0926:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op0936:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op0946:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op0956:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op0966:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op0976:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op0986:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op0996:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op09A6:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op09B6:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op09C6:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op09D6:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op09E6:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op09F6:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op0A06:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op0A16:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op0A26:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op0A36:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op0A46:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op0A56:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op0A66:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op0A76:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op0A86:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op0A96:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op0AA6:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op0AB6:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op0AC6:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op0AD6:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op0AE6:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op0AF6:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op0B06:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op0B16:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op0B26:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op0B36:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op0B46:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op0B56:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op0B66:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op0B76:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op0B86:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op0B96:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op0BA6:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op0BB6:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op0BC6:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op0BD6:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op0BE6:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op0BF6:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op0C06:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op0C16:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op0C26:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op0C36:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op0C46:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op0C56:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op0C66:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op0C76:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op0C86:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op0C96:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op0CA6:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op0CB6:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op0CC6:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op0CD6:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op0CE6:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op0CF6:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op0D06:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op0D16:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op0D26:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op0D36:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op0D46:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op0D56:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op0D66:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op0D76:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op0D86:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op0D96:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op0DA6:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op0DB6:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op0DC6:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op0DD6:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op0DE6:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op0DF6:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op0E06:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op0E16:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op0E26:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op0E36:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op0E46:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op0E56:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op0E66:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op0E76:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op0E86:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op0E96:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op0EA6:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op0EB6:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op0EC6:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op0ED6:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op0EE6:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op0EF6:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op0F06:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op0F16:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op0F26:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op0F36:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op0F46:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op0F56:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op0F66:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op0F76:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op0F86:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op0F96:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op0FA6:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op0FB6:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op0FC6:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op0FD6:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op0FE6:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op0FF6:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

// MUL.L Rm,Rn
Op0007:
{
	sh2->macl = sh2->r[0] * sh2->r[0];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0017:
{
	sh2->macl = sh2->r[0] * sh2->r[1];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0027:
{
	sh2->macl = sh2->r[0] * sh2->r[2];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0037:
{
	sh2->macl = sh2->r[0] * sh2->r[3];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0047:
{
	sh2->macl = sh2->r[0] * sh2->r[4];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0057:
{
	sh2->macl = sh2->r[0] * sh2->r[5];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0067:
{
	sh2->macl = sh2->r[0] * sh2->r[6];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0077:
{
	sh2->macl = sh2->r[0] * sh2->r[7];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0087:
{
	sh2->macl = sh2->r[0] * sh2->r[8];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0097:
{
	sh2->macl = sh2->r[0] * sh2->r[9];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op00A7:
{
	sh2->macl = sh2->r[0] * sh2->r[10];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op00B7:
{
	sh2->macl = sh2->r[0] * sh2->r[11];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op00C7:
{
	sh2->macl = sh2->r[0] * sh2->r[12];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op00D7:
{
	sh2->macl = sh2->r[0] * sh2->r[13];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op00E7:
{
	sh2->macl = sh2->r[0] * sh2->r[14];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op00F7:
{
	sh2->macl = sh2->r[0] * sh2->r[15];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0107:
{
	sh2->macl = sh2->r[1] * sh2->r[0];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0117:
{
	sh2->macl = sh2->r[1] * sh2->r[1];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0127:
{
	sh2->macl = sh2->r[1] * sh2->r[2];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0137:
{
	sh2->macl = sh2->r[1] * sh2->r[3];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0147:
{
	sh2->macl = sh2->r[1] * sh2->r[4];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0157:
{
	sh2->macl = sh2->r[1] * sh2->r[5];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0167:
{
	sh2->macl = sh2->r[1] * sh2->r[6];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0177:
{
	sh2->macl = sh2->r[1] * sh2->r[7];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0187:
{
	sh2->macl = sh2->r[1] * sh2->r[8];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0197:
{
	sh2->macl = sh2->r[1] * sh2->r[9];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op01A7:
{
	sh2->macl = sh2->r[1] * sh2->r[10];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op01B7:
{
	sh2->macl = sh2->r[1] * sh2->r[11];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op01C7:
{
	sh2->macl = sh2->r[1] * sh2->r[12];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op01D7:
{
	sh2->macl = sh2->r[1] * sh2->r[13];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op01E7:
{
	sh2->macl = sh2->r[1] * sh2->r[14];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op01F7:
{
	sh2->macl = sh2->r[1] * sh2->r[15];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0207:
{
	sh2->macl = sh2->r[2] * sh2->r[0];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0217:
{
	sh2->macl = sh2->r[2] * sh2->r[1];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0227:
{
	sh2->macl = sh2->r[2] * sh2->r[2];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0237:
{
	sh2->macl = sh2->r[2] * sh2->r[3];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0247:
{
	sh2->macl = sh2->r[2] * sh2->r[4];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0257:
{
	sh2->macl = sh2->r[2] * sh2->r[5];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0267:
{
	sh2->macl = sh2->r[2] * sh2->r[6];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0277:
{
	sh2->macl = sh2->r[2] * sh2->r[7];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0287:
{
	sh2->macl = sh2->r[2] * sh2->r[8];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0297:
{
	sh2->macl = sh2->r[2] * sh2->r[9];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op02A7:
{
	sh2->macl = sh2->r[2] * sh2->r[10];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op02B7:
{
	sh2->macl = sh2->r[2] * sh2->r[11];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op02C7:
{
	sh2->macl = sh2->r[2] * sh2->r[12];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op02D7:
{
	sh2->macl = sh2->r[2] * sh2->r[13];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op02E7:
{
	sh2->macl = sh2->r[2] * sh2->r[14];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op02F7:
{
	sh2->macl = sh2->r[2] * sh2->r[15];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0307:
{
	sh2->macl = sh2->r[3] * sh2->r[0];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0317:
{
	sh2->macl = sh2->r[3] * sh2->r[1];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0327:
{
	sh2->macl = sh2->r[3] * sh2->r[2];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0337:
{
	sh2->macl = sh2->r[3] * sh2->r[3];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0347:
{
	sh2->macl = sh2->r[3] * sh2->r[4];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0357:
{
	sh2->macl = sh2->r[3] * sh2->r[5];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0367:
{
	sh2->macl = sh2->r[3] * sh2->r[6];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0377:
{
	sh2->macl = sh2->r[3] * sh2->r[7];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0387:
{
	sh2->macl = sh2->r[3] * sh2->r[8];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0397:
{
	sh2->macl = sh2->r[3] * sh2->r[9];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op03A7:
{
	sh2->macl = sh2->r[3] * sh2->r[10];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op03B7:
{
	sh2->macl = sh2->r[3] * sh2->r[11];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op03C7:
{
	sh2->macl = sh2->r[3] * sh2->r[12];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op03D7:
{
	sh2->macl = sh2->r[3] * sh2->r[13];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op03E7:
{
	sh2->macl = sh2->r[3] * sh2->r[14];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op03F7:
{
	sh2->macl = sh2->r[3] * sh2->r[15];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0407:
{
	sh2->macl = sh2->r[4] * sh2->r[0];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0417:
{
	sh2->macl = sh2->r[4] * sh2->r[1];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0427:
{
	sh2->macl = sh2->r[4] * sh2->r[2];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0437:
{
	sh2->macl = sh2->r[4] * sh2->r[3];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0447:
{
	sh2->macl = sh2->r[4] * sh2->r[4];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0457:
{
	sh2->macl = sh2->r[4] * sh2->r[5];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0467:
{
	sh2->macl = sh2->r[4] * sh2->r[6];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0477:
{
	sh2->macl = sh2->r[4] * sh2->r[7];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0487:
{
	sh2->macl = sh2->r[4] * sh2->r[8];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0497:
{
	sh2->macl = sh2->r[4] * sh2->r[9];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op04A7:
{
	sh2->macl = sh2->r[4] * sh2->r[10];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op04B7:
{
	sh2->macl = sh2->r[4] * sh2->r[11];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op04C7:
{
	sh2->macl = sh2->r[4] * sh2->r[12];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op04D7:
{
	sh2->macl = sh2->r[4] * sh2->r[13];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op04E7:
{
	sh2->macl = sh2->r[4] * sh2->r[14];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op04F7:
{
	sh2->macl = sh2->r[4] * sh2->r[15];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0507:
{
	sh2->macl = sh2->r[5] * sh2->r[0];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0517:
{
	sh2->macl = sh2->r[5] * sh2->r[1];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0527:
{
	sh2->macl = sh2->r[5] * sh2->r[2];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0537:
{
	sh2->macl = sh2->r[5] * sh2->r[3];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0547:
{
	sh2->macl = sh2->r[5] * sh2->r[4];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0557:
{
	sh2->macl = sh2->r[5] * sh2->r[5];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0567:
{
	sh2->macl = sh2->r[5] * sh2->r[6];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0577:
{
	sh2->macl = sh2->r[5] * sh2->r[7];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0587:
{
	sh2->macl = sh2->r[5] * sh2->r[8];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0597:
{
	sh2->macl = sh2->r[5] * sh2->r[9];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op05A7:
{
	sh2->macl = sh2->r[5] * sh2->r[10];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op05B7:
{
	sh2->macl = sh2->r[5] * sh2->r[11];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op05C7:
{
	sh2->macl = sh2->r[5] * sh2->r[12];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op05D7:
{
	sh2->macl = sh2->r[5] * sh2->r[13];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op05E7:
{
	sh2->macl = sh2->r[5] * sh2->r[14];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op05F7:
{
	sh2->macl = sh2->r[5] * sh2->r[15];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0607:
{
	sh2->macl = sh2->r[6] * sh2->r[0];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0617:
{
	sh2->macl = sh2->r[6] * sh2->r[1];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0627:
{
	sh2->macl = sh2->r[6] * sh2->r[2];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0637:
{
	sh2->macl = sh2->r[6] * sh2->r[3];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0647:
{
	sh2->macl = sh2->r[6] * sh2->r[4];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0657:
{
	sh2->macl = sh2->r[6] * sh2->r[5];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0667:
{
	sh2->macl = sh2->r[6] * sh2->r[6];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0677:
{
	sh2->macl = sh2->r[6] * sh2->r[7];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0687:
{
	sh2->macl = sh2->r[6] * sh2->r[8];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0697:
{
	sh2->macl = sh2->r[6] * sh2->r[9];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op06A7:
{
	sh2->macl = sh2->r[6] * sh2->r[10];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op06B7:
{
	sh2->macl = sh2->r[6] * sh2->r[11];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op06C7:
{
	sh2->macl = sh2->r[6] * sh2->r[12];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op06D7:
{
	sh2->macl = sh2->r[6] * sh2->r[13];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op06E7:
{
	sh2->macl = sh2->r[6] * sh2->r[14];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op06F7:
{
	sh2->macl = sh2->r[6] * sh2->r[15];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0707:
{
	sh2->macl = sh2->r[7] * sh2->r[0];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0717:
{
	sh2->macl = sh2->r[7] * sh2->r[1];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0727:
{
	sh2->macl = sh2->r[7] * sh2->r[2];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0737:
{
	sh2->macl = sh2->r[7] * sh2->r[3];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0747:
{
	sh2->macl = sh2->r[7] * sh2->r[4];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0757:
{
	sh2->macl = sh2->r[7] * sh2->r[5];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0767:
{
	sh2->macl = sh2->r[7] * sh2->r[6];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0777:
{
	sh2->macl = sh2->r[7] * sh2->r[7];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0787:
{
	sh2->macl = sh2->r[7] * sh2->r[8];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0797:
{
	sh2->macl = sh2->r[7] * sh2->r[9];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op07A7:
{
	sh2->macl = sh2->r[7] * sh2->r[10];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op07B7:
{
	sh2->macl = sh2->r[7] * sh2->r[11];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op07C7:
{
	sh2->macl = sh2->r[7] * sh2->r[12];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op07D7:
{
	sh2->macl = sh2->r[7] * sh2->r[13];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op07E7:
{
	sh2->macl = sh2->r[7] * sh2->r[14];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op07F7:
{
	sh2->macl = sh2->r[7] * sh2->r[15];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0807:
{
	sh2->macl = sh2->r[8] * sh2->r[0];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0817:
{
	sh2->macl = sh2->r[8] * sh2->r[1];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0827:
{
	sh2->macl = sh2->r[8] * sh2->r[2];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0837:
{
	sh2->macl = sh2->r[8] * sh2->r[3];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0847:
{
	sh2->macl = sh2->r[8] * sh2->r[4];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0857:
{
	sh2->macl = sh2->r[8] * sh2->r[5];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0867:
{
	sh2->macl = sh2->r[8] * sh2->r[6];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0877:
{
	sh2->macl = sh2->r[8] * sh2->r[7];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0887:
{
	sh2->macl = sh2->r[8] * sh2->r[8];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0897:
{
	sh2->macl = sh2->r[8] * sh2->r[9];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op08A7:
{
	sh2->macl = sh2->r[8] * sh2->r[10];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op08B7:
{
	sh2->macl = sh2->r[8] * sh2->r[11];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op08C7:
{
	sh2->macl = sh2->r[8] * sh2->r[12];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op08D7:
{
	sh2->macl = sh2->r[8] * sh2->r[13];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op08E7:
{
	sh2->macl = sh2->r[8] * sh2->r[14];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op08F7:
{
	sh2->macl = sh2->r[8] * sh2->r[15];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0907:
{
	sh2->macl = sh2->r[9] * sh2->r[0];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0917:
{
	sh2->macl = sh2->r[9] * sh2->r[1];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0927:
{
	sh2->macl = sh2->r[9] * sh2->r[2];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0937:
{
	sh2->macl = sh2->r[9] * sh2->r[3];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0947:
{
	sh2->macl = sh2->r[9] * sh2->r[4];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0957:
{
	sh2->macl = sh2->r[9] * sh2->r[5];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0967:
{
	sh2->macl = sh2->r[9] * sh2->r[6];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0977:
{
	sh2->macl = sh2->r[9] * sh2->r[7];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0987:
{
	sh2->macl = sh2->r[9] * sh2->r[8];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0997:
{
	sh2->macl = sh2->r[9] * sh2->r[9];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op09A7:
{
	sh2->macl = sh2->r[9] * sh2->r[10];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op09B7:
{
	sh2->macl = sh2->r[9] * sh2->r[11];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op09C7:
{
	sh2->macl = sh2->r[9] * sh2->r[12];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op09D7:
{
	sh2->macl = sh2->r[9] * sh2->r[13];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op09E7:
{
	sh2->macl = sh2->r[9] * sh2->r[14];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op09F7:
{
	sh2->macl = sh2->r[9] * sh2->r[15];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0A07:
{
	sh2->macl = sh2->r[10] * sh2->r[0];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0A17:
{
	sh2->macl = sh2->r[10] * sh2->r[1];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0A27:
{
	sh2->macl = sh2->r[10] * sh2->r[2];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0A37:
{
	sh2->macl = sh2->r[10] * sh2->r[3];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0A47:
{
	sh2->macl = sh2->r[10] * sh2->r[4];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0A57:
{
	sh2->macl = sh2->r[10] * sh2->r[5];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0A67:
{
	sh2->macl = sh2->r[10] * sh2->r[6];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0A77:
{
	sh2->macl = sh2->r[10] * sh2->r[7];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0A87:
{
	sh2->macl = sh2->r[10] * sh2->r[8];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0A97:
{
	sh2->macl = sh2->r[10] * sh2->r[9];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0AA7:
{
	sh2->macl = sh2->r[10] * sh2->r[10];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0AB7:
{
	sh2->macl = sh2->r[10] * sh2->r[11];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0AC7:
{
	sh2->macl = sh2->r[10] * sh2->r[12];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0AD7:
{
	sh2->macl = sh2->r[10] * sh2->r[13];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0AE7:
{
	sh2->macl = sh2->r[10] * sh2->r[14];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0AF7:
{
	sh2->macl = sh2->r[10] * sh2->r[15];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0B07:
{
	sh2->macl = sh2->r[11] * sh2->r[0];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0B17:
{
	sh2->macl = sh2->r[11] * sh2->r[1];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0B27:
{
	sh2->macl = sh2->r[11] * sh2->r[2];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0B37:
{
	sh2->macl = sh2->r[11] * sh2->r[3];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0B47:
{
	sh2->macl = sh2->r[11] * sh2->r[4];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0B57:
{
	sh2->macl = sh2->r[11] * sh2->r[5];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0B67:
{
	sh2->macl = sh2->r[11] * sh2->r[6];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0B77:
{
	sh2->macl = sh2->r[11] * sh2->r[7];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0B87:
{
	sh2->macl = sh2->r[11] * sh2->r[8];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0B97:
{
	sh2->macl = sh2->r[11] * sh2->r[9];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0BA7:
{
	sh2->macl = sh2->r[11] * sh2->r[10];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0BB7:
{
	sh2->macl = sh2->r[11] * sh2->r[11];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0BC7:
{
	sh2->macl = sh2->r[11] * sh2->r[12];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0BD7:
{
	sh2->macl = sh2->r[11] * sh2->r[13];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0BE7:
{
	sh2->macl = sh2->r[11] * sh2->r[14];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0BF7:
{
	sh2->macl = sh2->r[11] * sh2->r[15];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0C07:
{
	sh2->macl = sh2->r[12] * sh2->r[0];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0C17:
{
	sh2->macl = sh2->r[12] * sh2->r[1];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0C27:
{
	sh2->macl = sh2->r[12] * sh2->r[2];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0C37:
{
	sh2->macl = sh2->r[12] * sh2->r[3];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0C47:
{
	sh2->macl = sh2->r[12] * sh2->r[4];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0C57:
{
	sh2->macl = sh2->r[12] * sh2->r[5];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0C67:
{
	sh2->macl = sh2->r[12] * sh2->r[6];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0C77:
{
	sh2->macl = sh2->r[12] * sh2->r[7];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0C87:
{
	sh2->macl = sh2->r[12] * sh2->r[8];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0C97:
{
	sh2->macl = sh2->r[12] * sh2->r[9];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0CA7:
{
	sh2->macl = sh2->r[12] * sh2->r[10];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0CB7:
{
	sh2->macl = sh2->r[12] * sh2->r[11];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0CC7:
{
	sh2->macl = sh2->r[12] * sh2->r[12];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0CD7:
{
	sh2->macl = sh2->r[12] * sh2->r[13];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0CE7:
{
	sh2->macl = sh2->r[12] * sh2->r[14];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0CF7:
{
	sh2->macl = sh2->r[12] * sh2->r[15];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0D07:
{
	sh2->macl = sh2->r[13] * sh2->r[0];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0D17:
{
	sh2->macl = sh2->r[13] * sh2->r[1];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0D27:
{
	sh2->macl = sh2->r[13] * sh2->r[2];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0D37:
{
	sh2->macl = sh2->r[13] * sh2->r[3];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0D47:
{
	sh2->macl = sh2->r[13] * sh2->r[4];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0D57:
{
	sh2->macl = sh2->r[13] * sh2->r[5];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0D67:
{
	sh2->macl = sh2->r[13] * sh2->r[6];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0D77:
{
	sh2->macl = sh2->r[13] * sh2->r[7];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0D87:
{
	sh2->macl = sh2->r[13] * sh2->r[8];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0D97:
{
	sh2->macl = sh2->r[13] * sh2->r[9];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0DA7:
{
	sh2->macl = sh2->r[13] * sh2->r[10];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0DB7:
{
	sh2->macl = sh2->r[13] * sh2->r[11];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0DC7:
{
	sh2->macl = sh2->r[13] * sh2->r[12];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0DD7:
{
	sh2->macl = sh2->r[13] * sh2->r[13];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0DE7:
{
	sh2->macl = sh2->r[13] * sh2->r[14];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0DF7:
{
	sh2->macl = sh2->r[13] * sh2->r[15];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0E07:
{
	sh2->macl = sh2->r[14] * sh2->r[0];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0E17:
{
	sh2->macl = sh2->r[14] * sh2->r[1];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0E27:
{
	sh2->macl = sh2->r[14] * sh2->r[2];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0E37:
{
	sh2->macl = sh2->r[14] * sh2->r[3];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0E47:
{
	sh2->macl = sh2->r[14] * sh2->r[4];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0E57:
{
	sh2->macl = sh2->r[14] * sh2->r[5];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0E67:
{
	sh2->macl = sh2->r[14] * sh2->r[6];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0E77:
{
	sh2->macl = sh2->r[14] * sh2->r[7];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0E87:
{
	sh2->macl = sh2->r[14] * sh2->r[8];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0E97:
{
	sh2->macl = sh2->r[14] * sh2->r[9];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0EA7:
{
	sh2->macl = sh2->r[14] * sh2->r[10];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0EB7:
{
	sh2->macl = sh2->r[14] * sh2->r[11];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0EC7:
{
	sh2->macl = sh2->r[14] * sh2->r[12];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0ED7:
{
	sh2->macl = sh2->r[14] * sh2->r[13];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0EE7:
{
	sh2->macl = sh2->r[14] * sh2->r[14];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0EF7:
{
	sh2->macl = sh2->r[14] * sh2->r[15];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0F07:
{
	sh2->macl = sh2->r[15] * sh2->r[0];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0F17:
{
	sh2->macl = sh2->r[15] * sh2->r[1];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0F27:
{
	sh2->macl = sh2->r[15] * sh2->r[2];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0F37:
{
	sh2->macl = sh2->r[15] * sh2->r[3];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0F47:
{
	sh2->macl = sh2->r[15] * sh2->r[4];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0F57:
{
	sh2->macl = sh2->r[15] * sh2->r[5];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0F67:
{
	sh2->macl = sh2->r[15] * sh2->r[6];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0F77:
{
	sh2->macl = sh2->r[15] * sh2->r[7];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0F87:
{
	sh2->macl = sh2->r[15] * sh2->r[8];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0F97:
{
	sh2->macl = sh2->r[15] * sh2->r[9];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0FA7:
{
	sh2->macl = sh2->r[15] * sh2->r[10];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0FB7:
{
	sh2->macl = sh2->r[15] * sh2->r[11];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0FC7:
{
	sh2->macl = sh2->r[15] * sh2->r[12];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0FD7:
{
	sh2->macl = sh2->r[15] * sh2->r[13];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0FE7:
{
	sh2->macl = sh2->r[15] * sh2->r[14];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0FF7:
{
	sh2->macl = sh2->r[15] * sh2->r[15];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

// CLRT
Op0008:
{
	sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

// STS MACH,Rn
Op000A:
{
	sh2->r[0] = sh2->mach;
	goto SH2_RUN_CONTINUE;
}

Op010A:
{
	sh2->r[1] = sh2->mach;
	goto SH2_RUN_CONTINUE;
}

Op020A:
{
	sh2->r[2] = sh2->mach;
	goto SH2_RUN_CONTINUE;
}

Op030A:
{
	sh2->r[3] = sh2->mach;
	goto SH2_RUN_CONTINUE;
}

Op040A:
{
	sh2->r[4] = sh2->mach;
	goto SH2_RUN_CONTINUE;
}

Op050A:
{
	sh2->r[5] = sh2->mach;
	goto SH2_RUN_CONTINUE;
}

Op060A:
{
	sh2->r[6] = sh2->mach;
	goto SH2_RUN_CONTINUE;
}

Op070A:
{
	sh2->r[7] = sh2->mach;
	goto SH2_RUN_CONTINUE;
}

Op080A:
{
	sh2->r[8] = sh2->mach;
	goto SH2_RUN_CONTINUE;
}

Op090A:
{
	sh2->r[9] = sh2->mach;
	goto SH2_RUN_CONTINUE;
}

Op0A0A:
{
	sh2->r[10] = sh2->mach;
	goto SH2_RUN_CONTINUE;
}

Op0B0A:
{
	sh2->r[11] = sh2->mach;
	goto SH2_RUN_CONTINUE;
}

Op0C0A:
{
	sh2->r[12] = sh2->mach;
	goto SH2_RUN_CONTINUE;
}

Op0D0A:
{
	sh2->r[13] = sh2->mach;
	goto SH2_RUN_CONTINUE;
}

Op0E0A:
{
	sh2->r[14] = sh2->mach;
	goto SH2_RUN_CONTINUE;
}

Op0F0A:
{
	sh2->r[15] = sh2->mach;
	goto SH2_RUN_CONTINUE;
}

// RTS
Op000B:
{
	sh2->delay = sh2->pc;
	sh2->pc = sh2->ea = sh2->pr;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

// MOV.B @(R0,Rm),Rn
Op000C:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op001C:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op002C:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op003C:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op004C:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op005C:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op006C:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op007C:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op008C:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op009C:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op00AC:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op00BC:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op00CC:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op00DC:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op00EC:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op00FC:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op010C:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op011C:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op012C:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op013C:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op014C:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op015C:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op016C:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op017C:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op018C:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op019C:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op01AC:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op01BC:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op01CC:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op01DC:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op01EC:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op01FC:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op020C:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op021C:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op022C:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op023C:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op024C:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op025C:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op026C:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op027C:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op028C:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op029C:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op02AC:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op02BC:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op02CC:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op02DC:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op02EC:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op02FC:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op030C:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op031C:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op032C:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op033C:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op034C:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op035C:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op036C:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op037C:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op038C:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op039C:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op03AC:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op03BC:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op03CC:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op03DC:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op03EC:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op03FC:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op040C:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op041C:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op042C:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op043C:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op044C:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op045C:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op046C:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op047C:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op048C:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op049C:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op04AC:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op04BC:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op04CC:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op04DC:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op04EC:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op04FC:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op050C:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op051C:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op052C:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op053C:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op054C:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op055C:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op056C:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op057C:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op058C:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op059C:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op05AC:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op05BC:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op05CC:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op05DC:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op05EC:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op05FC:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op060C:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op061C:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op062C:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op063C:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op064C:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op065C:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op066C:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op067C:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op068C:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op069C:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op06AC:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op06BC:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op06CC:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op06DC:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op06EC:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op06FC:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op070C:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op071C:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op072C:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op073C:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op074C:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op075C:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op076C:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op077C:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op078C:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op079C:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op07AC:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op07BC:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op07CC:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op07DC:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op07EC:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op07FC:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op080C:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op081C:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op082C:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op083C:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op084C:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op085C:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op086C:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op087C:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op088C:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op089C:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op08AC:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op08BC:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op08CC:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op08DC:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op08EC:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op08FC:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op090C:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op091C:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op092C:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op093C:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op094C:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op095C:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op096C:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op097C:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op098C:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op099C:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op09AC:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op09BC:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op09CC:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op09DC:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op09EC:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op09FC:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A0C:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A1C:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A2C:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A3C:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A4C:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A5C:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A6C:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A7C:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A8C:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A9C:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0AAC:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0ABC:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0ACC:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0ADC:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0AEC:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0AFC:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B0C:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B1C:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B2C:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B3C:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B4C:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B5C:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B6C:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B7C:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B8C:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B9C:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0BAC:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0BBC:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0BCC:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0BDC:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0BEC:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0BFC:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C0C:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C1C:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C2C:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C3C:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C4C:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C5C:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C6C:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C7C:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C8C:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C9C:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0CAC:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0CBC:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0CCC:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0CDC:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0CEC:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0CFC:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D0C:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D1C:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D2C:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D3C:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D4C:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D5C:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D6C:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D7C:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D8C:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D9C:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0DAC:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0DBC:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0DCC:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0DDC:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0DEC:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0DFC:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E0C:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E1C:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E2C:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E3C:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E4C:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E5C:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E6C:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E7C:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E8C:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E9C:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0EAC:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0EBC:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0ECC:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0EDC:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0EEC:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0EFC:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F0C:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F1C:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F2C:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F3C:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F4C:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F5C:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F6C:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F7C:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F8C:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F9C:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0FAC:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0FBC:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0FCC:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0FDC:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0FEC:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0FFC:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

// MOV.W @(R0,Rm),Rn
Op000D:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op001D:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op002D:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op003D:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op004D:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op005D:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op006D:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op007D:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op008D:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op009D:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op00AD:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op00BD:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op00CD:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op00DD:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op00ED:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op00FD:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op010D:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op011D:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op012D:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op013D:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op014D:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op015D:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op016D:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op017D:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op018D:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op019D:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op01AD:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op01BD:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op01CD:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op01DD:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op01ED:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op01FD:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op020D:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op021D:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op022D:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op023D:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op024D:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op025D:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op026D:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op027D:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op028D:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op029D:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op02AD:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op02BD:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op02CD:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op02DD:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op02ED:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op02FD:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op030D:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op031D:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op032D:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op033D:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op034D:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op035D:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op036D:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op037D:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op038D:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op039D:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op03AD:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op03BD:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op03CD:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op03DD:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op03ED:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op03FD:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op040D:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op041D:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op042D:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op043D:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op044D:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op045D:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op046D:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op047D:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op048D:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op049D:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op04AD:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op04BD:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op04CD:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op04DD:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op04ED:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op04FD:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op050D:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op051D:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op052D:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op053D:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op054D:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op055D:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op056D:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op057D:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op058D:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op059D:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op05AD:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op05BD:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op05CD:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op05DD:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op05ED:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op05FD:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op060D:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op061D:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op062D:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op063D:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op064D:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op065D:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op066D:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op067D:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op068D:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op069D:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op06AD:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op06BD:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op06CD:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op06DD:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op06ED:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op06FD:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op070D:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op071D:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op072D:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op073D:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op074D:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op075D:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op076D:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op077D:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op078D:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op079D:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op07AD:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op07BD:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op07CD:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op07DD:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op07ED:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op07FD:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op080D:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op081D:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op082D:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op083D:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op084D:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op085D:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op086D:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op087D:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op088D:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op089D:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op08AD:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op08BD:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op08CD:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op08DD:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op08ED:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op08FD:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op090D:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op091D:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op092D:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op093D:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op094D:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op095D:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op096D:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op097D:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op098D:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op099D:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op09AD:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op09BD:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op09CD:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op09DD:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op09ED:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op09FD:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A0D:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A1D:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A2D:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A3D:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A4D:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A5D:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A6D:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A7D:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A8D:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A9D:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0AAD:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0ABD:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0ACD:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0ADD:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0AED:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0AFD:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B0D:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B1D:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B2D:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B3D:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B4D:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B5D:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B6D:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B7D:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B8D:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B9D:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0BAD:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0BBD:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0BCD:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0BDD:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0BED:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0BFD:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C0D:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C1D:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C2D:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C3D:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C4D:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C5D:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C6D:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C7D:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C8D:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C9D:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0CAD:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0CBD:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0CCD:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0CDD:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0CED:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0CFD:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D0D:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D1D:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D2D:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D3D:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D4D:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D5D:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D6D:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D7D:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D8D:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D9D:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0DAD:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0DBD:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0DCD:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0DDD:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0DED:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0DFD:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E0D:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E1D:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E2D:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E3D:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E4D:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E5D:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E6D:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E7D:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E8D:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E9D:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0EAD:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0EBD:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0ECD:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0EDD:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0EED:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0EFD:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F0D:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F1D:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F2D:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F3D:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F4D:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F5D:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F6D:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F7D:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F8D:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F9D:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0FAD:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0FBD:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0FCD:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0FDD:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0FED:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0FFD:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

// MOV.L @(R0,Rm),Rn
Op000E:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op001E:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op002E:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op003E:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op004E:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op005E:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op006E:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op007E:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op008E:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op009E:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op00AE:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op00BE:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op00CE:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op00DE:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op00EE:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op00FE:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op010E:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op011E:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op012E:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op013E:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op014E:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op015E:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op016E:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op017E:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op018E:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op019E:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op01AE:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op01BE:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op01CE:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op01DE:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op01EE:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op01FE:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op020E:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op021E:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op022E:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op023E:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op024E:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op025E:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op026E:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op027E:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op028E:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op029E:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op02AE:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op02BE:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op02CE:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op02DE:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op02EE:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op02FE:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op030E:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op031E:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op032E:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op033E:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op034E:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op035E:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op036E:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op037E:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op038E:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op039E:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op03AE:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op03BE:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op03CE:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op03DE:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op03EE:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op03FE:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op040E:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op041E:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op042E:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op043E:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op044E:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op045E:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op046E:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op047E:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op048E:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op049E:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op04AE:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op04BE:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op04CE:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op04DE:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op04EE:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op04FE:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op050E:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op051E:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op052E:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op053E:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op054E:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op055E:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op056E:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op057E:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op058E:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op059E:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op05AE:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op05BE:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op05CE:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op05DE:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op05EE:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op05FE:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op060E:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op061E:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op062E:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op063E:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op064E:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op065E:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op066E:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op067E:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op068E:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op069E:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op06AE:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op06BE:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op06CE:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op06DE:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op06EE:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op06FE:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op070E:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op071E:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op072E:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op073E:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op074E:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op075E:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op076E:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op077E:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op078E:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op079E:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op07AE:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op07BE:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op07CE:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op07DE:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op07EE:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op07FE:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op080E:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op081E:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op082E:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op083E:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op084E:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op085E:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op086E:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op087E:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op088E:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op089E:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op08AE:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op08BE:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op08CE:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op08DE:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op08EE:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op08FE:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op090E:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op091E:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op092E:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op093E:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op094E:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op095E:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op096E:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op097E:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op098E:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op099E:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op09AE:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op09BE:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op09CE:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op09DE:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op09EE:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op09FE:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A0E:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A1E:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A2E:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A3E:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A4E:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A5E:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A6E:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A7E:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A8E:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0A9E:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0AAE:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0ABE:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0ACE:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0ADE:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0AEE:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0AFE:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B0E:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B1E:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B2E:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B3E:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B4E:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B5E:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B6E:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B7E:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B8E:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0B9E:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0BAE:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0BBE:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0BCE:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0BDE:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0BEE:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0BFE:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C0E:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C1E:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C2E:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C3E:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C4E:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C5E:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C6E:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C7E:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C8E:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0C9E:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0CAE:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0CBE:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0CCE:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0CDE:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0CEE:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0CFE:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D0E:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D1E:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D2E:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D3E:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D4E:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D5E:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D6E:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D7E:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D8E:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0D9E:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0DAE:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0DBE:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0DCE:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0DDE:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0DEE:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0DFE:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E0E:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E1E:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E2E:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E3E:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E4E:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E5E:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E6E:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E7E:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E8E:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0E9E:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0EAE:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0EBE:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0ECE:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0EDE:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0EEE:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0EFE:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F0E:
{
	sh2->ea = sh2->r[0] + sh2->r[0];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F1E:
{
	sh2->ea = sh2->r[1] + sh2->r[0];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F2E:
{
	sh2->ea = sh2->r[2] + sh2->r[0];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F3E:
{
	sh2->ea = sh2->r[3] + sh2->r[0];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F4E:
{
	sh2->ea = sh2->r[4] + sh2->r[0];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F5E:
{
	sh2->ea = sh2->r[5] + sh2->r[0];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F6E:
{
	sh2->ea = sh2->r[6] + sh2->r[0];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F7E:
{
	sh2->ea = sh2->r[7] + sh2->r[0];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F8E:
{
	sh2->ea = sh2->r[8] + sh2->r[0];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0F9E:
{
	sh2->ea = sh2->r[9] + sh2->r[0];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0FAE:
{
	sh2->ea = sh2->r[10] + sh2->r[0];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0FBE:
{
	sh2->ea = sh2->r[11] + sh2->r[0];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0FCE:
{
	sh2->ea = sh2->r[12] + sh2->r[0];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0FDE:
{
	sh2->ea = sh2->r[13] + sh2->r[0];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0FEE:
{
	sh2->ea = sh2->r[14] + sh2->r[0];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op0FFE:
{
	sh2->ea = sh2->r[15] + sh2->r[0];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

// MAC.L @Rm+,@Rn+
Op000F:
{
	n = (opcode>>8) & 0x0f;
	m = (opcode>>4) & 0x0f;
	tempn = (INT32) RL( sh2->r[n] );
	sh2->r[n] += 4;
	tempm = (INT32) RL( sh2->r[m] );
	sh2->r[m] += 4;
	if ((INT32) (tempn ^ tempm) < 0)
		fnLmL = -1;
	else
		fnLmL = 0;
	if (tempn < 0)
		tempn = 0 - tempn;
	if (tempm < 0)
		tempm = 0 - tempm;
	temp1 = (UINT32) tempn;
	temp2 = (UINT32) tempm;
	RnL = temp1 & 0x0000ffff;
	RnH = (temp1 >> 16) & 0x0000ffff;
	RmL = temp2 & 0x0000ffff;
	RmH = (temp2 >> 16) & 0x0000ffff;
	temp0 = RmL * RnL;
	temp1 = RmH * RnL;
	temp2 = RmL * RnH;
	temp3 = RmH * RnH;
	Res2 = 0;
	Res1 = temp1 + temp2;
	if (Res1 < temp1)
		Res2 += 0x00010000;
	temp1 = (Res1 << 16) & 0xffff0000;
	Res0 = temp0 + temp1;
	if (Res0 < temp0)
		Res2++;
	Res2 = Res2 + ((Res1 >> 16) & 0x0000ffff) + temp3;
	if (fnLmL < 0)
	{
		Res2 = ~Res2;
		if (Res0 == 0)
			Res2++;
		else
			Res0 = (~Res0) + 1;
	}
	if (sh2->sr & S)
	{
		Res0 = sh2->macl + Res0;
		if (sh2->macl > Res0)
			Res2++;
		Res2 += (sh2->mach & 0x0000ffff);
		if (((INT32) Res2 < 0) && (Res2 < 0xffff8000))
		{
			Res2 = 0x00008000;
			Res0 = 0x00000000;
		}
		else if (((INT32) Res2 > 0) && (Res2 > 0x00007fff))
		{
			Res2 = 0x00007fff;
			Res0 = 0xffffffff;
		}
		sh2->mach = Res2;
		sh2->macl = Res0;
	}
	else
	{
		Res0 = sh2->macl + Res0;
		if (sh2->macl > Res0)
			Res2++;
		Res2 += sh2->mach;
		sh2->mach = Res2;
		sh2->macl = Res0;
	}
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

// STC GBR,Rn
Op0012:
{
	sh2->r[0] = sh2->gbr;
	goto SH2_RUN_CONTINUE;
}

Op0112:
{
	sh2->r[1] = sh2->gbr;
	goto SH2_RUN_CONTINUE;
}

Op0212:
{
	sh2->r[2] = sh2->gbr;
	goto SH2_RUN_CONTINUE;
}

Op0312:
{
	sh2->r[3] = sh2->gbr;
	goto SH2_RUN_CONTINUE;
}

Op0412:
{
	sh2->r[4] = sh2->gbr;
	goto SH2_RUN_CONTINUE;
}

Op0512:
{
	sh2->r[5] = sh2->gbr;
	goto SH2_RUN_CONTINUE;
}

Op0612:
{
	sh2->r[6] = sh2->gbr;
	goto SH2_RUN_CONTINUE;
}

Op0712:
{
	sh2->r[7] = sh2->gbr;
	goto SH2_RUN_CONTINUE;
}

Op0812:
{
	sh2->r[8] = sh2->gbr;
	goto SH2_RUN_CONTINUE;
}

Op0912:
{
	sh2->r[9] = sh2->gbr;
	goto SH2_RUN_CONTINUE;
}

Op0A12:
{
	sh2->r[10] = sh2->gbr;
	goto SH2_RUN_CONTINUE;
}

Op0B12:
{
	sh2->r[11] = sh2->gbr;
	goto SH2_RUN_CONTINUE;
}

Op0C12:
{
	sh2->r[12] = sh2->gbr;
	goto SH2_RUN_CONTINUE;
}

Op0D12:
{
	sh2->r[13] = sh2->gbr;
	goto SH2_RUN_CONTINUE;
}

Op0E12:
{
	sh2->r[14] = sh2->gbr;
	goto SH2_RUN_CONTINUE;
}

Op0F12:
{
	sh2->r[15] = sh2->gbr;
	goto SH2_RUN_CONTINUE;
}

// SETT
Op0018:
{
	sh2->sr |= T;
	goto SH2_RUN_CONTINUE;
}

// DIV0U
Op0019:
{
	sh2->sr &= ~(M | Q | T);
	goto SH2_RUN_CONTINUE;
}

// STS MACL,Rn
Op001A:
{
	sh2->r[0] = sh2->macl;
	goto SH2_RUN_CONTINUE;
}

Op011A:
{
	sh2->r[1] = sh2->macl;
	goto SH2_RUN_CONTINUE;
}

Op021A:
{
	sh2->r[2] = sh2->macl;
	goto SH2_RUN_CONTINUE;
}

Op031A:
{
	sh2->r[3] = sh2->macl;
	goto SH2_RUN_CONTINUE;
}

Op041A:
{
	sh2->r[4] = sh2->macl;
	goto SH2_RUN_CONTINUE;
}

Op051A:
{
	sh2->r[5] = sh2->macl;
	goto SH2_RUN_CONTINUE;
}

Op061A:
{
	sh2->r[6] = sh2->macl;
	goto SH2_RUN_CONTINUE;
}

Op071A:
{
	sh2->r[7] = sh2->macl;
	goto SH2_RUN_CONTINUE;
}

Op081A:
{
	sh2->r[8] = sh2->macl;
	goto SH2_RUN_CONTINUE;
}

Op091A:
{
	sh2->r[9] = sh2->macl;
	goto SH2_RUN_CONTINUE;
}

Op0A1A:
{
	sh2->r[10] = sh2->macl;
	goto SH2_RUN_CONTINUE;
}

Op0B1A:
{
	sh2->r[11] = sh2->macl;
	goto SH2_RUN_CONTINUE;
}

Op0C1A:
{
	sh2->r[12] = sh2->macl;
	goto SH2_RUN_CONTINUE;
}

Op0D1A:
{
	sh2->r[13] = sh2->macl;
	goto SH2_RUN_CONTINUE;
}

Op0E1A:
{
	sh2->r[14] = sh2->macl;
	goto SH2_RUN_CONTINUE;
}

Op0F1A:
{
	sh2->r[15] = sh2->macl;
	goto SH2_RUN_CONTINUE;
}

// SLEEP
Op001B:
{
	sh2->pc -= 2;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

// STC VBR,Rn
Op0022:
{
	sh2->r[0] = sh2->vbr;
	goto SH2_RUN_CONTINUE;
}

Op0122:
{
	sh2->r[1] = sh2->vbr;
	goto SH2_RUN_CONTINUE;
}

Op0222:
{
	sh2->r[2] = sh2->vbr;
	goto SH2_RUN_CONTINUE;
}

Op0322:
{
	sh2->r[3] = sh2->vbr;
	goto SH2_RUN_CONTINUE;
}

Op0422:
{
	sh2->r[4] = sh2->vbr;
	goto SH2_RUN_CONTINUE;
}

Op0522:
{
	sh2->r[5] = sh2->vbr;
	goto SH2_RUN_CONTINUE;
}

Op0622:
{
	sh2->r[6] = sh2->vbr;
	goto SH2_RUN_CONTINUE;
}

Op0722:
{
	sh2->r[7] = sh2->vbr;
	goto SH2_RUN_CONTINUE;
}

Op0822:
{
	sh2->r[8] = sh2->vbr;
	goto SH2_RUN_CONTINUE;
}

Op0922:
{
	sh2->r[9] = sh2->vbr;
	goto SH2_RUN_CONTINUE;
}

Op0A22:
{
	sh2->r[10] = sh2->vbr;
	goto SH2_RUN_CONTINUE;
}

Op0B22:
{
	sh2->r[11] = sh2->vbr;
	goto SH2_RUN_CONTINUE;
}

Op0C22:
{
	sh2->r[12] = sh2->vbr;
	goto SH2_RUN_CONTINUE;
}

Op0D22:
{
	sh2->r[13] = sh2->vbr;
	goto SH2_RUN_CONTINUE;
}

Op0E22:
{
	sh2->r[14] = sh2->vbr;
	goto SH2_RUN_CONTINUE;
}

Op0F22:
{
	sh2->r[15] = sh2->vbr;
	goto SH2_RUN_CONTINUE;
}

// BRAF Rn
Op0023:
{
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[0] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0123:
{
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[1] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0223:
{
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[2] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0323:
{
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[3] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0423:
{
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[4] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0523:
{
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[5] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0623:
{
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[6] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0723:
{
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[7] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0823:
{
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[8] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0923:
{
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[9] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0A23:
{
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[10] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0B23:
{
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[11] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0C23:
{
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[12] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0D23:
{
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[13] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0E23:
{
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[14] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op0F23:
{
	sh2->delay = sh2->pc;
	sh2->pc += sh2->r[15] + 2;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

// CLRMAC
Op0028:
{
	sh2->mach = 0;
	sh2->macl = 0;
	goto SH2_RUN_CONTINUE;
}

// MOVT Rn
Op0029:
{
	sh2->r[0] = sh2->sr & T;
	goto SH2_RUN_CONTINUE;
}

Op0129:
{
	sh2->r[1] = sh2->sr & T;
	goto SH2_RUN_CONTINUE;
}

Op0229:
{
	sh2->r[2] = sh2->sr & T;
	goto SH2_RUN_CONTINUE;
}

Op0329:
{
	sh2->r[3] = sh2->sr & T;
	goto SH2_RUN_CONTINUE;
}

Op0429:
{
	sh2->r[4] = sh2->sr & T;
	goto SH2_RUN_CONTINUE;
}

Op0529:
{
	sh2->r[5] = sh2->sr & T;
	goto SH2_RUN_CONTINUE;
}

Op0629:
{
	sh2->r[6] = sh2->sr & T;
	goto SH2_RUN_CONTINUE;
}

Op0729:
{
	sh2->r[7] = sh2->sr & T;
	goto SH2_RUN_CONTINUE;
}

Op0829:
{
	sh2->r[8] = sh2->sr & T;
	goto SH2_RUN_CONTINUE;
}

Op0929:
{
	sh2->r[9] = sh2->sr & T;
	goto SH2_RUN_CONTINUE;
}

Op0A29:
{
	sh2->r[10] = sh2->sr & T;
	goto SH2_RUN_CONTINUE;
}

Op0B29:
{
	sh2->r[11] = sh2->sr & T;
	goto SH2_RUN_CONTINUE;
}

Op0C29:
{
	sh2->r[12] = sh2->sr & T;
	goto SH2_RUN_CONTINUE;
}

Op0D29:
{
	sh2->r[13] = sh2->sr & T;
	goto SH2_RUN_CONTINUE;
}

Op0E29:
{
	sh2->r[14] = sh2->sr & T;
	goto SH2_RUN_CONTINUE;
}

Op0F29:
{
	sh2->r[15] = sh2->sr & T;
	goto SH2_RUN_CONTINUE;
}

// STS PR,Rn
Op002A:
{
	sh2->r[0] = sh2->pr;
	goto SH2_RUN_CONTINUE;
}

Op012A:
{
	sh2->r[1] = sh2->pr;
	goto SH2_RUN_CONTINUE;
}

Op022A:
{
	sh2->r[2] = sh2->pr;
	goto SH2_RUN_CONTINUE;
}

Op032A:
{
	sh2->r[3] = sh2->pr;
	goto SH2_RUN_CONTINUE;
}

Op042A:
{
	sh2->r[4] = sh2->pr;
	goto SH2_RUN_CONTINUE;
}

Op052A:
{
	sh2->r[5] = sh2->pr;
	goto SH2_RUN_CONTINUE;
}

Op062A:
{
	sh2->r[6] = sh2->pr;
	goto SH2_RUN_CONTINUE;
}

Op072A:
{
	sh2->r[7] = sh2->pr;
	goto SH2_RUN_CONTINUE;
}

Op082A:
{
	sh2->r[8] = sh2->pr;
	goto SH2_RUN_CONTINUE;
}

Op092A:
{
	sh2->r[9] = sh2->pr;
	goto SH2_RUN_CONTINUE;
}

Op0A2A:
{
	sh2->r[10] = sh2->pr;
	goto SH2_RUN_CONTINUE;
}

Op0B2A:
{
	sh2->r[11] = sh2->pr;
	goto SH2_RUN_CONTINUE;
}

Op0C2A:
{
	sh2->r[12] = sh2->pr;
	goto SH2_RUN_CONTINUE;
}

Op0D2A:
{
	sh2->r[13] = sh2->pr;
	goto SH2_RUN_CONTINUE;
}

Op0E2A:
{
	sh2->r[14] = sh2->pr;
	goto SH2_RUN_CONTINUE;
}

Op0F2A:
{
	sh2->r[15] = sh2->pr;
	goto SH2_RUN_CONTINUE;
}

// RTE
Op002B:
{
	sh2->ea = sh2->r[15];
	sh2->delay = sh2->pc;
	sh2->pc = RL( sh2->ea );
	sh2->r[15] += 4;
	sh2->ea = sh2->r[15];
	sh2->sr = RL( sh2->ea ) & FLAGS;
	sh2->r[15] += 4;
	sh2->sh2_icount -= 3;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

// MOV.L Rm,@(disp4,Rn)
Op1000:
{
	sh2->ea = sh2->r[(opcode>>8) & 0x0f] + ((opcode<<2) & 0x3c);
	WL( sh2->ea, sh2->r[(opcode>>4) & 0x0f] );
	goto SH2_RUN_CONTINUE;
}

// MOV.B Rm,@Rn
Op2000:
{
	sh2->ea = sh2->r[0];
	WB( sh2->ea, sh2->r[0] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2010:
{
	sh2->ea = sh2->r[0];
	WB( sh2->ea, sh2->r[1] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2020:
{
	sh2->ea = sh2->r[0];
	WB( sh2->ea, sh2->r[2] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2030:
{
	sh2->ea = sh2->r[0];
	WB( sh2->ea, sh2->r[3] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2040:
{
	sh2->ea = sh2->r[0];
	WB( sh2->ea, sh2->r[4] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2050:
{
	sh2->ea = sh2->r[0];
	WB( sh2->ea, sh2->r[5] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2060:
{
	sh2->ea = sh2->r[0];
	WB( sh2->ea, sh2->r[6] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2070:
{
	sh2->ea = sh2->r[0];
	WB( sh2->ea, sh2->r[7] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2080:
{
	sh2->ea = sh2->r[0];
	WB( sh2->ea, sh2->r[8] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2090:
{
	sh2->ea = sh2->r[0];
	WB( sh2->ea, sh2->r[9] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op20A0:
{
	sh2->ea = sh2->r[0];
	WB( sh2->ea, sh2->r[10] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op20B0:
{
	sh2->ea = sh2->r[0];
	WB( sh2->ea, sh2->r[11] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op20C0:
{
	sh2->ea = sh2->r[0];
	WB( sh2->ea, sh2->r[12] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op20D0:
{
	sh2->ea = sh2->r[0];
	WB( sh2->ea, sh2->r[13] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op20E0:
{
	sh2->ea = sh2->r[0];
	WB( sh2->ea, sh2->r[14] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op20F0:
{
	sh2->ea = sh2->r[0];
	WB( sh2->ea, sh2->r[15] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2100:
{
	sh2->ea = sh2->r[1];
	WB( sh2->ea, sh2->r[0] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2110:
{
	sh2->ea = sh2->r[1];
	WB( sh2->ea, sh2->r[1] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2120:
{
	sh2->ea = sh2->r[1];
	WB( sh2->ea, sh2->r[2] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2130:
{
	sh2->ea = sh2->r[1];
	WB( sh2->ea, sh2->r[3] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2140:
{
	sh2->ea = sh2->r[1];
	WB( sh2->ea, sh2->r[4] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2150:
{
	sh2->ea = sh2->r[1];
	WB( sh2->ea, sh2->r[5] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2160:
{
	sh2->ea = sh2->r[1];
	WB( sh2->ea, sh2->r[6] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2170:
{
	sh2->ea = sh2->r[1];
	WB( sh2->ea, sh2->r[7] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2180:
{
	sh2->ea = sh2->r[1];
	WB( sh2->ea, sh2->r[8] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2190:
{
	sh2->ea = sh2->r[1];
	WB( sh2->ea, sh2->r[9] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op21A0:
{
	sh2->ea = sh2->r[1];
	WB( sh2->ea, sh2->r[10] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op21B0:
{
	sh2->ea = sh2->r[1];
	WB( sh2->ea, sh2->r[11] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op21C0:
{
	sh2->ea = sh2->r[1];
	WB( sh2->ea, sh2->r[12] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op21D0:
{
	sh2->ea = sh2->r[1];
	WB( sh2->ea, sh2->r[13] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op21E0:
{
	sh2->ea = sh2->r[1];
	WB( sh2->ea, sh2->r[14] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op21F0:
{
	sh2->ea = sh2->r[1];
	WB( sh2->ea, sh2->r[15] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2200:
{
	sh2->ea = sh2->r[2];
	WB( sh2->ea, sh2->r[0] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2210:
{
	sh2->ea = sh2->r[2];
	WB( sh2->ea, sh2->r[1] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2220:
{
	sh2->ea = sh2->r[2];
	WB( sh2->ea, sh2->r[2] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2230:
{
	sh2->ea = sh2->r[2];
	WB( sh2->ea, sh2->r[3] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2240:
{
	sh2->ea = sh2->r[2];
	WB( sh2->ea, sh2->r[4] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2250:
{
	sh2->ea = sh2->r[2];
	WB( sh2->ea, sh2->r[5] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2260:
{
	sh2->ea = sh2->r[2];
	WB( sh2->ea, sh2->r[6] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2270:
{
	sh2->ea = sh2->r[2];
	WB( sh2->ea, sh2->r[7] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2280:
{
	sh2->ea = sh2->r[2];
	WB( sh2->ea, sh2->r[8] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2290:
{
	sh2->ea = sh2->r[2];
	WB( sh2->ea, sh2->r[9] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op22A0:
{
	sh2->ea = sh2->r[2];
	WB( sh2->ea, sh2->r[10] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op22B0:
{
	sh2->ea = sh2->r[2];
	WB( sh2->ea, sh2->r[11] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op22C0:
{
	sh2->ea = sh2->r[2];
	WB( sh2->ea, sh2->r[12] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op22D0:
{
	sh2->ea = sh2->r[2];
	WB( sh2->ea, sh2->r[13] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op22E0:
{
	sh2->ea = sh2->r[2];
	WB( sh2->ea, sh2->r[14] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op22F0:
{
	sh2->ea = sh2->r[2];
	WB( sh2->ea, sh2->r[15] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2300:
{
	sh2->ea = sh2->r[3];
	WB( sh2->ea, sh2->r[0] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2310:
{
	sh2->ea = sh2->r[3];
	WB( sh2->ea, sh2->r[1] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2320:
{
	sh2->ea = sh2->r[3];
	WB( sh2->ea, sh2->r[2] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2330:
{
	sh2->ea = sh2->r[3];
	WB( sh2->ea, sh2->r[3] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2340:
{
	sh2->ea = sh2->r[3];
	WB( sh2->ea, sh2->r[4] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2350:
{
	sh2->ea = sh2->r[3];
	WB( sh2->ea, sh2->r[5] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2360:
{
	sh2->ea = sh2->r[3];
	WB( sh2->ea, sh2->r[6] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2370:
{
	sh2->ea = sh2->r[3];
	WB( sh2->ea, sh2->r[7] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2380:
{
	sh2->ea = sh2->r[3];
	WB( sh2->ea, sh2->r[8] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2390:
{
	sh2->ea = sh2->r[3];
	WB( sh2->ea, sh2->r[9] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op23A0:
{
	sh2->ea = sh2->r[3];
	WB( sh2->ea, sh2->r[10] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op23B0:
{
	sh2->ea = sh2->r[3];
	WB( sh2->ea, sh2->r[11] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op23C0:
{
	sh2->ea = sh2->r[3];
	WB( sh2->ea, sh2->r[12] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op23D0:
{
	sh2->ea = sh2->r[3];
	WB( sh2->ea, sh2->r[13] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op23E0:
{
	sh2->ea = sh2->r[3];
	WB( sh2->ea, sh2->r[14] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op23F0:
{
	sh2->ea = sh2->r[3];
	WB( sh2->ea, sh2->r[15] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2400:
{
	sh2->ea = sh2->r[4];
	WB( sh2->ea, sh2->r[0] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2410:
{
	sh2->ea = sh2->r[4];
	WB( sh2->ea, sh2->r[1] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2420:
{
	sh2->ea = sh2->r[4];
	WB( sh2->ea, sh2->r[2] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2430:
{
	sh2->ea = sh2->r[4];
	WB( sh2->ea, sh2->r[3] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2440:
{
	sh2->ea = sh2->r[4];
	WB( sh2->ea, sh2->r[4] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2450:
{
	sh2->ea = sh2->r[4];
	WB( sh2->ea, sh2->r[5] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2460:
{
	sh2->ea = sh2->r[4];
	WB( sh2->ea, sh2->r[6] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2470:
{
	sh2->ea = sh2->r[4];
	WB( sh2->ea, sh2->r[7] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2480:
{
	sh2->ea = sh2->r[4];
	WB( sh2->ea, sh2->r[8] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2490:
{
	sh2->ea = sh2->r[4];
	WB( sh2->ea, sh2->r[9] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op24A0:
{
	sh2->ea = sh2->r[4];
	WB( sh2->ea, sh2->r[10] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op24B0:
{
	sh2->ea = sh2->r[4];
	WB( sh2->ea, sh2->r[11] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op24C0:
{
	sh2->ea = sh2->r[4];
	WB( sh2->ea, sh2->r[12] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op24D0:
{
	sh2->ea = sh2->r[4];
	WB( sh2->ea, sh2->r[13] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op24E0:
{
	sh2->ea = sh2->r[4];
	WB( sh2->ea, sh2->r[14] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op24F0:
{
	sh2->ea = sh2->r[4];
	WB( sh2->ea, sh2->r[15] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2500:
{
	sh2->ea = sh2->r[5];
	WB( sh2->ea, sh2->r[0] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2510:
{
	sh2->ea = sh2->r[5];
	WB( sh2->ea, sh2->r[1] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2520:
{
	sh2->ea = sh2->r[5];
	WB( sh2->ea, sh2->r[2] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2530:
{
	sh2->ea = sh2->r[5];
	WB( sh2->ea, sh2->r[3] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2540:
{
	sh2->ea = sh2->r[5];
	WB( sh2->ea, sh2->r[4] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2550:
{
	sh2->ea = sh2->r[5];
	WB( sh2->ea, sh2->r[5] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2560:
{
	sh2->ea = sh2->r[5];
	WB( sh2->ea, sh2->r[6] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2570:
{
	sh2->ea = sh2->r[5];
	WB( sh2->ea, sh2->r[7] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2580:
{
	sh2->ea = sh2->r[5];
	WB( sh2->ea, sh2->r[8] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2590:
{
	sh2->ea = sh2->r[5];
	WB( sh2->ea, sh2->r[9] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op25A0:
{
	sh2->ea = sh2->r[5];
	WB( sh2->ea, sh2->r[10] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op25B0:
{
	sh2->ea = sh2->r[5];
	WB( sh2->ea, sh2->r[11] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op25C0:
{
	sh2->ea = sh2->r[5];
	WB( sh2->ea, sh2->r[12] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op25D0:
{
	sh2->ea = sh2->r[5];
	WB( sh2->ea, sh2->r[13] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op25E0:
{
	sh2->ea = sh2->r[5];
	WB( sh2->ea, sh2->r[14] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op25F0:
{
	sh2->ea = sh2->r[5];
	WB( sh2->ea, sh2->r[15] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2600:
{
	sh2->ea = sh2->r[6];
	WB( sh2->ea, sh2->r[0] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2610:
{
	sh2->ea = sh2->r[6];
	WB( sh2->ea, sh2->r[1] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2620:
{
	sh2->ea = sh2->r[6];
	WB( sh2->ea, sh2->r[2] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2630:
{
	sh2->ea = sh2->r[6];
	WB( sh2->ea, sh2->r[3] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2640:
{
	sh2->ea = sh2->r[6];
	WB( sh2->ea, sh2->r[4] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2650:
{
	sh2->ea = sh2->r[6];
	WB( sh2->ea, sh2->r[5] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2660:
{
	sh2->ea = sh2->r[6];
	WB( sh2->ea, sh2->r[6] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2670:
{
	sh2->ea = sh2->r[6];
	WB( sh2->ea, sh2->r[7] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2680:
{
	sh2->ea = sh2->r[6];
	WB( sh2->ea, sh2->r[8] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2690:
{
	sh2->ea = sh2->r[6];
	WB( sh2->ea, sh2->r[9] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op26A0:
{
	sh2->ea = sh2->r[6];
	WB( sh2->ea, sh2->r[10] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op26B0:
{
	sh2->ea = sh2->r[6];
	WB( sh2->ea, sh2->r[11] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op26C0:
{
	sh2->ea = sh2->r[6];
	WB( sh2->ea, sh2->r[12] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op26D0:
{
	sh2->ea = sh2->r[6];
	WB( sh2->ea, sh2->r[13] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op26E0:
{
	sh2->ea = sh2->r[6];
	WB( sh2->ea, sh2->r[14] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op26F0:
{
	sh2->ea = sh2->r[6];
	WB( sh2->ea, sh2->r[15] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2700:
{
	sh2->ea = sh2->r[7];
	WB( sh2->ea, sh2->r[0] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2710:
{
	sh2->ea = sh2->r[7];
	WB( sh2->ea, sh2->r[1] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2720:
{
	sh2->ea = sh2->r[7];
	WB( sh2->ea, sh2->r[2] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2730:
{
	sh2->ea = sh2->r[7];
	WB( sh2->ea, sh2->r[3] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2740:
{
	sh2->ea = sh2->r[7];
	WB( sh2->ea, sh2->r[4] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2750:
{
	sh2->ea = sh2->r[7];
	WB( sh2->ea, sh2->r[5] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2760:
{
	sh2->ea = sh2->r[7];
	WB( sh2->ea, sh2->r[6] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2770:
{
	sh2->ea = sh2->r[7];
	WB( sh2->ea, sh2->r[7] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2780:
{
	sh2->ea = sh2->r[7];
	WB( sh2->ea, sh2->r[8] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2790:
{
	sh2->ea = sh2->r[7];
	WB( sh2->ea, sh2->r[9] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op27A0:
{
	sh2->ea = sh2->r[7];
	WB( sh2->ea, sh2->r[10] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op27B0:
{
	sh2->ea = sh2->r[7];
	WB( sh2->ea, sh2->r[11] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op27C0:
{
	sh2->ea = sh2->r[7];
	WB( sh2->ea, sh2->r[12] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op27D0:
{
	sh2->ea = sh2->r[7];
	WB( sh2->ea, sh2->r[13] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op27E0:
{
	sh2->ea = sh2->r[7];
	WB( sh2->ea, sh2->r[14] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op27F0:
{
	sh2->ea = sh2->r[7];
	WB( sh2->ea, sh2->r[15] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2800:
{
	sh2->ea = sh2->r[8];
	WB( sh2->ea, sh2->r[0] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2810:
{
	sh2->ea = sh2->r[8];
	WB( sh2->ea, sh2->r[1] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2820:
{
	sh2->ea = sh2->r[8];
	WB( sh2->ea, sh2->r[2] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2830:
{
	sh2->ea = sh2->r[8];
	WB( sh2->ea, sh2->r[3] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2840:
{
	sh2->ea = sh2->r[8];
	WB( sh2->ea, sh2->r[4] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2850:
{
	sh2->ea = sh2->r[8];
	WB( sh2->ea, sh2->r[5] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2860:
{
	sh2->ea = sh2->r[8];
	WB( sh2->ea, sh2->r[6] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2870:
{
	sh2->ea = sh2->r[8];
	WB( sh2->ea, sh2->r[7] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2880:
{
	sh2->ea = sh2->r[8];
	WB( sh2->ea, sh2->r[8] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2890:
{
	sh2->ea = sh2->r[8];
	WB( sh2->ea, sh2->r[9] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op28A0:
{
	sh2->ea = sh2->r[8];
	WB( sh2->ea, sh2->r[10] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op28B0:
{
	sh2->ea = sh2->r[8];
	WB( sh2->ea, sh2->r[11] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op28C0:
{
	sh2->ea = sh2->r[8];
	WB( sh2->ea, sh2->r[12] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op28D0:
{
	sh2->ea = sh2->r[8];
	WB( sh2->ea, sh2->r[13] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op28E0:
{
	sh2->ea = sh2->r[8];
	WB( sh2->ea, sh2->r[14] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op28F0:
{
	sh2->ea = sh2->r[8];
	WB( sh2->ea, sh2->r[15] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2900:
{
	sh2->ea = sh2->r[9];
	WB( sh2->ea, sh2->r[0] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2910:
{
	sh2->ea = sh2->r[9];
	WB( sh2->ea, sh2->r[1] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2920:
{
	sh2->ea = sh2->r[9];
	WB( sh2->ea, sh2->r[2] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2930:
{
	sh2->ea = sh2->r[9];
	WB( sh2->ea, sh2->r[3] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2940:
{
	sh2->ea = sh2->r[9];
	WB( sh2->ea, sh2->r[4] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2950:
{
	sh2->ea = sh2->r[9];
	WB( sh2->ea, sh2->r[5] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2960:
{
	sh2->ea = sh2->r[9];
	WB( sh2->ea, sh2->r[6] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2970:
{
	sh2->ea = sh2->r[9];
	WB( sh2->ea, sh2->r[7] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2980:
{
	sh2->ea = sh2->r[9];
	WB( sh2->ea, sh2->r[8] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2990:
{
	sh2->ea = sh2->r[9];
	WB( sh2->ea, sh2->r[9] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op29A0:
{
	sh2->ea = sh2->r[9];
	WB( sh2->ea, sh2->r[10] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op29B0:
{
	sh2->ea = sh2->r[9];
	WB( sh2->ea, sh2->r[11] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op29C0:
{
	sh2->ea = sh2->r[9];
	WB( sh2->ea, sh2->r[12] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op29D0:
{
	sh2->ea = sh2->r[9];
	WB( sh2->ea, sh2->r[13] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op29E0:
{
	sh2->ea = sh2->r[9];
	WB( sh2->ea, sh2->r[14] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op29F0:
{
	sh2->ea = sh2->r[9];
	WB( sh2->ea, sh2->r[15] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2A00:
{
	sh2->ea = sh2->r[10];
	WB( sh2->ea, sh2->r[0] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2A10:
{
	sh2->ea = sh2->r[10];
	WB( sh2->ea, sh2->r[1] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2A20:
{
	sh2->ea = sh2->r[10];
	WB( sh2->ea, sh2->r[2] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2A30:
{
	sh2->ea = sh2->r[10];
	WB( sh2->ea, sh2->r[3] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2A40:
{
	sh2->ea = sh2->r[10];
	WB( sh2->ea, sh2->r[4] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2A50:
{
	sh2->ea = sh2->r[10];
	WB( sh2->ea, sh2->r[5] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2A60:
{
	sh2->ea = sh2->r[10];
	WB( sh2->ea, sh2->r[6] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2A70:
{
	sh2->ea = sh2->r[10];
	WB( sh2->ea, sh2->r[7] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2A80:
{
	sh2->ea = sh2->r[10];
	WB( sh2->ea, sh2->r[8] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2A90:
{
	sh2->ea = sh2->r[10];
	WB( sh2->ea, sh2->r[9] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2AA0:
{
	sh2->ea = sh2->r[10];
	WB( sh2->ea, sh2->r[10] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2AB0:
{
	sh2->ea = sh2->r[10];
	WB( sh2->ea, sh2->r[11] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2AC0:
{
	sh2->ea = sh2->r[10];
	WB( sh2->ea, sh2->r[12] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2AD0:
{
	sh2->ea = sh2->r[10];
	WB( sh2->ea, sh2->r[13] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2AE0:
{
	sh2->ea = sh2->r[10];
	WB( sh2->ea, sh2->r[14] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2AF0:
{
	sh2->ea = sh2->r[10];
	WB( sh2->ea, sh2->r[15] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2B00:
{
	sh2->ea = sh2->r[11];
	WB( sh2->ea, sh2->r[0] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2B10:
{
	sh2->ea = sh2->r[11];
	WB( sh2->ea, sh2->r[1] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2B20:
{
	sh2->ea = sh2->r[11];
	WB( sh2->ea, sh2->r[2] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2B30:
{
	sh2->ea = sh2->r[11];
	WB( sh2->ea, sh2->r[3] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2B40:
{
	sh2->ea = sh2->r[11];
	WB( sh2->ea, sh2->r[4] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2B50:
{
	sh2->ea = sh2->r[11];
	WB( sh2->ea, sh2->r[5] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2B60:
{
	sh2->ea = sh2->r[11];
	WB( sh2->ea, sh2->r[6] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2B70:
{
	sh2->ea = sh2->r[11];
	WB( sh2->ea, sh2->r[7] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2B80:
{
	sh2->ea = sh2->r[11];
	WB( sh2->ea, sh2->r[8] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2B90:
{
	sh2->ea = sh2->r[11];
	WB( sh2->ea, sh2->r[9] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2BA0:
{
	sh2->ea = sh2->r[11];
	WB( sh2->ea, sh2->r[10] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2BB0:
{
	sh2->ea = sh2->r[11];
	WB( sh2->ea, sh2->r[11] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2BC0:
{
	sh2->ea = sh2->r[11];
	WB( sh2->ea, sh2->r[12] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2BD0:
{
	sh2->ea = sh2->r[11];
	WB( sh2->ea, sh2->r[13] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2BE0:
{
	sh2->ea = sh2->r[11];
	WB( sh2->ea, sh2->r[14] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2BF0:
{
	sh2->ea = sh2->r[11];
	WB( sh2->ea, sh2->r[15] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2C00:
{
	sh2->ea = sh2->r[12];
	WB( sh2->ea, sh2->r[0] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2C10:
{
	sh2->ea = sh2->r[12];
	WB( sh2->ea, sh2->r[1] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2C20:
{
	sh2->ea = sh2->r[12];
	WB( sh2->ea, sh2->r[2] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2C30:
{
	sh2->ea = sh2->r[12];
	WB( sh2->ea, sh2->r[3] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2C40:
{
	sh2->ea = sh2->r[12];
	WB( sh2->ea, sh2->r[4] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2C50:
{
	sh2->ea = sh2->r[12];
	WB( sh2->ea, sh2->r[5] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2C60:
{
	sh2->ea = sh2->r[12];
	WB( sh2->ea, sh2->r[6] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2C70:
{
	sh2->ea = sh2->r[12];
	WB( sh2->ea, sh2->r[7] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2C80:
{
	sh2->ea = sh2->r[12];
	WB( sh2->ea, sh2->r[8] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2C90:
{
	sh2->ea = sh2->r[12];
	WB( sh2->ea, sh2->r[9] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2CA0:
{
	sh2->ea = sh2->r[12];
	WB( sh2->ea, sh2->r[10] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2CB0:
{
	sh2->ea = sh2->r[12];
	WB( sh2->ea, sh2->r[11] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2CC0:
{
	sh2->ea = sh2->r[12];
	WB( sh2->ea, sh2->r[12] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2CD0:
{
	sh2->ea = sh2->r[12];
	WB( sh2->ea, sh2->r[13] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2CE0:
{
	sh2->ea = sh2->r[12];
	WB( sh2->ea, sh2->r[14] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2CF0:
{
	sh2->ea = sh2->r[12];
	WB( sh2->ea, sh2->r[15] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2D00:
{
	sh2->ea = sh2->r[13];
	WB( sh2->ea, sh2->r[0] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2D10:
{
	sh2->ea = sh2->r[13];
	WB( sh2->ea, sh2->r[1] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2D20:
{
	sh2->ea = sh2->r[13];
	WB( sh2->ea, sh2->r[2] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2D30:
{
	sh2->ea = sh2->r[13];
	WB( sh2->ea, sh2->r[3] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2D40:
{
	sh2->ea = sh2->r[13];
	WB( sh2->ea, sh2->r[4] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2D50:
{
	sh2->ea = sh2->r[13];
	WB( sh2->ea, sh2->r[5] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2D60:
{
	sh2->ea = sh2->r[13];
	WB( sh2->ea, sh2->r[6] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2D70:
{
	sh2->ea = sh2->r[13];
	WB( sh2->ea, sh2->r[7] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2D80:
{
	sh2->ea = sh2->r[13];
	WB( sh2->ea, sh2->r[8] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2D90:
{
	sh2->ea = sh2->r[13];
	WB( sh2->ea, sh2->r[9] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2DA0:
{
	sh2->ea = sh2->r[13];
	WB( sh2->ea, sh2->r[10] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2DB0:
{
	sh2->ea = sh2->r[13];
	WB( sh2->ea, sh2->r[11] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2DC0:
{
	sh2->ea = sh2->r[13];
	WB( sh2->ea, sh2->r[12] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2DD0:
{
	sh2->ea = sh2->r[13];
	WB( sh2->ea, sh2->r[13] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2DE0:
{
	sh2->ea = sh2->r[13];
	WB( sh2->ea, sh2->r[14] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2DF0:
{
	sh2->ea = sh2->r[13];
	WB( sh2->ea, sh2->r[15] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2E00:
{
	sh2->ea = sh2->r[14];
	WB( sh2->ea, sh2->r[0] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2E10:
{
	sh2->ea = sh2->r[14];
	WB( sh2->ea, sh2->r[1] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2E20:
{
	sh2->ea = sh2->r[14];
	WB( sh2->ea, sh2->r[2] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2E30:
{
	sh2->ea = sh2->r[14];
	WB( sh2->ea, sh2->r[3] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2E40:
{
	sh2->ea = sh2->r[14];
	WB( sh2->ea, sh2->r[4] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2E50:
{
	sh2->ea = sh2->r[14];
	WB( sh2->ea, sh2->r[5] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2E60:
{
	sh2->ea = sh2->r[14];
	WB( sh2->ea, sh2->r[6] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2E70:
{
	sh2->ea = sh2->r[14];
	WB( sh2->ea, sh2->r[7] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2E80:
{
	sh2->ea = sh2->r[14];
	WB( sh2->ea, sh2->r[8] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2E90:
{
	sh2->ea = sh2->r[14];
	WB( sh2->ea, sh2->r[9] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2EA0:
{
	sh2->ea = sh2->r[14];
	WB( sh2->ea, sh2->r[10] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2EB0:
{
	sh2->ea = sh2->r[14];
	WB( sh2->ea, sh2->r[11] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2EC0:
{
	sh2->ea = sh2->r[14];
	WB( sh2->ea, sh2->r[12] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2ED0:
{
	sh2->ea = sh2->r[14];
	WB( sh2->ea, sh2->r[13] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2EE0:
{
	sh2->ea = sh2->r[14];
	WB( sh2->ea, sh2->r[14] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2EF0:
{
	sh2->ea = sh2->r[14];
	WB( sh2->ea, sh2->r[15] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2F00:
{
	sh2->ea = sh2->r[15];
	WB( sh2->ea, sh2->r[0] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2F10:
{
	sh2->ea = sh2->r[15];
	WB( sh2->ea, sh2->r[1] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2F20:
{
	sh2->ea = sh2->r[15];
	WB( sh2->ea, sh2->r[2] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2F30:
{
	sh2->ea = sh2->r[15];
	WB( sh2->ea, sh2->r[3] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2F40:
{
	sh2->ea = sh2->r[15];
	WB( sh2->ea, sh2->r[4] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2F50:
{
	sh2->ea = sh2->r[15];
	WB( sh2->ea, sh2->r[5] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2F60:
{
	sh2->ea = sh2->r[15];
	WB( sh2->ea, sh2->r[6] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2F70:
{
	sh2->ea = sh2->r[15];
	WB( sh2->ea, sh2->r[7] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2F80:
{
	sh2->ea = sh2->r[15];
	WB( sh2->ea, sh2->r[8] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2F90:
{
	sh2->ea = sh2->r[15];
	WB( sh2->ea, sh2->r[9] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2FA0:
{
	sh2->ea = sh2->r[15];
	WB( sh2->ea, sh2->r[10] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2FB0:
{
	sh2->ea = sh2->r[15];
	WB( sh2->ea, sh2->r[11] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2FC0:
{
	sh2->ea = sh2->r[15];
	WB( sh2->ea, sh2->r[12] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2FD0:
{
	sh2->ea = sh2->r[15];
	WB( sh2->ea, sh2->r[13] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2FE0:
{
	sh2->ea = sh2->r[15];
	WB( sh2->ea, sh2->r[14] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

Op2FF0:
{
	sh2->ea = sh2->r[15];
	WB( sh2->ea, sh2->r[15] & 0x000000ff);
	goto SH2_RUN_CONTINUE;
}

// MOV.W Rm,@Rn
Op2001:
{
	sh2->ea = sh2->r[0];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2011:
{
	sh2->ea = sh2->r[0];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2021:
{
	sh2->ea = sh2->r[0];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2031:
{
	sh2->ea = sh2->r[0];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2041:
{
	sh2->ea = sh2->r[0];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2051:
{
	sh2->ea = sh2->r[0];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2061:
{
	sh2->ea = sh2->r[0];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2071:
{
	sh2->ea = sh2->r[0];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2081:
{
	sh2->ea = sh2->r[0];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2091:
{
	sh2->ea = sh2->r[0];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op20A1:
{
	sh2->ea = sh2->r[0];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op20B1:
{
	sh2->ea = sh2->r[0];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op20C1:
{
	sh2->ea = sh2->r[0];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op20D1:
{
	sh2->ea = sh2->r[0];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op20E1:
{
	sh2->ea = sh2->r[0];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op20F1:
{
	sh2->ea = sh2->r[0];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2101:
{
	sh2->ea = sh2->r[1];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2111:
{
	sh2->ea = sh2->r[1];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2121:
{
	sh2->ea = sh2->r[1];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2131:
{
	sh2->ea = sh2->r[1];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2141:
{
	sh2->ea = sh2->r[1];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2151:
{
	sh2->ea = sh2->r[1];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2161:
{
	sh2->ea = sh2->r[1];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2171:
{
	sh2->ea = sh2->r[1];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2181:
{
	sh2->ea = sh2->r[1];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2191:
{
	sh2->ea = sh2->r[1];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op21A1:
{
	sh2->ea = sh2->r[1];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op21B1:
{
	sh2->ea = sh2->r[1];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op21C1:
{
	sh2->ea = sh2->r[1];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op21D1:
{
	sh2->ea = sh2->r[1];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op21E1:
{
	sh2->ea = sh2->r[1];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op21F1:
{
	sh2->ea = sh2->r[1];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2201:
{
	sh2->ea = sh2->r[2];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2211:
{
	sh2->ea = sh2->r[2];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2221:
{
	sh2->ea = sh2->r[2];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2231:
{
	sh2->ea = sh2->r[2];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2241:
{
	sh2->ea = sh2->r[2];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2251:
{
	sh2->ea = sh2->r[2];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2261:
{
	sh2->ea = sh2->r[2];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2271:
{
	sh2->ea = sh2->r[2];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2281:
{
	sh2->ea = sh2->r[2];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2291:
{
	sh2->ea = sh2->r[2];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op22A1:
{
	sh2->ea = sh2->r[2];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op22B1:
{
	sh2->ea = sh2->r[2];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op22C1:
{
	sh2->ea = sh2->r[2];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op22D1:
{
	sh2->ea = sh2->r[2];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op22E1:
{
	sh2->ea = sh2->r[2];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op22F1:
{
	sh2->ea = sh2->r[2];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2301:
{
	sh2->ea = sh2->r[3];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2311:
{
	sh2->ea = sh2->r[3];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2321:
{
	sh2->ea = sh2->r[3];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2331:
{
	sh2->ea = sh2->r[3];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2341:
{
	sh2->ea = sh2->r[3];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2351:
{
	sh2->ea = sh2->r[3];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2361:
{
	sh2->ea = sh2->r[3];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2371:
{
	sh2->ea = sh2->r[3];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2381:
{
	sh2->ea = sh2->r[3];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2391:
{
	sh2->ea = sh2->r[3];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op23A1:
{
	sh2->ea = sh2->r[3];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op23B1:
{
	sh2->ea = sh2->r[3];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op23C1:
{
	sh2->ea = sh2->r[3];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op23D1:
{
	sh2->ea = sh2->r[3];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op23E1:
{
	sh2->ea = sh2->r[3];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op23F1:
{
	sh2->ea = sh2->r[3];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2401:
{
	sh2->ea = sh2->r[4];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2411:
{
	sh2->ea = sh2->r[4];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2421:
{
	sh2->ea = sh2->r[4];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2431:
{
	sh2->ea = sh2->r[4];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2441:
{
	sh2->ea = sh2->r[4];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2451:
{
	sh2->ea = sh2->r[4];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2461:
{
	sh2->ea = sh2->r[4];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2471:
{
	sh2->ea = sh2->r[4];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2481:
{
	sh2->ea = sh2->r[4];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2491:
{
	sh2->ea = sh2->r[4];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op24A1:
{
	sh2->ea = sh2->r[4];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op24B1:
{
	sh2->ea = sh2->r[4];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op24C1:
{
	sh2->ea = sh2->r[4];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op24D1:
{
	sh2->ea = sh2->r[4];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op24E1:
{
	sh2->ea = sh2->r[4];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op24F1:
{
	sh2->ea = sh2->r[4];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2501:
{
	sh2->ea = sh2->r[5];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2511:
{
	sh2->ea = sh2->r[5];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2521:
{
	sh2->ea = sh2->r[5];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2531:
{
	sh2->ea = sh2->r[5];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2541:
{
	sh2->ea = sh2->r[5];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2551:
{
	sh2->ea = sh2->r[5];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2561:
{
	sh2->ea = sh2->r[5];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2571:
{
	sh2->ea = sh2->r[5];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2581:
{
	sh2->ea = sh2->r[5];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2591:
{
	sh2->ea = sh2->r[5];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op25A1:
{
	sh2->ea = sh2->r[5];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op25B1:
{
	sh2->ea = sh2->r[5];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op25C1:
{
	sh2->ea = sh2->r[5];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op25D1:
{
	sh2->ea = sh2->r[5];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op25E1:
{
	sh2->ea = sh2->r[5];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op25F1:
{
	sh2->ea = sh2->r[5];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2601:
{
	sh2->ea = sh2->r[6];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2611:
{
	sh2->ea = sh2->r[6];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2621:
{
	sh2->ea = sh2->r[6];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2631:
{
	sh2->ea = sh2->r[6];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2641:
{
	sh2->ea = sh2->r[6];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2651:
{
	sh2->ea = sh2->r[6];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2661:
{
	sh2->ea = sh2->r[6];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2671:
{
	sh2->ea = sh2->r[6];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2681:
{
	sh2->ea = sh2->r[6];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2691:
{
	sh2->ea = sh2->r[6];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op26A1:
{
	sh2->ea = sh2->r[6];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op26B1:
{
	sh2->ea = sh2->r[6];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op26C1:
{
	sh2->ea = sh2->r[6];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op26D1:
{
	sh2->ea = sh2->r[6];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op26E1:
{
	sh2->ea = sh2->r[6];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op26F1:
{
	sh2->ea = sh2->r[6];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2701:
{
	sh2->ea = sh2->r[7];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2711:
{
	sh2->ea = sh2->r[7];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2721:
{
	sh2->ea = sh2->r[7];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2731:
{
	sh2->ea = sh2->r[7];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2741:
{
	sh2->ea = sh2->r[7];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2751:
{
	sh2->ea = sh2->r[7];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2761:
{
	sh2->ea = sh2->r[7];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2771:
{
	sh2->ea = sh2->r[7];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2781:
{
	sh2->ea = sh2->r[7];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2791:
{
	sh2->ea = sh2->r[7];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op27A1:
{
	sh2->ea = sh2->r[7];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op27B1:
{
	sh2->ea = sh2->r[7];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op27C1:
{
	sh2->ea = sh2->r[7];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op27D1:
{
	sh2->ea = sh2->r[7];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op27E1:
{
	sh2->ea = sh2->r[7];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op27F1:
{
	sh2->ea = sh2->r[7];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2801:
{
	sh2->ea = sh2->r[8];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2811:
{
	sh2->ea = sh2->r[8];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2821:
{
	sh2->ea = sh2->r[8];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2831:
{
	sh2->ea = sh2->r[8];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2841:
{
	sh2->ea = sh2->r[8];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2851:
{
	sh2->ea = sh2->r[8];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2861:
{
	sh2->ea = sh2->r[8];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2871:
{
	sh2->ea = sh2->r[8];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2881:
{
	sh2->ea = sh2->r[8];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2891:
{
	sh2->ea = sh2->r[8];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op28A1:
{
	sh2->ea = sh2->r[8];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op28B1:
{
	sh2->ea = sh2->r[8];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op28C1:
{
	sh2->ea = sh2->r[8];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op28D1:
{
	sh2->ea = sh2->r[8];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op28E1:
{
	sh2->ea = sh2->r[8];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op28F1:
{
	sh2->ea = sh2->r[8];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2901:
{
	sh2->ea = sh2->r[9];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2911:
{
	sh2->ea = sh2->r[9];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2921:
{
	sh2->ea = sh2->r[9];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2931:
{
	sh2->ea = sh2->r[9];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2941:
{
	sh2->ea = sh2->r[9];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2951:
{
	sh2->ea = sh2->r[9];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2961:
{
	sh2->ea = sh2->r[9];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2971:
{
	sh2->ea = sh2->r[9];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2981:
{
	sh2->ea = sh2->r[9];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2991:
{
	sh2->ea = sh2->r[9];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op29A1:
{
	sh2->ea = sh2->r[9];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op29B1:
{
	sh2->ea = sh2->r[9];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op29C1:
{
	sh2->ea = sh2->r[9];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op29D1:
{
	sh2->ea = sh2->r[9];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op29E1:
{
	sh2->ea = sh2->r[9];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op29F1:
{
	sh2->ea = sh2->r[9];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2A01:
{
	sh2->ea = sh2->r[10];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2A11:
{
	sh2->ea = sh2->r[10];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2A21:
{
	sh2->ea = sh2->r[10];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2A31:
{
	sh2->ea = sh2->r[10];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2A41:
{
	sh2->ea = sh2->r[10];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2A51:
{
	sh2->ea = sh2->r[10];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2A61:
{
	sh2->ea = sh2->r[10];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2A71:
{
	sh2->ea = sh2->r[10];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2A81:
{
	sh2->ea = sh2->r[10];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2A91:
{
	sh2->ea = sh2->r[10];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2AA1:
{
	sh2->ea = sh2->r[10];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2AB1:
{
	sh2->ea = sh2->r[10];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2AC1:
{
	sh2->ea = sh2->r[10];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2AD1:
{
	sh2->ea = sh2->r[10];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2AE1:
{
	sh2->ea = sh2->r[10];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2AF1:
{
	sh2->ea = sh2->r[10];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2B01:
{
	sh2->ea = sh2->r[11];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2B11:
{
	sh2->ea = sh2->r[11];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2B21:
{
	sh2->ea = sh2->r[11];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2B31:
{
	sh2->ea = sh2->r[11];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2B41:
{
	sh2->ea = sh2->r[11];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2B51:
{
	sh2->ea = sh2->r[11];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2B61:
{
	sh2->ea = sh2->r[11];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2B71:
{
	sh2->ea = sh2->r[11];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2B81:
{
	sh2->ea = sh2->r[11];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2B91:
{
	sh2->ea = sh2->r[11];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2BA1:
{
	sh2->ea = sh2->r[11];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2BB1:
{
	sh2->ea = sh2->r[11];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2BC1:
{
	sh2->ea = sh2->r[11];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2BD1:
{
	sh2->ea = sh2->r[11];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2BE1:
{
	sh2->ea = sh2->r[11];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2BF1:
{
	sh2->ea = sh2->r[11];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2C01:
{
	sh2->ea = sh2->r[12];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2C11:
{
	sh2->ea = sh2->r[12];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2C21:
{
	sh2->ea = sh2->r[12];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2C31:
{
	sh2->ea = sh2->r[12];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2C41:
{
	sh2->ea = sh2->r[12];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2C51:
{
	sh2->ea = sh2->r[12];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2C61:
{
	sh2->ea = sh2->r[12];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2C71:
{
	sh2->ea = sh2->r[12];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2C81:
{
	sh2->ea = sh2->r[12];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2C91:
{
	sh2->ea = sh2->r[12];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2CA1:
{
	sh2->ea = sh2->r[12];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2CB1:
{
	sh2->ea = sh2->r[12];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2CC1:
{
	sh2->ea = sh2->r[12];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2CD1:
{
	sh2->ea = sh2->r[12];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2CE1:
{
	sh2->ea = sh2->r[12];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2CF1:
{
	sh2->ea = sh2->r[12];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2D01:
{
	sh2->ea = sh2->r[13];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2D11:
{
	sh2->ea = sh2->r[13];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2D21:
{
	sh2->ea = sh2->r[13];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2D31:
{
	sh2->ea = sh2->r[13];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2D41:
{
	sh2->ea = sh2->r[13];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2D51:
{
	sh2->ea = sh2->r[13];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2D61:
{
	sh2->ea = sh2->r[13];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2D71:
{
	sh2->ea = sh2->r[13];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2D81:
{
	sh2->ea = sh2->r[13];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2D91:
{
	sh2->ea = sh2->r[13];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2DA1:
{
	sh2->ea = sh2->r[13];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2DB1:
{
	sh2->ea = sh2->r[13];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2DC1:
{
	sh2->ea = sh2->r[13];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2DD1:
{
	sh2->ea = sh2->r[13];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2DE1:
{
	sh2->ea = sh2->r[13];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2DF1:
{
	sh2->ea = sh2->r[13];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2E01:
{
	sh2->ea = sh2->r[14];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2E11:
{
	sh2->ea = sh2->r[14];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2E21:
{
	sh2->ea = sh2->r[14];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2E31:
{
	sh2->ea = sh2->r[14];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2E41:
{
	sh2->ea = sh2->r[14];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2E51:
{
	sh2->ea = sh2->r[14];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2E61:
{
	sh2->ea = sh2->r[14];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2E71:
{
	sh2->ea = sh2->r[14];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2E81:
{
	sh2->ea = sh2->r[14];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2E91:
{
	sh2->ea = sh2->r[14];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2EA1:
{
	sh2->ea = sh2->r[14];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2EB1:
{
	sh2->ea = sh2->r[14];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2EC1:
{
	sh2->ea = sh2->r[14];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2ED1:
{
	sh2->ea = sh2->r[14];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2EE1:
{
	sh2->ea = sh2->r[14];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2EF1:
{
	sh2->ea = sh2->r[14];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2F01:
{
	sh2->ea = sh2->r[15];
	WW( sh2->ea, sh2->r[0] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2F11:
{
	sh2->ea = sh2->r[15];
	WW( sh2->ea, sh2->r[1] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2F21:
{
	sh2->ea = sh2->r[15];
	WW( sh2->ea, sh2->r[2] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2F31:
{
	sh2->ea = sh2->r[15];
	WW( sh2->ea, sh2->r[3] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2F41:
{
	sh2->ea = sh2->r[15];
	WW( sh2->ea, sh2->r[4] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2F51:
{
	sh2->ea = sh2->r[15];
	WW( sh2->ea, sh2->r[5] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2F61:
{
	sh2->ea = sh2->r[15];
	WW( sh2->ea, sh2->r[6] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2F71:
{
	sh2->ea = sh2->r[15];
	WW( sh2->ea, sh2->r[7] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2F81:
{
	sh2->ea = sh2->r[15];
	WW( sh2->ea, sh2->r[8] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2F91:
{
	sh2->ea = sh2->r[15];
	WW( sh2->ea, sh2->r[9] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2FA1:
{
	sh2->ea = sh2->r[15];
	WW( sh2->ea, sh2->r[10] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2FB1:
{
	sh2->ea = sh2->r[15];
	WW( sh2->ea, sh2->r[11] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2FC1:
{
	sh2->ea = sh2->r[15];
	WW( sh2->ea, sh2->r[12] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2FD1:
{
	sh2->ea = sh2->r[15];
	WW( sh2->ea, sh2->r[13] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2FE1:
{
	sh2->ea = sh2->r[15];
	WW( sh2->ea, sh2->r[14] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

Op2FF1:
{
	sh2->ea = sh2->r[15];
	WW( sh2->ea, sh2->r[15] & 0x0000ffff);
	goto SH2_RUN_CONTINUE;
}

// MOV.L Rm,@Rn
Op2002:
{
	sh2->ea = sh2->r[0];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op2012:
{
	sh2->ea = sh2->r[0];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op2022:
{
	sh2->ea = sh2->r[0];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op2032:
{
	sh2->ea = sh2->r[0];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op2042:
{
	sh2->ea = sh2->r[0];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op2052:
{
	sh2->ea = sh2->r[0];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op2062:
{
	sh2->ea = sh2->r[0];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op2072:
{
	sh2->ea = sh2->r[0];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op2082:
{
	sh2->ea = sh2->r[0];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op2092:
{
	sh2->ea = sh2->r[0];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op20A2:
{
	sh2->ea = sh2->r[0];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op20B2:
{
	sh2->ea = sh2->r[0];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op20C2:
{
	sh2->ea = sh2->r[0];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op20D2:
{
	sh2->ea = sh2->r[0];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op20E2:
{
	sh2->ea = sh2->r[0];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op20F2:
{
	sh2->ea = sh2->r[0];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op2102:
{
	sh2->ea = sh2->r[1];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op2112:
{
	sh2->ea = sh2->r[1];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op2122:
{
	sh2->ea = sh2->r[1];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op2132:
{
	sh2->ea = sh2->r[1];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op2142:
{
	sh2->ea = sh2->r[1];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op2152:
{
	sh2->ea = sh2->r[1];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op2162:
{
	sh2->ea = sh2->r[1];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op2172:
{
	sh2->ea = sh2->r[1];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op2182:
{
	sh2->ea = sh2->r[1];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op2192:
{
	sh2->ea = sh2->r[1];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op21A2:
{
	sh2->ea = sh2->r[1];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op21B2:
{
	sh2->ea = sh2->r[1];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op21C2:
{
	sh2->ea = sh2->r[1];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op21D2:
{
	sh2->ea = sh2->r[1];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op21E2:
{
	sh2->ea = sh2->r[1];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op21F2:
{
	sh2->ea = sh2->r[1];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op2202:
{
	sh2->ea = sh2->r[2];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op2212:
{
	sh2->ea = sh2->r[2];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op2222:
{
	sh2->ea = sh2->r[2];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op2232:
{
	sh2->ea = sh2->r[2];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op2242:
{
	sh2->ea = sh2->r[2];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op2252:
{
	sh2->ea = sh2->r[2];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op2262:
{
	sh2->ea = sh2->r[2];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op2272:
{
	sh2->ea = sh2->r[2];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op2282:
{
	sh2->ea = sh2->r[2];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op2292:
{
	sh2->ea = sh2->r[2];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op22A2:
{
	sh2->ea = sh2->r[2];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op22B2:
{
	sh2->ea = sh2->r[2];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op22C2:
{
	sh2->ea = sh2->r[2];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op22D2:
{
	sh2->ea = sh2->r[2];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op22E2:
{
	sh2->ea = sh2->r[2];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op22F2:
{
	sh2->ea = sh2->r[2];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op2302:
{
	sh2->ea = sh2->r[3];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op2312:
{
	sh2->ea = sh2->r[3];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op2322:
{
	sh2->ea = sh2->r[3];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op2332:
{
	sh2->ea = sh2->r[3];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op2342:
{
	sh2->ea = sh2->r[3];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op2352:
{
	sh2->ea = sh2->r[3];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op2362:
{
	sh2->ea = sh2->r[3];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op2372:
{
	sh2->ea = sh2->r[3];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op2382:
{
	sh2->ea = sh2->r[3];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op2392:
{
	sh2->ea = sh2->r[3];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op23A2:
{
	sh2->ea = sh2->r[3];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op23B2:
{
	sh2->ea = sh2->r[3];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op23C2:
{
	sh2->ea = sh2->r[3];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op23D2:
{
	sh2->ea = sh2->r[3];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op23E2:
{
	sh2->ea = sh2->r[3];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op23F2:
{
	sh2->ea = sh2->r[3];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op2402:
{
	sh2->ea = sh2->r[4];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op2412:
{
	sh2->ea = sh2->r[4];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op2422:
{
	sh2->ea = sh2->r[4];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op2432:
{
	sh2->ea = sh2->r[4];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op2442:
{
	sh2->ea = sh2->r[4];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op2452:
{
	sh2->ea = sh2->r[4];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op2462:
{
	sh2->ea = sh2->r[4];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op2472:
{
	sh2->ea = sh2->r[4];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op2482:
{
	sh2->ea = sh2->r[4];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op2492:
{
	sh2->ea = sh2->r[4];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op24A2:
{
	sh2->ea = sh2->r[4];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op24B2:
{
	sh2->ea = sh2->r[4];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op24C2:
{
	sh2->ea = sh2->r[4];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op24D2:
{
	sh2->ea = sh2->r[4];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op24E2:
{
	sh2->ea = sh2->r[4];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op24F2:
{
	sh2->ea = sh2->r[4];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op2502:
{
	sh2->ea = sh2->r[5];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op2512:
{
	sh2->ea = sh2->r[5];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op2522:
{
	sh2->ea = sh2->r[5];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op2532:
{
	sh2->ea = sh2->r[5];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op2542:
{
	sh2->ea = sh2->r[5];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op2552:
{
	sh2->ea = sh2->r[5];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op2562:
{
	sh2->ea = sh2->r[5];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op2572:
{
	sh2->ea = sh2->r[5];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op2582:
{
	sh2->ea = sh2->r[5];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op2592:
{
	sh2->ea = sh2->r[5];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op25A2:
{
	sh2->ea = sh2->r[5];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op25B2:
{
	sh2->ea = sh2->r[5];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op25C2:
{
	sh2->ea = sh2->r[5];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op25D2:
{
	sh2->ea = sh2->r[5];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op25E2:
{
	sh2->ea = sh2->r[5];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op25F2:
{
	sh2->ea = sh2->r[5];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op2602:
{
	sh2->ea = sh2->r[6];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op2612:
{
	sh2->ea = sh2->r[6];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op2622:
{
	sh2->ea = sh2->r[6];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op2632:
{
	sh2->ea = sh2->r[6];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op2642:
{
	sh2->ea = sh2->r[6];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op2652:
{
	sh2->ea = sh2->r[6];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op2662:
{
	sh2->ea = sh2->r[6];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op2672:
{
	sh2->ea = sh2->r[6];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op2682:
{
	sh2->ea = sh2->r[6];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op2692:
{
	sh2->ea = sh2->r[6];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op26A2:
{
	sh2->ea = sh2->r[6];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op26B2:
{
	sh2->ea = sh2->r[6];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op26C2:
{
	sh2->ea = sh2->r[6];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op26D2:
{
	sh2->ea = sh2->r[6];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op26E2:
{
	sh2->ea = sh2->r[6];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op26F2:
{
	sh2->ea = sh2->r[6];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op2702:
{
	sh2->ea = sh2->r[7];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op2712:
{
	sh2->ea = sh2->r[7];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op2722:
{
	sh2->ea = sh2->r[7];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op2732:
{
	sh2->ea = sh2->r[7];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op2742:
{
	sh2->ea = sh2->r[7];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op2752:
{
	sh2->ea = sh2->r[7];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op2762:
{
	sh2->ea = sh2->r[7];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op2772:
{
	sh2->ea = sh2->r[7];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op2782:
{
	sh2->ea = sh2->r[7];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op2792:
{
	sh2->ea = sh2->r[7];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op27A2:
{
	sh2->ea = sh2->r[7];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op27B2:
{
	sh2->ea = sh2->r[7];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op27C2:
{
	sh2->ea = sh2->r[7];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op27D2:
{
	sh2->ea = sh2->r[7];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op27E2:
{
	sh2->ea = sh2->r[7];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op27F2:
{
	sh2->ea = sh2->r[7];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op2802:
{
	sh2->ea = sh2->r[8];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op2812:
{
	sh2->ea = sh2->r[8];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op2822:
{
	sh2->ea = sh2->r[8];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op2832:
{
	sh2->ea = sh2->r[8];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op2842:
{
	sh2->ea = sh2->r[8];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op2852:
{
	sh2->ea = sh2->r[8];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op2862:
{
	sh2->ea = sh2->r[8];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op2872:
{
	sh2->ea = sh2->r[8];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op2882:
{
	sh2->ea = sh2->r[8];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op2892:
{
	sh2->ea = sh2->r[8];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op28A2:
{
	sh2->ea = sh2->r[8];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op28B2:
{
	sh2->ea = sh2->r[8];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op28C2:
{
	sh2->ea = sh2->r[8];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op28D2:
{
	sh2->ea = sh2->r[8];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op28E2:
{
	sh2->ea = sh2->r[8];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op28F2:
{
	sh2->ea = sh2->r[8];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op2902:
{
	sh2->ea = sh2->r[9];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op2912:
{
	sh2->ea = sh2->r[9];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op2922:
{
	sh2->ea = sh2->r[9];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op2932:
{
	sh2->ea = sh2->r[9];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op2942:
{
	sh2->ea = sh2->r[9];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op2952:
{
	sh2->ea = sh2->r[9];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op2962:
{
	sh2->ea = sh2->r[9];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op2972:
{
	sh2->ea = sh2->r[9];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op2982:
{
	sh2->ea = sh2->r[9];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op2992:
{
	sh2->ea = sh2->r[9];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op29A2:
{
	sh2->ea = sh2->r[9];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op29B2:
{
	sh2->ea = sh2->r[9];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op29C2:
{
	sh2->ea = sh2->r[9];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op29D2:
{
	sh2->ea = sh2->r[9];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op29E2:
{
	sh2->ea = sh2->r[9];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op29F2:
{
	sh2->ea = sh2->r[9];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op2A02:
{
	sh2->ea = sh2->r[10];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op2A12:
{
	sh2->ea = sh2->r[10];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op2A22:
{
	sh2->ea = sh2->r[10];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op2A32:
{
	sh2->ea = sh2->r[10];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op2A42:
{
	sh2->ea = sh2->r[10];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op2A52:
{
	sh2->ea = sh2->r[10];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op2A62:
{
	sh2->ea = sh2->r[10];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op2A72:
{
	sh2->ea = sh2->r[10];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op2A82:
{
	sh2->ea = sh2->r[10];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op2A92:
{
	sh2->ea = sh2->r[10];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op2AA2:
{
	sh2->ea = sh2->r[10];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op2AB2:
{
	sh2->ea = sh2->r[10];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op2AC2:
{
	sh2->ea = sh2->r[10];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op2AD2:
{
	sh2->ea = sh2->r[10];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op2AE2:
{
	sh2->ea = sh2->r[10];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op2AF2:
{
	sh2->ea = sh2->r[10];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op2B02:
{
	sh2->ea = sh2->r[11];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op2B12:
{
	sh2->ea = sh2->r[11];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op2B22:
{
	sh2->ea = sh2->r[11];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op2B32:
{
	sh2->ea = sh2->r[11];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op2B42:
{
	sh2->ea = sh2->r[11];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op2B52:
{
	sh2->ea = sh2->r[11];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op2B62:
{
	sh2->ea = sh2->r[11];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op2B72:
{
	sh2->ea = sh2->r[11];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op2B82:
{
	sh2->ea = sh2->r[11];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op2B92:
{
	sh2->ea = sh2->r[11];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op2BA2:
{
	sh2->ea = sh2->r[11];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op2BB2:
{
	sh2->ea = sh2->r[11];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op2BC2:
{
	sh2->ea = sh2->r[11];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op2BD2:
{
	sh2->ea = sh2->r[11];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op2BE2:
{
	sh2->ea = sh2->r[11];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op2BF2:
{
	sh2->ea = sh2->r[11];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op2C02:
{
	sh2->ea = sh2->r[12];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op2C12:
{
	sh2->ea = sh2->r[12];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op2C22:
{
	sh2->ea = sh2->r[12];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op2C32:
{
	sh2->ea = sh2->r[12];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op2C42:
{
	sh2->ea = sh2->r[12];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op2C52:
{
	sh2->ea = sh2->r[12];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op2C62:
{
	sh2->ea = sh2->r[12];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op2C72:
{
	sh2->ea = sh2->r[12];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op2C82:
{
	sh2->ea = sh2->r[12];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op2C92:
{
	sh2->ea = sh2->r[12];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op2CA2:
{
	sh2->ea = sh2->r[12];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op2CB2:
{
	sh2->ea = sh2->r[12];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op2CC2:
{
	sh2->ea = sh2->r[12];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op2CD2:
{
	sh2->ea = sh2->r[12];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op2CE2:
{
	sh2->ea = sh2->r[12];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op2CF2:
{
	sh2->ea = sh2->r[12];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op2D02:
{
	sh2->ea = sh2->r[13];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op2D12:
{
	sh2->ea = sh2->r[13];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op2D22:
{
	sh2->ea = sh2->r[13];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op2D32:
{
	sh2->ea = sh2->r[13];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op2D42:
{
	sh2->ea = sh2->r[13];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op2D52:
{
	sh2->ea = sh2->r[13];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op2D62:
{
	sh2->ea = sh2->r[13];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op2D72:
{
	sh2->ea = sh2->r[13];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op2D82:
{
	sh2->ea = sh2->r[13];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op2D92:
{
	sh2->ea = sh2->r[13];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op2DA2:
{
	sh2->ea = sh2->r[13];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op2DB2:
{
	sh2->ea = sh2->r[13];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op2DC2:
{
	sh2->ea = sh2->r[13];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op2DD2:
{
	sh2->ea = sh2->r[13];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op2DE2:
{
	sh2->ea = sh2->r[13];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op2DF2:
{
	sh2->ea = sh2->r[13];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op2E02:
{
	sh2->ea = sh2->r[14];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op2E12:
{
	sh2->ea = sh2->r[14];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op2E22:
{
	sh2->ea = sh2->r[14];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op2E32:
{
	sh2->ea = sh2->r[14];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op2E42:
{
	sh2->ea = sh2->r[14];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op2E52:
{
	sh2->ea = sh2->r[14];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op2E62:
{
	sh2->ea = sh2->r[14];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op2E72:
{
	sh2->ea = sh2->r[14];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op2E82:
{
	sh2->ea = sh2->r[14];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op2E92:
{
	sh2->ea = sh2->r[14];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op2EA2:
{
	sh2->ea = sh2->r[14];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op2EB2:
{
	sh2->ea = sh2->r[14];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op2EC2:
{
	sh2->ea = sh2->r[14];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op2ED2:
{
	sh2->ea = sh2->r[14];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op2EE2:
{
	sh2->ea = sh2->r[14];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op2EF2:
{
	sh2->ea = sh2->r[14];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

Op2F02:
{
	sh2->ea = sh2->r[15];
	WL( sh2->ea, sh2->r[0] );
	goto SH2_RUN_CONTINUE;
}

Op2F12:
{
	sh2->ea = sh2->r[15];
	WL( sh2->ea, sh2->r[1] );
	goto SH2_RUN_CONTINUE;
}

Op2F22:
{
	sh2->ea = sh2->r[15];
	WL( sh2->ea, sh2->r[2] );
	goto SH2_RUN_CONTINUE;
}

Op2F32:
{
	sh2->ea = sh2->r[15];
	WL( sh2->ea, sh2->r[3] );
	goto SH2_RUN_CONTINUE;
}

Op2F42:
{
	sh2->ea = sh2->r[15];
	WL( sh2->ea, sh2->r[4] );
	goto SH2_RUN_CONTINUE;
}

Op2F52:
{
	sh2->ea = sh2->r[15];
	WL( sh2->ea, sh2->r[5] );
	goto SH2_RUN_CONTINUE;
}

Op2F62:
{
	sh2->ea = sh2->r[15];
	WL( sh2->ea, sh2->r[6] );
	goto SH2_RUN_CONTINUE;
}

Op2F72:
{
	sh2->ea = sh2->r[15];
	WL( sh2->ea, sh2->r[7] );
	goto SH2_RUN_CONTINUE;
}

Op2F82:
{
	sh2->ea = sh2->r[15];
	WL( sh2->ea, sh2->r[8] );
	goto SH2_RUN_CONTINUE;
}

Op2F92:
{
	sh2->ea = sh2->r[15];
	WL( sh2->ea, sh2->r[9] );
	goto SH2_RUN_CONTINUE;
}

Op2FA2:
{
	sh2->ea = sh2->r[15];
	WL( sh2->ea, sh2->r[10] );
	goto SH2_RUN_CONTINUE;
}

Op2FB2:
{
	sh2->ea = sh2->r[15];
	WL( sh2->ea, sh2->r[11] );
	goto SH2_RUN_CONTINUE;
}

Op2FC2:
{
	sh2->ea = sh2->r[15];
	WL( sh2->ea, sh2->r[12] );
	goto SH2_RUN_CONTINUE;
}

Op2FD2:
{
	sh2->ea = sh2->r[15];
	WL( sh2->ea, sh2->r[13] );
	goto SH2_RUN_CONTINUE;
}

Op2FE2:
{
	sh2->ea = sh2->r[15];
	WL( sh2->ea, sh2->r[14] );
	goto SH2_RUN_CONTINUE;
}

Op2FF2:
{
	sh2->ea = sh2->r[15];
	WL( sh2->ea, sh2->r[15] );
	goto SH2_RUN_CONTINUE;
}

// MOV.B Rm,@-Rn
Op2004:
{
	UINT32 data = sh2->r[0] & 0x000000ff;
	sh2->r[0] -= 1;
	WB( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2014:
{
	UINT32 data = sh2->r[1] & 0x000000ff;
	sh2->r[0] -= 1;
	WB( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2024:
{
	UINT32 data = sh2->r[2] & 0x000000ff;
	sh2->r[0] -= 1;
	WB( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2034:
{
	UINT32 data = sh2->r[3] & 0x000000ff;
	sh2->r[0] -= 1;
	WB( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2044:
{
	UINT32 data = sh2->r[4] & 0x000000ff;
	sh2->r[0] -= 1;
	WB( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2054:
{
	UINT32 data = sh2->r[5] & 0x000000ff;
	sh2->r[0] -= 1;
	WB( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2064:
{
	UINT32 data = sh2->r[6] & 0x000000ff;
	sh2->r[0] -= 1;
	WB( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2074:
{
	UINT32 data = sh2->r[7] & 0x000000ff;
	sh2->r[0] -= 1;
	WB( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2084:
{
	UINT32 data = sh2->r[8] & 0x000000ff;
	sh2->r[0] -= 1;
	WB( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2094:
{
	UINT32 data = sh2->r[9] & 0x000000ff;
	sh2->r[0] -= 1;
	WB( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op20A4:
{
	UINT32 data = sh2->r[10] & 0x000000ff;
	sh2->r[0] -= 1;
	WB( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op20B4:
{
	UINT32 data = sh2->r[11] & 0x000000ff;
	sh2->r[0] -= 1;
	WB( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op20C4:
{
	UINT32 data = sh2->r[12] & 0x000000ff;
	sh2->r[0] -= 1;
	WB( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op20D4:
{
	UINT32 data = sh2->r[13] & 0x000000ff;
	sh2->r[0] -= 1;
	WB( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op20E4:
{
	UINT32 data = sh2->r[14] & 0x000000ff;
	sh2->r[0] -= 1;
	WB( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op20F4:
{
	UINT32 data = sh2->r[15] & 0x000000ff;
	sh2->r[0] -= 1;
	WB( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2104:
{
	UINT32 data = sh2->r[0] & 0x000000ff;
	sh2->r[1] -= 1;
	WB( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2114:
{
	UINT32 data = sh2->r[1] & 0x000000ff;
	sh2->r[1] -= 1;
	WB( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2124:
{
	UINT32 data = sh2->r[2] & 0x000000ff;
	sh2->r[1] -= 1;
	WB( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2134:
{
	UINT32 data = sh2->r[3] & 0x000000ff;
	sh2->r[1] -= 1;
	WB( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2144:
{
	UINT32 data = sh2->r[4] & 0x000000ff;
	sh2->r[1] -= 1;
	WB( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2154:
{
	UINT32 data = sh2->r[5] & 0x000000ff;
	sh2->r[1] -= 1;
	WB( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2164:
{
	UINT32 data = sh2->r[6] & 0x000000ff;
	sh2->r[1] -= 1;
	WB( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2174:
{
	UINT32 data = sh2->r[7] & 0x000000ff;
	sh2->r[1] -= 1;
	WB( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2184:
{
	UINT32 data = sh2->r[8] & 0x000000ff;
	sh2->r[1] -= 1;
	WB( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2194:
{
	UINT32 data = sh2->r[9] & 0x000000ff;
	sh2->r[1] -= 1;
	WB( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op21A4:
{
	UINT32 data = sh2->r[10] & 0x000000ff;
	sh2->r[1] -= 1;
	WB( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op21B4:
{
	UINT32 data = sh2->r[11] & 0x000000ff;
	sh2->r[1] -= 1;
	WB( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op21C4:
{
	UINT32 data = sh2->r[12] & 0x000000ff;
	sh2->r[1] -= 1;
	WB( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op21D4:
{
	UINT32 data = sh2->r[13] & 0x000000ff;
	sh2->r[1] -= 1;
	WB( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op21E4:
{
	UINT32 data = sh2->r[14] & 0x000000ff;
	sh2->r[1] -= 1;
	WB( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op21F4:
{
	UINT32 data = sh2->r[15] & 0x000000ff;
	sh2->r[1] -= 1;
	WB( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2204:
{
	UINT32 data = sh2->r[0] & 0x000000ff;
	sh2->r[2] -= 1;
	WB( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2214:
{
	UINT32 data = sh2->r[1] & 0x000000ff;
	sh2->r[2] -= 1;
	WB( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2224:
{
	UINT32 data = sh2->r[2] & 0x000000ff;
	sh2->r[2] -= 1;
	WB( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2234:
{
	UINT32 data = sh2->r[3] & 0x000000ff;
	sh2->r[2] -= 1;
	WB( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2244:
{
	UINT32 data = sh2->r[4] & 0x000000ff;
	sh2->r[2] -= 1;
	WB( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2254:
{
	UINT32 data = sh2->r[5] & 0x000000ff;
	sh2->r[2] -= 1;
	WB( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2264:
{
	UINT32 data = sh2->r[6] & 0x000000ff;
	sh2->r[2] -= 1;
	WB( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2274:
{
	UINT32 data = sh2->r[7] & 0x000000ff;
	sh2->r[2] -= 1;
	WB( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2284:
{
	UINT32 data = sh2->r[8] & 0x000000ff;
	sh2->r[2] -= 1;
	WB( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2294:
{
	UINT32 data = sh2->r[9] & 0x000000ff;
	sh2->r[2] -= 1;
	WB( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op22A4:
{
	UINT32 data = sh2->r[10] & 0x000000ff;
	sh2->r[2] -= 1;
	WB( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op22B4:
{
	UINT32 data = sh2->r[11] & 0x000000ff;
	sh2->r[2] -= 1;
	WB( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op22C4:
{
	UINT32 data = sh2->r[12] & 0x000000ff;
	sh2->r[2] -= 1;
	WB( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op22D4:
{
	UINT32 data = sh2->r[13] & 0x000000ff;
	sh2->r[2] -= 1;
	WB( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op22E4:
{
	UINT32 data = sh2->r[14] & 0x000000ff;
	sh2->r[2] -= 1;
	WB( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op22F4:
{
	UINT32 data = sh2->r[15] & 0x000000ff;
	sh2->r[2] -= 1;
	WB( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2304:
{
	UINT32 data = sh2->r[0] & 0x000000ff;
	sh2->r[3] -= 1;
	WB( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2314:
{
	UINT32 data = sh2->r[1] & 0x000000ff;
	sh2->r[3] -= 1;
	WB( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2324:
{
	UINT32 data = sh2->r[2] & 0x000000ff;
	sh2->r[3] -= 1;
	WB( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2334:
{
	UINT32 data = sh2->r[3] & 0x000000ff;
	sh2->r[3] -= 1;
	WB( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2344:
{
	UINT32 data = sh2->r[4] & 0x000000ff;
	sh2->r[3] -= 1;
	WB( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2354:
{
	UINT32 data = sh2->r[5] & 0x000000ff;
	sh2->r[3] -= 1;
	WB( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2364:
{
	UINT32 data = sh2->r[6] & 0x000000ff;
	sh2->r[3] -= 1;
	WB( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2374:
{
	UINT32 data = sh2->r[7] & 0x000000ff;
	sh2->r[3] -= 1;
	WB( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2384:
{
	UINT32 data = sh2->r[8] & 0x000000ff;
	sh2->r[3] -= 1;
	WB( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2394:
{
	UINT32 data = sh2->r[9] & 0x000000ff;
	sh2->r[3] -= 1;
	WB( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op23A4:
{
	UINT32 data = sh2->r[10] & 0x000000ff;
	sh2->r[3] -= 1;
	WB( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op23B4:
{
	UINT32 data = sh2->r[11] & 0x000000ff;
	sh2->r[3] -= 1;
	WB( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op23C4:
{
	UINT32 data = sh2->r[12] & 0x000000ff;
	sh2->r[3] -= 1;
	WB( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op23D4:
{
	UINT32 data = sh2->r[13] & 0x000000ff;
	sh2->r[3] -= 1;
	WB( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op23E4:
{
	UINT32 data = sh2->r[14] & 0x000000ff;
	sh2->r[3] -= 1;
	WB( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op23F4:
{
	UINT32 data = sh2->r[15] & 0x000000ff;
	sh2->r[3] -= 1;
	WB( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2404:
{
	UINT32 data = sh2->r[0] & 0x000000ff;
	sh2->r[4] -= 1;
	WB( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2414:
{
	UINT32 data = sh2->r[1] & 0x000000ff;
	sh2->r[4] -= 1;
	WB( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2424:
{
	UINT32 data = sh2->r[2] & 0x000000ff;
	sh2->r[4] -= 1;
	WB( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2434:
{
	UINT32 data = sh2->r[3] & 0x000000ff;
	sh2->r[4] -= 1;
	WB( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2444:
{
	UINT32 data = sh2->r[4] & 0x000000ff;
	sh2->r[4] -= 1;
	WB( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2454:
{
	UINT32 data = sh2->r[5] & 0x000000ff;
	sh2->r[4] -= 1;
	WB( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2464:
{
	UINT32 data = sh2->r[6] & 0x000000ff;
	sh2->r[4] -= 1;
	WB( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2474:
{
	UINT32 data = sh2->r[7] & 0x000000ff;
	sh2->r[4] -= 1;
	WB( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2484:
{
	UINT32 data = sh2->r[8] & 0x000000ff;
	sh2->r[4] -= 1;
	WB( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2494:
{
	UINT32 data = sh2->r[9] & 0x000000ff;
	sh2->r[4] -= 1;
	WB( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op24A4:
{
	UINT32 data = sh2->r[10] & 0x000000ff;
	sh2->r[4] -= 1;
	WB( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op24B4:
{
	UINT32 data = sh2->r[11] & 0x000000ff;
	sh2->r[4] -= 1;
	WB( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op24C4:
{
	UINT32 data = sh2->r[12] & 0x000000ff;
	sh2->r[4] -= 1;
	WB( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op24D4:
{
	UINT32 data = sh2->r[13] & 0x000000ff;
	sh2->r[4] -= 1;
	WB( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op24E4:
{
	UINT32 data = sh2->r[14] & 0x000000ff;
	sh2->r[4] -= 1;
	WB( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op24F4:
{
	UINT32 data = sh2->r[15] & 0x000000ff;
	sh2->r[4] -= 1;
	WB( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2504:
{
	UINT32 data = sh2->r[0] & 0x000000ff;
	sh2->r[5] -= 1;
	WB( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2514:
{
	UINT32 data = sh2->r[1] & 0x000000ff;
	sh2->r[5] -= 1;
	WB( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2524:
{
	UINT32 data = sh2->r[2] & 0x000000ff;
	sh2->r[5] -= 1;
	WB( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2534:
{
	UINT32 data = sh2->r[3] & 0x000000ff;
	sh2->r[5] -= 1;
	WB( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2544:
{
	UINT32 data = sh2->r[4] & 0x000000ff;
	sh2->r[5] -= 1;
	WB( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2554:
{
	UINT32 data = sh2->r[5] & 0x000000ff;
	sh2->r[5] -= 1;
	WB( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2564:
{
	UINT32 data = sh2->r[6] & 0x000000ff;
	sh2->r[5] -= 1;
	WB( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2574:
{
	UINT32 data = sh2->r[7] & 0x000000ff;
	sh2->r[5] -= 1;
	WB( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2584:
{
	UINT32 data = sh2->r[8] & 0x000000ff;
	sh2->r[5] -= 1;
	WB( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2594:
{
	UINT32 data = sh2->r[9] & 0x000000ff;
	sh2->r[5] -= 1;
	WB( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op25A4:
{
	UINT32 data = sh2->r[10] & 0x000000ff;
	sh2->r[5] -= 1;
	WB( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op25B4:
{
	UINT32 data = sh2->r[11] & 0x000000ff;
	sh2->r[5] -= 1;
	WB( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op25C4:
{
	UINT32 data = sh2->r[12] & 0x000000ff;
	sh2->r[5] -= 1;
	WB( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op25D4:
{
	UINT32 data = sh2->r[13] & 0x000000ff;
	sh2->r[5] -= 1;
	WB( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op25E4:
{
	UINT32 data = sh2->r[14] & 0x000000ff;
	sh2->r[5] -= 1;
	WB( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op25F4:
{
	UINT32 data = sh2->r[15] & 0x000000ff;
	sh2->r[5] -= 1;
	WB( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2604:
{
	UINT32 data = sh2->r[0] & 0x000000ff;
	sh2->r[6] -= 1;
	WB( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2614:
{
	UINT32 data = sh2->r[1] & 0x000000ff;
	sh2->r[6] -= 1;
	WB( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2624:
{
	UINT32 data = sh2->r[2] & 0x000000ff;
	sh2->r[6] -= 1;
	WB( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2634:
{
	UINT32 data = sh2->r[3] & 0x000000ff;
	sh2->r[6] -= 1;
	WB( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2644:
{
	UINT32 data = sh2->r[4] & 0x000000ff;
	sh2->r[6] -= 1;
	WB( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2654:
{
	UINT32 data = sh2->r[5] & 0x000000ff;
	sh2->r[6] -= 1;
	WB( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2664:
{
	UINT32 data = sh2->r[6] & 0x000000ff;
	sh2->r[6] -= 1;
	WB( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2674:
{
	UINT32 data = sh2->r[7] & 0x000000ff;
	sh2->r[6] -= 1;
	WB( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2684:
{
	UINT32 data = sh2->r[8] & 0x000000ff;
	sh2->r[6] -= 1;
	WB( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2694:
{
	UINT32 data = sh2->r[9] & 0x000000ff;
	sh2->r[6] -= 1;
	WB( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op26A4:
{
	UINT32 data = sh2->r[10] & 0x000000ff;
	sh2->r[6] -= 1;
	WB( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op26B4:
{
	UINT32 data = sh2->r[11] & 0x000000ff;
	sh2->r[6] -= 1;
	WB( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op26C4:
{
	UINT32 data = sh2->r[12] & 0x000000ff;
	sh2->r[6] -= 1;
	WB( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op26D4:
{
	UINT32 data = sh2->r[13] & 0x000000ff;
	sh2->r[6] -= 1;
	WB( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op26E4:
{
	UINT32 data = sh2->r[14] & 0x000000ff;
	sh2->r[6] -= 1;
	WB( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op26F4:
{
	UINT32 data = sh2->r[15] & 0x000000ff;
	sh2->r[6] -= 1;
	WB( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2704:
{
	UINT32 data = sh2->r[0] & 0x000000ff;
	sh2->r[7] -= 1;
	WB( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2714:
{
	UINT32 data = sh2->r[1] & 0x000000ff;
	sh2->r[7] -= 1;
	WB( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2724:
{
	UINT32 data = sh2->r[2] & 0x000000ff;
	sh2->r[7] -= 1;
	WB( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2734:
{
	UINT32 data = sh2->r[3] & 0x000000ff;
	sh2->r[7] -= 1;
	WB( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2744:
{
	UINT32 data = sh2->r[4] & 0x000000ff;
	sh2->r[7] -= 1;
	WB( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2754:
{
	UINT32 data = sh2->r[5] & 0x000000ff;
	sh2->r[7] -= 1;
	WB( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2764:
{
	UINT32 data = sh2->r[6] & 0x000000ff;
	sh2->r[7] -= 1;
	WB( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2774:
{
	UINT32 data = sh2->r[7] & 0x000000ff;
	sh2->r[7] -= 1;
	WB( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2784:
{
	UINT32 data = sh2->r[8] & 0x000000ff;
	sh2->r[7] -= 1;
	WB( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2794:
{
	UINT32 data = sh2->r[9] & 0x000000ff;
	sh2->r[7] -= 1;
	WB( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op27A4:
{
	UINT32 data = sh2->r[10] & 0x000000ff;
	sh2->r[7] -= 1;
	WB( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op27B4:
{
	UINT32 data = sh2->r[11] & 0x000000ff;
	sh2->r[7] -= 1;
	WB( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op27C4:
{
	UINT32 data = sh2->r[12] & 0x000000ff;
	sh2->r[7] -= 1;
	WB( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op27D4:
{
	UINT32 data = sh2->r[13] & 0x000000ff;
	sh2->r[7] -= 1;
	WB( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op27E4:
{
	UINT32 data = sh2->r[14] & 0x000000ff;
	sh2->r[7] -= 1;
	WB( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op27F4:
{
	UINT32 data = sh2->r[15] & 0x000000ff;
	sh2->r[7] -= 1;
	WB( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2804:
{
	UINT32 data = sh2->r[0] & 0x000000ff;
	sh2->r[8] -= 1;
	WB( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2814:
{
	UINT32 data = sh2->r[1] & 0x000000ff;
	sh2->r[8] -= 1;
	WB( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2824:
{
	UINT32 data = sh2->r[2] & 0x000000ff;
	sh2->r[8] -= 1;
	WB( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2834:
{
	UINT32 data = sh2->r[3] & 0x000000ff;
	sh2->r[8] -= 1;
	WB( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2844:
{
	UINT32 data = sh2->r[4] & 0x000000ff;
	sh2->r[8] -= 1;
	WB( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2854:
{
	UINT32 data = sh2->r[5] & 0x000000ff;
	sh2->r[8] -= 1;
	WB( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2864:
{
	UINT32 data = sh2->r[6] & 0x000000ff;
	sh2->r[8] -= 1;
	WB( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2874:
{
	UINT32 data = sh2->r[7] & 0x000000ff;
	sh2->r[8] -= 1;
	WB( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2884:
{
	UINT32 data = sh2->r[8] & 0x000000ff;
	sh2->r[8] -= 1;
	WB( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2894:
{
	UINT32 data = sh2->r[9] & 0x000000ff;
	sh2->r[8] -= 1;
	WB( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op28A4:
{
	UINT32 data = sh2->r[10] & 0x000000ff;
	sh2->r[8] -= 1;
	WB( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op28B4:
{
	UINT32 data = sh2->r[11] & 0x000000ff;
	sh2->r[8] -= 1;
	WB( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op28C4:
{
	UINT32 data = sh2->r[12] & 0x000000ff;
	sh2->r[8] -= 1;
	WB( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op28D4:
{
	UINT32 data = sh2->r[13] & 0x000000ff;
	sh2->r[8] -= 1;
	WB( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op28E4:
{
	UINT32 data = sh2->r[14] & 0x000000ff;
	sh2->r[8] -= 1;
	WB( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op28F4:
{
	UINT32 data = sh2->r[15] & 0x000000ff;
	sh2->r[8] -= 1;
	WB( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2904:
{
	UINT32 data = sh2->r[0] & 0x000000ff;
	sh2->r[9] -= 1;
	WB( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2914:
{
	UINT32 data = sh2->r[1] & 0x000000ff;
	sh2->r[9] -= 1;
	WB( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2924:
{
	UINT32 data = sh2->r[2] & 0x000000ff;
	sh2->r[9] -= 1;
	WB( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2934:
{
	UINT32 data = sh2->r[3] & 0x000000ff;
	sh2->r[9] -= 1;
	WB( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2944:
{
	UINT32 data = sh2->r[4] & 0x000000ff;
	sh2->r[9] -= 1;
	WB( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2954:
{
	UINT32 data = sh2->r[5] & 0x000000ff;
	sh2->r[9] -= 1;
	WB( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2964:
{
	UINT32 data = sh2->r[6] & 0x000000ff;
	sh2->r[9] -= 1;
	WB( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2974:
{
	UINT32 data = sh2->r[7] & 0x000000ff;
	sh2->r[9] -= 1;
	WB( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2984:
{
	UINT32 data = sh2->r[8] & 0x000000ff;
	sh2->r[9] -= 1;
	WB( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2994:
{
	UINT32 data = sh2->r[9] & 0x000000ff;
	sh2->r[9] -= 1;
	WB( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op29A4:
{
	UINT32 data = sh2->r[10] & 0x000000ff;
	sh2->r[9] -= 1;
	WB( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op29B4:
{
	UINT32 data = sh2->r[11] & 0x000000ff;
	sh2->r[9] -= 1;
	WB( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op29C4:
{
	UINT32 data = sh2->r[12] & 0x000000ff;
	sh2->r[9] -= 1;
	WB( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op29D4:
{
	UINT32 data = sh2->r[13] & 0x000000ff;
	sh2->r[9] -= 1;
	WB( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op29E4:
{
	UINT32 data = sh2->r[14] & 0x000000ff;
	sh2->r[9] -= 1;
	WB( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op29F4:
{
	UINT32 data = sh2->r[15] & 0x000000ff;
	sh2->r[9] -= 1;
	WB( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2A04:
{
	UINT32 data = sh2->r[0] & 0x000000ff;
	sh2->r[10] -= 1;
	WB( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A14:
{
	UINT32 data = sh2->r[1] & 0x000000ff;
	sh2->r[10] -= 1;
	WB( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A24:
{
	UINT32 data = sh2->r[2] & 0x000000ff;
	sh2->r[10] -= 1;
	WB( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A34:
{
	UINT32 data = sh2->r[3] & 0x000000ff;
	sh2->r[10] -= 1;
	WB( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A44:
{
	UINT32 data = sh2->r[4] & 0x000000ff;
	sh2->r[10] -= 1;
	WB( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A54:
{
	UINT32 data = sh2->r[5] & 0x000000ff;
	sh2->r[10] -= 1;
	WB( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A64:
{
	UINT32 data = sh2->r[6] & 0x000000ff;
	sh2->r[10] -= 1;
	WB( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A74:
{
	UINT32 data = sh2->r[7] & 0x000000ff;
	sh2->r[10] -= 1;
	WB( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A84:
{
	UINT32 data = sh2->r[8] & 0x000000ff;
	sh2->r[10] -= 1;
	WB( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A94:
{
	UINT32 data = sh2->r[9] & 0x000000ff;
	sh2->r[10] -= 1;
	WB( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2AA4:
{
	UINT32 data = sh2->r[10] & 0x000000ff;
	sh2->r[10] -= 1;
	WB( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2AB4:
{
	UINT32 data = sh2->r[11] & 0x000000ff;
	sh2->r[10] -= 1;
	WB( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2AC4:
{
	UINT32 data = sh2->r[12] & 0x000000ff;
	sh2->r[10] -= 1;
	WB( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2AD4:
{
	UINT32 data = sh2->r[13] & 0x000000ff;
	sh2->r[10] -= 1;
	WB( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2AE4:
{
	UINT32 data = sh2->r[14] & 0x000000ff;
	sh2->r[10] -= 1;
	WB( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2AF4:
{
	UINT32 data = sh2->r[15] & 0x000000ff;
	sh2->r[10] -= 1;
	WB( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2B04:
{
	UINT32 data = sh2->r[0] & 0x000000ff;
	sh2->r[11] -= 1;
	WB( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B14:
{
	UINT32 data = sh2->r[1] & 0x000000ff;
	sh2->r[11] -= 1;
	WB( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B24:
{
	UINT32 data = sh2->r[2] & 0x000000ff;
	sh2->r[11] -= 1;
	WB( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B34:
{
	UINT32 data = sh2->r[3] & 0x000000ff;
	sh2->r[11] -= 1;
	WB( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B44:
{
	UINT32 data = sh2->r[4] & 0x000000ff;
	sh2->r[11] -= 1;
	WB( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B54:
{
	UINT32 data = sh2->r[5] & 0x000000ff;
	sh2->r[11] -= 1;
	WB( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B64:
{
	UINT32 data = sh2->r[6] & 0x000000ff;
	sh2->r[11] -= 1;
	WB( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B74:
{
	UINT32 data = sh2->r[7] & 0x000000ff;
	sh2->r[11] -= 1;
	WB( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B84:
{
	UINT32 data = sh2->r[8] & 0x000000ff;
	sh2->r[11] -= 1;
	WB( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B94:
{
	UINT32 data = sh2->r[9] & 0x000000ff;
	sh2->r[11] -= 1;
	WB( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2BA4:
{
	UINT32 data = sh2->r[10] & 0x000000ff;
	sh2->r[11] -= 1;
	WB( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2BB4:
{
	UINT32 data = sh2->r[11] & 0x000000ff;
	sh2->r[11] -= 1;
	WB( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2BC4:
{
	UINT32 data = sh2->r[12] & 0x000000ff;
	sh2->r[11] -= 1;
	WB( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2BD4:
{
	UINT32 data = sh2->r[13] & 0x000000ff;
	sh2->r[11] -= 1;
	WB( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2BE4:
{
	UINT32 data = sh2->r[14] & 0x000000ff;
	sh2->r[11] -= 1;
	WB( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2BF4:
{
	UINT32 data = sh2->r[15] & 0x000000ff;
	sh2->r[11] -= 1;
	WB( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2C04:
{
	UINT32 data = sh2->r[0] & 0x000000ff;
	sh2->r[12] -= 1;
	WB( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C14:
{
	UINT32 data = sh2->r[1] & 0x000000ff;
	sh2->r[12] -= 1;
	WB( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C24:
{
	UINT32 data = sh2->r[2] & 0x000000ff;
	sh2->r[12] -= 1;
	WB( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C34:
{
	UINT32 data = sh2->r[3] & 0x000000ff;
	sh2->r[12] -= 1;
	WB( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C44:
{
	UINT32 data = sh2->r[4] & 0x000000ff;
	sh2->r[12] -= 1;
	WB( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C54:
{
	UINT32 data = sh2->r[5] & 0x000000ff;
	sh2->r[12] -= 1;
	WB( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C64:
{
	UINT32 data = sh2->r[6] & 0x000000ff;
	sh2->r[12] -= 1;
	WB( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C74:
{
	UINT32 data = sh2->r[7] & 0x000000ff;
	sh2->r[12] -= 1;
	WB( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C84:
{
	UINT32 data = sh2->r[8] & 0x000000ff;
	sh2->r[12] -= 1;
	WB( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C94:
{
	UINT32 data = sh2->r[9] & 0x000000ff;
	sh2->r[12] -= 1;
	WB( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2CA4:
{
	UINT32 data = sh2->r[10] & 0x000000ff;
	sh2->r[12] -= 1;
	WB( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2CB4:
{
	UINT32 data = sh2->r[11] & 0x000000ff;
	sh2->r[12] -= 1;
	WB( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2CC4:
{
	UINT32 data = sh2->r[12] & 0x000000ff;
	sh2->r[12] -= 1;
	WB( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2CD4:
{
	UINT32 data = sh2->r[13] & 0x000000ff;
	sh2->r[12] -= 1;
	WB( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2CE4:
{
	UINT32 data = sh2->r[14] & 0x000000ff;
	sh2->r[12] -= 1;
	WB( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2CF4:
{
	UINT32 data = sh2->r[15] & 0x000000ff;
	sh2->r[12] -= 1;
	WB( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2D04:
{
	UINT32 data = sh2->r[0] & 0x000000ff;
	sh2->r[13] -= 1;
	WB( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D14:
{
	UINT32 data = sh2->r[1] & 0x000000ff;
	sh2->r[13] -= 1;
	WB( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D24:
{
	UINT32 data = sh2->r[2] & 0x000000ff;
	sh2->r[13] -= 1;
	WB( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D34:
{
	UINT32 data = sh2->r[3] & 0x000000ff;
	sh2->r[13] -= 1;
	WB( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D44:
{
	UINT32 data = sh2->r[4] & 0x000000ff;
	sh2->r[13] -= 1;
	WB( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D54:
{
	UINT32 data = sh2->r[5] & 0x000000ff;
	sh2->r[13] -= 1;
	WB( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D64:
{
	UINT32 data = sh2->r[6] & 0x000000ff;
	sh2->r[13] -= 1;
	WB( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D74:
{
	UINT32 data = sh2->r[7] & 0x000000ff;
	sh2->r[13] -= 1;
	WB( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D84:
{
	UINT32 data = sh2->r[8] & 0x000000ff;
	sh2->r[13] -= 1;
	WB( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D94:
{
	UINT32 data = sh2->r[9] & 0x000000ff;
	sh2->r[13] -= 1;
	WB( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2DA4:
{
	UINT32 data = sh2->r[10] & 0x000000ff;
	sh2->r[13] -= 1;
	WB( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2DB4:
{
	UINT32 data = sh2->r[11] & 0x000000ff;
	sh2->r[13] -= 1;
	WB( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2DC4:
{
	UINT32 data = sh2->r[12] & 0x000000ff;
	sh2->r[13] -= 1;
	WB( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2DD4:
{
	UINT32 data = sh2->r[13] & 0x000000ff;
	sh2->r[13] -= 1;
	WB( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2DE4:
{
	UINT32 data = sh2->r[14] & 0x000000ff;
	sh2->r[13] -= 1;
	WB( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2DF4:
{
	UINT32 data = sh2->r[15] & 0x000000ff;
	sh2->r[13] -= 1;
	WB( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2E04:
{
	UINT32 data = sh2->r[0] & 0x000000ff;
	sh2->r[14] -= 1;
	WB( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E14:
{
	UINT32 data = sh2->r[1] & 0x000000ff;
	sh2->r[14] -= 1;
	WB( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E24:
{
	UINT32 data = sh2->r[2] & 0x000000ff;
	sh2->r[14] -= 1;
	WB( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E34:
{
	UINT32 data = sh2->r[3] & 0x000000ff;
	sh2->r[14] -= 1;
	WB( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E44:
{
	UINT32 data = sh2->r[4] & 0x000000ff;
	sh2->r[14] -= 1;
	WB( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E54:
{
	UINT32 data = sh2->r[5] & 0x000000ff;
	sh2->r[14] -= 1;
	WB( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E64:
{
	UINT32 data = sh2->r[6] & 0x000000ff;
	sh2->r[14] -= 1;
	WB( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E74:
{
	UINT32 data = sh2->r[7] & 0x000000ff;
	sh2->r[14] -= 1;
	WB( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E84:
{
	UINT32 data = sh2->r[8] & 0x000000ff;
	sh2->r[14] -= 1;
	WB( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E94:
{
	UINT32 data = sh2->r[9] & 0x000000ff;
	sh2->r[14] -= 1;
	WB( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2EA4:
{
	UINT32 data = sh2->r[10] & 0x000000ff;
	sh2->r[14] -= 1;
	WB( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2EB4:
{
	UINT32 data = sh2->r[11] & 0x000000ff;
	sh2->r[14] -= 1;
	WB( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2EC4:
{
	UINT32 data = sh2->r[12] & 0x000000ff;
	sh2->r[14] -= 1;
	WB( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2ED4:
{
	UINT32 data = sh2->r[13] & 0x000000ff;
	sh2->r[14] -= 1;
	WB( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2EE4:
{
	UINT32 data = sh2->r[14] & 0x000000ff;
	sh2->r[14] -= 1;
	WB( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2EF4:
{
	UINT32 data = sh2->r[15] & 0x000000ff;
	sh2->r[14] -= 1;
	WB( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2F04:
{
	UINT32 data = sh2->r[0] & 0x000000ff;
	sh2->r[15] -= 1;
	WB( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F14:
{
	UINT32 data = sh2->r[1] & 0x000000ff;
	sh2->r[15] -= 1;
	WB( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F24:
{
	UINT32 data = sh2->r[2] & 0x000000ff;
	sh2->r[15] -= 1;
	WB( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F34:
{
	UINT32 data = sh2->r[3] & 0x000000ff;
	sh2->r[15] -= 1;
	WB( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F44:
{
	UINT32 data = sh2->r[4] & 0x000000ff;
	sh2->r[15] -= 1;
	WB( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F54:
{
	UINT32 data = sh2->r[5] & 0x000000ff;
	sh2->r[15] -= 1;
	WB( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F64:
{
	UINT32 data = sh2->r[6] & 0x000000ff;
	sh2->r[15] -= 1;
	WB( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F74:
{
	UINT32 data = sh2->r[7] & 0x000000ff;
	sh2->r[15] -= 1;
	WB( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F84:
{
	UINT32 data = sh2->r[8] & 0x000000ff;
	sh2->r[15] -= 1;
	WB( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F94:
{
	UINT32 data = sh2->r[9] & 0x000000ff;
	sh2->r[15] -= 1;
	WB( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2FA4:
{
	UINT32 data = sh2->r[10] & 0x000000ff;
	sh2->r[15] -= 1;
	WB( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2FB4:
{
	UINT32 data = sh2->r[11] & 0x000000ff;
	sh2->r[15] -= 1;
	WB( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2FC4:
{
	UINT32 data = sh2->r[12] & 0x000000ff;
	sh2->r[15] -= 1;
	WB( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2FD4:
{
	UINT32 data = sh2->r[13] & 0x000000ff;
	sh2->r[15] -= 1;
	WB( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2FE4:
{
	UINT32 data = sh2->r[14] & 0x000000ff;
	sh2->r[15] -= 1;
	WB( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2FF4:
{
	UINT32 data = sh2->r[15] & 0x000000ff;
	sh2->r[15] -= 1;
	WB( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

// MOV.W Rm,@-Rn
Op2005:
{
	UINT32 data = sh2->r[0] & 0x0000ffff;
	sh2->r[0] -= 2;
	WW( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2015:
{
	UINT32 data = sh2->r[1] & 0x0000ffff;
	sh2->r[0] -= 2;
	WW( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2025:
{
	UINT32 data = sh2->r[2] & 0x0000ffff;
	sh2->r[0] -= 2;
	WW( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2035:
{
	UINT32 data = sh2->r[3] & 0x0000ffff;
	sh2->r[0] -= 2;
	WW( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2045:
{
	UINT32 data = sh2->r[4] & 0x0000ffff;
	sh2->r[0] -= 2;
	WW( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2055:
{
	UINT32 data = sh2->r[5] & 0x0000ffff;
	sh2->r[0] -= 2;
	WW( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2065:
{
	UINT32 data = sh2->r[6] & 0x0000ffff;
	sh2->r[0] -= 2;
	WW( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2075:
{
	UINT32 data = sh2->r[7] & 0x0000ffff;
	sh2->r[0] -= 2;
	WW( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2085:
{
	UINT32 data = sh2->r[8] & 0x0000ffff;
	sh2->r[0] -= 2;
	WW( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2095:
{
	UINT32 data = sh2->r[9] & 0x0000ffff;
	sh2->r[0] -= 2;
	WW( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op20A5:
{
	UINT32 data = sh2->r[10] & 0x0000ffff;
	sh2->r[0] -= 2;
	WW( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op20B5:
{
	UINT32 data = sh2->r[11] & 0x0000ffff;
	sh2->r[0] -= 2;
	WW( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op20C5:
{
	UINT32 data = sh2->r[12] & 0x0000ffff;
	sh2->r[0] -= 2;
	WW( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op20D5:
{
	UINT32 data = sh2->r[13] & 0x0000ffff;
	sh2->r[0] -= 2;
	WW( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op20E5:
{
	UINT32 data = sh2->r[14] & 0x0000ffff;
	sh2->r[0] -= 2;
	WW( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op20F5:
{
	UINT32 data = sh2->r[15] & 0x0000ffff;
	sh2->r[0] -= 2;
	WW( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2105:
{
	UINT32 data = sh2->r[0] & 0x0000ffff;
	sh2->r[1] -= 2;
	WW( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2115:
{
	UINT32 data = sh2->r[1] & 0x0000ffff;
	sh2->r[1] -= 2;
	WW( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2125:
{
	UINT32 data = sh2->r[2] & 0x0000ffff;
	sh2->r[1] -= 2;
	WW( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2135:
{
	UINT32 data = sh2->r[3] & 0x0000ffff;
	sh2->r[1] -= 2;
	WW( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2145:
{
	UINT32 data = sh2->r[4] & 0x0000ffff;
	sh2->r[1] -= 2;
	WW( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2155:
{
	UINT32 data = sh2->r[5] & 0x0000ffff;
	sh2->r[1] -= 2;
	WW( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2165:
{
	UINT32 data = sh2->r[6] & 0x0000ffff;
	sh2->r[1] -= 2;
	WW( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2175:
{
	UINT32 data = sh2->r[7] & 0x0000ffff;
	sh2->r[1] -= 2;
	WW( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2185:
{
	UINT32 data = sh2->r[8] & 0x0000ffff;
	sh2->r[1] -= 2;
	WW( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2195:
{
	UINT32 data = sh2->r[9] & 0x0000ffff;
	sh2->r[1] -= 2;
	WW( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op21A5:
{
	UINT32 data = sh2->r[10] & 0x0000ffff;
	sh2->r[1] -= 2;
	WW( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op21B5:
{
	UINT32 data = sh2->r[11] & 0x0000ffff;
	sh2->r[1] -= 2;
	WW( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op21C5:
{
	UINT32 data = sh2->r[12] & 0x0000ffff;
	sh2->r[1] -= 2;
	WW( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op21D5:
{
	UINT32 data = sh2->r[13] & 0x0000ffff;
	sh2->r[1] -= 2;
	WW( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op21E5:
{
	UINT32 data = sh2->r[14] & 0x0000ffff;
	sh2->r[1] -= 2;
	WW( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op21F5:
{
	UINT32 data = sh2->r[15] & 0x0000ffff;
	sh2->r[1] -= 2;
	WW( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2205:
{
	UINT32 data = sh2->r[0] & 0x0000ffff;
	sh2->r[2] -= 2;
	WW( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2215:
{
	UINT32 data = sh2->r[1] & 0x0000ffff;
	sh2->r[2] -= 2;
	WW( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2225:
{
	UINT32 data = sh2->r[2] & 0x0000ffff;
	sh2->r[2] -= 2;
	WW( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2235:
{
	UINT32 data = sh2->r[3] & 0x0000ffff;
	sh2->r[2] -= 2;
	WW( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2245:
{
	UINT32 data = sh2->r[4] & 0x0000ffff;
	sh2->r[2] -= 2;
	WW( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2255:
{
	UINT32 data = sh2->r[5] & 0x0000ffff;
	sh2->r[2] -= 2;
	WW( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2265:
{
	UINT32 data = sh2->r[6] & 0x0000ffff;
	sh2->r[2] -= 2;
	WW( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2275:
{
	UINT32 data = sh2->r[7] & 0x0000ffff;
	sh2->r[2] -= 2;
	WW( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2285:
{
	UINT32 data = sh2->r[8] & 0x0000ffff;
	sh2->r[2] -= 2;
	WW( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2295:
{
	UINT32 data = sh2->r[9] & 0x0000ffff;
	sh2->r[2] -= 2;
	WW( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op22A5:
{
	UINT32 data = sh2->r[10] & 0x0000ffff;
	sh2->r[2] -= 2;
	WW( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op22B5:
{
	UINT32 data = sh2->r[11] & 0x0000ffff;
	sh2->r[2] -= 2;
	WW( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op22C5:
{
	UINT32 data = sh2->r[12] & 0x0000ffff;
	sh2->r[2] -= 2;
	WW( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op22D5:
{
	UINT32 data = sh2->r[13] & 0x0000ffff;
	sh2->r[2] -= 2;
	WW( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op22E5:
{
	UINT32 data = sh2->r[14] & 0x0000ffff;
	sh2->r[2] -= 2;
	WW( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op22F5:
{
	UINT32 data = sh2->r[15] & 0x0000ffff;
	sh2->r[2] -= 2;
	WW( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2305:
{
	UINT32 data = sh2->r[0] & 0x0000ffff;
	sh2->r[3] -= 2;
	WW( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2315:
{
	UINT32 data = sh2->r[1] & 0x0000ffff;
	sh2->r[3] -= 2;
	WW( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2325:
{
	UINT32 data = sh2->r[2] & 0x0000ffff;
	sh2->r[3] -= 2;
	WW( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2335:
{
	UINT32 data = sh2->r[3] & 0x0000ffff;
	sh2->r[3] -= 2;
	WW( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2345:
{
	UINT32 data = sh2->r[4] & 0x0000ffff;
	sh2->r[3] -= 2;
	WW( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2355:
{
	UINT32 data = sh2->r[5] & 0x0000ffff;
	sh2->r[3] -= 2;
	WW( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2365:
{
	UINT32 data = sh2->r[6] & 0x0000ffff;
	sh2->r[3] -= 2;
	WW( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2375:
{
	UINT32 data = sh2->r[7] & 0x0000ffff;
	sh2->r[3] -= 2;
	WW( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2385:
{
	UINT32 data = sh2->r[8] & 0x0000ffff;
	sh2->r[3] -= 2;
	WW( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2395:
{
	UINT32 data = sh2->r[9] & 0x0000ffff;
	sh2->r[3] -= 2;
	WW( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op23A5:
{
	UINT32 data = sh2->r[10] & 0x0000ffff;
	sh2->r[3] -= 2;
	WW( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op23B5:
{
	UINT32 data = sh2->r[11] & 0x0000ffff;
	sh2->r[3] -= 2;
	WW( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op23C5:
{
	UINT32 data = sh2->r[12] & 0x0000ffff;
	sh2->r[3] -= 2;
	WW( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op23D5:
{
	UINT32 data = sh2->r[13] & 0x0000ffff;
	sh2->r[3] -= 2;
	WW( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op23E5:
{
	UINT32 data = sh2->r[14] & 0x0000ffff;
	sh2->r[3] -= 2;
	WW( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op23F5:
{
	UINT32 data = sh2->r[15] & 0x0000ffff;
	sh2->r[3] -= 2;
	WW( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2405:
{
	UINT32 data = sh2->r[0] & 0x0000ffff;
	sh2->r[4] -= 2;
	WW( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2415:
{
	UINT32 data = sh2->r[1] & 0x0000ffff;
	sh2->r[4] -= 2;
	WW( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2425:
{
	UINT32 data = sh2->r[2] & 0x0000ffff;
	sh2->r[4] -= 2;
	WW( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2435:
{
	UINT32 data = sh2->r[3] & 0x0000ffff;
	sh2->r[4] -= 2;
	WW( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2445:
{
	UINT32 data = sh2->r[4] & 0x0000ffff;
	sh2->r[4] -= 2;
	WW( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2455:
{
	UINT32 data = sh2->r[5] & 0x0000ffff;
	sh2->r[4] -= 2;
	WW( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2465:
{
	UINT32 data = sh2->r[6] & 0x0000ffff;
	sh2->r[4] -= 2;
	WW( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2475:
{
	UINT32 data = sh2->r[7] & 0x0000ffff;
	sh2->r[4] -= 2;
	WW( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2485:
{
	UINT32 data = sh2->r[8] & 0x0000ffff;
	sh2->r[4] -= 2;
	WW( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2495:
{
	UINT32 data = sh2->r[9] & 0x0000ffff;
	sh2->r[4] -= 2;
	WW( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op24A5:
{
	UINT32 data = sh2->r[10] & 0x0000ffff;
	sh2->r[4] -= 2;
	WW( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op24B5:
{
	UINT32 data = sh2->r[11] & 0x0000ffff;
	sh2->r[4] -= 2;
	WW( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op24C5:
{
	UINT32 data = sh2->r[12] & 0x0000ffff;
	sh2->r[4] -= 2;
	WW( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op24D5:
{
	UINT32 data = sh2->r[13] & 0x0000ffff;
	sh2->r[4] -= 2;
	WW( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op24E5:
{
	UINT32 data = sh2->r[14] & 0x0000ffff;
	sh2->r[4] -= 2;
	WW( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op24F5:
{
	UINT32 data = sh2->r[15] & 0x0000ffff;
	sh2->r[4] -= 2;
	WW( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2505:
{
	UINT32 data = sh2->r[0] & 0x0000ffff;
	sh2->r[5] -= 2;
	WW( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2515:
{
	UINT32 data = sh2->r[1] & 0x0000ffff;
	sh2->r[5] -= 2;
	WW( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2525:
{
	UINT32 data = sh2->r[2] & 0x0000ffff;
	sh2->r[5] -= 2;
	WW( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2535:
{
	UINT32 data = sh2->r[3] & 0x0000ffff;
	sh2->r[5] -= 2;
	WW( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2545:
{
	UINT32 data = sh2->r[4] & 0x0000ffff;
	sh2->r[5] -= 2;
	WW( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2555:
{
	UINT32 data = sh2->r[5] & 0x0000ffff;
	sh2->r[5] -= 2;
	WW( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2565:
{
	UINT32 data = sh2->r[6] & 0x0000ffff;
	sh2->r[5] -= 2;
	WW( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2575:
{
	UINT32 data = sh2->r[7] & 0x0000ffff;
	sh2->r[5] -= 2;
	WW( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2585:
{
	UINT32 data = sh2->r[8] & 0x0000ffff;
	sh2->r[5] -= 2;
	WW( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2595:
{
	UINT32 data = sh2->r[9] & 0x0000ffff;
	sh2->r[5] -= 2;
	WW( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op25A5:
{
	UINT32 data = sh2->r[10] & 0x0000ffff;
	sh2->r[5] -= 2;
	WW( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op25B5:
{
	UINT32 data = sh2->r[11] & 0x0000ffff;
	sh2->r[5] -= 2;
	WW( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op25C5:
{
	UINT32 data = sh2->r[12] & 0x0000ffff;
	sh2->r[5] -= 2;
	WW( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op25D5:
{
	UINT32 data = sh2->r[13] & 0x0000ffff;
	sh2->r[5] -= 2;
	WW( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op25E5:
{
	UINT32 data = sh2->r[14] & 0x0000ffff;
	sh2->r[5] -= 2;
	WW( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op25F5:
{
	UINT32 data = sh2->r[15] & 0x0000ffff;
	sh2->r[5] -= 2;
	WW( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2605:
{
	UINT32 data = sh2->r[0] & 0x0000ffff;
	sh2->r[6] -= 2;
	WW( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2615:
{
	UINT32 data = sh2->r[1] & 0x0000ffff;
	sh2->r[6] -= 2;
	WW( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2625:
{
	UINT32 data = sh2->r[2] & 0x0000ffff;
	sh2->r[6] -= 2;
	WW( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2635:
{
	UINT32 data = sh2->r[3] & 0x0000ffff;
	sh2->r[6] -= 2;
	WW( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2645:
{
	UINT32 data = sh2->r[4] & 0x0000ffff;
	sh2->r[6] -= 2;
	WW( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2655:
{
	UINT32 data = sh2->r[5] & 0x0000ffff;
	sh2->r[6] -= 2;
	WW( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2665:
{
	UINT32 data = sh2->r[6] & 0x0000ffff;
	sh2->r[6] -= 2;
	WW( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2675:
{
	UINT32 data = sh2->r[7] & 0x0000ffff;
	sh2->r[6] -= 2;
	WW( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2685:
{
	UINT32 data = sh2->r[8] & 0x0000ffff;
	sh2->r[6] -= 2;
	WW( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2695:
{
	UINT32 data = sh2->r[9] & 0x0000ffff;
	sh2->r[6] -= 2;
	WW( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op26A5:
{
	UINT32 data = sh2->r[10] & 0x0000ffff;
	sh2->r[6] -= 2;
	WW( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op26B5:
{
	UINT32 data = sh2->r[11] & 0x0000ffff;
	sh2->r[6] -= 2;
	WW( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op26C5:
{
	UINT32 data = sh2->r[12] & 0x0000ffff;
	sh2->r[6] -= 2;
	WW( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op26D5:
{
	UINT32 data = sh2->r[13] & 0x0000ffff;
	sh2->r[6] -= 2;
	WW( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op26E5:
{
	UINT32 data = sh2->r[14] & 0x0000ffff;
	sh2->r[6] -= 2;
	WW( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op26F5:
{
	UINT32 data = sh2->r[15] & 0x0000ffff;
	sh2->r[6] -= 2;
	WW( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2705:
{
	UINT32 data = sh2->r[0] & 0x0000ffff;
	sh2->r[7] -= 2;
	WW( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2715:
{
	UINT32 data = sh2->r[1] & 0x0000ffff;
	sh2->r[7] -= 2;
	WW( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2725:
{
	UINT32 data = sh2->r[2] & 0x0000ffff;
	sh2->r[7] -= 2;
	WW( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2735:
{
	UINT32 data = sh2->r[3] & 0x0000ffff;
	sh2->r[7] -= 2;
	WW( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2745:
{
	UINT32 data = sh2->r[4] & 0x0000ffff;
	sh2->r[7] -= 2;
	WW( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2755:
{
	UINT32 data = sh2->r[5] & 0x0000ffff;
	sh2->r[7] -= 2;
	WW( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2765:
{
	UINT32 data = sh2->r[6] & 0x0000ffff;
	sh2->r[7] -= 2;
	WW( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2775:
{
	UINT32 data = sh2->r[7] & 0x0000ffff;
	sh2->r[7] -= 2;
	WW( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2785:
{
	UINT32 data = sh2->r[8] & 0x0000ffff;
	sh2->r[7] -= 2;
	WW( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2795:
{
	UINT32 data = sh2->r[9] & 0x0000ffff;
	sh2->r[7] -= 2;
	WW( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op27A5:
{
	UINT32 data = sh2->r[10] & 0x0000ffff;
	sh2->r[7] -= 2;
	WW( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op27B5:
{
	UINT32 data = sh2->r[11] & 0x0000ffff;
	sh2->r[7] -= 2;
	WW( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op27C5:
{
	UINT32 data = sh2->r[12] & 0x0000ffff;
	sh2->r[7] -= 2;
	WW( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op27D5:
{
	UINT32 data = sh2->r[13] & 0x0000ffff;
	sh2->r[7] -= 2;
	WW( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op27E5:
{
	UINT32 data = sh2->r[14] & 0x0000ffff;
	sh2->r[7] -= 2;
	WW( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op27F5:
{
	UINT32 data = sh2->r[15] & 0x0000ffff;
	sh2->r[7] -= 2;
	WW( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2805:
{
	UINT32 data = sh2->r[0] & 0x0000ffff;
	sh2->r[8] -= 2;
	WW( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2815:
{
	UINT32 data = sh2->r[1] & 0x0000ffff;
	sh2->r[8] -= 2;
	WW( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2825:
{
	UINT32 data = sh2->r[2] & 0x0000ffff;
	sh2->r[8] -= 2;
	WW( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2835:
{
	UINT32 data = sh2->r[3] & 0x0000ffff;
	sh2->r[8] -= 2;
	WW( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2845:
{
	UINT32 data = sh2->r[4] & 0x0000ffff;
	sh2->r[8] -= 2;
	WW( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2855:
{
	UINT32 data = sh2->r[5] & 0x0000ffff;
	sh2->r[8] -= 2;
	WW( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2865:
{
	UINT32 data = sh2->r[6] & 0x0000ffff;
	sh2->r[8] -= 2;
	WW( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2875:
{
	UINT32 data = sh2->r[7] & 0x0000ffff;
	sh2->r[8] -= 2;
	WW( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2885:
{
	UINT32 data = sh2->r[8] & 0x0000ffff;
	sh2->r[8] -= 2;
	WW( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2895:
{
	UINT32 data = sh2->r[9] & 0x0000ffff;
	sh2->r[8] -= 2;
	WW( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op28A5:
{
	UINT32 data = sh2->r[10] & 0x0000ffff;
	sh2->r[8] -= 2;
	WW( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op28B5:
{
	UINT32 data = sh2->r[11] & 0x0000ffff;
	sh2->r[8] -= 2;
	WW( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op28C5:
{
	UINT32 data = sh2->r[12] & 0x0000ffff;
	sh2->r[8] -= 2;
	WW( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op28D5:
{
	UINT32 data = sh2->r[13] & 0x0000ffff;
	sh2->r[8] -= 2;
	WW( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op28E5:
{
	UINT32 data = sh2->r[14] & 0x0000ffff;
	sh2->r[8] -= 2;
	WW( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op28F5:
{
	UINT32 data = sh2->r[15] & 0x0000ffff;
	sh2->r[8] -= 2;
	WW( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2905:
{
	UINT32 data = sh2->r[0] & 0x0000ffff;
	sh2->r[9] -= 2;
	WW( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2915:
{
	UINT32 data = sh2->r[1] & 0x0000ffff;
	sh2->r[9] -= 2;
	WW( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2925:
{
	UINT32 data = sh2->r[2] & 0x0000ffff;
	sh2->r[9] -= 2;
	WW( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2935:
{
	UINT32 data = sh2->r[3] & 0x0000ffff;
	sh2->r[9] -= 2;
	WW( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2945:
{
	UINT32 data = sh2->r[4] & 0x0000ffff;
	sh2->r[9] -= 2;
	WW( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2955:
{
	UINT32 data = sh2->r[5] & 0x0000ffff;
	sh2->r[9] -= 2;
	WW( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2965:
{
	UINT32 data = sh2->r[6] & 0x0000ffff;
	sh2->r[9] -= 2;
	WW( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2975:
{
	UINT32 data = sh2->r[7] & 0x0000ffff;
	sh2->r[9] -= 2;
	WW( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2985:
{
	UINT32 data = sh2->r[8] & 0x0000ffff;
	sh2->r[9] -= 2;
	WW( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2995:
{
	UINT32 data = sh2->r[9] & 0x0000ffff;
	sh2->r[9] -= 2;
	WW( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op29A5:
{
	UINT32 data = sh2->r[10] & 0x0000ffff;
	sh2->r[9] -= 2;
	WW( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op29B5:
{
	UINT32 data = sh2->r[11] & 0x0000ffff;
	sh2->r[9] -= 2;
	WW( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op29C5:
{
	UINT32 data = sh2->r[12] & 0x0000ffff;
	sh2->r[9] -= 2;
	WW( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op29D5:
{
	UINT32 data = sh2->r[13] & 0x0000ffff;
	sh2->r[9] -= 2;
	WW( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op29E5:
{
	UINT32 data = sh2->r[14] & 0x0000ffff;
	sh2->r[9] -= 2;
	WW( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op29F5:
{
	UINT32 data = sh2->r[15] & 0x0000ffff;
	sh2->r[9] -= 2;
	WW( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2A05:
{
	UINT32 data = sh2->r[0] & 0x0000ffff;
	sh2->r[10] -= 2;
	WW( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A15:
{
	UINT32 data = sh2->r[1] & 0x0000ffff;
	sh2->r[10] -= 2;
	WW( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A25:
{
	UINT32 data = sh2->r[2] & 0x0000ffff;
	sh2->r[10] -= 2;
	WW( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A35:
{
	UINT32 data = sh2->r[3] & 0x0000ffff;
	sh2->r[10] -= 2;
	WW( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A45:
{
	UINT32 data = sh2->r[4] & 0x0000ffff;
	sh2->r[10] -= 2;
	WW( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A55:
{
	UINT32 data = sh2->r[5] & 0x0000ffff;
	sh2->r[10] -= 2;
	WW( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A65:
{
	UINT32 data = sh2->r[6] & 0x0000ffff;
	sh2->r[10] -= 2;
	WW( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A75:
{
	UINT32 data = sh2->r[7] & 0x0000ffff;
	sh2->r[10] -= 2;
	WW( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A85:
{
	UINT32 data = sh2->r[8] & 0x0000ffff;
	sh2->r[10] -= 2;
	WW( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A95:
{
	UINT32 data = sh2->r[9] & 0x0000ffff;
	sh2->r[10] -= 2;
	WW( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2AA5:
{
	UINT32 data = sh2->r[10] & 0x0000ffff;
	sh2->r[10] -= 2;
	WW( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2AB5:
{
	UINT32 data = sh2->r[11] & 0x0000ffff;
	sh2->r[10] -= 2;
	WW( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2AC5:
{
	UINT32 data = sh2->r[12] & 0x0000ffff;
	sh2->r[10] -= 2;
	WW( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2AD5:
{
	UINT32 data = sh2->r[13] & 0x0000ffff;
	sh2->r[10] -= 2;
	WW( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2AE5:
{
	UINT32 data = sh2->r[14] & 0x0000ffff;
	sh2->r[10] -= 2;
	WW( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2AF5:
{
	UINT32 data = sh2->r[15] & 0x0000ffff;
	sh2->r[10] -= 2;
	WW( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2B05:
{
	UINT32 data = sh2->r[0] & 0x0000ffff;
	sh2->r[11] -= 2;
	WW( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B15:
{
	UINT32 data = sh2->r[1] & 0x0000ffff;
	sh2->r[11] -= 2;
	WW( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B25:
{
	UINT32 data = sh2->r[2] & 0x0000ffff;
	sh2->r[11] -= 2;
	WW( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B35:
{
	UINT32 data = sh2->r[3] & 0x0000ffff;
	sh2->r[11] -= 2;
	WW( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B45:
{
	UINT32 data = sh2->r[4] & 0x0000ffff;
	sh2->r[11] -= 2;
	WW( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B55:
{
	UINT32 data = sh2->r[5] & 0x0000ffff;
	sh2->r[11] -= 2;
	WW( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B65:
{
	UINT32 data = sh2->r[6] & 0x0000ffff;
	sh2->r[11] -= 2;
	WW( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B75:
{
	UINT32 data = sh2->r[7] & 0x0000ffff;
	sh2->r[11] -= 2;
	WW( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B85:
{
	UINT32 data = sh2->r[8] & 0x0000ffff;
	sh2->r[11] -= 2;
	WW( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B95:
{
	UINT32 data = sh2->r[9] & 0x0000ffff;
	sh2->r[11] -= 2;
	WW( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2BA5:
{
	UINT32 data = sh2->r[10] & 0x0000ffff;
	sh2->r[11] -= 2;
	WW( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2BB5:
{
	UINT32 data = sh2->r[11] & 0x0000ffff;
	sh2->r[11] -= 2;
	WW( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2BC5:
{
	UINT32 data = sh2->r[12] & 0x0000ffff;
	sh2->r[11] -= 2;
	WW( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2BD5:
{
	UINT32 data = sh2->r[13] & 0x0000ffff;
	sh2->r[11] -= 2;
	WW( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2BE5:
{
	UINT32 data = sh2->r[14] & 0x0000ffff;
	sh2->r[11] -= 2;
	WW( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2BF5:
{
	UINT32 data = sh2->r[15] & 0x0000ffff;
	sh2->r[11] -= 2;
	WW( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2C05:
{
	UINT32 data = sh2->r[0] & 0x0000ffff;
	sh2->r[12] -= 2;
	WW( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C15:
{
	UINT32 data = sh2->r[1] & 0x0000ffff;
	sh2->r[12] -= 2;
	WW( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C25:
{
	UINT32 data = sh2->r[2] & 0x0000ffff;
	sh2->r[12] -= 2;
	WW( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C35:
{
	UINT32 data = sh2->r[3] & 0x0000ffff;
	sh2->r[12] -= 2;
	WW( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C45:
{
	UINT32 data = sh2->r[4] & 0x0000ffff;
	sh2->r[12] -= 2;
	WW( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C55:
{
	UINT32 data = sh2->r[5] & 0x0000ffff;
	sh2->r[12] -= 2;
	WW( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C65:
{
	UINT32 data = sh2->r[6] & 0x0000ffff;
	sh2->r[12] -= 2;
	WW( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C75:
{
	UINT32 data = sh2->r[7] & 0x0000ffff;
	sh2->r[12] -= 2;
	WW( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C85:
{
	UINT32 data = sh2->r[8] & 0x0000ffff;
	sh2->r[12] -= 2;
	WW( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C95:
{
	UINT32 data = sh2->r[9] & 0x0000ffff;
	sh2->r[12] -= 2;
	WW( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2CA5:
{
	UINT32 data = sh2->r[10] & 0x0000ffff;
	sh2->r[12] -= 2;
	WW( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2CB5:
{
	UINT32 data = sh2->r[11] & 0x0000ffff;
	sh2->r[12] -= 2;
	WW( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2CC5:
{
	UINT32 data = sh2->r[12] & 0x0000ffff;
	sh2->r[12] -= 2;
	WW( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2CD5:
{
	UINT32 data = sh2->r[13] & 0x0000ffff;
	sh2->r[12] -= 2;
	WW( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2CE5:
{
	UINT32 data = sh2->r[14] & 0x0000ffff;
	sh2->r[12] -= 2;
	WW( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2CF5:
{
	UINT32 data = sh2->r[15] & 0x0000ffff;
	sh2->r[12] -= 2;
	WW( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2D05:
{
	UINT32 data = sh2->r[0] & 0x0000ffff;
	sh2->r[13] -= 2;
	WW( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D15:
{
	UINT32 data = sh2->r[1] & 0x0000ffff;
	sh2->r[13] -= 2;
	WW( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D25:
{
	UINT32 data = sh2->r[2] & 0x0000ffff;
	sh2->r[13] -= 2;
	WW( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D35:
{
	UINT32 data = sh2->r[3] & 0x0000ffff;
	sh2->r[13] -= 2;
	WW( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D45:
{
	UINT32 data = sh2->r[4] & 0x0000ffff;
	sh2->r[13] -= 2;
	WW( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D55:
{
	UINT32 data = sh2->r[5] & 0x0000ffff;
	sh2->r[13] -= 2;
	WW( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D65:
{
	UINT32 data = sh2->r[6] & 0x0000ffff;
	sh2->r[13] -= 2;
	WW( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D75:
{
	UINT32 data = sh2->r[7] & 0x0000ffff;
	sh2->r[13] -= 2;
	WW( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D85:
{
	UINT32 data = sh2->r[8] & 0x0000ffff;
	sh2->r[13] -= 2;
	WW( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D95:
{
	UINT32 data = sh2->r[9] & 0x0000ffff;
	sh2->r[13] -= 2;
	WW( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2DA5:
{
	UINT32 data = sh2->r[10] & 0x0000ffff;
	sh2->r[13] -= 2;
	WW( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2DB5:
{
	UINT32 data = sh2->r[11] & 0x0000ffff;
	sh2->r[13] -= 2;
	WW( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2DC5:
{
	UINT32 data = sh2->r[12] & 0x0000ffff;
	sh2->r[13] -= 2;
	WW( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2DD5:
{
	UINT32 data = sh2->r[13] & 0x0000ffff;
	sh2->r[13] -= 2;
	WW( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2DE5:
{
	UINT32 data = sh2->r[14] & 0x0000ffff;
	sh2->r[13] -= 2;
	WW( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2DF5:
{
	UINT32 data = sh2->r[15] & 0x0000ffff;
	sh2->r[13] -= 2;
	WW( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2E05:
{
	UINT32 data = sh2->r[0] & 0x0000ffff;
	sh2->r[14] -= 2;
	WW( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E15:
{
	UINT32 data = sh2->r[1] & 0x0000ffff;
	sh2->r[14] -= 2;
	WW( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E25:
{
	UINT32 data = sh2->r[2] & 0x0000ffff;
	sh2->r[14] -= 2;
	WW( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E35:
{
	UINT32 data = sh2->r[3] & 0x0000ffff;
	sh2->r[14] -= 2;
	WW( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E45:
{
	UINT32 data = sh2->r[4] & 0x0000ffff;
	sh2->r[14] -= 2;
	WW( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E55:
{
	UINT32 data = sh2->r[5] & 0x0000ffff;
	sh2->r[14] -= 2;
	WW( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E65:
{
	UINT32 data = sh2->r[6] & 0x0000ffff;
	sh2->r[14] -= 2;
	WW( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E75:
{
	UINT32 data = sh2->r[7] & 0x0000ffff;
	sh2->r[14] -= 2;
	WW( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E85:
{
	UINT32 data = sh2->r[8] & 0x0000ffff;
	sh2->r[14] -= 2;
	WW( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E95:
{
	UINT32 data = sh2->r[9] & 0x0000ffff;
	sh2->r[14] -= 2;
	WW( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2EA5:
{
	UINT32 data = sh2->r[10] & 0x0000ffff;
	sh2->r[14] -= 2;
	WW( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2EB5:
{
	UINT32 data = sh2->r[11] & 0x0000ffff;
	sh2->r[14] -= 2;
	WW( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2EC5:
{
	UINT32 data = sh2->r[12] & 0x0000ffff;
	sh2->r[14] -= 2;
	WW( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2ED5:
{
	UINT32 data = sh2->r[13] & 0x0000ffff;
	sh2->r[14] -= 2;
	WW( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2EE5:
{
	UINT32 data = sh2->r[14] & 0x0000ffff;
	sh2->r[14] -= 2;
	WW( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2EF5:
{
	UINT32 data = sh2->r[15] & 0x0000ffff;
	sh2->r[14] -= 2;
	WW( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2F05:
{
	UINT32 data = sh2->r[0] & 0x0000ffff;
	sh2->r[15] -= 2;
	WW( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F15:
{
	UINT32 data = sh2->r[1] & 0x0000ffff;
	sh2->r[15] -= 2;
	WW( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F25:
{
	UINT32 data = sh2->r[2] & 0x0000ffff;
	sh2->r[15] -= 2;
	WW( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F35:
{
	UINT32 data = sh2->r[3] & 0x0000ffff;
	sh2->r[15] -= 2;
	WW( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F45:
{
	UINT32 data = sh2->r[4] & 0x0000ffff;
	sh2->r[15] -= 2;
	WW( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F55:
{
	UINT32 data = sh2->r[5] & 0x0000ffff;
	sh2->r[15] -= 2;
	WW( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F65:
{
	UINT32 data = sh2->r[6] & 0x0000ffff;
	sh2->r[15] -= 2;
	WW( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F75:
{
	UINT32 data = sh2->r[7] & 0x0000ffff;
	sh2->r[15] -= 2;
	WW( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F85:
{
	UINT32 data = sh2->r[8] & 0x0000ffff;
	sh2->r[15] -= 2;
	WW( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F95:
{
	UINT32 data = sh2->r[9] & 0x0000ffff;
	sh2->r[15] -= 2;
	WW( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2FA5:
{
	UINT32 data = sh2->r[10] & 0x0000ffff;
	sh2->r[15] -= 2;
	WW( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2FB5:
{
	UINT32 data = sh2->r[11] & 0x0000ffff;
	sh2->r[15] -= 2;
	WW( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2FC5:
{
	UINT32 data = sh2->r[12] & 0x0000ffff;
	sh2->r[15] -= 2;
	WW( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2FD5:
{
	UINT32 data = sh2->r[13] & 0x0000ffff;
	sh2->r[15] -= 2;
	WW( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2FE5:
{
	UINT32 data = sh2->r[14] & 0x0000ffff;
	sh2->r[15] -= 2;
	WW( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2FF5:
{
	UINT32 data = sh2->r[15] & 0x0000ffff;
	sh2->r[15] -= 2;
	WW( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

// MOV.L Rm,@-Rn
Op2006:
{
	UINT32 data = sh2->r[0];
	sh2->r[0] -= 4;
	WL( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2016:
{
	UINT32 data = sh2->r[1];
	sh2->r[0] -= 4;
	WL( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2026:
{
	UINT32 data = sh2->r[2];
	sh2->r[0] -= 4;
	WL( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2036:
{
	UINT32 data = sh2->r[3];
	sh2->r[0] -= 4;
	WL( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2046:
{
	UINT32 data = sh2->r[4];
	sh2->r[0] -= 4;
	WL( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2056:
{
	UINT32 data = sh2->r[5];
	sh2->r[0] -= 4;
	WL( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2066:
{
	UINT32 data = sh2->r[6];
	sh2->r[0] -= 4;
	WL( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2076:
{
	UINT32 data = sh2->r[7];
	sh2->r[0] -= 4;
	WL( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2086:
{
	UINT32 data = sh2->r[8];
	sh2->r[0] -= 4;
	WL( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2096:
{
	UINT32 data = sh2->r[9];
	sh2->r[0] -= 4;
	WL( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op20A6:
{
	UINT32 data = sh2->r[10];
	sh2->r[0] -= 4;
	WL( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op20B6:
{
	UINT32 data = sh2->r[11];
	sh2->r[0] -= 4;
	WL( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op20C6:
{
	UINT32 data = sh2->r[12];
	sh2->r[0] -= 4;
	WL( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op20D6:
{
	UINT32 data = sh2->r[13];
	sh2->r[0] -= 4;
	WL( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op20E6:
{
	UINT32 data = sh2->r[14];
	sh2->r[0] -= 4;
	WL( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op20F6:
{
	UINT32 data = sh2->r[15];
	sh2->r[0] -= 4;
	WL( sh2->r[0], data );
	goto SH2_RUN_CONTINUE;
}

Op2106:
{
	UINT32 data = sh2->r[0];
	sh2->r[1] -= 4;
	WL( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2116:
{
	UINT32 data = sh2->r[1];
	sh2->r[1] -= 4;
	WL( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2126:
{
	UINT32 data = sh2->r[2];
	sh2->r[1] -= 4;
	WL( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2136:
{
	UINT32 data = sh2->r[3];
	sh2->r[1] -= 4;
	WL( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2146:
{
	UINT32 data = sh2->r[4];
	sh2->r[1] -= 4;
	WL( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2156:
{
	UINT32 data = sh2->r[5];
	sh2->r[1] -= 4;
	WL( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2166:
{
	UINT32 data = sh2->r[6];
	sh2->r[1] -= 4;
	WL( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2176:
{
	UINT32 data = sh2->r[7];
	sh2->r[1] -= 4;
	WL( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2186:
{
	UINT32 data = sh2->r[8];
	sh2->r[1] -= 4;
	WL( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2196:
{
	UINT32 data = sh2->r[9];
	sh2->r[1] -= 4;
	WL( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op21A6:
{
	UINT32 data = sh2->r[10];
	sh2->r[1] -= 4;
	WL( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op21B6:
{
	UINT32 data = sh2->r[11];
	sh2->r[1] -= 4;
	WL( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op21C6:
{
	UINT32 data = sh2->r[12];
	sh2->r[1] -= 4;
	WL( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op21D6:
{
	UINT32 data = sh2->r[13];
	sh2->r[1] -= 4;
	WL( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op21E6:
{
	UINT32 data = sh2->r[14];
	sh2->r[1] -= 4;
	WL( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op21F6:
{
	UINT32 data = sh2->r[15];
	sh2->r[1] -= 4;
	WL( sh2->r[1], data );
	goto SH2_RUN_CONTINUE;
}

Op2206:
{
	UINT32 data = sh2->r[0];
	sh2->r[2] -= 4;
	WL( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2216:
{
	UINT32 data = sh2->r[1];
	sh2->r[2] -= 4;
	WL( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2226:
{
	UINT32 data = sh2->r[2];
	sh2->r[2] -= 4;
	WL( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2236:
{
	UINT32 data = sh2->r[3];
	sh2->r[2] -= 4;
	WL( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2246:
{
	UINT32 data = sh2->r[4];
	sh2->r[2] -= 4;
	WL( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2256:
{
	UINT32 data = sh2->r[5];
	sh2->r[2] -= 4;
	WL( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2266:
{
	UINT32 data = sh2->r[6];
	sh2->r[2] -= 4;
	WL( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2276:
{
	UINT32 data = sh2->r[7];
	sh2->r[2] -= 4;
	WL( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2286:
{
	UINT32 data = sh2->r[8];
	sh2->r[2] -= 4;
	WL( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2296:
{
	UINT32 data = sh2->r[9];
	sh2->r[2] -= 4;
	WL( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op22A6:
{
	UINT32 data = sh2->r[10];
	sh2->r[2] -= 4;
	WL( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op22B6:
{
	UINT32 data = sh2->r[11];
	sh2->r[2] -= 4;
	WL( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op22C6:
{
	UINT32 data = sh2->r[12];
	sh2->r[2] -= 4;
	WL( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op22D6:
{
	UINT32 data = sh2->r[13];
	sh2->r[2] -= 4;
	WL( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op22E6:
{
	UINT32 data = sh2->r[14];
	sh2->r[2] -= 4;
	WL( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op22F6:
{
	UINT32 data = sh2->r[15];
	sh2->r[2] -= 4;
	WL( sh2->r[2], data );
	goto SH2_RUN_CONTINUE;
}

Op2306:
{
	UINT32 data = sh2->r[0];
	sh2->r[3] -= 4;
	WL( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2316:
{
	UINT32 data = sh2->r[1];
	sh2->r[3] -= 4;
	WL( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2326:
{
	UINT32 data = sh2->r[2];
	sh2->r[3] -= 4;
	WL( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2336:
{
	UINT32 data = sh2->r[3];
	sh2->r[3] -= 4;
	WL( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2346:
{
	UINT32 data = sh2->r[4];
	sh2->r[3] -= 4;
	WL( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2356:
{
	UINT32 data = sh2->r[5];
	sh2->r[3] -= 4;
	WL( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2366:
{
	UINT32 data = sh2->r[6];
	sh2->r[3] -= 4;
	WL( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2376:
{
	UINT32 data = sh2->r[7];
	sh2->r[3] -= 4;
	WL( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2386:
{
	UINT32 data = sh2->r[8];
	sh2->r[3] -= 4;
	WL( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2396:
{
	UINT32 data = sh2->r[9];
	sh2->r[3] -= 4;
	WL( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op23A6:
{
	UINT32 data = sh2->r[10];
	sh2->r[3] -= 4;
	WL( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op23B6:
{
	UINT32 data = sh2->r[11];
	sh2->r[3] -= 4;
	WL( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op23C6:
{
	UINT32 data = sh2->r[12];
	sh2->r[3] -= 4;
	WL( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op23D6:
{
	UINT32 data = sh2->r[13];
	sh2->r[3] -= 4;
	WL( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op23E6:
{
	UINT32 data = sh2->r[14];
	sh2->r[3] -= 4;
	WL( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op23F6:
{
	UINT32 data = sh2->r[15];
	sh2->r[3] -= 4;
	WL( sh2->r[3], data );
	goto SH2_RUN_CONTINUE;
}

Op2406:
{
	UINT32 data = sh2->r[0];
	sh2->r[4] -= 4;
	WL( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2416:
{
	UINT32 data = sh2->r[1];
	sh2->r[4] -= 4;
	WL( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2426:
{
	UINT32 data = sh2->r[2];
	sh2->r[4] -= 4;
	WL( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2436:
{
	UINT32 data = sh2->r[3];
	sh2->r[4] -= 4;
	WL( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2446:
{
	UINT32 data = sh2->r[4];
	sh2->r[4] -= 4;
	WL( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2456:
{
	UINT32 data = sh2->r[5];
	sh2->r[4] -= 4;
	WL( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2466:
{
	UINT32 data = sh2->r[6];
	sh2->r[4] -= 4;
	WL( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2476:
{
	UINT32 data = sh2->r[7];
	sh2->r[4] -= 4;
	WL( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2486:
{
	UINT32 data = sh2->r[8];
	sh2->r[4] -= 4;
	WL( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2496:
{
	UINT32 data = sh2->r[9];
	sh2->r[4] -= 4;
	WL( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op24A6:
{
	UINT32 data = sh2->r[10];
	sh2->r[4] -= 4;
	WL( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op24B6:
{
	UINT32 data = sh2->r[11];
	sh2->r[4] -= 4;
	WL( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op24C6:
{
	UINT32 data = sh2->r[12];
	sh2->r[4] -= 4;
	WL( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op24D6:
{
	UINT32 data = sh2->r[13];
	sh2->r[4] -= 4;
	WL( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op24E6:
{
	UINT32 data = sh2->r[14];
	sh2->r[4] -= 4;
	WL( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op24F6:
{
	UINT32 data = sh2->r[15];
	sh2->r[4] -= 4;
	WL( sh2->r[4], data );
	goto SH2_RUN_CONTINUE;
}

Op2506:
{
	UINT32 data = sh2->r[0];
	sh2->r[5] -= 4;
	WL( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2516:
{
	UINT32 data = sh2->r[1];
	sh2->r[5] -= 4;
	WL( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2526:
{
	UINT32 data = sh2->r[2];
	sh2->r[5] -= 4;
	WL( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2536:
{
	UINT32 data = sh2->r[3];
	sh2->r[5] -= 4;
	WL( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2546:
{
	UINT32 data = sh2->r[4];
	sh2->r[5] -= 4;
	WL( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2556:
{
	UINT32 data = sh2->r[5];
	sh2->r[5] -= 4;
	WL( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2566:
{
	UINT32 data = sh2->r[6];
	sh2->r[5] -= 4;
	WL( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2576:
{
	UINT32 data = sh2->r[7];
	sh2->r[5] -= 4;
	WL( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2586:
{
	UINT32 data = sh2->r[8];
	sh2->r[5] -= 4;
	WL( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2596:
{
	UINT32 data = sh2->r[9];
	sh2->r[5] -= 4;
	WL( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op25A6:
{
	UINT32 data = sh2->r[10];
	sh2->r[5] -= 4;
	WL( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op25B6:
{
	UINT32 data = sh2->r[11];
	sh2->r[5] -= 4;
	WL( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op25C6:
{
	UINT32 data = sh2->r[12];
	sh2->r[5] -= 4;
	WL( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op25D6:
{
	UINT32 data = sh2->r[13];
	sh2->r[5] -= 4;
	WL( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op25E6:
{
	UINT32 data = sh2->r[14];
	sh2->r[5] -= 4;
	WL( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op25F6:
{
	UINT32 data = sh2->r[15];
	sh2->r[5] -= 4;
	WL( sh2->r[5], data );
	goto SH2_RUN_CONTINUE;
}

Op2606:
{
	UINT32 data = sh2->r[0];
	sh2->r[6] -= 4;
	WL( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2616:
{
	UINT32 data = sh2->r[1];
	sh2->r[6] -= 4;
	WL( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2626:
{
	UINT32 data = sh2->r[2];
	sh2->r[6] -= 4;
	WL( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2636:
{
	UINT32 data = sh2->r[3];
	sh2->r[6] -= 4;
	WL( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2646:
{
	UINT32 data = sh2->r[4];
	sh2->r[6] -= 4;
	WL( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2656:
{
	UINT32 data = sh2->r[5];
	sh2->r[6] -= 4;
	WL( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2666:
{
	UINT32 data = sh2->r[6];
	sh2->r[6] -= 4;
	WL( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2676:
{
	UINT32 data = sh2->r[7];
	sh2->r[6] -= 4;
	WL( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2686:
{
	UINT32 data = sh2->r[8];
	sh2->r[6] -= 4;
	WL( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2696:
{
	UINT32 data = sh2->r[9];
	sh2->r[6] -= 4;
	WL( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op26A6:
{
	UINT32 data = sh2->r[10];
	sh2->r[6] -= 4;
	WL( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op26B6:
{
	UINT32 data = sh2->r[11];
	sh2->r[6] -= 4;
	WL( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op26C6:
{
	UINT32 data = sh2->r[12];
	sh2->r[6] -= 4;
	WL( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op26D6:
{
	UINT32 data = sh2->r[13];
	sh2->r[6] -= 4;
	WL( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op26E6:
{
	UINT32 data = sh2->r[14];
	sh2->r[6] -= 4;
	WL( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op26F6:
{
	UINT32 data = sh2->r[15];
	sh2->r[6] -= 4;
	WL( sh2->r[6], data );
	goto SH2_RUN_CONTINUE;
}

Op2706:
{
	UINT32 data = sh2->r[0];
	sh2->r[7] -= 4;
	WL( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2716:
{
	UINT32 data = sh2->r[1];
	sh2->r[7] -= 4;
	WL( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2726:
{
	UINT32 data = sh2->r[2];
	sh2->r[7] -= 4;
	WL( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2736:
{
	UINT32 data = sh2->r[3];
	sh2->r[7] -= 4;
	WL( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2746:
{
	UINT32 data = sh2->r[4];
	sh2->r[7] -= 4;
	WL( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2756:
{
	UINT32 data = sh2->r[5];
	sh2->r[7] -= 4;
	WL( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2766:
{
	UINT32 data = sh2->r[6];
	sh2->r[7] -= 4;
	WL( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2776:
{
	UINT32 data = sh2->r[7];
	sh2->r[7] -= 4;
	WL( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2786:
{
	UINT32 data = sh2->r[8];
	sh2->r[7] -= 4;
	WL( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2796:
{
	UINT32 data = sh2->r[9];
	sh2->r[7] -= 4;
	WL( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op27A6:
{
	UINT32 data = sh2->r[10];
	sh2->r[7] -= 4;
	WL( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op27B6:
{
	UINT32 data = sh2->r[11];
	sh2->r[7] -= 4;
	WL( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op27C6:
{
	UINT32 data = sh2->r[12];
	sh2->r[7] -= 4;
	WL( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op27D6:
{
	UINT32 data = sh2->r[13];
	sh2->r[7] -= 4;
	WL( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op27E6:
{
	UINT32 data = sh2->r[14];
	sh2->r[7] -= 4;
	WL( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op27F6:
{
	UINT32 data = sh2->r[15];
	sh2->r[7] -= 4;
	WL( sh2->r[7], data );
	goto SH2_RUN_CONTINUE;
}

Op2806:
{
	UINT32 data = sh2->r[0];
	sh2->r[8] -= 4;
	WL( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2816:
{
	UINT32 data = sh2->r[1];
	sh2->r[8] -= 4;
	WL( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2826:
{
	UINT32 data = sh2->r[2];
	sh2->r[8] -= 4;
	WL( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2836:
{
	UINT32 data = sh2->r[3];
	sh2->r[8] -= 4;
	WL( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2846:
{
	UINT32 data = sh2->r[4];
	sh2->r[8] -= 4;
	WL( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2856:
{
	UINT32 data = sh2->r[5];
	sh2->r[8] -= 4;
	WL( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2866:
{
	UINT32 data = sh2->r[6];
	sh2->r[8] -= 4;
	WL( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2876:
{
	UINT32 data = sh2->r[7];
	sh2->r[8] -= 4;
	WL( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2886:
{
	UINT32 data = sh2->r[8];
	sh2->r[8] -= 4;
	WL( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2896:
{
	UINT32 data = sh2->r[9];
	sh2->r[8] -= 4;
	WL( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op28A6:
{
	UINT32 data = sh2->r[10];
	sh2->r[8] -= 4;
	WL( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op28B6:
{
	UINT32 data = sh2->r[11];
	sh2->r[8] -= 4;
	WL( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op28C6:
{
	UINT32 data = sh2->r[12];
	sh2->r[8] -= 4;
	WL( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op28D6:
{
	UINT32 data = sh2->r[13];
	sh2->r[8] -= 4;
	WL( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op28E6:
{
	UINT32 data = sh2->r[14];
	sh2->r[8] -= 4;
	WL( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op28F6:
{
	UINT32 data = sh2->r[15];
	sh2->r[8] -= 4;
	WL( sh2->r[8], data );
	goto SH2_RUN_CONTINUE;
}

Op2906:
{
	UINT32 data = sh2->r[0];
	sh2->r[9] -= 4;
	WL( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2916:
{
	UINT32 data = sh2->r[1];
	sh2->r[9] -= 4;
	WL( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2926:
{
	UINT32 data = sh2->r[2];
	sh2->r[9] -= 4;
	WL( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2936:
{
	UINT32 data = sh2->r[3];
	sh2->r[9] -= 4;
	WL( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2946:
{
	UINT32 data = sh2->r[4];
	sh2->r[9] -= 4;
	WL( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2956:
{
	UINT32 data = sh2->r[5];
	sh2->r[9] -= 4;
	WL( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2966:
{
	UINT32 data = sh2->r[6];
	sh2->r[9] -= 4;
	WL( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2976:
{
	UINT32 data = sh2->r[7];
	sh2->r[9] -= 4;
	WL( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2986:
{
	UINT32 data = sh2->r[8];
	sh2->r[9] -= 4;
	WL( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2996:
{
	UINT32 data = sh2->r[9];
	sh2->r[9] -= 4;
	WL( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op29A6:
{
	UINT32 data = sh2->r[10];
	sh2->r[9] -= 4;
	WL( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op29B6:
{
	UINT32 data = sh2->r[11];
	sh2->r[9] -= 4;
	WL( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op29C6:
{
	UINT32 data = sh2->r[12];
	sh2->r[9] -= 4;
	WL( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op29D6:
{
	UINT32 data = sh2->r[13];
	sh2->r[9] -= 4;
	WL( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op29E6:
{
	UINT32 data = sh2->r[14];
	sh2->r[9] -= 4;
	WL( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op29F6:
{
	UINT32 data = sh2->r[15];
	sh2->r[9] -= 4;
	WL( sh2->r[9], data );
	goto SH2_RUN_CONTINUE;
}

Op2A06:
{
	UINT32 data = sh2->r[0];
	sh2->r[10] -= 4;
	WL( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A16:
{
	UINT32 data = sh2->r[1];
	sh2->r[10] -= 4;
	WL( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A26:
{
	UINT32 data = sh2->r[2];
	sh2->r[10] -= 4;
	WL( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A36:
{
	UINT32 data = sh2->r[3];
	sh2->r[10] -= 4;
	WL( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A46:
{
	UINT32 data = sh2->r[4];
	sh2->r[10] -= 4;
	WL( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A56:
{
	UINT32 data = sh2->r[5];
	sh2->r[10] -= 4;
	WL( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A66:
{
	UINT32 data = sh2->r[6];
	sh2->r[10] -= 4;
	WL( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A76:
{
	UINT32 data = sh2->r[7];
	sh2->r[10] -= 4;
	WL( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A86:
{
	UINT32 data = sh2->r[8];
	sh2->r[10] -= 4;
	WL( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2A96:
{
	UINT32 data = sh2->r[9];
	sh2->r[10] -= 4;
	WL( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2AA6:
{
	UINT32 data = sh2->r[10];
	sh2->r[10] -= 4;
	WL( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2AB6:
{
	UINT32 data = sh2->r[11];
	sh2->r[10] -= 4;
	WL( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2AC6:
{
	UINT32 data = sh2->r[12];
	sh2->r[10] -= 4;
	WL( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2AD6:
{
	UINT32 data = sh2->r[13];
	sh2->r[10] -= 4;
	WL( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2AE6:
{
	UINT32 data = sh2->r[14];
	sh2->r[10] -= 4;
	WL( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2AF6:
{
	UINT32 data = sh2->r[15];
	sh2->r[10] -= 4;
	WL( sh2->r[10], data );
	goto SH2_RUN_CONTINUE;
}

Op2B06:
{
	UINT32 data = sh2->r[0];
	sh2->r[11] -= 4;
	WL( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B16:
{
	UINT32 data = sh2->r[1];
	sh2->r[11] -= 4;
	WL( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B26:
{
	UINT32 data = sh2->r[2];
	sh2->r[11] -= 4;
	WL( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B36:
{
	UINT32 data = sh2->r[3];
	sh2->r[11] -= 4;
	WL( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B46:
{
	UINT32 data = sh2->r[4];
	sh2->r[11] -= 4;
	WL( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B56:
{
	UINT32 data = sh2->r[5];
	sh2->r[11] -= 4;
	WL( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B66:
{
	UINT32 data = sh2->r[6];
	sh2->r[11] -= 4;
	WL( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B76:
{
	UINT32 data = sh2->r[7];
	sh2->r[11] -= 4;
	WL( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B86:
{
	UINT32 data = sh2->r[8];
	sh2->r[11] -= 4;
	WL( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2B96:
{
	UINT32 data = sh2->r[9];
	sh2->r[11] -= 4;
	WL( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2BA6:
{
	UINT32 data = sh2->r[10];
	sh2->r[11] -= 4;
	WL( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2BB6:
{
	UINT32 data = sh2->r[11];
	sh2->r[11] -= 4;
	WL( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2BC6:
{
	UINT32 data = sh2->r[12];
	sh2->r[11] -= 4;
	WL( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2BD6:
{
	UINT32 data = sh2->r[13];
	sh2->r[11] -= 4;
	WL( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2BE6:
{
	UINT32 data = sh2->r[14];
	sh2->r[11] -= 4;
	WL( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2BF6:
{
	UINT32 data = sh2->r[15];
	sh2->r[11] -= 4;
	WL( sh2->r[11], data );
	goto SH2_RUN_CONTINUE;
}

Op2C06:
{
	UINT32 data = sh2->r[0];
	sh2->r[12] -= 4;
	WL( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C16:
{
	UINT32 data = sh2->r[1];
	sh2->r[12] -= 4;
	WL( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C26:
{
	UINT32 data = sh2->r[2];
	sh2->r[12] -= 4;
	WL( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C36:
{
	UINT32 data = sh2->r[3];
	sh2->r[12] -= 4;
	WL( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C46:
{
	UINT32 data = sh2->r[4];
	sh2->r[12] -= 4;
	WL( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C56:
{
	UINT32 data = sh2->r[5];
	sh2->r[12] -= 4;
	WL( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C66:
{
	UINT32 data = sh2->r[6];
	sh2->r[12] -= 4;
	WL( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C76:
{
	UINT32 data = sh2->r[7];
	sh2->r[12] -= 4;
	WL( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C86:
{
	UINT32 data = sh2->r[8];
	sh2->r[12] -= 4;
	WL( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2C96:
{
	UINT32 data = sh2->r[9];
	sh2->r[12] -= 4;
	WL( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2CA6:
{
	UINT32 data = sh2->r[10];
	sh2->r[12] -= 4;
	WL( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2CB6:
{
	UINT32 data = sh2->r[11];
	sh2->r[12] -= 4;
	WL( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2CC6:
{
	UINT32 data = sh2->r[12];
	sh2->r[12] -= 4;
	WL( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2CD6:
{
	UINT32 data = sh2->r[13];
	sh2->r[12] -= 4;
	WL( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2CE6:
{
	UINT32 data = sh2->r[14];
	sh2->r[12] -= 4;
	WL( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2CF6:
{
	UINT32 data = sh2->r[15];
	sh2->r[12] -= 4;
	WL( sh2->r[12], data );
	goto SH2_RUN_CONTINUE;
}

Op2D06:
{
	UINT32 data = sh2->r[0];
	sh2->r[13] -= 4;
	WL( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D16:
{
	UINT32 data = sh2->r[1];
	sh2->r[13] -= 4;
	WL( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D26:
{
	UINT32 data = sh2->r[2];
	sh2->r[13] -= 4;
	WL( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D36:
{
	UINT32 data = sh2->r[3];
	sh2->r[13] -= 4;
	WL( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D46:
{
	UINT32 data = sh2->r[4];
	sh2->r[13] -= 4;
	WL( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D56:
{
	UINT32 data = sh2->r[5];
	sh2->r[13] -= 4;
	WL( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D66:
{
	UINT32 data = sh2->r[6];
	sh2->r[13] -= 4;
	WL( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D76:
{
	UINT32 data = sh2->r[7];
	sh2->r[13] -= 4;
	WL( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D86:
{
	UINT32 data = sh2->r[8];
	sh2->r[13] -= 4;
	WL( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2D96:
{
	UINT32 data = sh2->r[9];
	sh2->r[13] -= 4;
	WL( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2DA6:
{
	UINT32 data = sh2->r[10];
	sh2->r[13] -= 4;
	WL( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2DB6:
{
	UINT32 data = sh2->r[11];
	sh2->r[13] -= 4;
	WL( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2DC6:
{
	UINT32 data = sh2->r[12];
	sh2->r[13] -= 4;
	WL( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2DD6:
{
	UINT32 data = sh2->r[13];
	sh2->r[13] -= 4;
	WL( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2DE6:
{
	UINT32 data = sh2->r[14];
	sh2->r[13] -= 4;
	WL( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2DF6:
{
	UINT32 data = sh2->r[15];
	sh2->r[13] -= 4;
	WL( sh2->r[13], data );
	goto SH2_RUN_CONTINUE;
}

Op2E06:
{
	UINT32 data = sh2->r[0];
	sh2->r[14] -= 4;
	WL( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E16:
{
	UINT32 data = sh2->r[1];
	sh2->r[14] -= 4;
	WL( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E26:
{
	UINT32 data = sh2->r[2];
	sh2->r[14] -= 4;
	WL( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E36:
{
	UINT32 data = sh2->r[3];
	sh2->r[14] -= 4;
	WL( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E46:
{
	UINT32 data = sh2->r[4];
	sh2->r[14] -= 4;
	WL( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E56:
{
	UINT32 data = sh2->r[5];
	sh2->r[14] -= 4;
	WL( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E66:
{
	UINT32 data = sh2->r[6];
	sh2->r[14] -= 4;
	WL( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E76:
{
	UINT32 data = sh2->r[7];
	sh2->r[14] -= 4;
	WL( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E86:
{
	UINT32 data = sh2->r[8];
	sh2->r[14] -= 4;
	WL( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2E96:
{
	UINT32 data = sh2->r[9];
	sh2->r[14] -= 4;
	WL( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2EA6:
{
	UINT32 data = sh2->r[10];
	sh2->r[14] -= 4;
	WL( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2EB6:
{
	UINT32 data = sh2->r[11];
	sh2->r[14] -= 4;
	WL( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2EC6:
{
	UINT32 data = sh2->r[12];
	sh2->r[14] -= 4;
	WL( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2ED6:
{
	UINT32 data = sh2->r[13];
	sh2->r[14] -= 4;
	WL( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2EE6:
{
	UINT32 data = sh2->r[14];
	sh2->r[14] -= 4;
	WL( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2EF6:
{
	UINT32 data = sh2->r[15];
	sh2->r[14] -= 4;
	WL( sh2->r[14], data );
	goto SH2_RUN_CONTINUE;
}

Op2F06:
{
	UINT32 data = sh2->r[0];
	sh2->r[15] -= 4;
	WL( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F16:
{
	UINT32 data = sh2->r[1];
	sh2->r[15] -= 4;
	WL( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F26:
{
	UINT32 data = sh2->r[2];
	sh2->r[15] -= 4;
	WL( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F36:
{
	UINT32 data = sh2->r[3];
	sh2->r[15] -= 4;
	WL( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F46:
{
	UINT32 data = sh2->r[4];
	sh2->r[15] -= 4;
	WL( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F56:
{
	UINT32 data = sh2->r[5];
	sh2->r[15] -= 4;
	WL( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F66:
{
	UINT32 data = sh2->r[6];
	sh2->r[15] -= 4;
	WL( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F76:
{
	UINT32 data = sh2->r[7];
	sh2->r[15] -= 4;
	WL( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F86:
{
	UINT32 data = sh2->r[8];
	sh2->r[15] -= 4;
	WL( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2F96:
{
	UINT32 data = sh2->r[9];
	sh2->r[15] -= 4;
	WL( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2FA6:
{
	UINT32 data = sh2->r[10];
	sh2->r[15] -= 4;
	WL( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2FB6:
{
	UINT32 data = sh2->r[11];
	sh2->r[15] -= 4;
	WL( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2FC6:
{
	UINT32 data = sh2->r[12];
	sh2->r[15] -= 4;
	WL( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2FD6:
{
	UINT32 data = sh2->r[13];
	sh2->r[15] -= 4;
	WL( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2FE6:
{
	UINT32 data = sh2->r[14];
	sh2->r[15] -= 4;
	WL( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

Op2FF6:
{
	UINT32 data = sh2->r[15];
	sh2->r[15] -= 4;
	WL( sh2->r[15], data );
	goto SH2_RUN_CONTINUE;
}

// DIV0S Rm,Rn
Op2007:
{
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[0] ^ sh2->r[0]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2017:
{
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[1] ^ sh2->r[0]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2027:
{
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[2] ^ sh2->r[0]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2037:
{
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[3] ^ sh2->r[0]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2047:
{
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[4] ^ sh2->r[0]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2057:
{
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[5] ^ sh2->r[0]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2067:
{
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[6] ^ sh2->r[0]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2077:
{
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[7] ^ sh2->r[0]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2087:
{
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[8] ^ sh2->r[0]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2097:
{
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[9] ^ sh2->r[0]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op20A7:
{
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[10] ^ sh2->r[0]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op20B7:
{
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[11] ^ sh2->r[0]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op20C7:
{
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[12] ^ sh2->r[0]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op20D7:
{
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[13] ^ sh2->r[0]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op20E7:
{
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[14] ^ sh2->r[0]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op20F7:
{
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[15] ^ sh2->r[0]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2107:
{
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[0] ^ sh2->r[1]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2117:
{
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[1] ^ sh2->r[1]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2127:
{
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[2] ^ sh2->r[1]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2137:
{
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[3] ^ sh2->r[1]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2147:
{
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[4] ^ sh2->r[1]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2157:
{
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[5] ^ sh2->r[1]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2167:
{
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[6] ^ sh2->r[1]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2177:
{
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[7] ^ sh2->r[1]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2187:
{
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[8] ^ sh2->r[1]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2197:
{
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[9] ^ sh2->r[1]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op21A7:
{
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[10] ^ sh2->r[1]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op21B7:
{
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[11] ^ sh2->r[1]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op21C7:
{
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[12] ^ sh2->r[1]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op21D7:
{
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[13] ^ sh2->r[1]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op21E7:
{
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[14] ^ sh2->r[1]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op21F7:
{
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[15] ^ sh2->r[1]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2207:
{
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[0] ^ sh2->r[2]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2217:
{
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[1] ^ sh2->r[2]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2227:
{
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[2] ^ sh2->r[2]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2237:
{
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[3] ^ sh2->r[2]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2247:
{
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[4] ^ sh2->r[2]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2257:
{
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[5] ^ sh2->r[2]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2267:
{
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[6] ^ sh2->r[2]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2277:
{
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[7] ^ sh2->r[2]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2287:
{
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[8] ^ sh2->r[2]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2297:
{
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[9] ^ sh2->r[2]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op22A7:
{
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[10] ^ sh2->r[2]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op22B7:
{
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[11] ^ sh2->r[2]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op22C7:
{
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[12] ^ sh2->r[2]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op22D7:
{
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[13] ^ sh2->r[2]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op22E7:
{
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[14] ^ sh2->r[2]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op22F7:
{
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[15] ^ sh2->r[2]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2307:
{
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[0] ^ sh2->r[3]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2317:
{
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[1] ^ sh2->r[3]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2327:
{
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[2] ^ sh2->r[3]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2337:
{
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[3] ^ sh2->r[3]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2347:
{
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[4] ^ sh2->r[3]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2357:
{
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[5] ^ sh2->r[3]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2367:
{
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[6] ^ sh2->r[3]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2377:
{
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[7] ^ sh2->r[3]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2387:
{
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[8] ^ sh2->r[3]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2397:
{
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[9] ^ sh2->r[3]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op23A7:
{
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[10] ^ sh2->r[3]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op23B7:
{
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[11] ^ sh2->r[3]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op23C7:
{
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[12] ^ sh2->r[3]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op23D7:
{
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[13] ^ sh2->r[3]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op23E7:
{
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[14] ^ sh2->r[3]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op23F7:
{
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[15] ^ sh2->r[3]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2407:
{
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[0] ^ sh2->r[4]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2417:
{
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[1] ^ sh2->r[4]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2427:
{
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[2] ^ sh2->r[4]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2437:
{
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[3] ^ sh2->r[4]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2447:
{
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[4] ^ sh2->r[4]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2457:
{
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[5] ^ sh2->r[4]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2467:
{
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[6] ^ sh2->r[4]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2477:
{
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[7] ^ sh2->r[4]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2487:
{
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[8] ^ sh2->r[4]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2497:
{
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[9] ^ sh2->r[4]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op24A7:
{
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[10] ^ sh2->r[4]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op24B7:
{
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[11] ^ sh2->r[4]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op24C7:
{
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[12] ^ sh2->r[4]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op24D7:
{
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[13] ^ sh2->r[4]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op24E7:
{
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[14] ^ sh2->r[4]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op24F7:
{
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[15] ^ sh2->r[4]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2507:
{
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[0] ^ sh2->r[5]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2517:
{
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[1] ^ sh2->r[5]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2527:
{
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[2] ^ sh2->r[5]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2537:
{
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[3] ^ sh2->r[5]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2547:
{
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[4] ^ sh2->r[5]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2557:
{
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[5] ^ sh2->r[5]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2567:
{
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[6] ^ sh2->r[5]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2577:
{
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[7] ^ sh2->r[5]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2587:
{
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[8] ^ sh2->r[5]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2597:
{
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[9] ^ sh2->r[5]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op25A7:
{
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[10] ^ sh2->r[5]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op25B7:
{
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[11] ^ sh2->r[5]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op25C7:
{
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[12] ^ sh2->r[5]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op25D7:
{
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[13] ^ sh2->r[5]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op25E7:
{
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[14] ^ sh2->r[5]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op25F7:
{
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[15] ^ sh2->r[5]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2607:
{
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[0] ^ sh2->r[6]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2617:
{
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[1] ^ sh2->r[6]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2627:
{
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[2] ^ sh2->r[6]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2637:
{
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[3] ^ sh2->r[6]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2647:
{
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[4] ^ sh2->r[6]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2657:
{
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[5] ^ sh2->r[6]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2667:
{
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[6] ^ sh2->r[6]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2677:
{
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[7] ^ sh2->r[6]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2687:
{
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[8] ^ sh2->r[6]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2697:
{
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[9] ^ sh2->r[6]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op26A7:
{
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[10] ^ sh2->r[6]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op26B7:
{
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[11] ^ sh2->r[6]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op26C7:
{
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[12] ^ sh2->r[6]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op26D7:
{
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[13] ^ sh2->r[6]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op26E7:
{
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[14] ^ sh2->r[6]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op26F7:
{
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[15] ^ sh2->r[6]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2707:
{
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[0] ^ sh2->r[7]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2717:
{
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[1] ^ sh2->r[7]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2727:
{
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[2] ^ sh2->r[7]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2737:
{
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[3] ^ sh2->r[7]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2747:
{
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[4] ^ sh2->r[7]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2757:
{
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[5] ^ sh2->r[7]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2767:
{
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[6] ^ sh2->r[7]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2777:
{
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[7] ^ sh2->r[7]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2787:
{
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[8] ^ sh2->r[7]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2797:
{
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[9] ^ sh2->r[7]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op27A7:
{
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[10] ^ sh2->r[7]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op27B7:
{
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[11] ^ sh2->r[7]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op27C7:
{
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[12] ^ sh2->r[7]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op27D7:
{
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[13] ^ sh2->r[7]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op27E7:
{
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[14] ^ sh2->r[7]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op27F7:
{
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[15] ^ sh2->r[7]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2807:
{
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[0] ^ sh2->r[8]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2817:
{
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[1] ^ sh2->r[8]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2827:
{
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[2] ^ sh2->r[8]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2837:
{
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[3] ^ sh2->r[8]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2847:
{
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[4] ^ sh2->r[8]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2857:
{
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[5] ^ sh2->r[8]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2867:
{
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[6] ^ sh2->r[8]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2877:
{
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[7] ^ sh2->r[8]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2887:
{
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[8] ^ sh2->r[8]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2897:
{
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[9] ^ sh2->r[8]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op28A7:
{
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[10] ^ sh2->r[8]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op28B7:
{
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[11] ^ sh2->r[8]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op28C7:
{
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[12] ^ sh2->r[8]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op28D7:
{
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[13] ^ sh2->r[8]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op28E7:
{
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[14] ^ sh2->r[8]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op28F7:
{
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[15] ^ sh2->r[8]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2907:
{
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[0] ^ sh2->r[9]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2917:
{
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[1] ^ sh2->r[9]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2927:
{
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[2] ^ sh2->r[9]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2937:
{
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[3] ^ sh2->r[9]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2947:
{
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[4] ^ sh2->r[9]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2957:
{
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[5] ^ sh2->r[9]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2967:
{
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[6] ^ sh2->r[9]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2977:
{
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[7] ^ sh2->r[9]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2987:
{
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[8] ^ sh2->r[9]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2997:
{
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[9] ^ sh2->r[9]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op29A7:
{
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[10] ^ sh2->r[9]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op29B7:
{
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[11] ^ sh2->r[9]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op29C7:
{
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[12] ^ sh2->r[9]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op29D7:
{
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[13] ^ sh2->r[9]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op29E7:
{
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[14] ^ sh2->r[9]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op29F7:
{
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[15] ^ sh2->r[9]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2A07:
{
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[0] ^ sh2->r[10]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2A17:
{
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[1] ^ sh2->r[10]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2A27:
{
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[2] ^ sh2->r[10]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2A37:
{
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[3] ^ sh2->r[10]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2A47:
{
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[4] ^ sh2->r[10]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2A57:
{
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[5] ^ sh2->r[10]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2A67:
{
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[6] ^ sh2->r[10]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2A77:
{
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[7] ^ sh2->r[10]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2A87:
{
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[8] ^ sh2->r[10]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2A97:
{
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[9] ^ sh2->r[10]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2AA7:
{
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[10] ^ sh2->r[10]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2AB7:
{
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[11] ^ sh2->r[10]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2AC7:
{
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[12] ^ sh2->r[10]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2AD7:
{
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[13] ^ sh2->r[10]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2AE7:
{
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[14] ^ sh2->r[10]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2AF7:
{
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[15] ^ sh2->r[10]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2B07:
{
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[0] ^ sh2->r[11]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2B17:
{
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[1] ^ sh2->r[11]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2B27:
{
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[2] ^ sh2->r[11]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2B37:
{
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[3] ^ sh2->r[11]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2B47:
{
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[4] ^ sh2->r[11]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2B57:
{
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[5] ^ sh2->r[11]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2B67:
{
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[6] ^ sh2->r[11]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2B77:
{
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[7] ^ sh2->r[11]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2B87:
{
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[8] ^ sh2->r[11]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2B97:
{
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[9] ^ sh2->r[11]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2BA7:
{
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[10] ^ sh2->r[11]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2BB7:
{
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[11] ^ sh2->r[11]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2BC7:
{
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[12] ^ sh2->r[11]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2BD7:
{
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[13] ^ sh2->r[11]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2BE7:
{
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[14] ^ sh2->r[11]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2BF7:
{
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[15] ^ sh2->r[11]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2C07:
{
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[0] ^ sh2->r[12]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2C17:
{
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[1] ^ sh2->r[12]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2C27:
{
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[2] ^ sh2->r[12]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2C37:
{
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[3] ^ sh2->r[12]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2C47:
{
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[4] ^ sh2->r[12]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2C57:
{
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[5] ^ sh2->r[12]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2C67:
{
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[6] ^ sh2->r[12]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2C77:
{
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[7] ^ sh2->r[12]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2C87:
{
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[8] ^ sh2->r[12]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2C97:
{
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[9] ^ sh2->r[12]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2CA7:
{
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[10] ^ sh2->r[12]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2CB7:
{
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[11] ^ sh2->r[12]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2CC7:
{
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[12] ^ sh2->r[12]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2CD7:
{
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[13] ^ sh2->r[12]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2CE7:
{
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[14] ^ sh2->r[12]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2CF7:
{
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[15] ^ sh2->r[12]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2D07:
{
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[0] ^ sh2->r[13]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2D17:
{
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[1] ^ sh2->r[13]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2D27:
{
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[2] ^ sh2->r[13]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2D37:
{
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[3] ^ sh2->r[13]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2D47:
{
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[4] ^ sh2->r[13]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2D57:
{
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[5] ^ sh2->r[13]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2D67:
{
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[6] ^ sh2->r[13]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2D77:
{
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[7] ^ sh2->r[13]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2D87:
{
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[8] ^ sh2->r[13]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2D97:
{
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[9] ^ sh2->r[13]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2DA7:
{
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[10] ^ sh2->r[13]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2DB7:
{
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[11] ^ sh2->r[13]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2DC7:
{
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[12] ^ sh2->r[13]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2DD7:
{
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[13] ^ sh2->r[13]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2DE7:
{
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[14] ^ sh2->r[13]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2DF7:
{
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[15] ^ sh2->r[13]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2E07:
{
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[0] ^ sh2->r[14]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2E17:
{
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[1] ^ sh2->r[14]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2E27:
{
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[2] ^ sh2->r[14]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2E37:
{
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[3] ^ sh2->r[14]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2E47:
{
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[4] ^ sh2->r[14]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2E57:
{
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[5] ^ sh2->r[14]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2E67:
{
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[6] ^ sh2->r[14]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2E77:
{
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[7] ^ sh2->r[14]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2E87:
{
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[8] ^ sh2->r[14]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2E97:
{
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[9] ^ sh2->r[14]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2EA7:
{
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[10] ^ sh2->r[14]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2EB7:
{
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[11] ^ sh2->r[14]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2EC7:
{
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[12] ^ sh2->r[14]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2ED7:
{
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[13] ^ sh2->r[14]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2EE7:
{
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[14] ^ sh2->r[14]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2EF7:
{
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[15] ^ sh2->r[14]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2F07:
{
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[0] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[0] ^ sh2->r[15]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2F17:
{
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[1] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[1] ^ sh2->r[15]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2F27:
{
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[2] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[2] ^ sh2->r[15]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2F37:
{
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[3] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[3] ^ sh2->r[15]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2F47:
{
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[4] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[4] ^ sh2->r[15]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2F57:
{
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[5] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[5] ^ sh2->r[15]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2F67:
{
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[6] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[6] ^ sh2->r[15]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2F77:
{
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[7] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[7] ^ sh2->r[15]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2F87:
{
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[8] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[8] ^ sh2->r[15]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2F97:
{
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[9] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[9] ^ sh2->r[15]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2FA7:
{
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[10] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[10] ^ sh2->r[15]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2FB7:
{
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[11] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[11] ^ sh2->r[15]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2FC7:
{
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[12] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[12] ^ sh2->r[15]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2FD7:
{
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[13] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[13] ^ sh2->r[15]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2FE7:
{
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[14] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[14] ^ sh2->r[15]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2FF7:
{
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~Q;
	else
		sh2->sr |= Q;
	if ((sh2->r[15] & 0x80000000) == 0)
		sh2->sr &= ~M;
	else
		sh2->sr |= M;
	if ((sh2->r[15] ^ sh2->r[15]) & 0x80000000)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

// TST Rm,Rn
Op2008:
{
	if ((sh2->r[0] & sh2->r[0]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2018:
{
	if ((sh2->r[0] & sh2->r[1]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2028:
{
	if ((sh2->r[0] & sh2->r[2]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2038:
{
	if ((sh2->r[0] & sh2->r[3]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2048:
{
	if ((sh2->r[0] & sh2->r[4]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2058:
{
	if ((sh2->r[0] & sh2->r[5]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2068:
{
	if ((sh2->r[0] & sh2->r[6]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2078:
{
	if ((sh2->r[0] & sh2->r[7]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2088:
{
	if ((sh2->r[0] & sh2->r[8]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2098:
{
	if ((sh2->r[0] & sh2->r[9]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op20A8:
{
	if ((sh2->r[0] & sh2->r[10]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op20B8:
{
	if ((sh2->r[0] & sh2->r[11]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op20C8:
{
	if ((sh2->r[0] & sh2->r[12]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op20D8:
{
	if ((sh2->r[0] & sh2->r[13]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op20E8:
{
	if ((sh2->r[0] & sh2->r[14]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op20F8:
{
	if ((sh2->r[0] & sh2->r[15]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2108:
{
	if ((sh2->r[1] & sh2->r[0]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2118:
{
	if ((sh2->r[1] & sh2->r[1]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2128:
{
	if ((sh2->r[1] & sh2->r[2]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2138:
{
	if ((sh2->r[1] & sh2->r[3]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2148:
{
	if ((sh2->r[1] & sh2->r[4]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2158:
{
	if ((sh2->r[1] & sh2->r[5]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2168:
{
	if ((sh2->r[1] & sh2->r[6]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2178:
{
	if ((sh2->r[1] & sh2->r[7]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2188:
{
	if ((sh2->r[1] & sh2->r[8]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2198:
{
	if ((sh2->r[1] & sh2->r[9]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op21A8:
{
	if ((sh2->r[1] & sh2->r[10]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op21B8:
{
	if ((sh2->r[1] & sh2->r[11]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op21C8:
{
	if ((sh2->r[1] & sh2->r[12]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op21D8:
{
	if ((sh2->r[1] & sh2->r[13]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op21E8:
{
	if ((sh2->r[1] & sh2->r[14]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op21F8:
{
	if ((sh2->r[1] & sh2->r[15]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2208:
{
	if ((sh2->r[2] & sh2->r[0]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2218:
{
	if ((sh2->r[2] & sh2->r[1]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2228:
{
	if ((sh2->r[2] & sh2->r[2]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2238:
{
	if ((sh2->r[2] & sh2->r[3]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2248:
{
	if ((sh2->r[2] & sh2->r[4]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2258:
{
	if ((sh2->r[2] & sh2->r[5]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2268:
{
	if ((sh2->r[2] & sh2->r[6]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2278:
{
	if ((sh2->r[2] & sh2->r[7]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2288:
{
	if ((sh2->r[2] & sh2->r[8]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2298:
{
	if ((sh2->r[2] & sh2->r[9]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op22A8:
{
	if ((sh2->r[2] & sh2->r[10]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op22B8:
{
	if ((sh2->r[2] & sh2->r[11]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op22C8:
{
	if ((sh2->r[2] & sh2->r[12]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op22D8:
{
	if ((sh2->r[2] & sh2->r[13]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op22E8:
{
	if ((sh2->r[2] & sh2->r[14]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op22F8:
{
	if ((sh2->r[2] & sh2->r[15]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2308:
{
	if ((sh2->r[3] & sh2->r[0]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2318:
{
	if ((sh2->r[3] & sh2->r[1]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2328:
{
	if ((sh2->r[3] & sh2->r[2]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2338:
{
	if ((sh2->r[3] & sh2->r[3]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2348:
{
	if ((sh2->r[3] & sh2->r[4]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2358:
{
	if ((sh2->r[3] & sh2->r[5]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2368:
{
	if ((sh2->r[3] & sh2->r[6]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2378:
{
	if ((sh2->r[3] & sh2->r[7]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2388:
{
	if ((sh2->r[3] & sh2->r[8]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2398:
{
	if ((sh2->r[3] & sh2->r[9]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op23A8:
{
	if ((sh2->r[3] & sh2->r[10]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op23B8:
{
	if ((sh2->r[3] & sh2->r[11]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op23C8:
{
	if ((sh2->r[3] & sh2->r[12]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op23D8:
{
	if ((sh2->r[3] & sh2->r[13]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op23E8:
{
	if ((sh2->r[3] & sh2->r[14]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op23F8:
{
	if ((sh2->r[3] & sh2->r[15]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2408:
{
	if ((sh2->r[4] & sh2->r[0]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2418:
{
	if ((sh2->r[4] & sh2->r[1]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2428:
{
	if ((sh2->r[4] & sh2->r[2]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2438:
{
	if ((sh2->r[4] & sh2->r[3]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2448:
{
	if ((sh2->r[4] & sh2->r[4]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2458:
{
	if ((sh2->r[4] & sh2->r[5]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2468:
{
	if ((sh2->r[4] & sh2->r[6]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2478:
{
	if ((sh2->r[4] & sh2->r[7]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2488:
{
	if ((sh2->r[4] & sh2->r[8]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2498:
{
	if ((sh2->r[4] & sh2->r[9]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op24A8:
{
	if ((sh2->r[4] & sh2->r[10]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op24B8:
{
	if ((sh2->r[4] & sh2->r[11]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op24C8:
{
	if ((sh2->r[4] & sh2->r[12]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op24D8:
{
	if ((sh2->r[4] & sh2->r[13]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op24E8:
{
	if ((sh2->r[4] & sh2->r[14]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op24F8:
{
	if ((sh2->r[4] & sh2->r[15]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2508:
{
	if ((sh2->r[5] & sh2->r[0]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2518:
{
	if ((sh2->r[5] & sh2->r[1]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2528:
{
	if ((sh2->r[5] & sh2->r[2]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2538:
{
	if ((sh2->r[5] & sh2->r[3]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2548:
{
	if ((sh2->r[5] & sh2->r[4]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2558:
{
	if ((sh2->r[5] & sh2->r[5]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2568:
{
	if ((sh2->r[5] & sh2->r[6]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2578:
{
	if ((sh2->r[5] & sh2->r[7]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2588:
{
	if ((sh2->r[5] & sh2->r[8]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2598:
{
	if ((sh2->r[5] & sh2->r[9]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op25A8:
{
	if ((sh2->r[5] & sh2->r[10]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op25B8:
{
	if ((sh2->r[5] & sh2->r[11]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op25C8:
{
	if ((sh2->r[5] & sh2->r[12]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op25D8:
{
	if ((sh2->r[5] & sh2->r[13]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op25E8:
{
	if ((sh2->r[5] & sh2->r[14]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op25F8:
{
	if ((sh2->r[5] & sh2->r[15]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2608:
{
	if ((sh2->r[6] & sh2->r[0]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2618:
{
	if ((sh2->r[6] & sh2->r[1]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2628:
{
	if ((sh2->r[6] & sh2->r[2]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2638:
{
	if ((sh2->r[6] & sh2->r[3]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2648:
{
	if ((sh2->r[6] & sh2->r[4]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2658:
{
	if ((sh2->r[6] & sh2->r[5]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2668:
{
	if ((sh2->r[6] & sh2->r[6]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2678:
{
	if ((sh2->r[6] & sh2->r[7]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2688:
{
	if ((sh2->r[6] & sh2->r[8]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2698:
{
	if ((sh2->r[6] & sh2->r[9]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op26A8:
{
	if ((sh2->r[6] & sh2->r[10]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op26B8:
{
	if ((sh2->r[6] & sh2->r[11]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op26C8:
{
	if ((sh2->r[6] & sh2->r[12]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op26D8:
{
	if ((sh2->r[6] & sh2->r[13]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op26E8:
{
	if ((sh2->r[6] & sh2->r[14]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op26F8:
{
	if ((sh2->r[6] & sh2->r[15]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2708:
{
	if ((sh2->r[7] & sh2->r[0]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2718:
{
	if ((sh2->r[7] & sh2->r[1]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2728:
{
	if ((sh2->r[7] & sh2->r[2]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2738:
{
	if ((sh2->r[7] & sh2->r[3]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2748:
{
	if ((sh2->r[7] & sh2->r[4]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2758:
{
	if ((sh2->r[7] & sh2->r[5]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2768:
{
	if ((sh2->r[7] & sh2->r[6]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2778:
{
	if ((sh2->r[7] & sh2->r[7]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2788:
{
	if ((sh2->r[7] & sh2->r[8]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2798:
{
	if ((sh2->r[7] & sh2->r[9]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op27A8:
{
	if ((sh2->r[7] & sh2->r[10]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op27B8:
{
	if ((sh2->r[7] & sh2->r[11]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op27C8:
{
	if ((sh2->r[7] & sh2->r[12]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op27D8:
{
	if ((sh2->r[7] & sh2->r[13]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op27E8:
{
	if ((sh2->r[7] & sh2->r[14]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op27F8:
{
	if ((sh2->r[7] & sh2->r[15]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2808:
{
	if ((sh2->r[8] & sh2->r[0]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2818:
{
	if ((sh2->r[8] & sh2->r[1]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2828:
{
	if ((sh2->r[8] & sh2->r[2]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2838:
{
	if ((sh2->r[8] & sh2->r[3]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2848:
{
	if ((sh2->r[8] & sh2->r[4]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2858:
{
	if ((sh2->r[8] & sh2->r[5]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2868:
{
	if ((sh2->r[8] & sh2->r[6]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2878:
{
	if ((sh2->r[8] & sh2->r[7]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2888:
{
	if ((sh2->r[8] & sh2->r[8]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2898:
{
	if ((sh2->r[8] & sh2->r[9]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op28A8:
{
	if ((sh2->r[8] & sh2->r[10]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op28B8:
{
	if ((sh2->r[8] & sh2->r[11]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op28C8:
{
	if ((sh2->r[8] & sh2->r[12]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op28D8:
{
	if ((sh2->r[8] & sh2->r[13]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op28E8:
{
	if ((sh2->r[8] & sh2->r[14]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op28F8:
{
	if ((sh2->r[8] & sh2->r[15]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2908:
{
	if ((sh2->r[9] & sh2->r[0]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2918:
{
	if ((sh2->r[9] & sh2->r[1]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2928:
{
	if ((sh2->r[9] & sh2->r[2]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2938:
{
	if ((sh2->r[9] & sh2->r[3]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2948:
{
	if ((sh2->r[9] & sh2->r[4]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2958:
{
	if ((sh2->r[9] & sh2->r[5]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2968:
{
	if ((sh2->r[9] & sh2->r[6]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2978:
{
	if ((sh2->r[9] & sh2->r[7]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2988:
{
	if ((sh2->r[9] & sh2->r[8]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2998:
{
	if ((sh2->r[9] & sh2->r[9]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op29A8:
{
	if ((sh2->r[9] & sh2->r[10]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op29B8:
{
	if ((sh2->r[9] & sh2->r[11]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op29C8:
{
	if ((sh2->r[9] & sh2->r[12]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op29D8:
{
	if ((sh2->r[9] & sh2->r[13]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op29E8:
{
	if ((sh2->r[9] & sh2->r[14]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op29F8:
{
	if ((sh2->r[9] & sh2->r[15]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2A08:
{
	if ((sh2->r[10] & sh2->r[0]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2A18:
{
	if ((sh2->r[10] & sh2->r[1]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2A28:
{
	if ((sh2->r[10] & sh2->r[2]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2A38:
{
	if ((sh2->r[10] & sh2->r[3]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2A48:
{
	if ((sh2->r[10] & sh2->r[4]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2A58:
{
	if ((sh2->r[10] & sh2->r[5]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2A68:
{
	if ((sh2->r[10] & sh2->r[6]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2A78:
{
	if ((sh2->r[10] & sh2->r[7]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2A88:
{
	if ((sh2->r[10] & sh2->r[8]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2A98:
{
	if ((sh2->r[10] & sh2->r[9]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2AA8:
{
	if ((sh2->r[10] & sh2->r[10]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2AB8:
{
	if ((sh2->r[10] & sh2->r[11]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2AC8:
{
	if ((sh2->r[10] & sh2->r[12]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2AD8:
{
	if ((sh2->r[10] & sh2->r[13]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2AE8:
{
	if ((sh2->r[10] & sh2->r[14]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2AF8:
{
	if ((sh2->r[10] & sh2->r[15]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2B08:
{
	if ((sh2->r[11] & sh2->r[0]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2B18:
{
	if ((sh2->r[11] & sh2->r[1]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2B28:
{
	if ((sh2->r[11] & sh2->r[2]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2B38:
{
	if ((sh2->r[11] & sh2->r[3]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2B48:
{
	if ((sh2->r[11] & sh2->r[4]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2B58:
{
	if ((sh2->r[11] & sh2->r[5]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2B68:
{
	if ((sh2->r[11] & sh2->r[6]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2B78:
{
	if ((sh2->r[11] & sh2->r[7]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2B88:
{
	if ((sh2->r[11] & sh2->r[8]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2B98:
{
	if ((sh2->r[11] & sh2->r[9]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2BA8:
{
	if ((sh2->r[11] & sh2->r[10]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2BB8:
{
	if ((sh2->r[11] & sh2->r[11]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2BC8:
{
	if ((sh2->r[11] & sh2->r[12]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2BD8:
{
	if ((sh2->r[11] & sh2->r[13]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2BE8:
{
	if ((sh2->r[11] & sh2->r[14]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2BF8:
{
	if ((sh2->r[11] & sh2->r[15]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2C08:
{
	if ((sh2->r[12] & sh2->r[0]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2C18:
{
	if ((sh2->r[12] & sh2->r[1]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2C28:
{
	if ((sh2->r[12] & sh2->r[2]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2C38:
{
	if ((sh2->r[12] & sh2->r[3]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2C48:
{
	if ((sh2->r[12] & sh2->r[4]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2C58:
{
	if ((sh2->r[12] & sh2->r[5]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2C68:
{
	if ((sh2->r[12] & sh2->r[6]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2C78:
{
	if ((sh2->r[12] & sh2->r[7]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2C88:
{
	if ((sh2->r[12] & sh2->r[8]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2C98:
{
	if ((sh2->r[12] & sh2->r[9]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2CA8:
{
	if ((sh2->r[12] & sh2->r[10]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2CB8:
{
	if ((sh2->r[12] & sh2->r[11]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2CC8:
{
	if ((sh2->r[12] & sh2->r[12]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2CD8:
{
	if ((sh2->r[12] & sh2->r[13]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2CE8:
{
	if ((sh2->r[12] & sh2->r[14]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2CF8:
{
	if ((sh2->r[12] & sh2->r[15]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2D08:
{
	if ((sh2->r[13] & sh2->r[0]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2D18:
{
	if ((sh2->r[13] & sh2->r[1]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2D28:
{
	if ((sh2->r[13] & sh2->r[2]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2D38:
{
	if ((sh2->r[13] & sh2->r[3]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2D48:
{
	if ((sh2->r[13] & sh2->r[4]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2D58:
{
	if ((sh2->r[13] & sh2->r[5]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2D68:
{
	if ((sh2->r[13] & sh2->r[6]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2D78:
{
	if ((sh2->r[13] & sh2->r[7]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2D88:
{
	if ((sh2->r[13] & sh2->r[8]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2D98:
{
	if ((sh2->r[13] & sh2->r[9]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2DA8:
{
	if ((sh2->r[13] & sh2->r[10]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2DB8:
{
	if ((sh2->r[13] & sh2->r[11]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2DC8:
{
	if ((sh2->r[13] & sh2->r[12]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2DD8:
{
	if ((sh2->r[13] & sh2->r[13]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2DE8:
{
	if ((sh2->r[13] & sh2->r[14]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2DF8:
{
	if ((sh2->r[13] & sh2->r[15]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2E08:
{
	if ((sh2->r[14] & sh2->r[0]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2E18:
{
	if ((sh2->r[14] & sh2->r[1]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2E28:
{
	if ((sh2->r[14] & sh2->r[2]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2E38:
{
	if ((sh2->r[14] & sh2->r[3]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2E48:
{
	if ((sh2->r[14] & sh2->r[4]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2E58:
{
	if ((sh2->r[14] & sh2->r[5]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2E68:
{
	if ((sh2->r[14] & sh2->r[6]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2E78:
{
	if ((sh2->r[14] & sh2->r[7]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2E88:
{
	if ((sh2->r[14] & sh2->r[8]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2E98:
{
	if ((sh2->r[14] & sh2->r[9]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2EA8:
{
	if ((sh2->r[14] & sh2->r[10]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2EB8:
{
	if ((sh2->r[14] & sh2->r[11]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2EC8:
{
	if ((sh2->r[14] & sh2->r[12]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2ED8:
{
	if ((sh2->r[14] & sh2->r[13]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2EE8:
{
	if ((sh2->r[14] & sh2->r[14]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2EF8:
{
	if ((sh2->r[14] & sh2->r[15]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2F08:
{
	if ((sh2->r[15] & sh2->r[0]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2F18:
{
	if ((sh2->r[15] & sh2->r[1]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2F28:
{
	if ((sh2->r[15] & sh2->r[2]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2F38:
{
	if ((sh2->r[15] & sh2->r[3]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2F48:
{
	if ((sh2->r[15] & sh2->r[4]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2F58:
{
	if ((sh2->r[15] & sh2->r[5]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2F68:
{
	if ((sh2->r[15] & sh2->r[6]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2F78:
{
	if ((sh2->r[15] & sh2->r[7]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2F88:
{
	if ((sh2->r[15] & sh2->r[8]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2F98:
{
	if ((sh2->r[15] & sh2->r[9]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2FA8:
{
	if ((sh2->r[15] & sh2->r[10]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2FB8:
{
	if ((sh2->r[15] & sh2->r[11]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2FC8:
{
	if ((sh2->r[15] & sh2->r[12]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2FD8:
{
	if ((sh2->r[15] & sh2->r[13]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2FE8:
{
	if ((sh2->r[15] & sh2->r[14]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op2FF8:
{
	if ((sh2->r[15] & sh2->r[15]) == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

// AND Rm,Rn
Op2009:
{
	sh2->r[0] &= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2019:
{
	sh2->r[0] &= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2029:
{
	sh2->r[0] &= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2039:
{
	sh2->r[0] &= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2049:
{
	sh2->r[0] &= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2059:
{
	sh2->r[0] &= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2069:
{
	sh2->r[0] &= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2079:
{
	sh2->r[0] &= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2089:
{
	sh2->r[0] &= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2099:
{
	sh2->r[0] &= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op20A9:
{
	sh2->r[0] &= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op20B9:
{
	sh2->r[0] &= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op20C9:
{
	sh2->r[0] &= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op20D9:
{
	sh2->r[0] &= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op20E9:
{
	sh2->r[0] &= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op20F9:
{
	sh2->r[0] &= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2109:
{
	sh2->r[1] &= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2119:
{
	sh2->r[1] &= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2129:
{
	sh2->r[1] &= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2139:
{
	sh2->r[1] &= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2149:
{
	sh2->r[1] &= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2159:
{
	sh2->r[1] &= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2169:
{
	sh2->r[1] &= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2179:
{
	sh2->r[1] &= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2189:
{
	sh2->r[1] &= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2199:
{
	sh2->r[1] &= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op21A9:
{
	sh2->r[1] &= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op21B9:
{
	sh2->r[1] &= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op21C9:
{
	sh2->r[1] &= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op21D9:
{
	sh2->r[1] &= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op21E9:
{
	sh2->r[1] &= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op21F9:
{
	sh2->r[1] &= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2209:
{
	sh2->r[2] &= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2219:
{
	sh2->r[2] &= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2229:
{
	sh2->r[2] &= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2239:
{
	sh2->r[2] &= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2249:
{
	sh2->r[2] &= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2259:
{
	sh2->r[2] &= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2269:
{
	sh2->r[2] &= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2279:
{
	sh2->r[2] &= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2289:
{
	sh2->r[2] &= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2299:
{
	sh2->r[2] &= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op22A9:
{
	sh2->r[2] &= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op22B9:
{
	sh2->r[2] &= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op22C9:
{
	sh2->r[2] &= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op22D9:
{
	sh2->r[2] &= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op22E9:
{
	sh2->r[2] &= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op22F9:
{
	sh2->r[2] &= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2309:
{
	sh2->r[3] &= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2319:
{
	sh2->r[3] &= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2329:
{
	sh2->r[3] &= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2339:
{
	sh2->r[3] &= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2349:
{
	sh2->r[3] &= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2359:
{
	sh2->r[3] &= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2369:
{
	sh2->r[3] &= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2379:
{
	sh2->r[3] &= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2389:
{
	sh2->r[3] &= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2399:
{
	sh2->r[3] &= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op23A9:
{
	sh2->r[3] &= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op23B9:
{
	sh2->r[3] &= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op23C9:
{
	sh2->r[3] &= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op23D9:
{
	sh2->r[3] &= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op23E9:
{
	sh2->r[3] &= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op23F9:
{
	sh2->r[3] &= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2409:
{
	sh2->r[4] &= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2419:
{
	sh2->r[4] &= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2429:
{
	sh2->r[4] &= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2439:
{
	sh2->r[4] &= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2449:
{
	sh2->r[4] &= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2459:
{
	sh2->r[4] &= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2469:
{
	sh2->r[4] &= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2479:
{
	sh2->r[4] &= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2489:
{
	sh2->r[4] &= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2499:
{
	sh2->r[4] &= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op24A9:
{
	sh2->r[4] &= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op24B9:
{
	sh2->r[4] &= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op24C9:
{
	sh2->r[4] &= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op24D9:
{
	sh2->r[4] &= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op24E9:
{
	sh2->r[4] &= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op24F9:
{
	sh2->r[4] &= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2509:
{
	sh2->r[5] &= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2519:
{
	sh2->r[5] &= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2529:
{
	sh2->r[5] &= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2539:
{
	sh2->r[5] &= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2549:
{
	sh2->r[5] &= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2559:
{
	sh2->r[5] &= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2569:
{
	sh2->r[5] &= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2579:
{
	sh2->r[5] &= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2589:
{
	sh2->r[5] &= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2599:
{
	sh2->r[5] &= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op25A9:
{
	sh2->r[5] &= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op25B9:
{
	sh2->r[5] &= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op25C9:
{
	sh2->r[5] &= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op25D9:
{
	sh2->r[5] &= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op25E9:
{
	sh2->r[5] &= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op25F9:
{
	sh2->r[5] &= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2609:
{
	sh2->r[6] &= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2619:
{
	sh2->r[6] &= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2629:
{
	sh2->r[6] &= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2639:
{
	sh2->r[6] &= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2649:
{
	sh2->r[6] &= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2659:
{
	sh2->r[6] &= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2669:
{
	sh2->r[6] &= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2679:
{
	sh2->r[6] &= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2689:
{
	sh2->r[6] &= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2699:
{
	sh2->r[6] &= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op26A9:
{
	sh2->r[6] &= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op26B9:
{
	sh2->r[6] &= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op26C9:
{
	sh2->r[6] &= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op26D9:
{
	sh2->r[6] &= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op26E9:
{
	sh2->r[6] &= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op26F9:
{
	sh2->r[6] &= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2709:
{
	sh2->r[7] &= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2719:
{
	sh2->r[7] &= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2729:
{
	sh2->r[7] &= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2739:
{
	sh2->r[7] &= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2749:
{
	sh2->r[7] &= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2759:
{
	sh2->r[7] &= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2769:
{
	sh2->r[7] &= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2779:
{
	sh2->r[7] &= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2789:
{
	sh2->r[7] &= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2799:
{
	sh2->r[7] &= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op27A9:
{
	sh2->r[7] &= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op27B9:
{
	sh2->r[7] &= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op27C9:
{
	sh2->r[7] &= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op27D9:
{
	sh2->r[7] &= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op27E9:
{
	sh2->r[7] &= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op27F9:
{
	sh2->r[7] &= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2809:
{
	sh2->r[8] &= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2819:
{
	sh2->r[8] &= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2829:
{
	sh2->r[8] &= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2839:
{
	sh2->r[8] &= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2849:
{
	sh2->r[8] &= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2859:
{
	sh2->r[8] &= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2869:
{
	sh2->r[8] &= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2879:
{
	sh2->r[8] &= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2889:
{
	sh2->r[8] &= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2899:
{
	sh2->r[8] &= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op28A9:
{
	sh2->r[8] &= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op28B9:
{
	sh2->r[8] &= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op28C9:
{
	sh2->r[8] &= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op28D9:
{
	sh2->r[8] &= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op28E9:
{
	sh2->r[8] &= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op28F9:
{
	sh2->r[8] &= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2909:
{
	sh2->r[9] &= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2919:
{
	sh2->r[9] &= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2929:
{
	sh2->r[9] &= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2939:
{
	sh2->r[9] &= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2949:
{
	sh2->r[9] &= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2959:
{
	sh2->r[9] &= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2969:
{
	sh2->r[9] &= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2979:
{
	sh2->r[9] &= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2989:
{
	sh2->r[9] &= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2999:
{
	sh2->r[9] &= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op29A9:
{
	sh2->r[9] &= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op29B9:
{
	sh2->r[9] &= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op29C9:
{
	sh2->r[9] &= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op29D9:
{
	sh2->r[9] &= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op29E9:
{
	sh2->r[9] &= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op29F9:
{
	sh2->r[9] &= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2A09:
{
	sh2->r[10] &= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2A19:
{
	sh2->r[10] &= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2A29:
{
	sh2->r[10] &= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2A39:
{
	sh2->r[10] &= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2A49:
{
	sh2->r[10] &= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2A59:
{
	sh2->r[10] &= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2A69:
{
	sh2->r[10] &= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2A79:
{
	sh2->r[10] &= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2A89:
{
	sh2->r[10] &= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2A99:
{
	sh2->r[10] &= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2AA9:
{
	sh2->r[10] &= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2AB9:
{
	sh2->r[10] &= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2AC9:
{
	sh2->r[10] &= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2AD9:
{
	sh2->r[10] &= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2AE9:
{
	sh2->r[10] &= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2AF9:
{
	sh2->r[10] &= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2B09:
{
	sh2->r[11] &= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2B19:
{
	sh2->r[11] &= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2B29:
{
	sh2->r[11] &= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2B39:
{
	sh2->r[11] &= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2B49:
{
	sh2->r[11] &= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2B59:
{
	sh2->r[11] &= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2B69:
{
	sh2->r[11] &= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2B79:
{
	sh2->r[11] &= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2B89:
{
	sh2->r[11] &= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2B99:
{
	sh2->r[11] &= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2BA9:
{
	sh2->r[11] &= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2BB9:
{
	sh2->r[11] &= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2BC9:
{
	sh2->r[11] &= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2BD9:
{
	sh2->r[11] &= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2BE9:
{
	sh2->r[11] &= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2BF9:
{
	sh2->r[11] &= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2C09:
{
	sh2->r[12] &= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2C19:
{
	sh2->r[12] &= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2C29:
{
	sh2->r[12] &= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2C39:
{
	sh2->r[12] &= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2C49:
{
	sh2->r[12] &= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2C59:
{
	sh2->r[12] &= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2C69:
{
	sh2->r[12] &= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2C79:
{
	sh2->r[12] &= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2C89:
{
	sh2->r[12] &= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2C99:
{
	sh2->r[12] &= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2CA9:
{
	sh2->r[12] &= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2CB9:
{
	sh2->r[12] &= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2CC9:
{
	sh2->r[12] &= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2CD9:
{
	sh2->r[12] &= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2CE9:
{
	sh2->r[12] &= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2CF9:
{
	sh2->r[12] &= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2D09:
{
	sh2->r[13] &= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2D19:
{
	sh2->r[13] &= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2D29:
{
	sh2->r[13] &= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2D39:
{
	sh2->r[13] &= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2D49:
{
	sh2->r[13] &= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2D59:
{
	sh2->r[13] &= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2D69:
{
	sh2->r[13] &= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2D79:
{
	sh2->r[13] &= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2D89:
{
	sh2->r[13] &= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2D99:
{
	sh2->r[13] &= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2DA9:
{
	sh2->r[13] &= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2DB9:
{
	sh2->r[13] &= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2DC9:
{
	sh2->r[13] &= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2DD9:
{
	sh2->r[13] &= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2DE9:
{
	sh2->r[13] &= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2DF9:
{
	sh2->r[13] &= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2E09:
{
	sh2->r[14] &= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2E19:
{
	sh2->r[14] &= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2E29:
{
	sh2->r[14] &= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2E39:
{
	sh2->r[14] &= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2E49:
{
	sh2->r[14] &= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2E59:
{
	sh2->r[14] &= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2E69:
{
	sh2->r[14] &= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2E79:
{
	sh2->r[14] &= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2E89:
{
	sh2->r[14] &= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2E99:
{
	sh2->r[14] &= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2EA9:
{
	sh2->r[14] &= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2EB9:
{
	sh2->r[14] &= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2EC9:
{
	sh2->r[14] &= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2ED9:
{
	sh2->r[14] &= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2EE9:
{
	sh2->r[14] &= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2EF9:
{
	sh2->r[14] &= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2F09:
{
	sh2->r[15] &= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2F19:
{
	sh2->r[15] &= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2F29:
{
	sh2->r[15] &= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2F39:
{
	sh2->r[15] &= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2F49:
{
	sh2->r[15] &= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2F59:
{
	sh2->r[15] &= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2F69:
{
	sh2->r[15] &= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2F79:
{
	sh2->r[15] &= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2F89:
{
	sh2->r[15] &= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2F99:
{
	sh2->r[15] &= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2FA9:
{
	sh2->r[15] &= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2FB9:
{
	sh2->r[15] &= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2FC9:
{
	sh2->r[15] &= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2FD9:
{
	sh2->r[15] &= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2FE9:
{
	sh2->r[15] &= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2FF9:
{
	sh2->r[15] &= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

// XOR Rm,Rn
Op200A:
{
	sh2->r[0] ^= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op201A:
{
	sh2->r[0] ^= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op202A:
{
	sh2->r[0] ^= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op203A:
{
	sh2->r[0] ^= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op204A:
{
	sh2->r[0] ^= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op205A:
{
	sh2->r[0] ^= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op206A:
{
	sh2->r[0] ^= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op207A:
{
	sh2->r[0] ^= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op208A:
{
	sh2->r[0] ^= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op209A:
{
	sh2->r[0] ^= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op20AA:
{
	sh2->r[0] ^= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op20BA:
{
	sh2->r[0] ^= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op20CA:
{
	sh2->r[0] ^= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op20DA:
{
	sh2->r[0] ^= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op20EA:
{
	sh2->r[0] ^= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op20FA:
{
	sh2->r[0] ^= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op210A:
{
	sh2->r[1] ^= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op211A:
{
	sh2->r[1] ^= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op212A:
{
	sh2->r[1] ^= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op213A:
{
	sh2->r[1] ^= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op214A:
{
	sh2->r[1] ^= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op215A:
{
	sh2->r[1] ^= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op216A:
{
	sh2->r[1] ^= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op217A:
{
	sh2->r[1] ^= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op218A:
{
	sh2->r[1] ^= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op219A:
{
	sh2->r[1] ^= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op21AA:
{
	sh2->r[1] ^= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op21BA:
{
	sh2->r[1] ^= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op21CA:
{
	sh2->r[1] ^= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op21DA:
{
	sh2->r[1] ^= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op21EA:
{
	sh2->r[1] ^= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op21FA:
{
	sh2->r[1] ^= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op220A:
{
	sh2->r[2] ^= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op221A:
{
	sh2->r[2] ^= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op222A:
{
	sh2->r[2] ^= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op223A:
{
	sh2->r[2] ^= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op224A:
{
	sh2->r[2] ^= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op225A:
{
	sh2->r[2] ^= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op226A:
{
	sh2->r[2] ^= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op227A:
{
	sh2->r[2] ^= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op228A:
{
	sh2->r[2] ^= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op229A:
{
	sh2->r[2] ^= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op22AA:
{
	sh2->r[2] ^= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op22BA:
{
	sh2->r[2] ^= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op22CA:
{
	sh2->r[2] ^= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op22DA:
{
	sh2->r[2] ^= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op22EA:
{
	sh2->r[2] ^= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op22FA:
{
	sh2->r[2] ^= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op230A:
{
	sh2->r[3] ^= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op231A:
{
	sh2->r[3] ^= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op232A:
{
	sh2->r[3] ^= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op233A:
{
	sh2->r[3] ^= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op234A:
{
	sh2->r[3] ^= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op235A:
{
	sh2->r[3] ^= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op236A:
{
	sh2->r[3] ^= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op237A:
{
	sh2->r[3] ^= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op238A:
{
	sh2->r[3] ^= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op239A:
{
	sh2->r[3] ^= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op23AA:
{
	sh2->r[3] ^= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op23BA:
{
	sh2->r[3] ^= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op23CA:
{
	sh2->r[3] ^= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op23DA:
{
	sh2->r[3] ^= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op23EA:
{
	sh2->r[3] ^= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op23FA:
{
	sh2->r[3] ^= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op240A:
{
	sh2->r[4] ^= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op241A:
{
	sh2->r[4] ^= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op242A:
{
	sh2->r[4] ^= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op243A:
{
	sh2->r[4] ^= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op244A:
{
	sh2->r[4] ^= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op245A:
{
	sh2->r[4] ^= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op246A:
{
	sh2->r[4] ^= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op247A:
{
	sh2->r[4] ^= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op248A:
{
	sh2->r[4] ^= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op249A:
{
	sh2->r[4] ^= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op24AA:
{
	sh2->r[4] ^= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op24BA:
{
	sh2->r[4] ^= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op24CA:
{
	sh2->r[4] ^= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op24DA:
{
	sh2->r[4] ^= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op24EA:
{
	sh2->r[4] ^= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op24FA:
{
	sh2->r[4] ^= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op250A:
{
	sh2->r[5] ^= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op251A:
{
	sh2->r[5] ^= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op252A:
{
	sh2->r[5] ^= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op253A:
{
	sh2->r[5] ^= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op254A:
{
	sh2->r[5] ^= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op255A:
{
	sh2->r[5] ^= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op256A:
{
	sh2->r[5] ^= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op257A:
{
	sh2->r[5] ^= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op258A:
{
	sh2->r[5] ^= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op259A:
{
	sh2->r[5] ^= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op25AA:
{
	sh2->r[5] ^= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op25BA:
{
	sh2->r[5] ^= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op25CA:
{
	sh2->r[5] ^= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op25DA:
{
	sh2->r[5] ^= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op25EA:
{
	sh2->r[5] ^= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op25FA:
{
	sh2->r[5] ^= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op260A:
{
	sh2->r[6] ^= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op261A:
{
	sh2->r[6] ^= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op262A:
{
	sh2->r[6] ^= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op263A:
{
	sh2->r[6] ^= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op264A:
{
	sh2->r[6] ^= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op265A:
{
	sh2->r[6] ^= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op266A:
{
	sh2->r[6] ^= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op267A:
{
	sh2->r[6] ^= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op268A:
{
	sh2->r[6] ^= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op269A:
{
	sh2->r[6] ^= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op26AA:
{
	sh2->r[6] ^= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op26BA:
{
	sh2->r[6] ^= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op26CA:
{
	sh2->r[6] ^= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op26DA:
{
	sh2->r[6] ^= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op26EA:
{
	sh2->r[6] ^= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op26FA:
{
	sh2->r[6] ^= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op270A:
{
	sh2->r[7] ^= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op271A:
{
	sh2->r[7] ^= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op272A:
{
	sh2->r[7] ^= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op273A:
{
	sh2->r[7] ^= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op274A:
{
	sh2->r[7] ^= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op275A:
{
	sh2->r[7] ^= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op276A:
{
	sh2->r[7] ^= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op277A:
{
	sh2->r[7] ^= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op278A:
{
	sh2->r[7] ^= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op279A:
{
	sh2->r[7] ^= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op27AA:
{
	sh2->r[7] ^= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op27BA:
{
	sh2->r[7] ^= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op27CA:
{
	sh2->r[7] ^= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op27DA:
{
	sh2->r[7] ^= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op27EA:
{
	sh2->r[7] ^= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op27FA:
{
	sh2->r[7] ^= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op280A:
{
	sh2->r[8] ^= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op281A:
{
	sh2->r[8] ^= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op282A:
{
	sh2->r[8] ^= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op283A:
{
	sh2->r[8] ^= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op284A:
{
	sh2->r[8] ^= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op285A:
{
	sh2->r[8] ^= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op286A:
{
	sh2->r[8] ^= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op287A:
{
	sh2->r[8] ^= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op288A:
{
	sh2->r[8] ^= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op289A:
{
	sh2->r[8] ^= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op28AA:
{
	sh2->r[8] ^= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op28BA:
{
	sh2->r[8] ^= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op28CA:
{
	sh2->r[8] ^= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op28DA:
{
	sh2->r[8] ^= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op28EA:
{
	sh2->r[8] ^= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op28FA:
{
	sh2->r[8] ^= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op290A:
{
	sh2->r[9] ^= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op291A:
{
	sh2->r[9] ^= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op292A:
{
	sh2->r[9] ^= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op293A:
{
	sh2->r[9] ^= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op294A:
{
	sh2->r[9] ^= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op295A:
{
	sh2->r[9] ^= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op296A:
{
	sh2->r[9] ^= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op297A:
{
	sh2->r[9] ^= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op298A:
{
	sh2->r[9] ^= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op299A:
{
	sh2->r[9] ^= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op29AA:
{
	sh2->r[9] ^= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op29BA:
{
	sh2->r[9] ^= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op29CA:
{
	sh2->r[9] ^= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op29DA:
{
	sh2->r[9] ^= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op29EA:
{
	sh2->r[9] ^= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op29FA:
{
	sh2->r[9] ^= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2A0A:
{
	sh2->r[10] ^= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2A1A:
{
	sh2->r[10] ^= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2A2A:
{
	sh2->r[10] ^= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2A3A:
{
	sh2->r[10] ^= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2A4A:
{
	sh2->r[10] ^= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2A5A:
{
	sh2->r[10] ^= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2A6A:
{
	sh2->r[10] ^= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2A7A:
{
	sh2->r[10] ^= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2A8A:
{
	sh2->r[10] ^= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2A9A:
{
	sh2->r[10] ^= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2AAA:
{
	sh2->r[10] ^= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2ABA:
{
	sh2->r[10] ^= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2ACA:
{
	sh2->r[10] ^= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2ADA:
{
	sh2->r[10] ^= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2AEA:
{
	sh2->r[10] ^= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2AFA:
{
	sh2->r[10] ^= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2B0A:
{
	sh2->r[11] ^= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2B1A:
{
	sh2->r[11] ^= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2B2A:
{
	sh2->r[11] ^= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2B3A:
{
	sh2->r[11] ^= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2B4A:
{
	sh2->r[11] ^= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2B5A:
{
	sh2->r[11] ^= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2B6A:
{
	sh2->r[11] ^= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2B7A:
{
	sh2->r[11] ^= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2B8A:
{
	sh2->r[11] ^= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2B9A:
{
	sh2->r[11] ^= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2BAA:
{
	sh2->r[11] ^= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2BBA:
{
	sh2->r[11] ^= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2BCA:
{
	sh2->r[11] ^= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2BDA:
{
	sh2->r[11] ^= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2BEA:
{
	sh2->r[11] ^= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2BFA:
{
	sh2->r[11] ^= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2C0A:
{
	sh2->r[12] ^= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2C1A:
{
	sh2->r[12] ^= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2C2A:
{
	sh2->r[12] ^= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2C3A:
{
	sh2->r[12] ^= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2C4A:
{
	sh2->r[12] ^= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2C5A:
{
	sh2->r[12] ^= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2C6A:
{
	sh2->r[12] ^= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2C7A:
{
	sh2->r[12] ^= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2C8A:
{
	sh2->r[12] ^= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2C9A:
{
	sh2->r[12] ^= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2CAA:
{
	sh2->r[12] ^= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2CBA:
{
	sh2->r[12] ^= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2CCA:
{
	sh2->r[12] ^= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2CDA:
{
	sh2->r[12] ^= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2CEA:
{
	sh2->r[12] ^= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2CFA:
{
	sh2->r[12] ^= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2D0A:
{
	sh2->r[13] ^= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2D1A:
{
	sh2->r[13] ^= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2D2A:
{
	sh2->r[13] ^= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2D3A:
{
	sh2->r[13] ^= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2D4A:
{
	sh2->r[13] ^= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2D5A:
{
	sh2->r[13] ^= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2D6A:
{
	sh2->r[13] ^= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2D7A:
{
	sh2->r[13] ^= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2D8A:
{
	sh2->r[13] ^= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2D9A:
{
	sh2->r[13] ^= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2DAA:
{
	sh2->r[13] ^= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2DBA:
{
	sh2->r[13] ^= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2DCA:
{
	sh2->r[13] ^= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2DDA:
{
	sh2->r[13] ^= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2DEA:
{
	sh2->r[13] ^= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2DFA:
{
	sh2->r[13] ^= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2E0A:
{
	sh2->r[14] ^= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2E1A:
{
	sh2->r[14] ^= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2E2A:
{
	sh2->r[14] ^= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2E3A:
{
	sh2->r[14] ^= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2E4A:
{
	sh2->r[14] ^= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2E5A:
{
	sh2->r[14] ^= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2E6A:
{
	sh2->r[14] ^= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2E7A:
{
	sh2->r[14] ^= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2E8A:
{
	sh2->r[14] ^= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2E9A:
{
	sh2->r[14] ^= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2EAA:
{
	sh2->r[14] ^= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2EBA:
{
	sh2->r[14] ^= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2ECA:
{
	sh2->r[14] ^= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2EDA:
{
	sh2->r[14] ^= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2EEA:
{
	sh2->r[14] ^= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2EFA:
{
	sh2->r[14] ^= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2F0A:
{
	sh2->r[15] ^= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2F1A:
{
	sh2->r[15] ^= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2F2A:
{
	sh2->r[15] ^= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2F3A:
{
	sh2->r[15] ^= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2F4A:
{
	sh2->r[15] ^= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2F5A:
{
	sh2->r[15] ^= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2F6A:
{
	sh2->r[15] ^= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2F7A:
{
	sh2->r[15] ^= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2F8A:
{
	sh2->r[15] ^= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2F9A:
{
	sh2->r[15] ^= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2FAA:
{
	sh2->r[15] ^= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2FBA:
{
	sh2->r[15] ^= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2FCA:
{
	sh2->r[15] ^= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2FDA:
{
	sh2->r[15] ^= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2FEA:
{
	sh2->r[15] ^= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2FFA:
{
	sh2->r[15] ^= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

// OR Rm,Rn
Op200B:
{
	sh2->r[0] |= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op201B:
{
	sh2->r[0] |= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op202B:
{
	sh2->r[0] |= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op203B:
{
	sh2->r[0] |= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op204B:
{
	sh2->r[0] |= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op205B:
{
	sh2->r[0] |= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op206B:
{
	sh2->r[0] |= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op207B:
{
	sh2->r[0] |= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op208B:
{
	sh2->r[0] |= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op209B:
{
	sh2->r[0] |= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op20AB:
{
	sh2->r[0] |= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op20BB:
{
	sh2->r[0] |= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op20CB:
{
	sh2->r[0] |= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op20DB:
{
	sh2->r[0] |= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op20EB:
{
	sh2->r[0] |= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op20FB:
{
	sh2->r[0] |= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op210B:
{
	sh2->r[1] |= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op211B:
{
	sh2->r[1] |= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op212B:
{
	sh2->r[1] |= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op213B:
{
	sh2->r[1] |= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op214B:
{
	sh2->r[1] |= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op215B:
{
	sh2->r[1] |= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op216B:
{
	sh2->r[1] |= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op217B:
{
	sh2->r[1] |= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op218B:
{
	sh2->r[1] |= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op219B:
{
	sh2->r[1] |= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op21AB:
{
	sh2->r[1] |= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op21BB:
{
	sh2->r[1] |= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op21CB:
{
	sh2->r[1] |= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op21DB:
{
	sh2->r[1] |= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op21EB:
{
	sh2->r[1] |= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op21FB:
{
	sh2->r[1] |= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op220B:
{
	sh2->r[2] |= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op221B:
{
	sh2->r[2] |= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op222B:
{
	sh2->r[2] |= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op223B:
{
	sh2->r[2] |= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op224B:
{
	sh2->r[2] |= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op225B:
{
	sh2->r[2] |= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op226B:
{
	sh2->r[2] |= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op227B:
{
	sh2->r[2] |= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op228B:
{
	sh2->r[2] |= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op229B:
{
	sh2->r[2] |= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op22AB:
{
	sh2->r[2] |= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op22BB:
{
	sh2->r[2] |= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op22CB:
{
	sh2->r[2] |= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op22DB:
{
	sh2->r[2] |= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op22EB:
{
	sh2->r[2] |= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op22FB:
{
	sh2->r[2] |= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op230B:
{
	sh2->r[3] |= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op231B:
{
	sh2->r[3] |= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op232B:
{
	sh2->r[3] |= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op233B:
{
	sh2->r[3] |= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op234B:
{
	sh2->r[3] |= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op235B:
{
	sh2->r[3] |= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op236B:
{
	sh2->r[3] |= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op237B:
{
	sh2->r[3] |= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op238B:
{
	sh2->r[3] |= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op239B:
{
	sh2->r[3] |= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op23AB:
{
	sh2->r[3] |= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op23BB:
{
	sh2->r[3] |= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op23CB:
{
	sh2->r[3] |= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op23DB:
{
	sh2->r[3] |= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op23EB:
{
	sh2->r[3] |= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op23FB:
{
	sh2->r[3] |= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op240B:
{
	sh2->r[4] |= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op241B:
{
	sh2->r[4] |= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op242B:
{
	sh2->r[4] |= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op243B:
{
	sh2->r[4] |= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op244B:
{
	sh2->r[4] |= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op245B:
{
	sh2->r[4] |= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op246B:
{
	sh2->r[4] |= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op247B:
{
	sh2->r[4] |= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op248B:
{
	sh2->r[4] |= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op249B:
{
	sh2->r[4] |= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op24AB:
{
	sh2->r[4] |= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op24BB:
{
	sh2->r[4] |= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op24CB:
{
	sh2->r[4] |= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op24DB:
{
	sh2->r[4] |= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op24EB:
{
	sh2->r[4] |= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op24FB:
{
	sh2->r[4] |= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op250B:
{
	sh2->r[5] |= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op251B:
{
	sh2->r[5] |= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op252B:
{
	sh2->r[5] |= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op253B:
{
	sh2->r[5] |= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op254B:
{
	sh2->r[5] |= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op255B:
{
	sh2->r[5] |= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op256B:
{
	sh2->r[5] |= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op257B:
{
	sh2->r[5] |= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op258B:
{
	sh2->r[5] |= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op259B:
{
	sh2->r[5] |= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op25AB:
{
	sh2->r[5] |= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op25BB:
{
	sh2->r[5] |= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op25CB:
{
	sh2->r[5] |= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op25DB:
{
	sh2->r[5] |= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op25EB:
{
	sh2->r[5] |= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op25FB:
{
	sh2->r[5] |= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op260B:
{
	sh2->r[6] |= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op261B:
{
	sh2->r[6] |= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op262B:
{
	sh2->r[6] |= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op263B:
{
	sh2->r[6] |= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op264B:
{
	sh2->r[6] |= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op265B:
{
	sh2->r[6] |= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op266B:
{
	sh2->r[6] |= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op267B:
{
	sh2->r[6] |= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op268B:
{
	sh2->r[6] |= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op269B:
{
	sh2->r[6] |= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op26AB:
{
	sh2->r[6] |= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op26BB:
{
	sh2->r[6] |= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op26CB:
{
	sh2->r[6] |= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op26DB:
{
	sh2->r[6] |= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op26EB:
{
	sh2->r[6] |= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op26FB:
{
	sh2->r[6] |= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op270B:
{
	sh2->r[7] |= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op271B:
{
	sh2->r[7] |= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op272B:
{
	sh2->r[7] |= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op273B:
{
	sh2->r[7] |= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op274B:
{
	sh2->r[7] |= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op275B:
{
	sh2->r[7] |= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op276B:
{
	sh2->r[7] |= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op277B:
{
	sh2->r[7] |= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op278B:
{
	sh2->r[7] |= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op279B:
{
	sh2->r[7] |= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op27AB:
{
	sh2->r[7] |= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op27BB:
{
	sh2->r[7] |= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op27CB:
{
	sh2->r[7] |= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op27DB:
{
	sh2->r[7] |= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op27EB:
{
	sh2->r[7] |= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op27FB:
{
	sh2->r[7] |= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op280B:
{
	sh2->r[8] |= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op281B:
{
	sh2->r[8] |= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op282B:
{
	sh2->r[8] |= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op283B:
{
	sh2->r[8] |= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op284B:
{
	sh2->r[8] |= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op285B:
{
	sh2->r[8] |= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op286B:
{
	sh2->r[8] |= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op287B:
{
	sh2->r[8] |= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op288B:
{
	sh2->r[8] |= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op289B:
{
	sh2->r[8] |= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op28AB:
{
	sh2->r[8] |= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op28BB:
{
	sh2->r[8] |= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op28CB:
{
	sh2->r[8] |= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op28DB:
{
	sh2->r[8] |= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op28EB:
{
	sh2->r[8] |= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op28FB:
{
	sh2->r[8] |= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op290B:
{
	sh2->r[9] |= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op291B:
{
	sh2->r[9] |= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op292B:
{
	sh2->r[9] |= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op293B:
{
	sh2->r[9] |= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op294B:
{
	sh2->r[9] |= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op295B:
{
	sh2->r[9] |= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op296B:
{
	sh2->r[9] |= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op297B:
{
	sh2->r[9] |= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op298B:
{
	sh2->r[9] |= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op299B:
{
	sh2->r[9] |= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op29AB:
{
	sh2->r[9] |= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op29BB:
{
	sh2->r[9] |= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op29CB:
{
	sh2->r[9] |= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op29DB:
{
	sh2->r[9] |= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op29EB:
{
	sh2->r[9] |= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op29FB:
{
	sh2->r[9] |= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2A0B:
{
	sh2->r[10] |= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2A1B:
{
	sh2->r[10] |= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2A2B:
{
	sh2->r[10] |= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2A3B:
{
	sh2->r[10] |= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2A4B:
{
	sh2->r[10] |= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2A5B:
{
	sh2->r[10] |= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2A6B:
{
	sh2->r[10] |= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2A7B:
{
	sh2->r[10] |= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2A8B:
{
	sh2->r[10] |= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2A9B:
{
	sh2->r[10] |= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2AAB:
{
	sh2->r[10] |= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2ABB:
{
	sh2->r[10] |= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2ACB:
{
	sh2->r[10] |= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2ADB:
{
	sh2->r[10] |= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2AEB:
{
	sh2->r[10] |= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2AFB:
{
	sh2->r[10] |= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2B0B:
{
	sh2->r[11] |= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2B1B:
{
	sh2->r[11] |= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2B2B:
{
	sh2->r[11] |= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2B3B:
{
	sh2->r[11] |= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2B4B:
{
	sh2->r[11] |= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2B5B:
{
	sh2->r[11] |= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2B6B:
{
	sh2->r[11] |= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2B7B:
{
	sh2->r[11] |= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2B8B:
{
	sh2->r[11] |= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2B9B:
{
	sh2->r[11] |= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2BAB:
{
	sh2->r[11] |= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2BBB:
{
	sh2->r[11] |= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2BCB:
{
	sh2->r[11] |= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2BDB:
{
	sh2->r[11] |= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2BEB:
{
	sh2->r[11] |= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2BFB:
{
	sh2->r[11] |= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2C0B:
{
	sh2->r[12] |= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2C1B:
{
	sh2->r[12] |= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2C2B:
{
	sh2->r[12] |= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2C3B:
{
	sh2->r[12] |= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2C4B:
{
	sh2->r[12] |= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2C5B:
{
	sh2->r[12] |= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2C6B:
{
	sh2->r[12] |= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2C7B:
{
	sh2->r[12] |= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2C8B:
{
	sh2->r[12] |= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2C9B:
{
	sh2->r[12] |= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2CAB:
{
	sh2->r[12] |= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2CBB:
{
	sh2->r[12] |= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2CCB:
{
	sh2->r[12] |= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2CDB:
{
	sh2->r[12] |= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2CEB:
{
	sh2->r[12] |= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2CFB:
{
	sh2->r[12] |= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2D0B:
{
	sh2->r[13] |= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2D1B:
{
	sh2->r[13] |= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2D2B:
{
	sh2->r[13] |= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2D3B:
{
	sh2->r[13] |= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2D4B:
{
	sh2->r[13] |= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2D5B:
{
	sh2->r[13] |= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2D6B:
{
	sh2->r[13] |= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2D7B:
{
	sh2->r[13] |= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2D8B:
{
	sh2->r[13] |= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2D9B:
{
	sh2->r[13] |= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2DAB:
{
	sh2->r[13] |= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2DBB:
{
	sh2->r[13] |= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2DCB:
{
	sh2->r[13] |= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2DDB:
{
	sh2->r[13] |= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2DEB:
{
	sh2->r[13] |= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2DFB:
{
	sh2->r[13] |= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2E0B:
{
	sh2->r[14] |= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2E1B:
{
	sh2->r[14] |= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2E2B:
{
	sh2->r[14] |= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2E3B:
{
	sh2->r[14] |= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2E4B:
{
	sh2->r[14] |= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2E5B:
{
	sh2->r[14] |= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2E6B:
{
	sh2->r[14] |= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2E7B:
{
	sh2->r[14] |= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2E8B:
{
	sh2->r[14] |= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2E9B:
{
	sh2->r[14] |= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2EAB:
{
	sh2->r[14] |= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2EBB:
{
	sh2->r[14] |= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2ECB:
{
	sh2->r[14] |= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2EDB:
{
	sh2->r[14] |= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2EEB:
{
	sh2->r[14] |= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2EFB:
{
	sh2->r[14] |= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2F0B:
{
	sh2->r[15] |= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2F1B:
{
	sh2->r[15] |= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2F2B:
{
	sh2->r[15] |= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2F3B:
{
	sh2->r[15] |= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2F4B:
{
	sh2->r[15] |= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2F5B:
{
	sh2->r[15] |= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2F6B:
{
	sh2->r[15] |= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2F7B:
{
	sh2->r[15] |= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2F8B:
{
	sh2->r[15] |= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2F9B:
{
	sh2->r[15] |= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2FAB:
{
	sh2->r[15] |= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2FBB:
{
	sh2->r[15] |= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2FCB:
{
	sh2->r[15] |= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2FDB:
{
	sh2->r[15] |= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2FEB:
{
	sh2->r[15] |= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2FFB:
{
	sh2->r[15] |= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

// CMP_STR Rm,Rn
Op200C:
{
	n = (opcode>>8) & 0x0f;
	m = (opcode>>4) & 0x0f;
	temp = sh2->r[n] ^ sh2->r[m];
	HH = (temp >> 24) & 0xff;
	HL = (temp >> 16) & 0xff;
	LH = (temp >> 8) & 0xff;
	LL = temp & 0xff;
	if (HH && HL && LH && LL)
		sh2->sr &= ~T;
	else
		sh2->sr |= T;
	goto SH2_RUN_CONTINUE;
}

// XTRCT Rm,Rn
Op200D:
{
	n = (opcode>>8) & 0x0f;
	m = (opcode>>4) & 0x0f;
	temp = (sh2->r[m] << 16) & 0xffff0000;
	sh2->r[n] = (sh2->r[n] >> 16) & 0x0000ffff;
	sh2->r[n] |= temp;
	goto SH2_RUN_CONTINUE;
}

// MULU Rm,Rn
Op200E:
{
	sh2->macl = (UINT16) sh2->r[0] * (UINT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op201E:
{
	sh2->macl = (UINT16) sh2->r[0] * (UINT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op202E:
{
	sh2->macl = (UINT16) sh2->r[0] * (UINT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op203E:
{
	sh2->macl = (UINT16) sh2->r[0] * (UINT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op204E:
{
	sh2->macl = (UINT16) sh2->r[0] * (UINT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op205E:
{
	sh2->macl = (UINT16) sh2->r[0] * (UINT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op206E:
{
	sh2->macl = (UINT16) sh2->r[0] * (UINT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op207E:
{
	sh2->macl = (UINT16) sh2->r[0] * (UINT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op208E:
{
	sh2->macl = (UINT16) sh2->r[0] * (UINT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op209E:
{
	sh2->macl = (UINT16) sh2->r[0] * (UINT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op20AE:
{
	sh2->macl = (UINT16) sh2->r[0] * (UINT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op20BE:
{
	sh2->macl = (UINT16) sh2->r[0] * (UINT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op20CE:
{
	sh2->macl = (UINT16) sh2->r[0] * (UINT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op20DE:
{
	sh2->macl = (UINT16) sh2->r[0] * (UINT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op20EE:
{
	sh2->macl = (UINT16) sh2->r[0] * (UINT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op20FE:
{
	sh2->macl = (UINT16) sh2->r[0] * (UINT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op210E:
{
	sh2->macl = (UINT16) sh2->r[1] * (UINT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op211E:
{
	sh2->macl = (UINT16) sh2->r[1] * (UINT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op212E:
{
	sh2->macl = (UINT16) sh2->r[1] * (UINT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op213E:
{
	sh2->macl = (UINT16) sh2->r[1] * (UINT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op214E:
{
	sh2->macl = (UINT16) sh2->r[1] * (UINT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op215E:
{
	sh2->macl = (UINT16) sh2->r[1] * (UINT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op216E:
{
	sh2->macl = (UINT16) sh2->r[1] * (UINT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op217E:
{
	sh2->macl = (UINT16) sh2->r[1] * (UINT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op218E:
{
	sh2->macl = (UINT16) sh2->r[1] * (UINT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op219E:
{
	sh2->macl = (UINT16) sh2->r[1] * (UINT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op21AE:
{
	sh2->macl = (UINT16) sh2->r[1] * (UINT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op21BE:
{
	sh2->macl = (UINT16) sh2->r[1] * (UINT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op21CE:
{
	sh2->macl = (UINT16) sh2->r[1] * (UINT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op21DE:
{
	sh2->macl = (UINT16) sh2->r[1] * (UINT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op21EE:
{
	sh2->macl = (UINT16) sh2->r[1] * (UINT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op21FE:
{
	sh2->macl = (UINT16) sh2->r[1] * (UINT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op220E:
{
	sh2->macl = (UINT16) sh2->r[2] * (UINT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op221E:
{
	sh2->macl = (UINT16) sh2->r[2] * (UINT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op222E:
{
	sh2->macl = (UINT16) sh2->r[2] * (UINT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op223E:
{
	sh2->macl = (UINT16) sh2->r[2] * (UINT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op224E:
{
	sh2->macl = (UINT16) sh2->r[2] * (UINT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op225E:
{
	sh2->macl = (UINT16) sh2->r[2] * (UINT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op226E:
{
	sh2->macl = (UINT16) sh2->r[2] * (UINT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op227E:
{
	sh2->macl = (UINT16) sh2->r[2] * (UINT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op228E:
{
	sh2->macl = (UINT16) sh2->r[2] * (UINT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op229E:
{
	sh2->macl = (UINT16) sh2->r[2] * (UINT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op22AE:
{
	sh2->macl = (UINT16) sh2->r[2] * (UINT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op22BE:
{
	sh2->macl = (UINT16) sh2->r[2] * (UINT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op22CE:
{
	sh2->macl = (UINT16) sh2->r[2] * (UINT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op22DE:
{
	sh2->macl = (UINT16) sh2->r[2] * (UINT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op22EE:
{
	sh2->macl = (UINT16) sh2->r[2] * (UINT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op22FE:
{
	sh2->macl = (UINT16) sh2->r[2] * (UINT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op230E:
{
	sh2->macl = (UINT16) sh2->r[3] * (UINT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op231E:
{
	sh2->macl = (UINT16) sh2->r[3] * (UINT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op232E:
{
	sh2->macl = (UINT16) sh2->r[3] * (UINT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op233E:
{
	sh2->macl = (UINT16) sh2->r[3] * (UINT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op234E:
{
	sh2->macl = (UINT16) sh2->r[3] * (UINT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op235E:
{
	sh2->macl = (UINT16) sh2->r[3] * (UINT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op236E:
{
	sh2->macl = (UINT16) sh2->r[3] * (UINT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op237E:
{
	sh2->macl = (UINT16) sh2->r[3] * (UINT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op238E:
{
	sh2->macl = (UINT16) sh2->r[3] * (UINT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op239E:
{
	sh2->macl = (UINT16) sh2->r[3] * (UINT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op23AE:
{
	sh2->macl = (UINT16) sh2->r[3] * (UINT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op23BE:
{
	sh2->macl = (UINT16) sh2->r[3] * (UINT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op23CE:
{
	sh2->macl = (UINT16) sh2->r[3] * (UINT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op23DE:
{
	sh2->macl = (UINT16) sh2->r[3] * (UINT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op23EE:
{
	sh2->macl = (UINT16) sh2->r[3] * (UINT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op23FE:
{
	sh2->macl = (UINT16) sh2->r[3] * (UINT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op240E:
{
	sh2->macl = (UINT16) sh2->r[4] * (UINT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op241E:
{
	sh2->macl = (UINT16) sh2->r[4] * (UINT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op242E:
{
	sh2->macl = (UINT16) sh2->r[4] * (UINT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op243E:
{
	sh2->macl = (UINT16) sh2->r[4] * (UINT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op244E:
{
	sh2->macl = (UINT16) sh2->r[4] * (UINT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op245E:
{
	sh2->macl = (UINT16) sh2->r[4] * (UINT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op246E:
{
	sh2->macl = (UINT16) sh2->r[4] * (UINT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op247E:
{
	sh2->macl = (UINT16) sh2->r[4] * (UINT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op248E:
{
	sh2->macl = (UINT16) sh2->r[4] * (UINT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op249E:
{
	sh2->macl = (UINT16) sh2->r[4] * (UINT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op24AE:
{
	sh2->macl = (UINT16) sh2->r[4] * (UINT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op24BE:
{
	sh2->macl = (UINT16) sh2->r[4] * (UINT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op24CE:
{
	sh2->macl = (UINT16) sh2->r[4] * (UINT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op24DE:
{
	sh2->macl = (UINT16) sh2->r[4] * (UINT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op24EE:
{
	sh2->macl = (UINT16) sh2->r[4] * (UINT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op24FE:
{
	sh2->macl = (UINT16) sh2->r[4] * (UINT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op250E:
{
	sh2->macl = (UINT16) sh2->r[5] * (UINT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op251E:
{
	sh2->macl = (UINT16) sh2->r[5] * (UINT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op252E:
{
	sh2->macl = (UINT16) sh2->r[5] * (UINT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op253E:
{
	sh2->macl = (UINT16) sh2->r[5] * (UINT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op254E:
{
	sh2->macl = (UINT16) sh2->r[5] * (UINT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op255E:
{
	sh2->macl = (UINT16) sh2->r[5] * (UINT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op256E:
{
	sh2->macl = (UINT16) sh2->r[5] * (UINT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op257E:
{
	sh2->macl = (UINT16) sh2->r[5] * (UINT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op258E:
{
	sh2->macl = (UINT16) sh2->r[5] * (UINT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op259E:
{
	sh2->macl = (UINT16) sh2->r[5] * (UINT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op25AE:
{
	sh2->macl = (UINT16) sh2->r[5] * (UINT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op25BE:
{
	sh2->macl = (UINT16) sh2->r[5] * (UINT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op25CE:
{
	sh2->macl = (UINT16) sh2->r[5] * (UINT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op25DE:
{
	sh2->macl = (UINT16) sh2->r[5] * (UINT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op25EE:
{
	sh2->macl = (UINT16) sh2->r[5] * (UINT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op25FE:
{
	sh2->macl = (UINT16) sh2->r[5] * (UINT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op260E:
{
	sh2->macl = (UINT16) sh2->r[6] * (UINT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op261E:
{
	sh2->macl = (UINT16) sh2->r[6] * (UINT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op262E:
{
	sh2->macl = (UINT16) sh2->r[6] * (UINT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op263E:
{
	sh2->macl = (UINT16) sh2->r[6] * (UINT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op264E:
{
	sh2->macl = (UINT16) sh2->r[6] * (UINT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op265E:
{
	sh2->macl = (UINT16) sh2->r[6] * (UINT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op266E:
{
	sh2->macl = (UINT16) sh2->r[6] * (UINT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op267E:
{
	sh2->macl = (UINT16) sh2->r[6] * (UINT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op268E:
{
	sh2->macl = (UINT16) sh2->r[6] * (UINT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op269E:
{
	sh2->macl = (UINT16) sh2->r[6] * (UINT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op26AE:
{
	sh2->macl = (UINT16) sh2->r[6] * (UINT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op26BE:
{
	sh2->macl = (UINT16) sh2->r[6] * (UINT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op26CE:
{
	sh2->macl = (UINT16) sh2->r[6] * (UINT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op26DE:
{
	sh2->macl = (UINT16) sh2->r[6] * (UINT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op26EE:
{
	sh2->macl = (UINT16) sh2->r[6] * (UINT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op26FE:
{
	sh2->macl = (UINT16) sh2->r[6] * (UINT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op270E:
{
	sh2->macl = (UINT16) sh2->r[7] * (UINT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op271E:
{
	sh2->macl = (UINT16) sh2->r[7] * (UINT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op272E:
{
	sh2->macl = (UINT16) sh2->r[7] * (UINT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op273E:
{
	sh2->macl = (UINT16) sh2->r[7] * (UINT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op274E:
{
	sh2->macl = (UINT16) sh2->r[7] * (UINT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op275E:
{
	sh2->macl = (UINT16) sh2->r[7] * (UINT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op276E:
{
	sh2->macl = (UINT16) sh2->r[7] * (UINT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op277E:
{
	sh2->macl = (UINT16) sh2->r[7] * (UINT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op278E:
{
	sh2->macl = (UINT16) sh2->r[7] * (UINT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op279E:
{
	sh2->macl = (UINT16) sh2->r[7] * (UINT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op27AE:
{
	sh2->macl = (UINT16) sh2->r[7] * (UINT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op27BE:
{
	sh2->macl = (UINT16) sh2->r[7] * (UINT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op27CE:
{
	sh2->macl = (UINT16) sh2->r[7] * (UINT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op27DE:
{
	sh2->macl = (UINT16) sh2->r[7] * (UINT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op27EE:
{
	sh2->macl = (UINT16) sh2->r[7] * (UINT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op27FE:
{
	sh2->macl = (UINT16) sh2->r[7] * (UINT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op280E:
{
	sh2->macl = (UINT16) sh2->r[8] * (UINT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op281E:
{
	sh2->macl = (UINT16) sh2->r[8] * (UINT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op282E:
{
	sh2->macl = (UINT16) sh2->r[8] * (UINT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op283E:
{
	sh2->macl = (UINT16) sh2->r[8] * (UINT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op284E:
{
	sh2->macl = (UINT16) sh2->r[8] * (UINT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op285E:
{
	sh2->macl = (UINT16) sh2->r[8] * (UINT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op286E:
{
	sh2->macl = (UINT16) sh2->r[8] * (UINT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op287E:
{
	sh2->macl = (UINT16) sh2->r[8] * (UINT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op288E:
{
	sh2->macl = (UINT16) sh2->r[8] * (UINT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op289E:
{
	sh2->macl = (UINT16) sh2->r[8] * (UINT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op28AE:
{
	sh2->macl = (UINT16) sh2->r[8] * (UINT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op28BE:
{
	sh2->macl = (UINT16) sh2->r[8] * (UINT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op28CE:
{
	sh2->macl = (UINT16) sh2->r[8] * (UINT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op28DE:
{
	sh2->macl = (UINT16) sh2->r[8] * (UINT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op28EE:
{
	sh2->macl = (UINT16) sh2->r[8] * (UINT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op28FE:
{
	sh2->macl = (UINT16) sh2->r[8] * (UINT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op290E:
{
	sh2->macl = (UINT16) sh2->r[9] * (UINT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op291E:
{
	sh2->macl = (UINT16) sh2->r[9] * (UINT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op292E:
{
	sh2->macl = (UINT16) sh2->r[9] * (UINT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op293E:
{
	sh2->macl = (UINT16) sh2->r[9] * (UINT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op294E:
{
	sh2->macl = (UINT16) sh2->r[9] * (UINT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op295E:
{
	sh2->macl = (UINT16) sh2->r[9] * (UINT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op296E:
{
	sh2->macl = (UINT16) sh2->r[9] * (UINT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op297E:
{
	sh2->macl = (UINT16) sh2->r[9] * (UINT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op298E:
{
	sh2->macl = (UINT16) sh2->r[9] * (UINT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op299E:
{
	sh2->macl = (UINT16) sh2->r[9] * (UINT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op29AE:
{
	sh2->macl = (UINT16) sh2->r[9] * (UINT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op29BE:
{
	sh2->macl = (UINT16) sh2->r[9] * (UINT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op29CE:
{
	sh2->macl = (UINT16) sh2->r[9] * (UINT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op29DE:
{
	sh2->macl = (UINT16) sh2->r[9] * (UINT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op29EE:
{
	sh2->macl = (UINT16) sh2->r[9] * (UINT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op29FE:
{
	sh2->macl = (UINT16) sh2->r[9] * (UINT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2A0E:
{
	sh2->macl = (UINT16) sh2->r[10] * (UINT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2A1E:
{
	sh2->macl = (UINT16) sh2->r[10] * (UINT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2A2E:
{
	sh2->macl = (UINT16) sh2->r[10] * (UINT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2A3E:
{
	sh2->macl = (UINT16) sh2->r[10] * (UINT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2A4E:
{
	sh2->macl = (UINT16) sh2->r[10] * (UINT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2A5E:
{
	sh2->macl = (UINT16) sh2->r[10] * (UINT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2A6E:
{
	sh2->macl = (UINT16) sh2->r[10] * (UINT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2A7E:
{
	sh2->macl = (UINT16) sh2->r[10] * (UINT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2A8E:
{
	sh2->macl = (UINT16) sh2->r[10] * (UINT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2A9E:
{
	sh2->macl = (UINT16) sh2->r[10] * (UINT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2AAE:
{
	sh2->macl = (UINT16) sh2->r[10] * (UINT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2ABE:
{
	sh2->macl = (UINT16) sh2->r[10] * (UINT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2ACE:
{
	sh2->macl = (UINT16) sh2->r[10] * (UINT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2ADE:
{
	sh2->macl = (UINT16) sh2->r[10] * (UINT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2AEE:
{
	sh2->macl = (UINT16) sh2->r[10] * (UINT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2AFE:
{
	sh2->macl = (UINT16) sh2->r[10] * (UINT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2B0E:
{
	sh2->macl = (UINT16) sh2->r[11] * (UINT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2B1E:
{
	sh2->macl = (UINT16) sh2->r[11] * (UINT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2B2E:
{
	sh2->macl = (UINT16) sh2->r[11] * (UINT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2B3E:
{
	sh2->macl = (UINT16) sh2->r[11] * (UINT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2B4E:
{
	sh2->macl = (UINT16) sh2->r[11] * (UINT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2B5E:
{
	sh2->macl = (UINT16) sh2->r[11] * (UINT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2B6E:
{
	sh2->macl = (UINT16) sh2->r[11] * (UINT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2B7E:
{
	sh2->macl = (UINT16) sh2->r[11] * (UINT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2B8E:
{
	sh2->macl = (UINT16) sh2->r[11] * (UINT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2B9E:
{
	sh2->macl = (UINT16) sh2->r[11] * (UINT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2BAE:
{
	sh2->macl = (UINT16) sh2->r[11] * (UINT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2BBE:
{
	sh2->macl = (UINT16) sh2->r[11] * (UINT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2BCE:
{
	sh2->macl = (UINT16) sh2->r[11] * (UINT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2BDE:
{
	sh2->macl = (UINT16) sh2->r[11] * (UINT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2BEE:
{
	sh2->macl = (UINT16) sh2->r[11] * (UINT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2BFE:
{
	sh2->macl = (UINT16) sh2->r[11] * (UINT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2C0E:
{
	sh2->macl = (UINT16) sh2->r[12] * (UINT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2C1E:
{
	sh2->macl = (UINT16) sh2->r[12] * (UINT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2C2E:
{
	sh2->macl = (UINT16) sh2->r[12] * (UINT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2C3E:
{
	sh2->macl = (UINT16) sh2->r[12] * (UINT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2C4E:
{
	sh2->macl = (UINT16) sh2->r[12] * (UINT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2C5E:
{
	sh2->macl = (UINT16) sh2->r[12] * (UINT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2C6E:
{
	sh2->macl = (UINT16) sh2->r[12] * (UINT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2C7E:
{
	sh2->macl = (UINT16) sh2->r[12] * (UINT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2C8E:
{
	sh2->macl = (UINT16) sh2->r[12] * (UINT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2C9E:
{
	sh2->macl = (UINT16) sh2->r[12] * (UINT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2CAE:
{
	sh2->macl = (UINT16) sh2->r[12] * (UINT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2CBE:
{
	sh2->macl = (UINT16) sh2->r[12] * (UINT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2CCE:
{
	sh2->macl = (UINT16) sh2->r[12] * (UINT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2CDE:
{
	sh2->macl = (UINT16) sh2->r[12] * (UINT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2CEE:
{
	sh2->macl = (UINT16) sh2->r[12] * (UINT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2CFE:
{
	sh2->macl = (UINT16) sh2->r[12] * (UINT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2D0E:
{
	sh2->macl = (UINT16) sh2->r[13] * (UINT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2D1E:
{
	sh2->macl = (UINT16) sh2->r[13] * (UINT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2D2E:
{
	sh2->macl = (UINT16) sh2->r[13] * (UINT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2D3E:
{
	sh2->macl = (UINT16) sh2->r[13] * (UINT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2D4E:
{
	sh2->macl = (UINT16) sh2->r[13] * (UINT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2D5E:
{
	sh2->macl = (UINT16) sh2->r[13] * (UINT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2D6E:
{
	sh2->macl = (UINT16) sh2->r[13] * (UINT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2D7E:
{
	sh2->macl = (UINT16) sh2->r[13] * (UINT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2D8E:
{
	sh2->macl = (UINT16) sh2->r[13] * (UINT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2D9E:
{
	sh2->macl = (UINT16) sh2->r[13] * (UINT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2DAE:
{
	sh2->macl = (UINT16) sh2->r[13] * (UINT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2DBE:
{
	sh2->macl = (UINT16) sh2->r[13] * (UINT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2DCE:
{
	sh2->macl = (UINT16) sh2->r[13] * (UINT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2DDE:
{
	sh2->macl = (UINT16) sh2->r[13] * (UINT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2DEE:
{
	sh2->macl = (UINT16) sh2->r[13] * (UINT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2DFE:
{
	sh2->macl = (UINT16) sh2->r[13] * (UINT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2E0E:
{
	sh2->macl = (UINT16) sh2->r[14] * (UINT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2E1E:
{
	sh2->macl = (UINT16) sh2->r[14] * (UINT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2E2E:
{
	sh2->macl = (UINT16) sh2->r[14] * (UINT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2E3E:
{
	sh2->macl = (UINT16) sh2->r[14] * (UINT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2E4E:
{
	sh2->macl = (UINT16) sh2->r[14] * (UINT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2E5E:
{
	sh2->macl = (UINT16) sh2->r[14] * (UINT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2E6E:
{
	sh2->macl = (UINT16) sh2->r[14] * (UINT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2E7E:
{
	sh2->macl = (UINT16) sh2->r[14] * (UINT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2E8E:
{
	sh2->macl = (UINT16) sh2->r[14] * (UINT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2E9E:
{
	sh2->macl = (UINT16) sh2->r[14] * (UINT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2EAE:
{
	sh2->macl = (UINT16) sh2->r[14] * (UINT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2EBE:
{
	sh2->macl = (UINT16) sh2->r[14] * (UINT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2ECE:
{
	sh2->macl = (UINT16) sh2->r[14] * (UINT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2EDE:
{
	sh2->macl = (UINT16) sh2->r[14] * (UINT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2EEE:
{
	sh2->macl = (UINT16) sh2->r[14] * (UINT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2EFE:
{
	sh2->macl = (UINT16) sh2->r[14] * (UINT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2F0E:
{
	sh2->macl = (UINT16) sh2->r[15] * (UINT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2F1E:
{
	sh2->macl = (UINT16) sh2->r[15] * (UINT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2F2E:
{
	sh2->macl = (UINT16) sh2->r[15] * (UINT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2F3E:
{
	sh2->macl = (UINT16) sh2->r[15] * (UINT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2F4E:
{
	sh2->macl = (UINT16) sh2->r[15] * (UINT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2F5E:
{
	sh2->macl = (UINT16) sh2->r[15] * (UINT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2F6E:
{
	sh2->macl = (UINT16) sh2->r[15] * (UINT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2F7E:
{
	sh2->macl = (UINT16) sh2->r[15] * (UINT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2F8E:
{
	sh2->macl = (UINT16) sh2->r[15] * (UINT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2F9E:
{
	sh2->macl = (UINT16) sh2->r[15] * (UINT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2FAE:
{
	sh2->macl = (UINT16) sh2->r[15] * (UINT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2FBE:
{
	sh2->macl = (UINT16) sh2->r[15] * (UINT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2FCE:
{
	sh2->macl = (UINT16) sh2->r[15] * (UINT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2FDE:
{
	sh2->macl = (UINT16) sh2->r[15] * (UINT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2FEE:
{
	sh2->macl = (UINT16) sh2->r[15] * (UINT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2FFE:
{
	sh2->macl = (UINT16) sh2->r[15] * (UINT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

// MULS Rm,Rn
Op200F:
{
	sh2->macl = (INT16) sh2->r[0] * (INT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op201F:
{
	sh2->macl = (INT16) sh2->r[0] * (INT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op202F:
{
	sh2->macl = (INT16) sh2->r[0] * (INT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op203F:
{
	sh2->macl = (INT16) sh2->r[0] * (INT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op204F:
{
	sh2->macl = (INT16) sh2->r[0] * (INT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op205F:
{
	sh2->macl = (INT16) sh2->r[0] * (INT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op206F:
{
	sh2->macl = (INT16) sh2->r[0] * (INT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op207F:
{
	sh2->macl = (INT16) sh2->r[0] * (INT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op208F:
{
	sh2->macl = (INT16) sh2->r[0] * (INT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op209F:
{
	sh2->macl = (INT16) sh2->r[0] * (INT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op20AF:
{
	sh2->macl = (INT16) sh2->r[0] * (INT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op20BF:
{
	sh2->macl = (INT16) sh2->r[0] * (INT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op20CF:
{
	sh2->macl = (INT16) sh2->r[0] * (INT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op20DF:
{
	sh2->macl = (INT16) sh2->r[0] * (INT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op20EF:
{
	sh2->macl = (INT16) sh2->r[0] * (INT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op20FF:
{
	sh2->macl = (INT16) sh2->r[0] * (INT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op210F:
{
	sh2->macl = (INT16) sh2->r[1] * (INT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op211F:
{
	sh2->macl = (INT16) sh2->r[1] * (INT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op212F:
{
	sh2->macl = (INT16) sh2->r[1] * (INT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op213F:
{
	sh2->macl = (INT16) sh2->r[1] * (INT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op214F:
{
	sh2->macl = (INT16) sh2->r[1] * (INT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op215F:
{
	sh2->macl = (INT16) sh2->r[1] * (INT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op216F:
{
	sh2->macl = (INT16) sh2->r[1] * (INT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op217F:
{
	sh2->macl = (INT16) sh2->r[1] * (INT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op218F:
{
	sh2->macl = (INT16) sh2->r[1] * (INT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op219F:
{
	sh2->macl = (INT16) sh2->r[1] * (INT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op21AF:
{
	sh2->macl = (INT16) sh2->r[1] * (INT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op21BF:
{
	sh2->macl = (INT16) sh2->r[1] * (INT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op21CF:
{
	sh2->macl = (INT16) sh2->r[1] * (INT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op21DF:
{
	sh2->macl = (INT16) sh2->r[1] * (INT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op21EF:
{
	sh2->macl = (INT16) sh2->r[1] * (INT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op21FF:
{
	sh2->macl = (INT16) sh2->r[1] * (INT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op220F:
{
	sh2->macl = (INT16) sh2->r[2] * (INT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op221F:
{
	sh2->macl = (INT16) sh2->r[2] * (INT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op222F:
{
	sh2->macl = (INT16) sh2->r[2] * (INT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op223F:
{
	sh2->macl = (INT16) sh2->r[2] * (INT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op224F:
{
	sh2->macl = (INT16) sh2->r[2] * (INT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op225F:
{
	sh2->macl = (INT16) sh2->r[2] * (INT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op226F:
{
	sh2->macl = (INT16) sh2->r[2] * (INT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op227F:
{
	sh2->macl = (INT16) sh2->r[2] * (INT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op228F:
{
	sh2->macl = (INT16) sh2->r[2] * (INT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op229F:
{
	sh2->macl = (INT16) sh2->r[2] * (INT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op22AF:
{
	sh2->macl = (INT16) sh2->r[2] * (INT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op22BF:
{
	sh2->macl = (INT16) sh2->r[2] * (INT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op22CF:
{
	sh2->macl = (INT16) sh2->r[2] * (INT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op22DF:
{
	sh2->macl = (INT16) sh2->r[2] * (INT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op22EF:
{
	sh2->macl = (INT16) sh2->r[2] * (INT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op22FF:
{
	sh2->macl = (INT16) sh2->r[2] * (INT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op230F:
{
	sh2->macl = (INT16) sh2->r[3] * (INT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op231F:
{
	sh2->macl = (INT16) sh2->r[3] * (INT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op232F:
{
	sh2->macl = (INT16) sh2->r[3] * (INT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op233F:
{
	sh2->macl = (INT16) sh2->r[3] * (INT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op234F:
{
	sh2->macl = (INT16) sh2->r[3] * (INT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op235F:
{
	sh2->macl = (INT16) sh2->r[3] * (INT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op236F:
{
	sh2->macl = (INT16) sh2->r[3] * (INT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op237F:
{
	sh2->macl = (INT16) sh2->r[3] * (INT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op238F:
{
	sh2->macl = (INT16) sh2->r[3] * (INT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op239F:
{
	sh2->macl = (INT16) sh2->r[3] * (INT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op23AF:
{
	sh2->macl = (INT16) sh2->r[3] * (INT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op23BF:
{
	sh2->macl = (INT16) sh2->r[3] * (INT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op23CF:
{
	sh2->macl = (INT16) sh2->r[3] * (INT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op23DF:
{
	sh2->macl = (INT16) sh2->r[3] * (INT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op23EF:
{
	sh2->macl = (INT16) sh2->r[3] * (INT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op23FF:
{
	sh2->macl = (INT16) sh2->r[3] * (INT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op240F:
{
	sh2->macl = (INT16) sh2->r[4] * (INT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op241F:
{
	sh2->macl = (INT16) sh2->r[4] * (INT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op242F:
{
	sh2->macl = (INT16) sh2->r[4] * (INT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op243F:
{
	sh2->macl = (INT16) sh2->r[4] * (INT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op244F:
{
	sh2->macl = (INT16) sh2->r[4] * (INT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op245F:
{
	sh2->macl = (INT16) sh2->r[4] * (INT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op246F:
{
	sh2->macl = (INT16) sh2->r[4] * (INT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op247F:
{
	sh2->macl = (INT16) sh2->r[4] * (INT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op248F:
{
	sh2->macl = (INT16) sh2->r[4] * (INT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op249F:
{
	sh2->macl = (INT16) sh2->r[4] * (INT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op24AF:
{
	sh2->macl = (INT16) sh2->r[4] * (INT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op24BF:
{
	sh2->macl = (INT16) sh2->r[4] * (INT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op24CF:
{
	sh2->macl = (INT16) sh2->r[4] * (INT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op24DF:
{
	sh2->macl = (INT16) sh2->r[4] * (INT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op24EF:
{
	sh2->macl = (INT16) sh2->r[4] * (INT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op24FF:
{
	sh2->macl = (INT16) sh2->r[4] * (INT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op250F:
{
	sh2->macl = (INT16) sh2->r[5] * (INT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op251F:
{
	sh2->macl = (INT16) sh2->r[5] * (INT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op252F:
{
	sh2->macl = (INT16) sh2->r[5] * (INT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op253F:
{
	sh2->macl = (INT16) sh2->r[5] * (INT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op254F:
{
	sh2->macl = (INT16) sh2->r[5] * (INT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op255F:
{
	sh2->macl = (INT16) sh2->r[5] * (INT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op256F:
{
	sh2->macl = (INT16) sh2->r[5] * (INT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op257F:
{
	sh2->macl = (INT16) sh2->r[5] * (INT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op258F:
{
	sh2->macl = (INT16) sh2->r[5] * (INT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op259F:
{
	sh2->macl = (INT16) sh2->r[5] * (INT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op25AF:
{
	sh2->macl = (INT16) sh2->r[5] * (INT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op25BF:
{
	sh2->macl = (INT16) sh2->r[5] * (INT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op25CF:
{
	sh2->macl = (INT16) sh2->r[5] * (INT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op25DF:
{
	sh2->macl = (INT16) sh2->r[5] * (INT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op25EF:
{
	sh2->macl = (INT16) sh2->r[5] * (INT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op25FF:
{
	sh2->macl = (INT16) sh2->r[5] * (INT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op260F:
{
	sh2->macl = (INT16) sh2->r[6] * (INT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op261F:
{
	sh2->macl = (INT16) sh2->r[6] * (INT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op262F:
{
	sh2->macl = (INT16) sh2->r[6] * (INT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op263F:
{
	sh2->macl = (INT16) sh2->r[6] * (INT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op264F:
{
	sh2->macl = (INT16) sh2->r[6] * (INT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op265F:
{
	sh2->macl = (INT16) sh2->r[6] * (INT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op266F:
{
	sh2->macl = (INT16) sh2->r[6] * (INT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op267F:
{
	sh2->macl = (INT16) sh2->r[6] * (INT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op268F:
{
	sh2->macl = (INT16) sh2->r[6] * (INT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op269F:
{
	sh2->macl = (INT16) sh2->r[6] * (INT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op26AF:
{
	sh2->macl = (INT16) sh2->r[6] * (INT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op26BF:
{
	sh2->macl = (INT16) sh2->r[6] * (INT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op26CF:
{
	sh2->macl = (INT16) sh2->r[6] * (INT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op26DF:
{
	sh2->macl = (INT16) sh2->r[6] * (INT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op26EF:
{
	sh2->macl = (INT16) sh2->r[6] * (INT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op26FF:
{
	sh2->macl = (INT16) sh2->r[6] * (INT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op270F:
{
	sh2->macl = (INT16) sh2->r[7] * (INT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op271F:
{
	sh2->macl = (INT16) sh2->r[7] * (INT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op272F:
{
	sh2->macl = (INT16) sh2->r[7] * (INT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op273F:
{
	sh2->macl = (INT16) sh2->r[7] * (INT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op274F:
{
	sh2->macl = (INT16) sh2->r[7] * (INT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op275F:
{
	sh2->macl = (INT16) sh2->r[7] * (INT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op276F:
{
	sh2->macl = (INT16) sh2->r[7] * (INT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op277F:
{
	sh2->macl = (INT16) sh2->r[7] * (INT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op278F:
{
	sh2->macl = (INT16) sh2->r[7] * (INT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op279F:
{
	sh2->macl = (INT16) sh2->r[7] * (INT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op27AF:
{
	sh2->macl = (INT16) sh2->r[7] * (INT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op27BF:
{
	sh2->macl = (INT16) sh2->r[7] * (INT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op27CF:
{
	sh2->macl = (INT16) sh2->r[7] * (INT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op27DF:
{
	sh2->macl = (INT16) sh2->r[7] * (INT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op27EF:
{
	sh2->macl = (INT16) sh2->r[7] * (INT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op27FF:
{
	sh2->macl = (INT16) sh2->r[7] * (INT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op280F:
{
	sh2->macl = (INT16) sh2->r[8] * (INT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op281F:
{
	sh2->macl = (INT16) sh2->r[8] * (INT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op282F:
{
	sh2->macl = (INT16) sh2->r[8] * (INT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op283F:
{
	sh2->macl = (INT16) sh2->r[8] * (INT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op284F:
{
	sh2->macl = (INT16) sh2->r[8] * (INT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op285F:
{
	sh2->macl = (INT16) sh2->r[8] * (INT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op286F:
{
	sh2->macl = (INT16) sh2->r[8] * (INT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op287F:
{
	sh2->macl = (INT16) sh2->r[8] * (INT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op288F:
{
	sh2->macl = (INT16) sh2->r[8] * (INT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op289F:
{
	sh2->macl = (INT16) sh2->r[8] * (INT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op28AF:
{
	sh2->macl = (INT16) sh2->r[8] * (INT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op28BF:
{
	sh2->macl = (INT16) sh2->r[8] * (INT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op28CF:
{
	sh2->macl = (INT16) sh2->r[8] * (INT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op28DF:
{
	sh2->macl = (INT16) sh2->r[8] * (INT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op28EF:
{
	sh2->macl = (INT16) sh2->r[8] * (INT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op28FF:
{
	sh2->macl = (INT16) sh2->r[8] * (INT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op290F:
{
	sh2->macl = (INT16) sh2->r[9] * (INT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op291F:
{
	sh2->macl = (INT16) sh2->r[9] * (INT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op292F:
{
	sh2->macl = (INT16) sh2->r[9] * (INT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op293F:
{
	sh2->macl = (INT16) sh2->r[9] * (INT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op294F:
{
	sh2->macl = (INT16) sh2->r[9] * (INT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op295F:
{
	sh2->macl = (INT16) sh2->r[9] * (INT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op296F:
{
	sh2->macl = (INT16) sh2->r[9] * (INT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op297F:
{
	sh2->macl = (INT16) sh2->r[9] * (INT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op298F:
{
	sh2->macl = (INT16) sh2->r[9] * (INT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op299F:
{
	sh2->macl = (INT16) sh2->r[9] * (INT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op29AF:
{
	sh2->macl = (INT16) sh2->r[9] * (INT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op29BF:
{
	sh2->macl = (INT16) sh2->r[9] * (INT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op29CF:
{
	sh2->macl = (INT16) sh2->r[9] * (INT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op29DF:
{
	sh2->macl = (INT16) sh2->r[9] * (INT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op29EF:
{
	sh2->macl = (INT16) sh2->r[9] * (INT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op29FF:
{
	sh2->macl = (INT16) sh2->r[9] * (INT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2A0F:
{
	sh2->macl = (INT16) sh2->r[10] * (INT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2A1F:
{
	sh2->macl = (INT16) sh2->r[10] * (INT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2A2F:
{
	sh2->macl = (INT16) sh2->r[10] * (INT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2A3F:
{
	sh2->macl = (INT16) sh2->r[10] * (INT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2A4F:
{
	sh2->macl = (INT16) sh2->r[10] * (INT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2A5F:
{
	sh2->macl = (INT16) sh2->r[10] * (INT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2A6F:
{
	sh2->macl = (INT16) sh2->r[10] * (INT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2A7F:
{
	sh2->macl = (INT16) sh2->r[10] * (INT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2A8F:
{
	sh2->macl = (INT16) sh2->r[10] * (INT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2A9F:
{
	sh2->macl = (INT16) sh2->r[10] * (INT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2AAF:
{
	sh2->macl = (INT16) sh2->r[10] * (INT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2ABF:
{
	sh2->macl = (INT16) sh2->r[10] * (INT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2ACF:
{
	sh2->macl = (INT16) sh2->r[10] * (INT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2ADF:
{
	sh2->macl = (INT16) sh2->r[10] * (INT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2AEF:
{
	sh2->macl = (INT16) sh2->r[10] * (INT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2AFF:
{
	sh2->macl = (INT16) sh2->r[10] * (INT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2B0F:
{
	sh2->macl = (INT16) sh2->r[11] * (INT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2B1F:
{
	sh2->macl = (INT16) sh2->r[11] * (INT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2B2F:
{
	sh2->macl = (INT16) sh2->r[11] * (INT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2B3F:
{
	sh2->macl = (INT16) sh2->r[11] * (INT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2B4F:
{
	sh2->macl = (INT16) sh2->r[11] * (INT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2B5F:
{
	sh2->macl = (INT16) sh2->r[11] * (INT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2B6F:
{
	sh2->macl = (INT16) sh2->r[11] * (INT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2B7F:
{
	sh2->macl = (INT16) sh2->r[11] * (INT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2B8F:
{
	sh2->macl = (INT16) sh2->r[11] * (INT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2B9F:
{
	sh2->macl = (INT16) sh2->r[11] * (INT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2BAF:
{
	sh2->macl = (INT16) sh2->r[11] * (INT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2BBF:
{
	sh2->macl = (INT16) sh2->r[11] * (INT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2BCF:
{
	sh2->macl = (INT16) sh2->r[11] * (INT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2BDF:
{
	sh2->macl = (INT16) sh2->r[11] * (INT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2BEF:
{
	sh2->macl = (INT16) sh2->r[11] * (INT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2BFF:
{
	sh2->macl = (INT16) sh2->r[11] * (INT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2C0F:
{
	sh2->macl = (INT16) sh2->r[12] * (INT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2C1F:
{
	sh2->macl = (INT16) sh2->r[12] * (INT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2C2F:
{
	sh2->macl = (INT16) sh2->r[12] * (INT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2C3F:
{
	sh2->macl = (INT16) sh2->r[12] * (INT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2C4F:
{
	sh2->macl = (INT16) sh2->r[12] * (INT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2C5F:
{
	sh2->macl = (INT16) sh2->r[12] * (INT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2C6F:
{
	sh2->macl = (INT16) sh2->r[12] * (INT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2C7F:
{
	sh2->macl = (INT16) sh2->r[12] * (INT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2C8F:
{
	sh2->macl = (INT16) sh2->r[12] * (INT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2C9F:
{
	sh2->macl = (INT16) sh2->r[12] * (INT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2CAF:
{
	sh2->macl = (INT16) sh2->r[12] * (INT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2CBF:
{
	sh2->macl = (INT16) sh2->r[12] * (INT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2CCF:
{
	sh2->macl = (INT16) sh2->r[12] * (INT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2CDF:
{
	sh2->macl = (INT16) sh2->r[12] * (INT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2CEF:
{
	sh2->macl = (INT16) sh2->r[12] * (INT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2CFF:
{
	sh2->macl = (INT16) sh2->r[12] * (INT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2D0F:
{
	sh2->macl = (INT16) sh2->r[13] * (INT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2D1F:
{
	sh2->macl = (INT16) sh2->r[13] * (INT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2D2F:
{
	sh2->macl = (INT16) sh2->r[13] * (INT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2D3F:
{
	sh2->macl = (INT16) sh2->r[13] * (INT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2D4F:
{
	sh2->macl = (INT16) sh2->r[13] * (INT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2D5F:
{
	sh2->macl = (INT16) sh2->r[13] * (INT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2D6F:
{
	sh2->macl = (INT16) sh2->r[13] * (INT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2D7F:
{
	sh2->macl = (INT16) sh2->r[13] * (INT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2D8F:
{
	sh2->macl = (INT16) sh2->r[13] * (INT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2D9F:
{
	sh2->macl = (INT16) sh2->r[13] * (INT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2DAF:
{
	sh2->macl = (INT16) sh2->r[13] * (INT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2DBF:
{
	sh2->macl = (INT16) sh2->r[13] * (INT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2DCF:
{
	sh2->macl = (INT16) sh2->r[13] * (INT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2DDF:
{
	sh2->macl = (INT16) sh2->r[13] * (INT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2DEF:
{
	sh2->macl = (INT16) sh2->r[13] * (INT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2DFF:
{
	sh2->macl = (INT16) sh2->r[13] * (INT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2E0F:
{
	sh2->macl = (INT16) sh2->r[14] * (INT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2E1F:
{
	sh2->macl = (INT16) sh2->r[14] * (INT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2E2F:
{
	sh2->macl = (INT16) sh2->r[14] * (INT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2E3F:
{
	sh2->macl = (INT16) sh2->r[14] * (INT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2E4F:
{
	sh2->macl = (INT16) sh2->r[14] * (INT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2E5F:
{
	sh2->macl = (INT16) sh2->r[14] * (INT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2E6F:
{
	sh2->macl = (INT16) sh2->r[14] * (INT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2E7F:
{
	sh2->macl = (INT16) sh2->r[14] * (INT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2E8F:
{
	sh2->macl = (INT16) sh2->r[14] * (INT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2E9F:
{
	sh2->macl = (INT16) sh2->r[14] * (INT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2EAF:
{
	sh2->macl = (INT16) sh2->r[14] * (INT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2EBF:
{
	sh2->macl = (INT16) sh2->r[14] * (INT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2ECF:
{
	sh2->macl = (INT16) sh2->r[14] * (INT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2EDF:
{
	sh2->macl = (INT16) sh2->r[14] * (INT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2EEF:
{
	sh2->macl = (INT16) sh2->r[14] * (INT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2EFF:
{
	sh2->macl = (INT16) sh2->r[14] * (INT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op2F0F:
{
	sh2->macl = (INT16) sh2->r[15] * (INT16) sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op2F1F:
{
	sh2->macl = (INT16) sh2->r[15] * (INT16) sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op2F2F:
{
	sh2->macl = (INT16) sh2->r[15] * (INT16) sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op2F3F:
{
	sh2->macl = (INT16) sh2->r[15] * (INT16) sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op2F4F:
{
	sh2->macl = (INT16) sh2->r[15] * (INT16) sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op2F5F:
{
	sh2->macl = (INT16) sh2->r[15] * (INT16) sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op2F6F:
{
	sh2->macl = (INT16) sh2->r[15] * (INT16) sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op2F7F:
{
	sh2->macl = (INT16) sh2->r[15] * (INT16) sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op2F8F:
{
	sh2->macl = (INT16) sh2->r[15] * (INT16) sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op2F9F:
{
	sh2->macl = (INT16) sh2->r[15] * (INT16) sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op2FAF:
{
	sh2->macl = (INT16) sh2->r[15] * (INT16) sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op2FBF:
{
	sh2->macl = (INT16) sh2->r[15] * (INT16) sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op2FCF:
{
	sh2->macl = (INT16) sh2->r[15] * (INT16) sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op2FDF:
{
	sh2->macl = (INT16) sh2->r[15] * (INT16) sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op2FEF:
{
	sh2->macl = (INT16) sh2->r[15] * (INT16) sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op2FFF:
{
	sh2->macl = (INT16) sh2->r[15] * (INT16) sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

// CMP_EQ Rm,Rn
Op3000:
{
	if (sh2->r[0] == sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3010:
{
	if (sh2->r[0] == sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3020:
{
	if (sh2->r[0] == sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3030:
{
	if (sh2->r[0] == sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3040:
{
	if (sh2->r[0] == sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3050:
{
	if (sh2->r[0] == sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3060:
{
	if (sh2->r[0] == sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3070:
{
	if (sh2->r[0] == sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3080:
{
	if (sh2->r[0] == sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3090:
{
	if (sh2->r[0] == sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30A0:
{
	if (sh2->r[0] == sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30B0:
{
	if (sh2->r[0] == sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30C0:
{
	if (sh2->r[0] == sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30D0:
{
	if (sh2->r[0] == sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30E0:
{
	if (sh2->r[0] == sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30F0:
{
	if (sh2->r[0] == sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3100:
{
	if (sh2->r[1] == sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3110:
{
	if (sh2->r[1] == sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3120:
{
	if (sh2->r[1] == sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3130:
{
	if (sh2->r[1] == sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3140:
{
	if (sh2->r[1] == sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3150:
{
	if (sh2->r[1] == sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3160:
{
	if (sh2->r[1] == sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3170:
{
	if (sh2->r[1] == sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3180:
{
	if (sh2->r[1] == sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3190:
{
	if (sh2->r[1] == sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31A0:
{
	if (sh2->r[1] == sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31B0:
{
	if (sh2->r[1] == sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31C0:
{
	if (sh2->r[1] == sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31D0:
{
	if (sh2->r[1] == sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31E0:
{
	if (sh2->r[1] == sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31F0:
{
	if (sh2->r[1] == sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3200:
{
	if (sh2->r[2] == sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3210:
{
	if (sh2->r[2] == sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3220:
{
	if (sh2->r[2] == sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3230:
{
	if (sh2->r[2] == sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3240:
{
	if (sh2->r[2] == sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3250:
{
	if (sh2->r[2] == sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3260:
{
	if (sh2->r[2] == sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3270:
{
	if (sh2->r[2] == sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3280:
{
	if (sh2->r[2] == sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3290:
{
	if (sh2->r[2] == sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32A0:
{
	if (sh2->r[2] == sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32B0:
{
	if (sh2->r[2] == sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32C0:
{
	if (sh2->r[2] == sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32D0:
{
	if (sh2->r[2] == sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32E0:
{
	if (sh2->r[2] == sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32F0:
{
	if (sh2->r[2] == sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3300:
{
	if (sh2->r[3] == sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3310:
{
	if (sh2->r[3] == sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3320:
{
	if (sh2->r[3] == sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3330:
{
	if (sh2->r[3] == sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3340:
{
	if (sh2->r[3] == sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3350:
{
	if (sh2->r[3] == sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3360:
{
	if (sh2->r[3] == sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3370:
{
	if (sh2->r[3] == sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3380:
{
	if (sh2->r[3] == sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3390:
{
	if (sh2->r[3] == sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33A0:
{
	if (sh2->r[3] == sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33B0:
{
	if (sh2->r[3] == sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33C0:
{
	if (sh2->r[3] == sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33D0:
{
	if (sh2->r[3] == sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33E0:
{
	if (sh2->r[3] == sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33F0:
{
	if (sh2->r[3] == sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3400:
{
	if (sh2->r[4] == sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3410:
{
	if (sh2->r[4] == sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3420:
{
	if (sh2->r[4] == sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3430:
{
	if (sh2->r[4] == sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3440:
{
	if (sh2->r[4] == sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3450:
{
	if (sh2->r[4] == sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3460:
{
	if (sh2->r[4] == sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3470:
{
	if (sh2->r[4] == sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3480:
{
	if (sh2->r[4] == sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3490:
{
	if (sh2->r[4] == sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34A0:
{
	if (sh2->r[4] == sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34B0:
{
	if (sh2->r[4] == sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34C0:
{
	if (sh2->r[4] == sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34D0:
{
	if (sh2->r[4] == sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34E0:
{
	if (sh2->r[4] == sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34F0:
{
	if (sh2->r[4] == sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3500:
{
	if (sh2->r[5] == sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3510:
{
	if (sh2->r[5] == sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3520:
{
	if (sh2->r[5] == sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3530:
{
	if (sh2->r[5] == sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3540:
{
	if (sh2->r[5] == sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3550:
{
	if (sh2->r[5] == sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3560:
{
	if (sh2->r[5] == sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3570:
{
	if (sh2->r[5] == sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3580:
{
	if (sh2->r[5] == sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3590:
{
	if (sh2->r[5] == sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35A0:
{
	if (sh2->r[5] == sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35B0:
{
	if (sh2->r[5] == sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35C0:
{
	if (sh2->r[5] == sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35D0:
{
	if (sh2->r[5] == sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35E0:
{
	if (sh2->r[5] == sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35F0:
{
	if (sh2->r[5] == sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3600:
{
	if (sh2->r[6] == sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3610:
{
	if (sh2->r[6] == sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3620:
{
	if (sh2->r[6] == sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3630:
{
	if (sh2->r[6] == sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3640:
{
	if (sh2->r[6] == sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3650:
{
	if (sh2->r[6] == sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3660:
{
	if (sh2->r[6] == sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3670:
{
	if (sh2->r[6] == sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3680:
{
	if (sh2->r[6] == sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3690:
{
	if (sh2->r[6] == sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36A0:
{
	if (sh2->r[6] == sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36B0:
{
	if (sh2->r[6] == sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36C0:
{
	if (sh2->r[6] == sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36D0:
{
	if (sh2->r[6] == sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36E0:
{
	if (sh2->r[6] == sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36F0:
{
	if (sh2->r[6] == sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3700:
{
	if (sh2->r[7] == sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3710:
{
	if (sh2->r[7] == sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3720:
{
	if (sh2->r[7] == sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3730:
{
	if (sh2->r[7] == sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3740:
{
	if (sh2->r[7] == sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3750:
{
	if (sh2->r[7] == sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3760:
{
	if (sh2->r[7] == sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3770:
{
	if (sh2->r[7] == sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3780:
{
	if (sh2->r[7] == sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3790:
{
	if (sh2->r[7] == sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37A0:
{
	if (sh2->r[7] == sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37B0:
{
	if (sh2->r[7] == sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37C0:
{
	if (sh2->r[7] == sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37D0:
{
	if (sh2->r[7] == sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37E0:
{
	if (sh2->r[7] == sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37F0:
{
	if (sh2->r[7] == sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3800:
{
	if (sh2->r[8] == sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3810:
{
	if (sh2->r[8] == sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3820:
{
	if (sh2->r[8] == sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3830:
{
	if (sh2->r[8] == sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3840:
{
	if (sh2->r[8] == sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3850:
{
	if (sh2->r[8] == sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3860:
{
	if (sh2->r[8] == sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3870:
{
	if (sh2->r[8] == sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3880:
{
	if (sh2->r[8] == sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3890:
{
	if (sh2->r[8] == sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38A0:
{
	if (sh2->r[8] == sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38B0:
{
	if (sh2->r[8] == sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38C0:
{
	if (sh2->r[8] == sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38D0:
{
	if (sh2->r[8] == sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38E0:
{
	if (sh2->r[8] == sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38F0:
{
	if (sh2->r[8] == sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3900:
{
	if (sh2->r[9] == sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3910:
{
	if (sh2->r[9] == sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3920:
{
	if (sh2->r[9] == sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3930:
{
	if (sh2->r[9] == sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3940:
{
	if (sh2->r[9] == sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3950:
{
	if (sh2->r[9] == sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3960:
{
	if (sh2->r[9] == sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3970:
{
	if (sh2->r[9] == sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3980:
{
	if (sh2->r[9] == sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3990:
{
	if (sh2->r[9] == sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39A0:
{
	if (sh2->r[9] == sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39B0:
{
	if (sh2->r[9] == sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39C0:
{
	if (sh2->r[9] == sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39D0:
{
	if (sh2->r[9] == sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39E0:
{
	if (sh2->r[9] == sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39F0:
{
	if (sh2->r[9] == sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A00:
{
	if (sh2->r[10] == sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A10:
{
	if (sh2->r[10] == sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A20:
{
	if (sh2->r[10] == sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A30:
{
	if (sh2->r[10] == sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A40:
{
	if (sh2->r[10] == sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A50:
{
	if (sh2->r[10] == sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A60:
{
	if (sh2->r[10] == sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A70:
{
	if (sh2->r[10] == sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A80:
{
	if (sh2->r[10] == sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A90:
{
	if (sh2->r[10] == sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AA0:
{
	if (sh2->r[10] == sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AB0:
{
	if (sh2->r[10] == sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AC0:
{
	if (sh2->r[10] == sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AD0:
{
	if (sh2->r[10] == sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AE0:
{
	if (sh2->r[10] == sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AF0:
{
	if (sh2->r[10] == sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B00:
{
	if (sh2->r[11] == sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B10:
{
	if (sh2->r[11] == sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B20:
{
	if (sh2->r[11] == sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B30:
{
	if (sh2->r[11] == sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B40:
{
	if (sh2->r[11] == sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B50:
{
	if (sh2->r[11] == sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B60:
{
	if (sh2->r[11] == sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B70:
{
	if (sh2->r[11] == sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B80:
{
	if (sh2->r[11] == sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B90:
{
	if (sh2->r[11] == sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BA0:
{
	if (sh2->r[11] == sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BB0:
{
	if (sh2->r[11] == sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BC0:
{
	if (sh2->r[11] == sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BD0:
{
	if (sh2->r[11] == sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BE0:
{
	if (sh2->r[11] == sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BF0:
{
	if (sh2->r[11] == sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C00:
{
	if (sh2->r[12] == sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C10:
{
	if (sh2->r[12] == sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C20:
{
	if (sh2->r[12] == sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C30:
{
	if (sh2->r[12] == sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C40:
{
	if (sh2->r[12] == sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C50:
{
	if (sh2->r[12] == sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C60:
{
	if (sh2->r[12] == sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C70:
{
	if (sh2->r[12] == sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C80:
{
	if (sh2->r[12] == sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C90:
{
	if (sh2->r[12] == sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CA0:
{
	if (sh2->r[12] == sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CB0:
{
	if (sh2->r[12] == sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CC0:
{
	if (sh2->r[12] == sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CD0:
{
	if (sh2->r[12] == sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CE0:
{
	if (sh2->r[12] == sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CF0:
{
	if (sh2->r[12] == sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D00:
{
	if (sh2->r[13] == sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D10:
{
	if (sh2->r[13] == sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D20:
{
	if (sh2->r[13] == sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D30:
{
	if (sh2->r[13] == sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D40:
{
	if (sh2->r[13] == sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D50:
{
	if (sh2->r[13] == sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D60:
{
	if (sh2->r[13] == sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D70:
{
	if (sh2->r[13] == sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D80:
{
	if (sh2->r[13] == sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D90:
{
	if (sh2->r[13] == sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DA0:
{
	if (sh2->r[13] == sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DB0:
{
	if (sh2->r[13] == sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DC0:
{
	if (sh2->r[13] == sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DD0:
{
	if (sh2->r[13] == sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DE0:
{
	if (sh2->r[13] == sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DF0:
{
	if (sh2->r[13] == sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E00:
{
	if (sh2->r[14] == sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E10:
{
	if (sh2->r[14] == sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E20:
{
	if (sh2->r[14] == sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E30:
{
	if (sh2->r[14] == sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E40:
{
	if (sh2->r[14] == sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E50:
{
	if (sh2->r[14] == sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E60:
{
	if (sh2->r[14] == sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E70:
{
	if (sh2->r[14] == sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E80:
{
	if (sh2->r[14] == sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E90:
{
	if (sh2->r[14] == sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3EA0:
{
	if (sh2->r[14] == sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3EB0:
{
	if (sh2->r[14] == sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3EC0:
{
	if (sh2->r[14] == sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3ED0:
{
	if (sh2->r[14] == sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3EE0:
{
	if (sh2->r[14] == sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3EF0:
{
	if (sh2->r[14] == sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F00:
{
	if (sh2->r[15] == sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F10:
{
	if (sh2->r[15] == sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F20:
{
	if (sh2->r[15] == sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F30:
{
	if (sh2->r[15] == sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F40:
{
	if (sh2->r[15] == sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F50:
{
	if (sh2->r[15] == sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F60:
{
	if (sh2->r[15] == sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F70:
{
	if (sh2->r[15] == sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F80:
{
	if (sh2->r[15] == sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F90:
{
	if (sh2->r[15] == sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FA0:
{
	if (sh2->r[15] == sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FB0:
{
	if (sh2->r[15] == sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FC0:
{
	if (sh2->r[15] == sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FD0:
{
	if (sh2->r[15] == sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FE0:
{
	if (sh2->r[15] == sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FF0:
{
	if (sh2->r[15] == sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

// CMP_HS Rm,Rn
Op3002:
{
	if ((UINT32) sh2->r[0] >= (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3012:
{
	if ((UINT32) sh2->r[0] >= (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3022:
{
	if ((UINT32) sh2->r[0] >= (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3032:
{
	if ((UINT32) sh2->r[0] >= (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3042:
{
	if ((UINT32) sh2->r[0] >= (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3052:
{
	if ((UINT32) sh2->r[0] >= (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3062:
{
	if ((UINT32) sh2->r[0] >= (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3072:
{
	if ((UINT32) sh2->r[0] >= (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3082:
{
	if ((UINT32) sh2->r[0] >= (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3092:
{
	if ((UINT32) sh2->r[0] >= (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30A2:
{
	if ((UINT32) sh2->r[0] >= (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30B2:
{
	if ((UINT32) sh2->r[0] >= (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30C2:
{
	if ((UINT32) sh2->r[0] >= (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30D2:
{
	if ((UINT32) sh2->r[0] >= (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30E2:
{
	if ((UINT32) sh2->r[0] >= (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30F2:
{
	if ((UINT32) sh2->r[0] >= (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3102:
{
	if ((UINT32) sh2->r[1] >= (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3112:
{
	if ((UINT32) sh2->r[1] >= (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3122:
{
	if ((UINT32) sh2->r[1] >= (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3132:
{
	if ((UINT32) sh2->r[1] >= (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3142:
{
	if ((UINT32) sh2->r[1] >= (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3152:
{
	if ((UINT32) sh2->r[1] >= (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3162:
{
	if ((UINT32) sh2->r[1] >= (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3172:
{
	if ((UINT32) sh2->r[1] >= (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3182:
{
	if ((UINT32) sh2->r[1] >= (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3192:
{
	if ((UINT32) sh2->r[1] >= (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31A2:
{
	if ((UINT32) sh2->r[1] >= (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31B2:
{
	if ((UINT32) sh2->r[1] >= (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31C2:
{
	if ((UINT32) sh2->r[1] >= (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31D2:
{
	if ((UINT32) sh2->r[1] >= (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31E2:
{
	if ((UINT32) sh2->r[1] >= (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31F2:
{
	if ((UINT32) sh2->r[1] >= (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3202:
{
	if ((UINT32) sh2->r[2] >= (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3212:
{
	if ((UINT32) sh2->r[2] >= (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3222:
{
	if ((UINT32) sh2->r[2] >= (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3232:
{
	if ((UINT32) sh2->r[2] >= (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3242:
{
	if ((UINT32) sh2->r[2] >= (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3252:
{
	if ((UINT32) sh2->r[2] >= (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3262:
{
	if ((UINT32) sh2->r[2] >= (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3272:
{
	if ((UINT32) sh2->r[2] >= (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3282:
{
	if ((UINT32) sh2->r[2] >= (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3292:
{
	if ((UINT32) sh2->r[2] >= (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32A2:
{
	if ((UINT32) sh2->r[2] >= (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32B2:
{
	if ((UINT32) sh2->r[2] >= (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32C2:
{
	if ((UINT32) sh2->r[2] >= (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32D2:
{
	if ((UINT32) sh2->r[2] >= (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32E2:
{
	if ((UINT32) sh2->r[2] >= (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32F2:
{
	if ((UINT32) sh2->r[2] >= (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3302:
{
	if ((UINT32) sh2->r[3] >= (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3312:
{
	if ((UINT32) sh2->r[3] >= (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3322:
{
	if ((UINT32) sh2->r[3] >= (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3332:
{
	if ((UINT32) sh2->r[3] >= (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3342:
{
	if ((UINT32) sh2->r[3] >= (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3352:
{
	if ((UINT32) sh2->r[3] >= (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3362:
{
	if ((UINT32) sh2->r[3] >= (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3372:
{
	if ((UINT32) sh2->r[3] >= (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3382:
{
	if ((UINT32) sh2->r[3] >= (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3392:
{
	if ((UINT32) sh2->r[3] >= (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33A2:
{
	if ((UINT32) sh2->r[3] >= (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33B2:
{
	if ((UINT32) sh2->r[3] >= (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33C2:
{
	if ((UINT32) sh2->r[3] >= (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33D2:
{
	if ((UINT32) sh2->r[3] >= (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33E2:
{
	if ((UINT32) sh2->r[3] >= (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33F2:
{
	if ((UINT32) sh2->r[3] >= (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3402:
{
	if ((UINT32) sh2->r[4] >= (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3412:
{
	if ((UINT32) sh2->r[4] >= (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3422:
{
	if ((UINT32) sh2->r[4] >= (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3432:
{
	if ((UINT32) sh2->r[4] >= (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3442:
{
	if ((UINT32) sh2->r[4] >= (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3452:
{
	if ((UINT32) sh2->r[4] >= (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3462:
{
	if ((UINT32) sh2->r[4] >= (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3472:
{
	if ((UINT32) sh2->r[4] >= (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3482:
{
	if ((UINT32) sh2->r[4] >= (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3492:
{
	if ((UINT32) sh2->r[4] >= (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34A2:
{
	if ((UINT32) sh2->r[4] >= (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34B2:
{
	if ((UINT32) sh2->r[4] >= (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34C2:
{
	if ((UINT32) sh2->r[4] >= (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34D2:
{
	if ((UINT32) sh2->r[4] >= (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34E2:
{
	if ((UINT32) sh2->r[4] >= (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34F2:
{
	if ((UINT32) sh2->r[4] >= (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3502:
{
	if ((UINT32) sh2->r[5] >= (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3512:
{
	if ((UINT32) sh2->r[5] >= (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3522:
{
	if ((UINT32) sh2->r[5] >= (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3532:
{
	if ((UINT32) sh2->r[5] >= (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3542:
{
	if ((UINT32) sh2->r[5] >= (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3552:
{
	if ((UINT32) sh2->r[5] >= (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3562:
{
	if ((UINT32) sh2->r[5] >= (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3572:
{
	if ((UINT32) sh2->r[5] >= (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3582:
{
	if ((UINT32) sh2->r[5] >= (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3592:
{
	if ((UINT32) sh2->r[5] >= (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35A2:
{
	if ((UINT32) sh2->r[5] >= (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35B2:
{
	if ((UINT32) sh2->r[5] >= (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35C2:
{
	if ((UINT32) sh2->r[5] >= (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35D2:
{
	if ((UINT32) sh2->r[5] >= (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35E2:
{
	if ((UINT32) sh2->r[5] >= (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35F2:
{
	if ((UINT32) sh2->r[5] >= (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3602:
{
	if ((UINT32) sh2->r[6] >= (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3612:
{
	if ((UINT32) sh2->r[6] >= (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3622:
{
	if ((UINT32) sh2->r[6] >= (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3632:
{
	if ((UINT32) sh2->r[6] >= (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3642:
{
	if ((UINT32) sh2->r[6] >= (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3652:
{
	if ((UINT32) sh2->r[6] >= (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3662:
{
	if ((UINT32) sh2->r[6] >= (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3672:
{
	if ((UINT32) sh2->r[6] >= (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3682:
{
	if ((UINT32) sh2->r[6] >= (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3692:
{
	if ((UINT32) sh2->r[6] >= (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36A2:
{
	if ((UINT32) sh2->r[6] >= (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36B2:
{
	if ((UINT32) sh2->r[6] >= (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36C2:
{
	if ((UINT32) sh2->r[6] >= (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36D2:
{
	if ((UINT32) sh2->r[6] >= (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36E2:
{
	if ((UINT32) sh2->r[6] >= (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36F2:
{
	if ((UINT32) sh2->r[6] >= (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3702:
{
	if ((UINT32) sh2->r[7] >= (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3712:
{
	if ((UINT32) sh2->r[7] >= (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3722:
{
	if ((UINT32) sh2->r[7] >= (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3732:
{
	if ((UINT32) sh2->r[7] >= (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3742:
{
	if ((UINT32) sh2->r[7] >= (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3752:
{
	if ((UINT32) sh2->r[7] >= (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3762:
{
	if ((UINT32) sh2->r[7] >= (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3772:
{
	if ((UINT32) sh2->r[7] >= (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3782:
{
	if ((UINT32) sh2->r[7] >= (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3792:
{
	if ((UINT32) sh2->r[7] >= (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37A2:
{
	if ((UINT32) sh2->r[7] >= (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37B2:
{
	if ((UINT32) sh2->r[7] >= (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37C2:
{
	if ((UINT32) sh2->r[7] >= (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37D2:
{
	if ((UINT32) sh2->r[7] >= (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37E2:
{
	if ((UINT32) sh2->r[7] >= (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37F2:
{
	if ((UINT32) sh2->r[7] >= (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3802:
{
	if ((UINT32) sh2->r[8] >= (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3812:
{
	if ((UINT32) sh2->r[8] >= (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3822:
{
	if ((UINT32) sh2->r[8] >= (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3832:
{
	if ((UINT32) sh2->r[8] >= (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3842:
{
	if ((UINT32) sh2->r[8] >= (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3852:
{
	if ((UINT32) sh2->r[8] >= (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3862:
{
	if ((UINT32) sh2->r[8] >= (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3872:
{
	if ((UINT32) sh2->r[8] >= (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3882:
{
	if ((UINT32) sh2->r[8] >= (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3892:
{
	if ((UINT32) sh2->r[8] >= (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38A2:
{
	if ((UINT32) sh2->r[8] >= (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38B2:
{
	if ((UINT32) sh2->r[8] >= (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38C2:
{
	if ((UINT32) sh2->r[8] >= (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38D2:
{
	if ((UINT32) sh2->r[8] >= (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38E2:
{
	if ((UINT32) sh2->r[8] >= (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38F2:
{
	if ((UINT32) sh2->r[8] >= (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3902:
{
	if ((UINT32) sh2->r[9] >= (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3912:
{
	if ((UINT32) sh2->r[9] >= (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3922:
{
	if ((UINT32) sh2->r[9] >= (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3932:
{
	if ((UINT32) sh2->r[9] >= (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3942:
{
	if ((UINT32) sh2->r[9] >= (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3952:
{
	if ((UINT32) sh2->r[9] >= (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3962:
{
	if ((UINT32) sh2->r[9] >= (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3972:
{
	if ((UINT32) sh2->r[9] >= (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3982:
{
	if ((UINT32) sh2->r[9] >= (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3992:
{
	if ((UINT32) sh2->r[9] >= (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39A2:
{
	if ((UINT32) sh2->r[9] >= (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39B2:
{
	if ((UINT32) sh2->r[9] >= (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39C2:
{
	if ((UINT32) sh2->r[9] >= (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39D2:
{
	if ((UINT32) sh2->r[9] >= (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39E2:
{
	if ((UINT32) sh2->r[9] >= (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39F2:
{
	if ((UINT32) sh2->r[9] >= (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A02:
{
	if ((UINT32) sh2->r[10] >= (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A12:
{
	if ((UINT32) sh2->r[10] >= (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A22:
{
	if ((UINT32) sh2->r[10] >= (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A32:
{
	if ((UINT32) sh2->r[10] >= (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A42:
{
	if ((UINT32) sh2->r[10] >= (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A52:
{
	if ((UINT32) sh2->r[10] >= (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A62:
{
	if ((UINT32) sh2->r[10] >= (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A72:
{
	if ((UINT32) sh2->r[10] >= (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A82:
{
	if ((UINT32) sh2->r[10] >= (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A92:
{
	if ((UINT32) sh2->r[10] >= (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AA2:
{
	if ((UINT32) sh2->r[10] >= (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AB2:
{
	if ((UINT32) sh2->r[10] >= (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AC2:
{
	if ((UINT32) sh2->r[10] >= (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AD2:
{
	if ((UINT32) sh2->r[10] >= (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AE2:
{
	if ((UINT32) sh2->r[10] >= (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AF2:
{
	if ((UINT32) sh2->r[10] >= (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B02:
{
	if ((UINT32) sh2->r[11] >= (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B12:
{
	if ((UINT32) sh2->r[11] >= (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B22:
{
	if ((UINT32) sh2->r[11] >= (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B32:
{
	if ((UINT32) sh2->r[11] >= (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B42:
{
	if ((UINT32) sh2->r[11] >= (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B52:
{
	if ((UINT32) sh2->r[11] >= (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B62:
{
	if ((UINT32) sh2->r[11] >= (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B72:
{
	if ((UINT32) sh2->r[11] >= (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B82:
{
	if ((UINT32) sh2->r[11] >= (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B92:
{
	if ((UINT32) sh2->r[11] >= (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BA2:
{
	if ((UINT32) sh2->r[11] >= (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BB2:
{
	if ((UINT32) sh2->r[11] >= (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BC2:
{
	if ((UINT32) sh2->r[11] >= (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BD2:
{
	if ((UINT32) sh2->r[11] >= (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BE2:
{
	if ((UINT32) sh2->r[11] >= (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BF2:
{
	if ((UINT32) sh2->r[11] >= (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C02:
{
	if ((UINT32) sh2->r[12] >= (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C12:
{
	if ((UINT32) sh2->r[12] >= (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C22:
{
	if ((UINT32) sh2->r[12] >= (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C32:
{
	if ((UINT32) sh2->r[12] >= (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C42:
{
	if ((UINT32) sh2->r[12] >= (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C52:
{
	if ((UINT32) sh2->r[12] >= (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C62:
{
	if ((UINT32) sh2->r[12] >= (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C72:
{
	if ((UINT32) sh2->r[12] >= (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C82:
{
	if ((UINT32) sh2->r[12] >= (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C92:
{
	if ((UINT32) sh2->r[12] >= (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CA2:
{
	if ((UINT32) sh2->r[12] >= (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CB2:
{
	if ((UINT32) sh2->r[12] >= (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CC2:
{
	if ((UINT32) sh2->r[12] >= (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CD2:
{
	if ((UINT32) sh2->r[12] >= (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CE2:
{
	if ((UINT32) sh2->r[12] >= (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CF2:
{
	if ((UINT32) sh2->r[12] >= (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D02:
{
	if ((UINT32) sh2->r[13] >= (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D12:
{
	if ((UINT32) sh2->r[13] >= (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D22:
{
	if ((UINT32) sh2->r[13] >= (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D32:
{
	if ((UINT32) sh2->r[13] >= (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D42:
{
	if ((UINT32) sh2->r[13] >= (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D52:
{
	if ((UINT32) sh2->r[13] >= (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D62:
{
	if ((UINT32) sh2->r[13] >= (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D72:
{
	if ((UINT32) sh2->r[13] >= (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D82:
{
	if ((UINT32) sh2->r[13] >= (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D92:
{
	if ((UINT32) sh2->r[13] >= (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DA2:
{
	if ((UINT32) sh2->r[13] >= (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DB2:
{
	if ((UINT32) sh2->r[13] >= (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DC2:
{
	if ((UINT32) sh2->r[13] >= (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DD2:
{
	if ((UINT32) sh2->r[13] >= (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DE2:
{
	if ((UINT32) sh2->r[13] >= (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DF2:
{
	if ((UINT32) sh2->r[13] >= (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E02:
{
	if ((UINT32) sh2->r[14] >= (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E12:
{
	if ((UINT32) sh2->r[14] >= (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E22:
{
	if ((UINT32) sh2->r[14] >= (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E32:
{
	if ((UINT32) sh2->r[14] >= (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E42:
{
	if ((UINT32) sh2->r[14] >= (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E52:
{
	if ((UINT32) sh2->r[14] >= (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E62:
{
	if ((UINT32) sh2->r[14] >= (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E72:
{
	if ((UINT32) sh2->r[14] >= (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E82:
{
	if ((UINT32) sh2->r[14] >= (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E92:
{
	if ((UINT32) sh2->r[14] >= (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3EA2:
{
	if ((UINT32) sh2->r[14] >= (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3EB2:
{
	if ((UINT32) sh2->r[14] >= (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3EC2:
{
	if ((UINT32) sh2->r[14] >= (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3ED2:
{
	if ((UINT32) sh2->r[14] >= (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3EE2:
{
	if ((UINT32) sh2->r[14] >= (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3EF2:
{
	if ((UINT32) sh2->r[14] >= (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F02:
{
	if ((UINT32) sh2->r[15] >= (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F12:
{
	if ((UINT32) sh2->r[15] >= (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F22:
{
	if ((UINT32) sh2->r[15] >= (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F32:
{
	if ((UINT32) sh2->r[15] >= (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F42:
{
	if ((UINT32) sh2->r[15] >= (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F52:
{
	if ((UINT32) sh2->r[15] >= (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F62:
{
	if ((UINT32) sh2->r[15] >= (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F72:
{
	if ((UINT32) sh2->r[15] >= (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F82:
{
	if ((UINT32) sh2->r[15] >= (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F92:
{
	if ((UINT32) sh2->r[15] >= (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FA2:
{
	if ((UINT32) sh2->r[15] >= (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FB2:
{
	if ((UINT32) sh2->r[15] >= (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FC2:
{
	if ((UINT32) sh2->r[15] >= (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FD2:
{
	if ((UINT32) sh2->r[15] >= (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FE2:
{
	if ((UINT32) sh2->r[15] >= (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FF2:
{
	if ((UINT32) sh2->r[15] >= (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

// CMP_GE Rm,Rn
Op3003:
{
	if ((INT32) sh2->r[0] >= (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3013:
{
	if ((INT32) sh2->r[0] >= (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3023:
{
	if ((INT32) sh2->r[0] >= (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3033:
{
	if ((INT32) sh2->r[0] >= (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3043:
{
	if ((INT32) sh2->r[0] >= (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3053:
{
	if ((INT32) sh2->r[0] >= (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3063:
{
	if ((INT32) sh2->r[0] >= (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3073:
{
	if ((INT32) sh2->r[0] >= (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3083:
{
	if ((INT32) sh2->r[0] >= (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3093:
{
	if ((INT32) sh2->r[0] >= (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30A3:
{
	if ((INT32) sh2->r[0] >= (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30B3:
{
	if ((INT32) sh2->r[0] >= (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30C3:
{
	if ((INT32) sh2->r[0] >= (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30D3:
{
	if ((INT32) sh2->r[0] >= (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30E3:
{
	if ((INT32) sh2->r[0] >= (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30F3:
{
	if ((INT32) sh2->r[0] >= (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3103:
{
	if ((INT32) sh2->r[1] >= (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3113:
{
	if ((INT32) sh2->r[1] >= (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3123:
{
	if ((INT32) sh2->r[1] >= (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3133:
{
	if ((INT32) sh2->r[1] >= (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3143:
{
	if ((INT32) sh2->r[1] >= (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3153:
{
	if ((INT32) sh2->r[1] >= (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3163:
{
	if ((INT32) sh2->r[1] >= (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3173:
{
	if ((INT32) sh2->r[1] >= (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3183:
{
	if ((INT32) sh2->r[1] >= (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3193:
{
	if ((INT32) sh2->r[1] >= (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31A3:
{
	if ((INT32) sh2->r[1] >= (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31B3:
{
	if ((INT32) sh2->r[1] >= (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31C3:
{
	if ((INT32) sh2->r[1] >= (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31D3:
{
	if ((INT32) sh2->r[1] >= (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31E3:
{
	if ((INT32) sh2->r[1] >= (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31F3:
{
	if ((INT32) sh2->r[1] >= (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3203:
{
	if ((INT32) sh2->r[2] >= (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3213:
{
	if ((INT32) sh2->r[2] >= (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3223:
{
	if ((INT32) sh2->r[2] >= (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3233:
{
	if ((INT32) sh2->r[2] >= (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3243:
{
	if ((INT32) sh2->r[2] >= (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3253:
{
	if ((INT32) sh2->r[2] >= (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3263:
{
	if ((INT32) sh2->r[2] >= (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3273:
{
	if ((INT32) sh2->r[2] >= (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3283:
{
	if ((INT32) sh2->r[2] >= (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3293:
{
	if ((INT32) sh2->r[2] >= (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32A3:
{
	if ((INT32) sh2->r[2] >= (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32B3:
{
	if ((INT32) sh2->r[2] >= (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32C3:
{
	if ((INT32) sh2->r[2] >= (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32D3:
{
	if ((INT32) sh2->r[2] >= (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32E3:
{
	if ((INT32) sh2->r[2] >= (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32F3:
{
	if ((INT32) sh2->r[2] >= (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3303:
{
	if ((INT32) sh2->r[3] >= (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3313:
{
	if ((INT32) sh2->r[3] >= (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3323:
{
	if ((INT32) sh2->r[3] >= (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3333:
{
	if ((INT32) sh2->r[3] >= (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3343:
{
	if ((INT32) sh2->r[3] >= (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3353:
{
	if ((INT32) sh2->r[3] >= (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3363:
{
	if ((INT32) sh2->r[3] >= (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3373:
{
	if ((INT32) sh2->r[3] >= (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3383:
{
	if ((INT32) sh2->r[3] >= (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3393:
{
	if ((INT32) sh2->r[3] >= (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33A3:
{
	if ((INT32) sh2->r[3] >= (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33B3:
{
	if ((INT32) sh2->r[3] >= (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33C3:
{
	if ((INT32) sh2->r[3] >= (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33D3:
{
	if ((INT32) sh2->r[3] >= (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33E3:
{
	if ((INT32) sh2->r[3] >= (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33F3:
{
	if ((INT32) sh2->r[3] >= (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3403:
{
	if ((INT32) sh2->r[4] >= (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3413:
{
	if ((INT32) sh2->r[4] >= (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3423:
{
	if ((INT32) sh2->r[4] >= (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3433:
{
	if ((INT32) sh2->r[4] >= (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3443:
{
	if ((INT32) sh2->r[4] >= (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3453:
{
	if ((INT32) sh2->r[4] >= (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3463:
{
	if ((INT32) sh2->r[4] >= (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3473:
{
	if ((INT32) sh2->r[4] >= (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3483:
{
	if ((INT32) sh2->r[4] >= (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3493:
{
	if ((INT32) sh2->r[4] >= (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34A3:
{
	if ((INT32) sh2->r[4] >= (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34B3:
{
	if ((INT32) sh2->r[4] >= (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34C3:
{
	if ((INT32) sh2->r[4] >= (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34D3:
{
	if ((INT32) sh2->r[4] >= (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34E3:
{
	if ((INT32) sh2->r[4] >= (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34F3:
{
	if ((INT32) sh2->r[4] >= (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3503:
{
	if ((INT32) sh2->r[5] >= (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3513:
{
	if ((INT32) sh2->r[5] >= (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3523:
{
	if ((INT32) sh2->r[5] >= (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3533:
{
	if ((INT32) sh2->r[5] >= (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3543:
{
	if ((INT32) sh2->r[5] >= (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3553:
{
	if ((INT32) sh2->r[5] >= (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3563:
{
	if ((INT32) sh2->r[5] >= (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3573:
{
	if ((INT32) sh2->r[5] >= (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3583:
{
	if ((INT32) sh2->r[5] >= (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3593:
{
	if ((INT32) sh2->r[5] >= (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35A3:
{
	if ((INT32) sh2->r[5] >= (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35B3:
{
	if ((INT32) sh2->r[5] >= (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35C3:
{
	if ((INT32) sh2->r[5] >= (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35D3:
{
	if ((INT32) sh2->r[5] >= (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35E3:
{
	if ((INT32) sh2->r[5] >= (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35F3:
{
	if ((INT32) sh2->r[5] >= (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3603:
{
	if ((INT32) sh2->r[6] >= (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3613:
{
	if ((INT32) sh2->r[6] >= (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3623:
{
	if ((INT32) sh2->r[6] >= (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3633:
{
	if ((INT32) sh2->r[6] >= (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3643:
{
	if ((INT32) sh2->r[6] >= (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3653:
{
	if ((INT32) sh2->r[6] >= (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3663:
{
	if ((INT32) sh2->r[6] >= (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3673:
{
	if ((INT32) sh2->r[6] >= (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3683:
{
	if ((INT32) sh2->r[6] >= (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3693:
{
	if ((INT32) sh2->r[6] >= (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36A3:
{
	if ((INT32) sh2->r[6] >= (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36B3:
{
	if ((INT32) sh2->r[6] >= (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36C3:
{
	if ((INT32) sh2->r[6] >= (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36D3:
{
	if ((INT32) sh2->r[6] >= (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36E3:
{
	if ((INT32) sh2->r[6] >= (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36F3:
{
	if ((INT32) sh2->r[6] >= (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3703:
{
	if ((INT32) sh2->r[7] >= (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3713:
{
	if ((INT32) sh2->r[7] >= (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3723:
{
	if ((INT32) sh2->r[7] >= (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3733:
{
	if ((INT32) sh2->r[7] >= (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3743:
{
	if ((INT32) sh2->r[7] >= (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3753:
{
	if ((INT32) sh2->r[7] >= (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3763:
{
	if ((INT32) sh2->r[7] >= (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3773:
{
	if ((INT32) sh2->r[7] >= (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3783:
{
	if ((INT32) sh2->r[7] >= (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3793:
{
	if ((INT32) sh2->r[7] >= (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37A3:
{
	if ((INT32) sh2->r[7] >= (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37B3:
{
	if ((INT32) sh2->r[7] >= (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37C3:
{
	if ((INT32) sh2->r[7] >= (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37D3:
{
	if ((INT32) sh2->r[7] >= (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37E3:
{
	if ((INT32) sh2->r[7] >= (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37F3:
{
	if ((INT32) sh2->r[7] >= (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3803:
{
	if ((INT32) sh2->r[8] >= (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3813:
{
	if ((INT32) sh2->r[8] >= (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3823:
{
	if ((INT32) sh2->r[8] >= (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3833:
{
	if ((INT32) sh2->r[8] >= (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3843:
{
	if ((INT32) sh2->r[8] >= (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3853:
{
	if ((INT32) sh2->r[8] >= (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3863:
{
	if ((INT32) sh2->r[8] >= (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3873:
{
	if ((INT32) sh2->r[8] >= (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3883:
{
	if ((INT32) sh2->r[8] >= (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3893:
{
	if ((INT32) sh2->r[8] >= (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38A3:
{
	if ((INT32) sh2->r[8] >= (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38B3:
{
	if ((INT32) sh2->r[8] >= (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38C3:
{
	if ((INT32) sh2->r[8] >= (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38D3:
{
	if ((INT32) sh2->r[8] >= (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38E3:
{
	if ((INT32) sh2->r[8] >= (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38F3:
{
	if ((INT32) sh2->r[8] >= (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3903:
{
	if ((INT32) sh2->r[9] >= (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3913:
{
	if ((INT32) sh2->r[9] >= (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3923:
{
	if ((INT32) sh2->r[9] >= (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3933:
{
	if ((INT32) sh2->r[9] >= (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3943:
{
	if ((INT32) sh2->r[9] >= (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3953:
{
	if ((INT32) sh2->r[9] >= (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3963:
{
	if ((INT32) sh2->r[9] >= (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3973:
{
	if ((INT32) sh2->r[9] >= (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3983:
{
	if ((INT32) sh2->r[9] >= (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3993:
{
	if ((INT32) sh2->r[9] >= (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39A3:
{
	if ((INT32) sh2->r[9] >= (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39B3:
{
	if ((INT32) sh2->r[9] >= (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39C3:
{
	if ((INT32) sh2->r[9] >= (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39D3:
{
	if ((INT32) sh2->r[9] >= (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39E3:
{
	if ((INT32) sh2->r[9] >= (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39F3:
{
	if ((INT32) sh2->r[9] >= (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A03:
{
	if ((INT32) sh2->r[10] >= (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A13:
{
	if ((INT32) sh2->r[10] >= (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A23:
{
	if ((INT32) sh2->r[10] >= (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A33:
{
	if ((INT32) sh2->r[10] >= (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A43:
{
	if ((INT32) sh2->r[10] >= (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A53:
{
	if ((INT32) sh2->r[10] >= (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A63:
{
	if ((INT32) sh2->r[10] >= (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A73:
{
	if ((INT32) sh2->r[10] >= (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A83:
{
	if ((INT32) sh2->r[10] >= (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A93:
{
	if ((INT32) sh2->r[10] >= (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AA3:
{
	if ((INT32) sh2->r[10] >= (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AB3:
{
	if ((INT32) sh2->r[10] >= (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AC3:
{
	if ((INT32) sh2->r[10] >= (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AD3:
{
	if ((INT32) sh2->r[10] >= (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AE3:
{
	if ((INT32) sh2->r[10] >= (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AF3:
{
	if ((INT32) sh2->r[10] >= (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B03:
{
	if ((INT32) sh2->r[11] >= (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B13:
{
	if ((INT32) sh2->r[11] >= (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B23:
{
	if ((INT32) sh2->r[11] >= (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B33:
{
	if ((INT32) sh2->r[11] >= (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B43:
{
	if ((INT32) sh2->r[11] >= (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B53:
{
	if ((INT32) sh2->r[11] >= (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B63:
{
	if ((INT32) sh2->r[11] >= (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B73:
{
	if ((INT32) sh2->r[11] >= (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B83:
{
	if ((INT32) sh2->r[11] >= (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B93:
{
	if ((INT32) sh2->r[11] >= (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BA3:
{
	if ((INT32) sh2->r[11] >= (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BB3:
{
	if ((INT32) sh2->r[11] >= (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BC3:
{
	if ((INT32) sh2->r[11] >= (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BD3:
{
	if ((INT32) sh2->r[11] >= (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BE3:
{
	if ((INT32) sh2->r[11] >= (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BF3:
{
	if ((INT32) sh2->r[11] >= (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C03:
{
	if ((INT32) sh2->r[12] >= (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C13:
{
	if ((INT32) sh2->r[12] >= (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C23:
{
	if ((INT32) sh2->r[12] >= (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C33:
{
	if ((INT32) sh2->r[12] >= (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C43:
{
	if ((INT32) sh2->r[12] >= (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C53:
{
	if ((INT32) sh2->r[12] >= (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C63:
{
	if ((INT32) sh2->r[12] >= (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C73:
{
	if ((INT32) sh2->r[12] >= (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C83:
{
	if ((INT32) sh2->r[12] >= (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C93:
{
	if ((INT32) sh2->r[12] >= (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CA3:
{
	if ((INT32) sh2->r[12] >= (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CB3:
{
	if ((INT32) sh2->r[12] >= (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CC3:
{
	if ((INT32) sh2->r[12] >= (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CD3:
{
	if ((INT32) sh2->r[12] >= (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CE3:
{
	if ((INT32) sh2->r[12] >= (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CF3:
{
	if ((INT32) sh2->r[12] >= (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D03:
{
	if ((INT32) sh2->r[13] >= (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D13:
{
	if ((INT32) sh2->r[13] >= (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D23:
{
	if ((INT32) sh2->r[13] >= (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D33:
{
	if ((INT32) sh2->r[13] >= (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D43:
{
	if ((INT32) sh2->r[13] >= (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D53:
{
	if ((INT32) sh2->r[13] >= (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D63:
{
	if ((INT32) sh2->r[13] >= (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D73:
{
	if ((INT32) sh2->r[13] >= (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D83:
{
	if ((INT32) sh2->r[13] >= (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D93:
{
	if ((INT32) sh2->r[13] >= (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DA3:
{
	if ((INT32) sh2->r[13] >= (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DB3:
{
	if ((INT32) sh2->r[13] >= (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DC3:
{
	if ((INT32) sh2->r[13] >= (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DD3:
{
	if ((INT32) sh2->r[13] >= (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DE3:
{
	if ((INT32) sh2->r[13] >= (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DF3:
{
	if ((INT32) sh2->r[13] >= (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E03:
{
	if ((INT32) sh2->r[14] >= (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E13:
{
	if ((INT32) sh2->r[14] >= (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E23:
{
	if ((INT32) sh2->r[14] >= (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E33:
{
	if ((INT32) sh2->r[14] >= (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E43:
{
	if ((INT32) sh2->r[14] >= (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E53:
{
	if ((INT32) sh2->r[14] >= (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E63:
{
	if ((INT32) sh2->r[14] >= (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E73:
{
	if ((INT32) sh2->r[14] >= (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E83:
{
	if ((INT32) sh2->r[14] >= (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E93:
{
	if ((INT32) sh2->r[14] >= (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3EA3:
{
	if ((INT32) sh2->r[14] >= (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3EB3:
{
	if ((INT32) sh2->r[14] >= (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3EC3:
{
	if ((INT32) sh2->r[14] >= (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3ED3:
{
	if ((INT32) sh2->r[14] >= (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3EE3:
{
	if ((INT32) sh2->r[14] >= (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3EF3:
{
	if ((INT32) sh2->r[14] >= (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F03:
{
	if ((INT32) sh2->r[15] >= (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F13:
{
	if ((INT32) sh2->r[15] >= (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F23:
{
	if ((INT32) sh2->r[15] >= (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F33:
{
	if ((INT32) sh2->r[15] >= (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F43:
{
	if ((INT32) sh2->r[15] >= (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F53:
{
	if ((INT32) sh2->r[15] >= (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F63:
{
	if ((INT32) sh2->r[15] >= (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F73:
{
	if ((INT32) sh2->r[15] >= (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F83:
{
	if ((INT32) sh2->r[15] >= (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F93:
{
	if ((INT32) sh2->r[15] >= (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FA3:
{
	if ((INT32) sh2->r[15] >= (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FB3:
{
	if ((INT32) sh2->r[15] >= (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FC3:
{
	if ((INT32) sh2->r[15] >= (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FD3:
{
	if ((INT32) sh2->r[15] >= (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FE3:
{
	if ((INT32) sh2->r[15] >= (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FF3:
{
	if ((INT32) sh2->r[15] >= (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

// DIV1 Rm,Rn
Op3004:
{
	n = (opcode>>8) & 0x0f;
	m = (opcode>>4) & 0x0f;
	old_q = sh2->sr & Q;
	if (0x80000000 & sh2->r[n])
		sh2->sr |= Q;
	else
		sh2->sr &= ~Q;

	sh2->r[n] = (sh2->r[n] << 1) | (sh2->sr & T);

	if (!old_q)
	{
		if (!(sh2->sr & M))
		{
			tmp0 = sh2->r[n];
			sh2->r[n] -= sh2->r[m];
			if(!(sh2->sr & Q))
				if(sh2->r[n] > tmp0)
					sh2->sr |= Q;
				else
					sh2->sr &= ~Q;
			else
				if(sh2->r[n] > tmp0)
					sh2->sr &= ~Q;
				else
					sh2->sr |= Q;
		}
		else
		{
			tmp0 = sh2->r[n];
			sh2->r[n] += sh2->r[m];
			if(!(sh2->sr & Q))
			{
				if(sh2->r[n] < tmp0)
					sh2->sr &= ~Q;
				else
					sh2->sr |= Q;
			}
			else
			{
				if(sh2->r[n] < tmp0)
					sh2->sr |= Q;
				else
					sh2->sr &= ~Q;
			}
		}
	}
	else
	{
		if (!(sh2->sr & M))
		{
			tmp0 = sh2->r[n];
			sh2->r[n] += sh2->r[m];
			if(!(sh2->sr & Q))
				if(sh2->r[n] < tmp0)
					sh2->sr |= Q;
				else
					sh2->sr &= ~Q;
			else
				if(sh2->r[n] < tmp0)
					sh2->sr &= ~Q;
				else
					sh2->sr |= Q;
		}
		else
		{
			tmp0 = sh2->r[n];
			sh2->r[n] -= sh2->r[m];
			if(!(sh2->sr & Q))
				if(sh2->r[n] > tmp0)
					sh2->sr &= ~Q;
				else
					sh2->sr |= Q;
			else
				if(sh2->r[n] > tmp0)
					sh2->sr |= Q;
				else
					sh2->sr &= ~Q;
		}
	}

	tmp0 = (sh2->sr & (Q | M));
	if((!tmp0) || (tmp0 == 0x300)) /* if Q == M set T else clear T */
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

// DMULU.L Rm,Rn
Op3005:
{
	n = (opcode>>8) & 0x0f;
	m = (opcode>>4) & 0x0f;
	RnL = sh2->r[n] & 0x0000ffff;
	RnH = (sh2->r[n] >> 16) & 0x0000ffff;
	RmL = sh2->r[m] & 0x0000ffff;
	RmH = (sh2->r[m] >> 16) & 0x0000ffff;
	temp0 = RmL * RnL;
	temp1 = RmH * RnL;
	temp2 = RmL * RnH;
	temp3 = RmH * RnH;
	Res2 = 0;
	Res1 = temp1 + temp2;
	if (Res1 < temp1)
		Res2 += 0x00010000;
	temp1 = (Res1 << 16) & 0xffff0000;
	Res0 = temp0 + temp1;
	if (Res0 < temp0)
		Res2++;
	Res2 = Res2 + ((Res1 >> 16) & 0x0000ffff) + temp3;
	sh2->mach = Res2;
	sh2->macl = Res0;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

// CMP_HI Rm,Rn
Op3006:
{
	if ((UINT32) sh2->r[0] > (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3016:
{
	if ((UINT32) sh2->r[0] > (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3026:
{
	if ((UINT32) sh2->r[0] > (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3036:
{
	if ((UINT32) sh2->r[0] > (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3046:
{
	if ((UINT32) sh2->r[0] > (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3056:
{
	if ((UINT32) sh2->r[0] > (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3066:
{
	if ((UINT32) sh2->r[0] > (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3076:
{
	if ((UINT32) sh2->r[0] > (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3086:
{
	if ((UINT32) sh2->r[0] > (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3096:
{
	if ((UINT32) sh2->r[0] > (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30A6:
{
	if ((UINT32) sh2->r[0] > (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30B6:
{
	if ((UINT32) sh2->r[0] > (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30C6:
{
	if ((UINT32) sh2->r[0] > (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30D6:
{
	if ((UINT32) sh2->r[0] > (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30E6:
{
	if ((UINT32) sh2->r[0] > (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30F6:
{
	if ((UINT32) sh2->r[0] > (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3106:
{
	if ((UINT32) sh2->r[1] > (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3116:
{
	if ((UINT32) sh2->r[1] > (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3126:
{
	if ((UINT32) sh2->r[1] > (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3136:
{
	if ((UINT32) sh2->r[1] > (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3146:
{
	if ((UINT32) sh2->r[1] > (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3156:
{
	if ((UINT32) sh2->r[1] > (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3166:
{
	if ((UINT32) sh2->r[1] > (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3176:
{
	if ((UINT32) sh2->r[1] > (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3186:
{
	if ((UINT32) sh2->r[1] > (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3196:
{
	if ((UINT32) sh2->r[1] > (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31A6:
{
	if ((UINT32) sh2->r[1] > (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31B6:
{
	if ((UINT32) sh2->r[1] > (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31C6:
{
	if ((UINT32) sh2->r[1] > (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31D6:
{
	if ((UINT32) sh2->r[1] > (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31E6:
{
	if ((UINT32) sh2->r[1] > (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31F6:
{
	if ((UINT32) sh2->r[1] > (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3206:
{
	if ((UINT32) sh2->r[2] > (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3216:
{
	if ((UINT32) sh2->r[2] > (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3226:
{
	if ((UINT32) sh2->r[2] > (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3236:
{
	if ((UINT32) sh2->r[2] > (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3246:
{
	if ((UINT32) sh2->r[2] > (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3256:
{
	if ((UINT32) sh2->r[2] > (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3266:
{
	if ((UINT32) sh2->r[2] > (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3276:
{
	if ((UINT32) sh2->r[2] > (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3286:
{
	if ((UINT32) sh2->r[2] > (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3296:
{
	if ((UINT32) sh2->r[2] > (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32A6:
{
	if ((UINT32) sh2->r[2] > (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32B6:
{
	if ((UINT32) sh2->r[2] > (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32C6:
{
	if ((UINT32) sh2->r[2] > (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32D6:
{
	if ((UINT32) sh2->r[2] > (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32E6:
{
	if ((UINT32) sh2->r[2] > (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32F6:
{
	if ((UINT32) sh2->r[2] > (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3306:
{
	if ((UINT32) sh2->r[3] > (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3316:
{
	if ((UINT32) sh2->r[3] > (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3326:
{
	if ((UINT32) sh2->r[3] > (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3336:
{
	if ((UINT32) sh2->r[3] > (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3346:
{
	if ((UINT32) sh2->r[3] > (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3356:
{
	if ((UINT32) sh2->r[3] > (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3366:
{
	if ((UINT32) sh2->r[3] > (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3376:
{
	if ((UINT32) sh2->r[3] > (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3386:
{
	if ((UINT32) sh2->r[3] > (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3396:
{
	if ((UINT32) sh2->r[3] > (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33A6:
{
	if ((UINT32) sh2->r[3] > (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33B6:
{
	if ((UINT32) sh2->r[3] > (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33C6:
{
	if ((UINT32) sh2->r[3] > (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33D6:
{
	if ((UINT32) sh2->r[3] > (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33E6:
{
	if ((UINT32) sh2->r[3] > (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33F6:
{
	if ((UINT32) sh2->r[3] > (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3406:
{
	if ((UINT32) sh2->r[4] > (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3416:
{
	if ((UINT32) sh2->r[4] > (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3426:
{
	if ((UINT32) sh2->r[4] > (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3436:
{
	if ((UINT32) sh2->r[4] > (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3446:
{
	if ((UINT32) sh2->r[4] > (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3456:
{
	if ((UINT32) sh2->r[4] > (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3466:
{
	if ((UINT32) sh2->r[4] > (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3476:
{
	if ((UINT32) sh2->r[4] > (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3486:
{
	if ((UINT32) sh2->r[4] > (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3496:
{
	if ((UINT32) sh2->r[4] > (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34A6:
{
	if ((UINT32) sh2->r[4] > (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34B6:
{
	if ((UINT32) sh2->r[4] > (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34C6:
{
	if ((UINT32) sh2->r[4] > (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34D6:
{
	if ((UINT32) sh2->r[4] > (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34E6:
{
	if ((UINT32) sh2->r[4] > (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34F6:
{
	if ((UINT32) sh2->r[4] > (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3506:
{
	if ((UINT32) sh2->r[5] > (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3516:
{
	if ((UINT32) sh2->r[5] > (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3526:
{
	if ((UINT32) sh2->r[5] > (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3536:
{
	if ((UINT32) sh2->r[5] > (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3546:
{
	if ((UINT32) sh2->r[5] > (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3556:
{
	if ((UINT32) sh2->r[5] > (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3566:
{
	if ((UINT32) sh2->r[5] > (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3576:
{
	if ((UINT32) sh2->r[5] > (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3586:
{
	if ((UINT32) sh2->r[5] > (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3596:
{
	if ((UINT32) sh2->r[5] > (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35A6:
{
	if ((UINT32) sh2->r[5] > (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35B6:
{
	if ((UINT32) sh2->r[5] > (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35C6:
{
	if ((UINT32) sh2->r[5] > (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35D6:
{
	if ((UINT32) sh2->r[5] > (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35E6:
{
	if ((UINT32) sh2->r[5] > (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35F6:
{
	if ((UINT32) sh2->r[5] > (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3606:
{
	if ((UINT32) sh2->r[6] > (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3616:
{
	if ((UINT32) sh2->r[6] > (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3626:
{
	if ((UINT32) sh2->r[6] > (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3636:
{
	if ((UINT32) sh2->r[6] > (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3646:
{
	if ((UINT32) sh2->r[6] > (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3656:
{
	if ((UINT32) sh2->r[6] > (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3666:
{
	if ((UINT32) sh2->r[6] > (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3676:
{
	if ((UINT32) sh2->r[6] > (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3686:
{
	if ((UINT32) sh2->r[6] > (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3696:
{
	if ((UINT32) sh2->r[6] > (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36A6:
{
	if ((UINT32) sh2->r[6] > (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36B6:
{
	if ((UINT32) sh2->r[6] > (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36C6:
{
	if ((UINT32) sh2->r[6] > (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36D6:
{
	if ((UINT32) sh2->r[6] > (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36E6:
{
	if ((UINT32) sh2->r[6] > (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36F6:
{
	if ((UINT32) sh2->r[6] > (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3706:
{
	if ((UINT32) sh2->r[7] > (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3716:
{
	if ((UINT32) sh2->r[7] > (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3726:
{
	if ((UINT32) sh2->r[7] > (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3736:
{
	if ((UINT32) sh2->r[7] > (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3746:
{
	if ((UINT32) sh2->r[7] > (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3756:
{
	if ((UINT32) sh2->r[7] > (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3766:
{
	if ((UINT32) sh2->r[7] > (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3776:
{
	if ((UINT32) sh2->r[7] > (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3786:
{
	if ((UINT32) sh2->r[7] > (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3796:
{
	if ((UINT32) sh2->r[7] > (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37A6:
{
	if ((UINT32) sh2->r[7] > (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37B6:
{
	if ((UINT32) sh2->r[7] > (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37C6:
{
	if ((UINT32) sh2->r[7] > (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37D6:
{
	if ((UINT32) sh2->r[7] > (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37E6:
{
	if ((UINT32) sh2->r[7] > (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37F6:
{
	if ((UINT32) sh2->r[7] > (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3806:
{
	if ((UINT32) sh2->r[8] > (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3816:
{
	if ((UINT32) sh2->r[8] > (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3826:
{
	if ((UINT32) sh2->r[8] > (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3836:
{
	if ((UINT32) sh2->r[8] > (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3846:
{
	if ((UINT32) sh2->r[8] > (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3856:
{
	if ((UINT32) sh2->r[8] > (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3866:
{
	if ((UINT32) sh2->r[8] > (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3876:
{
	if ((UINT32) sh2->r[8] > (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3886:
{
	if ((UINT32) sh2->r[8] > (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3896:
{
	if ((UINT32) sh2->r[8] > (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38A6:
{
	if ((UINT32) sh2->r[8] > (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38B6:
{
	if ((UINT32) sh2->r[8] > (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38C6:
{
	if ((UINT32) sh2->r[8] > (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38D6:
{
	if ((UINT32) sh2->r[8] > (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38E6:
{
	if ((UINT32) sh2->r[8] > (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38F6:
{
	if ((UINT32) sh2->r[8] > (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3906:
{
	if ((UINT32) sh2->r[9] > (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3916:
{
	if ((UINT32) sh2->r[9] > (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3926:
{
	if ((UINT32) sh2->r[9] > (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3936:
{
	if ((UINT32) sh2->r[9] > (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3946:
{
	if ((UINT32) sh2->r[9] > (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3956:
{
	if ((UINT32) sh2->r[9] > (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3966:
{
	if ((UINT32) sh2->r[9] > (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3976:
{
	if ((UINT32) sh2->r[9] > (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3986:
{
	if ((UINT32) sh2->r[9] > (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3996:
{
	if ((UINT32) sh2->r[9] > (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39A6:
{
	if ((UINT32) sh2->r[9] > (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39B6:
{
	if ((UINT32) sh2->r[9] > (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39C6:
{
	if ((UINT32) sh2->r[9] > (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39D6:
{
	if ((UINT32) sh2->r[9] > (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39E6:
{
	if ((UINT32) sh2->r[9] > (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39F6:
{
	if ((UINT32) sh2->r[9] > (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A06:
{
	if ((UINT32) sh2->r[10] > (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A16:
{
	if ((UINT32) sh2->r[10] > (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A26:
{
	if ((UINT32) sh2->r[10] > (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A36:
{
	if ((UINT32) sh2->r[10] > (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A46:
{
	if ((UINT32) sh2->r[10] > (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A56:
{
	if ((UINT32) sh2->r[10] > (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A66:
{
	if ((UINT32) sh2->r[10] > (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A76:
{
	if ((UINT32) sh2->r[10] > (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A86:
{
	if ((UINT32) sh2->r[10] > (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A96:
{
	if ((UINT32) sh2->r[10] > (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AA6:
{
	if ((UINT32) sh2->r[10] > (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AB6:
{
	if ((UINT32) sh2->r[10] > (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AC6:
{
	if ((UINT32) sh2->r[10] > (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AD6:
{
	if ((UINT32) sh2->r[10] > (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AE6:
{
	if ((UINT32) sh2->r[10] > (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AF6:
{
	if ((UINT32) sh2->r[10] > (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B06:
{
	if ((UINT32) sh2->r[11] > (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B16:
{
	if ((UINT32) sh2->r[11] > (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B26:
{
	if ((UINT32) sh2->r[11] > (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B36:
{
	if ((UINT32) sh2->r[11] > (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B46:
{
	if ((UINT32) sh2->r[11] > (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B56:
{
	if ((UINT32) sh2->r[11] > (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B66:
{
	if ((UINT32) sh2->r[11] > (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B76:
{
	if ((UINT32) sh2->r[11] > (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B86:
{
	if ((UINT32) sh2->r[11] > (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B96:
{
	if ((UINT32) sh2->r[11] > (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BA6:
{
	if ((UINT32) sh2->r[11] > (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BB6:
{
	if ((UINT32) sh2->r[11] > (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BC6:
{
	if ((UINT32) sh2->r[11] > (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BD6:
{
	if ((UINT32) sh2->r[11] > (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BE6:
{
	if ((UINT32) sh2->r[11] > (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BF6:
{
	if ((UINT32) sh2->r[11] > (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C06:
{
	if ((UINT32) sh2->r[12] > (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C16:
{
	if ((UINT32) sh2->r[12] > (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C26:
{
	if ((UINT32) sh2->r[12] > (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C36:
{
	if ((UINT32) sh2->r[12] > (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C46:
{
	if ((UINT32) sh2->r[12] > (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C56:
{
	if ((UINT32) sh2->r[12] > (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C66:
{
	if ((UINT32) sh2->r[12] > (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C76:
{
	if ((UINT32) sh2->r[12] > (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C86:
{
	if ((UINT32) sh2->r[12] > (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C96:
{
	if ((UINT32) sh2->r[12] > (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CA6:
{
	if ((UINT32) sh2->r[12] > (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CB6:
{
	if ((UINT32) sh2->r[12] > (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CC6:
{
	if ((UINT32) sh2->r[12] > (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CD6:
{
	if ((UINT32) sh2->r[12] > (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CE6:
{
	if ((UINT32) sh2->r[12] > (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CF6:
{
	if ((UINT32) sh2->r[12] > (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D06:
{
	if ((UINT32) sh2->r[13] > (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D16:
{
	if ((UINT32) sh2->r[13] > (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D26:
{
	if ((UINT32) sh2->r[13] > (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D36:
{
	if ((UINT32) sh2->r[13] > (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D46:
{
	if ((UINT32) sh2->r[13] > (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D56:
{
	if ((UINT32) sh2->r[13] > (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D66:
{
	if ((UINT32) sh2->r[13] > (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D76:
{
	if ((UINT32) sh2->r[13] > (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D86:
{
	if ((UINT32) sh2->r[13] > (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D96:
{
	if ((UINT32) sh2->r[13] > (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DA6:
{
	if ((UINT32) sh2->r[13] > (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DB6:
{
	if ((UINT32) sh2->r[13] > (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DC6:
{
	if ((UINT32) sh2->r[13] > (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DD6:
{
	if ((UINT32) sh2->r[13] > (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DE6:
{
	if ((UINT32) sh2->r[13] > (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DF6:
{
	if ((UINT32) sh2->r[13] > (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E06:
{
	if ((UINT32) sh2->r[14] > (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E16:
{
	if ((UINT32) sh2->r[14] > (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E26:
{
	if ((UINT32) sh2->r[14] > (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E36:
{
	if ((UINT32) sh2->r[14] > (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E46:
{
	if ((UINT32) sh2->r[14] > (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E56:
{
	if ((UINT32) sh2->r[14] > (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E66:
{
	if ((UINT32) sh2->r[14] > (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E76:
{
	if ((UINT32) sh2->r[14] > (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E86:
{
	if ((UINT32) sh2->r[14] > (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E96:
{
	if ((UINT32) sh2->r[14] > (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3EA6:
{
	if ((UINT32) sh2->r[14] > (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3EB6:
{
	if ((UINT32) sh2->r[14] > (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3EC6:
{
	if ((UINT32) sh2->r[14] > (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3ED6:
{
	if ((UINT32) sh2->r[14] > (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3EE6:
{
	if ((UINT32) sh2->r[14] > (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3EF6:
{
	if ((UINT32) sh2->r[14] > (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F06:
{
	if ((UINT32) sh2->r[15] > (UINT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F16:
{
	if ((UINT32) sh2->r[15] > (UINT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F26:
{
	if ((UINT32) sh2->r[15] > (UINT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F36:
{
	if ((UINT32) sh2->r[15] > (UINT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F46:
{
	if ((UINT32) sh2->r[15] > (UINT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F56:
{
	if ((UINT32) sh2->r[15] > (UINT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F66:
{
	if ((UINT32) sh2->r[15] > (UINT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F76:
{
	if ((UINT32) sh2->r[15] > (UINT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F86:
{
	if ((UINT32) sh2->r[15] > (UINT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F96:
{
	if ((UINT32) sh2->r[15] > (UINT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FA6:
{
	if ((UINT32) sh2->r[15] > (UINT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FB6:
{
	if ((UINT32) sh2->r[15] > (UINT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FC6:
{
	if ((UINT32) sh2->r[15] > (UINT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FD6:
{
	if ((UINT32) sh2->r[15] > (UINT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FE6:
{
	if ((UINT32) sh2->r[15] > (UINT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FF6:
{
	if ((UINT32) sh2->r[15] > (UINT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

// CMP_GT Rm,Rn
Op3007:
{
	if ((INT32) sh2->r[0] > (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3017:
{
	if ((INT32) sh2->r[0] > (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3027:
{
	if ((INT32) sh2->r[0] > (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3037:
{
	if ((INT32) sh2->r[0] > (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3047:
{
	if ((INT32) sh2->r[0] > (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3057:
{
	if ((INT32) sh2->r[0] > (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3067:
{
	if ((INT32) sh2->r[0] > (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3077:
{
	if ((INT32) sh2->r[0] > (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3087:
{
	if ((INT32) sh2->r[0] > (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3097:
{
	if ((INT32) sh2->r[0] > (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30A7:
{
	if ((INT32) sh2->r[0] > (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30B7:
{
	if ((INT32) sh2->r[0] > (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30C7:
{
	if ((INT32) sh2->r[0] > (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30D7:
{
	if ((INT32) sh2->r[0] > (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30E7:
{
	if ((INT32) sh2->r[0] > (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op30F7:
{
	if ((INT32) sh2->r[0] > (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3107:
{
	if ((INT32) sh2->r[1] > (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3117:
{
	if ((INT32) sh2->r[1] > (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3127:
{
	if ((INT32) sh2->r[1] > (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3137:
{
	if ((INT32) sh2->r[1] > (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3147:
{
	if ((INT32) sh2->r[1] > (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3157:
{
	if ((INT32) sh2->r[1] > (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3167:
{
	if ((INT32) sh2->r[1] > (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3177:
{
	if ((INT32) sh2->r[1] > (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3187:
{
	if ((INT32) sh2->r[1] > (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3197:
{
	if ((INT32) sh2->r[1] > (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31A7:
{
	if ((INT32) sh2->r[1] > (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31B7:
{
	if ((INT32) sh2->r[1] > (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31C7:
{
	if ((INT32) sh2->r[1] > (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31D7:
{
	if ((INT32) sh2->r[1] > (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31E7:
{
	if ((INT32) sh2->r[1] > (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op31F7:
{
	if ((INT32) sh2->r[1] > (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3207:
{
	if ((INT32) sh2->r[2] > (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3217:
{
	if ((INT32) sh2->r[2] > (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3227:
{
	if ((INT32) sh2->r[2] > (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3237:
{
	if ((INT32) sh2->r[2] > (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3247:
{
	if ((INT32) sh2->r[2] > (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3257:
{
	if ((INT32) sh2->r[2] > (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3267:
{
	if ((INT32) sh2->r[2] > (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3277:
{
	if ((INT32) sh2->r[2] > (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3287:
{
	if ((INT32) sh2->r[2] > (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3297:
{
	if ((INT32) sh2->r[2] > (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32A7:
{
	if ((INT32) sh2->r[2] > (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32B7:
{
	if ((INT32) sh2->r[2] > (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32C7:
{
	if ((INT32) sh2->r[2] > (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32D7:
{
	if ((INT32) sh2->r[2] > (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32E7:
{
	if ((INT32) sh2->r[2] > (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op32F7:
{
	if ((INT32) sh2->r[2] > (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3307:
{
	if ((INT32) sh2->r[3] > (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3317:
{
	if ((INT32) sh2->r[3] > (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3327:
{
	if ((INT32) sh2->r[3] > (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3337:
{
	if ((INT32) sh2->r[3] > (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3347:
{
	if ((INT32) sh2->r[3] > (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3357:
{
	if ((INT32) sh2->r[3] > (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3367:
{
	if ((INT32) sh2->r[3] > (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3377:
{
	if ((INT32) sh2->r[3] > (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3387:
{
	if ((INT32) sh2->r[3] > (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3397:
{
	if ((INT32) sh2->r[3] > (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33A7:
{
	if ((INT32) sh2->r[3] > (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33B7:
{
	if ((INT32) sh2->r[3] > (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33C7:
{
	if ((INT32) sh2->r[3] > (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33D7:
{
	if ((INT32) sh2->r[3] > (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33E7:
{
	if ((INT32) sh2->r[3] > (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op33F7:
{
	if ((INT32) sh2->r[3] > (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3407:
{
	if ((INT32) sh2->r[4] > (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3417:
{
	if ((INT32) sh2->r[4] > (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3427:
{
	if ((INT32) sh2->r[4] > (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3437:
{
	if ((INT32) sh2->r[4] > (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3447:
{
	if ((INT32) sh2->r[4] > (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3457:
{
	if ((INT32) sh2->r[4] > (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3467:
{
	if ((INT32) sh2->r[4] > (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3477:
{
	if ((INT32) sh2->r[4] > (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3487:
{
	if ((INT32) sh2->r[4] > (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3497:
{
	if ((INT32) sh2->r[4] > (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34A7:
{
	if ((INT32) sh2->r[4] > (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34B7:
{
	if ((INT32) sh2->r[4] > (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34C7:
{
	if ((INT32) sh2->r[4] > (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34D7:
{
	if ((INT32) sh2->r[4] > (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34E7:
{
	if ((INT32) sh2->r[4] > (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op34F7:
{
	if ((INT32) sh2->r[4] > (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3507:
{
	if ((INT32) sh2->r[5] > (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3517:
{
	if ((INT32) sh2->r[5] > (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3527:
{
	if ((INT32) sh2->r[5] > (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3537:
{
	if ((INT32) sh2->r[5] > (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3547:
{
	if ((INT32) sh2->r[5] > (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3557:
{
	if ((INT32) sh2->r[5] > (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3567:
{
	if ((INT32) sh2->r[5] > (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3577:
{
	if ((INT32) sh2->r[5] > (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3587:
{
	if ((INT32) sh2->r[5] > (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3597:
{
	if ((INT32) sh2->r[5] > (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35A7:
{
	if ((INT32) sh2->r[5] > (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35B7:
{
	if ((INT32) sh2->r[5] > (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35C7:
{
	if ((INT32) sh2->r[5] > (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35D7:
{
	if ((INT32) sh2->r[5] > (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35E7:
{
	if ((INT32) sh2->r[5] > (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op35F7:
{
	if ((INT32) sh2->r[5] > (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3607:
{
	if ((INT32) sh2->r[6] > (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3617:
{
	if ((INT32) sh2->r[6] > (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3627:
{
	if ((INT32) sh2->r[6] > (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3637:
{
	if ((INT32) sh2->r[6] > (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3647:
{
	if ((INT32) sh2->r[6] > (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3657:
{
	if ((INT32) sh2->r[6] > (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3667:
{
	if ((INT32) sh2->r[6] > (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3677:
{
	if ((INT32) sh2->r[6] > (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3687:
{
	if ((INT32) sh2->r[6] > (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3697:
{
	if ((INT32) sh2->r[6] > (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36A7:
{
	if ((INT32) sh2->r[6] > (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36B7:
{
	if ((INT32) sh2->r[6] > (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36C7:
{
	if ((INT32) sh2->r[6] > (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36D7:
{
	if ((INT32) sh2->r[6] > (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36E7:
{
	if ((INT32) sh2->r[6] > (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op36F7:
{
	if ((INT32) sh2->r[6] > (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3707:
{
	if ((INT32) sh2->r[7] > (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3717:
{
	if ((INT32) sh2->r[7] > (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3727:
{
	if ((INT32) sh2->r[7] > (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3737:
{
	if ((INT32) sh2->r[7] > (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3747:
{
	if ((INT32) sh2->r[7] > (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3757:
{
	if ((INT32) sh2->r[7] > (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3767:
{
	if ((INT32) sh2->r[7] > (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3777:
{
	if ((INT32) sh2->r[7] > (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3787:
{
	if ((INT32) sh2->r[7] > (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3797:
{
	if ((INT32) sh2->r[7] > (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37A7:
{
	if ((INT32) sh2->r[7] > (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37B7:
{
	if ((INT32) sh2->r[7] > (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37C7:
{
	if ((INT32) sh2->r[7] > (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37D7:
{
	if ((INT32) sh2->r[7] > (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37E7:
{
	if ((INT32) sh2->r[7] > (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op37F7:
{
	if ((INT32) sh2->r[7] > (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3807:
{
	if ((INT32) sh2->r[8] > (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3817:
{
	if ((INT32) sh2->r[8] > (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3827:
{
	if ((INT32) sh2->r[8] > (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3837:
{
	if ((INT32) sh2->r[8] > (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3847:
{
	if ((INT32) sh2->r[8] > (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3857:
{
	if ((INT32) sh2->r[8] > (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3867:
{
	if ((INT32) sh2->r[8] > (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3877:
{
	if ((INT32) sh2->r[8] > (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3887:
{
	if ((INT32) sh2->r[8] > (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3897:
{
	if ((INT32) sh2->r[8] > (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38A7:
{
	if ((INT32) sh2->r[8] > (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38B7:
{
	if ((INT32) sh2->r[8] > (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38C7:
{
	if ((INT32) sh2->r[8] > (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38D7:
{
	if ((INT32) sh2->r[8] > (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38E7:
{
	if ((INT32) sh2->r[8] > (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op38F7:
{
	if ((INT32) sh2->r[8] > (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3907:
{
	if ((INT32) sh2->r[9] > (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3917:
{
	if ((INT32) sh2->r[9] > (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3927:
{
	if ((INT32) sh2->r[9] > (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3937:
{
	if ((INT32) sh2->r[9] > (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3947:
{
	if ((INT32) sh2->r[9] > (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3957:
{
	if ((INT32) sh2->r[9] > (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3967:
{
	if ((INT32) sh2->r[9] > (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3977:
{
	if ((INT32) sh2->r[9] > (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3987:
{
	if ((INT32) sh2->r[9] > (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3997:
{
	if ((INT32) sh2->r[9] > (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39A7:
{
	if ((INT32) sh2->r[9] > (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39B7:
{
	if ((INT32) sh2->r[9] > (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39C7:
{
	if ((INT32) sh2->r[9] > (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39D7:
{
	if ((INT32) sh2->r[9] > (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39E7:
{
	if ((INT32) sh2->r[9] > (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op39F7:
{
	if ((INT32) sh2->r[9] > (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A07:
{
	if ((INT32) sh2->r[10] > (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A17:
{
	if ((INT32) sh2->r[10] > (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A27:
{
	if ((INT32) sh2->r[10] > (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A37:
{
	if ((INT32) sh2->r[10] > (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A47:
{
	if ((INT32) sh2->r[10] > (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A57:
{
	if ((INT32) sh2->r[10] > (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A67:
{
	if ((INT32) sh2->r[10] > (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A77:
{
	if ((INT32) sh2->r[10] > (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A87:
{
	if ((INT32) sh2->r[10] > (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3A97:
{
	if ((INT32) sh2->r[10] > (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AA7:
{
	if ((INT32) sh2->r[10] > (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AB7:
{
	if ((INT32) sh2->r[10] > (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AC7:
{
	if ((INT32) sh2->r[10] > (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AD7:
{
	if ((INT32) sh2->r[10] > (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AE7:
{
	if ((INT32) sh2->r[10] > (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3AF7:
{
	if ((INT32) sh2->r[10] > (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B07:
{
	if ((INT32) sh2->r[11] > (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B17:
{
	if ((INT32) sh2->r[11] > (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B27:
{
	if ((INT32) sh2->r[11] > (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B37:
{
	if ((INT32) sh2->r[11] > (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B47:
{
	if ((INT32) sh2->r[11] > (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B57:
{
	if ((INT32) sh2->r[11] > (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B67:
{
	if ((INT32) sh2->r[11] > (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B77:
{
	if ((INT32) sh2->r[11] > (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B87:
{
	if ((INT32) sh2->r[11] > (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3B97:
{
	if ((INT32) sh2->r[11] > (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BA7:
{
	if ((INT32) sh2->r[11] > (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BB7:
{
	if ((INT32) sh2->r[11] > (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BC7:
{
	if ((INT32) sh2->r[11] > (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BD7:
{
	if ((INT32) sh2->r[11] > (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BE7:
{
	if ((INT32) sh2->r[11] > (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3BF7:
{
	if ((INT32) sh2->r[11] > (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C07:
{
	if ((INT32) sh2->r[12] > (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C17:
{
	if ((INT32) sh2->r[12] > (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C27:
{
	if ((INT32) sh2->r[12] > (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C37:
{
	if ((INT32) sh2->r[12] > (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C47:
{
	if ((INT32) sh2->r[12] > (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C57:
{
	if ((INT32) sh2->r[12] > (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C67:
{
	if ((INT32) sh2->r[12] > (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C77:
{
	if ((INT32) sh2->r[12] > (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C87:
{
	if ((INT32) sh2->r[12] > (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3C97:
{
	if ((INT32) sh2->r[12] > (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CA7:
{
	if ((INT32) sh2->r[12] > (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CB7:
{
	if ((INT32) sh2->r[12] > (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CC7:
{
	if ((INT32) sh2->r[12] > (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CD7:
{
	if ((INT32) sh2->r[12] > (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CE7:
{
	if ((INT32) sh2->r[12] > (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3CF7:
{
	if ((INT32) sh2->r[12] > (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D07:
{
	if ((INT32) sh2->r[13] > (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D17:
{
	if ((INT32) sh2->r[13] > (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D27:
{
	if ((INT32) sh2->r[13] > (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D37:
{
	if ((INT32) sh2->r[13] > (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D47:
{
	if ((INT32) sh2->r[13] > (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D57:
{
	if ((INT32) sh2->r[13] > (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D67:
{
	if ((INT32) sh2->r[13] > (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D77:
{
	if ((INT32) sh2->r[13] > (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D87:
{
	if ((INT32) sh2->r[13] > (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3D97:
{
	if ((INT32) sh2->r[13] > (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DA7:
{
	if ((INT32) sh2->r[13] > (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DB7:
{
	if ((INT32) sh2->r[13] > (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DC7:
{
	if ((INT32) sh2->r[13] > (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DD7:
{
	if ((INT32) sh2->r[13] > (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DE7:
{
	if ((INT32) sh2->r[13] > (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3DF7:
{
	if ((INT32) sh2->r[13] > (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E07:
{
	if ((INT32) sh2->r[14] > (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E17:
{
	if ((INT32) sh2->r[14] > (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E27:
{
	if ((INT32) sh2->r[14] > (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E37:
{
	if ((INT32) sh2->r[14] > (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E47:
{
	if ((INT32) sh2->r[14] > (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E57:
{
	if ((INT32) sh2->r[14] > (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E67:
{
	if ((INT32) sh2->r[14] > (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E77:
{
	if ((INT32) sh2->r[14] > (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E87:
{
	if ((INT32) sh2->r[14] > (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3E97:
{
	if ((INT32) sh2->r[14] > (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3EA7:
{
	if ((INT32) sh2->r[14] > (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3EB7:
{
	if ((INT32) sh2->r[14] > (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3EC7:
{
	if ((INT32) sh2->r[14] > (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3ED7:
{
	if ((INT32) sh2->r[14] > (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3EE7:
{
	if ((INT32) sh2->r[14] > (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3EF7:
{
	if ((INT32) sh2->r[14] > (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F07:
{
	if ((INT32) sh2->r[15] > (INT32) sh2->r[0])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F17:
{
	if ((INT32) sh2->r[15] > (INT32) sh2->r[1])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F27:
{
	if ((INT32) sh2->r[15] > (INT32) sh2->r[2])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F37:
{
	if ((INT32) sh2->r[15] > (INT32) sh2->r[3])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F47:
{
	if ((INT32) sh2->r[15] > (INT32) sh2->r[4])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F57:
{
	if ((INT32) sh2->r[15] > (INT32) sh2->r[5])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F67:
{
	if ((INT32) sh2->r[15] > (INT32) sh2->r[6])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F77:
{
	if ((INT32) sh2->r[15] > (INT32) sh2->r[7])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F87:
{
	if ((INT32) sh2->r[15] > (INT32) sh2->r[8])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3F97:
{
	if ((INT32) sh2->r[15] > (INT32) sh2->r[9])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FA7:
{
	if ((INT32) sh2->r[15] > (INT32) sh2->r[10])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FB7:
{
	if ((INT32) sh2->r[15] > (INT32) sh2->r[11])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FC7:
{
	if ((INT32) sh2->r[15] > (INT32) sh2->r[12])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FD7:
{
	if ((INT32) sh2->r[15] > (INT32) sh2->r[13])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FE7:
{
	if ((INT32) sh2->r[15] > (INT32) sh2->r[14])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op3FF7:
{
	if ((INT32) sh2->r[15] > (INT32) sh2->r[15])
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

// SUB Rm,Rn
Op3008:
{
	sh2->r[0] -= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op3018:
{
	sh2->r[0] -= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op3028:
{
	sh2->r[0] -= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op3038:
{
	sh2->r[0] -= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op3048:
{
	sh2->r[0] -= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op3058:
{
	sh2->r[0] -= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op3068:
{
	sh2->r[0] -= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op3078:
{
	sh2->r[0] -= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op3088:
{
	sh2->r[0] -= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op3098:
{
	sh2->r[0] -= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op30A8:
{
	sh2->r[0] -= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op30B8:
{
	sh2->r[0] -= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op30C8:
{
	sh2->r[0] -= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op30D8:
{
	sh2->r[0] -= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op30E8:
{
	sh2->r[0] -= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op30F8:
{
	sh2->r[0] -= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op3108:
{
	sh2->r[1] -= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op3118:
{
	sh2->r[1] -= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op3128:
{
	sh2->r[1] -= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op3138:
{
	sh2->r[1] -= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op3148:
{
	sh2->r[1] -= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op3158:
{
	sh2->r[1] -= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op3168:
{
	sh2->r[1] -= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op3178:
{
	sh2->r[1] -= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op3188:
{
	sh2->r[1] -= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op3198:
{
	sh2->r[1] -= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op31A8:
{
	sh2->r[1] -= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op31B8:
{
	sh2->r[1] -= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op31C8:
{
	sh2->r[1] -= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op31D8:
{
	sh2->r[1] -= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op31E8:
{
	sh2->r[1] -= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op31F8:
{
	sh2->r[1] -= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op3208:
{
	sh2->r[2] -= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op3218:
{
	sh2->r[2] -= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op3228:
{
	sh2->r[2] -= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op3238:
{
	sh2->r[2] -= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op3248:
{
	sh2->r[2] -= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op3258:
{
	sh2->r[2] -= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op3268:
{
	sh2->r[2] -= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op3278:
{
	sh2->r[2] -= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op3288:
{
	sh2->r[2] -= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op3298:
{
	sh2->r[2] -= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op32A8:
{
	sh2->r[2] -= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op32B8:
{
	sh2->r[2] -= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op32C8:
{
	sh2->r[2] -= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op32D8:
{
	sh2->r[2] -= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op32E8:
{
	sh2->r[2] -= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op32F8:
{
	sh2->r[2] -= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op3308:
{
	sh2->r[3] -= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op3318:
{
	sh2->r[3] -= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op3328:
{
	sh2->r[3] -= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op3338:
{
	sh2->r[3] -= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op3348:
{
	sh2->r[3] -= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op3358:
{
	sh2->r[3] -= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op3368:
{
	sh2->r[3] -= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op3378:
{
	sh2->r[3] -= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op3388:
{
	sh2->r[3] -= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op3398:
{
	sh2->r[3] -= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op33A8:
{
	sh2->r[3] -= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op33B8:
{
	sh2->r[3] -= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op33C8:
{
	sh2->r[3] -= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op33D8:
{
	sh2->r[3] -= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op33E8:
{
	sh2->r[3] -= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op33F8:
{
	sh2->r[3] -= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op3408:
{
	sh2->r[4] -= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op3418:
{
	sh2->r[4] -= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op3428:
{
	sh2->r[4] -= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op3438:
{
	sh2->r[4] -= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op3448:
{
	sh2->r[4] -= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op3458:
{
	sh2->r[4] -= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op3468:
{
	sh2->r[4] -= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op3478:
{
	sh2->r[4] -= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op3488:
{
	sh2->r[4] -= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op3498:
{
	sh2->r[4] -= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op34A8:
{
	sh2->r[4] -= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op34B8:
{
	sh2->r[4] -= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op34C8:
{
	sh2->r[4] -= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op34D8:
{
	sh2->r[4] -= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op34E8:
{
	sh2->r[4] -= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op34F8:
{
	sh2->r[4] -= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op3508:
{
	sh2->r[5] -= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op3518:
{
	sh2->r[5] -= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op3528:
{
	sh2->r[5] -= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op3538:
{
	sh2->r[5] -= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op3548:
{
	sh2->r[5] -= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op3558:
{
	sh2->r[5] -= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op3568:
{
	sh2->r[5] -= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op3578:
{
	sh2->r[5] -= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op3588:
{
	sh2->r[5] -= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op3598:
{
	sh2->r[5] -= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op35A8:
{
	sh2->r[5] -= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op35B8:
{
	sh2->r[5] -= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op35C8:
{
	sh2->r[5] -= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op35D8:
{
	sh2->r[5] -= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op35E8:
{
	sh2->r[5] -= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op35F8:
{
	sh2->r[5] -= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op3608:
{
	sh2->r[6] -= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op3618:
{
	sh2->r[6] -= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op3628:
{
	sh2->r[6] -= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op3638:
{
	sh2->r[6] -= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op3648:
{
	sh2->r[6] -= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op3658:
{
	sh2->r[6] -= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op3668:
{
	sh2->r[6] -= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op3678:
{
	sh2->r[6] -= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op3688:
{
	sh2->r[6] -= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op3698:
{
	sh2->r[6] -= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op36A8:
{
	sh2->r[6] -= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op36B8:
{
	sh2->r[6] -= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op36C8:
{
	sh2->r[6] -= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op36D8:
{
	sh2->r[6] -= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op36E8:
{
	sh2->r[6] -= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op36F8:
{
	sh2->r[6] -= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op3708:
{
	sh2->r[7] -= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op3718:
{
	sh2->r[7] -= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op3728:
{
	sh2->r[7] -= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op3738:
{
	sh2->r[7] -= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op3748:
{
	sh2->r[7] -= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op3758:
{
	sh2->r[7] -= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op3768:
{
	sh2->r[7] -= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op3778:
{
	sh2->r[7] -= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op3788:
{
	sh2->r[7] -= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op3798:
{
	sh2->r[7] -= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op37A8:
{
	sh2->r[7] -= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op37B8:
{
	sh2->r[7] -= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op37C8:
{
	sh2->r[7] -= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op37D8:
{
	sh2->r[7] -= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op37E8:
{
	sh2->r[7] -= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op37F8:
{
	sh2->r[7] -= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op3808:
{
	sh2->r[8] -= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op3818:
{
	sh2->r[8] -= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op3828:
{
	sh2->r[8] -= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op3838:
{
	sh2->r[8] -= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op3848:
{
	sh2->r[8] -= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op3858:
{
	sh2->r[8] -= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op3868:
{
	sh2->r[8] -= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op3878:
{
	sh2->r[8] -= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op3888:
{
	sh2->r[8] -= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op3898:
{
	sh2->r[8] -= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op38A8:
{
	sh2->r[8] -= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op38B8:
{
	sh2->r[8] -= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op38C8:
{
	sh2->r[8] -= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op38D8:
{
	sh2->r[8] -= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op38E8:
{
	sh2->r[8] -= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op38F8:
{
	sh2->r[8] -= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op3908:
{
	sh2->r[9] -= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op3918:
{
	sh2->r[9] -= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op3928:
{
	sh2->r[9] -= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op3938:
{
	sh2->r[9] -= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op3948:
{
	sh2->r[9] -= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op3958:
{
	sh2->r[9] -= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op3968:
{
	sh2->r[9] -= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op3978:
{
	sh2->r[9] -= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op3988:
{
	sh2->r[9] -= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op3998:
{
	sh2->r[9] -= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op39A8:
{
	sh2->r[9] -= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op39B8:
{
	sh2->r[9] -= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op39C8:
{
	sh2->r[9] -= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op39D8:
{
	sh2->r[9] -= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op39E8:
{
	sh2->r[9] -= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op39F8:
{
	sh2->r[9] -= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op3A08:
{
	sh2->r[10] -= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op3A18:
{
	sh2->r[10] -= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op3A28:
{
	sh2->r[10] -= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op3A38:
{
	sh2->r[10] -= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op3A48:
{
	sh2->r[10] -= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op3A58:
{
	sh2->r[10] -= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op3A68:
{
	sh2->r[10] -= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op3A78:
{
	sh2->r[10] -= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op3A88:
{
	sh2->r[10] -= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op3A98:
{
	sh2->r[10] -= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op3AA8:
{
	sh2->r[10] -= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op3AB8:
{
	sh2->r[10] -= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op3AC8:
{
	sh2->r[10] -= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op3AD8:
{
	sh2->r[10] -= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op3AE8:
{
	sh2->r[10] -= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op3AF8:
{
	sh2->r[10] -= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op3B08:
{
	sh2->r[11] -= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op3B18:
{
	sh2->r[11] -= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op3B28:
{
	sh2->r[11] -= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op3B38:
{
	sh2->r[11] -= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op3B48:
{
	sh2->r[11] -= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op3B58:
{
	sh2->r[11] -= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op3B68:
{
	sh2->r[11] -= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op3B78:
{
	sh2->r[11] -= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op3B88:
{
	sh2->r[11] -= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op3B98:
{
	sh2->r[11] -= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op3BA8:
{
	sh2->r[11] -= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op3BB8:
{
	sh2->r[11] -= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op3BC8:
{
	sh2->r[11] -= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op3BD8:
{
	sh2->r[11] -= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op3BE8:
{
	sh2->r[11] -= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op3BF8:
{
	sh2->r[11] -= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op3C08:
{
	sh2->r[12] -= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op3C18:
{
	sh2->r[12] -= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op3C28:
{
	sh2->r[12] -= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op3C38:
{
	sh2->r[12] -= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op3C48:
{
	sh2->r[12] -= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op3C58:
{
	sh2->r[12] -= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op3C68:
{
	sh2->r[12] -= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op3C78:
{
	sh2->r[12] -= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op3C88:
{
	sh2->r[12] -= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op3C98:
{
	sh2->r[12] -= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op3CA8:
{
	sh2->r[12] -= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op3CB8:
{
	sh2->r[12] -= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op3CC8:
{
	sh2->r[12] -= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op3CD8:
{
	sh2->r[12] -= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op3CE8:
{
	sh2->r[12] -= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op3CF8:
{
	sh2->r[12] -= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op3D08:
{
	sh2->r[13] -= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op3D18:
{
	sh2->r[13] -= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op3D28:
{
	sh2->r[13] -= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op3D38:
{
	sh2->r[13] -= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op3D48:
{
	sh2->r[13] -= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op3D58:
{
	sh2->r[13] -= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op3D68:
{
	sh2->r[13] -= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op3D78:
{
	sh2->r[13] -= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op3D88:
{
	sh2->r[13] -= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op3D98:
{
	sh2->r[13] -= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op3DA8:
{
	sh2->r[13] -= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op3DB8:
{
	sh2->r[13] -= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op3DC8:
{
	sh2->r[13] -= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op3DD8:
{
	sh2->r[13] -= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op3DE8:
{
	sh2->r[13] -= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op3DF8:
{
	sh2->r[13] -= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op3E08:
{
	sh2->r[14] -= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op3E18:
{
	sh2->r[14] -= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op3E28:
{
	sh2->r[14] -= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op3E38:
{
	sh2->r[14] -= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op3E48:
{
	sh2->r[14] -= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op3E58:
{
	sh2->r[14] -= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op3E68:
{
	sh2->r[14] -= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op3E78:
{
	sh2->r[14] -= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op3E88:
{
	sh2->r[14] -= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op3E98:
{
	sh2->r[14] -= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op3EA8:
{
	sh2->r[14] -= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op3EB8:
{
	sh2->r[14] -= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op3EC8:
{
	sh2->r[14] -= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op3ED8:
{
	sh2->r[14] -= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op3EE8:
{
	sh2->r[14] -= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op3EF8:
{
	sh2->r[14] -= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op3F08:
{
	sh2->r[15] -= sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op3F18:
{
	sh2->r[15] -= sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op3F28:
{
	sh2->r[15] -= sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op3F38:
{
	sh2->r[15] -= sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op3F48:
{
	sh2->r[15] -= sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op3F58:
{
	sh2->r[15] -= sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op3F68:
{
	sh2->r[15] -= sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op3F78:
{
	sh2->r[15] -= sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op3F88:
{
	sh2->r[15] -= sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op3F98:
{
	sh2->r[15] -= sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op3FA8:
{
	sh2->r[15] -= sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op3FB8:
{
	sh2->r[15] -= sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op3FC8:
{
	sh2->r[15] -= sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op3FD8:
{
	sh2->r[15] -= sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op3FE8:
{
	sh2->r[15] -= sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op3FF8:
{
	sh2->r[15] -= sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

// SUBC Rm,Rn
Op300A:
{
	n = (opcode>>8) & 0x0f;
	m = (opcode>>4) & 0x0f;
	tmp1 = sh2->r[n] - sh2->r[m];
	tmp0 = sh2->r[n];
	sh2->r[n] = tmp1 - (sh2->sr & T);
	if (tmp0 < tmp1)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	if (tmp1 < sh2->r[n])
		sh2->sr |= T;
	goto SH2_RUN_CONTINUE;
}

// SUBV Rm,Rn
Op300B:
{
	n = (opcode>>8) & 0x0f;
	m = (opcode>>4) & 0x0f;
	if ((INT32) sh2->r[n] >= 0)
		dest = 0;
	else
		dest = 1;
	if ((INT32) sh2->r[m] >= 0)
		src = 0;
	else
		src = 1;
	src += dest;
	sh2->r[n] -= sh2->r[m];
	if ((INT32) sh2->r[n] >= 0)
		ans = 0;
	else
		ans = 1;
	ans += dest;
	if (src == 1)
	{
		if (ans == 1)
			sh2->sr |= T;
		else
			sh2->sr &= ~T;
	}
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

// ADD Rm,Rn
Op300C:
{
	sh2->r[0] += sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op301C:
{
	sh2->r[0] += sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op302C:
{
	sh2->r[0] += sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op303C:
{
	sh2->r[0] += sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op304C:
{
	sh2->r[0] += sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op305C:
{
	sh2->r[0] += sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op306C:
{
	sh2->r[0] += sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op307C:
{
	sh2->r[0] += sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op308C:
{
	sh2->r[0] += sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op309C:
{
	sh2->r[0] += sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op30AC:
{
	sh2->r[0] += sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op30BC:
{
	sh2->r[0] += sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op30CC:
{
	sh2->r[0] += sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op30DC:
{
	sh2->r[0] += sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op30EC:
{
	sh2->r[0] += sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op30FC:
{
	sh2->r[0] += sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op310C:
{
	sh2->r[1] += sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op311C:
{
	sh2->r[1] += sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op312C:
{
	sh2->r[1] += sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op313C:
{
	sh2->r[1] += sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op314C:
{
	sh2->r[1] += sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op315C:
{
	sh2->r[1] += sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op316C:
{
	sh2->r[1] += sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op317C:
{
	sh2->r[1] += sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op318C:
{
	sh2->r[1] += sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op319C:
{
	sh2->r[1] += sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op31AC:
{
	sh2->r[1] += sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op31BC:
{
	sh2->r[1] += sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op31CC:
{
	sh2->r[1] += sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op31DC:
{
	sh2->r[1] += sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op31EC:
{
	sh2->r[1] += sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op31FC:
{
	sh2->r[1] += sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op320C:
{
	sh2->r[2] += sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op321C:
{
	sh2->r[2] += sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op322C:
{
	sh2->r[2] += sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op323C:
{
	sh2->r[2] += sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op324C:
{
	sh2->r[2] += sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op325C:
{
	sh2->r[2] += sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op326C:
{
	sh2->r[2] += sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op327C:
{
	sh2->r[2] += sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op328C:
{
	sh2->r[2] += sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op329C:
{
	sh2->r[2] += sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op32AC:
{
	sh2->r[2] += sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op32BC:
{
	sh2->r[2] += sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op32CC:
{
	sh2->r[2] += sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op32DC:
{
	sh2->r[2] += sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op32EC:
{
	sh2->r[2] += sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op32FC:
{
	sh2->r[2] += sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op330C:
{
	sh2->r[3] += sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op331C:
{
	sh2->r[3] += sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op332C:
{
	sh2->r[3] += sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op333C:
{
	sh2->r[3] += sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op334C:
{
	sh2->r[3] += sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op335C:
{
	sh2->r[3] += sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op336C:
{
	sh2->r[3] += sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op337C:
{
	sh2->r[3] += sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op338C:
{
	sh2->r[3] += sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op339C:
{
	sh2->r[3] += sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op33AC:
{
	sh2->r[3] += sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op33BC:
{
	sh2->r[3] += sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op33CC:
{
	sh2->r[3] += sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op33DC:
{
	sh2->r[3] += sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op33EC:
{
	sh2->r[3] += sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op33FC:
{
	sh2->r[3] += sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op340C:
{
	sh2->r[4] += sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op341C:
{
	sh2->r[4] += sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op342C:
{
	sh2->r[4] += sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op343C:
{
	sh2->r[4] += sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op344C:
{
	sh2->r[4] += sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op345C:
{
	sh2->r[4] += sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op346C:
{
	sh2->r[4] += sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op347C:
{
	sh2->r[4] += sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op348C:
{
	sh2->r[4] += sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op349C:
{
	sh2->r[4] += sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op34AC:
{
	sh2->r[4] += sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op34BC:
{
	sh2->r[4] += sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op34CC:
{
	sh2->r[4] += sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op34DC:
{
	sh2->r[4] += sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op34EC:
{
	sh2->r[4] += sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op34FC:
{
	sh2->r[4] += sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op350C:
{
	sh2->r[5] += sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op351C:
{
	sh2->r[5] += sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op352C:
{
	sh2->r[5] += sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op353C:
{
	sh2->r[5] += sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op354C:
{
	sh2->r[5] += sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op355C:
{
	sh2->r[5] += sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op356C:
{
	sh2->r[5] += sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op357C:
{
	sh2->r[5] += sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op358C:
{
	sh2->r[5] += sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op359C:
{
	sh2->r[5] += sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op35AC:
{
	sh2->r[5] += sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op35BC:
{
	sh2->r[5] += sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op35CC:
{
	sh2->r[5] += sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op35DC:
{
	sh2->r[5] += sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op35EC:
{
	sh2->r[5] += sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op35FC:
{
	sh2->r[5] += sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op360C:
{
	sh2->r[6] += sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op361C:
{
	sh2->r[6] += sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op362C:
{
	sh2->r[6] += sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op363C:
{
	sh2->r[6] += sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op364C:
{
	sh2->r[6] += sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op365C:
{
	sh2->r[6] += sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op366C:
{
	sh2->r[6] += sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op367C:
{
	sh2->r[6] += sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op368C:
{
	sh2->r[6] += sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op369C:
{
	sh2->r[6] += sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op36AC:
{
	sh2->r[6] += sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op36BC:
{
	sh2->r[6] += sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op36CC:
{
	sh2->r[6] += sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op36DC:
{
	sh2->r[6] += sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op36EC:
{
	sh2->r[6] += sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op36FC:
{
	sh2->r[6] += sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op370C:
{
	sh2->r[7] += sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op371C:
{
	sh2->r[7] += sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op372C:
{
	sh2->r[7] += sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op373C:
{
	sh2->r[7] += sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op374C:
{
	sh2->r[7] += sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op375C:
{
	sh2->r[7] += sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op376C:
{
	sh2->r[7] += sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op377C:
{
	sh2->r[7] += sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op378C:
{
	sh2->r[7] += sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op379C:
{
	sh2->r[7] += sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op37AC:
{
	sh2->r[7] += sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op37BC:
{
	sh2->r[7] += sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op37CC:
{
	sh2->r[7] += sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op37DC:
{
	sh2->r[7] += sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op37EC:
{
	sh2->r[7] += sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op37FC:
{
	sh2->r[7] += sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op380C:
{
	sh2->r[8] += sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op381C:
{
	sh2->r[8] += sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op382C:
{
	sh2->r[8] += sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op383C:
{
	sh2->r[8] += sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op384C:
{
	sh2->r[8] += sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op385C:
{
	sh2->r[8] += sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op386C:
{
	sh2->r[8] += sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op387C:
{
	sh2->r[8] += sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op388C:
{
	sh2->r[8] += sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op389C:
{
	sh2->r[8] += sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op38AC:
{
	sh2->r[8] += sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op38BC:
{
	sh2->r[8] += sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op38CC:
{
	sh2->r[8] += sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op38DC:
{
	sh2->r[8] += sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op38EC:
{
	sh2->r[8] += sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op38FC:
{
	sh2->r[8] += sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op390C:
{
	sh2->r[9] += sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op391C:
{
	sh2->r[9] += sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op392C:
{
	sh2->r[9] += sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op393C:
{
	sh2->r[9] += sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op394C:
{
	sh2->r[9] += sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op395C:
{
	sh2->r[9] += sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op396C:
{
	sh2->r[9] += sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op397C:
{
	sh2->r[9] += sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op398C:
{
	sh2->r[9] += sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op399C:
{
	sh2->r[9] += sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op39AC:
{
	sh2->r[9] += sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op39BC:
{
	sh2->r[9] += sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op39CC:
{
	sh2->r[9] += sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op39DC:
{
	sh2->r[9] += sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op39EC:
{
	sh2->r[9] += sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op39FC:
{
	sh2->r[9] += sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op3A0C:
{
	sh2->r[10] += sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op3A1C:
{
	sh2->r[10] += sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op3A2C:
{
	sh2->r[10] += sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op3A3C:
{
	sh2->r[10] += sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op3A4C:
{
	sh2->r[10] += sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op3A5C:
{
	sh2->r[10] += sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op3A6C:
{
	sh2->r[10] += sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op3A7C:
{
	sh2->r[10] += sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op3A8C:
{
	sh2->r[10] += sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op3A9C:
{
	sh2->r[10] += sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op3AAC:
{
	sh2->r[10] += sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op3ABC:
{
	sh2->r[10] += sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op3ACC:
{
	sh2->r[10] += sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op3ADC:
{
	sh2->r[10] += sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op3AEC:
{
	sh2->r[10] += sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op3AFC:
{
	sh2->r[10] += sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op3B0C:
{
	sh2->r[11] += sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op3B1C:
{
	sh2->r[11] += sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op3B2C:
{
	sh2->r[11] += sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op3B3C:
{
	sh2->r[11] += sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op3B4C:
{
	sh2->r[11] += sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op3B5C:
{
	sh2->r[11] += sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op3B6C:
{
	sh2->r[11] += sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op3B7C:
{
	sh2->r[11] += sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op3B8C:
{
	sh2->r[11] += sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op3B9C:
{
	sh2->r[11] += sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op3BAC:
{
	sh2->r[11] += sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op3BBC:
{
	sh2->r[11] += sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op3BCC:
{
	sh2->r[11] += sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op3BDC:
{
	sh2->r[11] += sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op3BEC:
{
	sh2->r[11] += sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op3BFC:
{
	sh2->r[11] += sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op3C0C:
{
	sh2->r[12] += sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op3C1C:
{
	sh2->r[12] += sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op3C2C:
{
	sh2->r[12] += sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op3C3C:
{
	sh2->r[12] += sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op3C4C:
{
	sh2->r[12] += sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op3C5C:
{
	sh2->r[12] += sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op3C6C:
{
	sh2->r[12] += sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op3C7C:
{
	sh2->r[12] += sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op3C8C:
{
	sh2->r[12] += sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op3C9C:
{
	sh2->r[12] += sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op3CAC:
{
	sh2->r[12] += sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op3CBC:
{
	sh2->r[12] += sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op3CCC:
{
	sh2->r[12] += sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op3CDC:
{
	sh2->r[12] += sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op3CEC:
{
	sh2->r[12] += sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op3CFC:
{
	sh2->r[12] += sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op3D0C:
{
	sh2->r[13] += sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op3D1C:
{
	sh2->r[13] += sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op3D2C:
{
	sh2->r[13] += sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op3D3C:
{
	sh2->r[13] += sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op3D4C:
{
	sh2->r[13] += sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op3D5C:
{
	sh2->r[13] += sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op3D6C:
{
	sh2->r[13] += sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op3D7C:
{
	sh2->r[13] += sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op3D8C:
{
	sh2->r[13] += sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op3D9C:
{
	sh2->r[13] += sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op3DAC:
{
	sh2->r[13] += sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op3DBC:
{
	sh2->r[13] += sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op3DCC:
{
	sh2->r[13] += sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op3DDC:
{
	sh2->r[13] += sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op3DEC:
{
	sh2->r[13] += sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op3DFC:
{
	sh2->r[13] += sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op3E0C:
{
	sh2->r[14] += sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op3E1C:
{
	sh2->r[14] += sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op3E2C:
{
	sh2->r[14] += sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op3E3C:
{
	sh2->r[14] += sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op3E4C:
{
	sh2->r[14] += sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op3E5C:
{
	sh2->r[14] += sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op3E6C:
{
	sh2->r[14] += sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op3E7C:
{
	sh2->r[14] += sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op3E8C:
{
	sh2->r[14] += sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op3E9C:
{
	sh2->r[14] += sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op3EAC:
{
	sh2->r[14] += sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op3EBC:
{
	sh2->r[14] += sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op3ECC:
{
	sh2->r[14] += sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op3EDC:
{
	sh2->r[14] += sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op3EEC:
{
	sh2->r[14] += sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op3EFC:
{
	sh2->r[14] += sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op3F0C:
{
	sh2->r[15] += sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op3F1C:
{
	sh2->r[15] += sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op3F2C:
{
	sh2->r[15] += sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op3F3C:
{
	sh2->r[15] += sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op3F4C:
{
	sh2->r[15] += sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op3F5C:
{
	sh2->r[15] += sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op3F6C:
{
	sh2->r[15] += sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op3F7C:
{
	sh2->r[15] += sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op3F8C:
{
	sh2->r[15] += sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op3F9C:
{
	sh2->r[15] += sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op3FAC:
{
	sh2->r[15] += sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op3FBC:
{
	sh2->r[15] += sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op3FCC:
{
	sh2->r[15] += sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op3FDC:
{
	sh2->r[15] += sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op3FEC:
{
	sh2->r[15] += sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op3FFC:
{
	sh2->r[15] += sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

// DMULS.L Rm,Rn
Op300D:
{
	n = (opcode>>8) & 0x0f;
	m = (opcode>>4) & 0x0f;
	tempn = (INT32) sh2->r[n];
	tempm = (INT32) sh2->r[m];
	if (tempn < 0)
		tempn = 0 - tempn;
	if (tempm < 0)
		tempm = 0 - tempm;
	if ((INT32) (sh2->r[n] ^ sh2->r[m]) < 0)
		fnLmL = -1;
	else
		fnLmL = 0;
	temp1 = (UINT32) tempn;
	temp2 = (UINT32) tempm;
	RnL = temp1 & 0x0000ffff;
	RnH = (temp1 >> 16) & 0x0000ffff;
	RmL = temp2 & 0x0000ffff;
	RmH = (temp2 >> 16) & 0x0000ffff;
	temp0 = RmL * RnL;
	temp1 = RmH * RnL;
	temp2 = RmL * RnH;
	temp3 = RmH * RnH;
	Res2 = 0;
	Res1 = temp1 + temp2;
	if (Res1 < temp1)
		Res2 += 0x00010000;
	temp1 = (Res1 << 16) & 0xffff0000;
	Res0 = temp0 + temp1;
	if (Res0 < temp0)
		Res2++;
	Res2 = Res2 + ((Res1 >> 16) & 0x0000ffff) + temp3;
	if (fnLmL < 0)
	{
		Res2 = ~Res2;
		if (Res0 == 0)
			Res2++;
		else
			Res0 = (~Res0) + 1;
	}
	sh2->mach = Res2;
	sh2->macl = Res0;
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

// ADDC Rm,Rn
Op300E:
{
	n = (opcode>>8) & 0x0f;
	m = (opcode>>4) & 0x0f;
	tmp1 = sh2->r[n] + sh2->r[m];
	tmp0 = sh2->r[n];
	sh2->r[n] = tmp1 + (sh2->sr & T);
	if (tmp0 > tmp1)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	if (tmp1 > sh2->r[n])
		sh2->sr |= T;
	goto SH2_RUN_CONTINUE;
}

// ADDV Rm,Rn
Op300F:
{
	n = (opcode>>8) & 0x0f;
	m = (opcode>>4) & 0x0f;
	if ((INT32) sh2->r[n] >= 0)
		dest = 0;
	else
		dest = 1;
	if ((INT32) sh2->r[m] >= 0)
		src = 0;
	else
		src = 1;
	src += dest;
	sh2->r[n] += sh2->r[m];
	if ((INT32) sh2->r[n] >= 0)
		ans = 0;
	else
		ans = 1;
	ans += dest;
	if (src == 0 || src == 2)
	{
		if (ans == 1)
			sh2->sr |= T;
		else
			sh2->sr &= ~T;
	}
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

// SHAL Rn
Op4000:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[0] >> 31) & T);
	sh2->r[0] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4100:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[1] >> 31) & T);
	sh2->r[1] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4200:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[2] >> 31) & T);
	sh2->r[2] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4300:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[3] >> 31) & T);
	sh2->r[3] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4400:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[4] >> 31) & T);
	sh2->r[4] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4500:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[5] >> 31) & T);
	sh2->r[5] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4600:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[6] >> 31) & T);
	sh2->r[6] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4700:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[7] >> 31) & T);
	sh2->r[7] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4800:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[8] >> 31) & T);
	sh2->r[8] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4900:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[9] >> 31) & T);
	sh2->r[9] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4A00:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[10] >> 31) & T);
	sh2->r[10] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4B00:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[11] >> 31) & T);
	sh2->r[11] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4C00:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[12] >> 31) & T);
	sh2->r[12] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4D00:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[13] >> 31) & T);
	sh2->r[13] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4E00:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[14] >> 31) & T);
	sh2->r[14] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4F00:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[15] >> 31) & T);
	sh2->r[15] <<= 1;
	goto SH2_RUN_CONTINUE;
}

// SHLR Rn
Op4001:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[0] & T);
	sh2->r[0] >>= 1;
	goto SH2_RUN_CONTINUE;
}

Op4101:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[1] & T);
	sh2->r[1] >>= 1;
	goto SH2_RUN_CONTINUE;
}

Op4201:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[2] & T);
	sh2->r[2] >>= 1;
	goto SH2_RUN_CONTINUE;
}

Op4301:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[3] & T);
	sh2->r[3] >>= 1;
	goto SH2_RUN_CONTINUE;
}

Op4401:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[4] & T);
	sh2->r[4] >>= 1;
	goto SH2_RUN_CONTINUE;
}

Op4501:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[5] & T);
	sh2->r[5] >>= 1;
	goto SH2_RUN_CONTINUE;
}

Op4601:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[6] & T);
	sh2->r[6] >>= 1;
	goto SH2_RUN_CONTINUE;
}

Op4701:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[7] & T);
	sh2->r[7] >>= 1;
	goto SH2_RUN_CONTINUE;
}

Op4801:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[8] & T);
	sh2->r[8] >>= 1;
	goto SH2_RUN_CONTINUE;
}

Op4901:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[9] & T);
	sh2->r[9] >>= 1;
	goto SH2_RUN_CONTINUE;
}

Op4A01:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[10] & T);
	sh2->r[10] >>= 1;
	goto SH2_RUN_CONTINUE;
}

Op4B01:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[11] & T);
	sh2->r[11] >>= 1;
	goto SH2_RUN_CONTINUE;
}

Op4C01:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[12] & T);
	sh2->r[12] >>= 1;
	goto SH2_RUN_CONTINUE;
}

Op4D01:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[13] & T);
	sh2->r[13] >>= 1;
	goto SH2_RUN_CONTINUE;
}

Op4E01:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[14] & T);
	sh2->r[14] >>= 1;
	goto SH2_RUN_CONTINUE;
}

Op4F01:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[15] & T);
	sh2->r[15] >>= 1;
	goto SH2_RUN_CONTINUE;
}

// STS.L MACH,@-Rn
Op4002:
{
	sh2->r[0] -= 4;
	sh2->ea = sh2->r[0];
	WL( sh2->ea, sh2->mach );
	goto SH2_RUN_CONTINUE;
}

Op4102:
{
	sh2->r[1] -= 4;
	sh2->ea = sh2->r[1];
	WL( sh2->ea, sh2->mach );
	goto SH2_RUN_CONTINUE;
}

Op4202:
{
	sh2->r[2] -= 4;
	sh2->ea = sh2->r[2];
	WL( sh2->ea, sh2->mach );
	goto SH2_RUN_CONTINUE;
}

Op4302:
{
	sh2->r[3] -= 4;
	sh2->ea = sh2->r[3];
	WL( sh2->ea, sh2->mach );
	goto SH2_RUN_CONTINUE;
}

Op4402:
{
	sh2->r[4] -= 4;
	sh2->ea = sh2->r[4];
	WL( sh2->ea, sh2->mach );
	goto SH2_RUN_CONTINUE;
}

Op4502:
{
	sh2->r[5] -= 4;
	sh2->ea = sh2->r[5];
	WL( sh2->ea, sh2->mach );
	goto SH2_RUN_CONTINUE;
}

Op4602:
{
	sh2->r[6] -= 4;
	sh2->ea = sh2->r[6];
	WL( sh2->ea, sh2->mach );
	goto SH2_RUN_CONTINUE;
}

Op4702:
{
	sh2->r[7] -= 4;
	sh2->ea = sh2->r[7];
	WL( sh2->ea, sh2->mach );
	goto SH2_RUN_CONTINUE;
}

Op4802:
{
	sh2->r[8] -= 4;
	sh2->ea = sh2->r[8];
	WL( sh2->ea, sh2->mach );
	goto SH2_RUN_CONTINUE;
}

Op4902:
{
	sh2->r[9] -= 4;
	sh2->ea = sh2->r[9];
	WL( sh2->ea, sh2->mach );
	goto SH2_RUN_CONTINUE;
}

Op4A02:
{
	sh2->r[10] -= 4;
	sh2->ea = sh2->r[10];
	WL( sh2->ea, sh2->mach );
	goto SH2_RUN_CONTINUE;
}

Op4B02:
{
	sh2->r[11] -= 4;
	sh2->ea = sh2->r[11];
	WL( sh2->ea, sh2->mach );
	goto SH2_RUN_CONTINUE;
}

Op4C02:
{
	sh2->r[12] -= 4;
	sh2->ea = sh2->r[12];
	WL( sh2->ea, sh2->mach );
	goto SH2_RUN_CONTINUE;
}

Op4D02:
{
	sh2->r[13] -= 4;
	sh2->ea = sh2->r[13];
	WL( sh2->ea, sh2->mach );
	goto SH2_RUN_CONTINUE;
}

Op4E02:
{
	sh2->r[14] -= 4;
	sh2->ea = sh2->r[14];
	WL( sh2->ea, sh2->mach );
	goto SH2_RUN_CONTINUE;
}

Op4F02:
{
	sh2->r[15] -= 4;
	sh2->ea = sh2->r[15];
	WL( sh2->ea, sh2->mach );
	goto SH2_RUN_CONTINUE;
}

// STC.L SR,@-Rn
Op4003:
{
	sh2->r[0] -= 4;
	sh2->ea = sh2->r[0];
	WL( sh2->ea, sh2->sr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4103:
{
	sh2->r[1] -= 4;
	sh2->ea = sh2->r[1];
	WL( sh2->ea, sh2->sr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4203:
{
	sh2->r[2] -= 4;
	sh2->ea = sh2->r[2];
	WL( sh2->ea, sh2->sr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4303:
{
	sh2->r[3] -= 4;
	sh2->ea = sh2->r[3];
	WL( sh2->ea, sh2->sr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4403:
{
	sh2->r[4] -= 4;
	sh2->ea = sh2->r[4];
	WL( sh2->ea, sh2->sr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4503:
{
	sh2->r[5] -= 4;
	sh2->ea = sh2->r[5];
	WL( sh2->ea, sh2->sr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4603:
{
	sh2->r[6] -= 4;
	sh2->ea = sh2->r[6];
	WL( sh2->ea, sh2->sr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4703:
{
	sh2->r[7] -= 4;
	sh2->ea = sh2->r[7];
	WL( sh2->ea, sh2->sr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4803:
{
	sh2->r[8] -= 4;
	sh2->ea = sh2->r[8];
	WL( sh2->ea, sh2->sr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4903:
{
	sh2->r[9] -= 4;
	sh2->ea = sh2->r[9];
	WL( sh2->ea, sh2->sr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4A03:
{
	sh2->r[10] -= 4;
	sh2->ea = sh2->r[10];
	WL( sh2->ea, sh2->sr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4B03:
{
	sh2->r[11] -= 4;
	sh2->ea = sh2->r[11];
	WL( sh2->ea, sh2->sr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4C03:
{
	sh2->r[12] -= 4;
	sh2->ea = sh2->r[12];
	WL( sh2->ea, sh2->sr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4D03:
{
	sh2->r[13] -= 4;
	sh2->ea = sh2->r[13];
	WL( sh2->ea, sh2->sr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4E03:
{
	sh2->r[14] -= 4;
	sh2->ea = sh2->r[14];
	WL( sh2->ea, sh2->sr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4F03:
{
	sh2->r[15] -= 4;
	sh2->ea = sh2->r[15];
	WL( sh2->ea, sh2->sr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

// ROTL Rn
Op4004:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[0] >> 31) & T);
	sh2->r[0] = (sh2->r[0] << 1) | (sh2->r[0] >> 31);
	goto SH2_RUN_CONTINUE;
}

Op4104:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[1] >> 31) & T);
	sh2->r[1] = (sh2->r[1] << 1) | (sh2->r[1] >> 31);
	goto SH2_RUN_CONTINUE;
}

Op4204:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[2] >> 31) & T);
	sh2->r[2] = (sh2->r[2] << 1) | (sh2->r[2] >> 31);
	goto SH2_RUN_CONTINUE;
}

Op4304:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[3] >> 31) & T);
	sh2->r[3] = (sh2->r[3] << 1) | (sh2->r[3] >> 31);
	goto SH2_RUN_CONTINUE;
}

Op4404:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[4] >> 31) & T);
	sh2->r[4] = (sh2->r[4] << 1) | (sh2->r[4] >> 31);
	goto SH2_RUN_CONTINUE;
}

Op4504:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[5] >> 31) & T);
	sh2->r[5] = (sh2->r[5] << 1) | (sh2->r[5] >> 31);
	goto SH2_RUN_CONTINUE;
}

Op4604:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[6] >> 31) & T);
	sh2->r[6] = (sh2->r[6] << 1) | (sh2->r[6] >> 31);
	goto SH2_RUN_CONTINUE;
}

Op4704:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[7] >> 31) & T);
	sh2->r[7] = (sh2->r[7] << 1) | (sh2->r[7] >> 31);
	goto SH2_RUN_CONTINUE;
}

Op4804:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[8] >> 31) & T);
	sh2->r[8] = (sh2->r[8] << 1) | (sh2->r[8] >> 31);
	goto SH2_RUN_CONTINUE;
}

Op4904:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[9] >> 31) & T);
	sh2->r[9] = (sh2->r[9] << 1) | (sh2->r[9] >> 31);
	goto SH2_RUN_CONTINUE;
}

Op4A04:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[10] >> 31) & T);
	sh2->r[10] = (sh2->r[10] << 1) | (sh2->r[10] >> 31);
	goto SH2_RUN_CONTINUE;
}

Op4B04:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[11] >> 31) & T);
	sh2->r[11] = (sh2->r[11] << 1) | (sh2->r[11] >> 31);
	goto SH2_RUN_CONTINUE;
}

Op4C04:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[12] >> 31) & T);
	sh2->r[12] = (sh2->r[12] << 1) | (sh2->r[12] >> 31);
	goto SH2_RUN_CONTINUE;
}

Op4D04:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[13] >> 31) & T);
	sh2->r[13] = (sh2->r[13] << 1) | (sh2->r[13] >> 31);
	goto SH2_RUN_CONTINUE;
}

Op4E04:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[14] >> 31) & T);
	sh2->r[14] = (sh2->r[14] << 1) | (sh2->r[14] >> 31);
	goto SH2_RUN_CONTINUE;
}

Op4F04:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[15] >> 31) & T);
	sh2->r[15] = (sh2->r[15] << 1) | (sh2->r[15] >> 31);
	goto SH2_RUN_CONTINUE;
}

// ROTR Rn
Op4005:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[0] & T);
	sh2->r[0] = (sh2->r[0] >> 1) | (sh2->r[0] << 31);
	goto SH2_RUN_CONTINUE;
}

Op4105:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[1] & T);
	sh2->r[1] = (sh2->r[1] >> 1) | (sh2->r[1] << 31);
	goto SH2_RUN_CONTINUE;
}

Op4205:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[2] & T);
	sh2->r[2] = (sh2->r[2] >> 1) | (sh2->r[2] << 31);
	goto SH2_RUN_CONTINUE;
}

Op4305:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[3] & T);
	sh2->r[3] = (sh2->r[3] >> 1) | (sh2->r[3] << 31);
	goto SH2_RUN_CONTINUE;
}

Op4405:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[4] & T);
	sh2->r[4] = (sh2->r[4] >> 1) | (sh2->r[4] << 31);
	goto SH2_RUN_CONTINUE;
}

Op4505:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[5] & T);
	sh2->r[5] = (sh2->r[5] >> 1) | (sh2->r[5] << 31);
	goto SH2_RUN_CONTINUE;
}

Op4605:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[6] & T);
	sh2->r[6] = (sh2->r[6] >> 1) | (sh2->r[6] << 31);
	goto SH2_RUN_CONTINUE;
}

Op4705:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[7] & T);
	sh2->r[7] = (sh2->r[7] >> 1) | (sh2->r[7] << 31);
	goto SH2_RUN_CONTINUE;
}

Op4805:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[8] & T);
	sh2->r[8] = (sh2->r[8] >> 1) | (sh2->r[8] << 31);
	goto SH2_RUN_CONTINUE;
}

Op4905:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[9] & T);
	sh2->r[9] = (sh2->r[9] >> 1) | (sh2->r[9] << 31);
	goto SH2_RUN_CONTINUE;
}

Op4A05:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[10] & T);
	sh2->r[10] = (sh2->r[10] >> 1) | (sh2->r[10] << 31);
	goto SH2_RUN_CONTINUE;
}

Op4B05:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[11] & T);
	sh2->r[11] = (sh2->r[11] >> 1) | (sh2->r[11] << 31);
	goto SH2_RUN_CONTINUE;
}

Op4C05:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[12] & T);
	sh2->r[12] = (sh2->r[12] >> 1) | (sh2->r[12] << 31);
	goto SH2_RUN_CONTINUE;
}

Op4D05:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[13] & T);
	sh2->r[13] = (sh2->r[13] >> 1) | (sh2->r[13] << 31);
	goto SH2_RUN_CONTINUE;
}

Op4E05:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[14] & T);
	sh2->r[14] = (sh2->r[14] >> 1) | (sh2->r[14] << 31);
	goto SH2_RUN_CONTINUE;
}

Op4F05:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[15] & T);
	sh2->r[15] = (sh2->r[15] >> 1) | (sh2->r[15] << 31);
	goto SH2_RUN_CONTINUE;
}

// LDS.L @Rn+,MACH
Op4006:
{
	sh2->ea = sh2->r[0];
	sh2->mach = RL( sh2->ea );
	sh2->r[0] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4106:
{
	sh2->ea = sh2->r[1];
	sh2->mach = RL( sh2->ea );
	sh2->r[1] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4206:
{
	sh2->ea = sh2->r[2];
	sh2->mach = RL( sh2->ea );
	sh2->r[2] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4306:
{
	sh2->ea = sh2->r[3];
	sh2->mach = RL( sh2->ea );
	sh2->r[3] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4406:
{
	sh2->ea = sh2->r[4];
	sh2->mach = RL( sh2->ea );
	sh2->r[4] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4506:
{
	sh2->ea = sh2->r[5];
	sh2->mach = RL( sh2->ea );
	sh2->r[5] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4606:
{
	sh2->ea = sh2->r[6];
	sh2->mach = RL( sh2->ea );
	sh2->r[6] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4706:
{
	sh2->ea = sh2->r[7];
	sh2->mach = RL( sh2->ea );
	sh2->r[7] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4806:
{
	sh2->ea = sh2->r[8];
	sh2->mach = RL( sh2->ea );
	sh2->r[8] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4906:
{
	sh2->ea = sh2->r[9];
	sh2->mach = RL( sh2->ea );
	sh2->r[9] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4A06:
{
	sh2->ea = sh2->r[10];
	sh2->mach = RL( sh2->ea );
	sh2->r[10] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4B06:
{
	sh2->ea = sh2->r[11];
	sh2->mach = RL( sh2->ea );
	sh2->r[11] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4C06:
{
	sh2->ea = sh2->r[12];
	sh2->mach = RL( sh2->ea );
	sh2->r[12] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4D06:
{
	sh2->ea = sh2->r[13];
	sh2->mach = RL( sh2->ea );
	sh2->r[13] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4E06:
{
	sh2->ea = sh2->r[14];
	sh2->mach = RL( sh2->ea );
	sh2->r[14] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4F06:
{
	sh2->ea = sh2->r[15];
	sh2->mach = RL( sh2->ea );
	sh2->r[15] += 4;
	goto SH2_RUN_CONTINUE;
}

// LDC.L @Rn+,SR
Op4007:
{
	sh2->ea = sh2->r[0];
	sh2->sr = RL( sh2->ea ) & FLAGS;
	sh2->r[0] += 4;
	sh2->sh2_icount -= 2;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op4107:
{
	sh2->ea = sh2->r[1];
	sh2->sr = RL( sh2->ea ) & FLAGS;
	sh2->r[1] += 4;
	sh2->sh2_icount -= 2;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op4207:
{
	sh2->ea = sh2->r[2];
	sh2->sr = RL( sh2->ea ) & FLAGS;
	sh2->r[2] += 4;
	sh2->sh2_icount -= 2;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op4307:
{
	sh2->ea = sh2->r[3];
	sh2->sr = RL( sh2->ea ) & FLAGS;
	sh2->r[3] += 4;
	sh2->sh2_icount -= 2;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op4407:
{
	sh2->ea = sh2->r[4];
	sh2->sr = RL( sh2->ea ) & FLAGS;
	sh2->r[4] += 4;
	sh2->sh2_icount -= 2;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op4507:
{
	sh2->ea = sh2->r[5];
	sh2->sr = RL( sh2->ea ) & FLAGS;
	sh2->r[5] += 4;
	sh2->sh2_icount -= 2;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op4607:
{
	sh2->ea = sh2->r[6];
	sh2->sr = RL( sh2->ea ) & FLAGS;
	sh2->r[6] += 4;
	sh2->sh2_icount -= 2;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op4707:
{
	sh2->ea = sh2->r[7];
	sh2->sr = RL( sh2->ea ) & FLAGS;
	sh2->r[7] += 4;
	sh2->sh2_icount -= 2;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op4807:
{
	sh2->ea = sh2->r[8];
	sh2->sr = RL( sh2->ea ) & FLAGS;
	sh2->r[8] += 4;
	sh2->sh2_icount -= 2;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op4907:
{
	sh2->ea = sh2->r[9];
	sh2->sr = RL( sh2->ea ) & FLAGS;
	sh2->r[9] += 4;
	sh2->sh2_icount -= 2;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op4A07:
{
	sh2->ea = sh2->r[10];
	sh2->sr = RL( sh2->ea ) & FLAGS;
	sh2->r[10] += 4;
	sh2->sh2_icount -= 2;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op4B07:
{
	sh2->ea = sh2->r[11];
	sh2->sr = RL( sh2->ea ) & FLAGS;
	sh2->r[11] += 4;
	sh2->sh2_icount -= 2;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op4C07:
{
	sh2->ea = sh2->r[12];
	sh2->sr = RL( sh2->ea ) & FLAGS;
	sh2->r[12] += 4;
	sh2->sh2_icount -= 2;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op4D07:
{
	sh2->ea = sh2->r[13];
	sh2->sr = RL( sh2->ea ) & FLAGS;
	sh2->r[13] += 4;
	sh2->sh2_icount -= 2;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op4E07:
{
	sh2->ea = sh2->r[14];
	sh2->sr = RL( sh2->ea ) & FLAGS;
	sh2->r[14] += 4;
	sh2->sh2_icount -= 2;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op4F07:
{
	sh2->ea = sh2->r[15];
	sh2->sr = RL( sh2->ea ) & FLAGS;
	sh2->r[15] += 4;
	sh2->sh2_icount -= 2;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

// SHLL2 Rn
Op4008:
{
	sh2->r[0] <<= 2;
	goto SH2_RUN_CONTINUE;
}

Op4108:
{
	sh2->r[1] <<= 2;
	goto SH2_RUN_CONTINUE;
}

Op4208:
{
	sh2->r[2] <<= 2;
	goto SH2_RUN_CONTINUE;
}

Op4308:
{
	sh2->r[3] <<= 2;
	goto SH2_RUN_CONTINUE;
}

Op4408:
{
	sh2->r[4] <<= 2;
	goto SH2_RUN_CONTINUE;
}

Op4508:
{
	sh2->r[5] <<= 2;
	goto SH2_RUN_CONTINUE;
}

Op4608:
{
	sh2->r[6] <<= 2;
	goto SH2_RUN_CONTINUE;
}

Op4708:
{
	sh2->r[7] <<= 2;
	goto SH2_RUN_CONTINUE;
}

Op4808:
{
	sh2->r[8] <<= 2;
	goto SH2_RUN_CONTINUE;
}

Op4908:
{
	sh2->r[9] <<= 2;
	goto SH2_RUN_CONTINUE;
}

Op4A08:
{
	sh2->r[10] <<= 2;
	goto SH2_RUN_CONTINUE;
}

Op4B08:
{
	sh2->r[11] <<= 2;
	goto SH2_RUN_CONTINUE;
}

Op4C08:
{
	sh2->r[12] <<= 2;
	goto SH2_RUN_CONTINUE;
}

Op4D08:
{
	sh2->r[13] <<= 2;
	goto SH2_RUN_CONTINUE;
}

Op4E08:
{
	sh2->r[14] <<= 2;
	goto SH2_RUN_CONTINUE;
}

Op4F08:
{
	sh2->r[15] <<= 2;
	goto SH2_RUN_CONTINUE;
}

// SHLR2 Rn
Op4009:
{
	sh2->r[0] >>= 2;
	goto SH2_RUN_CONTINUE;
}

Op4109:
{
	sh2->r[1] >>= 2;
	goto SH2_RUN_CONTINUE;
}

Op4209:
{
	sh2->r[2] >>= 2;
	goto SH2_RUN_CONTINUE;
}

Op4309:
{
	sh2->r[3] >>= 2;
	goto SH2_RUN_CONTINUE;
}

Op4409:
{
	sh2->r[4] >>= 2;
	goto SH2_RUN_CONTINUE;
}

Op4509:
{
	sh2->r[5] >>= 2;
	goto SH2_RUN_CONTINUE;
}

Op4609:
{
	sh2->r[6] >>= 2;
	goto SH2_RUN_CONTINUE;
}

Op4709:
{
	sh2->r[7] >>= 2;
	goto SH2_RUN_CONTINUE;
}

Op4809:
{
	sh2->r[8] >>= 2;
	goto SH2_RUN_CONTINUE;
}

Op4909:
{
	sh2->r[9] >>= 2;
	goto SH2_RUN_CONTINUE;
}

Op4A09:
{
	sh2->r[10] >>= 2;
	goto SH2_RUN_CONTINUE;
}

Op4B09:
{
	sh2->r[11] >>= 2;
	goto SH2_RUN_CONTINUE;
}

Op4C09:
{
	sh2->r[12] >>= 2;
	goto SH2_RUN_CONTINUE;
}

Op4D09:
{
	sh2->r[13] >>= 2;
	goto SH2_RUN_CONTINUE;
}

Op4E09:
{
	sh2->r[14] >>= 2;
	goto SH2_RUN_CONTINUE;
}

Op4F09:
{
	sh2->r[15] >>= 2;
	goto SH2_RUN_CONTINUE;
}

// LDS Rn,MACH
Op400A:
{
	sh2->mach = sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op410A:
{
	sh2->mach = sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op420A:
{
	sh2->mach = sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op430A:
{
	sh2->mach = sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op440A:
{
	sh2->mach = sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op450A:
{
	sh2->mach = sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op460A:
{
	sh2->mach = sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op470A:
{
	sh2->mach = sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op480A:
{
	sh2->mach = sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op490A:
{
	sh2->mach = sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op4A0A:
{
	sh2->mach = sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op4B0A:
{
	sh2->mach = sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op4C0A:
{
	sh2->mach = sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op4D0A:
{
	sh2->mach = sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op4E0A:
{
	sh2->mach = sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op4F0A:
{
	sh2->mach = sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

// JSR @Rn
Op400B:
{
	sh2->delay = sh2->pc;
	sh2->pr = sh2->pc + 2;
	sh2->pc = sh2->ea = sh2->r[0];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op410B:
{
	sh2->delay = sh2->pc;
	sh2->pr = sh2->pc + 2;
	sh2->pc = sh2->ea = sh2->r[1];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op420B:
{
	sh2->delay = sh2->pc;
	sh2->pr = sh2->pc + 2;
	sh2->pc = sh2->ea = sh2->r[2];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op430B:
{
	sh2->delay = sh2->pc;
	sh2->pr = sh2->pc + 2;
	sh2->pc = sh2->ea = sh2->r[3];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op440B:
{
	sh2->delay = sh2->pc;
	sh2->pr = sh2->pc + 2;
	sh2->pc = sh2->ea = sh2->r[4];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op450B:
{
	sh2->delay = sh2->pc;
	sh2->pr = sh2->pc + 2;
	sh2->pc = sh2->ea = sh2->r[5];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op460B:
{
	sh2->delay = sh2->pc;
	sh2->pr = sh2->pc + 2;
	sh2->pc = sh2->ea = sh2->r[6];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op470B:
{
	sh2->delay = sh2->pc;
	sh2->pr = sh2->pc + 2;
	sh2->pc = sh2->ea = sh2->r[7];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op480B:
{
	sh2->delay = sh2->pc;
	sh2->pr = sh2->pc + 2;
	sh2->pc = sh2->ea = sh2->r[8];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op490B:
{
	sh2->delay = sh2->pc;
	sh2->pr = sh2->pc + 2;
	sh2->pc = sh2->ea = sh2->r[9];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4A0B:
{
	sh2->delay = sh2->pc;
	sh2->pr = sh2->pc + 2;
	sh2->pc = sh2->ea = sh2->r[10];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4B0B:
{
	sh2->delay = sh2->pc;
	sh2->pr = sh2->pc + 2;
	sh2->pc = sh2->ea = sh2->r[11];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4C0B:
{
	sh2->delay = sh2->pc;
	sh2->pr = sh2->pc + 2;
	sh2->pc = sh2->ea = sh2->r[12];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4D0B:
{
	sh2->delay = sh2->pc;
	sh2->pr = sh2->pc + 2;
	sh2->pc = sh2->ea = sh2->r[13];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4E0B:
{
	sh2->delay = sh2->pc;
	sh2->pr = sh2->pc + 2;
	sh2->pc = sh2->ea = sh2->r[14];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4F0B:
{
	sh2->delay = sh2->pc;
	sh2->pr = sh2->pc + 2;
	sh2->pc = sh2->ea = sh2->r[15];
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

// LDC Rn,SR
Op400E:
{
	sh2->sr = sh2->r[0] & FLAGS;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op410E:
{
	sh2->sr = sh2->r[1] & FLAGS;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op420E:
{
	sh2->sr = sh2->r[2] & FLAGS;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op430E:
{
	sh2->sr = sh2->r[3] & FLAGS;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op440E:
{
	sh2->sr = sh2->r[4] & FLAGS;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op450E:
{
	sh2->sr = sh2->r[5] & FLAGS;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op460E:
{
	sh2->sr = sh2->r[6] & FLAGS;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op470E:
{
	sh2->sr = sh2->r[7] & FLAGS;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op480E:
{
	sh2->sr = sh2->r[8] & FLAGS;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op490E:
{
	sh2->sr = sh2->r[9] & FLAGS;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op4A0E:
{
	sh2->sr = sh2->r[10] & FLAGS;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op4B0E:
{
	sh2->sr = sh2->r[11] & FLAGS;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op4C0E:
{
	sh2->sr = sh2->r[12] & FLAGS;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op4D0E:
{
	sh2->sr = sh2->r[13] & FLAGS;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op4E0E:
{
	sh2->sr = sh2->r[14] & FLAGS;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

Op4F0E:
{
	sh2->sr = sh2->r[15] & FLAGS;
	sh2->test_irq = 1;
	goto SH2_RUN_CONTINUE;
}

// MAC.W @Rm+,@Rn+
Op400F:
{
	n = (opcode>>8) & 0x0f;
	m = (opcode>>4) & 0x0f;
	tempn = (INT32) RW( sh2->r[n] );
	sh2->r[n] += 2;
	tempm = (INT32) RW( sh2->r[m] );
	sh2->r[m] += 2;
	templ = sh2->macl;
	tempm = ((INT32) (short) tempn * (INT32) (short) tempm);
	if ((INT32) sh2->macl >= 0)
		dest = 0;
	else
		dest = 1;
	if ((INT32) tempm >= 0)
	{
		src = 0;
		tempn = 0;
	}
	else
	{
		src = 1;
		tempn = 0xffffffff;
	}
	src += dest;
	sh2->macl += tempm;
	if ((INT32) sh2->macl >= 0)
		ans = 0;
	else
		ans = 1;
	ans += dest;
	if (sh2->sr & S)
	{
		if (ans == 1)
			{
				if (src == 0)
					sh2->macl = 0x7fffffff;
				if (src == 2)
					sh2->macl = 0x80000000;
			}
	}
	else
	{
		sh2->mach += tempn;
		if (templ > sh2->macl)
			sh2->mach += 1;
		}
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

// DT Rn
Op4010:
{
	n = (opcode>>8) & 0x0f;
	sh2->r[n]--;
	if (sh2->r[n] == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
#if BUSY_LOOP_HACKS
	{
		UINT32 next_opcode = OPRW(sh2->ppc & AM);
		if (next_opcode == 0x8bfd)
		{
			while (sh2->r[n] > 1 && sh2->sh2_icount > 4)
			{
				sh2->r[n]--;
				sh2->sh2_icount -= 4;
			}
		}
	}
#endif
	goto SH2_RUN_CONTINUE;
}

// CMP_PZ Rn
Op4011:
{
	if ((INT32) sh2->r[0] >= 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4111:
{
	if ((INT32) sh2->r[1] >= 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4211:
{
	if ((INT32) sh2->r[2] >= 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4311:
{
	if ((INT32) sh2->r[3] >= 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4411:
{
	if ((INT32) sh2->r[4] >= 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4511:
{
	if ((INT32) sh2->r[5] >= 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4611:
{
	if ((INT32) sh2->r[6] >= 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4711:
{
	if ((INT32) sh2->r[7] >= 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4811:
{
	if ((INT32) sh2->r[8] >= 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4911:
{
	if ((INT32) sh2->r[9] >= 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4A11:
{
	if ((INT32) sh2->r[10] >= 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4B11:
{
	if ((INT32) sh2->r[11] >= 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4C11:
{
	if ((INT32) sh2->r[12] >= 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4D11:
{
	if ((INT32) sh2->r[13] >= 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4E11:
{
	if ((INT32) sh2->r[14] >= 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4F11:
{
	if ((INT32) sh2->r[15] >= 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

// STS.L MACL,@-Rn
Op4012:
{
	sh2->r[0] -= 4;
	sh2->ea = sh2->r[0];
	WL( sh2->ea, sh2->macl );
	goto SH2_RUN_CONTINUE;
}

Op4112:
{
	sh2->r[1] -= 4;
	sh2->ea = sh2->r[1];
	WL( sh2->ea, sh2->macl );
	goto SH2_RUN_CONTINUE;
}

Op4212:
{
	sh2->r[2] -= 4;
	sh2->ea = sh2->r[2];
	WL( sh2->ea, sh2->macl );
	goto SH2_RUN_CONTINUE;
}

Op4312:
{
	sh2->r[3] -= 4;
	sh2->ea = sh2->r[3];
	WL( sh2->ea, sh2->macl );
	goto SH2_RUN_CONTINUE;
}

Op4412:
{
	sh2->r[4] -= 4;
	sh2->ea = sh2->r[4];
	WL( sh2->ea, sh2->macl );
	goto SH2_RUN_CONTINUE;
}

Op4512:
{
	sh2->r[5] -= 4;
	sh2->ea = sh2->r[5];
	WL( sh2->ea, sh2->macl );
	goto SH2_RUN_CONTINUE;
}

Op4612:
{
	sh2->r[6] -= 4;
	sh2->ea = sh2->r[6];
	WL( sh2->ea, sh2->macl );
	goto SH2_RUN_CONTINUE;
}

Op4712:
{
	sh2->r[7] -= 4;
	sh2->ea = sh2->r[7];
	WL( sh2->ea, sh2->macl );
	goto SH2_RUN_CONTINUE;
}

Op4812:
{
	sh2->r[8] -= 4;
	sh2->ea = sh2->r[8];
	WL( sh2->ea, sh2->macl );
	goto SH2_RUN_CONTINUE;
}

Op4912:
{
	sh2->r[9] -= 4;
	sh2->ea = sh2->r[9];
	WL( sh2->ea, sh2->macl );
	goto SH2_RUN_CONTINUE;
}

Op4A12:
{
	sh2->r[10] -= 4;
	sh2->ea = sh2->r[10];
	WL( sh2->ea, sh2->macl );
	goto SH2_RUN_CONTINUE;
}

Op4B12:
{
	sh2->r[11] -= 4;
	sh2->ea = sh2->r[11];
	WL( sh2->ea, sh2->macl );
	goto SH2_RUN_CONTINUE;
}

Op4C12:
{
	sh2->r[12] -= 4;
	sh2->ea = sh2->r[12];
	WL( sh2->ea, sh2->macl );
	goto SH2_RUN_CONTINUE;
}

Op4D12:
{
	sh2->r[13] -= 4;
	sh2->ea = sh2->r[13];
	WL( sh2->ea, sh2->macl );
	goto SH2_RUN_CONTINUE;
}

Op4E12:
{
	sh2->r[14] -= 4;
	sh2->ea = sh2->r[14];
	WL( sh2->ea, sh2->macl );
	goto SH2_RUN_CONTINUE;
}

Op4F12:
{
	sh2->r[15] -= 4;
	sh2->ea = sh2->r[15];
	WL( sh2->ea, sh2->macl );
	goto SH2_RUN_CONTINUE;
}

// STC.L GBR,@-Rn
Op4013:
{
	sh2->r[0] -= 4;
	sh2->ea = sh2->r[0];
	WL( sh2->ea, sh2->gbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4113:
{
	sh2->r[1] -= 4;
	sh2->ea = sh2->r[1];
	WL( sh2->ea, sh2->gbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4213:
{
	sh2->r[2] -= 4;
	sh2->ea = sh2->r[2];
	WL( sh2->ea, sh2->gbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4313:
{
	sh2->r[3] -= 4;
	sh2->ea = sh2->r[3];
	WL( sh2->ea, sh2->gbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4413:
{
	sh2->r[4] -= 4;
	sh2->ea = sh2->r[4];
	WL( sh2->ea, sh2->gbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4513:
{
	sh2->r[5] -= 4;
	sh2->ea = sh2->r[5];
	WL( sh2->ea, sh2->gbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4613:
{
	sh2->r[6] -= 4;
	sh2->ea = sh2->r[6];
	WL( sh2->ea, sh2->gbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4713:
{
	sh2->r[7] -= 4;
	sh2->ea = sh2->r[7];
	WL( sh2->ea, sh2->gbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4813:
{
	sh2->r[8] -= 4;
	sh2->ea = sh2->r[8];
	WL( sh2->ea, sh2->gbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4913:
{
	sh2->r[9] -= 4;
	sh2->ea = sh2->r[9];
	WL( sh2->ea, sh2->gbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4A13:
{
	sh2->r[10] -= 4;
	sh2->ea = sh2->r[10];
	WL( sh2->ea, sh2->gbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4B13:
{
	sh2->r[11] -= 4;
	sh2->ea = sh2->r[11];
	WL( sh2->ea, sh2->gbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4C13:
{
	sh2->r[12] -= 4;
	sh2->ea = sh2->r[12];
	WL( sh2->ea, sh2->gbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4D13:
{
	sh2->r[13] -= 4;
	sh2->ea = sh2->r[13];
	WL( sh2->ea, sh2->gbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4E13:
{
	sh2->r[14] -= 4;
	sh2->ea = sh2->r[14];
	WL( sh2->ea, sh2->gbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4F13:
{
	sh2->r[15] -= 4;
	sh2->ea = sh2->r[15];
	WL( sh2->ea, sh2->gbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

// CMP_PL Rn
Op4015:
{
	if ((INT32) sh2->r[0] > 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4115:
{
	if ((INT32) sh2->r[1] > 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4215:
{
	if ((INT32) sh2->r[2] > 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4315:
{
	if ((INT32) sh2->r[3] > 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4415:
{
	if ((INT32) sh2->r[4] > 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4515:
{
	if ((INT32) sh2->r[5] > 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4615:
{
	if ((INT32) sh2->r[6] > 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4715:
{
	if ((INT32) sh2->r[7] > 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4815:
{
	if ((INT32) sh2->r[8] > 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4915:
{
	if ((INT32) sh2->r[9] > 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4A15:
{
	if ((INT32) sh2->r[10] > 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4B15:
{
	if ((INT32) sh2->r[11] > 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4C15:
{
	if ((INT32) sh2->r[12] > 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4D15:
{
	if ((INT32) sh2->r[13] > 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4E15:
{
	if ((INT32) sh2->r[14] > 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

Op4F15:
{
	if ((INT32) sh2->r[15] > 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	goto SH2_RUN_CONTINUE;
}

// LDS.L @Rn+,MACL
Op4016:
{
	sh2->ea = sh2->r[0];
	sh2->macl = RL( sh2->ea );
	sh2->r[0] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4116:
{
	sh2->ea = sh2->r[1];
	sh2->macl = RL( sh2->ea );
	sh2->r[1] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4216:
{
	sh2->ea = sh2->r[2];
	sh2->macl = RL( sh2->ea );
	sh2->r[2] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4316:
{
	sh2->ea = sh2->r[3];
	sh2->macl = RL( sh2->ea );
	sh2->r[3] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4416:
{
	sh2->ea = sh2->r[4];
	sh2->macl = RL( sh2->ea );
	sh2->r[4] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4516:
{
	sh2->ea = sh2->r[5];
	sh2->macl = RL( sh2->ea );
	sh2->r[5] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4616:
{
	sh2->ea = sh2->r[6];
	sh2->macl = RL( sh2->ea );
	sh2->r[6] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4716:
{
	sh2->ea = sh2->r[7];
	sh2->macl = RL( sh2->ea );
	sh2->r[7] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4816:
{
	sh2->ea = sh2->r[8];
	sh2->macl = RL( sh2->ea );
	sh2->r[8] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4916:
{
	sh2->ea = sh2->r[9];
	sh2->macl = RL( sh2->ea );
	sh2->r[9] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4A16:
{
	sh2->ea = sh2->r[10];
	sh2->macl = RL( sh2->ea );
	sh2->r[10] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4B16:
{
	sh2->ea = sh2->r[11];
	sh2->macl = RL( sh2->ea );
	sh2->r[11] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4C16:
{
	sh2->ea = sh2->r[12];
	sh2->macl = RL( sh2->ea );
	sh2->r[12] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4D16:
{
	sh2->ea = sh2->r[13];
	sh2->macl = RL( sh2->ea );
	sh2->r[13] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4E16:
{
	sh2->ea = sh2->r[14];
	sh2->macl = RL( sh2->ea );
	sh2->r[14] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4F16:
{
	sh2->ea = sh2->r[15];
	sh2->macl = RL( sh2->ea );
	sh2->r[15] += 4;
	goto SH2_RUN_CONTINUE;
}

// LDC.L @Rm+,GBR
Op4017:
{
	sh2->ea = sh2->r[0];
	sh2->gbr = RL( sh2->ea );
	sh2->r[0] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4117:
{
	sh2->ea = sh2->r[1];
	sh2->gbr = RL( sh2->ea );
	sh2->r[1] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4217:
{
	sh2->ea = sh2->r[2];
	sh2->gbr = RL( sh2->ea );
	sh2->r[2] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4317:
{
	sh2->ea = sh2->r[3];
	sh2->gbr = RL( sh2->ea );
	sh2->r[3] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4417:
{
	sh2->ea = sh2->r[4];
	sh2->gbr = RL( sh2->ea );
	sh2->r[4] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4517:
{
	sh2->ea = sh2->r[5];
	sh2->gbr = RL( sh2->ea );
	sh2->r[5] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4617:
{
	sh2->ea = sh2->r[6];
	sh2->gbr = RL( sh2->ea );
	sh2->r[6] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4717:
{
	sh2->ea = sh2->r[7];
	sh2->gbr = RL( sh2->ea );
	sh2->r[7] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4817:
{
	sh2->ea = sh2->r[8];
	sh2->gbr = RL( sh2->ea );
	sh2->r[8] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4917:
{
	sh2->ea = sh2->r[9];
	sh2->gbr = RL( sh2->ea );
	sh2->r[9] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4A17:
{
	sh2->ea = sh2->r[10];
	sh2->gbr = RL( sh2->ea );
	sh2->r[10] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4B17:
{
	sh2->ea = sh2->r[11];
	sh2->gbr = RL( sh2->ea );
	sh2->r[11] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4C17:
{
	sh2->ea = sh2->r[12];
	sh2->gbr = RL( sh2->ea );
	sh2->r[12] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4D17:
{
	sh2->ea = sh2->r[13];
	sh2->gbr = RL( sh2->ea );
	sh2->r[13] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4E17:
{
	sh2->ea = sh2->r[14];
	sh2->gbr = RL( sh2->ea );
	sh2->r[14] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4F17:
{
	sh2->ea = sh2->r[15];
	sh2->gbr = RL( sh2->ea );
	sh2->r[15] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

// SHLL8 Rn
Op4018:
{
	sh2->r[0] <<= 8;
	goto SH2_RUN_CONTINUE;
}

Op4118:
{
	sh2->r[1] <<= 8;
	goto SH2_RUN_CONTINUE;
}

Op4218:
{
	sh2->r[2] <<= 8;
	goto SH2_RUN_CONTINUE;
}

Op4318:
{
	sh2->r[3] <<= 8;
	goto SH2_RUN_CONTINUE;
}

Op4418:
{
	sh2->r[4] <<= 8;
	goto SH2_RUN_CONTINUE;
}

Op4518:
{
	sh2->r[5] <<= 8;
	goto SH2_RUN_CONTINUE;
}

Op4618:
{
	sh2->r[6] <<= 8;
	goto SH2_RUN_CONTINUE;
}

Op4718:
{
	sh2->r[7] <<= 8;
	goto SH2_RUN_CONTINUE;
}

Op4818:
{
	sh2->r[8] <<= 8;
	goto SH2_RUN_CONTINUE;
}

Op4918:
{
	sh2->r[9] <<= 8;
	goto SH2_RUN_CONTINUE;
}

Op4A18:
{
	sh2->r[10] <<= 8;
	goto SH2_RUN_CONTINUE;
}

Op4B18:
{
	sh2->r[11] <<= 8;
	goto SH2_RUN_CONTINUE;
}

Op4C18:
{
	sh2->r[12] <<= 8;
	goto SH2_RUN_CONTINUE;
}

Op4D18:
{
	sh2->r[13] <<= 8;
	goto SH2_RUN_CONTINUE;
}

Op4E18:
{
	sh2->r[14] <<= 8;
	goto SH2_RUN_CONTINUE;
}

Op4F18:
{
	sh2->r[15] <<= 8;
	goto SH2_RUN_CONTINUE;
}

// SHLR8 Rn
Op4019:
{
	sh2->r[0] >>= 8;
	goto SH2_RUN_CONTINUE;
}

Op4119:
{
	sh2->r[1] >>= 8;
	goto SH2_RUN_CONTINUE;
}

Op4219:
{
	sh2->r[2] >>= 8;
	goto SH2_RUN_CONTINUE;
}

Op4319:
{
	sh2->r[3] >>= 8;
	goto SH2_RUN_CONTINUE;
}

Op4419:
{
	sh2->r[4] >>= 8;
	goto SH2_RUN_CONTINUE;
}

Op4519:
{
	sh2->r[5] >>= 8;
	goto SH2_RUN_CONTINUE;
}

Op4619:
{
	sh2->r[6] >>= 8;
	goto SH2_RUN_CONTINUE;
}

Op4719:
{
	sh2->r[7] >>= 8;
	goto SH2_RUN_CONTINUE;
}

Op4819:
{
	sh2->r[8] >>= 8;
	goto SH2_RUN_CONTINUE;
}

Op4919:
{
	sh2->r[9] >>= 8;
	goto SH2_RUN_CONTINUE;
}

Op4A19:
{
	sh2->r[10] >>= 8;
	goto SH2_RUN_CONTINUE;
}

Op4B19:
{
	sh2->r[11] >>= 8;
	goto SH2_RUN_CONTINUE;
}

Op4C19:
{
	sh2->r[12] >>= 8;
	goto SH2_RUN_CONTINUE;
}

Op4D19:
{
	sh2->r[13] >>= 8;
	goto SH2_RUN_CONTINUE;
}

Op4E19:
{
	sh2->r[14] >>= 8;
	goto SH2_RUN_CONTINUE;
}

Op4F19:
{
	sh2->r[15] >>= 8;
	goto SH2_RUN_CONTINUE;
}

// LDS Rn,MACL
Op401A:
{
	sh2->macl = sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op411A:
{
	sh2->macl = sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op421A:
{
	sh2->macl = sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op431A:
{
	sh2->macl = sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op441A:
{
	sh2->macl = sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op451A:
{
	sh2->macl = sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op461A:
{
	sh2->macl = sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op471A:
{
	sh2->macl = sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op481A:
{
	sh2->macl = sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op491A:
{
	sh2->macl = sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op4A1A:
{
	sh2->macl = sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op4B1A:
{
	sh2->macl = sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op4C1A:
{
	sh2->macl = sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op4D1A:
{
	sh2->macl = sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op4E1A:
{
	sh2->macl = sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op4F1A:
{
	sh2->macl = sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

// TAS.B @Rn
Op401B:
{
	n = (opcode>>8) & 0x0f;
	sh2->ea = sh2->r[n];
	temp = RB( sh2->ea );
	if (temp == 0)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	temp |= 0x80;
	WB( sh2->ea, temp );
	sh2->sh2_icount -= 3;
	goto SH2_RUN_CONTINUE;
}

// LDC Rn,GBR
Op401E:
{
	sh2->gbr = sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op411E:
{
	sh2->gbr = sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op421E:
{
	sh2->gbr = sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op431E:
{
	sh2->gbr = sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op441E:
{
	sh2->gbr = sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op451E:
{
	sh2->gbr = sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op461E:
{
	sh2->gbr = sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op471E:
{
	sh2->gbr = sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op481E:
{
	sh2->gbr = sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op491E:
{
	sh2->gbr = sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op4A1E:
{
	sh2->gbr = sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op4B1E:
{
	sh2->gbr = sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op4C1E:
{
	sh2->gbr = sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op4D1E:
{
	sh2->gbr = sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op4E1E:
{
	sh2->gbr = sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op4F1E:
{
	sh2->gbr = sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

// SHAL Rn
Op4020:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[0] >> 31) & T);
	sh2->r[0] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4120:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[1] >> 31) & T);
	sh2->r[1] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4220:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[2] >> 31) & T);
	sh2->r[2] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4320:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[3] >> 31) & T);
	sh2->r[3] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4420:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[4] >> 31) & T);
	sh2->r[4] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4520:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[5] >> 31) & T);
	sh2->r[5] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4620:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[6] >> 31) & T);
	sh2->r[6] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4720:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[7] >> 31) & T);
	sh2->r[7] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4820:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[8] >> 31) & T);
	sh2->r[8] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4920:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[9] >> 31) & T);
	sh2->r[9] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4A20:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[10] >> 31) & T);
	sh2->r[10] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4B20:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[11] >> 31) & T);
	sh2->r[11] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4C20:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[12] >> 31) & T);
	sh2->r[12] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4D20:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[13] >> 31) & T);
	sh2->r[13] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4E20:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[14] >> 31) & T);
	sh2->r[14] <<= 1;
	goto SH2_RUN_CONTINUE;
}

Op4F20:
{
	sh2->sr = (sh2->sr & ~T) | ((sh2->r[15] >> 31) & T);
	sh2->r[15] <<= 1;
	goto SH2_RUN_CONTINUE;
}

// SHAR Rn
Op4021:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[0] & T);
	sh2->r[0] = (UINT32)((INT32)sh2->r[0] >> 1);
	goto SH2_RUN_CONTINUE;
}

Op4121:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[1] & T);
	sh2->r[1] = (UINT32)((INT32)sh2->r[1] >> 1);
	goto SH2_RUN_CONTINUE;
}

Op4221:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[2] & T);
	sh2->r[2] = (UINT32)((INT32)sh2->r[2] >> 1);
	goto SH2_RUN_CONTINUE;
}

Op4321:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[3] & T);
	sh2->r[3] = (UINT32)((INT32)sh2->r[3] >> 1);
	goto SH2_RUN_CONTINUE;
}

Op4421:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[4] & T);
	sh2->r[4] = (UINT32)((INT32)sh2->r[4] >> 1);
	goto SH2_RUN_CONTINUE;
}

Op4521:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[5] & T);
	sh2->r[5] = (UINT32)((INT32)sh2->r[5] >> 1);
	goto SH2_RUN_CONTINUE;
}

Op4621:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[6] & T);
	sh2->r[6] = (UINT32)((INT32)sh2->r[6] >> 1);
	goto SH2_RUN_CONTINUE;
}

Op4721:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[7] & T);
	sh2->r[7] = (UINT32)((INT32)sh2->r[7] >> 1);
	goto SH2_RUN_CONTINUE;
}

Op4821:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[8] & T);
	sh2->r[8] = (UINT32)((INT32)sh2->r[8] >> 1);
	goto SH2_RUN_CONTINUE;
}

Op4921:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[9] & T);
	sh2->r[9] = (UINT32)((INT32)sh2->r[9] >> 1);
	goto SH2_RUN_CONTINUE;
}

Op4A21:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[10] & T);
	sh2->r[10] = (UINT32)((INT32)sh2->r[10] >> 1);
	goto SH2_RUN_CONTINUE;
}

Op4B21:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[11] & T);
	sh2->r[11] = (UINT32)((INT32)sh2->r[11] >> 1);
	goto SH2_RUN_CONTINUE;
}

Op4C21:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[12] & T);
	sh2->r[12] = (UINT32)((INT32)sh2->r[12] >> 1);
	goto SH2_RUN_CONTINUE;
}

Op4D21:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[13] & T);
	sh2->r[13] = (UINT32)((INT32)sh2->r[13] >> 1);
	goto SH2_RUN_CONTINUE;
}

Op4E21:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[14] & T);
	sh2->r[14] = (UINT32)((INT32)sh2->r[14] >> 1);
	goto SH2_RUN_CONTINUE;
}

Op4F21:
{
	sh2->sr = (sh2->sr & ~T) | (sh2->r[15] & T);
	sh2->r[15] = (UINT32)((INT32)sh2->r[15] >> 1);
	goto SH2_RUN_CONTINUE;
}

// STS.L PR,@-Rn
Op4022:
{
	sh2->r[0] -= 4;
	sh2->ea = sh2->r[0];
	WL( sh2->ea, sh2->pr );
	goto SH2_RUN_CONTINUE;
}

Op4122:
{
	sh2->r[1] -= 4;
	sh2->ea = sh2->r[1];
	WL( sh2->ea, sh2->pr );
	goto SH2_RUN_CONTINUE;
}

Op4222:
{
	sh2->r[2] -= 4;
	sh2->ea = sh2->r[2];
	WL( sh2->ea, sh2->pr );
	goto SH2_RUN_CONTINUE;
}

Op4322:
{
	sh2->r[3] -= 4;
	sh2->ea = sh2->r[3];
	WL( sh2->ea, sh2->pr );
	goto SH2_RUN_CONTINUE;
}

Op4422:
{
	sh2->r[4] -= 4;
	sh2->ea = sh2->r[4];
	WL( sh2->ea, sh2->pr );
	goto SH2_RUN_CONTINUE;
}

Op4522:
{
	sh2->r[5] -= 4;
	sh2->ea = sh2->r[5];
	WL( sh2->ea, sh2->pr );
	goto SH2_RUN_CONTINUE;
}

Op4622:
{
	sh2->r[6] -= 4;
	sh2->ea = sh2->r[6];
	WL( sh2->ea, sh2->pr );
	goto SH2_RUN_CONTINUE;
}

Op4722:
{
	sh2->r[7] -= 4;
	sh2->ea = sh2->r[7];
	WL( sh2->ea, sh2->pr );
	goto SH2_RUN_CONTINUE;
}

Op4822:
{
	sh2->r[8] -= 4;
	sh2->ea = sh2->r[8];
	WL( sh2->ea, sh2->pr );
	goto SH2_RUN_CONTINUE;
}

Op4922:
{
	sh2->r[9] -= 4;
	sh2->ea = sh2->r[9];
	WL( sh2->ea, sh2->pr );
	goto SH2_RUN_CONTINUE;
}

Op4A22:
{
	sh2->r[10] -= 4;
	sh2->ea = sh2->r[10];
	WL( sh2->ea, sh2->pr );
	goto SH2_RUN_CONTINUE;
}

Op4B22:
{
	sh2->r[11] -= 4;
	sh2->ea = sh2->r[11];
	WL( sh2->ea, sh2->pr );
	goto SH2_RUN_CONTINUE;
}

Op4C22:
{
	sh2->r[12] -= 4;
	sh2->ea = sh2->r[12];
	WL( sh2->ea, sh2->pr );
	goto SH2_RUN_CONTINUE;
}

Op4D22:
{
	sh2->r[13] -= 4;
	sh2->ea = sh2->r[13];
	WL( sh2->ea, sh2->pr );
	goto SH2_RUN_CONTINUE;
}

Op4E22:
{
	sh2->r[14] -= 4;
	sh2->ea = sh2->r[14];
	WL( sh2->ea, sh2->pr );
	goto SH2_RUN_CONTINUE;
}

Op4F22:
{
	sh2->r[15] -= 4;
	sh2->ea = sh2->r[15];
	WL( sh2->ea, sh2->pr );
	goto SH2_RUN_CONTINUE;
}

// STC.L VBR,@-Rn
Op4023:
{
	sh2->r[0] -= 4;
	sh2->ea = sh2->r[0];
	WL( sh2->ea, sh2->vbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4123:
{
	sh2->r[1] -= 4;
	sh2->ea = sh2->r[1];
	WL( sh2->ea, sh2->vbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4223:
{
	sh2->r[2] -= 4;
	sh2->ea = sh2->r[2];
	WL( sh2->ea, sh2->vbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4323:
{
	sh2->r[3] -= 4;
	sh2->ea = sh2->r[3];
	WL( sh2->ea, sh2->vbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4423:
{
	sh2->r[4] -= 4;
	sh2->ea = sh2->r[4];
	WL( sh2->ea, sh2->vbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4523:
{
	sh2->r[5] -= 4;
	sh2->ea = sh2->r[5];
	WL( sh2->ea, sh2->vbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4623:
{
	sh2->r[6] -= 4;
	sh2->ea = sh2->r[6];
	WL( sh2->ea, sh2->vbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4723:
{
	sh2->r[7] -= 4;
	sh2->ea = sh2->r[7];
	WL( sh2->ea, sh2->vbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4823:
{
	sh2->r[8] -= 4;
	sh2->ea = sh2->r[8];
	WL( sh2->ea, sh2->vbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4923:
{
	sh2->r[9] -= 4;
	sh2->ea = sh2->r[9];
	WL( sh2->ea, sh2->vbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4A23:
{
	sh2->r[10] -= 4;
	sh2->ea = sh2->r[10];
	WL( sh2->ea, sh2->vbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4B23:
{
	sh2->r[11] -= 4;
	sh2->ea = sh2->r[11];
	WL( sh2->ea, sh2->vbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4C23:
{
	sh2->r[12] -= 4;
	sh2->ea = sh2->r[12];
	WL( sh2->ea, sh2->vbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4D23:
{
	sh2->r[13] -= 4;
	sh2->ea = sh2->r[13];
	WL( sh2->ea, sh2->vbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4E23:
{
	sh2->r[14] -= 4;
	sh2->ea = sh2->r[14];
	WL( sh2->ea, sh2->vbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

Op4F23:
{
	sh2->r[15] -= 4;
	sh2->ea = sh2->r[15];
	WL( sh2->ea, sh2->vbr );
	sh2->sh2_icount--;
	goto SH2_RUN_CONTINUE;
}

// ROTCL Rn
Op4024:
{
	temp = (sh2->r[0] >> 31) & T;
	sh2->r[0] = (sh2->r[0] << 1) | (sh2->sr & T);
	sh2->sr = (sh2->sr & ~T) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4124:
{
	temp = (sh2->r[1] >> 31) & T;
	sh2->r[1] = (sh2->r[1] << 1) | (sh2->sr & T);
	sh2->sr = (sh2->sr & ~T) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4224:
{
	temp = (sh2->r[2] >> 31) & T;
	sh2->r[2] = (sh2->r[2] << 1) | (sh2->sr & T);
	sh2->sr = (sh2->sr & ~T) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4324:
{
	temp = (sh2->r[3] >> 31) & T;
	sh2->r[3] = (sh2->r[3] << 1) | (sh2->sr & T);
	sh2->sr = (sh2->sr & ~T) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4424:
{
	temp = (sh2->r[4] >> 31) & T;
	sh2->r[4] = (sh2->r[4] << 1) | (sh2->sr & T);
	sh2->sr = (sh2->sr & ~T) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4524:
{
	temp = (sh2->r[5] >> 31) & T;
	sh2->r[5] = (sh2->r[5] << 1) | (sh2->sr & T);
	sh2->sr = (sh2->sr & ~T) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4624:
{
	temp = (sh2->r[6] >> 31) & T;
	sh2->r[6] = (sh2->r[6] << 1) | (sh2->sr & T);
	sh2->sr = (sh2->sr & ~T) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4724:
{
	temp = (sh2->r[7] >> 31) & T;
	sh2->r[7] = (sh2->r[7] << 1) | (sh2->sr & T);
	sh2->sr = (sh2->sr & ~T) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4824:
{
	temp = (sh2->r[8] >> 31) & T;
	sh2->r[8] = (sh2->r[8] << 1) | (sh2->sr & T);
	sh2->sr = (sh2->sr & ~T) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4924:
{
	temp = (sh2->r[9] >> 31) & T;
	sh2->r[9] = (sh2->r[9] << 1) | (sh2->sr & T);
	sh2->sr = (sh2->sr & ~T) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4A24:
{
	temp = (sh2->r[10] >> 31) & T;
	sh2->r[10] = (sh2->r[10] << 1) | (sh2->sr & T);
	sh2->sr = (sh2->sr & ~T) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4B24:
{
	temp = (sh2->r[11] >> 31) & T;
	sh2->r[11] = (sh2->r[11] << 1) | (sh2->sr & T);
	sh2->sr = (sh2->sr & ~T) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4C24:
{
	temp = (sh2->r[12] >> 31) & T;
	sh2->r[12] = (sh2->r[12] << 1) | (sh2->sr & T);
	sh2->sr = (sh2->sr & ~T) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4D24:
{
	temp = (sh2->r[13] >> 31) & T;
	sh2->r[13] = (sh2->r[13] << 1) | (sh2->sr & T);
	sh2->sr = (sh2->sr & ~T) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4E24:
{
	temp = (sh2->r[14] >> 31) & T;
	sh2->r[14] = (sh2->r[14] << 1) | (sh2->sr & T);
	sh2->sr = (sh2->sr & ~T) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4F24:
{
	temp = (sh2->r[15] >> 31) & T;
	sh2->r[15] = (sh2->r[15] << 1) | (sh2->sr & T);
	sh2->sr = (sh2->sr & ~T) | temp;
	goto SH2_RUN_CONTINUE;
}

// ROTCR Rn
Op4025:
{
	temp = (sh2->sr & T) << 31;
	if (sh2->r[0] & T)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	sh2->r[0] = (sh2->r[0] >> 1) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4125:
{
	temp = (sh2->sr & T) << 31;
	if (sh2->r[1] & T)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	sh2->r[1] = (sh2->r[1] >> 1) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4225:
{
	temp = (sh2->sr & T) << 31;
	if (sh2->r[2] & T)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	sh2->r[2] = (sh2->r[2] >> 1) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4325:
{
	temp = (sh2->sr & T) << 31;
	if (sh2->r[3] & T)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	sh2->r[3] = (sh2->r[3] >> 1) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4425:
{
	temp = (sh2->sr & T) << 31;
	if (sh2->r[4] & T)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	sh2->r[4] = (sh2->r[4] >> 1) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4525:
{
	temp = (sh2->sr & T) << 31;
	if (sh2->r[5] & T)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	sh2->r[5] = (sh2->r[5] >> 1) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4625:
{
	temp = (sh2->sr & T) << 31;
	if (sh2->r[6] & T)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	sh2->r[6] = (sh2->r[6] >> 1) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4725:
{
	temp = (sh2->sr & T) << 31;
	if (sh2->r[7] & T)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	sh2->r[7] = (sh2->r[7] >> 1) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4825:
{
	temp = (sh2->sr & T) << 31;
	if (sh2->r[8] & T)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	sh2->r[8] = (sh2->r[8] >> 1) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4925:
{
	temp = (sh2->sr & T) << 31;
	if (sh2->r[9] & T)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	sh2->r[9] = (sh2->r[9] >> 1) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4A25:
{
	temp = (sh2->sr & T) << 31;
	if (sh2->r[10] & T)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	sh2->r[10] = (sh2->r[10] >> 1) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4B25:
{
	temp = (sh2->sr & T) << 31;
	if (sh2->r[11] & T)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	sh2->r[11] = (sh2->r[11] >> 1) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4C25:
{
	temp = (sh2->sr & T) << 31;
	if (sh2->r[12] & T)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	sh2->r[12] = (sh2->r[12] >> 1) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4D25:
{
	temp = (sh2->sr & T) << 31;
	if (sh2->r[13] & T)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	sh2->r[13] = (sh2->r[13] >> 1) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4E25:
{
	temp = (sh2->sr & T) << 31;
	if (sh2->r[14] & T)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	sh2->r[14] = (sh2->r[14] >> 1) | temp;
	goto SH2_RUN_CONTINUE;
}

Op4F25:
{
	temp = (sh2->sr & T) << 31;
	if (sh2->r[15] & T)
		sh2->sr |= T;
	else
		sh2->sr &= ~T;
	sh2->r[15] = (sh2->r[15] >> 1) | temp;
	goto SH2_RUN_CONTINUE;
}

// LDS.L @Rn+,PR
Op4026:
{
	sh2->ea = sh2->r[0];
	sh2->pr = RL( sh2->ea );
	sh2->r[0] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4126:
{
	sh2->ea = sh2->r[1];
	sh2->pr = RL( sh2->ea );
	sh2->r[1] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4226:
{
	sh2->ea = sh2->r[2];
	sh2->pr = RL( sh2->ea );
	sh2->r[2] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4326:
{
	sh2->ea = sh2->r[3];
	sh2->pr = RL( sh2->ea );
	sh2->r[3] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4426:
{
	sh2->ea = sh2->r[4];
	sh2->pr = RL( sh2->ea );
	sh2->r[4] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4526:
{
	sh2->ea = sh2->r[5];
	sh2->pr = RL( sh2->ea );
	sh2->r[5] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4626:
{
	sh2->ea = sh2->r[6];
	sh2->pr = RL( sh2->ea );
	sh2->r[6] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4726:
{
	sh2->ea = sh2->r[7];
	sh2->pr = RL( sh2->ea );
	sh2->r[7] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4826:
{
	sh2->ea = sh2->r[8];
	sh2->pr = RL( sh2->ea );
	sh2->r[8] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4926:
{
	sh2->ea = sh2->r[9];
	sh2->pr = RL( sh2->ea );
	sh2->r[9] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4A26:
{
	sh2->ea = sh2->r[10];
	sh2->pr = RL( sh2->ea );
	sh2->r[10] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4B26:
{
	sh2->ea = sh2->r[11];
	sh2->pr = RL( sh2->ea );
	sh2->r[11] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4C26:
{
	sh2->ea = sh2->r[12];
	sh2->pr = RL( sh2->ea );
	sh2->r[12] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4D26:
{
	sh2->ea = sh2->r[13];
	sh2->pr = RL( sh2->ea );
	sh2->r[13] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4E26:
{
	sh2->ea = sh2->r[14];
	sh2->pr = RL( sh2->ea );
	sh2->r[14] += 4;
	goto SH2_RUN_CONTINUE;
}

Op4F26:
{
	sh2->ea = sh2->r[15];
	sh2->pr = RL( sh2->ea );
	sh2->r[15] += 4;
	goto SH2_RUN_CONTINUE;
}

// LDC.L @Rn+,VBR
Op4027:
{
	sh2->ea = sh2->r[0];
	sh2->vbr = RL( sh2->ea );
	sh2->r[0] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4127:
{
	sh2->ea = sh2->r[1];
	sh2->vbr = RL( sh2->ea );
	sh2->r[1] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4227:
{
	sh2->ea = sh2->r[2];
	sh2->vbr = RL( sh2->ea );
	sh2->r[2] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4327:
{
	sh2->ea = sh2->r[3];
	sh2->vbr = RL( sh2->ea );
	sh2->r[3] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4427:
{
	sh2->ea = sh2->r[4];
	sh2->vbr = RL( sh2->ea );
	sh2->r[4] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4527:
{
	sh2->ea = sh2->r[5];
	sh2->vbr = RL( sh2->ea );
	sh2->r[5] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4627:
{
	sh2->ea = sh2->r[6];
	sh2->vbr = RL( sh2->ea );
	sh2->r[6] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4727:
{
	sh2->ea = sh2->r[7];
	sh2->vbr = RL( sh2->ea );
	sh2->r[7] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4827:
{
	sh2->ea = sh2->r[8];
	sh2->vbr = RL( sh2->ea );
	sh2->r[8] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4927:
{
	sh2->ea = sh2->r[9];
	sh2->vbr = RL( sh2->ea );
	sh2->r[9] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4A27:
{
	sh2->ea = sh2->r[10];
	sh2->vbr = RL( sh2->ea );
	sh2->r[10] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4B27:
{
	sh2->ea = sh2->r[11];
	sh2->vbr = RL( sh2->ea );
	sh2->r[11] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4C27:
{
	sh2->ea = sh2->r[12];
	sh2->vbr = RL( sh2->ea );
	sh2->r[12] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4D27:
{
	sh2->ea = sh2->r[13];
	sh2->vbr = RL( sh2->ea );
	sh2->r[13] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4E27:
{
	sh2->ea = sh2->r[14];
	sh2->vbr = RL( sh2->ea );
	sh2->r[14] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

Op4F27:
{
	sh2->ea = sh2->r[15];
	sh2->vbr = RL( sh2->ea );
	sh2->r[15] += 4;
	sh2->sh2_icount -= 2;
	goto SH2_RUN_CONTINUE;
}

// SHLL16 Rn
Op4028:
{
	sh2->r[0] <<= 16;
	goto SH2_RUN_CONTINUE;
}

Op4128:
{
	sh2->r[1] <<= 16;
	goto SH2_RUN_CONTINUE;
}

Op4228:
{
	sh2->r[2] <<= 16;
	goto SH2_RUN_CONTINUE;
}

Op4328:
{
	sh2->r[3] <<= 16;
	goto SH2_RUN_CONTINUE;
}

Op4428:
{
	sh2->r[4] <<= 16;
	goto SH2_RUN_CONTINUE;
}

Op4528:
{
	sh2->r[5] <<= 16;
	goto SH2_RUN_CONTINUE;
}

Op4628:
{
	sh2->r[6] <<= 16;
	goto SH2_RUN_CONTINUE;
}

Op4728:
{
	sh2->r[7] <<= 16;
	goto SH2_RUN_CONTINUE;
}

Op4828:
{
	sh2->r[8] <<= 16;
	goto SH2_RUN_CONTINUE;
}

Op4928:
{
	sh2->r[9] <<= 16;
	goto SH2_RUN_CONTINUE;
}

Op4A28:
{
	sh2->r[10] <<= 16;
	goto SH2_RUN_CONTINUE;
}

Op4B28:
{
	sh2->r[11] <<= 16;
	goto SH2_RUN_CONTINUE;
}

Op4C28:
{
	sh2->r[12] <<= 16;
	goto SH2_RUN_CONTINUE;
}

Op4D28:
{
	sh2->r[13] <<= 16;
	goto SH2_RUN_CONTINUE;
}

Op4E28:
{
	sh2->r[14] <<= 16;
	goto SH2_RUN_CONTINUE;
}

Op4F28:
{
	sh2->r[15] <<= 16;
	goto SH2_RUN_CONTINUE;
}

// SHLR16 Rn
Op4029:
{
	sh2->r[0] >>= 16;
	goto SH2_RUN_CONTINUE;
}

Op4129:
{
	sh2->r[1] >>= 16;
	goto SH2_RUN_CONTINUE;
}

Op4229:
{
	sh2->r[2] >>= 16;
	goto SH2_RUN_CONTINUE;
}

Op4329:
{
	sh2->r[3] >>= 16;
	goto SH2_RUN_CONTINUE;
}

Op4429:
{
	sh2->r[4] >>= 16;
	goto SH2_RUN_CONTINUE;
}

Op4529:
{
	sh2->r[5] >>= 16;
	goto SH2_RUN_CONTINUE;
}

Op4629:
{
	sh2->r[6] >>= 16;
	goto SH2_RUN_CONTINUE;
}

Op4729:
{
	sh2->r[7] >>= 16;
	goto SH2_RUN_CONTINUE;
}

Op4829:
{
	sh2->r[8] >>= 16;
	goto SH2_RUN_CONTINUE;
}

Op4929:
{
	sh2->r[9] >>= 16;
	goto SH2_RUN_CONTINUE;
}

Op4A29:
{
	sh2->r[10] >>= 16;
	goto SH2_RUN_CONTINUE;
}

Op4B29:
{
	sh2->r[11] >>= 16;
	goto SH2_RUN_CONTINUE;
}

Op4C29:
{
	sh2->r[12] >>= 16;
	goto SH2_RUN_CONTINUE;
}

Op4D29:
{
	sh2->r[13] >>= 16;
	goto SH2_RUN_CONTINUE;
}

Op4E29:
{
	sh2->r[14] >>= 16;
	goto SH2_RUN_CONTINUE;
}

Op4F29:
{
	sh2->r[15] >>= 16;
	goto SH2_RUN_CONTINUE;
}

// LDS Rn,PR
Op402A:
{
	sh2->pr = sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op412A:
{
	sh2->pr = sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op422A:
{
	sh2->pr = sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op432A:
{
	sh2->pr = sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op442A:
{
	sh2->pr = sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op452A:
{
	sh2->pr = sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op462A:
{
	sh2->pr = sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op472A:
{
	sh2->pr = sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op482A:
{
	sh2->pr = sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op492A:
{
	sh2->pr = sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op4A2A:
{
	sh2->pr = sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op4B2A:
{
	sh2->pr = sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op4C2A:
{
	sh2->pr = sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op4D2A:
{
	sh2->pr = sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op4E2A:
{
	sh2->pr = sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op4F2A:
{
	sh2->pr = sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

// JMP @Rn
Op402B:
{
	sh2->delay = sh2->pc;
	sh2->pc = sh2->ea = sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op412B:
{
	sh2->delay = sh2->pc;
	sh2->pc = sh2->ea = sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op422B:
{
	sh2->delay = sh2->pc;
	sh2->pc = sh2->ea = sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op432B:
{
	sh2->delay = sh2->pc;
	sh2->pc = sh2->ea = sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op442B:
{
	sh2->delay = sh2->pc;
	sh2->pc = sh2->ea = sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op452B:
{
	sh2->delay = sh2->pc;
	sh2->pc = sh2->ea = sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op462B:
{
	sh2->delay = sh2->pc;
	sh2->pc = sh2->ea = sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op472B:
{
	sh2->delay = sh2->pc;
	sh2->pc = sh2->ea = sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op482B:
{
	sh2->delay = sh2->pc;
	sh2->pc = sh2->ea = sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op492B:
{
	sh2->delay = sh2->pc;
	sh2->pc = sh2->ea = sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op4A2B:
{
	sh2->delay = sh2->pc;
	sh2->pc = sh2->ea = sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op4B2B:
{
	sh2->delay = sh2->pc;
	sh2->pc = sh2->ea = sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op4C2B:
{
	sh2->delay = sh2->pc;
	sh2->pc = sh2->ea = sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op4D2B:
{
	sh2->delay = sh2->pc;
	sh2->pc = sh2->ea = sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op4E2B:
{
	sh2->delay = sh2->pc;
	sh2->pc = sh2->ea = sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op4F2B:
{
	sh2->delay = sh2->pc;
	sh2->pc = sh2->ea = sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

// LDC Rn,VBR
Op402E:
{
	sh2->vbr = sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op412E:
{
	sh2->vbr = sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op422E:
{
	sh2->vbr = sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op432E:
{
	sh2->vbr = sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op442E:
{
	sh2->vbr = sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op452E:
{
	sh2->vbr = sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op462E:
{
	sh2->vbr = sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op472E:
{
	sh2->vbr = sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op482E:
{
	sh2->vbr = sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op492E:
{
	sh2->vbr = sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op4A2E:
{
	sh2->vbr = sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op4B2E:
{
	sh2->vbr = sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op4C2E:
{
	sh2->vbr = sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op4D2E:
{
	sh2->vbr = sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op4E2E:
{
	sh2->vbr = sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op4F2E:
{
	sh2->vbr = sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

// MOV.L @(disp4,Rm),Rn
Op5000:
{
	sh2->ea = sh2->r[(opcode>>4) & 0x0f] + ((opcode<<2) & 0x3c);
	sh2->r[(opcode>>8) & 0x0f] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

// MOV.B @Rm,Rn
Op6000:
{
	sh2->ea = sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6010:
{
	sh2->ea = sh2->r[1];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6020:
{
	sh2->ea = sh2->r[2];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6030:
{
	sh2->ea = sh2->r[3];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6040:
{
	sh2->ea = sh2->r[4];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6050:
{
	sh2->ea = sh2->r[5];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6060:
{
	sh2->ea = sh2->r[6];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6070:
{
	sh2->ea = sh2->r[7];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6080:
{
	sh2->ea = sh2->r[8];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6090:
{
	sh2->ea = sh2->r[9];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op60A0:
{
	sh2->ea = sh2->r[10];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op60B0:
{
	sh2->ea = sh2->r[11];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op60C0:
{
	sh2->ea = sh2->r[12];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op60D0:
{
	sh2->ea = sh2->r[13];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op60E0:
{
	sh2->ea = sh2->r[14];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op60F0:
{
	sh2->ea = sh2->r[15];
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6100:
{
	sh2->ea = sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6110:
{
	sh2->ea = sh2->r[1];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6120:
{
	sh2->ea = sh2->r[2];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6130:
{
	sh2->ea = sh2->r[3];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6140:
{
	sh2->ea = sh2->r[4];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6150:
{
	sh2->ea = sh2->r[5];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6160:
{
	sh2->ea = sh2->r[6];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6170:
{
	sh2->ea = sh2->r[7];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6180:
{
	sh2->ea = sh2->r[8];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6190:
{
	sh2->ea = sh2->r[9];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op61A0:
{
	sh2->ea = sh2->r[10];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op61B0:
{
	sh2->ea = sh2->r[11];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op61C0:
{
	sh2->ea = sh2->r[12];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op61D0:
{
	sh2->ea = sh2->r[13];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op61E0:
{
	sh2->ea = sh2->r[14];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op61F0:
{
	sh2->ea = sh2->r[15];
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6200:
{
	sh2->ea = sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6210:
{
	sh2->ea = sh2->r[1];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6220:
{
	sh2->ea = sh2->r[2];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6230:
{
	sh2->ea = sh2->r[3];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6240:
{
	sh2->ea = sh2->r[4];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6250:
{
	sh2->ea = sh2->r[5];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6260:
{
	sh2->ea = sh2->r[6];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6270:
{
	sh2->ea = sh2->r[7];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6280:
{
	sh2->ea = sh2->r[8];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6290:
{
	sh2->ea = sh2->r[9];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op62A0:
{
	sh2->ea = sh2->r[10];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op62B0:
{
	sh2->ea = sh2->r[11];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op62C0:
{
	sh2->ea = sh2->r[12];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op62D0:
{
	sh2->ea = sh2->r[13];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op62E0:
{
	sh2->ea = sh2->r[14];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op62F0:
{
	sh2->ea = sh2->r[15];
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6300:
{
	sh2->ea = sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6310:
{
	sh2->ea = sh2->r[1];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6320:
{
	sh2->ea = sh2->r[2];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6330:
{
	sh2->ea = sh2->r[3];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6340:
{
	sh2->ea = sh2->r[4];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6350:
{
	sh2->ea = sh2->r[5];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6360:
{
	sh2->ea = sh2->r[6];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6370:
{
	sh2->ea = sh2->r[7];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6380:
{
	sh2->ea = sh2->r[8];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6390:
{
	sh2->ea = sh2->r[9];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op63A0:
{
	sh2->ea = sh2->r[10];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op63B0:
{
	sh2->ea = sh2->r[11];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op63C0:
{
	sh2->ea = sh2->r[12];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op63D0:
{
	sh2->ea = sh2->r[13];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op63E0:
{
	sh2->ea = sh2->r[14];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op63F0:
{
	sh2->ea = sh2->r[15];
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6400:
{
	sh2->ea = sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6410:
{
	sh2->ea = sh2->r[1];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6420:
{
	sh2->ea = sh2->r[2];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6430:
{
	sh2->ea = sh2->r[3];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6440:
{
	sh2->ea = sh2->r[4];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6450:
{
	sh2->ea = sh2->r[5];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6460:
{
	sh2->ea = sh2->r[6];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6470:
{
	sh2->ea = sh2->r[7];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6480:
{
	sh2->ea = sh2->r[8];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6490:
{
	sh2->ea = sh2->r[9];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op64A0:
{
	sh2->ea = sh2->r[10];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op64B0:
{
	sh2->ea = sh2->r[11];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op64C0:
{
	sh2->ea = sh2->r[12];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op64D0:
{
	sh2->ea = sh2->r[13];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op64E0:
{
	sh2->ea = sh2->r[14];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op64F0:
{
	sh2->ea = sh2->r[15];
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6500:
{
	sh2->ea = sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6510:
{
	sh2->ea = sh2->r[1];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6520:
{
	sh2->ea = sh2->r[2];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6530:
{
	sh2->ea = sh2->r[3];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6540:
{
	sh2->ea = sh2->r[4];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6550:
{
	sh2->ea = sh2->r[5];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6560:
{
	sh2->ea = sh2->r[6];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6570:
{
	sh2->ea = sh2->r[7];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6580:
{
	sh2->ea = sh2->r[8];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6590:
{
	sh2->ea = sh2->r[9];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op65A0:
{
	sh2->ea = sh2->r[10];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op65B0:
{
	sh2->ea = sh2->r[11];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op65C0:
{
	sh2->ea = sh2->r[12];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op65D0:
{
	sh2->ea = sh2->r[13];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op65E0:
{
	sh2->ea = sh2->r[14];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op65F0:
{
	sh2->ea = sh2->r[15];
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6600:
{
	sh2->ea = sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6610:
{
	sh2->ea = sh2->r[1];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6620:
{
	sh2->ea = sh2->r[2];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6630:
{
	sh2->ea = sh2->r[3];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6640:
{
	sh2->ea = sh2->r[4];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6650:
{
	sh2->ea = sh2->r[5];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6660:
{
	sh2->ea = sh2->r[6];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6670:
{
	sh2->ea = sh2->r[7];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6680:
{
	sh2->ea = sh2->r[8];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6690:
{
	sh2->ea = sh2->r[9];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op66A0:
{
	sh2->ea = sh2->r[10];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op66B0:
{
	sh2->ea = sh2->r[11];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op66C0:
{
	sh2->ea = sh2->r[12];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op66D0:
{
	sh2->ea = sh2->r[13];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op66E0:
{
	sh2->ea = sh2->r[14];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op66F0:
{
	sh2->ea = sh2->r[15];
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6700:
{
	sh2->ea = sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6710:
{
	sh2->ea = sh2->r[1];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6720:
{
	sh2->ea = sh2->r[2];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6730:
{
	sh2->ea = sh2->r[3];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6740:
{
	sh2->ea = sh2->r[4];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6750:
{
	sh2->ea = sh2->r[5];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6760:
{
	sh2->ea = sh2->r[6];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6770:
{
	sh2->ea = sh2->r[7];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6780:
{
	sh2->ea = sh2->r[8];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6790:
{
	sh2->ea = sh2->r[9];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op67A0:
{
	sh2->ea = sh2->r[10];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op67B0:
{
	sh2->ea = sh2->r[11];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op67C0:
{
	sh2->ea = sh2->r[12];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op67D0:
{
	sh2->ea = sh2->r[13];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op67E0:
{
	sh2->ea = sh2->r[14];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op67F0:
{
	sh2->ea = sh2->r[15];
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6800:
{
	sh2->ea = sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6810:
{
	sh2->ea = sh2->r[1];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6820:
{
	sh2->ea = sh2->r[2];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6830:
{
	sh2->ea = sh2->r[3];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6840:
{
	sh2->ea = sh2->r[4];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6850:
{
	sh2->ea = sh2->r[5];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6860:
{
	sh2->ea = sh2->r[6];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6870:
{
	sh2->ea = sh2->r[7];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6880:
{
	sh2->ea = sh2->r[8];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6890:
{
	sh2->ea = sh2->r[9];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op68A0:
{
	sh2->ea = sh2->r[10];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op68B0:
{
	sh2->ea = sh2->r[11];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op68C0:
{
	sh2->ea = sh2->r[12];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op68D0:
{
	sh2->ea = sh2->r[13];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op68E0:
{
	sh2->ea = sh2->r[14];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op68F0:
{
	sh2->ea = sh2->r[15];
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6900:
{
	sh2->ea = sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6910:
{
	sh2->ea = sh2->r[1];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6920:
{
	sh2->ea = sh2->r[2];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6930:
{
	sh2->ea = sh2->r[3];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6940:
{
	sh2->ea = sh2->r[4];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6950:
{
	sh2->ea = sh2->r[5];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6960:
{
	sh2->ea = sh2->r[6];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6970:
{
	sh2->ea = sh2->r[7];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6980:
{
	sh2->ea = sh2->r[8];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6990:
{
	sh2->ea = sh2->r[9];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op69A0:
{
	sh2->ea = sh2->r[10];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op69B0:
{
	sh2->ea = sh2->r[11];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op69C0:
{
	sh2->ea = sh2->r[12];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op69D0:
{
	sh2->ea = sh2->r[13];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op69E0:
{
	sh2->ea = sh2->r[14];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op69F0:
{
	sh2->ea = sh2->r[15];
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A00:
{
	sh2->ea = sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A10:
{
	sh2->ea = sh2->r[1];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A20:
{
	sh2->ea = sh2->r[2];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A30:
{
	sh2->ea = sh2->r[3];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A40:
{
	sh2->ea = sh2->r[4];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A50:
{
	sh2->ea = sh2->r[5];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A60:
{
	sh2->ea = sh2->r[6];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A70:
{
	sh2->ea = sh2->r[7];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A80:
{
	sh2->ea = sh2->r[8];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A90:
{
	sh2->ea = sh2->r[9];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6AA0:
{
	sh2->ea = sh2->r[10];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6AB0:
{
	sh2->ea = sh2->r[11];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6AC0:
{
	sh2->ea = sh2->r[12];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6AD0:
{
	sh2->ea = sh2->r[13];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6AE0:
{
	sh2->ea = sh2->r[14];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6AF0:
{
	sh2->ea = sh2->r[15];
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B00:
{
	sh2->ea = sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B10:
{
	sh2->ea = sh2->r[1];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B20:
{
	sh2->ea = sh2->r[2];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B30:
{
	sh2->ea = sh2->r[3];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B40:
{
	sh2->ea = sh2->r[4];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B50:
{
	sh2->ea = sh2->r[5];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B60:
{
	sh2->ea = sh2->r[6];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B70:
{
	sh2->ea = sh2->r[7];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B80:
{
	sh2->ea = sh2->r[8];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B90:
{
	sh2->ea = sh2->r[9];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6BA0:
{
	sh2->ea = sh2->r[10];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6BB0:
{
	sh2->ea = sh2->r[11];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6BC0:
{
	sh2->ea = sh2->r[12];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6BD0:
{
	sh2->ea = sh2->r[13];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6BE0:
{
	sh2->ea = sh2->r[14];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6BF0:
{
	sh2->ea = sh2->r[15];
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C00:
{
	sh2->ea = sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C10:
{
	sh2->ea = sh2->r[1];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C20:
{
	sh2->ea = sh2->r[2];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C30:
{
	sh2->ea = sh2->r[3];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C40:
{
	sh2->ea = sh2->r[4];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C50:
{
	sh2->ea = sh2->r[5];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C60:
{
	sh2->ea = sh2->r[6];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C70:
{
	sh2->ea = sh2->r[7];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C80:
{
	sh2->ea = sh2->r[8];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C90:
{
	sh2->ea = sh2->r[9];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6CA0:
{
	sh2->ea = sh2->r[10];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6CB0:
{
	sh2->ea = sh2->r[11];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6CC0:
{
	sh2->ea = sh2->r[12];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6CD0:
{
	sh2->ea = sh2->r[13];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6CE0:
{
	sh2->ea = sh2->r[14];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6CF0:
{
	sh2->ea = sh2->r[15];
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D00:
{
	sh2->ea = sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D10:
{
	sh2->ea = sh2->r[1];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D20:
{
	sh2->ea = sh2->r[2];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D30:
{
	sh2->ea = sh2->r[3];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D40:
{
	sh2->ea = sh2->r[4];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D50:
{
	sh2->ea = sh2->r[5];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D60:
{
	sh2->ea = sh2->r[6];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D70:
{
	sh2->ea = sh2->r[7];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D80:
{
	sh2->ea = sh2->r[8];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D90:
{
	sh2->ea = sh2->r[9];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6DA0:
{
	sh2->ea = sh2->r[10];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6DB0:
{
	sh2->ea = sh2->r[11];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6DC0:
{
	sh2->ea = sh2->r[12];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6DD0:
{
	sh2->ea = sh2->r[13];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6DE0:
{
	sh2->ea = sh2->r[14];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6DF0:
{
	sh2->ea = sh2->r[15];
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E00:
{
	sh2->ea = sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E10:
{
	sh2->ea = sh2->r[1];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E20:
{
	sh2->ea = sh2->r[2];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E30:
{
	sh2->ea = sh2->r[3];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E40:
{
	sh2->ea = sh2->r[4];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E50:
{
	sh2->ea = sh2->r[5];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E60:
{
	sh2->ea = sh2->r[6];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E70:
{
	sh2->ea = sh2->r[7];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E80:
{
	sh2->ea = sh2->r[8];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E90:
{
	sh2->ea = sh2->r[9];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6EA0:
{
	sh2->ea = sh2->r[10];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6EB0:
{
	sh2->ea = sh2->r[11];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6EC0:
{
	sh2->ea = sh2->r[12];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6ED0:
{
	sh2->ea = sh2->r[13];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6EE0:
{
	sh2->ea = sh2->r[14];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6EF0:
{
	sh2->ea = sh2->r[15];
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F00:
{
	sh2->ea = sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F10:
{
	sh2->ea = sh2->r[1];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F20:
{
	sh2->ea = sh2->r[2];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F30:
{
	sh2->ea = sh2->r[3];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F40:
{
	sh2->ea = sh2->r[4];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F50:
{
	sh2->ea = sh2->r[5];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F60:
{
	sh2->ea = sh2->r[6];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F70:
{
	sh2->ea = sh2->r[7];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F80:
{
	sh2->ea = sh2->r[8];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F90:
{
	sh2->ea = sh2->r[9];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6FA0:
{
	sh2->ea = sh2->r[10];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6FB0:
{
	sh2->ea = sh2->r[11];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6FC0:
{
	sh2->ea = sh2->r[12];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6FD0:
{
	sh2->ea = sh2->r[13];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6FE0:
{
	sh2->ea = sh2->r[14];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6FF0:
{
	sh2->ea = sh2->r[15];
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

// MOV.W @Rm,Rn
Op6001:
{
	sh2->ea = sh2->r[0];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6011:
{
	sh2->ea = sh2->r[1];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6021:
{
	sh2->ea = sh2->r[2];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6031:
{
	sh2->ea = sh2->r[3];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6041:
{
	sh2->ea = sh2->r[4];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6051:
{
	sh2->ea = sh2->r[5];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6061:
{
	sh2->ea = sh2->r[6];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6071:
{
	sh2->ea = sh2->r[7];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6081:
{
	sh2->ea = sh2->r[8];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6091:
{
	sh2->ea = sh2->r[9];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op60A1:
{
	sh2->ea = sh2->r[10];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op60B1:
{
	sh2->ea = sh2->r[11];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op60C1:
{
	sh2->ea = sh2->r[12];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op60D1:
{
	sh2->ea = sh2->r[13];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op60E1:
{
	sh2->ea = sh2->r[14];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op60F1:
{
	sh2->ea = sh2->r[15];
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6101:
{
	sh2->ea = sh2->r[0];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6111:
{
	sh2->ea = sh2->r[1];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6121:
{
	sh2->ea = sh2->r[2];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6131:
{
	sh2->ea = sh2->r[3];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6141:
{
	sh2->ea = sh2->r[4];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6151:
{
	sh2->ea = sh2->r[5];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6161:
{
	sh2->ea = sh2->r[6];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6171:
{
	sh2->ea = sh2->r[7];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6181:
{
	sh2->ea = sh2->r[8];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6191:
{
	sh2->ea = sh2->r[9];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op61A1:
{
	sh2->ea = sh2->r[10];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op61B1:
{
	sh2->ea = sh2->r[11];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op61C1:
{
	sh2->ea = sh2->r[12];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op61D1:
{
	sh2->ea = sh2->r[13];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op61E1:
{
	sh2->ea = sh2->r[14];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op61F1:
{
	sh2->ea = sh2->r[15];
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6201:
{
	sh2->ea = sh2->r[0];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6211:
{
	sh2->ea = sh2->r[1];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6221:
{
	sh2->ea = sh2->r[2];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6231:
{
	sh2->ea = sh2->r[3];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6241:
{
	sh2->ea = sh2->r[4];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6251:
{
	sh2->ea = sh2->r[5];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6261:
{
	sh2->ea = sh2->r[6];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6271:
{
	sh2->ea = sh2->r[7];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6281:
{
	sh2->ea = sh2->r[8];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6291:
{
	sh2->ea = sh2->r[9];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op62A1:
{
	sh2->ea = sh2->r[10];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op62B1:
{
	sh2->ea = sh2->r[11];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op62C1:
{
	sh2->ea = sh2->r[12];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op62D1:
{
	sh2->ea = sh2->r[13];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op62E1:
{
	sh2->ea = sh2->r[14];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op62F1:
{
	sh2->ea = sh2->r[15];
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6301:
{
	sh2->ea = sh2->r[0];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6311:
{
	sh2->ea = sh2->r[1];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6321:
{
	sh2->ea = sh2->r[2];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6331:
{
	sh2->ea = sh2->r[3];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6341:
{
	sh2->ea = sh2->r[4];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6351:
{
	sh2->ea = sh2->r[5];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6361:
{
	sh2->ea = sh2->r[6];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6371:
{
	sh2->ea = sh2->r[7];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6381:
{
	sh2->ea = sh2->r[8];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6391:
{
	sh2->ea = sh2->r[9];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op63A1:
{
	sh2->ea = sh2->r[10];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op63B1:
{
	sh2->ea = sh2->r[11];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op63C1:
{
	sh2->ea = sh2->r[12];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op63D1:
{
	sh2->ea = sh2->r[13];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op63E1:
{
	sh2->ea = sh2->r[14];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op63F1:
{
	sh2->ea = sh2->r[15];
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6401:
{
	sh2->ea = sh2->r[0];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6411:
{
	sh2->ea = sh2->r[1];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6421:
{
	sh2->ea = sh2->r[2];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6431:
{
	sh2->ea = sh2->r[3];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6441:
{
	sh2->ea = sh2->r[4];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6451:
{
	sh2->ea = sh2->r[5];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6461:
{
	sh2->ea = sh2->r[6];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6471:
{
	sh2->ea = sh2->r[7];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6481:
{
	sh2->ea = sh2->r[8];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6491:
{
	sh2->ea = sh2->r[9];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op64A1:
{
	sh2->ea = sh2->r[10];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op64B1:
{
	sh2->ea = sh2->r[11];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op64C1:
{
	sh2->ea = sh2->r[12];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op64D1:
{
	sh2->ea = sh2->r[13];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op64E1:
{
	sh2->ea = sh2->r[14];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op64F1:
{
	sh2->ea = sh2->r[15];
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6501:
{
	sh2->ea = sh2->r[0];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6511:
{
	sh2->ea = sh2->r[1];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6521:
{
	sh2->ea = sh2->r[2];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6531:
{
	sh2->ea = sh2->r[3];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6541:
{
	sh2->ea = sh2->r[4];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6551:
{
	sh2->ea = sh2->r[5];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6561:
{
	sh2->ea = sh2->r[6];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6571:
{
	sh2->ea = sh2->r[7];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6581:
{
	sh2->ea = sh2->r[8];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6591:
{
	sh2->ea = sh2->r[9];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op65A1:
{
	sh2->ea = sh2->r[10];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op65B1:
{
	sh2->ea = sh2->r[11];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op65C1:
{
	sh2->ea = sh2->r[12];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op65D1:
{
	sh2->ea = sh2->r[13];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op65E1:
{
	sh2->ea = sh2->r[14];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op65F1:
{
	sh2->ea = sh2->r[15];
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6601:
{
	sh2->ea = sh2->r[0];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6611:
{
	sh2->ea = sh2->r[1];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6621:
{
	sh2->ea = sh2->r[2];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6631:
{
	sh2->ea = sh2->r[3];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6641:
{
	sh2->ea = sh2->r[4];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6651:
{
	sh2->ea = sh2->r[5];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6661:
{
	sh2->ea = sh2->r[6];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6671:
{
	sh2->ea = sh2->r[7];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6681:
{
	sh2->ea = sh2->r[8];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6691:
{
	sh2->ea = sh2->r[9];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op66A1:
{
	sh2->ea = sh2->r[10];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op66B1:
{
	sh2->ea = sh2->r[11];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op66C1:
{
	sh2->ea = sh2->r[12];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op66D1:
{
	sh2->ea = sh2->r[13];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op66E1:
{
	sh2->ea = sh2->r[14];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op66F1:
{
	sh2->ea = sh2->r[15];
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6701:
{
	sh2->ea = sh2->r[0];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6711:
{
	sh2->ea = sh2->r[1];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6721:
{
	sh2->ea = sh2->r[2];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6731:
{
	sh2->ea = sh2->r[3];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6741:
{
	sh2->ea = sh2->r[4];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6751:
{
	sh2->ea = sh2->r[5];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6761:
{
	sh2->ea = sh2->r[6];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6771:
{
	sh2->ea = sh2->r[7];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6781:
{
	sh2->ea = sh2->r[8];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6791:
{
	sh2->ea = sh2->r[9];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op67A1:
{
	sh2->ea = sh2->r[10];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op67B1:
{
	sh2->ea = sh2->r[11];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op67C1:
{
	sh2->ea = sh2->r[12];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op67D1:
{
	sh2->ea = sh2->r[13];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op67E1:
{
	sh2->ea = sh2->r[14];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op67F1:
{
	sh2->ea = sh2->r[15];
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6801:
{
	sh2->ea = sh2->r[0];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6811:
{
	sh2->ea = sh2->r[1];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6821:
{
	sh2->ea = sh2->r[2];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6831:
{
	sh2->ea = sh2->r[3];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6841:
{
	sh2->ea = sh2->r[4];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6851:
{
	sh2->ea = sh2->r[5];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6861:
{
	sh2->ea = sh2->r[6];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6871:
{
	sh2->ea = sh2->r[7];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6881:
{
	sh2->ea = sh2->r[8];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6891:
{
	sh2->ea = sh2->r[9];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op68A1:
{
	sh2->ea = sh2->r[10];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op68B1:
{
	sh2->ea = sh2->r[11];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op68C1:
{
	sh2->ea = sh2->r[12];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op68D1:
{
	sh2->ea = sh2->r[13];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op68E1:
{
	sh2->ea = sh2->r[14];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op68F1:
{
	sh2->ea = sh2->r[15];
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6901:
{
	sh2->ea = sh2->r[0];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6911:
{
	sh2->ea = sh2->r[1];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6921:
{
	sh2->ea = sh2->r[2];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6931:
{
	sh2->ea = sh2->r[3];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6941:
{
	sh2->ea = sh2->r[4];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6951:
{
	sh2->ea = sh2->r[5];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6961:
{
	sh2->ea = sh2->r[6];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6971:
{
	sh2->ea = sh2->r[7];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6981:
{
	sh2->ea = sh2->r[8];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6991:
{
	sh2->ea = sh2->r[9];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op69A1:
{
	sh2->ea = sh2->r[10];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op69B1:
{
	sh2->ea = sh2->r[11];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op69C1:
{
	sh2->ea = sh2->r[12];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op69D1:
{
	sh2->ea = sh2->r[13];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op69E1:
{
	sh2->ea = sh2->r[14];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op69F1:
{
	sh2->ea = sh2->r[15];
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A01:
{
	sh2->ea = sh2->r[0];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A11:
{
	sh2->ea = sh2->r[1];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A21:
{
	sh2->ea = sh2->r[2];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A31:
{
	sh2->ea = sh2->r[3];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A41:
{
	sh2->ea = sh2->r[4];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A51:
{
	sh2->ea = sh2->r[5];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A61:
{
	sh2->ea = sh2->r[6];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A71:
{
	sh2->ea = sh2->r[7];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A81:
{
	sh2->ea = sh2->r[8];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A91:
{
	sh2->ea = sh2->r[9];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6AA1:
{
	sh2->ea = sh2->r[10];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6AB1:
{
	sh2->ea = sh2->r[11];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6AC1:
{
	sh2->ea = sh2->r[12];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6AD1:
{
	sh2->ea = sh2->r[13];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6AE1:
{
	sh2->ea = sh2->r[14];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6AF1:
{
	sh2->ea = sh2->r[15];
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B01:
{
	sh2->ea = sh2->r[0];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B11:
{
	sh2->ea = sh2->r[1];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B21:
{
	sh2->ea = sh2->r[2];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B31:
{
	sh2->ea = sh2->r[3];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B41:
{
	sh2->ea = sh2->r[4];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B51:
{
	sh2->ea = sh2->r[5];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B61:
{
	sh2->ea = sh2->r[6];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B71:
{
	sh2->ea = sh2->r[7];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B81:
{
	sh2->ea = sh2->r[8];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B91:
{
	sh2->ea = sh2->r[9];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6BA1:
{
	sh2->ea = sh2->r[10];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6BB1:
{
	sh2->ea = sh2->r[11];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6BC1:
{
	sh2->ea = sh2->r[12];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6BD1:
{
	sh2->ea = sh2->r[13];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6BE1:
{
	sh2->ea = sh2->r[14];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6BF1:
{
	sh2->ea = sh2->r[15];
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C01:
{
	sh2->ea = sh2->r[0];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C11:
{
	sh2->ea = sh2->r[1];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C21:
{
	sh2->ea = sh2->r[2];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C31:
{
	sh2->ea = sh2->r[3];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C41:
{
	sh2->ea = sh2->r[4];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C51:
{
	sh2->ea = sh2->r[5];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C61:
{
	sh2->ea = sh2->r[6];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C71:
{
	sh2->ea = sh2->r[7];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C81:
{
	sh2->ea = sh2->r[8];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C91:
{
	sh2->ea = sh2->r[9];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6CA1:
{
	sh2->ea = sh2->r[10];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6CB1:
{
	sh2->ea = sh2->r[11];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6CC1:
{
	sh2->ea = sh2->r[12];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6CD1:
{
	sh2->ea = sh2->r[13];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6CE1:
{
	sh2->ea = sh2->r[14];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6CF1:
{
	sh2->ea = sh2->r[15];
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D01:
{
	sh2->ea = sh2->r[0];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D11:
{
	sh2->ea = sh2->r[1];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D21:
{
	sh2->ea = sh2->r[2];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D31:
{
	sh2->ea = sh2->r[3];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D41:
{
	sh2->ea = sh2->r[4];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D51:
{
	sh2->ea = sh2->r[5];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D61:
{
	sh2->ea = sh2->r[6];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D71:
{
	sh2->ea = sh2->r[7];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D81:
{
	sh2->ea = sh2->r[8];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D91:
{
	sh2->ea = sh2->r[9];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6DA1:
{
	sh2->ea = sh2->r[10];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6DB1:
{
	sh2->ea = sh2->r[11];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6DC1:
{
	sh2->ea = sh2->r[12];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6DD1:
{
	sh2->ea = sh2->r[13];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6DE1:
{
	sh2->ea = sh2->r[14];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6DF1:
{
	sh2->ea = sh2->r[15];
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E01:
{
	sh2->ea = sh2->r[0];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E11:
{
	sh2->ea = sh2->r[1];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E21:
{
	sh2->ea = sh2->r[2];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E31:
{
	sh2->ea = sh2->r[3];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E41:
{
	sh2->ea = sh2->r[4];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E51:
{
	sh2->ea = sh2->r[5];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E61:
{
	sh2->ea = sh2->r[6];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E71:
{
	sh2->ea = sh2->r[7];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E81:
{
	sh2->ea = sh2->r[8];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E91:
{
	sh2->ea = sh2->r[9];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6EA1:
{
	sh2->ea = sh2->r[10];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6EB1:
{
	sh2->ea = sh2->r[11];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6EC1:
{
	sh2->ea = sh2->r[12];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6ED1:
{
	sh2->ea = sh2->r[13];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6EE1:
{
	sh2->ea = sh2->r[14];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6EF1:
{
	sh2->ea = sh2->r[15];
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F01:
{
	sh2->ea = sh2->r[0];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F11:
{
	sh2->ea = sh2->r[1];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F21:
{
	sh2->ea = sh2->r[2];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F31:
{
	sh2->ea = sh2->r[3];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F41:
{
	sh2->ea = sh2->r[4];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F51:
{
	sh2->ea = sh2->r[5];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F61:
{
	sh2->ea = sh2->r[6];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F71:
{
	sh2->ea = sh2->r[7];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F81:
{
	sh2->ea = sh2->r[8];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F91:
{
	sh2->ea = sh2->r[9];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6FA1:
{
	sh2->ea = sh2->r[10];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6FB1:
{
	sh2->ea = sh2->r[11];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6FC1:
{
	sh2->ea = sh2->r[12];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6FD1:
{
	sh2->ea = sh2->r[13];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6FE1:
{
	sh2->ea = sh2->r[14];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6FF1:
{
	sh2->ea = sh2->r[15];
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

// MOV.L @Rm,Rn
Op6002:
{
	sh2->ea = sh2->r[0];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6012:
{
	sh2->ea = sh2->r[1];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6022:
{
	sh2->ea = sh2->r[2];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6032:
{
	sh2->ea = sh2->r[3];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6042:
{
	sh2->ea = sh2->r[4];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6052:
{
	sh2->ea = sh2->r[5];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6062:
{
	sh2->ea = sh2->r[6];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6072:
{
	sh2->ea = sh2->r[7];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6082:
{
	sh2->ea = sh2->r[8];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6092:
{
	sh2->ea = sh2->r[9];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op60A2:
{
	sh2->ea = sh2->r[10];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op60B2:
{
	sh2->ea = sh2->r[11];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op60C2:
{
	sh2->ea = sh2->r[12];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op60D2:
{
	sh2->ea = sh2->r[13];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op60E2:
{
	sh2->ea = sh2->r[14];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op60F2:
{
	sh2->ea = sh2->r[15];
	sh2->r[0] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6102:
{
	sh2->ea = sh2->r[0];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6112:
{
	sh2->ea = sh2->r[1];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6122:
{
	sh2->ea = sh2->r[2];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6132:
{
	sh2->ea = sh2->r[3];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6142:
{
	sh2->ea = sh2->r[4];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6152:
{
	sh2->ea = sh2->r[5];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6162:
{
	sh2->ea = sh2->r[6];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6172:
{
	sh2->ea = sh2->r[7];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6182:
{
	sh2->ea = sh2->r[8];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6192:
{
	sh2->ea = sh2->r[9];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op61A2:
{
	sh2->ea = sh2->r[10];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op61B2:
{
	sh2->ea = sh2->r[11];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op61C2:
{
	sh2->ea = sh2->r[12];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op61D2:
{
	sh2->ea = sh2->r[13];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op61E2:
{
	sh2->ea = sh2->r[14];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op61F2:
{
	sh2->ea = sh2->r[15];
	sh2->r[1] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6202:
{
	sh2->ea = sh2->r[0];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6212:
{
	sh2->ea = sh2->r[1];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6222:
{
	sh2->ea = sh2->r[2];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6232:
{
	sh2->ea = sh2->r[3];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6242:
{
	sh2->ea = sh2->r[4];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6252:
{
	sh2->ea = sh2->r[5];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6262:
{
	sh2->ea = sh2->r[6];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6272:
{
	sh2->ea = sh2->r[7];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6282:
{
	sh2->ea = sh2->r[8];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6292:
{
	sh2->ea = sh2->r[9];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op62A2:
{
	sh2->ea = sh2->r[10];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op62B2:
{
	sh2->ea = sh2->r[11];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op62C2:
{
	sh2->ea = sh2->r[12];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op62D2:
{
	sh2->ea = sh2->r[13];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op62E2:
{
	sh2->ea = sh2->r[14];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op62F2:
{
	sh2->ea = sh2->r[15];
	sh2->r[2] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6302:
{
	sh2->ea = sh2->r[0];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6312:
{
	sh2->ea = sh2->r[1];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6322:
{
	sh2->ea = sh2->r[2];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6332:
{
	sh2->ea = sh2->r[3];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6342:
{
	sh2->ea = sh2->r[4];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6352:
{
	sh2->ea = sh2->r[5];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6362:
{
	sh2->ea = sh2->r[6];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6372:
{
	sh2->ea = sh2->r[7];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6382:
{
	sh2->ea = sh2->r[8];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6392:
{
	sh2->ea = sh2->r[9];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op63A2:
{
	sh2->ea = sh2->r[10];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op63B2:
{
	sh2->ea = sh2->r[11];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op63C2:
{
	sh2->ea = sh2->r[12];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op63D2:
{
	sh2->ea = sh2->r[13];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op63E2:
{
	sh2->ea = sh2->r[14];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op63F2:
{
	sh2->ea = sh2->r[15];
	sh2->r[3] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6402:
{
	sh2->ea = sh2->r[0];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6412:
{
	sh2->ea = sh2->r[1];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6422:
{
	sh2->ea = sh2->r[2];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6432:
{
	sh2->ea = sh2->r[3];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6442:
{
	sh2->ea = sh2->r[4];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6452:
{
	sh2->ea = sh2->r[5];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6462:
{
	sh2->ea = sh2->r[6];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6472:
{
	sh2->ea = sh2->r[7];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6482:
{
	sh2->ea = sh2->r[8];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6492:
{
	sh2->ea = sh2->r[9];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op64A2:
{
	sh2->ea = sh2->r[10];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op64B2:
{
	sh2->ea = sh2->r[11];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op64C2:
{
	sh2->ea = sh2->r[12];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op64D2:
{
	sh2->ea = sh2->r[13];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op64E2:
{
	sh2->ea = sh2->r[14];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op64F2:
{
	sh2->ea = sh2->r[15];
	sh2->r[4] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6502:
{
	sh2->ea = sh2->r[0];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6512:
{
	sh2->ea = sh2->r[1];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6522:
{
	sh2->ea = sh2->r[2];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6532:
{
	sh2->ea = sh2->r[3];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6542:
{
	sh2->ea = sh2->r[4];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6552:
{
	sh2->ea = sh2->r[5];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6562:
{
	sh2->ea = sh2->r[6];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6572:
{
	sh2->ea = sh2->r[7];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6582:
{
	sh2->ea = sh2->r[8];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6592:
{
	sh2->ea = sh2->r[9];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op65A2:
{
	sh2->ea = sh2->r[10];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op65B2:
{
	sh2->ea = sh2->r[11];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op65C2:
{
	sh2->ea = sh2->r[12];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op65D2:
{
	sh2->ea = sh2->r[13];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op65E2:
{
	sh2->ea = sh2->r[14];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op65F2:
{
	sh2->ea = sh2->r[15];
	sh2->r[5] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6602:
{
	sh2->ea = sh2->r[0];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6612:
{
	sh2->ea = sh2->r[1];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6622:
{
	sh2->ea = sh2->r[2];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6632:
{
	sh2->ea = sh2->r[3];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6642:
{
	sh2->ea = sh2->r[4];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6652:
{
	sh2->ea = sh2->r[5];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6662:
{
	sh2->ea = sh2->r[6];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6672:
{
	sh2->ea = sh2->r[7];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6682:
{
	sh2->ea = sh2->r[8];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6692:
{
	sh2->ea = sh2->r[9];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op66A2:
{
	sh2->ea = sh2->r[10];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op66B2:
{
	sh2->ea = sh2->r[11];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op66C2:
{
	sh2->ea = sh2->r[12];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op66D2:
{
	sh2->ea = sh2->r[13];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op66E2:
{
	sh2->ea = sh2->r[14];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op66F2:
{
	sh2->ea = sh2->r[15];
	sh2->r[6] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6702:
{
	sh2->ea = sh2->r[0];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6712:
{
	sh2->ea = sh2->r[1];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6722:
{
	sh2->ea = sh2->r[2];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6732:
{
	sh2->ea = sh2->r[3];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6742:
{
	sh2->ea = sh2->r[4];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6752:
{
	sh2->ea = sh2->r[5];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6762:
{
	sh2->ea = sh2->r[6];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6772:
{
	sh2->ea = sh2->r[7];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6782:
{
	sh2->ea = sh2->r[8];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6792:
{
	sh2->ea = sh2->r[9];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op67A2:
{
	sh2->ea = sh2->r[10];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op67B2:
{
	sh2->ea = sh2->r[11];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op67C2:
{
	sh2->ea = sh2->r[12];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op67D2:
{
	sh2->ea = sh2->r[13];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op67E2:
{
	sh2->ea = sh2->r[14];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op67F2:
{
	sh2->ea = sh2->r[15];
	sh2->r[7] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6802:
{
	sh2->ea = sh2->r[0];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6812:
{
	sh2->ea = sh2->r[1];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6822:
{
	sh2->ea = sh2->r[2];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6832:
{
	sh2->ea = sh2->r[3];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6842:
{
	sh2->ea = sh2->r[4];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6852:
{
	sh2->ea = sh2->r[5];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6862:
{
	sh2->ea = sh2->r[6];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6872:
{
	sh2->ea = sh2->r[7];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6882:
{
	sh2->ea = sh2->r[8];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6892:
{
	sh2->ea = sh2->r[9];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op68A2:
{
	sh2->ea = sh2->r[10];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op68B2:
{
	sh2->ea = sh2->r[11];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op68C2:
{
	sh2->ea = sh2->r[12];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op68D2:
{
	sh2->ea = sh2->r[13];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op68E2:
{
	sh2->ea = sh2->r[14];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op68F2:
{
	sh2->ea = sh2->r[15];
	sh2->r[8] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6902:
{
	sh2->ea = sh2->r[0];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6912:
{
	sh2->ea = sh2->r[1];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6922:
{
	sh2->ea = sh2->r[2];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6932:
{
	sh2->ea = sh2->r[3];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6942:
{
	sh2->ea = sh2->r[4];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6952:
{
	sh2->ea = sh2->r[5];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6962:
{
	sh2->ea = sh2->r[6];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6972:
{
	sh2->ea = sh2->r[7];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6982:
{
	sh2->ea = sh2->r[8];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6992:
{
	sh2->ea = sh2->r[9];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op69A2:
{
	sh2->ea = sh2->r[10];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op69B2:
{
	sh2->ea = sh2->r[11];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op69C2:
{
	sh2->ea = sh2->r[12];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op69D2:
{
	sh2->ea = sh2->r[13];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op69E2:
{
	sh2->ea = sh2->r[14];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op69F2:
{
	sh2->ea = sh2->r[15];
	sh2->r[9] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A02:
{
	sh2->ea = sh2->r[0];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A12:
{
	sh2->ea = sh2->r[1];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A22:
{
	sh2->ea = sh2->r[2];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A32:
{
	sh2->ea = sh2->r[3];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A42:
{
	sh2->ea = sh2->r[4];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A52:
{
	sh2->ea = sh2->r[5];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A62:
{
	sh2->ea = sh2->r[6];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A72:
{
	sh2->ea = sh2->r[7];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A82:
{
	sh2->ea = sh2->r[8];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6A92:
{
	sh2->ea = sh2->r[9];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6AA2:
{
	sh2->ea = sh2->r[10];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6AB2:
{
	sh2->ea = sh2->r[11];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6AC2:
{
	sh2->ea = sh2->r[12];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6AD2:
{
	sh2->ea = sh2->r[13];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6AE2:
{
	sh2->ea = sh2->r[14];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6AF2:
{
	sh2->ea = sh2->r[15];
	sh2->r[10] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B02:
{
	sh2->ea = sh2->r[0];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B12:
{
	sh2->ea = sh2->r[1];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B22:
{
	sh2->ea = sh2->r[2];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B32:
{
	sh2->ea = sh2->r[3];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B42:
{
	sh2->ea = sh2->r[4];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B52:
{
	sh2->ea = sh2->r[5];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B62:
{
	sh2->ea = sh2->r[6];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B72:
{
	sh2->ea = sh2->r[7];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B82:
{
	sh2->ea = sh2->r[8];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6B92:
{
	sh2->ea = sh2->r[9];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6BA2:
{
	sh2->ea = sh2->r[10];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6BB2:
{
	sh2->ea = sh2->r[11];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6BC2:
{
	sh2->ea = sh2->r[12];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6BD2:
{
	sh2->ea = sh2->r[13];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6BE2:
{
	sh2->ea = sh2->r[14];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6BF2:
{
	sh2->ea = sh2->r[15];
	sh2->r[11] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C02:
{
	sh2->ea = sh2->r[0];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C12:
{
	sh2->ea = sh2->r[1];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C22:
{
	sh2->ea = sh2->r[2];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C32:
{
	sh2->ea = sh2->r[3];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C42:
{
	sh2->ea = sh2->r[4];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C52:
{
	sh2->ea = sh2->r[5];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C62:
{
	sh2->ea = sh2->r[6];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C72:
{
	sh2->ea = sh2->r[7];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C82:
{
	sh2->ea = sh2->r[8];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6C92:
{
	sh2->ea = sh2->r[9];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6CA2:
{
	sh2->ea = sh2->r[10];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6CB2:
{
	sh2->ea = sh2->r[11];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6CC2:
{
	sh2->ea = sh2->r[12];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6CD2:
{
	sh2->ea = sh2->r[13];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6CE2:
{
	sh2->ea = sh2->r[14];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6CF2:
{
	sh2->ea = sh2->r[15];
	sh2->r[12] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D02:
{
	sh2->ea = sh2->r[0];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D12:
{
	sh2->ea = sh2->r[1];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D22:
{
	sh2->ea = sh2->r[2];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D32:
{
	sh2->ea = sh2->r[3];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D42:
{
	sh2->ea = sh2->r[4];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D52:
{
	sh2->ea = sh2->r[5];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D62:
{
	sh2->ea = sh2->r[6];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D72:
{
	sh2->ea = sh2->r[7];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D82:
{
	sh2->ea = sh2->r[8];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6D92:
{
	sh2->ea = sh2->r[9];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6DA2:
{
	sh2->ea = sh2->r[10];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6DB2:
{
	sh2->ea = sh2->r[11];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6DC2:
{
	sh2->ea = sh2->r[12];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6DD2:
{
	sh2->ea = sh2->r[13];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6DE2:
{
	sh2->ea = sh2->r[14];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6DF2:
{
	sh2->ea = sh2->r[15];
	sh2->r[13] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E02:
{
	sh2->ea = sh2->r[0];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E12:
{
	sh2->ea = sh2->r[1];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E22:
{
	sh2->ea = sh2->r[2];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E32:
{
	sh2->ea = sh2->r[3];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E42:
{
	sh2->ea = sh2->r[4];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E52:
{
	sh2->ea = sh2->r[5];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E62:
{
	sh2->ea = sh2->r[6];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E72:
{
	sh2->ea = sh2->r[7];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E82:
{
	sh2->ea = sh2->r[8];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6E92:
{
	sh2->ea = sh2->r[9];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6EA2:
{
	sh2->ea = sh2->r[10];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6EB2:
{
	sh2->ea = sh2->r[11];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6EC2:
{
	sh2->ea = sh2->r[12];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6ED2:
{
	sh2->ea = sh2->r[13];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6EE2:
{
	sh2->ea = sh2->r[14];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6EF2:
{
	sh2->ea = sh2->r[15];
	sh2->r[14] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F02:
{
	sh2->ea = sh2->r[0];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F12:
{
	sh2->ea = sh2->r[1];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F22:
{
	sh2->ea = sh2->r[2];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F32:
{
	sh2->ea = sh2->r[3];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F42:
{
	sh2->ea = sh2->r[4];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F52:
{
	sh2->ea = sh2->r[5];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F62:
{
	sh2->ea = sh2->r[6];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F72:
{
	sh2->ea = sh2->r[7];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F82:
{
	sh2->ea = sh2->r[8];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6F92:
{
	sh2->ea = sh2->r[9];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6FA2:
{
	sh2->ea = sh2->r[10];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6FB2:
{
	sh2->ea = sh2->r[11];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6FC2:
{
	sh2->ea = sh2->r[12];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6FD2:
{
	sh2->ea = sh2->r[13];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6FE2:
{
	sh2->ea = sh2->r[14];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

Op6FF2:
{
	sh2->ea = sh2->r[15];
	sh2->r[15] = RL( sh2->ea );
	goto SH2_RUN_CONTINUE;
}

// MOV Rm,Rn
Op6003:
{
	sh2->r[0] = sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op6013:
{
	sh2->r[0] = sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op6023:
{
	sh2->r[0] = sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op6033:
{
	sh2->r[0] = sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op6043:
{
	sh2->r[0] = sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op6053:
{
	sh2->r[0] = sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op6063:
{
	sh2->r[0] = sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op6073:
{
	sh2->r[0] = sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op6083:
{
	sh2->r[0] = sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op6093:
{
	sh2->r[0] = sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op60A3:
{
	sh2->r[0] = sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op60B3:
{
	sh2->r[0] = sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op60C3:
{
	sh2->r[0] = sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op60D3:
{
	sh2->r[0] = sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op60E3:
{
	sh2->r[0] = sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op60F3:
{
	sh2->r[0] = sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op6103:
{
	sh2->r[1] = sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op6113:
{
	sh2->r[1] = sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op6123:
{
	sh2->r[1] = sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op6133:
{
	sh2->r[1] = sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op6143:
{
	sh2->r[1] = sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op6153:
{
	sh2->r[1] = sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op6163:
{
	sh2->r[1] = sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op6173:
{
	sh2->r[1] = sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op6183:
{
	sh2->r[1] = sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op6193:
{
	sh2->r[1] = sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op61A3:
{
	sh2->r[1] = sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op61B3:
{
	sh2->r[1] = sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op61C3:
{
	sh2->r[1] = sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op61D3:
{
	sh2->r[1] = sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op61E3:
{
	sh2->r[1] = sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op61F3:
{
	sh2->r[1] = sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op6203:
{
	sh2->r[2] = sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op6213:
{
	sh2->r[2] = sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op6223:
{
	sh2->r[2] = sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op6233:
{
	sh2->r[2] = sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op6243:
{
	sh2->r[2] = sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op6253:
{
	sh2->r[2] = sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op6263:
{
	sh2->r[2] = sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op6273:
{
	sh2->r[2] = sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op6283:
{
	sh2->r[2] = sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op6293:
{
	sh2->r[2] = sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op62A3:
{
	sh2->r[2] = sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op62B3:
{
	sh2->r[2] = sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op62C3:
{
	sh2->r[2] = sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op62D3:
{
	sh2->r[2] = sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op62E3:
{
	sh2->r[2] = sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op62F3:
{
	sh2->r[2] = sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op6303:
{
	sh2->r[3] = sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op6313:
{
	sh2->r[3] = sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op6323:
{
	sh2->r[3] = sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op6333:
{
	sh2->r[3] = sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op6343:
{
	sh2->r[3] = sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op6353:
{
	sh2->r[3] = sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op6363:
{
	sh2->r[3] = sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op6373:
{
	sh2->r[3] = sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op6383:
{
	sh2->r[3] = sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op6393:
{
	sh2->r[3] = sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op63A3:
{
	sh2->r[3] = sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op63B3:
{
	sh2->r[3] = sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op63C3:
{
	sh2->r[3] = sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op63D3:
{
	sh2->r[3] = sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op63E3:
{
	sh2->r[3] = sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op63F3:
{
	sh2->r[3] = sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op6403:
{
	sh2->r[4] = sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op6413:
{
	sh2->r[4] = sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op6423:
{
	sh2->r[4] = sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op6433:
{
	sh2->r[4] = sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op6443:
{
	sh2->r[4] = sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op6453:
{
	sh2->r[4] = sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op6463:
{
	sh2->r[4] = sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op6473:
{
	sh2->r[4] = sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op6483:
{
	sh2->r[4] = sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op6493:
{
	sh2->r[4] = sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op64A3:
{
	sh2->r[4] = sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op64B3:
{
	sh2->r[4] = sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op64C3:
{
	sh2->r[4] = sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op64D3:
{
	sh2->r[4] = sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op64E3:
{
	sh2->r[4] = sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op64F3:
{
	sh2->r[4] = sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op6503:
{
	sh2->r[5] = sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op6513:
{
	sh2->r[5] = sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op6523:
{
	sh2->r[5] = sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op6533:
{
	sh2->r[5] = sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op6543:
{
	sh2->r[5] = sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op6553:
{
	sh2->r[5] = sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op6563:
{
	sh2->r[5] = sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op6573:
{
	sh2->r[5] = sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op6583:
{
	sh2->r[5] = sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op6593:
{
	sh2->r[5] = sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op65A3:
{
	sh2->r[5] = sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op65B3:
{
	sh2->r[5] = sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op65C3:
{
	sh2->r[5] = sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op65D3:
{
	sh2->r[5] = sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op65E3:
{
	sh2->r[5] = sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op65F3:
{
	sh2->r[5] = sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op6603:
{
	sh2->r[6] = sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op6613:
{
	sh2->r[6] = sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op6623:
{
	sh2->r[6] = sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op6633:
{
	sh2->r[6] = sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op6643:
{
	sh2->r[6] = sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op6653:
{
	sh2->r[6] = sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op6663:
{
	sh2->r[6] = sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op6673:
{
	sh2->r[6] = sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op6683:
{
	sh2->r[6] = sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op6693:
{
	sh2->r[6] = sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op66A3:
{
	sh2->r[6] = sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op66B3:
{
	sh2->r[6] = sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op66C3:
{
	sh2->r[6] = sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op66D3:
{
	sh2->r[6] = sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op66E3:
{
	sh2->r[6] = sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op66F3:
{
	sh2->r[6] = sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op6703:
{
	sh2->r[7] = sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op6713:
{
	sh2->r[7] = sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op6723:
{
	sh2->r[7] = sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op6733:
{
	sh2->r[7] = sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op6743:
{
	sh2->r[7] = sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op6753:
{
	sh2->r[7] = sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op6763:
{
	sh2->r[7] = sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op6773:
{
	sh2->r[7] = sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op6783:
{
	sh2->r[7] = sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op6793:
{
	sh2->r[7] = sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op67A3:
{
	sh2->r[7] = sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op67B3:
{
	sh2->r[7] = sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op67C3:
{
	sh2->r[7] = sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op67D3:
{
	sh2->r[7] = sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op67E3:
{
	sh2->r[7] = sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op67F3:
{
	sh2->r[7] = sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op6803:
{
	sh2->r[8] = sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op6813:
{
	sh2->r[8] = sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op6823:
{
	sh2->r[8] = sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op6833:
{
	sh2->r[8] = sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op6843:
{
	sh2->r[8] = sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op6853:
{
	sh2->r[8] = sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op6863:
{
	sh2->r[8] = sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op6873:
{
	sh2->r[8] = sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op6883:
{
	sh2->r[8] = sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op6893:
{
	sh2->r[8] = sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op68A3:
{
	sh2->r[8] = sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op68B3:
{
	sh2->r[8] = sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op68C3:
{
	sh2->r[8] = sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op68D3:
{
	sh2->r[8] = sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op68E3:
{
	sh2->r[8] = sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op68F3:
{
	sh2->r[8] = sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op6903:
{
	sh2->r[9] = sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op6913:
{
	sh2->r[9] = sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op6923:
{
	sh2->r[9] = sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op6933:
{
	sh2->r[9] = sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op6943:
{
	sh2->r[9] = sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op6953:
{
	sh2->r[9] = sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op6963:
{
	sh2->r[9] = sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op6973:
{
	sh2->r[9] = sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op6983:
{
	sh2->r[9] = sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op6993:
{
	sh2->r[9] = sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op69A3:
{
	sh2->r[9] = sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op69B3:
{
	sh2->r[9] = sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op69C3:
{
	sh2->r[9] = sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op69D3:
{
	sh2->r[9] = sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op69E3:
{
	sh2->r[9] = sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op69F3:
{
	sh2->r[9] = sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op6A03:
{
	sh2->r[10] = sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op6A13:
{
	sh2->r[10] = sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op6A23:
{
	sh2->r[10] = sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op6A33:
{
	sh2->r[10] = sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op6A43:
{
	sh2->r[10] = sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op6A53:
{
	sh2->r[10] = sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op6A63:
{
	sh2->r[10] = sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op6A73:
{
	sh2->r[10] = sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op6A83:
{
	sh2->r[10] = sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op6A93:
{
	sh2->r[10] = sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op6AA3:
{
	sh2->r[10] = sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op6AB3:
{
	sh2->r[10] = sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op6AC3:
{
	sh2->r[10] = sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op6AD3:
{
	sh2->r[10] = sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op6AE3:
{
	sh2->r[10] = sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op6AF3:
{
	sh2->r[10] = sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op6B03:
{
	sh2->r[11] = sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op6B13:
{
	sh2->r[11] = sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op6B23:
{
	sh2->r[11] = sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op6B33:
{
	sh2->r[11] = sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op6B43:
{
	sh2->r[11] = sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op6B53:
{
	sh2->r[11] = sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op6B63:
{
	sh2->r[11] = sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op6B73:
{
	sh2->r[11] = sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op6B83:
{
	sh2->r[11] = sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op6B93:
{
	sh2->r[11] = sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op6BA3:
{
	sh2->r[11] = sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op6BB3:
{
	sh2->r[11] = sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op6BC3:
{
	sh2->r[11] = sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op6BD3:
{
	sh2->r[11] = sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op6BE3:
{
	sh2->r[11] = sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op6BF3:
{
	sh2->r[11] = sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op6C03:
{
	sh2->r[12] = sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op6C13:
{
	sh2->r[12] = sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op6C23:
{
	sh2->r[12] = sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op6C33:
{
	sh2->r[12] = sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op6C43:
{
	sh2->r[12] = sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op6C53:
{
	sh2->r[12] = sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op6C63:
{
	sh2->r[12] = sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op6C73:
{
	sh2->r[12] = sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op6C83:
{
	sh2->r[12] = sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op6C93:
{
	sh2->r[12] = sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op6CA3:
{
	sh2->r[12] = sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op6CB3:
{
	sh2->r[12] = sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op6CC3:
{
	sh2->r[12] = sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op6CD3:
{
	sh2->r[12] = sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op6CE3:
{
	sh2->r[12] = sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op6CF3:
{
	sh2->r[12] = sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op6D03:
{
	sh2->r[13] = sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op6D13:
{
	sh2->r[13] = sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op6D23:
{
	sh2->r[13] = sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op6D33:
{
	sh2->r[13] = sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op6D43:
{
	sh2->r[13] = sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op6D53:
{
	sh2->r[13] = sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op6D63:
{
	sh2->r[13] = sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op6D73:
{
	sh2->r[13] = sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op6D83:
{
	sh2->r[13] = sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op6D93:
{
	sh2->r[13] = sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op6DA3:
{
	sh2->r[13] = sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op6DB3:
{
	sh2->r[13] = sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op6DC3:
{
	sh2->r[13] = sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op6DD3:
{
	sh2->r[13] = sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op6DE3:
{
	sh2->r[13] = sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op6DF3:
{
	sh2->r[13] = sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op6E03:
{
	sh2->r[14] = sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op6E13:
{
	sh2->r[14] = sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op6E23:
{
	sh2->r[14] = sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op6E33:
{
	sh2->r[14] = sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op6E43:
{
	sh2->r[14] = sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op6E53:
{
	sh2->r[14] = sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op6E63:
{
	sh2->r[14] = sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op6E73:
{
	sh2->r[14] = sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op6E83:
{
	sh2->r[14] = sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op6E93:
{
	sh2->r[14] = sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op6EA3:
{
	sh2->r[14] = sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op6EB3:
{
	sh2->r[14] = sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op6EC3:
{
	sh2->r[14] = sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op6ED3:
{
	sh2->r[14] = sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op6EE3:
{
	sh2->r[14] = sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op6EF3:
{
	sh2->r[14] = sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

Op6F03:
{
	sh2->r[15] = sh2->r[0];
	goto SH2_RUN_CONTINUE;
}

Op6F13:
{
	sh2->r[15] = sh2->r[1];
	goto SH2_RUN_CONTINUE;
}

Op6F23:
{
	sh2->r[15] = sh2->r[2];
	goto SH2_RUN_CONTINUE;
}

Op6F33:
{
	sh2->r[15] = sh2->r[3];
	goto SH2_RUN_CONTINUE;
}

Op6F43:
{
	sh2->r[15] = sh2->r[4];
	goto SH2_RUN_CONTINUE;
}

Op6F53:
{
	sh2->r[15] = sh2->r[5];
	goto SH2_RUN_CONTINUE;
}

Op6F63:
{
	sh2->r[15] = sh2->r[6];
	goto SH2_RUN_CONTINUE;
}

Op6F73:
{
	sh2->r[15] = sh2->r[7];
	goto SH2_RUN_CONTINUE;
}

Op6F83:
{
	sh2->r[15] = sh2->r[8];
	goto SH2_RUN_CONTINUE;
}

Op6F93:
{
	sh2->r[15] = sh2->r[9];
	goto SH2_RUN_CONTINUE;
}

Op6FA3:
{
	sh2->r[15] = sh2->r[10];
	goto SH2_RUN_CONTINUE;
}

Op6FB3:
{
	sh2->r[15] = sh2->r[11];
	goto SH2_RUN_CONTINUE;
}

Op6FC3:
{
	sh2->r[15] = sh2->r[12];
	goto SH2_RUN_CONTINUE;
}

Op6FD3:
{
	sh2->r[15] = sh2->r[13];
	goto SH2_RUN_CONTINUE;
}

Op6FE3:
{
	sh2->r[15] = sh2->r[14];
	goto SH2_RUN_CONTINUE;
}

Op6FF3:
{
	sh2->r[15] = sh2->r[15];
	goto SH2_RUN_CONTINUE;
}

// MOV.B @Rm+,Rn
Op6004:
{
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[0] );
	if (0 != 0)
		sh2->r[0] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6014:
{
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[1] );
	if (0 != 1)
		sh2->r[1] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6024:
{
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[2] );
	if (0 != 2)
		sh2->r[2] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6034:
{
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[3] );
	if (0 != 3)
		sh2->r[3] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6044:
{
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[4] );
	if (0 != 4)
		sh2->r[4] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6054:
{
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[5] );
	if (0 != 5)
		sh2->r[5] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6064:
{
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[6] );
	if (0 != 6)
		sh2->r[6] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6074:
{
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[7] );
	if (0 != 7)
		sh2->r[7] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6084:
{
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[8] );
	if (0 != 8)
		sh2->r[8] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6094:
{
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[9] );
	if (0 != 9)
		sh2->r[9] += 1;
	goto SH2_RUN_CONTINUE;
}

Op60A4:
{
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[10] );
	if (0 != 10)
		sh2->r[10] += 1;
	goto SH2_RUN_CONTINUE;
}

Op60B4:
{
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[11] );
	if (0 != 11)
		sh2->r[11] += 1;
	goto SH2_RUN_CONTINUE;
}

Op60C4:
{
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[12] );
	if (0 != 12)
		sh2->r[12] += 1;
	goto SH2_RUN_CONTINUE;
}

Op60D4:
{
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[13] );
	if (0 != 13)
		sh2->r[13] += 1;
	goto SH2_RUN_CONTINUE;
}

Op60E4:
{
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[14] );
	if (0 != 14)
		sh2->r[14] += 1;
	goto SH2_RUN_CONTINUE;
}

Op60F4:
{
	sh2->r[0] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[15] );
	if (0 != 15)
		sh2->r[15] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6104:
{
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[0] );
	if (1 != 0)
		sh2->r[0] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6114:
{
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[1] );
	if (1 != 1)
		sh2->r[1] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6124:
{
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[2] );
	if (1 != 2)
		sh2->r[2] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6134:
{
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[3] );
	if (1 != 3)
		sh2->r[3] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6144:
{
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[4] );
	if (1 != 4)
		sh2->r[4] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6154:
{
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[5] );
	if (1 != 5)
		sh2->r[5] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6164:
{
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[6] );
	if (1 != 6)
		sh2->r[6] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6174:
{
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[7] );
	if (1 != 7)
		sh2->r[7] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6184:
{
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[8] );
	if (1 != 8)
		sh2->r[8] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6194:
{
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[9] );
	if (1 != 9)
		sh2->r[9] += 1;
	goto SH2_RUN_CONTINUE;
}

Op61A4:
{
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[10] );
	if (1 != 10)
		sh2->r[10] += 1;
	goto SH2_RUN_CONTINUE;
}

Op61B4:
{
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[11] );
	if (1 != 11)
		sh2->r[11] += 1;
	goto SH2_RUN_CONTINUE;
}

Op61C4:
{
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[12] );
	if (1 != 12)
		sh2->r[12] += 1;
	goto SH2_RUN_CONTINUE;
}

Op61D4:
{
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[13] );
	if (1 != 13)
		sh2->r[13] += 1;
	goto SH2_RUN_CONTINUE;
}

Op61E4:
{
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[14] );
	if (1 != 14)
		sh2->r[14] += 1;
	goto SH2_RUN_CONTINUE;
}

Op61F4:
{
	sh2->r[1] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[15] );
	if (1 != 15)
		sh2->r[15] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6204:
{
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[0] );
	if (2 != 0)
		sh2->r[0] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6214:
{
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[1] );
	if (2 != 1)
		sh2->r[1] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6224:
{
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[2] );
	if (2 != 2)
		sh2->r[2] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6234:
{
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[3] );
	if (2 != 3)
		sh2->r[3] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6244:
{
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[4] );
	if (2 != 4)
		sh2->r[4] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6254:
{
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[5] );
	if (2 != 5)
		sh2->r[5] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6264:
{
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[6] );
	if (2 != 6)
		sh2->r[6] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6274:
{
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[7] );
	if (2 != 7)
		sh2->r[7] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6284:
{
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[8] );
	if (2 != 8)
		sh2->r[8] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6294:
{
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[9] );
	if (2 != 9)
		sh2->r[9] += 1;
	goto SH2_RUN_CONTINUE;
}

Op62A4:
{
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[10] );
	if (2 != 10)
		sh2->r[10] += 1;
	goto SH2_RUN_CONTINUE;
}

Op62B4:
{
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[11] );
	if (2 != 11)
		sh2->r[11] += 1;
	goto SH2_RUN_CONTINUE;
}

Op62C4:
{
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[12] );
	if (2 != 12)
		sh2->r[12] += 1;
	goto SH2_RUN_CONTINUE;
}

Op62D4:
{
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[13] );
	if (2 != 13)
		sh2->r[13] += 1;
	goto SH2_RUN_CONTINUE;
}

Op62E4:
{
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[14] );
	if (2 != 14)
		sh2->r[14] += 1;
	goto SH2_RUN_CONTINUE;
}

Op62F4:
{
	sh2->r[2] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[15] );
	if (2 != 15)
		sh2->r[15] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6304:
{
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[0] );
	if (3 != 0)
		sh2->r[0] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6314:
{
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[1] );
	if (3 != 1)
		sh2->r[1] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6324:
{
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[2] );
	if (3 != 2)
		sh2->r[2] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6334:
{
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[3] );
	if (3 != 3)
		sh2->r[3] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6344:
{
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[4] );
	if (3 != 4)
		sh2->r[4] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6354:
{
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[5] );
	if (3 != 5)
		sh2->r[5] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6364:
{
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[6] );
	if (3 != 6)
		sh2->r[6] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6374:
{
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[7] );
	if (3 != 7)
		sh2->r[7] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6384:
{
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[8] );
	if (3 != 8)
		sh2->r[8] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6394:
{
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[9] );
	if (3 != 9)
		sh2->r[9] += 1;
	goto SH2_RUN_CONTINUE;
}

Op63A4:
{
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[10] );
	if (3 != 10)
		sh2->r[10] += 1;
	goto SH2_RUN_CONTINUE;
}

Op63B4:
{
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[11] );
	if (3 != 11)
		sh2->r[11] += 1;
	goto SH2_RUN_CONTINUE;
}

Op63C4:
{
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[12] );
	if (3 != 12)
		sh2->r[12] += 1;
	goto SH2_RUN_CONTINUE;
}

Op63D4:
{
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[13] );
	if (3 != 13)
		sh2->r[13] += 1;
	goto SH2_RUN_CONTINUE;
}

Op63E4:
{
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[14] );
	if (3 != 14)
		sh2->r[14] += 1;
	goto SH2_RUN_CONTINUE;
}

Op63F4:
{
	sh2->r[3] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[15] );
	if (3 != 15)
		sh2->r[15] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6404:
{
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[0] );
	if (4 != 0)
		sh2->r[0] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6414:
{
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[1] );
	if (4 != 1)
		sh2->r[1] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6424:
{
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[2] );
	if (4 != 2)
		sh2->r[2] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6434:
{
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[3] );
	if (4 != 3)
		sh2->r[3] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6444:
{
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[4] );
	if (4 != 4)
		sh2->r[4] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6454:
{
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[5] );
	if (4 != 5)
		sh2->r[5] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6464:
{
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[6] );
	if (4 != 6)
		sh2->r[6] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6474:
{
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[7] );
	if (4 != 7)
		sh2->r[7] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6484:
{
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[8] );
	if (4 != 8)
		sh2->r[8] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6494:
{
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[9] );
	if (4 != 9)
		sh2->r[9] += 1;
	goto SH2_RUN_CONTINUE;
}

Op64A4:
{
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[10] );
	if (4 != 10)
		sh2->r[10] += 1;
	goto SH2_RUN_CONTINUE;
}

Op64B4:
{
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[11] );
	if (4 != 11)
		sh2->r[11] += 1;
	goto SH2_RUN_CONTINUE;
}

Op64C4:
{
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[12] );
	if (4 != 12)
		sh2->r[12] += 1;
	goto SH2_RUN_CONTINUE;
}

Op64D4:
{
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[13] );
	if (4 != 13)
		sh2->r[13] += 1;
	goto SH2_RUN_CONTINUE;
}

Op64E4:
{
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[14] );
	if (4 != 14)
		sh2->r[14] += 1;
	goto SH2_RUN_CONTINUE;
}

Op64F4:
{
	sh2->r[4] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[15] );
	if (4 != 15)
		sh2->r[15] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6504:
{
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[0] );
	if (5 != 0)
		sh2->r[0] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6514:
{
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[1] );
	if (5 != 1)
		sh2->r[1] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6524:
{
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[2] );
	if (5 != 2)
		sh2->r[2] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6534:
{
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[3] );
	if (5 != 3)
		sh2->r[3] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6544:
{
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[4] );
	if (5 != 4)
		sh2->r[4] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6554:
{
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[5] );
	if (5 != 5)
		sh2->r[5] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6564:
{
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[6] );
	if (5 != 6)
		sh2->r[6] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6574:
{
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[7] );
	if (5 != 7)
		sh2->r[7] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6584:
{
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[8] );
	if (5 != 8)
		sh2->r[8] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6594:
{
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[9] );
	if (5 != 9)
		sh2->r[9] += 1;
	goto SH2_RUN_CONTINUE;
}

Op65A4:
{
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[10] );
	if (5 != 10)
		sh2->r[10] += 1;
	goto SH2_RUN_CONTINUE;
}

Op65B4:
{
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[11] );
	if (5 != 11)
		sh2->r[11] += 1;
	goto SH2_RUN_CONTINUE;
}

Op65C4:
{
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[12] );
	if (5 != 12)
		sh2->r[12] += 1;
	goto SH2_RUN_CONTINUE;
}

Op65D4:
{
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[13] );
	if (5 != 13)
		sh2->r[13] += 1;
	goto SH2_RUN_CONTINUE;
}

Op65E4:
{
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[14] );
	if (5 != 14)
		sh2->r[14] += 1;
	goto SH2_RUN_CONTINUE;
}

Op65F4:
{
	sh2->r[5] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[15] );
	if (5 != 15)
		sh2->r[15] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6604:
{
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[0] );
	if (6 != 0)
		sh2->r[0] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6614:
{
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[1] );
	if (6 != 1)
		sh2->r[1] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6624:
{
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[2] );
	if (6 != 2)
		sh2->r[2] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6634:
{
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[3] );
	if (6 != 3)
		sh2->r[3] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6644:
{
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[4] );
	if (6 != 4)
		sh2->r[4] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6654:
{
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[5] );
	if (6 != 5)
		sh2->r[5] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6664:
{
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[6] );
	if (6 != 6)
		sh2->r[6] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6674:
{
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[7] );
	if (6 != 7)
		sh2->r[7] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6684:
{
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[8] );
	if (6 != 8)
		sh2->r[8] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6694:
{
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[9] );
	if (6 != 9)
		sh2->r[9] += 1;
	goto SH2_RUN_CONTINUE;
}

Op66A4:
{
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[10] );
	if (6 != 10)
		sh2->r[10] += 1;
	goto SH2_RUN_CONTINUE;
}

Op66B4:
{
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[11] );
	if (6 != 11)
		sh2->r[11] += 1;
	goto SH2_RUN_CONTINUE;
}

Op66C4:
{
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[12] );
	if (6 != 12)
		sh2->r[12] += 1;
	goto SH2_RUN_CONTINUE;
}

Op66D4:
{
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[13] );
	if (6 != 13)
		sh2->r[13] += 1;
	goto SH2_RUN_CONTINUE;
}

Op66E4:
{
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[14] );
	if (6 != 14)
		sh2->r[14] += 1;
	goto SH2_RUN_CONTINUE;
}

Op66F4:
{
	sh2->r[6] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[15] );
	if (6 != 15)
		sh2->r[15] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6704:
{
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[0] );
	if (7 != 0)
		sh2->r[0] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6714:
{
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[1] );
	if (7 != 1)
		sh2->r[1] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6724:
{
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[2] );
	if (7 != 2)
		sh2->r[2] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6734:
{
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[3] );
	if (7 != 3)
		sh2->r[3] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6744:
{
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[4] );
	if (7 != 4)
		sh2->r[4] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6754:
{
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[5] );
	if (7 != 5)
		sh2->r[5] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6764:
{
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[6] );
	if (7 != 6)
		sh2->r[6] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6774:
{
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[7] );
	if (7 != 7)
		sh2->r[7] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6784:
{
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[8] );
	if (7 != 8)
		sh2->r[8] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6794:
{
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[9] );
	if (7 != 9)
		sh2->r[9] += 1;
	goto SH2_RUN_CONTINUE;
}

Op67A4:
{
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[10] );
	if (7 != 10)
		sh2->r[10] += 1;
	goto SH2_RUN_CONTINUE;
}

Op67B4:
{
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[11] );
	if (7 != 11)
		sh2->r[11] += 1;
	goto SH2_RUN_CONTINUE;
}

Op67C4:
{
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[12] );
	if (7 != 12)
		sh2->r[12] += 1;
	goto SH2_RUN_CONTINUE;
}

Op67D4:
{
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[13] );
	if (7 != 13)
		sh2->r[13] += 1;
	goto SH2_RUN_CONTINUE;
}

Op67E4:
{
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[14] );
	if (7 != 14)
		sh2->r[14] += 1;
	goto SH2_RUN_CONTINUE;
}

Op67F4:
{
	sh2->r[7] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[15] );
	if (7 != 15)
		sh2->r[15] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6804:
{
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[0] );
	if (8 != 0)
		sh2->r[0] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6814:
{
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[1] );
	if (8 != 1)
		sh2->r[1] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6824:
{
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[2] );
	if (8 != 2)
		sh2->r[2] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6834:
{
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[3] );
	if (8 != 3)
		sh2->r[3] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6844:
{
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[4] );
	if (8 != 4)
		sh2->r[4] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6854:
{
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[5] );
	if (8 != 5)
		sh2->r[5] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6864:
{
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[6] );
	if (8 != 6)
		sh2->r[6] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6874:
{
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[7] );
	if (8 != 7)
		sh2->r[7] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6884:
{
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[8] );
	if (8 != 8)
		sh2->r[8] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6894:
{
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[9] );
	if (8 != 9)
		sh2->r[9] += 1;
	goto SH2_RUN_CONTINUE;
}

Op68A4:
{
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[10] );
	if (8 != 10)
		sh2->r[10] += 1;
	goto SH2_RUN_CONTINUE;
}

Op68B4:
{
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[11] );
	if (8 != 11)
		sh2->r[11] += 1;
	goto SH2_RUN_CONTINUE;
}

Op68C4:
{
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[12] );
	if (8 != 12)
		sh2->r[12] += 1;
	goto SH2_RUN_CONTINUE;
}

Op68D4:
{
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[13] );
	if (8 != 13)
		sh2->r[13] += 1;
	goto SH2_RUN_CONTINUE;
}

Op68E4:
{
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[14] );
	if (8 != 14)
		sh2->r[14] += 1;
	goto SH2_RUN_CONTINUE;
}

Op68F4:
{
	sh2->r[8] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[15] );
	if (8 != 15)
		sh2->r[15] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6904:
{
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[0] );
	if (9 != 0)
		sh2->r[0] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6914:
{
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[1] );
	if (9 != 1)
		sh2->r[1] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6924:
{
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[2] );
	if (9 != 2)
		sh2->r[2] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6934:
{
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[3] );
	if (9 != 3)
		sh2->r[3] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6944:
{
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[4] );
	if (9 != 4)
		sh2->r[4] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6954:
{
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[5] );
	if (9 != 5)
		sh2->r[5] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6964:
{
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[6] );
	if (9 != 6)
		sh2->r[6] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6974:
{
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[7] );
	if (9 != 7)
		sh2->r[7] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6984:
{
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[8] );
	if (9 != 8)
		sh2->r[8] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6994:
{
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[9] );
	if (9 != 9)
		sh2->r[9] += 1;
	goto SH2_RUN_CONTINUE;
}

Op69A4:
{
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[10] );
	if (9 != 10)
		sh2->r[10] += 1;
	goto SH2_RUN_CONTINUE;
}

Op69B4:
{
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[11] );
	if (9 != 11)
		sh2->r[11] += 1;
	goto SH2_RUN_CONTINUE;
}

Op69C4:
{
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[12] );
	if (9 != 12)
		sh2->r[12] += 1;
	goto SH2_RUN_CONTINUE;
}

Op69D4:
{
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[13] );
	if (9 != 13)
		sh2->r[13] += 1;
	goto SH2_RUN_CONTINUE;
}

Op69E4:
{
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[14] );
	if (9 != 14)
		sh2->r[14] += 1;
	goto SH2_RUN_CONTINUE;
}

Op69F4:
{
	sh2->r[9] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[15] );
	if (9 != 15)
		sh2->r[15] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6A04:
{
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[0] );
	if (10 != 0)
		sh2->r[0] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6A14:
{
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[1] );
	if (10 != 1)
		sh2->r[1] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6A24:
{
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[2] );
	if (10 != 2)
		sh2->r[2] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6A34:
{
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[3] );
	if (10 != 3)
		sh2->r[3] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6A44:
{
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[4] );
	if (10 != 4)
		sh2->r[4] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6A54:
{
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[5] );
	if (10 != 5)
		sh2->r[5] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6A64:
{
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[6] );
	if (10 != 6)
		sh2->r[6] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6A74:
{
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[7] );
	if (10 != 7)
		sh2->r[7] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6A84:
{
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[8] );
	if (10 != 8)
		sh2->r[8] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6A94:
{
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[9] );
	if (10 != 9)
		sh2->r[9] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6AA4:
{
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[10] );
	if (10 != 10)
		sh2->r[10] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6AB4:
{
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[11] );
	if (10 != 11)
		sh2->r[11] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6AC4:
{
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[12] );
	if (10 != 12)
		sh2->r[12] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6AD4:
{
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[13] );
	if (10 != 13)
		sh2->r[13] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6AE4:
{
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[14] );
	if (10 != 14)
		sh2->r[14] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6AF4:
{
	sh2->r[10] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[15] );
	if (10 != 15)
		sh2->r[15] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6B04:
{
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[0] );
	if (11 != 0)
		sh2->r[0] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6B14:
{
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[1] );
	if (11 != 1)
		sh2->r[1] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6B24:
{
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[2] );
	if (11 != 2)
		sh2->r[2] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6B34:
{
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[3] );
	if (11 != 3)
		sh2->r[3] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6B44:
{
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[4] );
	if (11 != 4)
		sh2->r[4] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6B54:
{
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[5] );
	if (11 != 5)
		sh2->r[5] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6B64:
{
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[6] );
	if (11 != 6)
		sh2->r[6] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6B74:
{
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[7] );
	if (11 != 7)
		sh2->r[7] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6B84:
{
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[8] );
	if (11 != 8)
		sh2->r[8] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6B94:
{
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[9] );
	if (11 != 9)
		sh2->r[9] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6BA4:
{
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[10] );
	if (11 != 10)
		sh2->r[10] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6BB4:
{
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[11] );
	if (11 != 11)
		sh2->r[11] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6BC4:
{
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[12] );
	if (11 != 12)
		sh2->r[12] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6BD4:
{
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[13] );
	if (11 != 13)
		sh2->r[13] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6BE4:
{
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[14] );
	if (11 != 14)
		sh2->r[14] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6BF4:
{
	sh2->r[11] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[15] );
	if (11 != 15)
		sh2->r[15] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6C04:
{
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[0] );
	if (12 != 0)
		sh2->r[0] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6C14:
{
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[1] );
	if (12 != 1)
		sh2->r[1] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6C24:
{
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[2] );
	if (12 != 2)
		sh2->r[2] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6C34:
{
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[3] );
	if (12 != 3)
		sh2->r[3] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6C44:
{
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[4] );
	if (12 != 4)
		sh2->r[4] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6C54:
{
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[5] );
	if (12 != 5)
		sh2->r[5] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6C64:
{
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[6] );
	if (12 != 6)
		sh2->r[6] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6C74:
{
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[7] );
	if (12 != 7)
		sh2->r[7] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6C84:
{
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[8] );
	if (12 != 8)
		sh2->r[8] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6C94:
{
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[9] );
	if (12 != 9)
		sh2->r[9] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6CA4:
{
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[10] );
	if (12 != 10)
		sh2->r[10] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6CB4:
{
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[11] );
	if (12 != 11)
		sh2->r[11] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6CC4:
{
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[12] );
	if (12 != 12)
		sh2->r[12] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6CD4:
{
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[13] );
	if (12 != 13)
		sh2->r[13] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6CE4:
{
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[14] );
	if (12 != 14)
		sh2->r[14] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6CF4:
{
	sh2->r[12] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[15] );
	if (12 != 15)
		sh2->r[15] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6D04:
{
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[0] );
	if (13 != 0)
		sh2->r[0] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6D14:
{
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[1] );
	if (13 != 1)
		sh2->r[1] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6D24:
{
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[2] );
	if (13 != 2)
		sh2->r[2] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6D34:
{
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[3] );
	if (13 != 3)
		sh2->r[3] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6D44:
{
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[4] );
	if (13 != 4)
		sh2->r[4] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6D54:
{
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[5] );
	if (13 != 5)
		sh2->r[5] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6D64:
{
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[6] );
	if (13 != 6)
		sh2->r[6] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6D74:
{
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[7] );
	if (13 != 7)
		sh2->r[7] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6D84:
{
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[8] );
	if (13 != 8)
		sh2->r[8] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6D94:
{
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[9] );
	if (13 != 9)
		sh2->r[9] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6DA4:
{
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[10] );
	if (13 != 10)
		sh2->r[10] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6DB4:
{
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[11] );
	if (13 != 11)
		sh2->r[11] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6DC4:
{
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[12] );
	if (13 != 12)
		sh2->r[12] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6DD4:
{
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[13] );
	if (13 != 13)
		sh2->r[13] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6DE4:
{
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[14] );
	if (13 != 14)
		sh2->r[14] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6DF4:
{
	sh2->r[13] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[15] );
	if (13 != 15)
		sh2->r[15] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6E04:
{
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[0] );
	if (14 != 0)
		sh2->r[0] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6E14:
{
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[1] );
	if (14 != 1)
		sh2->r[1] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6E24:
{
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[2] );
	if (14 != 2)
		sh2->r[2] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6E34:
{
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[3] );
	if (14 != 3)
		sh2->r[3] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6E44:
{
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[4] );
	if (14 != 4)
		sh2->r[4] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6E54:
{
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[5] );
	if (14 != 5)
		sh2->r[5] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6E64:
{
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[6] );
	if (14 != 6)
		sh2->r[6] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6E74:
{
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[7] );
	if (14 != 7)
		sh2->r[7] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6E84:
{
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[8] );
	if (14 != 8)
		sh2->r[8] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6E94:
{
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[9] );
	if (14 != 9)
		sh2->r[9] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6EA4:
{
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[10] );
	if (14 != 10)
		sh2->r[10] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6EB4:
{
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[11] );
	if (14 != 11)
		sh2->r[11] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6EC4:
{
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[12] );
	if (14 != 12)
		sh2->r[12] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6ED4:
{
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[13] );
	if (14 != 13)
		sh2->r[13] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6EE4:
{
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[14] );
	if (14 != 14)
		sh2->r[14] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6EF4:
{
	sh2->r[14] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[15] );
	if (14 != 15)
		sh2->r[15] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6F04:
{
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[0] );
	if (15 != 0)
		sh2->r[0] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6F14:
{
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[1] );
	if (15 != 1)
		sh2->r[1] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6F24:
{
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[2] );
	if (15 != 2)
		sh2->r[2] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6F34:
{
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[3] );
	if (15 != 3)
		sh2->r[3] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6F44:
{
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[4] );
	if (15 != 4)
		sh2->r[4] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6F54:
{
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[5] );
	if (15 != 5)
		sh2->r[5] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6F64:
{
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[6] );
	if (15 != 6)
		sh2->r[6] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6F74:
{
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[7] );
	if (15 != 7)
		sh2->r[7] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6F84:
{
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[8] );
	if (15 != 8)
		sh2->r[8] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6F94:
{
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[9] );
	if (15 != 9)
		sh2->r[9] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6FA4:
{
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[10] );
	if (15 != 10)
		sh2->r[10] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6FB4:
{
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[11] );
	if (15 != 11)
		sh2->r[11] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6FC4:
{
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[12] );
	if (15 != 12)
		sh2->r[12] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6FD4:
{
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[13] );
	if (15 != 13)
		sh2->r[13] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6FE4:
{
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[14] );
	if (15 != 14)
		sh2->r[14] += 1;
	goto SH2_RUN_CONTINUE;
}

Op6FF4:
{
	sh2->r[15] = (UINT32)(INT32)(INT16)(INT8) RB( sh2->r[15] );
	if (15 != 15)
		sh2->r[15] += 1;
	goto SH2_RUN_CONTINUE;
}

// MOV.W @Rm+,Rn
Op6005:
{
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->r[0] );
	if (0 != 0)
		sh2->r[0] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6015:
{
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->r[1] );
	if (0 != 1)
		sh2->r[1] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6025:
{
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->r[2] );
	if (0 != 2)
		sh2->r[2] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6035:
{
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->r[3] );
	if (0 != 3)
		sh2->r[3] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6045:
{
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->r[4] );
	if (0 != 4)
		sh2->r[4] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6055:
{
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->r[5] );
	if (0 != 5)
		sh2->r[5] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6065:
{
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->r[6] );
	if (0 != 6)
		sh2->r[6] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6075:
{
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->r[7] );
	if (0 != 7)
		sh2->r[7] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6085:
{
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->r[8] );
	if (0 != 8)
		sh2->r[8] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6095:
{
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->r[9] );
	if (0 != 9)
		sh2->r[9] += 2;
	goto SH2_RUN_CONTINUE;
}

Op60A5:
{
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->r[10] );
	if (0 != 10)
		sh2->r[10] += 2;
	goto SH2_RUN_CONTINUE;
}

Op60B5:
{
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->r[11] );
	if (0 != 11)
		sh2->r[11] += 2;
	goto SH2_RUN_CONTINUE;
}

Op60C5:
{
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->r[12] );
	if (0 != 12)
		sh2->r[12] += 2;
	goto SH2_RUN_CONTINUE;
}

Op60D5:
{
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->r[13] );
	if (0 != 13)
		sh2->r[13] += 2;
	goto SH2_RUN_CONTINUE;
}

Op60E5:
{
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->r[14] );
	if (0 != 14)
		sh2->r[14] += 2;
	goto SH2_RUN_CONTINUE;
}

Op60F5:
{
	sh2->r[0] = (UINT32)(INT32)(INT16) RW( sh2->r[15] );
	if (0 != 15)
		sh2->r[15] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6105:
{
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->r[0] );
	if (1 != 0)
		sh2->r[0] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6115:
{
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->r[1] );
	if (1 != 1)
		sh2->r[1] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6125:
{
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->r[2] );
	if (1 != 2)
		sh2->r[2] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6135:
{
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->r[3] );
	if (1 != 3)
		sh2->r[3] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6145:
{
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->r[4] );
	if (1 != 4)
		sh2->r[4] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6155:
{
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->r[5] );
	if (1 != 5)
		sh2->r[5] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6165:
{
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->r[6] );
	if (1 != 6)
		sh2->r[6] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6175:
{
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->r[7] );
	if (1 != 7)
		sh2->r[7] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6185:
{
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->r[8] );
	if (1 != 8)
		sh2->r[8] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6195:
{
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->r[9] );
	if (1 != 9)
		sh2->r[9] += 2;
	goto SH2_RUN_CONTINUE;
}

Op61A5:
{
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->r[10] );
	if (1 != 10)
		sh2->r[10] += 2;
	goto SH2_RUN_CONTINUE;
}

Op61B5:
{
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->r[11] );
	if (1 != 11)
		sh2->r[11] += 2;
	goto SH2_RUN_CONTINUE;
}

Op61C5:
{
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->r[12] );
	if (1 != 12)
		sh2->r[12] += 2;
	goto SH2_RUN_CONTINUE;
}

Op61D5:
{
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->r[13] );
	if (1 != 13)
		sh2->r[13] += 2;
	goto SH2_RUN_CONTINUE;
}

Op61E5:
{
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->r[14] );
	if (1 != 14)
		sh2->r[14] += 2;
	goto SH2_RUN_CONTINUE;
}

Op61F5:
{
	sh2->r[1] = (UINT32)(INT32)(INT16) RW( sh2->r[15] );
	if (1 != 15)
		sh2->r[15] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6205:
{
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->r[0] );
	if (2 != 0)
		sh2->r[0] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6215:
{
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->r[1] );
	if (2 != 1)
		sh2->r[1] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6225:
{
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->r[2] );
	if (2 != 2)
		sh2->r[2] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6235:
{
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->r[3] );
	if (2 != 3)
		sh2->r[3] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6245:
{
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->r[4] );
	if (2 != 4)
		sh2->r[4] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6255:
{
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->r[5] );
	if (2 != 5)
		sh2->r[5] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6265:
{
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->r[6] );
	if (2 != 6)
		sh2->r[6] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6275:
{
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->r[7] );
	if (2 != 7)
		sh2->r[7] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6285:
{
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->r[8] );
	if (2 != 8)
		sh2->r[8] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6295:
{
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->r[9] );
	if (2 != 9)
		sh2->r[9] += 2;
	goto SH2_RUN_CONTINUE;
}

Op62A5:
{
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->r[10] );
	if (2 != 10)
		sh2->r[10] += 2;
	goto SH2_RUN_CONTINUE;
}

Op62B5:
{
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->r[11] );
	if (2 != 11)
		sh2->r[11] += 2;
	goto SH2_RUN_CONTINUE;
}

Op62C5:
{
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->r[12] );
	if (2 != 12)
		sh2->r[12] += 2;
	goto SH2_RUN_CONTINUE;
}

Op62D5:
{
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->r[13] );
	if (2 != 13)
		sh2->r[13] += 2;
	goto SH2_RUN_CONTINUE;
}

Op62E5:
{
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->r[14] );
	if (2 != 14)
		sh2->r[14] += 2;
	goto SH2_RUN_CONTINUE;
}

Op62F5:
{
	sh2->r[2] = (UINT32)(INT32)(INT16) RW( sh2->r[15] );
	if (2 != 15)
		sh2->r[15] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6305:
{
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->r[0] );
	if (3 != 0)
		sh2->r[0] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6315:
{
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->r[1] );
	if (3 != 1)
		sh2->r[1] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6325:
{
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->r[2] );
	if (3 != 2)
		sh2->r[2] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6335:
{
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->r[3] );
	if (3 != 3)
		sh2->r[3] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6345:
{
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->r[4] );
	if (3 != 4)
		sh2->r[4] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6355:
{
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->r[5] );
	if (3 != 5)
		sh2->r[5] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6365:
{
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->r[6] );
	if (3 != 6)
		sh2->r[6] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6375:
{
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->r[7] );
	if (3 != 7)
		sh2->r[7] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6385:
{
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->r[8] );
	if (3 != 8)
		sh2->r[8] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6395:
{
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->r[9] );
	if (3 != 9)
		sh2->r[9] += 2;
	goto SH2_RUN_CONTINUE;
}

Op63A5:
{
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->r[10] );
	if (3 != 10)
		sh2->r[10] += 2;
	goto SH2_RUN_CONTINUE;
}

Op63B5:
{
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->r[11] );
	if (3 != 11)
		sh2->r[11] += 2;
	goto SH2_RUN_CONTINUE;
}

Op63C5:
{
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->r[12] );
	if (3 != 12)
		sh2->r[12] += 2;
	goto SH2_RUN_CONTINUE;
}

Op63D5:
{
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->r[13] );
	if (3 != 13)
		sh2->r[13] += 2;
	goto SH2_RUN_CONTINUE;
}

Op63E5:
{
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->r[14] );
	if (3 != 14)
		sh2->r[14] += 2;
	goto SH2_RUN_CONTINUE;
}

Op63F5:
{
	sh2->r[3] = (UINT32)(INT32)(INT16) RW( sh2->r[15] );
	if (3 != 15)
		sh2->r[15] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6405:
{
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->r[0] );
	if (4 != 0)
		sh2->r[0] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6415:
{
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->r[1] );
	if (4 != 1)
		sh2->r[1] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6425:
{
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->r[2] );
	if (4 != 2)
		sh2->r[2] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6435:
{
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->r[3] );
	if (4 != 3)
		sh2->r[3] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6445:
{
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->r[4] );
	if (4 != 4)
		sh2->r[4] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6455:
{
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->r[5] );
	if (4 != 5)
		sh2->r[5] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6465:
{
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->r[6] );
	if (4 != 6)
		sh2->r[6] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6475:
{
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->r[7] );
	if (4 != 7)
		sh2->r[7] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6485:
{
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->r[8] );
	if (4 != 8)
		sh2->r[8] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6495:
{
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->r[9] );
	if (4 != 9)
		sh2->r[9] += 2;
	goto SH2_RUN_CONTINUE;
}

Op64A5:
{
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->r[10] );
	if (4 != 10)
		sh2->r[10] += 2;
	goto SH2_RUN_CONTINUE;
}

Op64B5:
{
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->r[11] );
	if (4 != 11)
		sh2->r[11] += 2;
	goto SH2_RUN_CONTINUE;
}

Op64C5:
{
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->r[12] );
	if (4 != 12)
		sh2->r[12] += 2;
	goto SH2_RUN_CONTINUE;
}

Op64D5:
{
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->r[13] );
	if (4 != 13)
		sh2->r[13] += 2;
	goto SH2_RUN_CONTINUE;
}

Op64E5:
{
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->r[14] );
	if (4 != 14)
		sh2->r[14] += 2;
	goto SH2_RUN_CONTINUE;
}

Op64F5:
{
	sh2->r[4] = (UINT32)(INT32)(INT16) RW( sh2->r[15] );
	if (4 != 15)
		sh2->r[15] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6505:
{
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->r[0] );
	if (5 != 0)
		sh2->r[0] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6515:
{
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->r[1] );
	if (5 != 1)
		sh2->r[1] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6525:
{
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->r[2] );
	if (5 != 2)
		sh2->r[2] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6535:
{
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->r[3] );
	if (5 != 3)
		sh2->r[3] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6545:
{
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->r[4] );
	if (5 != 4)
		sh2->r[4] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6555:
{
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->r[5] );
	if (5 != 5)
		sh2->r[5] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6565:
{
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->r[6] );
	if (5 != 6)
		sh2->r[6] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6575:
{
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->r[7] );
	if (5 != 7)
		sh2->r[7] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6585:
{
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->r[8] );
	if (5 != 8)
		sh2->r[8] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6595:
{
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->r[9] );
	if (5 != 9)
		sh2->r[9] += 2;
	goto SH2_RUN_CONTINUE;
}

Op65A5:
{
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->r[10] );
	if (5 != 10)
		sh2->r[10] += 2;
	goto SH2_RUN_CONTINUE;
}

Op65B5:
{
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->r[11] );
	if (5 != 11)
		sh2->r[11] += 2;
	goto SH2_RUN_CONTINUE;
}

Op65C5:
{
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->r[12] );
	if (5 != 12)
		sh2->r[12] += 2;
	goto SH2_RUN_CONTINUE;
}

Op65D5:
{
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->r[13] );
	if (5 != 13)
		sh2->r[13] += 2;
	goto SH2_RUN_CONTINUE;
}

Op65E5:
{
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->r[14] );
	if (5 != 14)
		sh2->r[14] += 2;
	goto SH2_RUN_CONTINUE;
}

Op65F5:
{
	sh2->r[5] = (UINT32)(INT32)(INT16) RW( sh2->r[15] );
	if (5 != 15)
		sh2->r[15] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6605:
{
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->r[0] );
	if (6 != 0)
		sh2->r[0] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6615:
{
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->r[1] );
	if (6 != 1)
		sh2->r[1] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6625:
{
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->r[2] );
	if (6 != 2)
		sh2->r[2] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6635:
{
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->r[3] );
	if (6 != 3)
		sh2->r[3] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6645:
{
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->r[4] );
	if (6 != 4)
		sh2->r[4] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6655:
{
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->r[5] );
	if (6 != 5)
		sh2->r[5] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6665:
{
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->r[6] );
	if (6 != 6)
		sh2->r[6] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6675:
{
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->r[7] );
	if (6 != 7)
		sh2->r[7] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6685:
{
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->r[8] );
	if (6 != 8)
		sh2->r[8] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6695:
{
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->r[9] );
	if (6 != 9)
		sh2->r[9] += 2;
	goto SH2_RUN_CONTINUE;
}

Op66A5:
{
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->r[10] );
	if (6 != 10)
		sh2->r[10] += 2;
	goto SH2_RUN_CONTINUE;
}

Op66B5:
{
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->r[11] );
	if (6 != 11)
		sh2->r[11] += 2;
	goto SH2_RUN_CONTINUE;
}

Op66C5:
{
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->r[12] );
	if (6 != 12)
		sh2->r[12] += 2;
	goto SH2_RUN_CONTINUE;
}

Op66D5:
{
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->r[13] );
	if (6 != 13)
		sh2->r[13] += 2;
	goto SH2_RUN_CONTINUE;
}

Op66E5:
{
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->r[14] );
	if (6 != 14)
		sh2->r[14] += 2;
	goto SH2_RUN_CONTINUE;
}

Op66F5:
{
	sh2->r[6] = (UINT32)(INT32)(INT16) RW( sh2->r[15] );
	if (6 != 15)
		sh2->r[15] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6705:
{
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->r[0] );
	if (7 != 0)
		sh2->r[0] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6715:
{
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->r[1] );
	if (7 != 1)
		sh2->r[1] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6725:
{
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->r[2] );
	if (7 != 2)
		sh2->r[2] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6735:
{
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->r[3] );
	if (7 != 3)
		sh2->r[3] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6745:
{
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->r[4] );
	if (7 != 4)
		sh2->r[4] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6755:
{
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->r[5] );
	if (7 != 5)
		sh2->r[5] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6765:
{
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->r[6] );
	if (7 != 6)
		sh2->r[6] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6775:
{
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->r[7] );
	if (7 != 7)
		sh2->r[7] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6785:
{
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->r[8] );
	if (7 != 8)
		sh2->r[8] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6795:
{
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->r[9] );
	if (7 != 9)
		sh2->r[9] += 2;
	goto SH2_RUN_CONTINUE;
}

Op67A5:
{
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->r[10] );
	if (7 != 10)
		sh2->r[10] += 2;
	goto SH2_RUN_CONTINUE;
}

Op67B5:
{
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->r[11] );
	if (7 != 11)
		sh2->r[11] += 2;
	goto SH2_RUN_CONTINUE;
}

Op67C5:
{
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->r[12] );
	if (7 != 12)
		sh2->r[12] += 2;
	goto SH2_RUN_CONTINUE;
}

Op67D5:
{
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->r[13] );
	if (7 != 13)
		sh2->r[13] += 2;
	goto SH2_RUN_CONTINUE;
}

Op67E5:
{
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->r[14] );
	if (7 != 14)
		sh2->r[14] += 2;
	goto SH2_RUN_CONTINUE;
}

Op67F5:
{
	sh2->r[7] = (UINT32)(INT32)(INT16) RW( sh2->r[15] );
	if (7 != 15)
		sh2->r[15] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6805:
{
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->r[0] );
	if (8 != 0)
		sh2->r[0] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6815:
{
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->r[1] );
	if (8 != 1)
		sh2->r[1] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6825:
{
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->r[2] );
	if (8 != 2)
		sh2->r[2] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6835:
{
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->r[3] );
	if (8 != 3)
		sh2->r[3] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6845:
{
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->r[4] );
	if (8 != 4)
		sh2->r[4] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6855:
{
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->r[5] );
	if (8 != 5)
		sh2->r[5] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6865:
{
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->r[6] );
	if (8 != 6)
		sh2->r[6] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6875:
{
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->r[7] );
	if (8 != 7)
		sh2->r[7] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6885:
{
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->r[8] );
	if (8 != 8)
		sh2->r[8] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6895:
{
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->r[9] );
	if (8 != 9)
		sh2->r[9] += 2;
	goto SH2_RUN_CONTINUE;
}

Op68A5:
{
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->r[10] );
	if (8 != 10)
		sh2->r[10] += 2;
	goto SH2_RUN_CONTINUE;
}

Op68B5:
{
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->r[11] );
	if (8 != 11)
		sh2->r[11] += 2;
	goto SH2_RUN_CONTINUE;
}

Op68C5:
{
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->r[12] );
	if (8 != 12)
		sh2->r[12] += 2;
	goto SH2_RUN_CONTINUE;
}

Op68D5:
{
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->r[13] );
	if (8 != 13)
		sh2->r[13] += 2;
	goto SH2_RUN_CONTINUE;
}

Op68E5:
{
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->r[14] );
	if (8 != 14)
		sh2->r[14] += 2;
	goto SH2_RUN_CONTINUE;
}

Op68F5:
{
	sh2->r[8] = (UINT32)(INT32)(INT16) RW( sh2->r[15] );
	if (8 != 15)
		sh2->r[15] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6905:
{
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->r[0] );
	if (9 != 0)
		sh2->r[0] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6915:
{
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->r[1] );
	if (9 != 1)
		sh2->r[1] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6925:
{
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->r[2] );
	if (9 != 2)
		sh2->r[2] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6935:
{
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->r[3] );
	if (9 != 3)
		sh2->r[3] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6945:
{
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->r[4] );
	if (9 != 4)
		sh2->r[4] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6955:
{
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->r[5] );
	if (9 != 5)
		sh2->r[5] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6965:
{
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->r[6] );
	if (9 != 6)
		sh2->r[6] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6975:
{
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->r[7] );
	if (9 != 7)
		sh2->r[7] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6985:
{
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->r[8] );
	if (9 != 8)
		sh2->r[8] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6995:
{
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->r[9] );
	if (9 != 9)
		sh2->r[9] += 2;
	goto SH2_RUN_CONTINUE;
}

Op69A5:
{
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->r[10] );
	if (9 != 10)
		sh2->r[10] += 2;
	goto SH2_RUN_CONTINUE;
}

Op69B5:
{
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->r[11] );
	if (9 != 11)
		sh2->r[11] += 2;
	goto SH2_RUN_CONTINUE;
}

Op69C5:
{
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->r[12] );
	if (9 != 12)
		sh2->r[12] += 2;
	goto SH2_RUN_CONTINUE;
}

Op69D5:
{
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->r[13] );
	if (9 != 13)
		sh2->r[13] += 2;
	goto SH2_RUN_CONTINUE;
}

Op69E5:
{
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->r[14] );
	if (9 != 14)
		sh2->r[14] += 2;
	goto SH2_RUN_CONTINUE;
}

Op69F5:
{
	sh2->r[9] = (UINT32)(INT32)(INT16) RW( sh2->r[15] );
	if (9 != 15)
		sh2->r[15] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6A05:
{
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->r[0] );
	if (10 != 0)
		sh2->r[0] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6A15:
{
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->r[1] );
	if (10 != 1)
		sh2->r[1] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6A25:
{
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->r[2] );
	if (10 != 2)
		sh2->r[2] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6A35:
{
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->r[3] );
	if (10 != 3)
		sh2->r[3] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6A45:
{
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->r[4] );
	if (10 != 4)
		sh2->r[4] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6A55:
{
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->r[5] );
	if (10 != 5)
		sh2->r[5] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6A65:
{
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->r[6] );
	if (10 != 6)
		sh2->r[6] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6A75:
{
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->r[7] );
	if (10 != 7)
		sh2->r[7] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6A85:
{
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->r[8] );
	if (10 != 8)
		sh2->r[8] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6A95:
{
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->r[9] );
	if (10 != 9)
		sh2->r[9] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6AA5:
{
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->r[10] );
	if (10 != 10)
		sh2->r[10] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6AB5:
{
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->r[11] );
	if (10 != 11)
		sh2->r[11] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6AC5:
{
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->r[12] );
	if (10 != 12)
		sh2->r[12] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6AD5:
{
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->r[13] );
	if (10 != 13)
		sh2->r[13] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6AE5:
{
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->r[14] );
	if (10 != 14)
		sh2->r[14] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6AF5:
{
	sh2->r[10] = (UINT32)(INT32)(INT16) RW( sh2->r[15] );
	if (10 != 15)
		sh2->r[15] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6B05:
{
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->r[0] );
	if (11 != 0)
		sh2->r[0] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6B15:
{
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->r[1] );
	if (11 != 1)
		sh2->r[1] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6B25:
{
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->r[2] );
	if (11 != 2)
		sh2->r[2] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6B35:
{
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->r[3] );
	if (11 != 3)
		sh2->r[3] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6B45:
{
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->r[4] );
	if (11 != 4)
		sh2->r[4] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6B55:
{
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->r[5] );
	if (11 != 5)
		sh2->r[5] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6B65:
{
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->r[6] );
	if (11 != 6)
		sh2->r[6] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6B75:
{
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->r[7] );
	if (11 != 7)
		sh2->r[7] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6B85:
{
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->r[8] );
	if (11 != 8)
		sh2->r[8] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6B95:
{
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->r[9] );
	if (11 != 9)
		sh2->r[9] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6BA5:
{
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->r[10] );
	if (11 != 10)
		sh2->r[10] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6BB5:
{
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->r[11] );
	if (11 != 11)
		sh2->r[11] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6BC5:
{
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->r[12] );
	if (11 != 12)
		sh2->r[12] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6BD5:
{
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->r[13] );
	if (11 != 13)
		sh2->r[13] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6BE5:
{
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->r[14] );
	if (11 != 14)
		sh2->r[14] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6BF5:
{
	sh2->r[11] = (UINT32)(INT32)(INT16) RW( sh2->r[15] );
	if (11 != 15)
		sh2->r[15] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6C05:
{
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->r[0] );
	if (12 != 0)
		sh2->r[0] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6C15:
{
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->r[1] );
	if (12 != 1)
		sh2->r[1] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6C25:
{
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->r[2] );
	if (12 != 2)
		sh2->r[2] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6C35:
{
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->r[3] );
	if (12 != 3)
		sh2->r[3] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6C45:
{
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->r[4] );
	if (12 != 4)
		sh2->r[4] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6C55:
{
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->r[5] );
	if (12 != 5)
		sh2->r[5] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6C65:
{
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->r[6] );
	if (12 != 6)
		sh2->r[6] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6C75:
{
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->r[7] );
	if (12 != 7)
		sh2->r[7] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6C85:
{
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->r[8] );
	if (12 != 8)
		sh2->r[8] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6C95:
{
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->r[9] );
	if (12 != 9)
		sh2->r[9] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6CA5:
{
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->r[10] );
	if (12 != 10)
		sh2->r[10] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6CB5:
{
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->r[11] );
	if (12 != 11)
		sh2->r[11] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6CC5:
{
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->r[12] );
	if (12 != 12)
		sh2->r[12] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6CD5:
{
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->r[13] );
	if (12 != 13)
		sh2->r[13] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6CE5:
{
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->r[14] );
	if (12 != 14)
		sh2->r[14] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6CF5:
{
	sh2->r[12] = (UINT32)(INT32)(INT16) RW( sh2->r[15] );
	if (12 != 15)
		sh2->r[15] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6D05:
{
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->r[0] );
	if (13 != 0)
		sh2->r[0] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6D15:
{
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->r[1] );
	if (13 != 1)
		sh2->r[1] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6D25:
{
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->r[2] );
	if (13 != 2)
		sh2->r[2] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6D35:
{
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->r[3] );
	if (13 != 3)
		sh2->r[3] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6D45:
{
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->r[4] );
	if (13 != 4)
		sh2->r[4] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6D55:
{
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->r[5] );
	if (13 != 5)
		sh2->r[5] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6D65:
{
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->r[6] );
	if (13 != 6)
		sh2->r[6] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6D75:
{
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->r[7] );
	if (13 != 7)
		sh2->r[7] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6D85:
{
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->r[8] );
	if (13 != 8)
		sh2->r[8] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6D95:
{
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->r[9] );
	if (13 != 9)
		sh2->r[9] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6DA5:
{
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->r[10] );
	if (13 != 10)
		sh2->r[10] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6DB5:
{
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->r[11] );
	if (13 != 11)
		sh2->r[11] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6DC5:
{
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->r[12] );
	if (13 != 12)
		sh2->r[12] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6DD5:
{
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->r[13] );
	if (13 != 13)
		sh2->r[13] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6DE5:
{
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->r[14] );
	if (13 != 14)
		sh2->r[14] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6DF5:
{
	sh2->r[13] = (UINT32)(INT32)(INT16) RW( sh2->r[15] );
	if (13 != 15)
		sh2->r[15] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6E05:
{
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->r[0] );
	if (14 != 0)
		sh2->r[0] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6E15:
{
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->r[1] );
	if (14 != 1)
		sh2->r[1] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6E25:
{
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->r[2] );
	if (14 != 2)
		sh2->r[2] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6E35:
{
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->r[3] );
	if (14 != 3)
		sh2->r[3] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6E45:
{
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->r[4] );
	if (14 != 4)
		sh2->r[4] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6E55:
{
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->r[5] );
	if (14 != 5)
		sh2->r[5] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6E65:
{
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->r[6] );
	if (14 != 6)
		sh2->r[6] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6E75:
{
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->r[7] );
	if (14 != 7)
		sh2->r[7] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6E85:
{
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->r[8] );
	if (14 != 8)
		sh2->r[8] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6E95:
{
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->r[9] );
	if (14 != 9)
		sh2->r[9] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6EA5:
{
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->r[10] );
	if (14 != 10)
		sh2->r[10] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6EB5:
{
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->r[11] );
	if (14 != 11)
		sh2->r[11] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6EC5:
{
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->r[12] );
	if (14 != 12)
		sh2->r[12] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6ED5:
{
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->r[13] );
	if (14 != 13)
		sh2->r[13] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6EE5:
{
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->r[14] );
	if (14 != 14)
		sh2->r[14] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6EF5:
{
	sh2->r[14] = (UINT32)(INT32)(INT16) RW( sh2->r[15] );
	if (14 != 15)
		sh2->r[15] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6F05:
{
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->r[0] );
	if (15 != 0)
		sh2->r[0] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6F15:
{
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->r[1] );
	if (15 != 1)
		sh2->r[1] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6F25:
{
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->r[2] );
	if (15 != 2)
		sh2->r[2] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6F35:
{
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->r[3] );
	if (15 != 3)
		sh2->r[3] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6F45:
{
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->r[4] );
	if (15 != 4)
		sh2->r[4] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6F55:
{
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->r[5] );
	if (15 != 5)
		sh2->r[5] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6F65:
{
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->r[6] );
	if (15 != 6)
		sh2->r[6] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6F75:
{
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->r[7] );
	if (15 != 7)
		sh2->r[7] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6F85:
{
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->r[8] );
	if (15 != 8)
		sh2->r[8] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6F95:
{
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->r[9] );
	if (15 != 9)
		sh2->r[9] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6FA5:
{
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->r[10] );
	if (15 != 10)
		sh2->r[10] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6FB5:
{
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->r[11] );
	if (15 != 11)
		sh2->r[11] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6FC5:
{
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->r[12] );
	if (15 != 12)
		sh2->r[12] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6FD5:
{
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->r[13] );
	if (15 != 13)
		sh2->r[13] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6FE5:
{
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->r[14] );
	if (15 != 14)
		sh2->r[14] += 2;
	goto SH2_RUN_CONTINUE;
}

Op6FF5:
{
	sh2->r[15] = (UINT32)(INT32)(INT16) RW( sh2->r[15] );
	if (15 != 15)
		sh2->r[15] += 2;
	goto SH2_RUN_CONTINUE;
}

// MOV.L @Rm+,Rn
Op6006:
{
	sh2->r[0] = RL( sh2->r[0] );
	if (0 != 0)
		sh2->r[0] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6016:
{
	sh2->r[0] = RL( sh2->r[1] );
	if (0 != 1)
		sh2->r[1] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6026:
{
	sh2->r[0] = RL( sh2->r[2] );
	if (0 != 2)
		sh2->r[2] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6036:
{
	sh2->r[0] = RL( sh2->r[3] );
	if (0 != 3)
		sh2->r[3] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6046:
{
	sh2->r[0] = RL( sh2->r[4] );
	if (0 != 4)
		sh2->r[4] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6056:
{
	sh2->r[0] = RL( sh2->r[5] );
	if (0 != 5)
		sh2->r[5] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6066:
{
	sh2->r[0] = RL( sh2->r[6] );
	if (0 != 6)
		sh2->r[6] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6076:
{
	sh2->r[0] = RL( sh2->r[7] );
	if (0 != 7)
		sh2->r[7] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6086:
{
	sh2->r[0] = RL( sh2->r[8] );
	if (0 != 8)
		sh2->r[8] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6096:
{
	sh2->r[0] = RL( sh2->r[9] );
	if (0 != 9)
		sh2->r[9] += 4;
	goto SH2_RUN_CONTINUE;
}

Op60A6:
{
	sh2->r[0] = RL( sh2->r[10] );
	if (0 != 10)
		sh2->r[10] += 4;
	goto SH2_RUN_CONTINUE;
}

Op60B6:
{
	sh2->r[0] = RL( sh2->r[11] );
	if (0 != 11)
		sh2->r[11] += 4;
	goto SH2_RUN_CONTINUE;
}

Op60C6:
{
	sh2->r[0] = RL( sh2->r[12] );
	if (0 != 12)
		sh2->r[12] += 4;
	goto SH2_RUN_CONTINUE;
}

Op60D6:
{
	sh2->r[0] = RL( sh2->r[13] );
	if (0 != 13)
		sh2->r[13] += 4;
	goto SH2_RUN_CONTINUE;
}

Op60E6:
{
	sh2->r[0] = RL( sh2->r[14] );
	if (0 != 14)
		sh2->r[14] += 4;
	goto SH2_RUN_CONTINUE;
}

Op60F6:
{
	sh2->r[0] = RL( sh2->r[15] );
	if (0 != 15)
		sh2->r[15] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6106:
{
	sh2->r[1] = RL( sh2->r[0] );
	if (1 != 0)
		sh2->r[0] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6116:
{
	sh2->r[1] = RL( sh2->r[1] );
	if (1 != 1)
		sh2->r[1] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6126:
{
	sh2->r[1] = RL( sh2->r[2] );
	if (1 != 2)
		sh2->r[2] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6136:
{
	sh2->r[1] = RL( sh2->r[3] );
	if (1 != 3)
		sh2->r[3] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6146:
{
	sh2->r[1] = RL( sh2->r[4] );
	if (1 != 4)
		sh2->r[4] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6156:
{
	sh2->r[1] = RL( sh2->r[5] );
	if (1 != 5)
		sh2->r[5] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6166:
{
	sh2->r[1] = RL( sh2->r[6] );
	if (1 != 6)
		sh2->r[6] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6176:
{
	sh2->r[1] = RL( sh2->r[7] );
	if (1 != 7)
		sh2->r[7] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6186:
{
	sh2->r[1] = RL( sh2->r[8] );
	if (1 != 8)
		sh2->r[8] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6196:
{
	sh2->r[1] = RL( sh2->r[9] );
	if (1 != 9)
		sh2->r[9] += 4;
	goto SH2_RUN_CONTINUE;
}

Op61A6:
{
	sh2->r[1] = RL( sh2->r[10] );
	if (1 != 10)
		sh2->r[10] += 4;
	goto SH2_RUN_CONTINUE;
}

Op61B6:
{
	sh2->r[1] = RL( sh2->r[11] );
	if (1 != 11)
		sh2->r[11] += 4;
	goto SH2_RUN_CONTINUE;
}

Op61C6:
{
	sh2->r[1] = RL( sh2->r[12] );
	if (1 != 12)
		sh2->r[12] += 4;
	goto SH2_RUN_CONTINUE;
}

Op61D6:
{
	sh2->r[1] = RL( sh2->r[13] );
	if (1 != 13)
		sh2->r[13] += 4;
	goto SH2_RUN_CONTINUE;
}

Op61E6:
{
	sh2->r[1] = RL( sh2->r[14] );
	if (1 != 14)
		sh2->r[14] += 4;
	goto SH2_RUN_CONTINUE;
}

Op61F6:
{
	sh2->r[1] = RL( sh2->r[15] );
	if (1 != 15)
		sh2->r[15] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6206:
{
	sh2->r[2] = RL( sh2->r[0] );
	if (2 != 0)
		sh2->r[0] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6216:
{
	sh2->r[2] = RL( sh2->r[1] );
	if (2 != 1)
		sh2->r[1] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6226:
{
	sh2->r[2] = RL( sh2->r[2] );
	if (2 != 2)
		sh2->r[2] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6236:
{
	sh2->r[2] = RL( sh2->r[3] );
	if (2 != 3)
		sh2->r[3] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6246:
{
	sh2->r[2] = RL( sh2->r[4] );
	if (2 != 4)
		sh2->r[4] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6256:
{
	sh2->r[2] = RL( sh2->r[5] );
	if (2 != 5)
		sh2->r[5] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6266:
{
	sh2->r[2] = RL( sh2->r[6] );
	if (2 != 6)
		sh2->r[6] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6276:
{
	sh2->r[2] = RL( sh2->r[7] );
	if (2 != 7)
		sh2->r[7] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6286:
{
	sh2->r[2] = RL( sh2->r[8] );
	if (2 != 8)
		sh2->r[8] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6296:
{
	sh2->r[2] = RL( sh2->r[9] );
	if (2 != 9)
		sh2->r[9] += 4;
	goto SH2_RUN_CONTINUE;
}

Op62A6:
{
	sh2->r[2] = RL( sh2->r[10] );
	if (2 != 10)
		sh2->r[10] += 4;
	goto SH2_RUN_CONTINUE;
}

Op62B6:
{
	sh2->r[2] = RL( sh2->r[11] );
	if (2 != 11)
		sh2->r[11] += 4;
	goto SH2_RUN_CONTINUE;
}

Op62C6:
{
	sh2->r[2] = RL( sh2->r[12] );
	if (2 != 12)
		sh2->r[12] += 4;
	goto SH2_RUN_CONTINUE;
}

Op62D6:
{
	sh2->r[2] = RL( sh2->r[13] );
	if (2 != 13)
		sh2->r[13] += 4;
	goto SH2_RUN_CONTINUE;
}

Op62E6:
{
	sh2->r[2] = RL( sh2->r[14] );
	if (2 != 14)
		sh2->r[14] += 4;
	goto SH2_RUN_CONTINUE;
}

Op62F6:
{
	sh2->r[2] = RL( sh2->r[15] );
	if (2 != 15)
		sh2->r[15] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6306:
{
	sh2->r[3] = RL( sh2->r[0] );
	if (3 != 0)
		sh2->r[0] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6316:
{
	sh2->r[3] = RL( sh2->r[1] );
	if (3 != 1)
		sh2->r[1] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6326:
{
	sh2->r[3] = RL( sh2->r[2] );
	if (3 != 2)
		sh2->r[2] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6336:
{
	sh2->r[3] = RL( sh2->r[3] );
	if (3 != 3)
		sh2->r[3] += 4;
	goto SH2_RUN_CONTINUE;
}

Op6346: