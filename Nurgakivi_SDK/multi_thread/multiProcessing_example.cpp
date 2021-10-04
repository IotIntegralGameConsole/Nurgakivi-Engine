#include <iostream>
#include <string>
#include <unistd.h>
 
using namespace std;

void spawn(const int& number, pid_t * processTable) {
    pid_t forkedProcess;
    if (number > 0) {       
        forkedProcess = fork();
        if (forkedProcess == -1) {
            exit(0);
        }
        else if (forkedProcess == 0) {
            // 부모프로세스일 경우 아무것도 안함
        }
        else {          
            processTable[number] = forkedProcess;
            spawn(number - 1, processTable);
        }
    }
}

int main() {   
    int number = 5;
    int mainProcess = getpid();
    pid_t processTable[number] = {-1};
    
    // 프로세스 생성
    // 여기서 부터 로직이 분기된다.
    spawn(number, processTable);

    // 작업 수행 및 로직
	// doSomething1(); 
    // ...
	// doSomething5();

    return 0;
}    