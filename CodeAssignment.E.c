#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "listSearcher.h"

static int findMaxInteger(int list[], int startingIndex, int numbrOfEntries);

void searchIntegerList(int list[], int nbrOfListEntries, int childrenCount)
{
    int baseSize = nbrOfListEntries / childrenCount;
    int remainder = nbrOfListEntries % childrenCount;
    int startIndex = 0; 

    for (int i 0; i < childrenCount; i++)
    {
        int count = baseSize;
        if (i == childrenCount - 1)
        count += remainder;

        pid_t pid = fork();
        if (pid < 0)
        {
            perror("fork failed");
            exit(1);
        }
        else if (pid == 0)
        {
            int localMax = findMaxInteger(list, startIndex, count);
            printf("\n Child process \n", getpid(), startIndex, startIndex + count - 1, localMax);

            exit(localMax);
        }

        startIndex += count;
    }
}

static int findMaxInteger (int list[], int startingIndex, int nbrOfEntries)
{
    int maxValue = list[startingIndex];
    for(int 1 = startingIndex + 1; i < startingIndex + nbrOfEntries; i++)
    {
        if(list[i] > maxValue)
            maxValue = list[i];
    }
    return maxValue;
}