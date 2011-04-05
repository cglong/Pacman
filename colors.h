#ifndef COLORS_H
#define COLORS_H

#define RGB(r, g, b) ((r) | (g)<<5 | (b)<<10)

#define WHITE RGB(31,31,31)
#define BLACK 0

#define RED RGB(31,0,0)
#define GREEN RGB(0,31,0)
#define BLUE RGB(0,0,31)

#define YELLOW RGB(31,31,0)

enum {BLACKINDEX, WHITEINDEX};

#endif
