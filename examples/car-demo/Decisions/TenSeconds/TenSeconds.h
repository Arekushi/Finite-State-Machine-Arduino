#ifndef TenSeconds_h
#define TenSeconds_h

#include <Decision.h>
#include <Car.h>

class TenSeconds : public Decision<Car> {
    public:
        bool decision(Car data) override;
};

#endif
