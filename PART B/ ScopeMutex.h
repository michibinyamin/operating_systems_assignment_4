// ScopeMutex.h
#ifndef SCOPE_MUTEX_H
#define SCOPE_MUTEX_H

#include <pthread.h>

class ScopeMutex {
public:
    explicit ScopeMutex(pthread_mutex_t& mutex);
    ~ScopeMutex();

private:
    pthread_mutex_t& m_mutex;
};

#endif // SCOPE_MUTEX_H
