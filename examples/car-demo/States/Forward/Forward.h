#ifndef Forward_h
#define Forward_h

#include <State.h>

class Car;

class Forward : public State<Car> {
    public:
        void enter(Car data) override;
        void exit(Car data) override;
        void setActions() override;
        void setTransitions() override;
};

#endif
