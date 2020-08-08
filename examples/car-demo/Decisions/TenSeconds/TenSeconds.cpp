#include <TenSeconds.h>

bool TenSeconds::decision(Car data) {
    
    /**
     * This is a check that returns a Boolean value, whether true or false, 
     * the State Machine will modify the State of the object.
     */

    return millis() >= 10000;
}
