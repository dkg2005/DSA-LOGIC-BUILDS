#include <iostream>
#include <cassert>
using namespace std;

int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact =fact * i ;
    }
    return fact;
}
int ncr(int n, int r)
{

    int num = factorial(n);
    int den = factorial(r) * factorial(n - r);
    int ans = num / den;
    return ans;
}

int main()
{
    int n, r;
    cout << "Enter n and r: ";
    cin >> n >> r;
    cout << "ncr: " << ncr(n, r) << endl;


    
    return 0;
}
