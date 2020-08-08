#include <Stationary.h>
#include <Car.h>

#include <Stop.h>

void Stationary::enter(Car data) {
    base::enter(data);

    Serial.println("Entering Stationary");
}

void Stationary::exit(Car data) {
    Serial.println("Exiting Stationary");
}

void Stationary::setActions() {
    addAction(Singleton<Stop>::getInstance());
}

void Stationary::setTransitions() {
}
