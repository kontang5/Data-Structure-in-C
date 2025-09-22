#include <stdio.h>
#include <assert.h>
#include "sample.h"

int main() {
    int result = add(2, 3);
    
    assert(result == 5);
    return 0;
}
