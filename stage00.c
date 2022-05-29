#include <assert.h>
#include <nusys.h>
#include <stdlib.h>
#include "main.h"
#include "graphic.h"
#include "red_mushroom.h"

static float triPos_x; /* The display position, X */
static float triPos_y; /* The display position, Y */
static int x; // x position of our sprite
static int y; // y position of our sprite
static int b;
static int count;

void shadetri(Dynamic* dynamicp);

/* The initialization of stage 0  */
void initStage00(void)
{
  x = 0;
  y = 32;
  b = 255;
  triPos_x = 0.0;
  triPos_y = 0.0;
  srand(0xFF1E);
}

void DrawSpriteRed(int x, int y)
{
    gDPLoadTextureBlock(glistp++, 
        red_mushroom, 
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

void ClearBackground(u8 r, u8 g, u8 b)
{
    gDPPipeSync(glistp++);
    gDPSetCycleType(glistp++, G_CYC_FILL);
    gDPSetDepthImage(glistp++, nuGfxZBuffer);
    gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WD, nuGfxZBuffer);
    gDPSetFillColor(glistp++, (GPACK_ZDZ(G_MAXFBZ, 0) << 16 | GPACK_ZDZ(G_MAXFBZ, 0)));
    gDPFillRectangle(glistp++, 0, 0, SCREEN_WD - 1, SCREEN_HT - 1);
    gDPPipeSync(glistp++);
    gDPSetCycleType(glistp++, G_CYC_FILL);
    gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WD, nuGfxCfb_ptr);
    gDPSetFillColor(glistp++, (GPACK_RGBA5551(r, g, b, 1) << 16 | GPACK_RGBA5551(r, g, b, 1)));
    gDPFillRectangle(glistp++, 0, 0, SCREEN_WD - 1, SCREEN_HT - 1);
    gDPPipeSync(glistp++);
}

/* Make the display list and activate the task  */
void makeDL00(void)
{
  int i, q;
  char conbuf[32];
  Dynamic* dynamicp;

  /* Specify the display list buffer */
  dynamicp = &gfx_dynamic[gfx_gtask_no];
  glistp = &gfx_glist[gfx_gtask_no][0];

  // clear debug consonle text
  nuDebConClear(0);

  /*  The initialization of RCP  */
  gfxRCPInit();

  /* Clear the frame and Z-buffer  */
  //gfxClearCfb();

  //RCPInit(glistp);
  ClearBackground(0, 0, 0);

  // Init DSP
  gDPSetCycleType(glistp++, G_CYC_1CYCLE);
  gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
  gDPSetRenderMode(glistp++, G_RM_AA_ZB_TEX_EDGE, G_RM_AA_ZB_TEX_EDGE);
  gDPSetDepthSource(glistp++, G_ZS_PRIM);
  gDPSetPrimDepth(glistp++, 0, 0);
  gDPSetTexturePersp(glistp++, G_TP_NONE);

  // draw mushroom sprites like a smooth brain
  DrawSpriteRed(20,228);
  DrawSpriteRed(32,221);
  DrawSpriteRed(50,227);
  DrawSpriteRed(70,211);
  DrawSpriteRed(70,230);
  DrawSpriteRed(90,224);
  DrawSpriteRed(110,224);
  DrawSpriteRed(115,228);
  DrawSpriteRed(120,223);
  DrawSpriteRed(127,213);
  DrawSpriteRed(128,221);
  DrawSpriteRed(141,218);
  DrawSpriteRed(151,228);
  DrawSpriteRed(170,215);
  DrawSpriteRed(170,235);
  DrawSpriteRed(192,221);
  DrawSpriteRed(210,228);
  DrawSpriteRed(233,219);
  DrawSpriteRed(241,224);
  DrawSpriteRed(245,219);
  DrawSpriteRed(272,230);
  DrawSpriteRed(290,233);

  gDPFullSync(glistp++);
  gSPEndDisplayList(glistp++);
  nuGfxTaskStart(&gfx_glist[gfx_gtask_no][0],
     (s32)(glistp - gfx_glist[gfx_gtask_no]) * sizeof (Gfx),
     NU_GFX_UCODE_F3DEX , NU_SC_NOSWAPBUFFER);

  gfx_gtask_no ^= 1;

  nuDebConTextPos(0,11,15);
  nuDebConCPuts(0, "START: Change Stage");

  nuDebConTextPos(0,11,13);
  nuDebConCPuts(0, "Legend of Shiitakoin.");

  nuDebConDisp(NU_SC_SWAPBUFFER);
}


/* The game progressing process for stage 0  */
void updateGame00(void)
{  
  /* Data reading of controller 1  */
  nuContDataGetEx(contdata,0);

  /* Convert to stage 1 when the start button is pushed  */
  if(contdata[0].trigger & START_BUTTON){
    /* Remove the call-back function.  */
    nuGfxFuncRemove();

    /* Specify next stage to main  */
    stage = 1;
    stageswitch = 1;
  }
}

/* The vertex coordinate */
static Vtx shade_vtx[] =  {
        {        -64,  64, -5, 0, 0, 0, 0, 0xff, 0, 0xff  },
        {         64,  64, -5, 0, 0, 0, 0, 0, 0, 0xff },
        {         64, -64, -5, 0, 0, 0, 0, 0, 0xff, 0xff  },
        {        -64, -64, -5, 0, 0, 0, 0xff, 0, 0, 0xff  },
};

/* Draw a square */
void shadetri(Dynamic* dynamicp)
{
  gSPMatrix(glistp++,OS_K0_TO_PHYSICAL(&(dynamicp->projection)),
    G_MTX_PROJECTION|G_MTX_LOAD|G_MTX_NOPUSH);
  gSPMatrix(glistp++,OS_K0_TO_PHYSICAL(&(dynamicp->translate)),
    G_MTX_MODELVIEW|G_MTX_LOAD|G_MTX_NOPUSH);
  gSPMatrix(glistp++,OS_K0_TO_PHYSICAL(&(dynamicp->modeling)),
    G_MTX_MODELVIEW|G_MTX_MUL|G_MTX_NOPUSH);

  gSPVertex(glistp++,&(shade_vtx[0]),4, 0);

  gDPPipeSync(glistp++);
  gDPSetCycleType(glistp++,G_CYC_1CYCLE);
  gDPSetRenderMode(glistp++,G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
  gSPClearGeometryMode(glistp++,0xFFFFFFFF);
  gSPSetGeometryMode(glistp++,G_SHADE| G_SHADING_SMOOTH);

  gSP2Triangles(glistp++,0,1,2,0,0,2,3,0);
}