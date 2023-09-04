#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
    vector<int> vect1{1, 2, 3, 4, 5};
    vector<int> vect2;
    copy(vect1.begin() + 2, vect1.begin() + 3, back_inserter(vect2));
    // cout << vect2[0] << endl;
    // cout << vect2[1] << endl;

    // cout << vect2.max_size() << endl;
    cout << vect1.size() << endl;
    // vect2.resize(20);
    vect1.resize(20);
    // cout << vect2.max_size() << endl;
    cout << vect1.size() << endl;

    // vect2 = vect1;
    // vect2[2] = 10;
    // cout << vect1[2] << endl;
    // cout << vect2[2] << endl;
    // array<int, 5> arr1{1, 2, 3, 4, 5};
    // array<int, 5> arr2;
    // arr2 = arr1;
    // arr2[2] = 10;
    // cout << arr1[2] << endl;
}