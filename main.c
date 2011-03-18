#include "myLib.h"
#include "pacman.h"

int main() {
	REG_DISPCNT = MODE3 | BG2_ENABLE;
	
	PACMAN pacman;
	pacman.size = 24;
	pacman.row = 0;
	pacman.col = SCREENHEIGHT/2-pacman.size;
	PACMAN oldPacman = pacman;
	
	while (1) {
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
