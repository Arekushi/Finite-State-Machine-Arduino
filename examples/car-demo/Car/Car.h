/**
 * Class of our line follower cart.
 * 
 * She is responsible for having our State Machine, 
 * and any other component that is in the cart, such as sensors, engines, etc.
 */

#ifndef Car_h
#define Car_h

#include <Arduino.h>
#include <StateMachine.h>
#include <State.h>

class Car {
    public:
        /// This is an attribute of our class of the same type as our class - Car.
        StateMachine<Car> *machine;

        /**
         * Constructor of Car, in it we must instantiate a variable machine.
         * 
         * @param[out] initState it is the first state of our object.
         */
        Car(State<Car> *initState);

        /// Method to move forward.
        void forward();

        /// Method to stop.
        void stop();
};

#endif
