#ifndef MYLIB_H
#define MYLIB_H

#include "colors.h"
#include "dma.h"
#include "buttons.h"
#include "rect.h"

#define REG_DISPCNT *(unsigned short *)0x4000000
#define MODE3 3
#define MODE4 4
#define BG2_ENABLE (1<<10)

#define OFFSET(r, c, rowlen) ((r)*(rowlen)+(c))
#define SCREENWIDTH 240
#define SCREENHEIGHT 160

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef volatile unsigned int vu32;
extern unsigned short *videoBuffer;

void setPixel(int r, int c, u16 color);
void setPixel4(int r, int c, u8 index);
void drawRect(int r, int c, int width, int height, u16 color);
void drawRect4(int row, int col, int height, int width, u8 index);
void waitForVblank();
void drawImage3(int x, int y, int width, int height, const u16* image);
int rectCollides(Rect a, Rect b);

#endif
