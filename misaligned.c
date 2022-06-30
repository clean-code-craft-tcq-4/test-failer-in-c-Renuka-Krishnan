#include <stdio.h>
#include <assert.h>
#include "misaligned.h"

int printColorMap(void(*ReferenceManualFunPtr)(int,int)) 
{
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) 
    {
        for(j = 0; j < 5; j++) 
        {
            ReferenceManualFunPtr(i,j);
        }
    }
    return i * j;
}

void print(int MajorColorIndex, int MinorColorIndex)
{
    printf("%d | %s | %s\n", MajorColorIndex * 5 + MinorColorIndex+ 1, majorColor[MajorColorIndex], minorColor[MajorColorIndex]);
}

void TestPrintColorMap(int MajorColorIndex, int MinorColorIndex)
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
   // assert(Manual[3].PairNumber == 3);
    assert(strcmp(Manual[3].MajorColor,"White") == 0);
    assert(strcmp(Manual[3].MinorColor,"Green") == 0);
    printf("All is well (maybe!)\n");
    return 0;
}
