#include <stdlib.h>
#include "myLib.h"
#include "pacman.h"
#include "dot.h"

#define NUMDOTS 5
#define NUMDELTAS 5

void initDot(int i);

DOT dots[NUMDOTS];
int deltas[] = {2, 3, 4, 5, 6};
int ghostFrequency = 64;

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
		drawRect(pacman.row, pacman.col, pacman.size, pacman.size, YELLOW);
		
		for (int i = 0; i < NUMDOTS; i++) {
			drawRect(oldDots[i].col, oldDots[i].row, oldDots[i].size, oldDots[i].size, BLACK);
			if (videoBuffer[OFFSET(dots[i].row, dots[i].col, SCREENWIDTH)] || dots[i].col<-dots[i].size)
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
	dots[i].col = SCREENWIDTH - 1;
	dots[i].del = deltas[rand() % NUMDELTAS];
}
