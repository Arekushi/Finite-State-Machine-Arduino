#include "Forward.h"
#include "Car.h"

#include "Walk.h"
#include "TenSeconds.h"
#include "Stationary.h"

void Forward::enter(Car data) {
    /**
     * Enter method of Forward's father, 
     * very important because with it we can initialize our actions and transitions.
     */
    base::enter(data);

    Serial.println("Entering Forward");
}

void Forward::exit(Car data) {
    Serial.println("Exiting Forward");
}

void Forward::setActions() {
    /**
     * Here we are adding an action, 
     * and to get an instance of it, we use our friend class Singleton.
     */
    addAction(Singleton<Walk>::getInstance());
}

void Forward::setTransitions() {
    /**
     * Here we are creating a Transition instance, 
     * and to create an object of type Transition, we need to give as an argument:
     * A decision
     * A state for true case
     * A state for false case
     * 
     * If you want to remain in the same state, give a null pointer as a value - nullptr.
     * 
     * In this case, the TenSeconds decision, 
     * after 10 seconds it will go to the Stationary state, 
     * if the decision returns true, if it is false, it will remain in Forward.
     */
    addTransition(new Transition<Car>(
        Singleton<TenSeconds>::getInstance(),
        Singleton<Stationary>::getInstance(),
        nullptr
    ));
}
