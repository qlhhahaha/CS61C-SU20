#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> *k = new vector<int>; // vector����ָ��

    for (int i = 0; i < 5; i++)
    {
        k->push_back(i); // ������ָ����׷��ֵ
    }
    for (int i = 0; i < 5; i++)
    {
        cout << k->at(i)<< "  ";
    }
    delete k;
    return 0;
}