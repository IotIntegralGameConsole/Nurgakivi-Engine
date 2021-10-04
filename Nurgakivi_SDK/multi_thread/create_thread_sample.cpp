#include <iostream>
#include <mutex> 
#include <thread>
#include <vector>
#include <chrono>
#include <string>

using namespace std;

// 쓰레드 생성
int main()
{
	const int num_pro = std::thread::hardware_concurrency();

	cout << std::this_thread::get_id() << endl; // main thread ID

	std::thread t1 = std::thread([]()
	{
		cout << std::this_thread::get_id() << endl; // thread t1 ID
	});

	
	t1.join();  // join은 스레드 종료까지 대기하는 함수 대기하지않으면 main 함수에의해 종료된다.
}

// 메인 프로세스가 가지는 쓰레드 ID와 새로 생성한 쓰레드 t1의 ID를 확인할 수 있다.