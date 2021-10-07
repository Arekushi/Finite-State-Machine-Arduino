#ifndef Abstract_State_h
#define Abstract_State_h

#include <Arduino.h>
#include <Action.h>
#include <Transition.h>
#include <Decision.h>
#include <StateMachine.h>
#include <Singleton.h>
#include <ArrayList.h>

/**
 * Class referring to a state of an object. 
 * 
 * Abstract class, to create States for a given object,
 * having a set of actions and transitions itself.
 * 
 * @tparam T It is the type of our object that has State Machine.
 */
template <class T>
class State {

    friend class Singleton<T>;

    protected:
        using base = State;

        /**
         * ArrayList of actions that this state has.
         */
        ArrayList<Action<T>> *actions;

        /**
         * ArrayList of transitions that this state has.
         */
        ArrayList<Transition<T>> *transitions;

    public:
        /**
         * Boolean to verify that this state has already 
         * been configured with its actions and transitions.
         */
        bool hasSetup;

        /**
         * Char array referring to the name of our state.
         */
        const char *name;

        State<T> *opposite;

        /**
         * State Constructor
         * 
         * @param[out] name is a char array assigned to the state name.
         */
        State(const char *name) : name(name) {
            hasSetup = false;
            actions = new ArrayList<Action<T>>();
            transitions = new ArrayList<Transition<T>>();
        }

        /**
         * State Constructor
         */
        State() {
            hasSetup = false;
            actions = new ArrayList<Action<T>>();
            transitions = new ArrayList<Transition<T>>();
        }

        /**
         * Method for configuring actions and transitions.
         */
        void setup() {
            hasSetup = true;
            setTransitions();
            setActions();
        }

        /**
         * Method for adding actions of a type to our state, 
         * so that it can be run when it is the current state.
         * 
         * @param[out] pointer of an action<T> to be added to a state.
         */
        void addAction(Action<T> *action) {
            actions->add(action);
        }

        /**
         * Method for adding transitions to a state, so that, 
         * when it is the current state, we rotate the state transitions.
         * 
         * @param[out] pointer of an transition<T> to be added to a state.
         */
        void addTransition(Transition<T> *transition) {
            transitions->add(transition);
        }

        /**
         * Method to perform all actions that the state has.
         * 
         * @param[out] machine It is a reference to the State Machine<T>.
         */
        void executeAction(StateMachine<T> &machine) {
            Action<T> **array = actions->data();

            for(byte i = 0; i < actions->length(); i++) {
                array[i]->execute(machine.data());
            }
        }

        /**
         * Method to verify the decision of the transition and from that, 
         * to make a change of state for true case and 
         * for case the result of the decision is false.
         * 
         * @param[out] machine It is a reference to the State Machine<T>.
         */
        void checkTransitions(StateMachine<T> &machine) {
            Transition<T> **array = transitions->data();

            for(byte i = 0; i < transitions->length(); i++) {
                if(isCurrentBehavior(array[i], machine)) {
                    const bool result = array[i]->getDecision()->decision(machine.data());
                    machine.transitionNextState(array[i]->getState(result));
                }
            }
        }

        void undo(StateMachine<T> &machine) {
            if(!machine.arrivedCheckpoint()) {
                Log<T> *log = machine.logs()->last();

                if(millis() >= log->transitionTime()) {
                    machine.logs()->pop();
                    machine.transitionNextState(log->getOppositeState());
                }
            } else {
                machine.checkpoints()->pop();
                machine.returnToPreviousBehavior();
            }
        }

        /**
         * Method that calls the actions and transitions methods of a state, 
         * to execute when that state is the current state.
         * 
         * @see executeAction
         * @see checkTransitions
         * @param[out] machine It is a reference to the State Machine<T>.
         */
        void executeState(StateMachine<T> &machine) {
            executeAction(machine);

            if(!machine.isReversedBehavior()) {
                checkTransitions(machine);
            } else {
                undo(machine);
            }
        }

        /**
         * Virtual method for when he enters this state, perform specific actions for him.
         */
        virtual void enter(T data) = 0;

        /**
         * Virtual method for when he exits this state, perform specific actions for him.
         */
        virtual void exit(T data) = 0;

        /**
         * Virtual method for setting state actions.
         */
        virtual void setActions() = 0;

        /**
         * Virtual method for setting state transitions.
         */
        virtual void setTransitions() = 0;

    private:
        bool isCurrentBehavior(Transition<T> *transition, StateMachine<T> &machine) {
            return transition->behaviors->has((int*) machine.currentBehavior());
        }
};

#endif
