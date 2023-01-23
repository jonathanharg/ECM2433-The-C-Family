#include <math.h>

float radius(area) {
    /* Return the radius of a circle with the given area */
    float PI = 3.14159265358979323846;
    float r = sqrt(area/PI);
    return r;
}
