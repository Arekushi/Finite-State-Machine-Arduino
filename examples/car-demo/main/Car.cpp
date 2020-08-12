#include "Car.h"
#include <Arduino.h>

Car::Car(State<Car> *initState) {
    machine = new StateMachine<Car>(*this, initState);
}

void Car::forward() {
    Serial.println("Forward");
}

void Car::stop() {
    Serial.println("Stop");
}
