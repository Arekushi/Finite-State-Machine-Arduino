#ifndef Abstract_Action_h
#define Abstract_Action_h

#include <Singleton.h>

template <class T>
class Action {

    friend class Singleton<T>;

    public:
        virtual void execute(T data);
};

#endif
