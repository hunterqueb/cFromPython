#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void f(double t, double y[], double fReturn[])
{
    // RHS function
    fReturn[0] = y[1];                // RHS of first equation
    fReturn[1] = -1.0 * y[0]; // RHS of second equations
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

void rk4(void func(double, double[] ,double[]), double IC[], double a, double b, double h, int problemDim)
{
    double t = 0; int i;

    double y[problemDim], fReturn[problemDim], yy[problemDim];

    for (i = 0;i<problemDim;i++)
        y[i] = IC[i];

    out2Term(t,y,problemDim);
    while (t < b)
    {
        double k1[problemDim], k2[problemDim], k3[problemDim], k4[problemDim];

        func(t,y,fReturn);
        for (i = 0; i < problemDim; i++)
        {
            k1[i] = h * fReturn[i];

            //update variables for next eval step
            yy[i] = y[i] + 0.5 * k1[i];
        }

        func(t + 0.5 * h, yy, fReturn);
        for (i = 0; i < problemDim; i++)
        {
            k2[i] = h * fReturn[i];
            yy[i] = (y[i] + 0.5 * k2[i]);
        }
        
        func((t+0.5*h),yy,fReturn);
        for (i = 0; i < problemDim; i++)
        {
            k3[i] = h * fReturn[i];
            yy[i] = y[i] + k3[i];
        }

        
        func((t+h),yy,fReturn);
        for (i = 0; i < problemDim; i++)
        {
            k4[i] = h * fReturn[i];
            y[i] = y[i] + (k1[i]+2*k2[i]+2*k3[i]+k4[i])/6;
        }
        
        out2Term(t,y,problemDim);
        t = t + h;
    }
}


int main(void)
{
    int problemDim = 2;
    double a = 0;
    double b = 6.3;
    double h = 0.1;

    int numSteps = b/h;

    double y[problemDim];
    y[0] = 1;
    y[1] = 0;

    // how do i get a returned array?
    // i think i should pass a long 1d array to this, so that numpy arrays can access it straight from python
    rk4(f,y,a,b,h,problemDim);

    return 0;
}