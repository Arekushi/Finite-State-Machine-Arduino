#include <Arduino.h>
#include <Forward.h>
#include <Car.h>

Car *car;

void setup() {
    car = new Car(Singleton<Forward>::getInstance());
    Serial.begin(9600);
}

void loop() {
    car->machine->executeMachine();
}
