#include <assert.h>
#include <nusys.h>
#include "main.h"
#include "graphic.h"
#include "purple_mushroom.h"

static float theta;  /* The rotational angle of the square  */
static unsigned temp_buf[4];
static unsigned char triPos_x; /* The display position-X */
static unsigned char triPos_y; /* The display position-Y */
static unsigned char temp_buf_index;

void shadetri(Dynamic* dynamicp);


/* The initialization of stage 1  */
void initStage02(void)
{
  theta = 0.0;
  triPos_x = 0;
  triPos_y = 0;
  temp_buf_index = 0;
  temp_buf[0] = 0;
  temp_buf[1] = 0;
  temp_buf[2] = 0;
  temp_buf[3] = 0;
}

void DrawSpritePurple(int x, int y)
{
    gDPLoadTextureBlock(glistp++, 
        purple_mushroom, 
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
void makeDL02(void)
{
  Dynamic* dynamicp;
  char conbuf[20]; 

  /* Specify the display list buffer */
  dynamicp = &gfx_dynamic[gfx_gtask_no];
  glistp = &gfx_glist[gfx_gtask_no][0];

  /* Initialize RCP */
  gfxRCPInit();

  /* Clear twhe frame and Z-buffer */
  gfxClearCfb();

  gDPSetCycleType(glistp++, G_CYC_1CYCLE);
  gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
  gDPSetRenderMode(glistp++, G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE);
  gDPSetDepthSource(glistp++, G_ZS_PRIM);
  gDPSetPrimDepth(glistp++, 0, 0);
  gDPSetTexturePersp(glistp++, G_TP_NONE);

  // draw sprites like a smooth brain
  DrawSpriteYellow((20+triPos_x),(21+triPos_y));
  DrawSpritePurple(20,228);
  DrawSpritePurple(32,221);
  DrawSpritePurple(50,227);
  DrawSpritePurple(70,211);
  DrawSpritePurple(70,230);
  DrawSpritePurple(90,224);
  DrawSpritePurple(110,224);
  DrawSpritePurple(115,228);
  DrawSpritePurple(120,223);
  DrawSpritePurple(127,213);
  DrawSpritePurple(128,221);
  DrawSpritePurple(141,218);
  DrawSpritePurple(151,228);
  DrawSpritePurple(160,234);
  DrawSpritePurple(170,215);
  DrawSpritePurple(192,221);
  DrawSpritePurple(210,228);
  DrawSpritePurple(222,230);
  DrawSpritePurple(233,219);
  DrawSpritePurple(241,224);
  DrawSpritePurple(245,219);
  DrawSpritePurple(272,220);
  DrawSpritePurple(290,223);

  /* projection,modeling matrix set */
  guOrtho(&dynamicp->projection,
    -(float)SCREEN_WD/2.0F, (float)SCREEN_WD/2.0F,
    -(float)SCREEN_HT/2.0F, (float)SCREEN_HT/2.0F,
    1.0F, 10.0F, 1.0F);
  guTranslate(&dynamicp->translate, (float)triPos_x, (float)triPos_y, 0.0F);

  /* Draw a square */
  //shadetri(dynamicp);

  gDPFullSync(glistp++);
  gSPEndDisplayList(glistp++);

  /* Activate the task and 
     switch display buffers */
  nuGfxTaskStart(&gfx_glist[gfx_gtask_no][0],
     (s32)(glistp - gfx_glist[gfx_gtask_no]) * sizeof (Gfx),
     NU_GFX_UCODE_F3DEX , NU_SC_NOSWAPBUFFER);

  /* Switch display list buffers */
  gfx_gtask_no ^= 1;

  // clear debug consonle text
  nuDebConClear(0);

  /* Change character representation positions */
  nuDebConTextPos(0,18,2);
  sprintf(conbuf,"X = %x\0",triPos_x);
  nuDebConCPuts(0, conbuf);

  nuDebConTextPos(0,25,2);
  sprintf(conbuf,"Y = %x\0",triPos_y);
  nuDebConCPuts(0, conbuf);
   
  /* Display characters on the frame buffer */
  nuDebConDisp(NU_SC_SWAPBUFFER);

}

void screenDisplayForNFT(void)
{
  int i;
  unsigned char flag[26];
  unsigned char string[32];
  unsigned char flag_buf[] = "GQMXGTNDCWCABEGWGBKDFJMJTBWFACYMMSHFFTNZMHGGXQEUZHVFTCPJCKUEAMGBSXABZRMTKQCFUFXWFJMZFBMFTMDXZMVZXSRPQTCMFMBKNVMVXZRQYQBGCQYYNVSNFGEWHKBDZJMXZSFEAUVSEPGQQYTKJNQMEEFHZQCFSXFDKVPSQMUPTJSMCRGNJZKCDJDQNSHTGPBMJUKUDQWMJUKMEYQFPZGXHCCTNPHYBUEQXSYCEMWQAHMVPNKYTAY";

  // should these print "you cant patch me" if the
  // input booleans for Start and Z are not set ?
  unsigned char flag_buf_1[6];
  unsigned char flag_buf_2[6];
  unsigned char flag_buf_3[6];
  unsigned char flag_buf_4[6];
  unsigned char offset_1 = 0;
  unsigned char offset_2 = 0;

  /* Initialize RCP */
  gfxRCPInit();

  /* Clear the frame and Z-buffer */
  gfxClearCfb();

  // clear debug consonle text
  nuDebConClear(0);

  offset_1 = temp_buf[0];
  offset_2 = temp_buf[1];

  for(i=0; i<5; i++)
  {
    flag_buf_1[i] = flag_buf[offset_1+i];
  }
  flag_buf_1[5] = '\0';

  for(i=0; i<5; i++)
  {
    flag_buf_2[i] = flag_buf[offset_2+i];
  }
  flag_buf_2[5] = '\0';

  for(i=0; i<5; i++)
  {
    flag_buf_3[i] = flag_buf[(offset_1+16)+i];
  }
  flag_buf_3[5] = '\0';

  for(i=0; i<5; i++)
  {
    flag_buf_4[i] = flag_buf[(offset_2+24)+i];
  }
  flag_buf_4[5] = '\0';

  while(1)
  {
    nuDebConTextPos(0,3,18);
    sprintf(flag, "FLAG-%s%s%s%s", flag_buf_1, flag_buf_2, flag_buf_3, flag_buf_4);
    nuDebConCPuts(0, flag);

    /* Display characters on the frame buffer */
    nuDebConDisp(NU_SC_SWAPBUFFER);
  }
}

int proceduralOperation(void)
{
    int i;
    unsigned char string[32];

    /* Initialize RCP */
    gfxRCPInit();

    /* Clear the frame and Z-buffer */
    gfxClearCfb();

    // clear debug consonle text
    nuDebConClear(0);

    nuDebConTextPos(0,7,8);
    sprintf(string,"( %x, %x )", temp_buf[0], temp_buf[1]);
    nuDebConCPuts(0, string);

    if((temp_buf[0] & 0x80) != 0x80){
        return -1;
    }

    if((temp_buf[1] & 0x01) != 0x00){
        return -1;
    }

    if((temp_buf[1] & 0x80) != 0x00){
        return -1;
    }

    if((temp_buf[0] & 0x20) != 0x20){
        return -1;
    }

    if((temp_buf[1] & 0x40) != 0x40){
        return -1;
    }

    if((temp_buf[0] & 0x40) != 0x00){
        return -1;
    }

    if((temp_buf[1] & 0x20) != 0x00){
        return -1;
    }

    if((temp_buf[0] & 0x02) != 0x02){
        return -1;
    }

    if((temp_buf[1] & 0x04) != 0x04){
        return -1;
    }

    if((temp_buf[1] & 0x02) != 0x02){
        return -1;
    }

    if((temp_buf[0] & 0x01) != 0x01){
        return -1;
    }

    if((temp_buf[1] & 0x10) != 0x00){
        return -1;
    }

    if((temp_buf[0] & 0x10) != 0x00){
        return -1;
    }

    if((temp_buf[1] & 0x08) != 0x08){
        return -1;
    }

    if((temp_buf[0] & 0x08) != 0x00){
        return -1;
    }

    if((temp_buf[0] & 0x04) != 0x00){
        return -1;
    }

    return 1;
}

/* The game progressing process for stage 1  */
void updateGame02(void)
{
  /* Data reading of controller 1  */
  nuContDataGetEx(contdata,0);

  if(contdata[0].trigger & U_CBUTTONS)
  {
      if(triPos_y < 255)
          triPos_y += 1;
  }

  if(contdata[0].trigger & D_CBUTTONS)
  {
      if(triPos_y > 0)
          triPos_y -= 1;
  }

  if(contdata[0].button & U_JPAD)
  {
      if(triPos_y < 255)
          triPos_y += 1;
  }

  if(contdata[0].button & D_JPAD)
  {
      if(triPos_y > 0)
          triPos_y -= 1;
  }

  if(contdata[0].trigger & R_CBUTTONS)
  {
      if(triPos_x < 255)
          triPos_x += 1;
  }

  if(contdata[0].trigger & L_CBUTTONS)
  {
      if(triPos_x > 0)
          triPos_x -= 1;
  }

  if(contdata[0].button & R_JPAD)
  {
      if(triPos_x < 255)
          triPos_x += 1;
  }

  if(contdata[0].button & L_JPAD)
  {
      if(triPos_x > 0)
          triPos_x -= 1;
  }

  if(contdata[0].trigger & R_TRIG)
  {
      temp_buf[0] = triPos_x;
      temp_buf[1] = triPos_y;

      if(proceduralOperation() == 1){
        screenDisplayForNFT();
      }
      else{
        while(1) {
          nuDebConTextPos(0,15,15);
          nuDebConCPuts(0, "INCORRECT");

          /* Display characters on the frame buffer */
          nuDebConDisp(NU_SC_SWAPBUFFER);
          nuDebConClear(0);
        }
      }
  }

  /* Convert to stage 0 when the start button is pushed  */
  if(contdata[0].trigger & START_BUTTON)
  {
    /* Remove the call-back function. */
    nuGfxFuncRemove();

    /* Specify next stage to main  */
    stage = 0;
    stageswitch = 1;
  }
}