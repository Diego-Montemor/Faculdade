#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

void Barra(int i){
    for(int j = 0 ; j < 100; j = j + 5){
        cout << "thread " << i << " contagem: " << j << "%";
        sleep(2.5);
    }
}

int main(){
    thread t1(Barra(1));
    thread t2(Barra(2));
    thread t3(Barra(3));
    thread t4(Barra(4));
    thread t5(Barra(5));
    
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    return 0;
}
