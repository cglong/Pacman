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

const unsigned short ghost_palette[126] =
{
	0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,
	0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,
	0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,
	0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,
	0x8000,0x8000,0x0000,0x0001,0x0402,0x0404,0x0405,0x0406,0x14a6,0x0407,
	0x0807,0x0827,0x2108,0x0809,0x0829,0x294a,0x000b,0x040b,0x080b,0x080c,
	0x318c,0x4a50,0x1014,0x1435,0x6315,0x1416,0x1436,0x5ef6,0x1417,0x1437,
	0x5ed7,0x0c18,0x1418,0x3978,0x41d8,0x6318,0x1419,0x1439,0x3159,0x101a,
	0x141a,0x0c1b,0x101b,0x141b,0x181b,0x183b,0x185b,0x249b,0x397b,0x4a1b,
	0x101c,0x141c,0x181c,0x183c,0x1c5c,0x205c,0x207c,0x24bc,0x28bc,0x28dc,
	0x28fc,0x395c,0x101d,0x141d,0x181d,0x183d,0x249d,0x2cdd,0x353d,0x49fd,
	0x4a1d,0x4e3d,0x525d,0x5a9d,0x181e,0x28be,0x351e,0x77be,0x7ffe,0x5a9f,
	0x62ff,0x6f3f,0x737f,0x77bf,0x7bdf,0x7fff
};

const unsigned short ghost[128] =
{
	0x2a2a,0x2a2a,0x2a2a,0x5c44,0x445c,0x2a2a,0x2a2a,0x2a2a,0x2b2a,0x332a,
	0x444d,0x5c54,0x555c,0x4c45,0x2a32,0x2a2b,0x2a2a,0x4739,0x6966,0x5c5c,
	0x5a5b,0x695a,0x3a4c,0x2a2a,0x382a,0x774e,0x526e,0x515c,0x7164,0x5670,
	0x4c67,0x2a3b,0x492a,0x7d79,0x6d7b,0x745e,0x7d78,0x6f7c,0x7257,0x2a44,
	0x3d2a,0x4b43,0x7d7d,0x4a6a,0x4640,0x7d7c,0x6665,0x2a3f,0x2c2e,0x372a,
	0x767d,0x3973,0x302a,0x7d7d,0x6665,0x2d42,0x3668,0x3c2a,0x757d,0x3b73,
	0x342a,0x7d7d,0x526c,0x5c5d,0x4f5d,0x7659,0x607a,0x4f5d,0x7658,0x637c,
	0x5c5c,0x5c5c,0x5b5c,0x6b60,0x5b61,0x5b5c,0x6b5f,0x5d62,0x5c5b,0x5c5c,
	0x545c,0x5353,0x5c53,0x5c5c,0x5353,0x5c53,0x5c5c,0x5c5c,0x5c5c,0x5454,
	0x5c5c,0x5454,0x5454,0x5c5c,0x5454,0x5c5c,0x545c,0x685c,0x5c54,0x6868,
	0x6868,0x545c,0x5c68,0x5c54,0x685c,0x4448,0x5c68,0x3e41,0x413e,0x685c,
	0x4844,0x5c68,0x5054,0x2f35,0x5450,0x2a2e,0x2e2a,0x5054,0x352f,0x5450,
	0x3168,0x2a2a,0x542d,0x2a2e,0x2e2a,0x2d54,0x2a2a,0x6831
};
