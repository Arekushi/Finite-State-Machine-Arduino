#ifndef Walk_h
#define Walk_h

#include <Action.h>

class Car;

class Walk : public Action<Car> {
    public:
        void execute(Car data) override;
};

#endif
