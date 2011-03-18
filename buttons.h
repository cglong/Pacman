#ifndef BUTTONS_H
#define BUTTONS_H

#define BUTTON_A      (1<<0)
#define BUTTON_B      (1<<1)
#define BUTTON_SELECT (1<<2)
#define BUTTON_START  (1<<3)
#define BUTTON_RIGHT  (1<<4)
#define BUTTON_LEFT   (1<<5)
#define BUTTON_UP     (1<<6)
#define BUTTON_DOWN   (1<<7)
#define BUTTON_R      (1<<8)
#define BUTTON_L      (1<<9)

#define BUTTON_INDEX_A      0
#define BUTTON_INDEX_B      1
#define BUTTON_INDEX_SELECT 2
#define BUTTON_INDEX_START  3
#define BUTTON_INDEX_RIGHT  4
#define BUTTON_INDEX_LEFT   5
#define BUTTON_INDEX_UP     6
#define BUTTON_INDEX_DOWN   7
#define BUTTON_INDEX_R      8
#define BUTTON_INDEX_L      9

#define BUTTONS (*( unsigned int *)0x04000130)

#define KEY_DOWN_NOW(key)  (~(BUTTONS) & key)

#endif
