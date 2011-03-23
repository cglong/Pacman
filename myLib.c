#include "myLib.h"

unsigned short *videoBuffer = (unsigned short *)0x6000000;
volatile unsigned short *scanLineCounter = (unsigned short *)0x4000006;

void setPixel(int r, int c, u16 color) {
	videoBuffer[OFFSET(r, c, SCREENWIDTH)] = color;
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

void drawImage3(int x, int y, int width, int height, const u16* image) {
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) {
			REG_DMA3SAD = (vu32) &image[width * i + j];
			REG_DMA3DAD = (vu32) &videoBuffer[OFFSET(i+x, y, SCREENWIDTH)];
			REG_DMA3CNT = width | DMA_ON;
		}
}

int rectCollides(Rect a, Rect b) {
	if (a.col + a.width >= b.col && a.row + a.height >= b.row)
		return 1;
	else
		return 0;
}
