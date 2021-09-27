#ifndef Abstract_Transition_h
#define Abstract_Transition_h

#include <Monobehavior.h>

template <class T> class State;
template <class T> class Decision;

/**
 * Class referring to transitions between States
 * 
 * Responsible for containing, a decision, and two status for true or false case.
 * 
 * @tparam T It is the type of our object that has State Machine.
 */
template <class T>
class Transition : public Monobehavior {
    
    protected:
        /// Basic decision to which state we will go.
        Decision<T> *decision;

        /// State that we will go to the true case of the decision.
        State<T> *trueState;

        /// State that we will go to the false case of the decision.
        State<T> *falseState;

    public:
        /**
         * Transition Constructor.
         * 
         * Simple builder that asks for what is necessary to exist.
         * 
         * @param[out] decision it is our pointer of decision<T> to make a transition to true or false.
         * @param[out] trueState pointer of state<T> in case the decision returns true.
         * @param[out] falseState pointer of state<T> in case the decision returns false.
         */
        Transition(Decision<T> *decision, State<T> *trueState, State<T> *falseState) : Monobehavior() {
            this->decision = decision;
            this->trueState = trueState;
            this->falseState = falseState;
        }

        Transition(Decision<T> *decision, State<T> *trueState, State<T> *falseState, ArrayList<int> *behaviors) : Monobehavior(behaviors) {
            this->decision = decision;
            this->trueState = trueState;
            this->falseState = falseState;
        }

        /**
         * Get method for decision.
         * 
         * @return Returns a pointer of decision of a generic type.
         */
        Decision<T> *getDecision() {
            return decision;
        }

        /**
         * Get method for true or false state.
         * 
         * @param type It is type about state [true or false].
         * @return Returns a pointer of state of a generic type.
         */
        State<T> *getState(bool type) {
            return type ? trueState : falseState;
        }
};

#endif
