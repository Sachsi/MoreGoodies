#include "singleton.h"
#include "main.h"

int main() {
    Singleton& instance1 = Singleton::getInstance();
    instance1.showMessage();

    Singleton& instance2 = Singleton::getInstance();
    instance2.showMessage();

    // Both instance1 and instance2 refer to the same instance
    return 0;
}
