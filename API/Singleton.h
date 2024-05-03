#pragma once
#include <iostream>
template <typename T>
class Singleton
{
public:
    static T* getInstance() {
        if (m_pInst == NULL)
            m_pInst = new T;
        return m_pInst;
    }

    static void Destroy() {
        if (m_pInst) {
            delete m_pInst;
            m_pInst = NULL;
        }
    }

protected:
    Singleton() {} 
    ~Singleton(){}
private:
    static T* m_pInst;
};

template <typename T> T* Singleton<T>::m_pInst;