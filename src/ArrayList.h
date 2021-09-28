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

        T *pop() {
            m_length--;

            T **newData = new T*[m_length];
            T *lastItem = m_data[m_length];

            for(byte i = 0; i < m_length; i++) {
                newData[i] = m_data[i];
            }

            delete[] m_data;
            m_data = newData;
            return lastItem;
        }

        T *shift() {
            m_length--;

            T **newData = new T*[m_length];
            T *firstItem = m_data[0];

            for(byte i = 1; i <= m_length; i++) {
                newData[i] = m_data[i];
            }

            delete[] m_data;
            m_data = newData;
            return firstItem;
        }

        bool remove(int *element) {
            byte index = indexOf(element);

            if (index != -1) {
                T **newData = new T*[m_length - 1];

                byte count = 0;
                for(byte i = 0; i < m_length; i++) {
                    if(i != index) {
                        newData[count] = m_data[i];
                    }

                    count++;
                }

                delete[] m_data;
                m_data = newData;
                m_length--;
                return true;
            }

            return false;
        }

        bool slice(int start, int end) {
            if(end > start) {
                int length = start + end;
                T **newData = new T*[length];

                int count = 0;
                for(byte i = start; i < end; i++) {
                    newData[count] = m_data[i];
                    count++;
                }

                delete[] m_data;
                m_data = newData;
                m_length = length;
                return true;
            }

            return false;
        }

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

        bool empty() {
            return m_length == 0;
        }

        T *first() {
            return m_data[0];
        }

        T *last() {
            return m_data[m_length - 1];
        }
};

#endif
