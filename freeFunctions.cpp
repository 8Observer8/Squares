
#include <cstdlib>
#include "freeFunctions.h"

double random( int y1, int y2 )
{
    // y = kx + b, y[y1, y2], x[0, 1]
    double x, y;
    int k, b;

    // Point: x = 0, y = y1
    b = y1;

    // Point: x = 1, y = y2
    k = y2 - b;

    x = ( double ) std::rand() / ( RAND_MAX+1.0 );

    y = ( double ) k * x + ( double ) b;

    return y;
}
