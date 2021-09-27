/**
 * Stoping Action Class.
 * 
 * Daughter of Action, it is a class with only one method, 
 * responsible for executing a method of our Car object to stop.
 */

#ifndef Stop_h
#define Stop_h

#include <Action.h>

/// Car Forward Declaration.
class Car;

/// Stop is a Action of type Car
class Stop : public Action<Car> {
    public:

        /// Method for implementing an action for a state.
        void execute(Car data) override;
};

#endif
