#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void f(double t, double y[], double fReturn[])
{
    // RHS function
    fReturn[0] = y[1];                // RHS of first equation
    fReturn[1] = -2.0 * y[0]; // RHS of second equations
}

void out2Term(double t, double y[], int problemDim)
{
    int i;
    printf("%f\t", t);
    for (i = 0; i < problemDim; i++)
    {
        printf("%f\t", y[i]);
    }
    printf("\n");
}

void rk4(double f(double t, double y[],double fReturn[]), double IC[], double a, double b, double h)
{
    double t = 0;

    problemDim = sizeof(IC) / sizeof(IC[0])

    double fReturn[problemDim], yy[problemDim];

    out2Term(t,y,problemDim)
    while (t < b)
    {
        double k1[problemDim], k2[problemDim], k3[problemDim], k4[problemDim];

        f(t,y,fReturn);
        for (i = 0; i < problemDim; i++)
        {
            k1[i] = h * fReturn[i];

            //update variables for next eval step
            yy[i] = y[i] + 0.5 * k1[i]
        }

        f(t + 0.5 * h, yy, fReturn);
        for (i = 0; i < problemDim; i++)
        {
            k2[i] = h * fReturn[i];
            yy[i] = (y[i] + 0.5 * k2[i])
        }
        
        f((t+0.5*h),yy,fReturn);
        for (i = 0; i < problemDim; i++)
        {
            k3[i] = h * fReturn[i];
            yy[i] = y[i] + k3[i];
        }

        
        f((t+h),yy,fReturn);
        for (i = 0; i < problemDim; i++)
        {
            k4[i] = h * fReturn[i];
            y[i] = y[i] + (k1[i]+2*k2[i]+2*k3[i]+k4[i])/6
        }
        
        out2Term(t,y,problemDim)
        t = t + h;
    }
}


int main(void)
{
    int problemDim = 2;
    double a = 0;
    double b = 5;
    double h = 0.01;

    double y[problemDim];
    y[0] = 1;
    y[1] = 0;

    rk4(f,t,y,a,b,h);

    return 0;
}