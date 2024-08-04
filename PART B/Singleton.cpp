#include <pthread.h>
#include <iostream>

// Abstract base class
class SingletonBase {
public:
    // Delete copy constructor and assignment operator
    SingletonBase(const SingletonBase&) = delete;
    SingletonBase& operator=(const SingletonBase&) = delete;

    // Public method to access the singleton instance
    static SingletonBase* getInstance() {
        pthread_mutex_lock(&mutex_);
        if (!instance_) {
            instance_ = createInstance();
        }
        pthread_mutex_unlock(&mutex_);
        return instance_;
    }

    // Virtual destructor for proper cleanup of derived classes
    virtual ~SingletonBase() {}

    // Pure virtual function to be implemented by derived classes
    virtual void doSomething() const = 0;

protected:
    // Protected constructor to prevent direct instantiation
    SingletonBase() {}

    // Pure virtual function to create the singleton instance
    static SingletonBase* createInstance();

private:
    static SingletonBase* instance_;
    static pthread_mutex_t mutex_;
    
};

// Initialize the static members
SingletonBase* SingletonBase::instance_ = nullptr;
pthread_mutex_t SingletonBase::mutex_ = PTHREAD_MUTEX_INITIALIZER;

// Example derived class
class DerivedSingleton : public SingletonBase {
protected:
    // Implement the pure virtual function to create the instance
    static SingletonBase* createInstance() {
        return new DerivedSingleton();
    }

public:
    // Implement the pure virtual function
    void doSomething() const override {
        std::cout << "Doing something in DerivedSingleton!" << std::endl;
    }

    // Protected constructor
    DerivedSingleton() {}
};

// Example usage
int main() {
    SingletonBase* singleton = DerivedSingleton::getInstance();
    singleton->doSomething();

    return 0;
}
