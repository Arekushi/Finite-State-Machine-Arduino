#ifndef Abstract_Transition_h
#define Abstract_Transition_h

template <class T> class State;
template <class T> class Decision;

template <class T>
class Transition {
    
    protected:
        Decision<T> *decision;
        State<T> *trueState;
        State<T> *falseState;

    public:
        Transition(Decision<T> *decision, State<T> *trueState, State<T> *falseState) {
            this->decision = decision;
            this->trueState = trueState;
            this->falseState = falseState;
        }

        Decision<T> *getDecision() {
            return decision;
        }

        State<T> *getTrueState() {
            return trueState;
        }

        State<T> *getFalseState() {
            return falseState;
        }
};

#endif
