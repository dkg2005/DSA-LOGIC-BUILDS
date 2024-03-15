#include <iostream>
using namespace std;

int fibb(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }
    else
    {
        return (fibb(n - 1) + fibb(n - 2));
    }
}

int main()
{

    int i, n = 1; // n is  the nth digit of fibbonaci series
    // cout << "enter the nth no of fibbonacci sequence : " << endl;
    // cin >> n;
    // cout << "nth term of series is :" << fibb(n) << endl;
    while (n != 20)
    {
        cout << "finn("<<n<<") :" << fibb(n) << endl;
        n++;
    }

    return 0;
}