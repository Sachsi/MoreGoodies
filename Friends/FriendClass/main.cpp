#include <iostream>

class Dog{
    friend class Cat; // Declare the Cat class as a friend of the Dog class
public:
    Dog(const std::string& name, int age)
        : m_name{name}, m_age{age}
        {

        }
    
private:
    std::string m_name;
    int m_age;
};

class Cat{

public:
    void print_dog_info(const Dog& d)
    {
        std::cout << "Dog [ name: " << d.m_name << " , age: " << d.m_age << "]" << std::endl;
        // with the this pointer it is not possible as well to acces to the private members of the Dog class
       
        // is not possible when the Cat objects does not has variables
        std::cout << "Cat members: " << m_name << ", age: " << m_age << std::endl;
    }
    
private:
    std::string m_name{"Whiskers"};
    int m_age{5};
};

int main() {
    Cat cat1;

    Dog dog("Fido", 3);
    cat1.print_dog_info(dog);
    return 0;
}