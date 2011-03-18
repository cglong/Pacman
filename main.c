#include <stdlib.h>
#include "myLib.h"
#include "pacman.h"
#include "dot.h"
#include "Pacman.h"

#define NUMDOTS 5
#define NUMDELTAS 4

void initDot(int i);
void drawPacman(int x, int y);

DOT dots[NUMDOTS];
int deltas[] = {2, 3, 4, 5};
int ghostFrequency = 32;

int main() {
	REG_DISPCNT = MODE3 | BG2_ENABLE;
	
	// Make Pacman and his shadow
	PACMAN pacman;
	pacman.size = 16;
	pacman.row = 0;
	pacman.col = (SCREENHEIGHT-pacman.size)/2;
	PACMAN oldPacman = pacman;
	
	// Make dots
	DOT oldDots[NUMDOTS];
	for (int i = 0; i < NUMDOTS; i++) {
		initDot(i);
		drawRect(dots[i].col, dots[i].row, dots[i].size, dots[i].size, WHITE);
		oldDots[i] = dots[i];
	}
	
	while (1) {
		// Move dots
		for (int i = 0; i < NUMDOTS; i++)
			dots[i].col -= dots[i].del;
		
		// Move Pacman
		if (KEY_DOWN_NOW(BUTTON_DOWN))
			pacman.col++;
		if (KEY_DOWN_NOW(BUTTON_UP))
			pacman.col--;
		if (KEY_DOWN_NOW(BUTTON_LEFT))
			pacman.row--;
		if (KEY_DOWN_NOW(BUTTON_RIGHT))
			pacman.row++;
		
		waitForVblank();
		
		drawRect(oldPacman.row, oldPacman.col, oldPacman.size, oldPacman.size, BLACK);
		//drawRect(pacman.row, pacman.col, pacman.size, pacman.size, YELLOW);
		drawPacman(pacman.col, pacman.row);
		
		for (int i = 0; i < NUMDOTS; i++) {
			drawRect(oldDots[i].col, oldDots[i].row, oldDots[i].size, oldDots[i].size, BLACK);
			if (videoBuffer[OFFSET(dots[i].row, dots[i].col, SCREENWIDTH)] || dots[i].col<=0)
				initDot(i);
		}
		
		for (int i = 0; i < NUMDOTS; i++) {
			drawRect(dots[i].col, dots[i].row, dots[i].size, dots[i].size, WHITE);
			oldDots[i] = dots[i];
		}
		
		oldPacman = pacman;
	}
}

void initDot(int i) {
	if ((rand() % ghostFrequency))
		dots[i].size = 3;
	else {
		dots[i].size = 16;
		if (ghostFrequency > 2)
			ghostFrequency /= 2;
	}
	
	dots[i].row = rand() % (SCREENHEIGHT-dots[i].size);
	dots[i].col = SCREENWIDTH - dots[i].size;
	dots[i].del = deltas[rand() % NUMDELTAS];
}

void drawPacman(int x, int y) {
	for (int i = 0; i < PACMAN_HEIGHT; i++)
		for (int j = 0; j < PACMAN_WIDTH; j++) {
			REG_DMA3SAD = (vu32) &Pacman[PACMAN_WIDTH * i + j];
			REG_DMA3DAD = (vu32) &videoBuffer[OFFSET(i+x, y, SCREENWIDTH)];
			REG_DMA3CNT = PACMAN_WIDTH | DMA_ON;
		}
}
