/*
 * Exported with BrandonTools v0.9
 * Invocation command was BrandonTools -mode4 -start=2 Pacman Pacman1.png Pacman2.png Pacman3.png Pacman2.png Pacman1.png 
 * 
 * Image Information
 * -----------------
 * Pacman1.png 16@16
 * Pacman2.png 16@16
 * Pacman3.png 16@16
 * Pacman2.png 16@16
 * Pacman1.png 16@16
 * 
 * Quote/Fortune of the Day!
 * -------------------------
 * A compromise is an agreement whereby both parties get what neither of them wanted.  ~Author Unknown
 * 
 * All bug reports / feature requests are to be sent to Brandon (brandon.whitehead@gatech.edu)
 */

#ifndef PACMAN_BITMAP_H
#define PACMAN_BITMAP_H

#define PACMAN_PALETTE_SIZE 40
#define PACMAN_PALETTE_OFFSET 2

extern const unsigned short Pacman_palette[40];

extern const unsigned short Pacman1[128];
#define PACMAN1_WIDTH 16
#define PACMAN1_HEIGHT 16

extern const unsigned short Pacman2[128];
#define PACMAN2_WIDTH 16
#define PACMAN2_HEIGHT 16

extern const unsigned short Pacman3[128];
#define PACMAN3_WIDTH 16
#define PACMAN3_HEIGHT 16

extern const unsigned short Pacman2[128];
#define PACMAN2_WIDTH 16
#define PACMAN2_HEIGHT 16

extern const unsigned short Pacman1[128];
#define PACMAN1_WIDTH 16
#define PACMAN1_HEIGHT 16

#endif