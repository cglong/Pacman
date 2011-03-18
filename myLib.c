#include "myLib.h"

unsigned short *videoBuffer = (unsigned short *)0x6000000;
volatile unsigned short *scanLineCounter = (unsigned short *)0x4000006;

void setPixel(int r, int c, u16 color) {
	videoBuffer[OFFSET(80, 120, SCREENWIDTH)] = color;
}

void drawRect(int x, int y, int width, int height, u16 color) {
	for (int i = 0; i < height; i++) {
		REG_DMA3SAD = (vu32) &color;
		REG_DMA3DAD = (vu32) &videoBuffer[(y+i)*240 + x];
		REG_DMA3CNT = width | DMA_ON | DMA_SOURCE_FIXED;
	}
}

void waitForVblank() {
	while(*scanLineCounter > 160);
	while(*scanLineCounter < 160);
}
