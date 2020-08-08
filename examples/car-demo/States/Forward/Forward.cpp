#include <Forward.h>
#include <Car.h>

#include <Walk.h>
#include <TenSeconds.h>
#include <Stationary.h>

void Forward::enter(Car data) {
    base::enter(data);

    Serial.println("Entering Forward");
}

void Forward::exit(Car data) {
    Serial.println("Exiting Forward");
}

void Forward::setActions() {
    addAction(Singleton<Walk>::getInstance());
}

void Forward::setTransitions() {
    addTransition(new Transition<Car>(
        Singleton<TenSeconds>::getInstance(),
        Singleton<Stationary>::getInstance(),
        nullptr
    ));
}
