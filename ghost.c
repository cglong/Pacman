/*
 * Exported with BrandonTools v0.9
 * Invocation command was BrandonTools -mode4 -start=34 -resize=16,16 ghost ghost.png 
 * 
 * Image Information
 * -----------------
 * ghost.png 16@16
 * 
 * Quote/Fortune of the Day!
 * -------------------------
 * I plan on living forever.  So far, so good. ~Author Unknown
 * 
 * All bug reports / feature requests are to be sent to Brandon (brandon.whitehead@gatech.edu)
 */

const unsigned short ghost_palette[118] =
{
	0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,
	0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,
	0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,0x8000,
	0x8000,0x8000,0x8000,0x8000,0x0000,0x0001,0x0402,0x0404,0x0405,0x0406,
	0x14a6,0x0407,0x0807,0x0827,0x2108,0x0809,0x0829,0x294a,0x000b,0x040b,
	0x080b,0x080c,0x318c,0x4a50,0x1014,0x1435,0x6315,0x1416,0x1436,0x5ef6,
	0x1417,0x1437,0x5ed7,0x0c18,0x1418,0x3978,0x41d8,0x6318,0x1419,0x1439,
	0x3159,0x101a,0x141a,0x0c1b,0x101b,0x141b,0x181b,0x183b,0x185b,0x249b,
	0x397b,0x4a1b,0x101c,0x141c,0x181c,0x183c,0x1c5c,0x205c,0x207c,0x24bc,
	0x28bc,0x28dc,0x28fc,0x395c,0x101d,0x141d,0x181d,0x183d,0x249d,0x2cdd,
	0x353d,0x49fd,0x4a1d,0x4e3d,0x525d,0x5a9d,0x181e,0x28be,0x351e,0x77be,
	0x7ffe,0x5a9f,0x62ff,0x6f3f,0x737f,0x77bf,0x7bdf,0x7fff
};

const unsigned short ghost[128] =
{
	0x2222,0x2222,0x2222,0x543c,0x3c54,0x2222,0x2222,0x2222,0x2322,0x2b22,
	0x3c45,0x544c,0x4d54,0x443d,0x222a,0x2223,0x2222,0x3f31,0x615e,0x5454,
	0x5253,0x6152,0x3244,0x2222,0x3022,0x6f46,0x4a66,0x4954,0x695c,0x4e68,
	0x445f,0x2233,0x4122,0x7571,0x6573,0x6c56,0x7570,0x6774,0x6a4f,0x223c,
	0x3522,0x433b,0x7575,0x4262,0x3e38,0x7574,0x5e5d,0x2237,0x2426,0x2f22,
	0x6e75,0x316b,0x2822,0x7575,0x5e5d,0x253a,0x2e60,0x3422,0x6d75,0x336b,
	0x2c22,0x7575,0x4a64,0x5455,0x4755,0x6e51,0x5872,0x4755,0x6e50,0x5b74,
	0x5454,0x5454,0x5354,0x6358,0x5359,0x5354,0x6357,0x555a,0x5453,0x5454,
	0x4c54,0x4b4b,0x544b,0x5454,0x4b4b,0x544b,0x5454,0x5454,0x5454,0x4c4c,
	0x5454,0x4c4c,0x4c4c,0x5454,0x4c4c,0x5454,0x4c54,0x6054,0x544c,0x6060,
	0x6060,0x4c54,0x5460,0x544c,0x6054,0x3c40,0x5460,0x3639,0x3936,0x6054,
	0x403c,0x5460,0x484c,0x272d,0x4c48,0x2226,0x2622,0x484c,0x2d27,0x4c48,
	0x2960,0x2222,0x4c25,0x2226,0x2622,0x254c,0x2222,0x6029
};
