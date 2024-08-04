#include <iostream>
#include <memory>

// Forward declaration of ConcreteSingleton
class ConcreteSingleton;

class AbstractSingleton {
public:
    virtual ~AbstractSingleton() = default;

    // Pure virtual method (abstract method)
    virtual void doSomething() const = 0;

    // Static method to access the singleton instance
    static AbstractSingleton* getInstance();

    // Delete copy constructor and assignment operator to prevent copying
    AbstractSingleton(const AbstractSingleton&) = delete;
    AbstractSingleton& operator=(const AbstractSingleton&) = delete;

protected:
    AbstractSingleton() = default; // Protected constructor for singleton pattern

private:
    static AbstractSingleton* instance;
};

// Initialize static member
AbstractSingleton* AbstractSingleton::instance = nullptr;

// Definition of ConcreteSingleton class
class ConcreteSingleton : public AbstractSingleton {
public:
    void doSomething() const override {
        std::cout << "Doing something in ConcreteSingleton" << std::endl;
    }

    ConcreteSingleton() = default;
    ~ConcreteSingleton() override = default;
};

// Implementation of getInstance method
AbstractSingleton* AbstractSingleton::getInstance() {
    if (!instance) {
        instance = new ConcreteSingleton();
    }
    return instance;
}

int main() {
    AbstractSingleton* singleton = AbstractSingleton::getInstance();
    singleton->doSomething();

    return 0;
}
