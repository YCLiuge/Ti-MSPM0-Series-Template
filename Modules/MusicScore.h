/*
Program MusicPlayer;
Author 0x91f aka Lzy;
}
*/
#ifndef __MUSICSCORE_H
#define __MUSICSCORE_H 	   
#include "MusicPlayer.h"
//MusicScore:
#define MT_Sakura 128
const struct MusicNote Sakura[] = {
	{M5,MT_Sakura},{M6,MT_Sakura},{M2,MT_Sakura/2},{M1,MT_Sakura/2},{M2,MT_Sakura/2},{M1,MT_Sakura/2},
	{M5,MT_Sakura},{M6,MT_Sakura},{M2,MT_Sakura/2},{M1,MT_Sakura/2},{M2,MT_Sakura/2},{M1,MT_Sakura/2},
	{M5,MT_Sakura},{M6,MT_Sakura},{M2,MT_Sakura/2},{M1,MT_Sakura/2},{M2,MT_Sakura/2},{M1,MT_Sakura/2},	//18
	{M4,MT_Sakura},{M3,MT_Sakura},{M4,MT_Sakura/4},{M3,MT_Sakura/4},{M2,MT_Sakura/2},{M1,MT_Sakura},
	{M5,MT_Sakura},{M6,MT_Sakura},{M2,MT_Sakura/2},{M1,MT_Sakura/2},{M2,MT_Sakura/2},{M1,MT_Sakura/2},
	{M5,MT_Sakura},{M6,MT_Sakura},{M2,MT_Sakura/2},{M1,MT_Sakura/2},{M2,MT_Sakura/2},{M1,MT_Sakura/2},	//36
	{M5,MT_Sakura},{M6,MT_Sakura},{H1,MT_Sakura},{H4,MT_Sakura},{H3,MT_Sakura/2},{H4,MT_Sakura/2},
	{H3,MT_Sakura/2},{H2,MT_Sakura/2},{H1,MT_Sakura},{M6,MT_Sakura},											//46
	{M5,MT_Sakura},{M6,MT_Sakura},{M2,MT_Sakura/2},{M1,MT_Sakura/2},{M2,MT_Sakura/2},{M1,MT_Sakura/2},
	{M5,MT_Sakura},{M6,MT_Sakura},{M2,MT_Sakura/2},{M1,MT_Sakura/2},{M2,MT_Sakura/2},{M1,MT_Sakura/2},
	{M5,MT_Sakura},{M6,MT_Sakura},{M2,MT_Sakura/2},{M1,MT_Sakura/2},{M2,MT_Sakura/2},{M1,MT_Sakura/2},
	{M4,MT_Sakura},{M3,MT_Sakura},{M4,MT_Sakura/4},{M3,MT_Sakura/4},{M2,MT_Sakura/2},{M1,MT_Sakura},
	{M2,MT_Sakura},{M1,MT_Sakura/2},{M2,MT_Sakura/2},{M4,MT_Sakura},{M2,MT_Sakura/2},{M4,MT_Sakura/2},
	{M6,MT_Sakura},{M5,MT_Sakura/2},{M6,MT_Sakura/2},{H1,MT_Sakura},{M6,MT_Sakura/2},{H1,MT_Sakura/2},
	{H4,MT_Sakura},{H3,MT_Sakura/2},{H4,MT_Sakura/4},{H3,MT_Sakura/4},{H2,MT_Sakura},{H1,MT_Sakura},
	{H2,MT_Sakura*2},{M2,MT_Sakura},{M4,MT_Sakura},																//91
	{M5,MT_Sakura},{M6,MT_Sakura},{M2,MT_Sakura/2},{M1,MT_Sakura/2},{M2,MT_Sakura/2},{M1,MT_Sakura/2},
	{M5,MT_Sakura},{M6,MT_Sakura},{M2,MT_Sakura/2},{M1,MT_Sakura/2},{M2,MT_Sakura/2},{M1,MT_Sakura/2},
	{M5,MT_Sakura},{M6,MT_Sakura},{M2,MT_Sakura/2},{M1,MT_Sakura/2},{M2,MT_Sakura/2},{M1,MT_Sakura/2},
	{M4,MT_Sakura},{M3,MT_Sakura},{M4,MT_Sakura/4},{M3,MT_Sakura/4},{M2,MT_Sakura/2},{M1,MT_Sakura},
	{M5,MT_Sakura},{M6,MT_Sakura},{M2,MT_Sakura/2},{M1,MT_Sakura/2},{M2,MT_Sakura/2},{M1,MT_Sakura/2},
	{M5,MT_Sakura},{M6,MT_Sakura},{M2,MT_Sakura/2},{M1,MT_Sakura/2},{M2,MT_Sakura/2},{M1,MT_Sakura/2},
	{M5,MT_Sakura},{M6,MT_Sakura},{H1,MT_Sakura},{H4,MT_Sakura},{H3,MT_Sakura/2},{H4,MT_Sakura/2},
	{H3,MT_Sakura/2},{H2,MT_Sakura/2},{H1,MT_Sakura},{M6,MT_Sakura},											//137
	{M5,MT_Sakura},{M6,MT_Sakura},{M2,MT_Sakura/2},{M1,MT_Sakura/2},{M2,MT_Sakura/2},{M1,MT_Sakura/2},
	{M5,MT_Sakura},{M6,MT_Sakura},{M2,MT_Sakura/2},{M1,MT_Sakura/2},{M2,MT_Sakura/2},{M1,MT_Sakura/2},
	{M5,MT_Sakura},{M6,MT_Sakura},{M2,MT_Sakura/2},{M1,MT_Sakura/2},{M2,MT_Sakura/2},{M1,MT_Sakura/2},
	{M4,MT_Sakura},{M3,MT_Sakura},{M4,MT_Sakura/4},{M3,MT_Sakura/4},{M2,MT_Sakura/2},{M1,MT_Sakura},
	{M5,MT_Sakura/2},{M4,MT_Sakura/2},{M6,MT_Sakura/2},{H1,MT_Sakura/2},{H2,MT_Sakura/2},{H1,MT_Sakura/2},
	{M6,MT_Sakura/2},{M5,MT_Sakura/2},{M2,MT_Sakura},{M4,MT_Sakura/2},{M5,MT_Sakura},{M6,MT_Sakura},		//173
	{M2,MT_Sakura},{M2,MT_Sakura/2},{M2,MT_Sakura/2},{0,MT_Sakura},{M1,MT_Sakura},{M2,MT_Sakura*2},{0,MT_Sakura*2},	//180
	{M2,MT_Sakura},{M2,MT_Sakura/2},{M2,MT_Sakura},{M1,MT_Sakura},{M2,MT_Sakura},{M4,MT_Sakura},
	{M4,MT_Sakura},{M5,MT_Sakura},{M2,MT_Sakura},{M2,MT_Sakura/2},{M2,MT_Sakura},{M1,MT_Sakura},
	{M2,MT_Sakura},{M1,MT_Sakura},{L6,MT_Sakura},{M1,MT_Sakura/2},{M2,MT_Sakura},{M2,MT_Sakura/2},
	{M2,MT_Sakura},{M1,MT_Sakura},{M2,MT_Sakura},{M4,MT_Sakura},{M4,MT_Sakura},{M5,MT_Sakura},					//204
	{M6,MT_Sakura*2},{M5,MT_Sakura},{M6,MT_Sakura/2},{M5,MT_Sakura/2},{M4,MT_Sakura*2},{M2,MT_Sakura*2},
	{M2,MT_Sakura},{M2,MT_Sakura/2},{M2,MT_Sakura},{M1,MT_Sakura},{M2,MT_Sakura},{M4,MT_Sakura},
	{M4,MT_Sakura},{M5,MT_Sakura},{M2,MT_Sakura},{M2,MT_Sakura/2},{M2,MT_Sakura},{M1,MT_Sakura},
	{M2,MT_Sakura},{M1,MT_Sakura},{M1,MT_Sakura},{L6,MT_Sakura/2},{M2,MT_Sakura},{M2,MT_Sakura/2},
	{M2,MT_Sakura},{M1,MT_Sakura},{M2,MT_Sakura},{M4,MT_Sakura},{M4,MT_Sakura},{M5,MT_Sakura},					
	{M6,MT_Sakura*2},{M5,MT_Sakura},{M6,MT_Sakura/2},{M5,MT_Sakura/2},{M4,MT_Sakura*2},{M2,MT_Sakura*2},//240
	{M4,MT_Sakura*2},{M3,MT_Sakura*2},{M2,MT_Sakura*2},{M1,MT_Sakura*2},									//244
	
	{1,MT_Sakura}
};	//MT_Sakura = 128, 244 notes

#define MT_MEG 200
const struct MusicNote MEGALOVANIA[] = {
	{L6,MT_MEG/4},{L6,MT_MEG/4},{M6,MT_MEG/2},{M3,MT_MEG/2},{M2_,MT_MEG/4},{0,MT_MEG/4},{M1_,MT_MEG/2},{M1,MT_MEG/2},{L6,MT_MEG/4},{M1,MT_MEG/4},{M2,MT_MEG/4},
	{L5,MT_MEG/4},{L5,MT_MEG/4},{L6,MT_MEG/2},{M3,MT_MEG/2},{M2_,MT_MEG/4},{0,MT_MEG/4},{M1_,MT_MEG/2},{M1,MT_MEG/2},{L6,MT_MEG/4},{M1,MT_MEG/4},{M2,MT_MEG/4},
	{L4_,MT_MEG/4},{L4,MT_MEG/4},{M6,MT_MEG/2},{M3,MT_MEG/2},{M2_,MT_MEG/4},{0,MT_MEG/4},{M1_,MT_MEG/2},{M1,MT_MEG/2},{L6,MT_MEG/4},{M1,MT_MEG/4},{M2,MT_MEG/4},	//33
	{L4,MT_MEG/4},{L4,MT_MEG/2},{M6,MT_MEG/2},{M3,MT_MEG/2},{M2_,MT_MEG/4},{0,MT_MEG/4},{M1_,MT_MEG/2},{M1,MT_MEG/2},{L6,MT_MEG/4},{M1,MT_MEG/4},{M2,MT_MEG/4},		//44
	{L6,MT_MEG/4},{L6,MT_MEG/4},{M6,MT_MEG/2},{M3,MT_MEG/2},{M2_,MT_MEG/4},{0,MT_MEG/4},{M1_,MT_MEG/2},{M1,MT_MEG/2},{L6,MT_MEG/4},{M1,MT_MEG/4},{M2,MT_MEG/4},
	{L4,MT_MEG/4},{L4,MT_MEG/4},{L6,MT_MEG/2},{M3,MT_MEG/2},{M2_,MT_MEG/4},{0,MT_MEG/4},{M1_,MT_MEG/2},{M1,MT_MEG/2},{L6,MT_MEG/4},{M1,MT_MEG/4},{M2,MT_MEG/4},
	{L4_,MT_MEG/4},{L4,MT_MEG/4},{M6,MT_MEG/2},{M3,MT_MEG/2},{M2_,MT_MEG/4},{0,MT_MEG/4},{M1_,MT_MEG/2},{M1,MT_MEG/2},{L6,MT_MEG/4},{M1,MT_MEG/4},{M2,MT_MEG/4},
	{L4,MT_MEG/4},{L4,MT_MEG/2},{M6,MT_MEG/2},{M3,MT_MEG/2},{M2_,MT_MEG/4},{0,MT_MEG/4},{M1_,MT_MEG/2},{M1,MT_MEG/2},{L6,MT_MEG/4},{M1,MT_MEG/4},{M2,MT_MEG/4},		//88
	{M6,MT_MEG/4},{M6,MT_MEG/2},{H6,MT_MEG/2},{H3,MT_MEG/2},{H2_,MT_MEG/4},{0,MT_MEG/4},{H1_,MT_MEG/2},{H1,MT_MEG/2},{M6,MT_MEG/4},{H1,MT_MEG/4},{H2,MT_MEG/4},
	{M6,MT_MEG/4},{M6,MT_MEG/2},{H6,MT_MEG/2},{H3,MT_MEG/2},{H2_,MT_MEG/4},{0,MT_MEG/4},{H1_,MT_MEG/2},{H1,MT_MEG/2},{M6,MT_MEG/4},{H1,MT_MEG/4},{H2,MT_MEG/4},
	{M4_,MT_MEG/4},{M4,MT_MEG/4},{H6,MT_MEG/2},{H3,MT_MEG/2},{H2_,MT_MEG/4},{0,MT_MEG/4},{H1_,MT_MEG/2},{H1,MT_MEG/2},{M6,MT_MEG/4},{H1,MT_MEG/4},{H2,MT_MEG/4},
	{M4,MT_MEG/4},{M4,MT_MEG/2},{H6,MT_MEG/2},{H3,MT_MEG/2},{H2_,MT_MEG/4},{0,MT_MEG/4},{H1_,MT_MEG/2},{H1,MT_MEG/2},{M6,MT_MEG/4},{H1,MT_MEG/4},{H2,MT_MEG/4},		//132
	{H1,MT_MEG/2},{H1,MT_MEG/4},{H1,MT_MEG/4},{0,MT_MEG/4},{H1,MT_MEG/2},{H1,MT_MEG/4},{M6,MT_MEG/2},{M6,MT_MEG/2},																								//140
	{H1,MT_MEG/2},{H1,MT_MEG/4},{H1,MT_MEG/4},{0,MT_MEG/4},{H2,MT_MEG/2},{H2_,MT_MEG/2},{H2,MT_MEG/8},{H1,MT_MEG/4},{M6,MT_MEG/4},{H1,MT_MEG/4},{H2,MT_MEG/4},{0,MT_MEG/2},	//152
	{H1,MT_MEG/2},{H1,MT_MEG/4},{H1,MT_MEG/4},{0,MT_MEG/4},{H2,MT_MEG/2},{H2_,MT_MEG/4},{0,MT_MEG/4},{H3,MT_MEG/2},{H5,MT_MEG/2},{H3,MT_MEG/2},	//162
	{H6,MT_MEG/2},{H6,MT_MEG/2},{H6,MT_MEG/4},{H3,MT_MEG/4},{H6,MT_MEG/4},{H5,MT_MEG/4},{H5,MT_MEG},{HH2,MT_MEG},																//170
	{H3,MT_MEG/2},{H3,MT_MEG/4},{H3,MT_MEG/4},{0,MT_MEG/4},{H3,MT_MEG/2},{H3,MT_MEG/2},{H2,MT_MEG/2},{H2,MT_MEG/4},{H2,MT_MEG},									//179
	{H3,MT_MEG/2},{H3,MT_MEG/4},{H3,MT_MEG/4},{0,MT_MEG/4},{H3,MT_MEG/2},{H2,MT_MEG/4},{0,MT_MEG/4},{H3,MT_MEG/2},{H6,MT_MEG/4},{0,MT_MEG/4},{H3,MT_MEG/4},{H2,MT_MEG/2},
	{H6,MT_MEG/2},{H3,MT_MEG/2},{H2,MT_MEG/2},{H1,MT_MEG/2},{H5,MT_MEG/2},{H2,MT_MEG/2},{H1,MT_MEG/2},{M7,MT_MEG/2},														//199
	{M4,MT_MEG/2},{M5,MT_MEG/4},{M6,MT_MEG/4},{0,MT_MEG/4},{H1,MT_MEG/2},{H5,MT_MEG/4},{H5,MT_MEG*2},																					//206
	{1,MT_MEG}
};

#define MT_KAMI 180
const struct MusicNote KAMI[] = {
	{M5,MT_KAMI},{M6,MT_KAMI},{H1,MT_KAMI},	//3
	{H2,MT_KAMI*3/4},{H2,MT_KAMI/8},{H1,MT_KAMI*3/4},{H1,MT_KAMI/8},{H2,MT_KAMI/2},{H3,MT_KAMI/2},{H3,MT_KAMI},	//10
	{H2,MT_KAMI*3/4},{H2,MT_KAMI/8},{H1,MT_KAMI*3/4},{H1,MT_KAMI/8},{H2,MT_KAMI/2},{H3,MT_KAMI/2},{H3,MT_KAMI/2},{H3,MT_KAMI/2},	//18
	{H5,MT_KAMI/2},{H3,MT_KAMI/8},{H4,MT_KAMI/4},{H3,MT_KAMI/4},{H2,MT_KAMI/2},{H1,MT_KAMI/2},{H3,MT_KAMI},{M3,MT_KAMI/4},{H3,MT_KAMI/4},{M1,MT_KAMI/2},	//28
	{H2,MT_KAMI*3/4},{H2,MT_KAMI/8},{H1,MT_KAMI*3/4},{H1,MT_KAMI/8},{H2,MT_KAMI/2},{H3,MT_KAMI/2},{H3,MT_KAMI},	//35
	{H2,MT_KAMI*3/4},{H2,MT_KAMI/8},{H1,MT_KAMI*3/4},{H1,MT_KAMI/8},{H2,MT_KAMI/2},{H3,MT_KAMI/2},{H3,MT_KAMI}, //42
	{H2,MT_KAMI*3/4},{H2,MT_KAMI/8},{H1,MT_KAMI*3/4},{H1,MT_KAMI/8},{H2,MT_KAMI/2},{H3,MT_KAMI/2},{H3,MT_KAMI/2},{H3,MT_KAMI/2},	//50
	{H2,MT_KAMI/2},{H3,MT_KAMI/4},{H2,MT_KAMI/4},{H1,MT_KAMI*3},
	{H3,MT_KAMI/2},	//55
	{M1,MT_KAMI/2},{M1,MT_KAMI/2},{L7,MT_KAMI/4},{M1,MT_KAMI},{M5,MT_KAMI/2},{M6,MT_KAMI/2},{M7,MT_KAMI/2},
	{H1,MT_KAMI*3/4},{H1,MT_KAMI/8},{M7,MT_KAMI*3/4},{M7,MT_KAMI/8},{M6,MT_KAMI/2},{M5,MT_KAMI/2},{M3,MT_KAMI/2},{M1,MT_KAMI/4},{M1,MT_KAMI/4},	//71
	{H2,MT_KAMI/2},{H1,MT_KAMI/2},{H2,MT_KAMI/2},{H3,MT_KAMI*3/2},{H1,MT_KAMI/8},
	{H2,MT_KAMI/2},{H1,MT_KAMI/4},{H2,MT_KAMI/2},{H1,MT_KAMI/4},{H3,MT_KAMI/2},{H2,MT_KAMI/2},{H1,MT_KAMI/2},{H2,MT_KAMI/2},
	{H3,MT_KAMI/2},{H5,MT_KAMI/2},{H6,MT_KAMI/2},{H2,MT_KAMI},{H5,MT_KAMI/2},{H6,MT_KAMI/2},{H7,MT_KAMI/2},	//91
	{H1,MT_KAMI*3/4},{M6,MT_KAMI/8},{H1,MT_KAMI*3/4},{M6,MT_KAMI/8},{H1,MT_KAMI/2},{H2,MT_KAMI/2},{H3,MT_KAMI/2},{H2,MT_KAMI/4},{H2,MT_KAMI/4},
	{H2,MT_KAMI/2},{H3,MT_KAMI/2},{H2,MT_KAMI/2},{H1,MT_KAMI},{M5,MT_KAMI/2},{M6,MT_KAMI/2},{H1,MT_KAMI},{M5,MT_KAMI/2},{M6,MT_KAMI/2},
	{H1,MT_KAMI},{M5,MT_KAMI/2},{M6,MT_KAMI/2},{M7,MT_KAMI/2},	//113
	
	{1,MT_KAMI}
};

#define MT_SkyWeakness 120
const struct MusicNote SkyWeakness[] = {
	{M5,MT_SkyWeakness / 2},{M5,MT_SkyWeakness / 2},
	{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness / 2},{M1,MT_SkyWeakness / 2},	//8
	{M2,MT_SkyWeakness},{M3,MT_SkyWeakness},{0,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M1,MT_SkyWeakness / 2},
	{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness / 2},{M1,MT_SkyWeakness / 2},	//19
	{M2,MT_SkyWeakness / 2},{M2,MT_SkyWeakness / 2},{M3,MT_SkyWeakness},{M1,MT_SkyWeakness},{M5,MT_SkyWeakness / 2},{M5,MT_SkyWeakness / 2},
	{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness / 2},{M1,MT_SkyWeakness / 2},	//31
	{M2,MT_SkyWeakness},{M3,MT_SkyWeakness},{0,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M1,MT_SkyWeakness / 2},
	{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness / 2},{M1,MT_SkyWeakness / 2},
	{M2,MT_SkyWeakness / 2},{M2,MT_SkyWeakness / 2},{M3,MT_SkyWeakness},{M1,MT_SkyWeakness},{M5,MT_SkyWeakness / 2},{M5,MT_SkyWeakness / 2},	//47
	{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness / 2},{M1,MT_SkyWeakness / 2},
	{M2,MT_SkyWeakness},{M3,MT_SkyWeakness},{0,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M1,MT_SkyWeakness / 2},
	{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness / 2},{M1,MT_SkyWeakness / 2},
	{M2,MT_SkyWeakness / 2},{M2,MT_SkyWeakness / 2},{M3,MT_SkyWeakness},{M1,MT_SkyWeakness},{M5,MT_SkyWeakness / 2},{M5,MT_SkyWeakness / 2},
	{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness / 2},{M1,MT_SkyWeakness / 2},	
	{M2,MT_SkyWeakness},{M3,MT_SkyWeakness},{0,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M1,MT_SkyWeakness / 2},
	{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness / 2},{M1,MT_SkyWeakness / 2},	
	{M2,MT_SkyWeakness},{M3,MT_SkyWeakness},{M5,MT_SkyWeakness},{L7,MT_SkyWeakness},{M1,MT_SkyWeakness * 4},	//92
	/*
	{M5,MT_SkyWeakness / 2},{M5,MT_SkyWeakness / 2},
	{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness / 2},{M1,MT_SkyWeakness / 2},	
	{M2,MT_SkyWeakness},{M3,MT_SkyWeakness},{0,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M1,MT_SkyWeakness / 2},
	{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness / 2},{M1,MT_SkyWeakness / 2},	
	{M2,MT_SkyWeakness / 2},{M2,MT_SkyWeakness / 2},{M3,MT_SkyWeakness},{M1,MT_SkyWeakness},{M5,MT_SkyWeakness / 2},{M5,MT_SkyWeakness / 2},
	{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness / 2},{M1,MT_SkyWeakness / 2},	
	{M2,MT_SkyWeakness},{M3,MT_SkyWeakness},{0,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M1,MT_SkyWeakness / 2},
	{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness / 2},{M1,MT_SkyWeakness / 2},
	{M2,MT_SkyWeakness / 2},{M2,MT_SkyWeakness / 2},{M3,MT_SkyWeakness},{M1,MT_SkyWeakness},{M5,MT_SkyWeakness / 2},{M5,MT_SkyWeakness / 2},	
	{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness / 2},{M1,MT_SkyWeakness / 2},
	{M2,MT_SkyWeakness},{M3,MT_SkyWeakness},{0,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M1,MT_SkyWeakness / 2},
	{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness / 2},{M1,MT_SkyWeakness / 2},
	{M2,MT_SkyWeakness / 2},{M2,MT_SkyWeakness / 2},{M3,MT_SkyWeakness},{M1,MT_SkyWeakness},{M5,MT_SkyWeakness / 2},{M5,MT_SkyWeakness / 2},
	{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness / 2},{M1,MT_SkyWeakness / 2},	
	{M2,MT_SkyWeakness},{M3,MT_SkyWeakness},{0,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M1,MT_SkyWeakness / 2},
	{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness},{M1,MT_SkyWeakness / 2},{M2,MT_SkyWeakness / 2},{M1,MT_SkyWeakness / 2},	
	{M2,MT_SkyWeakness},{M3,MT_SkyWeakness},{M5,MT_SkyWeakness},{L7,MT_SkyWeakness},{M1,MT_SkyWeakness * 4},	//184
	*/
	{1,MT_SkyWeakness}
};

#define MT_NightOfNights 180
const struct MusicNote NightOfNights[] = {
	{H2,MT_NightOfNights / 2},{H6,MT_NightOfNights / 2},{H5,MT_NightOfNights / 4},{H6,MT_NightOfNights / 2},{H3,MT_NightOfNights / 4},{0,MT_NightOfNights / 4},{H4,MT_NightOfNights / 2},{H6,MT_NightOfNights / 4},{H5,MT_NightOfNights / 4},{H4,MT_NightOfNights / 4},{H3,MT_NightOfNights / 4},{H2,MT_NightOfNights / 4},	//12
	{0,MT_NightOfNights / 4},{H2,MT_NightOfNights / 4},	{H6,MT_NightOfNights / 2},{H5,MT_NightOfNights / 4},{H6,MT_NightOfNights / 2},{H3,MT_NightOfNights / 4},{0,MT_NightOfNights / 4},{H4,MT_NightOfNights / 2},{H6,MT_NightOfNights / 4},{H1,MT_NightOfNights / 2},{H1_,MT_NightOfNights / 2},							//23
	{H2,MT_NightOfNights / 2},{H6,MT_NightOfNights / 2},{H5,MT_NightOfNights / 4},{H6,MT_NightOfNights / 2},{H3,MT_NightOfNights / 4},{0,MT_NightOfNights / 4},{H4,MT_NightOfNights / 2},{H6,MT_NightOfNights / 4},{H5,MT_NightOfNights / 4},{H4,MT_NightOfNights / 4},{H3,MT_NightOfNights / 4},{H2,MT_NightOfNights / 4},	
	{0,MT_NightOfNights / 4},{H2,MT_NightOfNights / 4},	{H6,MT_NightOfNights / 2},{H5,MT_NightOfNights / 4},{H6,MT_NightOfNights / 2},{H3,MT_NightOfNights / 4},{0,MT_NightOfNights / 4},{H4,MT_NightOfNights / 2},{H6,MT_NightOfNights / 4},{H1,MT_NightOfNights / 2},{H1_,MT_NightOfNights / 2},							//46
	{H2,MT_NightOfNights / 2},{H6,MT_NightOfNights / 2},{H5,MT_NightOfNights / 4},{H6,MT_NightOfNights / 2},{H3,MT_NightOfNights / 4},{0,MT_NightOfNights / 4},{H4,MT_NightOfNights / 2},{H6,MT_NightOfNights / 4},{H5,MT_NightOfNights / 4},{H4,MT_NightOfNights / 4},{H3,MT_NightOfNights / 4},{H2,MT_NightOfNights / 4},	
	{0,MT_NightOfNights / 4},{H2,MT_NightOfNights / 4},	{H6,MT_NightOfNights / 2},{H5,MT_NightOfNights / 4},{H6,MT_NightOfNights / 2},{H3,MT_NightOfNights / 4},{0,MT_NightOfNights / 4},{H4,MT_NightOfNights / 2},{H6,MT_NightOfNights / 4},{H1,MT_NightOfNights / 2},{H1_,MT_NightOfNights / 2},							//69
	{H2,MT_NightOfNights / 2},{H6,MT_NightOfNights / 2},{H5,MT_NightOfNights / 4},{H6,MT_NightOfNights / 2},{H3,MT_NightOfNights / 4},{0,MT_NightOfNights / 4},{H4,MT_NightOfNights / 2},{H6,MT_NightOfNights / 4},{H5,MT_NightOfNights / 4},{H4,MT_NightOfNights / 4},{H3,MT_NightOfNights / 4},{H2,MT_NightOfNights / 4},	//81
	{0,MT_NightOfNights / 4},{H2,MT_NightOfNights / 4},	{H6,MT_NightOfNights / 2},{H5,MT_NightOfNights / 4},{H6,MT_NightOfNights / 2},{HH1,MT_NightOfNights / 4},{0,MT_NightOfNights / 4},{HH1,MT_NightOfNights / 4},{H6,MT_NightOfNights / 4},{0,MT_NightOfNights / 4},{HH3,MT_NightOfNights / 4},{HH3,MT_NightOfNights / 4},{HH1,MT_NightOfNights / 4},{HH1_,MT_NightOfNights / 4},	//95	
	{1,MT_NightOfNights}
};

//FunkyStar:
//https://www.tan8.com/yuepu-83350.html
#define MT_FunkyStar 200
const struct MusicNote FunkyStar[] = {
	{L3,MT_FunkyStar / 2},{L5,MT_FunkyStar / 4},{L6,MT_FunkyStar / 4},{0,MT_FunkyStar / 2},{L3,MT_FunkyStar / 2},{L7,MT_FunkyStar / 2},{M1,MT_FunkyStar / 2},{L4,MT_FunkyStar / 2},	//8
	{0,MT_FunkyStar / 2},{L4,MT_FunkyStar / 2},{L4,MT_FunkyStar / 4},{L3,MT_FunkyStar / 4},{L1,MT_FunkyStar / 2},{L2,MT_FunkyStar / 2},{L3,MT_FunkyStar / 2},{L5,MT_FunkyStar / 4},{L6,MT_FunkyStar / 4},{0,MT_FunkyStar / 2}, //18
	{L6,MT_FunkyStar / 2},{M3,MT_FunkyStar / 2},{M5,MT_FunkyStar / 4},{M6,MT_FunkyStar / 4},{L6,MT_FunkyStar / 2},{M3,MT_FunkyStar / 2},{M7,MT_FunkyStar / 2},{H1,MT_FunkyStar / 2},{M4,MT_FunkyStar / 2},	//27
	{L6,MT_FunkyStar / 2},{M4,MT_FunkyStar / 2},{M4,MT_FunkyStar / 4},{M3,MT_FunkyStar / 4},{M1,MT_FunkyStar / 2},{M2,MT_FunkyStar / 2},{M3,MT_FunkyStar / 2},{M5,MT_FunkyStar / 4},{M6,MT_FunkyStar / 4},{L6,MT_FunkyStar / 2},//37
	{L6,MT_FunkyStar / 2},{M3,MT_FunkyStar / 2},{M5,MT_FunkyStar / 4},{M6,MT_FunkyStar / 4},{L6,MT_FunkyStar / 2},{M3,MT_FunkyStar / 2},{M7,MT_FunkyStar / 2},{H1,MT_FunkyStar / 2},{M4,MT_FunkyStar / 2},	//46
	{L6,MT_FunkyStar / 2},{M4,MT_FunkyStar / 2},{M4,MT_FunkyStar / 4},{M3,MT_FunkyStar / 4},{M1,MT_FunkyStar / 2},{M2,MT_FunkyStar / 2},{M3,MT_FunkyStar / 2},{M5,MT_FunkyStar / 4},{M6,MT_FunkyStar / 4},{L6,MT_FunkyStar / 2},//56
	{L6,MT_FunkyStar / 2},{M3,MT_FunkyStar / 2},{M5,MT_FunkyStar / 4},{M6,MT_FunkyStar / 4},{L6,MT_FunkyStar / 2},{M3,MT_FunkyStar / 2},{M7,MT_FunkyStar / 2},{H1,MT_FunkyStar / 2},{H2,MT_FunkyStar / 2},	//65
	{L6,MT_FunkyStar / 2},{M6,MT_FunkyStar / 2},{M7,MT_FunkyStar / 2},{M5,MT_FunkyStar / 2},{M2,MT_FunkyStar / 2},{M3,MT_FunkyStar / 2},{M5,MT_FunkyStar / 4},{M7,MT_FunkyStar / 4},{H1,MT_FunkyStar / 4},{M7,MT_FunkyStar / 4},//75
	{1,MT_FunkyStar}
};

#endif
