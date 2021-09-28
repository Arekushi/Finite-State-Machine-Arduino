#ifndef Log_h
#define Log_h

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
        }

        void finish(unsigned long ended) {
            this->ended = ended;
            this->time = this->ended - this->started;
        }
    
    private:
        unsigned long started;
        unsigned long ended;
};

#endif
