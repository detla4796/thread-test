#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <ctime>

using namespace std;

void threadFunc(int id) {
    cout << "Thread " << id << " start." << endl;
    int sleep = rand() % 901 + 100;
    this_thread::sleep_for(chrono::milliseconds(sleep));
    cout << "Thread " << id << " end after " << sleep << " ms." << endl;
}

int main() {
    srand(time(0));

    vector<thread> thr;
    for (int i = 1; i <= 3; i++) {
        thr.emplace_back(threadFunc, i);
    }

    for (auto& i : thr) {
        i.join();
    }
}
