#ifndef Abstract_StateMachine_h
#define Abstract_StateMachine_h

template <class T>
class State;

/**
 * Controlling class of our states.
 * 
 * Responsible for executing the current state of an object and executing the transitions.
 * 
 * @tparam T It is the type of our object that has State Machine.
 */
template<class T>
class StateMachine {

    private:
        /**
         * Pointer of the current state of the object that has State Machine.
         */
        State<T> *currentState;

        //State<T> *previousState;

    public:
        /**
         * Reference to the instance of the object that owns this State Machine.
         */
        T &data;

        /**
         * State Machine constructor.
         * 
         * @param[out] data is a reference to the instance 
         *  of the object that owns this State Machine.
         * @param[out] initState object's initial state pointer.
         */
        StateMachine(T &data, State<T> *initState) : data(data) {
            currentState = initState;
            currentState->enter(this->data);
        }

        /**
         * Get method for the current state of the object.
         * 
         * @return Returns the pointer of the object's current state.
         */
        State<T> *getCurrentState() {
            return currentState;
        }

        /*State<T> *getPreviousState() {
            return previousState;
        }*/

        /**
         * Method for setting a new state for the current state of the object.
         * 
         * @param[out] newState is a pointer from a new state to the current state.
         */
        void setCurrentState(State<T> *newState) {
            currentState->exit(data);
            //previousState = currentState;
            currentState = newState;
            currentState->enter(data);
        }

        /**
         * Method to start the State Machine, 
         * must be executed in a loop, 
         * in the case of Arduino, the loop method.
         * Executes the current state.
         * 
         * @see executeState
         */
        void executeMachine() {
            currentState->executeState(*this);
        }

        /**
         * Method to move from one state to another.
         * 
         * @see setCurrentState
         * @param[out] nextState isa pointer to a new state to replace the current state.
         */
        void transitionNextState(State<T> *nextState) {
            if(nextState != nullptr) {
                setCurrentState(nextState);
            }
        }
};

#endif
