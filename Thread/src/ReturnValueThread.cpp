#include <iostream>
#include <list>
#include <thread>
#include <string>

std::list<int> g_Data;
const int SIZE = 50000000;

class String{
public:
    String(){
        std::cout << "String()" << std::endl;
    }
    String(const String &){
        std::cout << "String(const String&)" << std::endl;
    }
    String & operator=(const String&){
        std::cout << "operator=(const String&)" << std::endl;
        return *this;
    }
    ~String(){
        std::cout << "~String()" << std::endl;
    }
};

void DownloadData(const String &file){
    //std::cout << "[Downloader] Started download of file: " << file << std::endl;
    for(int i = 0; i < SIZE; i++){
        g_Data.push_back(i);
    }
    std::cout << "[Downloader]Finished download" << std::endl;
}
#define REF_STRING

int main(){
    String file;

    std::cout << "[Main] User started an operation" << std::endl;
    //creating a thread
    //with this normal referance, two string objects are created
#ifndef REF_STRING
    std::thread thDownloader(DownloadData, file);
#else
    //to create just one string object, we can use std::ref or std::cref (for const reference)
    std::thread thDownloader(DownloadData, std::cref(file));
#endif
    // a detached thread can not be joined. It can never be joined again
    //thDownloader.detach();

    std::cout << "[Main] User started another operation" << std::endl;
    // to wait until the thread is finished ww have to call join
    // every created thread is joinable thread
    if(thDownloader.joinable()){
        thDownloader.join();
    }else
        std::cout << "[Main]thread was not joinable" << std::endl;

    //to wait by detached thread use system("Pause");
    //system("Pause");
    return 1;
}