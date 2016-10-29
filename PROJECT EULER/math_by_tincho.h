
#include <iostream>

//Constants///////////////////
#define MLG_PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286 //
#define MLG_Euler 2.71828182846 //
//////////////////////////////

//Gives the nth power of a number
long double MLG_wholePower(long double base, long double exponent = 1)
{
    long double value = base;
    for (int i = exponent-1; i > 0; i--)
    {
        value *= base;
    }
    return value;
}

//Converts radians to degrees
long double MLG_radToDeg(long double rad)
{
    rad = rad*180/MLG_PI;
    return rad;
}

//Converts degrees to radians
long double MLG_degToRad(long double deg)
{
    deg = deg*MLG_PI/180;
    return deg;
}

//Factorial of a whole number
long double MLG_factorial(long double number)
{
    for (unsigned long long int i = number-1; i > 1; i--)
    {
        number *= i;
    }
    return number;
}

//Calculate the square root of a number using Newtons Method
long double MLG_sqrt(long double number)
{
    long double originalValue = number;
    for (unsigned long int i = 0; i < number; i++)
    {
        number = 0.5*(number+(originalValue/number));
    }
    return number;
}

//Calculate the nth root of a number using Newtons Method
long double MLG_root(long double number, long double rt)
{
    long double originalValue = number;
    for (unsigned long int i = 0; i < number*rt*rt; i++)
    {
        number = (1/rt)*((rt-1)*number + (originalValue/MLG_wholePower(number, (rt-1))));
    }
    return number;
}

//Solves a quadratic equation, returing by default the "plus" anwser
long double MLG_quadraticFormula(long double a, long double b, long double c, int anwser = 0)
{
    if ((MLG_wholePower(b, 2) - (4*a*c)) < 0)
    {
        return 0;
    }
    else
    {
        long double term1 = b*(-1);
        long double term2 = MLG_sqrt(MLG_wholePower(b, 2) - (4*a*c));
        long double term3 = 2*a;
        switch (anwser)
        {
            case 0:
                return ((term1+term2)/term3);
                break;
            case 1:
                return ((term1-term2)/term3);
                break;
        }
    }
}

//Gives the nth fibonacci number, starting at 0th = 0, 1st = 1, 2nd = 1, 3rd = 2, etc. using The Explicit formula
unsigned long long int MLG_fibonacciNumber(unsigned long long int number)
{
    if (number == 1)
    {
        return 1;
    }
    else
    {
        long double phi = (1+MLG_sqrt(5))/2;
        long double term1 = MLG_wholePower(phi, number);
        long double term2 = MLG_wholePower((-(1/phi)),number);
        long double term3 = MLG_sqrt(5);
        unsigned long long int result = (term1-term2)/term3;
        return result;
    }
}

long double MLG_sin_radian(long double angle)
{
    long double result = 0;
    for (int i = 0; i < 700; i++)
    {
        switch (i % 2)
        {
            case 0:
                result += (MLG_wholePower(angle, (i*2+1)))/(MLG_factorial((i*2+1)));
                break;
            case 1:
                result -= (MLG_wholePower(angle, (i*2+1)))/(MLG_factorial((i*2+1)));
                break;
        }
    }
    return result;
}

unsigned long long int MLG_ncr(unsigned long long int row, unsigned long long int term)
{
    return (MLG_factorial(row)/(MLG_factorial(row-term)*MLG_factorial(term)));
}

long double MLG_sin_degree(long double angle)
{
    return MLG_sin_radian(MLG_degToRad(angle));
}

long double MLG_cos_radian(long double angle)
{
    return (MLG_sin_radian(angle+MLG_PI/2));
}

long double MLG_cos_degree(long double angle)
{
    return MLG_cos_radian(MLG_degToRad(angle));
}

long double MLG_tan_radian(long double angle)
{
    return (MLG_sin_radian(angle)/MLG_cos_radian(angle));
}

long double MLG_tan_degree(long double angle)
{
    return (MLG_sin_degree(angle)/MLG_cos_degree(angle));
}


