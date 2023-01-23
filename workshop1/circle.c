#include <stdio.h>

float radius(float); /* Declare the radius function */

int main()
{
    float A = 23.4;
    float r;

    r = radius(A);
    printf("The area of a circle with radius %f is %f\n", A, r);
    return 0;
}
