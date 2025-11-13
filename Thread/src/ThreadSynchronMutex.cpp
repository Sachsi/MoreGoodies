#include <iostream>
#include <list>
#include <thread>
#include <mutex>

std::list<int> g_Data;
const int SIZE = 10000;
std::mutex g_Mutex;

void DownloadData(){
    for(int i = 0; i < SIZE; i++){
        g_Mutex.lock();
        g_Data.push_back(i);
        //deed lock, the other thread is waiting for ever
        if(i == 500)
            return;
        g_Mutex.unlock();
    }
}

void DownloadData2(){
    for(int i = 0; i < SIZE; i++){
        g_Mutex.lock();
        g_Data.push_back(i);
        g_Mutex.unlock();
    }
}

int main(){
    std::cout << "[Main] User started an operation" << std::endl;
    //creating a thread
    std::thread thDownloader(DownloadData);
    std::thread thDownloader2(DownloadData2);

    std::cout << "[Main] User started another operation" << std::endl;
    // to wait until the thread is finished ww have to call join
    // every created thread is joinable thread
    thDownloader.join();
    thDownloader2.join();

    std::cout << g_Data.size() << std::endl;

    return 1;
}