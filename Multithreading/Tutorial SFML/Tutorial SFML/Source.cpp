#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <functional>
#include <queue>

#define NUM_MAX_THREADS std::thread::hardware_concurrency()

std::mutex consoleMutex;
std::mutex sharedMutex;
std::atomic <int> atomicInt(0); //constructor - tipo de variable - nomVariable(Valor inicial)

int globalInt = 0;

std::queue <std::function<void()>> tasks;
std::mutex tasksMutex;

void Increase() {
	atomicInt.fetch_add(1);
}

void Count() {
	
	int count = 0;

	while (count < 10)
		count++;

	sharedMutex.lock();
	consoleMutex.lock();
	globalInt++;
	std::cout << "Variable compartida: " << globalInt  << " del thread con Id: " << std::this_thread::get_id() << std::endl;
	consoleMutex.unlock();
	sharedMutex.unlock();
}

void PrintThread() {
	//std::lock_guard<std::mutex> lock(consoleMutex);
	std::unique_lock<std::mutex> uniqueLock(consoleMutex);
	//consoleMutex.lock();
	std::cout << "Soy el thread con id: " << std::this_thread::get_id() << std::endl;
	//consoleMutex.unlock();
	uniqueLock.unlock();
}

void Worker() {
	bool closeThread = false;

	while (!closeThread) {
		std::function<void()> task;
		{
			std::lock_guard<std::mutex> lock(tasksMutex);
			if (!tasks.empty()) {
				task = tasks.front();
				tasks.pop();
			}
			else {
				closeThread = true;
			}
		}

		if (task) {
			task();
		}
	}

}

void main()
{
	std::cout <<"Numero maximo de threads: " << NUM_MAX_THREADS << std::endl;

	std::vector<std::thread> threads;

	for (unsigned int i = 0; i < NUM_MAX_THREADS; i++) {
		tasks.push(Count);
		tasks.push(PrintThread);
		tasks.push(Increase);		
	}


	for (unsigned int i = 0; i < NUM_MAX_THREADS; i++) {
		threads.emplace_back(Worker);
	}

	for (unsigned int i = 0; i < NUM_MAX_THREADS; i++) {
		threads[i].join();
	}

	std::cout << "El valor de AtomicInt es: " << atomicInt << std::endl;

	//t.detach();
	//PrintThread();

}