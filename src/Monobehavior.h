#ifndef Monobehavior_h
#define Monobehavior_h

#include <ArrayList.h>

class Monobehavior {
    public:
        ArrayList<int> *behaviors;

        Monobehavior() {
            this->behaviors = new ArrayList<int>();
        }

        Monobehavior(ArrayList<int> *behaviors) {
            this->behaviors = behaviors;
        }

        void addBehavior(int *behavior) {
            this->behaviors->add(behavior);
        }

        void removeBehavior(int *behavior) {
            this->behaviors->remove(behavior);
        }
};

#endif
