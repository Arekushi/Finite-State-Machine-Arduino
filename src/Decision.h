#ifndef Abstract_Decision_h
#define Abstract_Decision_h

#include <Singleton.h>

/**
 * Class referring to an decision to be performed in a Transitions of States.
 * 
 * Abstract class to create Decisions for Transitions.
 * 
 * @tparam T It is the type of our object that has State Machine.
 */
template <class T>
class Decision {

    friend class Singleton<T>;

    public:
        /**
         * Virtual method for performing an decision in a transition.
         * 
         * @param[out] T is our class that has State Machine, 
         *  through it we will be able to access its public methods.
         */
        virtual bool decision(T data);
};

#endif