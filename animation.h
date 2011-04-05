#ifndef ANIMATION_H
#define ANIMATION_H

#include "myLib.h"

typedef struct {
	int frame;
	int maxFrames;
	int delay;
	int counter;
	u16 *images[];
} Animation;

#endif
