/*
 * Exported with BrandonTools v0.9
 * Invocation command was BrandonTools -mode4 -start=42 -resize=16,16 ghost ghost.png 
 * 
 * Image Information
 * -----------------
 * ghost.png 16@16
 * 
 * Quote/Fortune of the Day!
 * -------------------------
 * A compromise is an agreement whereby both parties get what neither of them wanted.  ~Author Unknown
 * 
 * All bug reports / feature requests are to be sent to Brandon (brandon.whitehead@gatech.edu)
 */

#ifndef GHOST_BITMAP_H
#define GHOST_BITMAP_H

extern const unsigned short ghost[128];
extern const unsigned short ghost_palette[126];
#define GHOST_WIDTH 16
#define GHOST_HEIGHT 16
#define GHOST_PALETTE_SIZE 126
#define GHOST_PALETTE_OFFSET 42

#endif