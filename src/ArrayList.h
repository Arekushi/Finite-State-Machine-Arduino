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
        T **m_data = new T*[0];

        /**
         * Size of our list.
         */
        byte m_length = 0;

    public:
        ArrayList() { }

        ArrayList(T *elements[], byte size) {
            for(byte i = 0; i < size; i++) {
                add(elements[i]);
            }
        }

        /**
         * Responsible method for adding one more element to our list.
         * 
         * @param[out] element is a generic pointer that will be added to the list.
         */
        void add(T *element) {
            T **newData = new T*[m_length + 1];

            for(byte i = 0; i < m_length; i++) {
                newData[i] = m_data[i];
            }

            newData[m_length] = element;
            delete[] m_data;
            m_data = newData;
            m_length++;
        }

        void remove(int *behavior) { }

        /**
         * Get method for the size of our list.
         * 
         * @return Returns the size of our list.
         */
        byte length() {
            return m_length;
        }

        /**
         * Get method for our generic list.
         * 
         * @return Returns our array of pointers of a generic type.
         */
        T **data() {
            return m_data;
        }

        /**
         * Clear our list.
         */
        void clear() {
            delete[] m_data;
            m_data = new T*[0];
            m_length = 0;
        }

        byte indexOf(T *element) {
            for(byte i = 0; i < m_length; i++) {
                if(m_data[i] == element) {
                    return i;
                }
            }

            return -1;
        }

        bool has(T *element) {
            for(byte i = 0; i < m_length; i++) {
                if(m_data[i] == element) {
                    return true;
                }
            }

            return false;
        }

        bool any() {
            return m_length > 0;
        }

        bool isEmpty() {
            return m_length == 0;
        }
};

#endif
