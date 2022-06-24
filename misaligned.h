#include <stdio.h>
#include <string.h>
#include <assert.h>

int printColorMap(void(*ReferenceManualFunPtr)(int,int));
  
struct ColorCode
{
    int PairNumber;
    char MajorColor[15];
    char MinorColor[15];
};
ColorCode Manual[26];

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};