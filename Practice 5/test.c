#include <assert.h>
#include <stdio.h>
#include "bisection.h"

int bisect_test() {
    float x, y;

    // Test case 1: Lines intersect
    assert(bisection(1, 1, -1, 1, &x, &y) == 1); 
    assert(x == 0); 
    assert(y == 1);

    // Test case 2: Lines are parallel (no intersection)
    assert(bisection(1, 1, 1, 2, &x, &y) == 0); 

    // Test case 3: Lines are the same (infinite intersections)
    assert(bisection(1, 1, 1, 1, &x, &y) == -1); 

    // Test case 4: Another intersection case
    assert(bisection(2, 2, -1, 1, &x, &y) == 1); 
    assert(x == 0);
    assert(y == 2); 

    printf("All tests passed!\n");

    return 0;
}