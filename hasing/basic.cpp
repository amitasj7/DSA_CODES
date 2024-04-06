#include <bits/stdc++.h>
using namespace std;

// find how many times appears integers value
/* 
7 // size
1 2 3 1 2 3 1
5 // total 5 numbers check krne hoge
2
2 // 2 number 2 times aaya hai
3
2 // 3 number  times aaya hai
1
3 // 1 number 3 times aaya hia
4
0
6
0 // 6 number 0 times aaya hai
 */
void number_hashing()
{
    int size;
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // pre compute
    map<int, int> hashmap;
    for (int i = 0; i < size; i++)
    {
        hashmap[arr[i]]++;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int num;
        cin >> num;

        // fetch value from hashmap
        cout << hashmap[num] << endl;
    }
}

// find number of all characters in string
/*
jdslkjsf850348046146ALJDASJFD840878
5  // 5 numbers ke liye check kar rahe hoge
a
0 // a char 0 times aaya hai
A
2 // A char 2 times aaya hai
8
5 // 8 char 5 times aaya hai
6
2
u
0
 */
void String_char_all()
{
    string s;
    cin >> s;

    // pre compute
    int hash[256] = {0}; //{0,0,0, ....., 0} 256 times

    for (int i = 0; i < s.size(); i++)
    {
        int index = s[i];
        hash[index]++;
    }

    // fetch
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        int index = c;

        cout << hash[index] << endl;
    }
}

// find number of characters in string
/*
abcadefce
5
a
2 // output for a
b
1 // output for b
c
2
d
1
e
2
 */
void String_char_lower()
{
    string s;
    cin >> s;

    // pre compute
    int hash[26] = {0}; //{0,0,0, ....., 0} 26 times

    for (int i = 0; i < s.size(); i++)
    {
        int index = s[i] - 'a';
        hash[index]++;
    }

    // fetch
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        int index = c - 'a';

        cout << hash[index] << endl;
    }
}
int main()
{
    // String_char_lower();

    // String_char_all();

    number_hashing();

    return 0;
}