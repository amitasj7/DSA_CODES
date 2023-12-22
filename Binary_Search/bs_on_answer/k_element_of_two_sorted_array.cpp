#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &arr1, vector<int> &arr2, int n, int m, int k)
{
    // Write your code here

    int count = 0;
    int k_element = -1;

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {

            if (count == k)
            {
                k_element = arr1[i];
            }
            count++;
            i++;
        }
        else
        {

            if (count == k)
            {
                k_element = arr2[j];
            }
            count++;
            j++;
        }
    }
    while (i < n)
    {

        if (count == k)
        {
            k_element = arr1[i];
        }
        count++;
        i++;
    }
    while (j < m)
    {
        if (count == k)
        {
            k_element = arr2[j];
        }
        count++;
        j++;
    }

    return k_element;
}
int main()
{

    return 0;
}