#include <iostream>
#include<variant>
#include<vector>
#include <thread>
#include <pthread.h>
#include <unistd.h>

//std::thread::id main_thread_id = std::this_thread::get_id();

using namespace std;
thread::id main_thread_id = std::this_thread::get_id();

void hello()
{
    std::cout << "Hello Concurrent World\n";
    if (main_thread_id == std::this_thread::get_id())
        std::cout << "This is the main thread.\n";
    else
        std::cout << "This is not the main thread.\n";
}

void pause_thread(int n) {
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout << "pause of " << n << " seconds ended\n";
}

int main()
{
    cout << "Hello World! Let's start learn CPP!" << endl;

    cout << "vector usage ---------------------------------------------------------------------------------------" << endl;
    int arr[5] = {0,1,2,3,4};
    vector<int> var(arr,arr+5);//将arr数组的元素用于初始化向量
    var.size(); //向量大小
    var.begin(); //开始指针
    var.end(); //结束指针
    var[0]; //下标访问
    var.at(1); //at方法访问
    //var.resize(); //更改向量大小
    var.empty(); //判断是否为空

    //遍历
    vector<int>::iterator it;
    for (it = var.begin(); it != var.end(); it++)
        cout << *it << endl;
    //或者
    for (size_t i = 0; i < var.size(); i++) {
        cout << var.at(i) << endl;
    }

    cout << "thread usage ---------------------------------------------------------------------------------------" << endl;

    std::thread t(hello);
    std::cout << t.hardware_concurrency() << std::endl;//可以并发执行多少个(不准确)
    std::cout << "native_handle " << t.native_handle() << std::endl;//可以并发执行多少个(不准确)
    t.join();
    std::thread a(hello);
    a.detach();
    std::thread threads[5];                         // 默认构造线程

    std::cout << "Spawning 5 threads...\n";
    for (int i = 0; i < 5; ++i)
        threads[i] = std::thread(pause_thread, i + 1);   // move-assign threads
    std::cout << "Done spawning threads. Now waiting for them to join:\n";
    for (auto &thread : threads)
        thread.join();
    std::cout << "All threads joined!\n";


    cout << "End ---------------------------------------------------------------------------------------" << endl;
    return 0;
}


