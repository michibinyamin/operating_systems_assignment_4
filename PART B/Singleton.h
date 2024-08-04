// Singleton.h
#ifndef SINGLETON_H
#define SINGLETON_H

#include <pthread.h>

class SingletonBase {
public:
    // Get the instance of the Singleton
    static SingletonBase* getInstance();

    // Pure virtual method to be implemented by derived classes
    virtual void someMethod() = 0;

protected:
    SingletonBase();
    virtual ~SingletonBase();

    // Mutex for thread safety
    static pthread_mutex_t mutex;

private:
    // Prevent copy construction and assignment
    SingletonBase(const SingletonBase&) = delete;
    SingletonBase& operator=(const SingletonBase&) = delete;

    // Initialize and destroy instance
    static void initializeInstance();
    static void destroyInstance();

    // The single instance
    static SingletonBase* instance;
};

#endif // SINGLETON_H
