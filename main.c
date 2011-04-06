#include <stdlib.h>
#include <stdio.h>
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
void flipPage();

Rect pacman, oldPacman;
DOT dots[NUMDOTS], oldDots[NUMDOTS];
int deltas[] = {2, 3, 4, 5};
int ghostFrequency;
int score;
char string[41];

int main() {
	REG_DISPCNT = MODE4 | BG2_ENABLE;
	initialize();
	while (1) {
		waitForVblank();
		flipPage();
		clear();
		update();
		draw();
	}
}

void flipPage() {
	if (REG_DISPCNT & BUFFER1FLAG) {
		videoBuffer = BUFFER1;
		REG_DISPCNT &= ~BUFFER1FLAG;
	} else {
		videoBuffer = BUFFER0;
		REG_DISPCNT |= BUFFER1FLAG;
	}
}

void initialize() {
	drawTitle();
	setPalette(Pacman_palette, PACMAN_PALETTE_SIZE, PACMAN_PALETTE_OFFSET);
	setPalette(ghost_palette, PACMAN_PALETTE_SIZE, GHOST_PALETTE_OFFSET);
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
	score = 0;
	
	// Make Pacman and his shadow
	pacman.height = pacman.width = 16;
	pacman.row = (SCREENHEIGHT-pacman.height-TEXT_HEIGHT)/2;
	pacman.col = 0;
	
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
	oldPacman = pacman;
	drawRect4(oldPacman.col, oldPacman.row, oldPacman.width, oldPacman.height, BLACKINDEX);
	
	for (int i = 0; i < NUMDOTS; i++) {
		oldDots[i] = dots[i];
		drawRect4(oldDots[i].rect.col, oldDots[i].rect.row, oldDots[i].rect.width, oldDots[i].rect.height, BLACKINDEX);
	}
}

void update() {
	if (KEY_DOWN_NOW(BUTTON_SELECT))
			main();
	
	sprintf(string, "Score = %d", score);
	
	for (int i = 0; i < NUMDOTS; i++) {
		if (rectCollides(dots[i].rect, pacman) || dots[i].rect.col<=0) {
			if (dots[i].isGhost && dots[i].rect.col > 0)
				drawEnd();
			else {
				initDot(i);
				score++;
			}
		}
		dots[i].rect.col -= dots[i].del;
	}
	
	// Move Pacman
	if (KEY_DOWN_NOW(BUTTON_DOWN) && pacman.row < SCREENHEIGHT - pacman.height - TEXT_HEIGHT)
		pacman.row++;
	if (KEY_DOWN_NOW(BUTTON_UP) && pacman.row > 0)
		pacman.row--;
	if (KEY_DOWN_NOW(BUTTON_LEFT) && pacman.col > 0)
		pacman.col--;
	if (KEY_DOWN_NOW(BUTTON_RIGHT) && pacman.col < SCREENWIDTH - pacman.width)
		pacman.col++;
}

void draw() {
	drawPacman(pacman.row, pacman.col);
	drawString4(SCREENHEIGHT-TEXT_HEIGHT, 0, string, WHITEINDEX);
	
	for (int i = 0; i < NUMDOTS; i++)
		drawDot(i);
}

void initDot(int i) {
	if ((rand() % ghostFrequency)) {
		dots[i].rect.width = dots[i].rect.height = 4;
		dots[i].isGhost = 0;
	} else {
		dots[i].rect.width = dots[i].rect.height = 16;
		dots[i].isGhost = 1;
		if (ghostFrequency > 2)
			ghostFrequency /= 2;
	}
	
	dots[i].rect.row = rand() % (SCREENHEIGHT-dots[i].rect.height-TEXT_HEIGHT);
	dots[i].rect.col = SCREENWIDTH - dots[i].rect.width;
	dots[i].del = deltas[rand() % NUMDELTAS];
}

void drawDot(int i) {
	if (dots[i].isGhost)
		drawGhost(dots[i].rect.row, dots[i].rect.col);
	else
		drawRect4(dots[i].rect.col, dots[i].rect.row, dots[i].rect.width, dots[i].rect.height, WHITEINDEX);
}

void drawGhost(int x, int y) {
	drawImage4(x, y, GHOST_WIDTH, GHOST_HEIGHT, ghost);
}

void drawPacman(int x, int y) {
	drawImage4(x, y, PACMAN_WIDTH, PACMAN_HEIGHT, Pacman);
}

void drawTitle() {
	setPalette(title_palette, TITLE_PALETTE_SIZE, 0);
	drawImage4(0, 0, TITLE_WIDTH, TITLE_HEIGHT, title);
	while (!KEY_DOWN_NOW(BUTTON_START));
	drawRect4(0, 0, SCREENWIDTH, SCREENHEIGHT, BLACKINDEX);
}

void drawEnd() {
	setPalette(end_palette, END_PALETTE_SIZE, 0);
	drawImage4(0, 0, END_WIDTH, END_HEIGHT, end);
	while (!KEY_DOWN_NOW(BUTTON_START));
	main();
}
