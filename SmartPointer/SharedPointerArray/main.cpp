#include <iostream>
#include <memory>
#include "dog.h"



int main(){

    std::shared_ptr<int[]> shared_int_ptr_arr_1 ( new int[10]{1,2,3,4,5,6,7,8,9,10});
    std::shared_ptr<Dog[]> shared_dog_ptr_arr_1 ( new Dog[10]{Dog("Dog1"), Dog("Dog2"), Dog("Dog3"), Dog("Dog4"), Dog("Dog5"),
        Dog("Dog6"), Dog("Dog7"), Dog("Dog8"), Dog("Dog9"), Dog("Dog10")});

    //setting elements in the array
    shared_int_ptr_arr_1[3] = 100;
    shared_dog_ptr_arr_1[1] = Dog("Dog2-Update");

    //Read int array
    std::cout << "Reading data from array..." << std::endl;
    std::cout << "Reading shared_int_ptr_arr_1..." << std::endl;
    for(int i=0; i<10; i++){
        std::cout << "shared_int_ptr_arr_1[" << i << "] : " << shared_int_ptr_arr_1[i] << std::endl;
    }
 
    std::cout << "Reading shared_dog_ptr_arr_1..." << std::endl;
    for(int i=0; i<10; i++){
        std::cout << "shared_dog_ptr_arr_1[" << i << "] : " << shared_dog_ptr_arr_1[i].get_name() << std::endl;
    }
    return 0;
}