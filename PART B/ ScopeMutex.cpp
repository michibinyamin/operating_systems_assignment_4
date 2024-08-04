// ScopeMutex.cpp
#include "ScopeMutex.h"

ScopeMutex::ScopeMutex(pthread_mutex_t& mutex) : m_mutex(mutex) {
    pthread_mutex_lock(&m_mutex);
}

ScopeMutex::~ScopeMutex() {
    pthread_mutex_unlock(&m_mutex);
}
