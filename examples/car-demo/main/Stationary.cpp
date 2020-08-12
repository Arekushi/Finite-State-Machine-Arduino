#include "Stationary.h"
#include "Car.h"

#include "Stop.h"

void Stationary::enter(Car data) {
    /**
     * Enter method of Stationary's father, 
     * very important because with it we can initialize our actions and transitions.
     */
    base::enter(data);

    Serial.println("Entering Stationary");
}

void Stationary::exit(Car data) {
    Serial.println("Exiting Stationary");
}

void Stationary::setActions() {
    /**
     * Here we are adding an action, 
     * and to get an instance of it, we use our friend class Singleton.
     */
    addAction(Singleton<Stop>::getInstance());
}

void Stationary::setTransitions() {
}
