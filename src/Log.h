#ifndef Log_h
#define Log_h

#include <Arduino.h>

template <class T>
class State;

template <class T>
class Log {

    public:
        State<T> *state;
        unsigned long time;

        Log(State<T> *state, unsigned long started) {
            this->state = state;
            this->started = started;
            this->m_transitionTime = 0;
        }

        void finish(unsigned long ended) {
            this->ended = ended;
            this->time = this->ended - this->started;
        }

        State<T> *getOppositeState() {
            return this->state->opposite == nullptr ?
                this->state : this->state->opposite;
        }

        unsigned long transitionTime() {
            if(m_transitionTime == 0) {
                m_transitionTime = millis() + time;
            }

            return m_transitionTime;
        }
    
    private:
        unsigned long started;
        unsigned long ended;
        unsigned long m_transitionTime;
};

#endif
