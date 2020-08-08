/**
 * State of going forward
 * 
 * Daughter of state, it is a class that gathers and executes actions 
 * and has transitions that are based on decisions to go to other states.
 */

#ifndef Forward_h
#define Forward_h

#include <State.h>

/// Car Forward Declaration.
class Car;

/// Forward is a State of type Car.
class Forward : public State<Car> {
    public:

        /// Method triggered when entering state.
        void enter(Car data) override;

        /// Method triggered when exiting state.
        void exit(Car data) override;

        /// Method for adding our actions.
        void setActions() override;

        /// Method for adding transitions.
        void setTransitions() override;
};

#endif
