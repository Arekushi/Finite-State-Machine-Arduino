/**
 * This is a State Machine model for Arduino projects,
 * designed for line followers in robotics competitions.
 * 
 * By: @Arekushi (Alexandre Ferreira)
 * Github: https://github.com/Arekushi
 * LinkedIn: https://www.linkedin.com/in/alex-ferreira/
 * 
 * This is a practical and simple example of how to use this model.
 * Able to control the states of anything, in our case, a line-following cart.
 * For more details, see: https://arekushi.github.io/Finite-State-Machine-Arduino/
 */

/**
 * Include a Initial State
 * Include a car
 */

#include <Forward.h>
#include <Car.h>

Car *car;

void setup() {

    /**
     * Here we created a car passing as reference our 
     * initial State using the friendly class Singleton.
     * 
     * We call Singleton, give our class as a generic parameter, 
     * and use the static method getInstance().
     */

    car = new Car(Singleton<Forward>::getInstance());
    Serial.begin(9600);
}

void loop() {
    /// We started the State Machine.
    car->machine->executeMachine();
}
