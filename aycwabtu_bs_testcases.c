/* CSA brute force bitslice test cases */

#include "aycwabtu_config.h"
#include <stdio.h>

/*unsigned char pusi_key[] = {0x64 ,0x01 ,0x57 ,0xBC ,0x16 ,0xA6 ,0xF9 ,0xB5};*/
/* this pusi_fakekey01 provides also  0x00 0x00 0x01 in clear packet !! */
/*unsigned char pusi_fakekey01[] = {0x54 ,0x01 ,0x58 ,0xAD ,0x31 ,0xDF ,0xAD ,0xBD};*/

/* payload from pusi_crypted */
unsigned char bs_tc_crypteddata[16] = {
   0x8C ,0xD7 ,0x35 ,0x89  ,0x6D ,0xA4 ,0xDC ,0x4B     ,0x2C ,0xE3 ,0x02 ,0x33,   0xE7 ,0x0B ,0x3A ,0x98};
   /*0x8C ,0xD7 ,0x35 ,0x89  ,0x6D ,0xA4 ,0xDC ,0x4B     ,0x2C ,0xE3 ,0x03 ,0x33,   0xFF ,0xFF ,0xFF ,0xFF};*/
/* 2nd block doesnt pass the block alg -> changed bit does not affect all 64 block bits, so it could be calculated into */

/* 64 bit csa key including checksum. 128 times to test SSE2 */
const unsigned char bs_tc_keys[32*4][8] = {
/* 0 */
   {0x64, 0x01, 0x57, 0xBC,  0x16, 0xA6, 0xF9, 0xB5},
   {0x64, 0x01, 0x57, 0xBC,  0x17, 0xA6, 0xF9, 0xB6},
   {0x64, 0x01, 0x57, 0xBC,  0x18, 0xA6, 0xF9, 0xB7},
   {0x64, 0x01, 0x57, 0xBC,  0x19, 0xA6, 0xF9, 0xB8},
   {0x64, 0x01, 0x57, 0xBC,  0x1A, 0xA6, 0xF9, 0xB9},
   {0x64, 0x01, 0x57, 0xBC,  0x1B, 0xA6, 0xF9, 0xBA},
   {0x64, 0x01, 0x57, 0xBC,  0x1C, 0xA6, 0xF9, 0xBB},
   {0x64, 0x01, 0x57, 0xBC,  0x1D, 0xA6, 0xF9, 0xBC},
   {0x64, 0x01, 0x57, 0xBC,  0x1E, 0xA6, 0xF9, 0xBD},
   {0x64, 0x01, 0x57, 0xBC,  0x1F, 0xA6, 0xF9, 0xBE},
   {0x64, 0x01, 0x57, 0xBC,  0x20, 0xA6, 0xF9, 0xBF},
   {0x64, 0x01, 0x57, 0xBC,  0x21, 0xA6, 0xF9, 0xC0},
   {0x64, 0x01, 0x57, 0xBC,  0x22, 0xA6, 0xF9, 0xC1},
   {0x64, 0x01, 0x57, 0xBC,  0x23, 0xA6, 0xF9, 0xC2},
   {0x64, 0x01, 0x57, 0xBC,  0x24, 0xA6, 0xF9, 0xC3},
   {0x64, 0x01, 0x57, 0xBC,  0x25, 0xA6, 0xF9, 0xC4},
   {0x64, 0x01, 0x57, 0xBC,  0x26, 0xA6, 0xF9, 0xC5},
   {0x64, 0x01, 0x57, 0xBC,  0x27, 0xA6, 0xF9, 0xC6},
   {0x64, 0x01, 0x57, 0xBC,  0x28, 0xA6, 0xF9, 0xC7},
   {0x64, 0x01, 0x57, 0xBC,  0x29, 0xA6, 0xF9, 0xC8},
   {0x64, 0x01, 0x57, 0xBC,  0x2A, 0xA6, 0xF9, 0xC9},
   {0x64, 0x01, 0x57, 0xBC,  0x2B, 0xA6, 0xF9, 0xCA},
   {0x64, 0x01, 0x57, 0xBC,  0x2C, 0xA6, 0xF9, 0xCB},
   {0x64, 0x01, 0x57, 0xBC,  0x2D, 0xA6, 0xF9, 0xCC},
   {0x64, 0x01, 0x57, 0xBC,  0x2E, 0xA6, 0xF9, 0xCD},
   {0x64, 0x01, 0x57, 0xBC,  0x2F, 0xA6, 0xF9, 0xCE},
   {0x64, 0x01, 0x57, 0xBC,  0x30, 0xA6, 0xF9, 0xCF},
   {0x64, 0x01, 0x57, 0xBC,  0x31, 0xA6, 0xF9, 0xD0},
   {0x64, 0x01, 0x57, 0xBC,  0x32, 0xA6, 0xF9, 0xD1},
   {0x64, 0x01, 0x57, 0xBC,  0x33, 0xA6, 0xF9, 0xD2},
   {0x64, 0x01, 0x57, 0xBC,  0x34, 0xA6, 0xF9, 0xD3},
   {0x64, 0x01, 0x57, 0xBC,  0x35, 0xA6, 0xF9, 0xD4},
/* 1 */
   {0x64, 0x01, 0x57, 0xBC,  0x16, 0xA6, 0xF9, 0xB5},
   {0x64, 0x01, 0x57, 0xBC,  0x17, 0xA6, 0xF9, 0xB6},
   {0x64, 0x01, 0x57, 0xBC,  0x18, 0xA6, 0xF9, 0xB7},
   {0x64, 0x01, 0x57, 0xBC,  0x19, 0xA6, 0xF9, 0xB8},
   {0x64, 0x01, 0x57, 0xBC,  0x1A, 0xA6, 0xF9, 0xB9},
   {0x64, 0x01, 0x57, 0xBC,  0x1B, 0xA6, 0xF9, 0xBA},
   {0x64, 0x01, 0x57, 0xBC,  0x1C, 0xA6, 0xF9, 0xBB},
   {0x64, 0x01, 0x57, 0xBC,  0x1D, 0xA6, 0xF9, 0xBC},
   {0x64, 0x01, 0x57, 0xBC,  0x1E, 0xA6, 0xF9, 0xBD},
   {0x64, 0x01, 0x57, 0xBC,  0x1F, 0xA6, 0xF9, 0xBE},
   {0x64, 0x01, 0x57, 0xBC,  0x20, 0xA6, 0xF9, 0xBF},
   {0x64, 0x01, 0x57, 0xBC,  0x21, 0xA6, 0xF9, 0xC0},
   {0x64, 0x01, 0x57, 0xBC,  0x22, 0xA6, 0xF9, 0xC1},
   {0x64, 0x01, 0x57, 0xBC,  0x23, 0xA6, 0xF9, 0xC2},
   {0x64, 0x01, 0x57, 0xBC,  0x24, 0xA6, 0xF9, 0xC3},
   {0x64, 0x01, 0x57, 0xBC,  0x25, 0xA6, 0xF9, 0xC4},
   {0x64, 0x01, 0x57, 0xBC,  0x26, 0xA6, 0xF9, 0xC5},
   {0x64, 0x01, 0x57, 0xBC,  0x27, 0xA6, 0xF9, 0xC6},
   {0x64, 0x01, 0x57, 0xBC,  0x28, 0xA6, 0xF9, 0xC7},
   {0x64, 0x01, 0x57, 0xBC,  0x29, 0xA6, 0xF9, 0xC8},
   {0x64, 0x01, 0x57, 0xBC,  0x2A, 0xA6, 0xF9, 0xC9},
   {0x64, 0x01, 0x57, 0xBC,  0x2B, 0xA6, 0xF9, 0xCA},
   {0x64, 0x01, 0x57, 0xBC,  0x2C, 0xA6, 0xF9, 0xCB},
   {0x64, 0x01, 0x57, 0xBC,  0x2D, 0xA6, 0xF9, 0xCC},
   {0x64, 0x01, 0x57, 0xBC,  0x2E, 0xA6, 0xF9, 0xCD},
   {0x64, 0x01, 0x57, 0xBC,  0x2F, 0xA6, 0xF9, 0xCE},
   {0x64, 0x01, 0x57, 0xBC,  0x30, 0xA6, 0xF9, 0xCF},
   {0x64, 0x01, 0x57, 0xBC,  0x31, 0xA6, 0xF9, 0xD0},
   {0x64, 0x01, 0x57, 0xBC,  0x32, 0xA6, 0xF9, 0xD1},
   {0x64, 0x01, 0x57, 0xBC,  0x33, 0xA6, 0xF9, 0xD2},
   {0x64, 0x01, 0x57, 0xBC,  0x34, 0xA6, 0xF9, 0xD3},
   {0x64, 0x01, 0x57, 0xBC,  0x35, 0xA6, 0xF9, 0xD4},
/* 2 */
   {0x64, 0x01, 0x57, 0xBC,  0x16, 0xA6, 0xF9, 0xB5},
   {0x64, 0x01, 0x57, 0xBC,  0x17, 0xA6, 0xF9, 0xB6},
   {0x64, 0x01, 0x57, 0xBC,  0x18, 0xA6, 0xF9, 0xB7},
   {0x64, 0x01, 0x57, 0xBC,  0x19, 0xA6, 0xF9, 0xB8},
   {0x64, 0x01, 0x57, 0xBC,  0x1A, 0xA6, 0xF9, 0xB9},
   {0x64, 0x01, 0x57, 0xBC,  0x1B, 0xA6, 0xF9, 0xBA},
   {0x64, 0x01, 0x57, 0xBC,  0x1C, 0xA6, 0xF9, 0xBB},
   {0x64, 0x01, 0x57, 0xBC,  0x1D, 0xA6, 0xF9, 0xBC},
   {0x64, 0x01, 0x57, 0xBC,  0x1E, 0xA6, 0xF9, 0xBD},
   {0x64, 0x01, 0x57, 0xBC,  0x1F, 0xA6, 0xF9, 0xBE},
   {0x64, 0x01, 0x57, 0xBC,  0x20, 0xA6, 0xF9, 0xBF},
   {0x64, 0x01, 0x57, 0xBC,  0x21, 0xA6, 0xF9, 0xC0},
   {0x64, 0x01, 0x57, 0xBC,  0x22, 0xA6, 0xF9, 0xC1},
   {0x64, 0x01, 0x57, 0xBC,  0x23, 0xA6, 0xF9, 0xC2},
   {0x64, 0x01, 0x57, 0xBC,  0x24, 0xA6, 0xF9, 0xC3},
   {0x64, 0x01, 0x57, 0xBC,  0x25, 0xA6, 0xF9, 0xC4},
   {0x64, 0x01, 0x57, 0xBC,  0x26, 0xA6, 0xF9, 0xC5},
   {0x64, 0x01, 0x57, 0xBC,  0x27, 0xA6, 0xF9, 0xC6},
   {0x64, 0x01, 0x57, 0xBC,  0x28, 0xA6, 0xF9, 0xC7},
   {0x64, 0x01, 0x57, 0xBC,  0x29, 0xA6, 0xF9, 0xC8},
   {0x64, 0x01, 0x57, 0xBC,  0x2A, 0xA6, 0xF9, 0xC9},
   {0x64, 0x01, 0x57, 0xBC,  0x2B, 0xA6, 0xF9, 0xCA},
   {0x64, 0x01, 0x57, 0xBC,  0x2C, 0xA6, 0xF9, 0xCB},
   {0x64, 0x01, 0x57, 0xBC,  0x2D, 0xA6, 0xF9, 0xCC},
   {0x64, 0x01, 0x57, 0xBC,  0x2E, 0xA6, 0xF9, 0xCD},
   {0x64, 0x01, 0x57, 0xBC,  0x2F, 0xA6, 0xF9, 0xCE},
   {0x64, 0x01, 0x57, 0xBC,  0x30, 0xA6, 0xF9, 0xCF},
   {0x64, 0x01, 0x57, 0xBC,  0x31, 0xA6, 0xF9, 0xD0},
   {0x64, 0x01, 0x57, 0xBC,  0x32, 0xA6, 0xF9, 0xD1},
   {0x64, 0x01, 0x57, 0xBC,  0x33, 0xA6, 0xF9, 0xD2},
   {0x64, 0x01, 0x57, 0xBC,  0x34, 0xA6, 0xF9, 0xD3},
   {0x64, 0x01, 0x57, 0xBC,  0x35, 0xA6, 0xF9, 0xD4},
/* 3 */
   {0x64, 0x01, 0x57, 0xBC,  0x16, 0xA6, 0xF9, 0xB5},
   {0x64, 0x01, 0x57, 0xBC,  0x17, 0xA6, 0xF9, 0xB6},
   {0x64, 0x01, 0x57, 0xBC,  0x18, 0xA6, 0xF9, 0xB7},
   {0x64, 0x01, 0x57, 0xBC,  0x19, 0xA6, 0xF9, 0xB8},
   {0x64, 0x01, 0x57, 0xBC,  0x1A, 0xA6, 0xF9, 0xB9},
   {0x64, 0x01, 0x57, 0xBC,  0x1B, 0xA6, 0xF9, 0xBA},
   {0x64, 0x01, 0x57, 0xBC,  0x1C, 0xA6, 0xF9, 0xBB},
   {0x64, 0x01, 0x57, 0xBC,  0x1D, 0xA6, 0xF9, 0xBC},
   {0x64, 0x01, 0x57, 0xBC,  0x1E, 0xA6, 0xF9, 0xBD},
   {0x64, 0x01, 0x57, 0xBC,  0x1F, 0xA6, 0xF9, 0xBE},
   {0x64, 0x01, 0x57, 0xBC,  0x20, 0xA6, 0xF9, 0xBF},
   {0x64, 0x01, 0x57, 0xBC,  0x21, 0xA6, 0xF9, 0xC0},
   {0x64, 0x01, 0x57, 0xBC,  0x22, 0xA6, 0xF9, 0xC1},
   {0x64, 0x01, 0x57, 0xBC,  0x23, 0xA6, 0xF9, 0xC2},
   {0x64, 0x01, 0x57, 0xBC,  0x24, 0xA6, 0xF9, 0xC3},
   {0x64, 0x01, 0x57, 0xBC,  0x25, 0xA6, 0xF9, 0xC4},
   {0x64, 0x01, 0x57, 0xBC,  0x26, 0xA6, 0xF9, 0xC5},
   {0x64, 0x01, 0x57, 0xBC,  0x27, 0xA6, 0xF9, 0xC6},
   {0x64, 0x01, 0x57, 0xBC,  0x28, 0xA6, 0xF9, 0xC7},
   {0x64, 0x01, 0x57, 0xBC,  0x29, 0xA6, 0xF9, 0xC8},
   {0x64, 0x01, 0x57, 0xBC,  0x2A, 0xA6, 0xF9, 0xC9},
   {0x64, 0x01, 0x57, 0xBC,  0x2B, 0xA6, 0xF9, 0xCA},
   {0x64, 0x01, 0x57, 0xBC,  0x2C, 0xA6, 0xF9, 0xCB},
   {0x64, 0x01, 0x57, 0xBC,  0x2D, 0xA6, 0xF9, 0xCC},
   {0x64, 0x01, 0x57, 0xBC,  0x2E, 0xA6, 0xF9, 0xCD},
   {0x64, 0x01, 0x57, 0xBC,  0x2F, 0xA6, 0xF9, 0xCE},
   {0x64, 0x01, 0x57, 0xBC,  0x30, 0xA6, 0xF9, 0xCF},
   {0x64, 0x01, 0x57, 0xBC,  0x31, 0xA6, 0xF9, 0xD0},
   {0x64, 0x01, 0x57, 0xBC,  0x32, 0xA6, 0xF9, 0xD1},
   {0x64, 0x01, 0x57, 0xBC,  0x33, 0xA6, 0xF9, 0xD2},
   {0x64, 0x01, 0x57, 0xBC,  0x34, 0xA6, 0xF9, 0xD3},
   {0x64, 0x01, 0x57, 0xBC,  0x35, 0xA6, 0xF9, 0xD4},
};

const unsigned char bs_tc_expstream[32][16] = {
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0x2F, 0x8E, 0xE1, 0x0C,  0xA6, 0x1E, 0xB2, 0x33},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0xEB, 0x98, 0xB7, 0x1E,  0xC1, 0xD7, 0xE5, 0x4C},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0x98, 0x45, 0x20, 0xF4,  0xBB, 0xF1, 0x4B, 0x75},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0xFA, 0x98, 0xEA, 0x0C,  0xAB, 0x40, 0x35, 0x1E},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0x2F, 0x87, 0x15, 0xFB,  0x63, 0xC0, 0x85, 0x64},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0x59, 0x5B, 0xF9, 0x7A,  0x1C, 0x1E, 0xC1, 0x7A},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0x84, 0x56, 0x30, 0x39,  0x20, 0x9F, 0x07, 0xAA},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0x25, 0x74, 0xF2, 0x00,  0x3D, 0xEC, 0x95, 0x51},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0x99, 0x27, 0x98, 0xC3,  0xFE, 0x8F, 0x74, 0xFF},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0x65, 0xAF, 0xA5, 0x4D,  0x0A, 0xE2, 0x6B, 0xE9},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0xA1, 0xD6, 0x99, 0x42,  0xC9, 0xC1, 0x2E, 0x61},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0x84, 0xE5, 0xAE, 0x08,  0x97, 0x87, 0x93, 0xEF},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0xBB, 0x59, 0xAE, 0xB0,  0x21, 0x03, 0x74, 0xC3},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0xC5, 0xC4, 0x81, 0xD4,  0x8A, 0xFB, 0xB3, 0xA4},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0x3C, 0x15, 0xB7, 0x7E,  0xB8, 0x06, 0xD4, 0x74},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0x66, 0x34, 0x6B, 0xC0,  0x57, 0x36, 0x9C, 0xE3},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0xEA, 0x0F, 0x46, 0x5C,  0xB6, 0x05, 0x1B, 0xC0},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0x3F, 0x6C, 0xE5, 0xCD,  0x1E, 0x3F, 0x1C, 0xC0},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0xB6, 0x3F, 0x29, 0x0C,  0xED, 0x15, 0x3B, 0xD6},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0x7D, 0xD2, 0xCF, 0x42,  0xF4, 0x5E, 0xF9, 0x4F},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0x6D, 0xB2, 0x56, 0x1D,  0x36, 0x31, 0x0C, 0x26},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0x01, 0xDC, 0x0E, 0x74,  0x58, 0x9C, 0x31, 0x0B},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0xC0, 0xC1, 0xDC, 0x92,  0x56, 0xC8, 0xB4, 0x2B},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0xA2, 0x43, 0x8A, 0x21,  0x56, 0x00, 0x21, 0x9C},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0x7C, 0x53, 0x5F, 0x99,  0x42, 0xEB, 0x72, 0x7D},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0xF5, 0x5E, 0xB1, 0xE1,  0xF6, 0x2E, 0x72, 0x29},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0x05, 0xA5, 0x6D, 0x10,  0x09, 0xD2, 0x95, 0x8F},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0x6C, 0x7F, 0x31, 0xC5,  0x24, 0x2D, 0xCE, 0xB4},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0xF3, 0x07, 0x61, 0xCB,  0xF8, 0xBF, 0x2E, 0x76},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0x03, 0x96, 0x4E, 0x54,  0x66, 0x76, 0xEA, 0x47},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0x70, 0x27, 0xD0, 0xF0,  0x02, 0xA5, 0x3C, 0x1B},
   {0x8C, 0xD7, 0x35, 0x89,  0x6D, 0xA4, 0xDC, 0x4B,   0x7C, 0x7C, 0xA2, 0x15,  0x4F, 0xF5, 0x99, 0xC7},
};

const unsigned char bs_tc_expblock[32][16] = {
   {0x03, 0x6D, 0xE2, 0xFF,  0x4C, 0x9D, 0x0C, 0x2B,   0x0A, 0xB3, 0x4D, 0xB0,  0x77, 0xDD, 0x9B, 0xBE},
   {0xA4, 0xD0, 0x8E, 0x88,  0xF0, 0x2B, 0xA6, 0xD3,   0xA3, 0x2A, 0x0F, 0x2E,  0x83, 0xC8, 0xC1, 0x38},
   {0xF6, 0x40, 0x54, 0x8C,  0xCE, 0xAA, 0xA1, 0x3C,   0x09, 0xA7, 0x20, 0xA9,  0xBE, 0x50, 0x62, 0x09},
   {0x26, 0x2E, 0x9D, 0x36,  0x38, 0x1E, 0x7D, 0x30,   0x21, 0xAE, 0xFB, 0xA9,  0xDB, 0xC4, 0x7C, 0x66},
   {0x66, 0xDA, 0x8E, 0x59,  0x0A, 0x5D, 0x33, 0x0D,   0xB1, 0x62, 0xF6, 0x9D,  0x07, 0x33, 0x0A, 0xAE},
   {0xAE, 0x8D, 0x74, 0xF8,  0x94, 0xE3, 0x07, 0x57,   0x4C, 0xB9, 0xE1, 0xC5,  0xFF, 0x71, 0x6F, 0xDA},
   {0x2C, 0x5A, 0x9E, 0xD7,  0xA7, 0x1B, 0x90, 0x3E,   0x06, 0xFA, 0xB9, 0xE7,  0x04, 0xA7, 0x59, 0xCE},
   {0x95, 0x8A, 0x0C, 0xDE,  0xEA, 0x65, 0xBA, 0xFA,   0xD9, 0xAB, 0xEF, 0xB0,  0xC7, 0x24, 0x20, 0xBF},
   {0x12, 0x13, 0x99, 0x7C,  0xD3, 0x53, 0xBB, 0xE9,   0x19, 0x4B, 0x26, 0xE4,  0x39, 0xCF, 0xEB, 0x94},
   {0x92, 0x49, 0xD0, 0x66,  0x8A, 0x3C, 0xEA, 0x3E,   0x19, 0x7B, 0x2A, 0x49,  0xB7, 0xFA, 0xDE, 0xE9},
   {0x81, 0x90, 0x48, 0x44,  0x9D, 0xF4, 0xAE, 0x71,   0x6E, 0xF2, 0x00, 0x40,  0xCF, 0x26, 0x8E, 0xC9},
   {0xC5, 0x55, 0x40, 0xBF,  0xAA, 0x63, 0x81, 0x0A,   0xBF, 0xFE, 0x98, 0x84,  0x1C, 0x7E, 0xF3, 0x57},
   {0x67, 0x09, 0xFA, 0xAC,  0x72, 0xA7, 0x37, 0x9E,   0x67, 0xE5, 0xC8, 0x05,  0xCF, 0xB6, 0x41, 0xF9},
   {0xB5, 0x8A, 0x9D, 0x49,  0xFD, 0x69, 0x43, 0x48,   0x8B, 0x94, 0x1D, 0xD7,  0x12, 0x15, 0x32, 0x64},
   {0x01, 0x8B, 0xD5, 0x93,  0x5A, 0x6F, 0x49, 0xDE,   0xB4, 0xE5, 0xE7, 0x5B,  0xEA, 0x98, 0x5E, 0x2C},
   {0x37, 0x1A, 0x9D, 0x47,  0x14, 0x90, 0xB0, 0x9F,   0xE4, 0x2B, 0x16, 0xE8,  0xFC, 0x0A, 0x1D, 0x99},
   {0xDF, 0x2B, 0x2C, 0x46,  0x30, 0x41, 0xAC, 0x20,   0x57, 0x63, 0x34, 0x13,  0xB2, 0xD0, 0x2D, 0xB3},
   {0x53, 0xC6, 0x09, 0xA6,  0xA0, 0xAD, 0x40, 0x4B,   0xBA, 0xF3, 0xB1, 0x04,  0x48, 0x3B, 0xBE, 0xAF},
   {0x8F, 0x25, 0xEC, 0xB2,  0x28, 0x21, 0x22, 0x87,   0x7A, 0x13, 0xCC, 0xB5,  0xDE, 0x1E, 0xCF, 0x8E},
   {0x68, 0x7A, 0x26, 0xEE,  0x0F, 0x4A, 0xB6, 0xF1,   0x45, 0x0B, 0x74, 0xBD,  0x84, 0xFD, 0x53, 0x39},
   {0x60, 0xB0, 0x7F, 0xDE,  0x64, 0x3D, 0xBA, 0x3F,   0x5E, 0x90, 0xA5, 0x13,  0x09, 0xDB, 0xE7, 0xC2},
   {0xFA, 0xF4, 0x05, 0x7E,  0xB0, 0x19, 0xB3, 0x5D,   0x37, 0x8E, 0x50, 0xC7,  0x35, 0xAB, 0x40, 0xFD},
   {0x70, 0x83, 0xAC, 0x4E,  0x01, 0x58, 0xB4, 0x07,   0x53, 0x77, 0xA6, 0xAF,  0x20, 0xF0, 0x03, 0x3D},
   {0x2D, 0x1E, 0x2D, 0xF4,  0xAC, 0x95, 0x72, 0x47,   0x0C, 0xD8, 0xD4, 0xC4,  0x7F, 0x2B, 0x3D, 0x3C},
   {0xF4, 0xAA, 0x73, 0xDA,  0x82, 0xD6, 0x3E, 0x4E,   0xCB, 0xF2, 0x77, 0xF1,  0xB2, 0x53, 0x48, 0x7F},
   {0x8C, 0x5D, 0x22, 0x37,  0x0C, 0xA5, 0xB9, 0x9C,   0x25, 0x02, 0xA7, 0x5F,  0x32, 0xFD, 0x8F, 0x88},
   {0x7F, 0x34, 0x10, 0x4F,  0x1E, 0x32, 0x7F, 0xDB,   0x88, 0xFA, 0x18, 0xDE,  0xE9, 0xD7, 0x27, 0x8D},
   {0x95, 0x8D, 0x32, 0xFD,  0x30, 0xDF, 0x8A, 0x87,   0xC2, 0x53, 0x65, 0xC7,  0xFA, 0x86, 0xA5, 0xED},
   {0x27, 0x13, 0xCC, 0x19,  0x57, 0x45, 0xDB, 0x18,   0xBD, 0xA4, 0x60, 0x09,  0xB2, 0xB5, 0x28, 0x0B},
   {0x36, 0x5F, 0x14, 0x19,  0x66, 0xB8, 0x68, 0x80,   0x40, 0xCB, 0x9D, 0xF2,  0xED, 0x21, 0x13, 0x05},
   {0x09, 0x00, 0x37, 0xEC,  0xB8, 0x55, 0x13, 0x33,   0xC4, 0x59, 0xDB, 0x15,  0xCD, 0xC7, 0x02, 0x28},
   {0x33, 0xB3, 0x5D, 0x64,  0x75, 0x75, 0x08, 0x96,   0xD8, 0xE2, 0x4B, 0x4C,  0xCE, 0xE0, 0x5E, 0xC3},
};

const unsigned char bs_tc_expected[32*4][16] = {
/* 0 */
   {0x00, 0x00, 0x01, 0xC0,  0x0D, 0x88, 0x84, 0x80,   0x05, 0x2F, 0x22, 0x25,  0x19, 0xE1, 0xFF, 0xFC},
   {0x63, 0xAB, 0x3B, 0xA5,  0xD6, 0xF7, 0x79, 0x07,   0x33, 0x14, 0x2C, 0x85,  0x60, 0x1C, 0xDA, 0x81},
   {0x42, 0xE6, 0x76, 0x4B,  0x92, 0x50, 0xD0, 0xD1,   0xD1, 0x52, 0x00, 0x99,  0x35, 0x09, 0x8B, 0xE7},
   {0xF0, 0x55, 0x75, 0x09,  0x74, 0x55, 0x72, 0xB6,   0x0B, 0xA9, 0x55, 0xF7,  0x2D, 0xDD, 0x0D, 0xDF},
   {0x65, 0xBE, 0x99, 0x91,  0x8E, 0x96, 0x8C, 0xF1,   0x73, 0xFA, 0x67, 0x8A,  0x46, 0x35, 0xFF, 0xA5},
   {0xDB, 0x35, 0x8F, 0xB1,  0x6F, 0xF6, 0xFC, 0xB5,   0xC8, 0xE3, 0xAF, 0xFE,  0x15, 0x36, 0xF3, 0x01},
   {0x84, 0xEF, 0xAC, 0xDD,  0x60, 0x8F, 0xAD, 0x0C,   0x10, 0xBA, 0x16, 0xCB,  0x68, 0x89, 0xB7, 0xC1},
   {0x9C, 0x1D, 0xFC, 0xED,  0x30, 0x82, 0x15, 0x33,   0xE0, 0x57, 0x46, 0xE5,  0x67, 0xFC, 0x34, 0xED},
   {0xA7, 0xD7, 0x03, 0x8C,  0xCA, 0xD7, 0xF5, 0x8E,   0x65, 0xEE, 0x3A, 0x50,  0x50, 0x10, 0x99, 0x83},
   {0xDB, 0x05, 0x77, 0x18,  0x67, 0xD5, 0xBB, 0x4F,   0xE1, 0xB5, 0xC3, 0x87,  0x7D, 0xBB, 0xA4, 0xF5},
   {0x0C, 0xA5, 0xD3, 0x35,  0xB3, 0x3E, 0xBA, 0x88,   0x07, 0xD9, 0x75, 0xE9,  0x0E, 0xC6, 0xBB, 0xBE},
   {0x6D, 0x53, 0xEC, 0x84,  0xDA, 0xEF, 0x28, 0x7D,   0xD1, 0xB4, 0x9C, 0xDD,  0xA6, 0x07, 0x36, 0x08},
   {0xF0, 0xB3, 0x56, 0x2F,  0xB4, 0xAF, 0x79, 0xC5,   0xA7, 0x49, 0xA9, 0x6D,  0x82, 0x98, 0x19, 0x8C},
   {0x5C, 0xAD, 0x1E, 0xAE,  0x90, 0x99, 0xCA, 0x74,   0x8F, 0x51, 0xD5, 0x7E,  0x17, 0x59, 0xB7, 0x44},
   {0x11, 0x7D, 0x60, 0xDE,  0x05, 0x62, 0xA7, 0x32,   0xA2, 0xDB, 0x86, 0x07,  0xA0, 0x1C, 0xAB, 0x4D},
   {0x7D, 0xCD, 0xF4, 0xB4,  0xA4, 0xAD, 0x16, 0xE4,   0x78, 0xD0, 0x66, 0xC8,  0x4A, 0x9F, 0x7A, 0x0D},
   {0x19, 0xC7, 0x68, 0x29,  0x61, 0x4F, 0x8D, 0x78,   0x30, 0x6A, 0x49, 0xA6,  0xC6, 0xCF, 0xD9, 0xBF},
   {0x40, 0x49, 0xEE, 0x58,  0x59, 0x99, 0x66, 0x13,   0x03, 0xA6, 0x15, 0x37,  0x85, 0xF1, 0x8B, 0xBB},
   {0x15, 0xF9, 0xC7, 0x8D,  0x22, 0x3F, 0x23, 0xC9,   0x41, 0x7C, 0x15, 0x74,  0xF8, 0xFB, 0x68, 0xD3},
   {0x39, 0x4B, 0xEB, 0x9F,  0x1C, 0x1F, 0x75, 0x26,   0x8C, 0xD5, 0x85, 0x12,  0xA7, 0x48, 0xFD, 0xB0},
   {0x21, 0xE1, 0x2B, 0xF0,  0xB5, 0x07, 0x8C, 0x81,   0x66, 0x2E, 0x72, 0x4D,  0x56, 0x40, 0xFE, 0x4E},
   {0xD7, 0xCB, 0x09, 0x39,  0x0F, 0x8E, 0xB8, 0xCE,   0x7A, 0x5E, 0xFF, 0xDA,  0x9F, 0xA5, 0xB6, 0x34},
   {0x9C, 0xA1, 0x72, 0xEF,  0xB0, 0x9B, 0x3A, 0xB4,   0xBF, 0x91, 0x7F, 0xAC,  0x1D, 0x45, 0xFB, 0x61},
   {0xA3, 0xBE, 0xA5, 0xE6,  0x1D, 0x9E, 0x69, 0x43,   0x44, 0xD9, 0x2C, 0xFC,  0x8C, 0x2A, 0xED, 0x72},
   {0xA4, 0x1A, 0x2E, 0x70,  0x27, 0x36, 0x76, 0xAB,   0xDC, 0x19, 0x57, 0xFB,  0xE6, 0xC5, 0x26, 0x61},
   {0x55, 0xE0, 0x91, 0xE5,  0x1D, 0x80, 0xF1, 0x2D,   0xC7, 0x94, 0x76, 0xD0,  0x5F, 0x03, 0x49, 0xC1},
   {0x56, 0x72, 0x7F, 0x6C,  0xF0, 0xEB, 0xD0, 0xCC,   0xBC, 0xF0, 0x8E, 0xB0,  0xBD, 0x05, 0x7E, 0x66},
   {0xD5, 0x11, 0x01, 0x0B,  0xF3, 0xF9, 0x7E, 0xAB,   0xCE, 0xD7, 0x05, 0x46,  0x94, 0x8F, 0x7D, 0xF4},
   {0xF8, 0xF7, 0xAF, 0xE1,  0x48, 0xF1, 0xCF, 0xF6,   0x00, 0x4B, 0xF8, 0x08,  0x2B, 0xF3, 0xE0, 0x0D},
   {0x19, 0x2A, 0x58, 0x7E,  0xE7, 0xC5, 0xB8, 0x5F,   0x0B, 0x72, 0x72, 0x42,  0x46, 0x73, 0x18, 0xE3},
   {0x55, 0xC4, 0xE5, 0x2F,  0x5D, 0xFB, 0x15, 0xB0,   0x87, 0x3D, 0xF0, 0x21,  0x17, 0x62, 0x32, 0xD8},
   {0x63, 0x2C, 0xFD, 0x42,  0xDD, 0x8B, 0xAB, 0xC9,   0x94, 0xBC, 0xB1, 0xF2,  0x30, 0xC5, 0xC3, 0x76},
/* 1 */
   {0x00, 0x00, 0x01, 0xC0,  0x0D, 0x88, 0x84, 0x80,   0x05, 0x2F, 0x22, 0x25,  0x19, 0xE1, 0xFF, 0xFC},
   {0x63, 0xAB, 0x3B, 0xA5,  0xD6, 0xF7, 0x79, 0x07,   0x33, 0x14, 0x2C, 0x85,  0x60, 0x1C, 0xDA, 0x81},
   {0x42, 0xE6, 0x76, 0x4B,  0x92, 0x50, 0xD0, 0xD1,   0xD1, 0x52, 0x00, 0x99,  0x35, 0x09, 0x8B, 0xE7},
   {0xF0, 0x55, 0x75, 0x09,  0x74, 0x55, 0x72, 0xB6,   0x0B, 0xA9, 0x55, 0xF7,  0x2D, 0xDD, 0x0D, 0xDF},
   {0x65, 0xBE, 0x99, 0x91,  0x8E, 0x96, 0x8C, 0xF1,   0x73, 0xFA, 0x67, 0x8A,  0x46, 0x35, 0xFF, 0xA5},
   {0xDB, 0x35, 0x8F, 0xB1,  0x6F, 0xF6, 0xFC, 0xB5,   0xC8, 0xE3, 0xAF, 0xFE,  0x15, 0x36, 0xF3, 0x01},
   {0x84, 0xEF, 0xAC, 0xDD,  0x60, 0x8F, 0xAD, 0x0C,   0x10, 0xBA, 0x16, 0xCB,  0x68, 0x89, 0xB7, 0xC1},
   {0x9C, 0x1D, 0xFC, 0xED,  0x30, 0x82, 0x15, 0x33,   0xE0, 0x57, 0x46, 0xE5,  0x67, 0xFC, 0x34, 0xED},
   {0xA7, 0xD7, 0x03, 0x8C,  0xCA, 0xD7, 0xF5, 0x8E,   0x65, 0xEE, 0x3A, 0x50,  0x50, 0x10, 0x99, 0x83},
   {0xDB, 0x05, 0x77, 0x18,  0x67, 0xD5, 0xBB, 0x4F,   0xE1, 0xB5, 0xC3, 0x87,  0x7D, 0xBB, 0xA4, 0xF5},
   {0x0C, 0xA5, 0xD3, 0x35,  0xB3, 0x3E, 0xBA, 0x88,   0x07, 0xD9, 0x75, 0xE9,  0x0E, 0xC6, 0xBB, 0xBE},
   {0x6D, 0x53, 0xEC, 0x84,  0xDA, 0xEF, 0x28, 0x7D,   0xD1, 0xB4, 0x9C, 0xDD,  0xA6, 0x07, 0x36, 0x08},
   {0xF0, 0xB3, 0x56, 0x2F,  0xB4, 0xAF, 0x79, 0xC5,   0xA7, 0x49, 0xA9, 0x6D,  0x82, 0x98, 0x19, 0x8C},
   {0x5C, 0xAD, 0x1E, 0xAE,  0x90, 0x99, 0xCA, 0x74,   0x8F, 0x51, 0xD5, 0x7E,  0x17, 0x59, 0xB7, 0x44},
   {0x11, 0x7D, 0x60, 0xDE,  0x05, 0x62, 0xA7, 0x32,   0xA2, 0xDB, 0x86, 0x07,  0xA0, 0x1C, 0xAB, 0x4D},
   {0x7D, 0xCD, 0xF4, 0xB4,  0xA4, 0xAD, 0x16, 0xE4,   0x78, 0xD0, 0x66, 0xC8,  0x4A, 0x9F, 0x7A, 0x0D},
   {0x19, 0xC7, 0x68, 0x29,  0x61, 0x4F, 0x8D, 0x78,   0x30, 0x6A, 0x49, 0xA6,  0xC6, 0xCF, 0xD9, 0xBF},
   {0x40, 0x49, 0xEE, 0x58,  0x59, 0x99, 0x66, 0x13,   0x03, 0xA6, 0x15, 0x37,  0x85, 0xF1, 0x8B, 0xBB},
   {0x15, 0xF9, 0xC7, 0x8D,  0x22, 0x3F, 0x23, 0xC9,   0x41, 0x7C, 0x15, 0x74,  0xF8, 0xFB, 0x68, 0xD3},
   {0x39, 0x4B, 0xEB, 0x9F,  0x1C, 0x1F, 0x75, 0x26,   0x8C, 0xD5, 0x85, 0x12,  0xA7, 0x48, 0xFD, 0xB0},
   {0x21, 0xE1, 0x2B, 0xF0,  0xB5, 0x07, 0x8C, 0x81,   0x66, 0x2E, 0x72, 0x4D,  0x56, 0x40, 0xFE, 0x4E},
   {0xD7, 0xCB, 0x09, 0x39,  0x0F, 0x8E, 0xB8, 0xCE,   0x7A, 0x5E, 0xFF, 0xDA,  0x9F, 0xA5, 0xB6, 0x34},
   {0x9C, 0xA1, 0x72, 0xEF,  0xB0, 0x9B, 0x3A, 0xB4,   0xBF, 0x91, 0x7F, 0xAC,  0x1D, 0x45, 0xFB, 0x61},
   {0xA3, 0xBE, 0xA5, 0xE6,  0x1D, 0x9E, 0x69, 0x43,   0x44, 0xD9, 0x2C, 0xFC,  0x8C, 0x2A, 0xED, 0x72},
   {0xA4, 0x1A, 0x2E, 0x70,  0x27, 0x36, 0x76, 0xAB,   0xDC, 0x19, 0x57, 0xFB,  0xE6, 0xC5, 0x26, 0x61},
   {0x55, 0xE0, 0x91, 0xE5,  0x1D, 0x80, 0xF1, 0x2D,   0xC7, 0x94, 0x76, 0xD0,  0x5F, 0x03, 0x49, 0xC1},
   {0x56, 0x72, 0x7F, 0x6C,  0xF0, 0xEB, 0xD0, 0xCC,   0xBC, 0xF0, 0x8E, 0xB0,  0xBD, 0x05, 0x7E, 0x66},
   {0xD5, 0x11, 0x01, 0x0B,  0xF3, 0xF9, 0x7E, 0xAB,   0xCE, 0xD7, 0x05, 0x46,  0x94, 0x8F, 0x7D, 0xF4},
   {0xF8, 0xF7, 0xAF, 0xE1,  0x48, 0xF1, 0xCF, 0xF6,   0x00, 0x4B, 0xF8, 0x08,  0x2B, 0xF3, 0xE0, 0x0D},
   {0x19, 0x2A, 0x58, 0x7E,  0xE7, 0xC5, 0xB8, 0x5F,   0x0B, 0x72, 0x72, 0x42,  0x46, 0x73, 0x18, 0xE3},
   {0x55, 0xC4, 0xE5, 0x2F,  0x5D, 0xFB, 0x15, 0xB0,   0x87, 0x3D, 0xF0, 0x21,  0x17, 0x62, 0x32, 0xD8},
   {0x63, 0x2C, 0xFD, 0x42,  0xDD, 0x8B, 0xAB, 0xC9,   0x94, 0xBC, 0xB1, 0xF2,  0x30, 0xC5, 0xC3, 0x76},
/* 2 */
   {0x00, 0x00, 0x01, 0xC0,  0x0D, 0x88, 0x84, 0x80,   0x05, 0x2F, 0x22, 0x25,  0x19, 0xE1, 0xFF, 0xFC},
   {0x63, 0xAB, 0x3B, 0xA5,  0xD6, 0xF7, 0x79, 0x07,   0x33, 0x14, 0x2C, 0x85,  0x60, 0x1C, 0xDA, 0x81},
   {0x42, 0xE6, 0x76, 0x4B,  0x92, 0x50, 0xD0, 0xD1,   0xD1, 0x52, 0x00, 0x99,  0x35, 0x09, 0x8B, 0xE7},
   {0xF0, 0x55, 0x75, 0x09,  0x74, 0x55, 0x72, 0xB6,   0x0B, 0xA9, 0x55, 0xF7,  0x2D, 0xDD, 0x0D, 0xDF},
   {0x65, 0xBE, 0x99, 0x91,  0x8E, 0x96, 0x8C, 0xF1,   0x73, 0xFA, 0x67, 0x8A,  0x46, 0x35, 0xFF, 0xA5},
   {0xDB, 0x35, 0x8F, 0xB1,  0x6F, 0xF6, 0xFC, 0xB5,   0xC8, 0xE3, 0xAF, 0xFE,  0x15, 0x36, 0xF3, 0x01},
   {0x84, 0xEF, 0xAC, 0xDD,  0x60, 0x8F, 0xAD, 0x0C,   0x10, 0xBA, 0x16, 0xCB,  0x68, 0x89, 0xB7, 0xC1},
   {0x9C, 0x1D, 0xFC, 0xED,  0x30, 0x82, 0x15, 0x33,   0xE0, 0x57, 0x46, 0xE5,  0x67, 0xFC, 0x34, 0xED},
   {0xA7, 0xD7, 0x03, 0x8C,  0xCA, 0xD7, 0xF5, 0x8E,   0x65, 0xEE, 0x3A, 0x50,  0x50, 0x10, 0x99, 0x83},
   {0xDB, 0x05, 0x77, 0x18,  0x67, 0xD5, 0xBB, 0x4F,   0xE1, 0xB5, 0xC3, 0x87,  0x7D, 0xBB, 0xA4, 0xF5},
   {0x0C, 0xA5, 0xD3, 0x35,  0xB3, 0x3E, 0xBA, 0x88,   0x07, 0xD9, 0x75, 0xE9,  0x0E, 0xC6, 0xBB, 0xBE},
   {0x6D, 0x53, 0xEC, 0x84,  0xDA, 0xEF, 0x28, 0x7D,   0xD1, 0xB4, 0x9C, 0xDD,  0xA6, 0x07, 0x36, 0x08},
   {0xF0, 0xB3, 0x56, 0x2F,  0xB4, 0xAF, 0x79, 0xC5,   0xA7, 0x49, 0xA9, 0x6D,  0x82, 0x98, 0x19, 0x8C},
   {0x5C, 0xAD, 0x1E, 0xAE,  0x90, 0x99, 0xCA, 0x74,   0x8F, 0x51, 0xD5, 0x7E,  0x17, 0x59, 0xB7, 0x44},
   {0x11, 0x7D, 0x60, 0xDE,  0x05, 0x62, 0xA7, 0x32,   0xA2, 0xDB, 0x86, 0x07,  0xA0, 0x1C, 0xAB, 0x4D},
   {0x7D, 0xCD, 0xF4, 0xB4,  0xA4, 0xAD, 0x16, 0xE4,   0x78, 0xD0, 0x66, 0xC8,  0x4A, 0x9F, 0x7A, 0x0D},
   {0x19, 0xC7, 0x68, 0x29,  0x61, 0x4F, 0x8D, 0x78,   0x30, 0x6A, 0x49, 0xA6,  0xC6, 0xCF, 0xD9, 0xBF},
   {0x40, 0x49, 0xEE, 0x58,  0x59, 0x99, 0x66, 0x13,   0x03, 0xA6, 0x15, 0x37,  0x85, 0xF1, 0x8B, 0xBB},
   {0x15, 0xF9, 0xC7, 0x8D,  0x22, 0x3F, 0x23, 0xC9,   0x41, 0x7C, 0x15, 0x74,  0xF8, 0xFB, 0x68, 0xD3},
   {0x39, 0x4B, 0xEB, 0x9F,  0x1C, 0x1F, 0x75, 0x26,   0x8C, 0xD5, 0x85, 0x12,  0xA7, 0x48, 0xFD, 0xB0},
   {0x21, 0xE1, 0x2B, 0xF0,  0xB5, 0x07, 0x8C, 0x81,   0x66, 0x2E, 0x72, 0x4D,  0x56, 0x40, 0xFE, 0x4E},
   {0xD7, 0xCB, 0x09, 0x39,  0x0F, 0x8E, 0xB8, 0xCE,   0x7A, 0x5E, 0xFF, 0xDA,  0x9F, 0xA5, 0xB6, 0x34},
   {0x9C, 0xA1, 0x72, 0xEF,  0xB0, 0x9B, 0x3A, 0xB4,   0xBF, 0x91, 0x7F, 0xAC,  0x1D, 0x45, 0xFB, 0x61},
   {0xA3, 0xBE, 0xA5, 0xE6,  0x1D, 0x9E, 0x69, 0x43,   0x44, 0xD9, 0x2C, 0xFC,  0x8C, 0x2A, 0xED, 0x72},
   {0xA4, 0x1A, 0x2E, 0x70,  0x27, 0x36, 0x76, 0xAB,   0xDC, 0x19, 0x57, 0xFB,  0xE6, 0xC5, 0x26, 0x61},
   {0x55, 0xE0, 0x91, 0xE5,  0x1D, 0x80, 0xF1, 0x2D,   0xC7, 0x94, 0x76, 0xD0,  0x5F, 0x03, 0x49, 0xC1},
   {0x56, 0x72, 0x7F, 0x6C,  0xF0, 0xEB, 0xD0, 0xCC,   0xBC, 0xF0, 0x8E, 0xB0,  0xBD, 0x05, 0x7E, 0x66},
   {0xD5, 0x11, 0x01, 0x0B,  0xF3, 0xF9, 0x7E, 0xAB,   0xCE, 0xD7, 0x05, 0x46,  0x94, 0x8F, 0x7D, 0xF4},
   {0xF8, 0xF7, 0xAF, 0xE1,  0x48, 0xF1, 0xCF, 0xF6,   0x00, 0x4B, 0xF8, 0x08,  0x2B, 0xF3, 0xE0, 0x0D},
   {0x19, 0x2A, 0x58, 0x7E,  0xE7, 0xC5, 0xB8, 0x5F,   0x0B, 0x72, 0x72, 0x42,  0x46, 0x73, 0x18, 0xE3},
   {0x55, 0xC4, 0xE5, 0x2F,  0x5D, 0xFB, 0x15, 0xB0,   0x87, 0x3D, 0xF0, 0x21,  0x17, 0x62, 0x32, 0xD8},
   {0x63, 0x2C, 0xFD, 0x42,  0xDD, 0x8B, 0xAB, 0xC9,   0x94, 0xBC, 0xB1, 0xF2,  0x30, 0xC5, 0xC3, 0x76},
/* 3 */
   {0x00, 0x00, 0x01, 0xC0,  0x0D, 0x88, 0x84, 0x80,   0x05, 0x2F, 0x22, 0x25,  0x19, 0xE1, 0xFF, 0xFC},
   {0x63, 0xAB, 0x3B, 0xA5,  0xD6, 0xF7, 0x79, 0x07,   0x33, 0x14, 0x2C, 0x85,  0x60, 0x1C, 0xDA, 0x81},
   {0x42, 0xE6, 0x76, 0x4B,  0x92, 0x50, 0xD0, 0xD1,   0xD1, 0x52, 0x00, 0x99,  0x35, 0x09, 0x8B, 0xE7},
   {0xF0, 0x55, 0x75, 0x09,  0x74, 0x55, 0x72, 0xB6,   0x0B, 0xA9, 0x55, 0xF7,  0x2D, 0xDD, 0x0D, 0xDF},
   {0x65, 0xBE, 0x99, 0x91,  0x8E, 0x96, 0x8C, 0xF1,   0x73, 0xFA, 0x67, 0x8A,  0x46, 0x35, 0xFF, 0xA5},
   {0xDB, 0x35, 0x8F, 0xB1,  0x6F, 0xF6, 0xFC, 0xB5,   0xC8, 0xE3, 0xAF, 0xFE,  0x15, 0x36, 0xF3, 0x01},
   {0x84, 0xEF, 0xAC, 0xDD,  0x60, 0x8F, 0xAD, 0x0C,   0x10, 0xBA, 0x16, 0xCB,  0x68, 0x89, 0xB7, 0xC1},
   {0x9C, 0x1D, 0xFC, 0xED,  0x30, 0x82, 0x15, 0x33,   0xE0, 0x57, 0x46, 0xE5,  0x67, 0xFC, 0x34, 0xED},
   {0xA7, 0xD7, 0x03, 0x8C,  0xCA, 0xD7, 0xF5, 0x8E,   0x65, 0xEE, 0x3A, 0x50,  0x50, 0x10, 0x99, 0x83},
   {0xDB, 0x05, 0x77, 0x18,  0x67, 0xD5, 0xBB, 0x4F,   0xE1, 0xB5, 0xC3, 0x87,  0x7D, 0xBB, 0xA4, 0xF5},
   {0x0C, 0xA5, 0xD3, 0x35,  0xB3, 0x3E, 0xBA, 0x88,   0x07, 0xD9, 0x75, 0xE9,  0x0E, 0xC6, 0xBB, 0xBE},
   {0x6D, 0x53, 0xEC, 0x84,  0xDA, 0xEF, 0x28, 0x7D,   0xD1, 0xB4, 0x9C, 0xDD,  0xA6, 0x07, 0x36, 0x08},
   {0xF0, 0xB3, 0x56, 0x2F,  0xB4, 0xAF, 0x79, 0xC5,   0xA7, 0x49, 0xA9, 0x6D,  0x82, 0x98, 0x19, 0x8C},
   {0x5C, 0xAD, 0x1E, 0xAE,  0x90, 0x99, 0xCA, 0x74,   0x8F, 0x51, 0xD5, 0x7E,  0x17, 0x59, 0xB7, 0x44},
   {0x11, 0x7D, 0x60, 0xDE,  0x05, 0x62, 0xA7, 0x32,   0xA2, 0xDB, 0x86, 0x07,  0xA0, 0x1C, 0xAB, 0x4D},
   {0x7D, 0xCD, 0xF4, 0xB4,  0xA4, 0xAD, 0x16, 0xE4,   0x78, 0xD0, 0x66, 0xC8,  0x4A, 0x9F, 0x7A, 0x0D},
   {0x19, 0xC7, 0x68, 0x29,  0x61, 0x4F, 0x8D, 0x78,   0x30, 0x6A, 0x49, 0xA6,  0xC6, 0xCF, 0xD9, 0xBF},
   {0x40, 0x49, 0xEE, 0x58,  0x59, 0x99, 0x66, 0x13,   0x03, 0xA6, 0x15, 0x37,  0x85, 0xF1, 0x8B, 0xBB},
   {0x15, 0xF9, 0xC7, 0x8D,  0x22, 0x3F, 0x23, 0xC9,   0x41, 0x7C, 0x15, 0x74,  0xF8, 0xFB, 0x68, 0xD3},
   {0x39, 0x4B, 0xEB, 0x9F,  0x1C, 0x1F, 0x75, 0x26,   0x8C, 0xD5, 0x85, 0x12,  0xA7, 0x48, 0xFD, 0xB0},
   {0x21, 0xE1, 0x2B, 0xF0,  0xB5, 0x07, 0x8C, 0x81,   0x66, 0x2E, 0x72, 0x4D,  0x56, 0x40, 0xFE, 0x4E},
   {0xD7, 0xCB, 0x09, 0x39,  0x0F, 0x8E, 0xB8, 0xCE,   0x7A, 0x5E, 0xFF, 0xDA,  0x9F, 0xA5, 0xB6, 0x34},
   {0x9C, 0xA1, 0x72, 0xEF,  0xB0, 0x9B, 0x3A, 0xB4,   0xBF, 0x91, 0x7F, 0xAC,  0x1D, 0x45, 0xFB, 0x61},
   {0xA3, 0xBE, 0xA5, 0xE6,  0x1D, 0x9E, 0x69, 0x43,   0x44, 0xD9, 0x2C, 0xFC,  0x8C, 0x2A, 0xED, 0x72},
   {0xA4, 0x1A, 0x2E, 0x70,  0x27, 0x36, 0x76, 0xAB,   0xDC, 0x19, 0x57, 0xFB,  0xE6, 0xC5, 0x26, 0x61},
   {0x55, 0xE0, 0x91, 0xE5,  0x1D, 0x80, 0xF1, 0x2D,   0xC7, 0x94, 0x76, 0xD0,  0x5F, 0x03, 0x49, 0xC1},
   {0x56, 0x72, 0x7F, 0x6C,  0xF0, 0xEB, 0xD0, 0xCC,   0xBC, 0xF0, 0x8E, 0xB0,  0xBD, 0x05, 0x7E, 0x66},
   {0xD5, 0x11, 0x01, 0x0B,  0xF3, 0xF9, 0x7E, 0xAB,   0xCE, 0xD7, 0x05, 0x46,  0x94, 0x8F, 0x7D, 0xF4},
   {0xF8, 0xF7, 0xAF, 0xE1,  0x48, 0xF1, 0xCF, 0xF6,   0x00, 0x4B, 0xF8, 0x08,  0x2B, 0xF3, 0xE0, 0x0D},
   {0x19, 0x2A, 0x58, 0x7E,  0xE7, 0xC5, 0xB8, 0x5F,   0x0B, 0x72, 0x72, 0x42,  0x46, 0x73, 0x18, 0xE3},
   {0x55, 0xC4, 0xE5, 0x2F,  0x5D, 0xFB, 0x15, 0xB0,   0x87, 0x3D, 0xF0, 0x21,  0x17, 0x62, 0x32, 0xD8},
   {0x63, 0x2C, 0xFD, 0x42,  0xDD, 0x8B, 0xAB, 0xC9,   0x94, 0xBC, 0xB1, 0xF2,  0x30, 0xC5, 0xC3, 0x76},
};


int aycw_check_bs_testcases(dvbcsa_bs_word_t	*r)
{
   uint8 i, j, tmp;

   /* check bytesliced r data bytes against bs_tc_expected */
   for (i = 0; i<BS_BATCH_SIZE; i++)
   {
      for (j = 0; j<8; j++)
      {
         switch (i%BS_BATCH_BYTES)
         {  /* _mm_srli_si128 does only support immediate value */
         case 0:  tmp = BS_EXTRACT8(r[8 * j + i / BS_BATCH_BYTES], 0); break;
         case 1:  tmp = BS_EXTRACT8(r[8 * j + i / BS_BATCH_BYTES], 1); break;
         case 2:  tmp = BS_EXTRACT8(r[8 * j + i / BS_BATCH_BYTES], 2); break;
         case 3:  tmp = BS_EXTRACT8(r[8 * j + i / BS_BATCH_BYTES], 3); break;
         default: break;
         }

         if (bs_tc_expected[i][j] != tmp)
         {
            return 0;   // 0 == failed
         }
      }
   }
   return 1;   // ok
}

/******************************************************************************************/
/* key   00 11 22 33  44 00 00 44 */
unsigned char probedata[3][16] = { 
    {0xB2, 0x74, 0x85, 0x51 , 0xF9, 0x3C, 0x9B, 0xD2  , 0x30, 0x9E, 0x8E, 0x78 , 0xFB, 0x16, 0x55, 0xA9},
    {0x25, 0x2D, 0x3D, 0xAB , 0x5E, 0x3B, 0x31, 0x39  , 0xFE, 0xDF, 0xCD, 0x84 , 0x51, 0x5A, 0x86, 0x4A},
    {0xD0, 0xE1, 0x78, 0x48 , 0xB3, 0x41, 0x63, 0x22  , 0x25, 0xA3, 0x63, 0x0A , 0x0E, 0xD3, 0x1C, 0x70}};
currentkey32 = 0x00 << 24 | 0x111 << 16 | 0x33 << 8 | 0x44;

/* decrypts to
000001ff11111111aa11111111111155
000001ff11111111aa11111111111156
000001ff11111111aa11111111111157
*/