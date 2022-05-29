#include <assert.h>
#include <nusys.h>
#include "main.h"
#include "graphic.h"
#include "yellow_mushroom.h"

static unsigned char input_bytes[4];
static unsigned char display_offsets[4];
static unsigned char cur_offset;

void shadetri(Dynamic* dynamicp);

/* The initialization of stage 1  */
void initStage01(void)
{
  input_bytes[0] = 0;
  input_bytes[1] = 0;
  input_bytes[2] = 0;
  input_bytes[3] = 0;
  display_offsets[0] = 14;
  display_offsets[1] = 17;
  display_offsets[2] = 20;
  display_offsets[3] = 23;
  cur_offset = 0;
}

void DrawSpriteYellow(int x, int y)
{
    gDPLoadTextureBlock(glistp++, 
        yellow_mushroom, 
        G_IM_FMT_RGBA, G_IM_SIZ_16b, 
        32, 32, 0, 
        G_TX_WRAP, G_TX_WRAP, 
        G_TX_NOMASK, G_TX_NOMASK, 
        G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(glistp++, 
        x-16<<2, y-16<<2, 
        (x + 16)<<2, (y + 16)<<2,
        G_TX_RENDERTILE, 
        0 << 5, 0 << 5, 
        1 << 10, 1 << 10);
    gDPPipeSync(glistp++);
}

/* Make the display list for stage 1 and activate the task  */
void makeDL01(void)
{
  int i = 0;
  char conbuf[32];
  Dynamic* dynamicp;

  /* Specify the display list buffer  */
  dynamicp = &gfx_dynamic[gfx_gtask_no];
  glistp = &gfx_glist[gfx_gtask_no][0];

  // clear debug consonle text
  nuDebConClear(0);

  /*  The initialization of RCP  */
  gfxRCPInit();

  /* Clear the frame and Z-buffer  */
  //gfxClearCfb();

  ClearBackground(0, 0, 0);

  // Init DSP
  gDPSetCycleType(glistp++, G_CYC_1CYCLE);
  gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
  gDPSetRenderMode(glistp++, G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE);
  gDPSetDepthSource(glistp++, G_ZS_PRIM);
  gDPSetPrimDepth(glistp++, 0, 0);
  gDPSetTexturePersp(glistp++, G_TP_NONE);

  //draw mushroom sprites like a smooth brain
  DrawSpriteYellow(20,228);
  DrawSpriteYellow(32,221);
  DrawSpriteYellow(50,227);
  DrawSpriteYellow(70,211);
  DrawSpriteYellow(71,231);
  DrawSpriteYellow(90,224);
  DrawSpriteYellow(110,224);
  DrawSpriteYellow(115,228);
  DrawSpriteYellow(120,223);
  DrawSpriteYellow(151,228);
  DrawSpriteYellow(170,215);
  DrawSpriteYellow(170,231);
  DrawSpriteYellow(192,221);
  DrawSpriteYellow(210,228);
  DrawSpriteYellow(233,219);
  DrawSpriteYellow(250,224);
  DrawSpriteYellow(272,220);
  DrawSpriteYellow(290,223);

  gDPFullSync(glistp++);
  gSPEndDisplayList(glistp++);

  assert((glistp - gfx_glist[gfx_gtask_no]) < GFX_GLIST_LEN);

  /* Activate the task and 
     switch display buffers.  */
  nuGfxTaskStart(&gfx_glist[gfx_gtask_no][0],
		 (s32)(glistp - gfx_glist[gfx_gtask_no]) * sizeof (Gfx),
		 NU_GFX_UCODE_F3DEX , NU_SC_NOSWAPBUFFER);

  for(i=0; i<4; i++)
  {
      nuDebConTextPos(0,display_offsets[i],15);
      sprintf(conbuf,"%02X", input_bytes[i]);
      nuDebConCPuts(0, conbuf);
  }

  nuDebConTextPos(0,display_offsets[cur_offset],17);
  nuDebConCPuts(0,"^");


  nuDebConDisp(NU_SC_SWAPBUFFER);

  /* Switch the display list buffer  */
  gfx_gtask_no ^= 1;
}


/* The game progressing process for stage 1  */
void updateGame01(void)
{  
  static float vel = 1.0;

  /* Data reading of controller 1  */
  nuContDataGetEx(contdata,0);

  if(contdata[0].trigger & R_TRIG)
  {
      interactiveScreenShow();
  }

  if(contdata[0].trigger & Z_TRIG)
  {
      if(cur_offset >= 3 )
        cur_offset = 0;
      else
        cur_offset += 1;
  }

  if(contdata[0].button & U_JPAD)
  {
      if(input_bytes[cur_offset] < 255)
          input_bytes[cur_offset] += 1;
  }

  if(contdata[0].button & D_JPAD)
  {
      if(input_bytes[cur_offset] > 0)
          input_bytes[cur_offset] -= 1;
  }

  if(contdata[0].trigger & A_BUTTON)
  {
      if(input_bytes[cur_offset] < 255)
          input_bytes[cur_offset] += 1;
  }

  if(contdata[0].trigger & B_BUTTON)
  {
      if(input_bytes[cur_offset] > 0)
          input_bytes[cur_offset] -= 1;
  }

  if(contdata[0].trigger & START_BUTTON)
    {
      /* Remove the call-back function. */
      nuGfxFuncRemove();

      /* Specify next stage to main  */
      stage = 2;
      stageswitch = 1;
    }
}

void interactiveScreenShow(void)
{
  int i;
  int input_valid;
  char flag[26];
  char string[32];
  char flag_buf[] = "GQMXGTNDCWCABEGWGBKDFJMJTBWFACYMMSHFFTNZMHGGXQEUZHVFTCPJCKUEAMGBSXABZRMTKQCFUFXWFJMZFBMFTMDXZMVZXSRPQTCMFMBKNVMVXZRQYQBGCQYYNVSNFGEWHKBDZJMXZSFEAUVSEPGQQYTKJNQMEEFHZQCFSXFDKVPSQMUPTJSMCRGNJZKCDJDQNSHTGPBMJUKUDQWMJUKMEYQFPZGXHCCTNPHYBUEQXSYCEMWQAHMVPNKYTAY";

  char flag_buf_1[4];
  char flag_buf_2[5];
  char flag_buf_3[5];
  char flag_buf_4[5];

  /* Initialize RCP */
  gfxRCPInit();

  /* Clear the frame and Z-buffer */
  gfxClearCfb();

  if(evaluationRoutine() != 1) {
    while(1)
    {
      nuDebConTextPos(0,15,15);
      nuDebConCPuts(0, "INCORRECT");

      /* Display characters on the frame buffer */
      nuDebConDisp(NU_SC_SWAPBUFFER);
      nuDebConClear(0);
    }
  }

  for(i=0; i<5; i++)
  {
    flag_buf_1[i] = flag_buf[input_bytes[0]+i];
  }
  flag_buf_1[5] = '\0';

  for(i=0; i<5; i++)
  {
    flag_buf_2[i] = flag_buf[input_bytes[1]+i];
  }
  flag_buf_2[5] = '\0';

  for(i=0; i<5; i++)
  {
    flag_buf_3[i] = flag_buf[input_bytes[2]+i];
  }
  flag_buf_3[5] = '\0';

  for(i=0; i<4; i++)
  {
    flag_buf_4[i] = flag_buf[input_bytes[3]+i];
  }
  flag_buf_4[4] = '\0';

  while(1)
  {
    nuDebConTextPos(0,3,18);
    sprintf(flag, "FLAG-%s%s%s%s", flag_buf_1, flag_buf_2, flag_buf_3, flag_buf_4);
    nuDebConCPuts(0, flag);

    /* Display characters on the frame buffer */
    nuDebConDisp(NU_SC_SWAPBUFFER);
  }
}

int evaluationRoutine() {  
  unsigned int count;
  unsigned char string[64];
  unsigned char shifter;
  unsigned char value;
  unsigned char value_1;
  unsigned char value_2;
  unsigned char value_3;

  value_1 = input_bytes[0]^input_bytes[1];
  if((value_1 & 0x00F0) != 0xF0) {
    return -1;
  }
  if((value_1 & 0x000F) != 0x0D) {
    return -1;
  }

  value = input_bytes[2];
  if((value^0x81) != 0x0C){
    return -1;
  }

  value = input_bytes[3];
  if((value^0xD3) != 0xEC){
    return -1;
  }

  shifter = (input_bytes[0] & 0x03);
  value_2 = input_bytes[2] >> shifter;
  if(value_2 != 0x11) {
    return -1;
  }

  value_3 = input_bytes[3];
  for(count = 0; count < 3; count++){
    value_3 = (value_3 & 0xE5) | (0x2C+count);
  }

  if (value_3 != 0x2F) {
    return -1;
  }

  value = input_bytes[0];
  if((value^0x47) != 0xE4){
    return -1;
  }

  value = input_bytes[1];
  if((value^0xBD) != 0xE3){
    return -1;
  }

  return 1;
}
