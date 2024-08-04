// Singleton.cpp
#include "Singleton.h"
#include <stdexcept>

pthread_mutex_t SingletonBase::mutex = PTHREAD_MUTEX_INITIALIZER;
SingletonBase* SingletonBase::instance = nullptr;

SingletonBase::SingletonBase() {
    // Constructor code here
}

SingletonBase::~SingletonBase() {
    // Destructor code here
}

SingletonBase* SingletonBase::getInstance() {
    pthread_mutex_lock(&mutex);
    if (instance == nullptr) {
        initializeInstance();
    }
    pthread_mutex_unlock(&mutex);
    return instance;
}

void SingletonBase::initializeInstance() {
    if (instance == nullptr) {
        instance = new SingletonBase();
    }
}

void SingletonBase::destroyInstance() {
    delete instance;
    instance = nullptr;
}
