#include <iostream>
#include <list>

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
    DownloadData();
    std::cout << "[Main] User started another operation" << std::endl;

    return 1;
}