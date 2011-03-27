#include <stdlib.h>
#include "myLib.h"
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

Rect pacman, oldPacman;
DOT dots[NUMDOTS], oldDots[NUMDOTS];
int deltas[] = {2, 3, 4, 5};
int ghostFrequency;

int main() {
	REG_DISPCNT = MODE3 | BG2_ENABLE;
	drawTitle();
	initialize();
	clear();
	while (1) {
		update();
		waitForVblank();
		draw();
	}
}

void initialize() {
	DOT emptyDot;
	emptyDot.rect.row = 0;
	emptyDot.rect.col = 0;
	emptyDot.rect.height = 0;
	emptyDot.rect.width = 0;
	emptyDot.del = 0;
	emptyDot.isGhost = 0;
	
	for (int i = 0; i < NUMDOTS; i++)
		dots[i] = oldDots[i] = emptyDot;
	
	ghostFrequency = 32;
	
	// Make Pacman and his shadow
	pacman.height = pacman.width = 16;
	pacman.row = 0;
	pacman.col = (SCREENHEIGHT-pacman.height)/2;
	
	// Make dots
	for (int i = 0; i < NUMDOTS; i++) {
		initDot(i);
		drawDot(i);
	}
	
	oldPacman = pacman;
	for (int i = 0; i < NUMDOTS; i++)
		oldDots[i] = dots[i];
}

void clear() {
	drawRect(0, 0, SCREENWIDTH, SCREENHEIGHT, BLACK);
}

void update() {
	if (KEY_DOWN_NOW(BUTTON_SELECT))
			main();
	
	oldPacman = pacman;
	
	for (int i = 0; i < NUMDOTS; i++) {
		if (rectCollides(pacman, dots[i].rect) || dots[i].rect.col<=0) {
			if (dots[i].isGhost && dots[i].rect.col > 0)
				drawEnd();
			else
				initDot(i);
		}
		dots[i].rect.col -= dots[i].del;
	}
	
	// Move Pacman
	if (KEY_DOWN_NOW(BUTTON_DOWN) && pacman.col < SCREENHEIGHT - pacman.height)
		pacman.col++;
	if (KEY_DOWN_NOW(BUTTON_UP) && pacman.col > 0)
		pacman.col--;
	if (KEY_DOWN_NOW(BUTTON_LEFT) && pacman.row > 0)
		pacman.row--;
	if (KEY_DOWN_NOW(BUTTON_RIGHT) && pacman.row < SCREENWIDTH - pacman.width)
		pacman.row++;
}

void draw() {
	drawRect(oldPacman.row, oldPacman.col, oldPacman.width, oldPacman.height, BLACK);
	drawPacman(pacman.col, pacman.row);
	
	for (int i = 0; i < NUMDOTS; i++)
		drawRect(oldDots[i].rect.col, oldDots[i].rect.row, oldDots[i].rect.width, oldDots[i].rect.height, BLACK);
	
	for (int i = 0; i < NUMDOTS; i++) {
		drawDot(i);
		oldDots[i] = dots[i];
	}
}

void initDot(int i) {
	if ((rand() % ghostFrequency)) {
		dots[i].rect.width = dots[i].rect.height = 3;
		dots[i].isGhost = 0;
	} else {
		dots[i].rect.width = dots[i].rect.height = 16;
		dots[i].isGhost = 1;
		if (ghostFrequency > 2)
			ghostFrequency /= 2;
	}
	
	dots[i].rect.row = rand() % (SCREENHEIGHT-dots[i].rect.height);
	dots[i].rect.col = SCREENWIDTH - dots[i].rect.width;
	dots[i].del = deltas[rand() % NUMDELTAS];
}

void drawDot(int i) {
	if (dots[i].isGhost)
		drawGhost(dots[i].rect.row, dots[i].rect.col);
	else
		drawRect(dots[i].rect.col, dots[i].rect.row, dots[i].rect.width, dots[i].rect.height, WHITE);
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
