/**
 * Walking Action Class.
 * 
 * Daughter of Action, it is a class with only one method, 
 * responsible for executing a method of our Car object to go forward, 
 * performing the act of walking.
 */

#ifndef Walk_h
#define Walk_h

#include <Action.h>

/// Car Forward Declaration.
class Car;

/// Walk is a Action of type Car
class Walk : public Action<Car> {
    public:

        /// Method for implementing an action for a state.
        void execute(Car data) override;
};

#endif
