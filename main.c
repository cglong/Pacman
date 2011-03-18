#include "myLib.h"
#include "pacman.h"

int main() {
	REG_DISPCNT = MODE3 | BG2_ENABLE;
	
	// Make Pacman and his shadow
	PACMAN pacman;
	pacman.size = 24;
	pacman.row = 0;
	pacman.col = (SCREENHEIGHT-pacman.size)/2;
	PACMAN oldPacman = pacman;
	
	// Make dots
	DOT dot;
	dot.row = SCREENHEIGHT/2;
	dot.col = SCREENWIDTH-1;
	dot.del = -3;
	setPixel(dot.row, dot.col, WHITE);
	
	while (1) {
		
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
		oldPacman = pacman;
	}
}
