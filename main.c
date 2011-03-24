#include <stdlib.h>
#include "myLib.h"
#include "pacman.h"
#include "dot.h"
#include "ghost.h"
#include "title.h"
#include "end.h"
#include "Pacman.h"

#define NUMDOTS 5
#define NUMDELTAS 4

void initialize();
void clear();
void update();
void draw();
void initDot(int i);
void drawDot(int i);
void drawGhost(int x, int y);
void drawTitle();
void drawEnd();
void drawPacman(int x, int y);

PACMAN pacman, oldPacman;
DOT dots[NUMDOTS], oldDots[NUMDOTS];
int deltas[] = {2, 3, 4, 5};
int ghostFrequency;

int main() {
	REG_DISPCNT = MODE3 | BG2_ENABLE;
	drawTitle();
	initialize();
	clear();
	
	oldPacman = pacman;
	for (int i = 0; i < NUMDOTS; i++)
		oldDots[i] = dots[i];
	
	while (1) {
		if (KEY_DOWN_NOW(BUTTON_SELECT))
			main();
		
		update();
		waitForVblank();
		draw();
		oldPacman = pacman;
	}
}

void initialize() {
	DOT emptyDot;
	emptyDot.row = 0;
	emptyDot.col = 0;
	emptyDot.del = 0;
	emptyDot.size = 0;
	emptyDot.isGhost = 0;
	
	for (int i = 0; i < NUMDOTS; i++)
		dots[i] = oldDots[i] = emptyDot;
	
	ghostFrequency = 32;
	
	// Make Pacman and his shadow
	pacman.size = 16;
	pacman.row = 0;
	pacman.col = (SCREENHEIGHT-pacman.size)/2;
	
	// Make dots
	for (int i = 0; i < NUMDOTS; i++) {
		initDot(i);
		drawDot(i);
	}
}

void clear() {
	drawRect(0, 0, SCREENWIDTH, SCREENHEIGHT, BLACK);
}

void update() {
	// Move dots
	for (int i = 0; i < NUMDOTS; i++)
		dots[i].col -= dots[i].del;
	
	// Move Pacman
	if (KEY_DOWN_NOW(BUTTON_DOWN) && pacman.col < SCREENHEIGHT - pacman.size)
		pacman.col++;
	if (KEY_DOWN_NOW(BUTTON_UP) && pacman.col > 0)
		pacman.col--;
	if (KEY_DOWN_NOW(BUTTON_LEFT) && pacman.row > 0)
		pacman.row--;
	if (KEY_DOWN_NOW(BUTTON_RIGHT) && pacman.row < SCREENWIDTH - pacman.size)
		pacman.row++;
}

void draw() {
	drawRect(oldPacman.row, oldPacman.col, oldPacman.size, oldPacman.size, BLACK);
	drawPacman(pacman.col, pacman.row);
	
	for (int i = 0; i < NUMDOTS; i++) {
		drawRect(oldDots[i].col, oldDots[i].row, oldDots[i].size, oldDots[i].size, BLACK);
		if (videoBuffer[OFFSET(dots[i].row, dots[i].col, SCREENWIDTH)] == YELLOW ||
			videoBuffer[OFFSET(dots[i].row+dots[i].size, dots[i].col, SCREENWIDTH)] == YELLOW ||
			videoBuffer[OFFSET(dots[i].row, dots[i].col+dots[i].size, SCREENWIDTH)] == YELLOW ||
			videoBuffer[OFFSET(dots[i].row+dots[i].size, dots[i].col+dots[i].size, SCREENWIDTH)] == YELLOW ||
			dots[i].col<=0) {
			if (dots[i].isGhost && dots[i].col > 0)
				drawEnd();
			else
				initDot(i);
		}
	}
	
	for (int i = 0; i < NUMDOTS; i++) {
		drawDot(i);
		oldDots[i] = dots[i];
	}
}

void initDot(int i) {
	if ((rand() % ghostFrequency)) {
		dots[i].size = 3;
		dots[i].isGhost = 0;
	} else {
		dots[i].size = 16;
		dots[i].isGhost = 1;
		if (ghostFrequency > 2)
			ghostFrequency /= 2;
	}
	
	dots[i].row = rand() % (SCREENHEIGHT-dots[i].size);
	dots[i].col = SCREENWIDTH - dots[i].size;
	dots[i].del = deltas[rand() % NUMDELTAS];
}

void drawDot(int i) {
	if (dots[i].isGhost)
		drawGhost(dots[i].row, dots[i].col);
	else
		drawRect(dots[i].col, dots[i].row, dots[i].size, dots[i].size, WHITE);
}

void drawGhost(int x, int y) {
	drawImage3(x, y, GHOST_WIDTH, GHOST_HEIGHT, ghost);
}

void drawPacman(int x, int y) {
	drawImage3(x, y, PACMAN_WIDTH, PACMAN_HEIGHT, Pacman);
}

void drawTitle() {
	drawImage3(0, 0, TITLE_WIDTH, TITLE_HEIGHT, title);
	while (!KEY_DOWN_NOW(BUTTON_START));
}

void drawEnd() {
	drawImage3(0, 0, END_WIDTH, END_HEIGHT, end);
	while (!KEY_DOWN_NOW(BUTTON_START));
	main();
}
