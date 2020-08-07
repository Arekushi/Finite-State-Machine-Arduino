#ifndef Abstract_Decision_h
#define Abstract_Decision_h

#include <Singleton.h>

template <class T>
class Decision {

    friend class Singleton<T>;

    public:
        virtual bool decision(T data);
};

#endif