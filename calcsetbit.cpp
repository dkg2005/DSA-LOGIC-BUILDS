#include <iostream>
using namespace std;

int setbit(int x)
{
    int count = 0;
    while (x != 0)
    {
        if ( x& 1)
        {
            count++;
        }
        x = x >> 1;
    }
    return count;
}

int main()
{
    int a, b;
    cout << " enter a and b:" << endl;     
    cin >> a >> b;
    int seta = setbit(a);
    int setb = setbit(b);

    int setbit = seta + setb;

    cout << "Total no of set bits is :" << setbit << endl;
    return 0;
}