// main.cpp
#include <iostream>
#include "Singleton.h"
//#include "ScopeMutex.h"

class MySingleton : public SingletonBase {
public:
    void someMethod() override {
        std::cout << "Singleton method called!" << std::endl;
    }
};

int main() {
    SingletonBase* singleton = MySingleton::getInstance();

    // Use the singleton
    singleton->someMethod();

    return 0;
}
