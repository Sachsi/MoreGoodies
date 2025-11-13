#include <iostream>
#include <list>
#include <thread>

std::list<int> g_Data;
const int SIZE = 50000000;

void DownloadData(){
    std::cout << "[Downloader] Started download" << std::endl;
    for(int i = 0; i < SIZE; i++){
        g_Data.push_back(i);
    }
    std::cout << "[Downloader]Finished download" << std::endl;
}

int main(){
    std::cout << "[Main] User started an operation" << std::endl;
    //creating a thread
    std::thread thDownloader(DownloadData);
    // a detached thread can not be joined. It can never be joined again
    thDownloader.detach();

    std::cout << "[Main] User started another operation" << std::endl;
    // to wait until the thread is finished ww have to call join
    // every created thread is joinable thread
    if(thDownloader.joinable()){
        thDownloader.join();
    }else
        std::cout << "[Main]thread was not joinable" << std::endl;

    //to wait by detached thread use system("Pause");
    system("Pause");
    return 1;
}