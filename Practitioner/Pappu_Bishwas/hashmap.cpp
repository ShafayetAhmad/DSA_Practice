#include <bits/stdc++.h>
using namespace std;

class MyHashMap {
public:
    int a[1000001];

    MyHashMap() {
        for (int i = 0; i < 1000001; i++)
            a[i] = -1;
    }

    void put(int key, int value) {
        a[key] = value;
    }

    int get(int key) {
        if (a[key] == -1)
            return -1;
        return a[key];
    }

    void remove(int key) {
        if (a[key] != -1)
            a[key] = -1;
    }
};

int main() {
    MyHashMap hashMap;

    hashMap.put(1, 10);
    hashMap.put(2, 20);

    std::cout << "Value at key 1: " << hashMap.get(1) << std::endl; // Output: 10
    std::cout << "Value at key 3: " << hashMap.get(3) << std::endl; // Output: -1

    hashMap.remove(2);

    std::cout << "Value at key 2: " << hashMap.get(2) << std::endl; // Output: -1

    return 0;
}
