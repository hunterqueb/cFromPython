// rk45.c: Solve ordinary differential equations of the Runge-Kutta-Fehlberg Method with
// variations in step size.
// taken from github repo HussainAther/C
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void f(double t, double y[], double fReturn[])
{
    // RHS function
    fReturn[0] = y[1];                // RHS of first equation
    fReturn[1] = -2.0 * y[0]; // RHS of second equations
    fReturn[2] = y[3];
    fReturn[3] = -2 * y[2];
}

void out2File(double t, double y[], int problemDim, FILE *fp)
{
    int i;
    fprintf(fp, "%f\t", t);
    for (i = 0; i < problemDim; i++)
    {
        fprintf(fp, "%f\t", y[i]);
    }
    fprintf(fp, "\n");
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

void rk45(void func(double, double[], double[]), double *IC, double a, double b, int problemDim, double Tol,double *sol)
{
    double Tol = 1.0E-8; // error control tolerance

    int currentArrayLength = 50;

    int problemDim = 4;

    double *sol = (double *)malloc(currentArrayLength * problemDim * sizeof(double));
    int row = 0, col = 0;

    // time length, tolerance
    double a = 0;        // endpoints in calculation
    double b = 10;

    // utility variable definitions
    double h, t, s, s1, hmin, hmax;
    double k1[problemDim], k2[problemDim], k3[problemDim];
    double k4[problemDim], k5[problemDim], k6[problemDim];
    double err[problemDim];
    int i, j, n = 1000;

    // initializing function and initial conditions
    double y[problemDim], fReturn[problemDim], ydumb[problemDim];
    y[0] = 1;
    y[1] = 0;
    y[2] = -1;
    y[3] = 0;
    // time things - steps min and max, as well as starting time
    h = (b - a) / n;
    hmin = h / 64;
    hmax = h * 64;
    t = a;
    j = 0;

    while (t < b)
    {
        row++;
        if ((t + h) > b)
            h = b - t; // last step

        func(t, y, fReturn);

        for (i = 0; i < problemDim; i++)
        {
            k1[i] = h * fReturn[i];
            ydumb[i] = y[i] + k1[i] / 4;
        }

        func(t + h / 4, ydumb, fReturn);

        for (i = 0; i < problemDim; i++)
        {
            k2[i] = h * fReturn[i];
            ydumb[i] = y[i] + 3 * k1[i] / 32 + 9 * k2[i] / 32;
        }

        func(t + 3 * h / 8, ydumb, fReturn);

        for (i = 0; i < problemDim; i++)
        {
            k3[i] = h * fReturn[i];
            ydumb[i] = y[i] + 1932 * k1[i] / 2197 - 7200 * k2[i] / 2197 + 7296 * k3[i] / 2197;
        }

        func(t + 12 * h / 13, ydumb, fReturn);
        
        for (i = 0; i < problemDim; i++)
        {
            k4[i] = h * fReturn[i];
            ydumb[i] = y[i] + 439 * k1[i] / 216 - 8 * k2[i] + 3680 * k3[i] / 513 - 845 * k4[i] / 4104;
        }

        func(t + h, ydumb, fReturn);

        for (i = 0; i < problemDim; i++)
        {
            k5[i] = h * fReturn[i];
            ydumb[i] = y[i] - 8 * k1[i] / 27 - 2 * k2[i] - 3544 * k3[i] / 2565 + 1859 * k4[i] / 4104 - 11 * k5[i] / 40;
        }

        func(t + h / 2, ydumb, fReturn);

        for (i = 0; i < problemDim; i++)
        {
            k6[0] = h * fReturn[0];
            err[i] = fabs(k1[i] / 360 - 128 * k3[i] / 4275 - 2197 * k4[i] / 75240 - k5[i] / 50 + 2 * k6[i] / 55);
            y[i] = y[i] + 25 * k1[i] / 216 + 1408 * k3[i] / 2565 + 2197 * k4[i] / 4104 - k5[i] / 5;
        }

        t = t + h;
        j++;

        if ((err[0] == 0) || (err[1] == 0))
            s = 0; // trap division by zero
        else
            s = .84 * pow(Tol * h / err[0], .25); // step size scalar
        if ((s < .75) && (h > 2 * hmin))
            h /= 2; // reduce step
        else if ((s > 1.5) && (2 * h < hmax))
            h *= 2;                                   // increase step
        
        // check to see if you need to dynamically allocate new array space
        if (row == currentArrayLength)
        {
            currentArrayLength = (int) currentArrayLength * 1.5;
            sol = (double *)realloc(sol,currentArrayLength * problemDim * sizeof(double));
        }


        // end of a loop, here is where you would report the variables
        for (i = 0; i < problemDim; i++)
        {
            sol[row * problemDim + i] = y[i];
        }
        out2Term(t, y, problemDim);
    }
    
    free(sol);
    return 0;
}
