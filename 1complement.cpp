#include <iostream>
using namespace std;

int bitwisecomplement(int n)
{
    int m = n;
    int mask = 0;
    if (m == 1)
    {
        return 1;
    }
    while (m != 0) 
    {
        mask = (mask << 1) | 1;
        m = m >> 1;
    }
    int ans = (~n) & mask;

    return ans;
}

int main()
{
    cout << "bitwisecomplement(5):  " << bitwisecomplement(5) << endl;
    cout << "bitwisecomplement(7):  " << bitwisecomplement(7) << endl;
    cout << "bitwisecomplement(2):  " << bitwisecomplement(2) << endl;
    cout << "bitwisecomplement(8):  " << bitwisecomplement(8) << endl;

    return 0;
}
