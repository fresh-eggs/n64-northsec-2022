#include <ultra64.h>
#include "red_mushroom.h"

static Gfx red_mushroom_C_dummy_aligner1[] = { gsSPEndDisplayList() };
unsigned short red_mushroom[] = {
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8085, 0x8085, 0x8085, 0x8085, 0xC109, 0xC109, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0xC109, 0xC109, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0xC109, 0xC109, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0xC109, 0xC109, 0xC109, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0xC109, 0xC109, 0xC109, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0xC109, 0xC109, 0xC109, 0xC109, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0xC109, 0xC109, 0xC109, 0xC109, 0xC109, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0xD5A7, 0xA3D7, 0xA3D7, 0xA3D7, 0xA3D7, 0xCCDD, 0xCCDD, 0xD5A7, 0x8085, 0x8085, 0xC109, 0xC109, 0xC109, 0xC109, 0xC109, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8085, 0x8085, 0xD5A7, 0xD5A7, 0xD5A7, 0xD5A7, 0xD5A7, 0xA3D7, 0xA3D7, 0xA3D7, 0xA3D7, 0xCCDD, 0xCCDD, 0xD5A7, 0xD5A7, 0xD5A7, 0xD5A7, 0xD5A7, 0xC109, 0xC109, 0xC109, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEE29, 0xEE29, 0xD5A7, 0xD5A7, 0xD5A7, 0xD5A7, 0xD5A7, 0xA3D7, 0xA3D7, 0xA3D7, 0xCCDD, 0xCCDD, 0xCCDD, 0xD5A7, 0xD5A7, 0xD5A7, 0xD5A7, 0xD5A7, 0xD5A7, 0xC109, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xEE29, 0xEE29, 0xEE29, 0xEE29, 0xD5A7, 0xA3D7, 0xA3D7, 0xA3D7, 0xA3D7, 0xCCDD, 0xCCDD, 0xD5A7, 0xD5A7, 0xD5A7, 0xD5A7, 0xEE29, 0xEE29, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8085, 0x8085, 0x8085, 0x8085, 0xC109, 0x0000, 0x0000, 0xEE29, 0xA3D7, 0xA3D7, 0xA3D7, 0xA3D7, 0xCCDD, 0xCCDD, 0xEE29, 0xEE29, 0xEE29, 0xEE29, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0xC109, 0xC109, 0x0000, 0xA3D7, 0xA3D7, 0xA3D7, 0xA3D7, 0xCCDD, 0xCCDD, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0xC109, 0xC109, 0x0000, 0xA3D7, 0xBCE1, 0xBCE1, 0xCCDD, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0xC109, 0xC109, 0xBCE1, 0xBCE1, 0xBCE1, 0xEE29, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0x8085, 0xCCDD, 0xCCDD, 0xD5A7, 0xD5A7, 0xEE29, 0xBCE1, 0xBCE1, 0xBCE1, 0xEE29, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x8085, 0x8085, 0x8085, 0xD5A7, 0xD5A7, 0xA3D7, 0xA3D7, 0xA3D7, 0xCCDD, 0xEE29, 0xEE29, 0x0000, 0x0000, 0xBCE1, 0xBCE1, 0xEE29, 0xEE29, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x8085, 0x8085, 0xD5A7, 0xD5A7, 0xD5A7, 0xA3D7, 0xA3D7, 0xA3D7, 0xCCDD, 0xCCDD, 0x0000, 0x0000, 0x0000, 0xBCE1, 0xBCE1, 0xBCE1, 0xEE29, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x8085, 0xEE29, 0xEE29, 0xEE29, 0xEE29, 0xEE29, 0xA3D7, 0xA3D7, 0xA3D7, 0xCCDD, 0x0000, 0x0000, 0x0000, 0xBCE1, 0xBCE1, 0xBCE1, 0xEE29, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xA3D7, 0xA3D7, 0xA3D7, 0xCCDD, 0x0000, 0x0000, 0x0000, 0xBCE1, 0xBCE1, 0xBCE1, 0xEE29, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xA3D7, 0xA3D7, 0xEE29, 0xEE29, 0x0000, 0x0000, 0xBCE1, 0xBCE1, 0xBCE1, 0xEE29, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xBCE1, 0xBCE1, 0xEE29, 0x0000, 0x0000, 0xBCE1, 0xBCE1, 0xBCE1, 0xEE29, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xBCE1, 0xBCE1, 0xEE29, 0xEE29, 0x0000, 0xBCE1, 0xBCE1, 0xBCE1, 0xEE29, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xBCE1, 0xBCE1, 0xEE29, 0x0000, 0xBCE1, 0xBCE1, 0xBCE1, 0xEE29, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xBCE1, 0xBCE1, 0xEE29, 0xEE29, 0xBCE1, 0xBCE1, 0xBCE1, 0xEE29, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xBCE1, 0xBCE1, 0xBCE1, 0xEE29, 0xBCE1, 0xBCE1, 0xBCE1, 0xEE29, 0xEE29, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xBCE1, 0xBCE1, 0xEE29, 0xEE29, 0xBCE1, 0xBCE1, 0xBCE1, 0xEE29, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
    0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xBCE1, 0xBCE1, 0xEE29, 0xEE29, 0xBCE1, 0xBCE1, 0xBCE1, 0xEE29, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
};