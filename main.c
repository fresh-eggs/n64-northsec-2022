/*
   main.c

   NuSYSTEM sample nu2

   Copyright (C) 1997-1999, NINTENDO Co,Ltd.	
   */

#include <nusys.h>
#include "main.h"

/* The stage number  */
volatile int stage;
volatile int stageswitch = 1;
volatile int first_render = 1;


/* Declaration of the prototype  */
void stage00(int);
void stage01(int);
void stage02(int);
void stage03(int);

/* Declaration of the external function  */
void initStage00(void);
void makeDL00(void);
void updateGame00(void);

void initStage01(void);
void makeDL01(void);
void updateGame01(void);

void initStage02(void);
void makeDL02(void);
void updateGame02(void);

void initStage03(void);
void makeDL03(void);
void updateGame03(void);

NUContData	contdata[1]; /* Read data of 1 controller  */

/*------------------------
	Main 
--------------------------*/
void mainproc(void)
{
  /* The initialization of graphic  */
  nuGfxInit();

  /* The initialization of the controller manager  */
  nuContInit();
	
  /* Set the stage number to 0 */
  stage = 0;

  while(1)
  {
    	if(stageswitch)
    	{
		    	switch(stage)
					{
							/* 
							Register the corresponding call-back function according to the 
							stage number.  
							The call-back function sets the value to the stage when another 
							call-back function needs the register change.  
							*/
							case 0:
							  /* The initialization of stage 0  */
							  initStage00();
							  /* The call-back register  */
							  nuGfxFuncSet((NUGfxFunc)stage00);
							  /* Start to display  */
							  nuGfxDisplayOn();
							  stageswitch = 0;
							  first_render = 1;
							  break;
							case 1:
							  initStage01();
							  nuGfxFuncSet((NUGfxFunc)stage01);
							  nuGfxDisplayOn();
							  stageswitch = 0;
							  first_render = 1;
							  break;
							case 2:
							  initStage02();
							  nuGfxFuncSet((NUGfxFunc)stage02);
							  nuGfxDisplayOn();
							  stageswitch = 0;
							  first_render = 1;
							  break;
							case 3:
							  initStage03();
							  nuGfxFuncSet((NUGfxFunc)stage03);
							  nuGfxDisplayOn();
							  stageswitch = 0;
							  first_render = 1;
							  break;
							default:
							  break;
					}
    	}
  }
}


/*-----------------------------------------------------------------------------
  The call-back function 

  pendingGfx which is passed from Nusystem as the argument of the call-back   
  function is the total number of RCP tasks that are currently processing
  and waiting for the process. 
-----------------------------------------------------------------------------*/

/* Stage 0 */
void stage00(int pendingGfx)
{
  /* Provide the display process if 2 or less RCP tasks are processing or 
	 waiting for the process.  */
  if(pendingGfx < 3)
    makeDL00();		

  /* The process of game progress  */
  updateGame00(); 
}

/* Stage 1 */
void stage01(int pendingGfx)
{
  /* Provide the display process if 2 or less RCP tasks processing or 
	waiting for the process.   */
  if(pendingGfx < 3)
    makeDL01();

  /* The process of game progress  */
  updateGame01();
}

/* Stage 2 */
void stage02(int pendingGfx)
{
  /* Provide the display process if 2 or less RCP tasks processing or 
	waiting for the process.   */
  if(pendingGfx < 3)
    makeDL02();

  /* The process of game progress  */
  updateGame02();
}

/* Stage 3 */
void stage03(int pendingGfx)
{
  /* Provide the display process if 3 or less RCP tasks processing or 
	waiting for the process.   */
  if(pendingGfx < 3)
    makeDL03();

  /* The process of game progress  */
  updateGame03();
}