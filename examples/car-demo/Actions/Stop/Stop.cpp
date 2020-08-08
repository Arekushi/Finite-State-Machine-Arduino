#include <Stop.h>
#include <Car.h>

void Stop::execute(Car data) {
    
    /**
     * This is an action, if it is linked to a state, it will always run.
     * 
     * As data is a reference to our car, we can use a method of it.
     */
    data.stop();
}
