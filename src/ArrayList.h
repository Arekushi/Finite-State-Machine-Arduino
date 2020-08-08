#ifndef ArrayList_h
#define ArrayList_h

template <class T>
class ArrayList {

    private:
        T **data = new T*[0];
        byte length = 0;

    public:
        void addElement(T *element) {
            T **newData = new T*[length+1];

            for(byte i = 0; i < length; i++) {
                newData[i] = data[i];
            }

            newData[length] = element;
            delete[] data;
            data = newData;
            length++;
        }

        byte getLength() {
            return length;
        }

        T **getArray() {
            return data;
        }
};

#endif
