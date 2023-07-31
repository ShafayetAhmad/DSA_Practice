#include <iostream>
#include <array>
using namespace std;

int main()
{
    array<int, 5> anArray;
    anArray[0] = 1;
    anArray[1] = 2;
    anArray[2] = 3;
    anArray[3] = 4;
    anArray[4] = 5;

    // anArray.fill(5);

    // cout << anArray[0] << " "
    //      << anArray[1] << " "
    //      << anArray[2] << " "
    //      << anArray[3] << " "
    //      << anArray[4] << endl;

    cout << anArray.front() << " " << anArray.back() << " " << anArray.at(2) << endl;
}