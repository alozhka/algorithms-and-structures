#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define len 10

int main()
{
    FILE *f;
    int Border, found, pos, result;
    int array[len];

    //coping array
    f = fopen("array.txt", "r");
    if (!f) 
    {
        puts("File is not exists");
        exit(0);
    }
    else
    {
        fscanf(f, "%d", &result);
        for (pos = 0; pos < len; pos++)
        {
            fscanf(f, "%d", &array[pos]);
        }
        fclose(f);
    }

    for(pos = 0; pos < len; pos++)
        printf("%d: %d ", pos, array[pos]);
/*
    Border = 0;
    pos = floor(len / 2);
    while (found == 0 && pos != 0)
    {
        if (array[pos] == result)
        {
            break;
        }

        if (array[pos] < result)
        {
            pos  = pos / 2;
            continue;
        }
        if (result < array[pos])
        {
            pos
        }

    }*/

    return 0;
}