#include <stdio.h>
#include <assert.h>
#include "misaligned.h"

int printColorMap(void(*ReferenceManualFunPtr)(int,int)) 
{
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) 
    {
        for(j = 0; j < 5; j++) 
        {
            ReferenceManualFunPtr(i,j);
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

void TestPrintColorMap(int MajorColorIndex, intMinorColorIndex)
{
    int k= 1;
    Manual[k].PairNumber = (MajorColorIndex*5)+ MinorColorIndex+1;
    strcpy(Manual[k].MajorColor, majorColor[MajorColorIndex]);
    strcpy(Manual[k].MinorColor, minorColor[MinorColorIndex]);
    k++;
}

int main() 
{   void (*ReferenceManualFunPtr)(int,int);
    ReferenceManualFunPtr = &TestPrintColorMap;
    int result = printColorMap(ReferenceManualFunPtr);
    assert(result == 25);
    assert(Manual[2].pairNumber == 2);
    assert(strcmp(Manual[2].MajorColor,"White") == 0);
    assert(strcmp(Manual[2].MinorColor,"Orange") == 0);
    printf("All is well (maybe!)\n");
    return 0;
}
