#include <thread>
#include <mutex>
#include <iostream>
using std::thread;

// 8 core 12 thread or 8 core 16 thread
void func1(){
    for(int i = 0; i < 10; i++){
        std::cout << "thread 1 Moving \n";
    }
}

void func2(){
    for(int i = 0; i < 10; i++){
        std::cout << "thread 2 Moving \n";
    }
}

void func3(){
    for(int i = 0; i < 10; i++){
        std::cout << "thread 3 Moving \n";
    }
}

void func4(){
    for(int i = 0; i < 10; i++){
        std::cout << "thread 4 Moving \n";
    }
}

void func5(){
    for(int i = 0; i < 10; i++){
        std::cout << "thread 5 Moving \n";
    }
}

void func6(){
    for(int i = 0; i < 10; i++){
        std::cout << "thread 6 Moving \n";
    }
}

void func7(){
    for(int i = 0; i < 10; i++){
        std::cout << "thread 7 Moving \n";
    }
}

void func8(){
    for(int i = 0; i < 10; i++){
        std::cout << "thread 8 Moving \n";
    }
}

void func9(){
    for(int i = 0; i < 10; i++){
        std::cout << "thread 9 Moving \n";
    }
}

void func10(){
    for(int i = 0; i < 10; i++){
        std::cout << "thread 10 Moving \n";
    }
}

void func11(){
    for(int i = 0; i < 10; i++){
        std::cout << "thread 11 Moving \n";
    }
}

void func12(){
    for(int i = 0; i < 10; i++){
        std::cout << "thread 12 Moving \n";
    }
}

void func13(){
    for(int i = 0; i < 10; i++){
        std::cout << "thread 13 Moving \n";
    }
}

void func14(){
    for(int i = 0; i < 10; i++){
        std::cout << "thread 14 Moving \n";
    }
}

void func15(){
    for(int i = 0; i < 10; i++){
        std::cout << "thread 15 Moving \n";
    }

void func16(){
    for(int i = 0; i < 10; i++){
        std::cout << "thread 16 Moving \n";
    }
}

int main(){
    thread t1(func1);
    thread t2(func2);
    thread t3(func3);
    thread t4(func4);
    thread t5(func5);
    thread t6(func6);
    thread t7(func7);
    thread t8(func8);
    thread t9(func9);
    thread t10(func10);
    thread t11(func11);
    thread t12(func12);
    thread t13(func13);
    thread t14(func14);
    thread t15(func15);
    thread t16(func16);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    t9.join();
    t10.join();
    t11.join();
    t12.join(;
    t13.join();
    t14.join();
    t15.join();
    t16.join();
}

