#ifndef Abstract_State_Machine_h
#define Abstract_State_Machine_h

#include <Arduino.h>
#include <Behaviors.h>
#include <ArrayList.h>
#include <Log.h>

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

    public:
        bool log;

        /**
         * State Machine constructor.
         * 
         * @param[out] data is a reference to the instance 
         *  of the object that owns this State Machine.
         * @param[out] initState object's initial state pointer.
         */
        StateMachine(T &data, State<T> *initState, bool log = true) : m_data(data) {
            m_currentBehavior = (int) Behaviors::STANDARD;
            m_currentStateIndex = -1;

            m_checkpoints = new ArrayList<int>();
            m_logs = new ArrayList<Log<T>>();
            this->log = log;

            setCurrentState(initState);
        }

        /**
         * Method for setting a new state for the current state of the object.
         * 
         * @param[out] newState is a pointer from a new state to the current state.
         */
        void setCurrentState(State<T> *newState) {
            exitCurrentState();
            m_currentState = newState;
            enterCurrentState();
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
            m_currentState->executeState(*this);
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

        void changeToReversed() {
            currentBehavior((int) Behaviors::REVERSED);
        }

        void currentBehavior(int behavior) {
            m_previousBehavior = m_currentBehavior;
            m_currentBehavior = behavior;
        }

        int currentBehavior() {
            return m_currentBehavior;
        }

        int previousBehavior() {
            return m_previousBehavior;
        }

        void returnToPreviousBehavior() {
            m_currentBehavior = m_previousBehavior;
        }

        int currentStateIndex() {
            return m_currentStateIndex;
        }

        State<T> *currentState() {
            return m_currentState;
        }

        ArrayList<Log<T>> *logs() {
            return m_logs;
        }

        ArrayList<int> *checkpoints() {
            return m_checkpoints;
        }

        void saveCheckpoint() {
            m_checkpoints->add((int*) currentStateIndex());
        }

        T &data() {
            return m_data;
        }

        bool isReversedBehavior() {
            return currentBehavior() == (int) Behaviors::REVERSED;
        }

        bool arrivedCheckpoint() {
            return (logs()->length() - 1) == reinterpret_cast<int>(checkpoints()->last());
        }

    private:
        /**
         * Pointer of the current state of the object that has State Machine.
         */
        State<T> *m_currentState;

        /**
         * Reference to the instance of the object that owns this State Machine.
         */
        T &m_data;

        int m_currentBehavior;

        int m_previousBehavior;

        int m_currentStateIndex;

        ArrayList<int> *m_checkpoints;

        ArrayList<Log<T>> *m_logs;

        void exitCurrentState() {
            if(m_currentStateIndex > 0) {
                m_currentState->exit(m_data);

                if(log && !isReversedBehavior()) {
                    m_logs->last()->finish(millis());
                }
            }
        }

        void enterCurrentState() {
            if(!m_currentState->hasSetup) {
                m_currentState->setup();
            }
            
            m_currentState->enter(m_data);
            m_currentStateIndex++;

            if(log && !isReversedBehavior()) {
                m_logs->add(
                    new Log<T>(m_currentState, millis())
                );
            }
        }
};

#endif
