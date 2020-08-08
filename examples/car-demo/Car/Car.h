#ifndef Car_h
#define Car_h

#include <Arduino.h>
#include <StateMachine.h>
#include <State.h>

class Car {
    public:
        byte velocity;
        char *name;
        StateMachine<Car> *machine;

        Car(State<Car> *initState);
        void forward();
        void stop();
};

#endif
