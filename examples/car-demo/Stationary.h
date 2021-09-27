/**
 * Parked state.
 * 
 * Daughter of state, it is a class that gathers and executes actions 
 * and has transitions that are based on decisions to go to other states.
 */

#ifndef Stationary_h
#define Stationary_h

#include <State.h>

/// Car Forward Declaration.
class Car;

/// Stationary is a State of type Car.
class Stationary : public State<Car> {
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
