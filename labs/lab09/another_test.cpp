#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> *k = new vector<int>; // vector向量指针

    for (int i = 0; i < 5; i++)
    {
        k->push_back(i); // 像向量指针中追加值
    }
    for (int i = 0; i < 5; i++)
    {
        cout << k->at(i)<< "  ";
    }
    delete k;
    return 0;
}