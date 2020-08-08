#ifndef Stationary_h
#define Stationary_h

#include <State.h>

class Car;

class Stationary : public State<Car> {
    public:
        void enter(Car data) override;
        void exit(Car data) override;
        void setActions() override;
        void setTransitions() override;
};

#endif
