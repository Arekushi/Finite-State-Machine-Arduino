#ifndef Dictionary_h
#define Dictionary_h

#include <Arduino.h>
#include <ArrayList.h>

template<class K, class V>
class Dictionary {
    private:
        ArrayList<K> *m_keys;
        ArrayList<V> *m_values;
        
    public:
        Dictionary() {
            m_keys = new ArrayList<K>();
            m_values = new ArrayList<V>();
        }

        void add(K *key, V *value) {
            m_keys->add(key);
            m_values->add(value);
        }

        V *get(K *key) {
            for(byte i = 0; i < m_values->length(); i++) {
                if(m_keys->data()[i] == key) {
                    return m_values->data()[i];
                }
            }

            return nullptr;
        }

        K **getKeys() {
            return m_keys.data();
        }

        V **getValues() {
            return m_values.data();
        }
};


#endif
