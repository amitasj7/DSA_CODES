#include <bits/stdc++.h>
using namespace std;

bool helper(int n, int x)
{
    if (( pow(3, x)) >  n)
    {
        cout<<n<<endl;
        cout<<pow(3,x)<<endl;
        cout<<"less than"<<endl;
        return false;
    }
    if (n == pow(3, x))
    {
        return true;
    }
    cout<<pow(3,x)<<endl;

    helper(n, x + 1);
}
bool isPowerOfThree(int n)
{
    int x = 1;
    cout<<abs(n)<<endl;

    return helper(abs(n), x);
}

int main()
{
    int n;
    cin >> n;

    // cout << abs(n) << endl;
    // abs se only integer value ko positiv me change kiya jata hai

    if (isPowerOfThree(n))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}