#include <Walk.h>
#include <Car.h>
#include <Arduino.h>

void Walk::execute(Car data) {
    data.forward();
}
