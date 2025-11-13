#include <iostream>
#include <future>
#include <thread>
#include <vector>

int Add(int x, int y){
    return x + y;
}

int Square(int x){
    return x * x;
}

int Compute(const std::vector<int> &data){
    using namespace std;
    int sum{};
    for(auto e : data){
        sum += e;
        std::this_thread::sleep_for(1s);
        std::cout << '.';
    }
    return sum;
}

int main(){
    std::packaged_task<int(int, int)> taskAdd{Add};
    std::future<int> ft = taskAdd.get_future();
    taskAdd(3, 5);

    auto result = ft.get();
    //return value auf Add function
    std::cout << "Result of Add: " << result << std::endl;

    std::packaged_task<int(int)> taskSquare{Square};
    auto fSquare = taskSquare.get_future();
    taskSquare(5);
    int resultSquare = fSquare.get();
    //return value of Square function
    std::cout << "Result of Square: " << resultSquare << std::endl;

    std::packaged_task<int(const std::vector<int>&)> taskCompute(Compute);
    auto fCompute = taskCompute.get_future();
    std::vector<int> data{1, 2, 3, 4, 5, 6};
    //taskCompute(data);
    //create one thread to execute the packaged task. Using std::move to transfer the task
    std::thread thCompute(std::move(taskCompute), data);
    std::cout << "[Main] User started thCompute thread" << std::endl;
    //Main wait for the return value
    int resultCompute = fCompute.get();
    //return value of Compute function
    std::cout << "Result of Compute: " << resultCompute << std::endl;

    std::cout << "[Main] User ends" << std::endl;
    thCompute.join();
    return 1;
}