#include <stdio.h>
#include <stdlib.h>
#include "cTestLib.h"

double cmult(int int_param, double float_param)
{
    float return_value = int_param * float_param;
    printf("in cmult: int %d float %.1lf returning %.1lf\n",int_param,float_param,return_value);
    return return_value;
}

void c_speed(void)
{
    int i; int j;
    for(i = 0;i<10000;i++)
    {
        for(j=0;j<10000;j++)
        {

        }
    }
    printf("done");
    return;
}

void changeByRef(int *a)
{
    *a = 14;
    return;
}

void print1dArray(int *array)
{
    // when taking a numpy array in from python, you MUST be careful with array out of bounds, memory for array
    // is maybe not contiguous? / array can access greatly outside the bounds of the array
    
    int i;
    for(i=0;i<20;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}

void print2dArray(int *array,int N)
{
    // 2d arrays from numpy are represented as a single array, this WILL
    // cause problems when you go to implement
    // indexing goes down rows first
    N = (N * N);
    int i;
    for(i = 0;i<N;i++)
    {
        printf(" %d",array[i]);
    }
}

void returnByRefArray(int *array,int N)
{
    N = N * N;
    int i;
    for(i=0;i<N;i++)
    {
        array[i] = array[i] * N;
    }
}

// returning arrays are not possible, even trying to get this from python is hard
// this is an example of what not to do
// to store memory pass the array by reference and modify in script, have the function return as void
// this means that the memory to be passed to a function like rk45 needs to be dynamic...

double *createArray(void)
{
    double *arr = malloc(10*sizeof(double));

    for(int i = 0;i<10;i++)
    {
        arr[i] = i;
    }
    return arr;
}