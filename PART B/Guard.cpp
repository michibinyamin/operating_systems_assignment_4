#include <pthread.h>

class Guard {
public:
    explicit Guard(pthread_mutex_t& mutex) : m_mutex(mutex) {
    pthread_mutex_lock(&m_mutex);
}

~Guard(){
    pthread_mutex_unlock(&m_mutex);
}
Guard(const Guard&) = delete;
Guard& operator=(const Guard&) = delete;

private:
    pthread_mutex_t& m_mutex;
};
