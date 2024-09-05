#pragma once

#define min(a, b) a < b ? a : b
#define max(a, b) a > b ? a : b
#define swap(a) a >> (sizeof(a)*4) | a << (sizeof(a)*4)
#define high(a) ((a >> (sizeof(a)*4)) << (sizeof(a)*4)) >> (sizeof(a)*4)
#define low(a) (a << (sizeof(a)*4)) >> (sizeof(a)*4)

short choose(short min, short max);
void creator();
void setCaret(short x, short y);
void setColor(short clr);