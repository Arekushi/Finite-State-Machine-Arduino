#ifndef Abstract_StateMachine_h
#define Abstract_StateMachine_h

template <class T>
class State;

template<class T>
class StateMachine {

    private:
        State<T> *currentState;
        State<T> *previousState;

    public:
        T &data;

        StateMachine(T &data, State<T> *initState) : data(data) {
            currentState = initState;
            currentState->enter(this->data);
        }

        State<T> *getCurrentState() {
            return currentState;
        }

        State<T> *getPreviousState() {
            return previousState;
        }

        void setCurrentState(State<T> *newState) {
            currentState->exit(data);
            previousState = currentState;
            currentState = newState;
            currentState->enter(data);
        }

        void executeMachine() {
            currentState->executeState(*this);
        }

        void transitionNextState(State<T> *nextState) {
            if(nextState != nullptr) {
                setCurrentState(nextState);
            }
        }
};

#endif
