void linPend(double t, double y[], double fReturn[])
{
    // RHS function
    fReturn[0] = y[1];        // RHS of first equation
    fReturn[1] = -1.0 * y[0]; // RHS of second equations
}
