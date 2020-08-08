#ifndef Abstract_Action_h
#define Abstract_Action_h

#include <Singleton.h>

/**
 * Class referring to an action to be performed in a State.
 * 
 * Abstract class to create Actions for States.
 * 
 * @tparam T It is the type of our object that has State Machine.
 */
template <class T>
class Action {

    friend class Singleton<T>;

    public:
        /**
         * Virtual method for performing an action in a state.
         * 
         * @param[out] T is our class that has State Machine, 
         *  through it we will be able to access its public methods.
         */
        virtual void execute(T data);
};

#endif
