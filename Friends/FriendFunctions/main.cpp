#include <iostream>

class Dog{
    // Declare the debug_dog_info functions as friends of the Dog class
    // It is not necessary to do the definition insite the class, but it is necessary to declare them as friends
    friend void debug_dog_info(const Dog& d);
    friend void debug_dog_info();

public:
    Dog(const std::string& name, int age)
        : m_name{name}, m_age{age}
        {

        }
    
private:
    std::string m_name;
    int m_age;
};

void debug_dog_info(const Dog& d){
    std::cout << "Dog [ name: " << d.m_name << ", age: " << d.m_age << "]" << std::endl;
}

void debug_dog_info(){
    Dog dog1("Fluffy", 10);
    std::cout << "Dog [ name: " << dog1.m_name << ", age: " << dog1.m_age << "] " << std::endl;
}

int main() {
    Dog dog("Fido", 3);
    debug_dog_info(dog);
    debug_dog_info();
    return 0;
}