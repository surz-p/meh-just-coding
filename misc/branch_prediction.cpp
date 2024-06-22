// https://stackoverflow.com/questions/11227809/why-is-processing-a-sorted-array-faster-than-processing-an-unsorted-array

#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <sys/time.h>

using namespace std;

int main() {
    const int size = 1000000000;
    struct timeval tv;
    gettimeofday(&tv, nullptr);
    srand(tv.tv_sec);

    long long sum = 0LL;
    vector<int> v(size, 0);
    for (int i = 0; i < size; i++) {
        v[i] = rand() % 256;
    }

    cout << "without sorting; branch prediction penalties!\n";
    gettimeofday(&tv, nullptr);
    cout << tv.tv_sec << " : " << tv.tv_usec << endl;
    for (int i = 0; i < size; i++) {
        if (v[i] >= 128) {
            sum += v[i];
        }
    }
    gettimeofday(&tv, nullptr);
    cout << tv.tv_sec << " : " << tv.tv_usec << endl;

    cout /* << endl << sum << endl */ << endl;
    sum = 0LL;

    cout << "sorting; expensive!\n\n";
    sort(v.begin(), v.end());

    cout << "after sorting; branch prediction works!\n";
    gettimeofday(&tv, nullptr);
    cout << tv.tv_sec << " : " << tv.tv_usec << endl;
    for (int i = 0; i < size; i++) {
        if (v[i] >= 128) {
            sum += v[i];
        }
    }
    gettimeofday(&tv, nullptr);
    cout << tv.tv_sec << " : " << tv.tv_usec << endl;

    return 0;
}
