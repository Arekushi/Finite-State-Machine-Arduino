#ifndef Singleton_h
#define Singleton_h

/**
 * Friend class to achieve a single instance of a class.
 * 
 * @tparam T is the class that we want an instance of.
 */
template <class T>
class Singleton {

    private:
        /**
         * Static pointer of our parameter T.
         */
        static T *instance;

    protected:
        /**
         * Empty Singleton Constructor.
         */
        Singleton() {}

    public:
        /**
         * Get method to get just one instance of our T class.
         * 
         * @return Returns a pointer with the instance of our generic parameter T.
         */
        static T *getInstance() {
            if(instance == nullptr) {
                instance = new T;
            }

            return instance;
        }
};

template<class T>
T *Singleton<T>::instance = nullptr;

#endif
