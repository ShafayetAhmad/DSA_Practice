#include <bits/stdc++.h>
using namespace std;

class MyHashMap
{
public:
    int data[1000001];
    MyHashMap()
    {
        fill(data, data + 1000000, -1);
    }
    void put(int key, int val)
    {
        data[key] = val;
    }
    int get(int key)
    {
        return data[key];
    }
    void remove(int key)
    {
        data[key] = -1;
    }
};

int main()
{
    MyHashMap *obj = new MyHashMap();
    obj->put(1, 2);
    cout << obj->get(1) << endl;
    obj->remove(1);

    return 0;
}