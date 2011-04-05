#include "myLib.h"

unsigned short *videoBuffer = (unsigned short *)0x6000000;
volatile unsigned short *scanLineCounter = (unsigned short *)0x4000006;

void setPixel(int r, int c, u16 color) {
	videoBuffer[OFFSET(r, c, SCREENWIDTH)] = color;
}

void setPixel4(int r, int c, u8 index) {
	u16 pixel = videoBuffer[(r * 240 + c) / 2];
	if (c & 1)
		pixel = (pixel & 0xFF) | (index << 8);
	else
		pixel = (pixel & 0xFF00) | index;
	videoBuffer[(r * 240 + c) / 2] = pixel;
}

void drawRect(int x, int y, int width, int height, u16 color) {
	for (int i = 0; i < height; i++) {
		REG_DMA3SAD = (vu32) &color;
		REG_DMA3DAD = (vu32) &videoBuffer[(y+i)*240 + x];
		REG_DMA3CNT = width | DMA_ON | DMA_SOURCE_FIXED;
	}
}

void drawRect4(int row, int col, int height, int width, u8 index) {
	int r;
	volatile u16 color = (index<<8) | index;
	if (width > 1)
		for (r=0; r < height; r++) {
			REG_DMA3SAD = &color;
			REG_DMA3DAD = videoBuffer + OFFSET(row+r, col, 240)/2;
			REG_DMA3CNT = width/2 | DMA_SOURCE_FIXED | DMA_ON;
		}
}

void waitForVblank() {
	while(*scanLineCounter > 160);
	while(*scanLineCounter < 160);
}

void drawImage3(int x, int y, int width, int height, const u16* image) {
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) {
			REG_DMA3SAD = (vu32) &image[width * (i-1) + (j+1)];
			REG_DMA3DAD = (vu32) &videoBuffer[OFFSET(i+x, y, SCREENWIDTH)];
			REG_DMA3CNT = width | DMA_ON;
		}
}

int rectCollides(Rect a, Rect b) {
	int aRight = a.col + a.width;
	int aBottom = a.row + a.height;
	int bRight = b.col + b.width;
	int bBottom = b.row + b.height;
	
	if ((aRight >= b.col && aRight <= bRight) || (a.col >= b.col && a.col <= bRight))
		if ((a.row >= b.row && a.row <= bBottom) || (aBottom >= b.row && aBottom <= bBottom))
			return 1;
	return 0;
}

void setPalette(const u16 *array, int size, int start) {
	PALETTE[0] = BLACK;
	PALETTE[1] = WHITE;
	
	for (int i = start; i < start + size; i++)
		PALETTE[i] = array[i];
}
