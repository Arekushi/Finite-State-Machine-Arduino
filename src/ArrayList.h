#ifndef ArrayList_h
#define ArrayList_h

/**
 * Class to create lists with an indefinite size.
 * 
 * @tparam T is the type on our list.
 */
template <class T>
class ArrayList {

    private:
        /**
         * Our generic type array.
         */
        T **data = new T*[0];

        /**
         * Size of our list.
         */
        byte length = 0;

    public:
        /**
         * Responsible method for adding one more element to our list.
         * 
         * @param[out] element is a generic pointer that will be added to the list.
         */
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

        /**
         * Get method for the size of our list.
         * 
         * @return Returns the size of our list.
         */
        byte getLength() {
            return length;
        }

        /**
         * Get method for our generic list.
         * 
         * @return Returns our array of pointers of a generic type.
         */
        T **getArray() {
            return data;
        }
};

#endif
