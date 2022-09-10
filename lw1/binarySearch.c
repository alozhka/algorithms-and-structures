#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//len отвечает за длину и известен заранее
#define len 10

int main()
{
    FILE *f;
    int lBorder, rBorder, found, pos, result;
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

    /*for(pos = 0; pos < len; pos++)
        printf("%d: %d ", pos, array[pos]);*/

    //finding equals result
    found = 0;
    lBorder = 0;
    rBorder = len - 1;
    pos = floor(len / 2);
    while(pos != 0)
    {
        //printf("lB %d, rB %d, pos %d\n", lBorder, rBorder, pos);
        if(array[pos] == result)
        {
            found = pos;
            break;
        }
        if(result < array[pos])
        {
            rBorder = pos;
            pos = floor((lBorder + rBorder) / 2);
            continue;
        }
        if(array[pos] < result)
        {
            lBorder = pos;
            pos = floor((lBorder + rBorder) / 2);
            continue;
        }
    }

    if(found == 0)
        printf("%d was not found\n", result);
    else
        printf("%d has %d position\n", result, found + 1);

    return 0;
}