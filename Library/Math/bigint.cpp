#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;



int main()
{
    bigint a = bigint("1");
    int b = 2;
    for(int i=1; i<100; i++)
    {
        a = a*b;
    }
    
    cout << a << endl;

    for(int i=1; i<99; i++)
    {
        a /= b;
    }

    cout << a << endl;
}
