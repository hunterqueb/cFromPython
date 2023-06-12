#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int length = 10, width = 2;

    int* arr = (int*)malloc(length * width * sizeof(int));

    int i,j;

    for(i=0;i<length;i++)
    {
        for(j=0;j<width;j++)
        {
            *(arr + i*width * j) = i+j;
            printf("%d ", *(arr + i * width * j));
        }
        printf("\n");
    }
    width = width+2;
    arr = (int*)realloc(arr, length * width * sizeof(int));
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < width; j++)
        {
            *(arr + i * width * ) = i + j;
            printf("%d ", *(arr + i * width * j));
        }
        printf("\n");
    }

    free(arr);
    return 0;
}