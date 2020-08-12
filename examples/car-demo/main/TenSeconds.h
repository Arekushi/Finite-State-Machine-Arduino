/**
 * Decision class for a 10 second case.
 * 
 * Decision Daughter, it is a class with only one method, 
 * which checks at all times giving an answer in a method in Boolean.
 */

#ifndef TenSeconds_h
#define TenSeconds_h

#include <Decision.h>

/// Car Forward Declaration.
class Car;

/// TenSeconds is a Decision of type Car.
class TenSeconds : public Decision<Car> {
    public:

        /**
         * Method to implement a decision, 
         * which will decide which state we will go to.
         */
        bool decision(Car data) override;
};

#endif
