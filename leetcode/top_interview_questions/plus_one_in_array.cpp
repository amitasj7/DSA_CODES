#include <bits/stdc++.h>
using namespace std;

#include "D:\coding\leetcode\top_interview_questions\vector_helper.cpp"
/*
vector<int> plusOne(vector<int> &digits)
{
    int sum = 0;
    int size = digits.size();
    for (int i = 0; i < size; i++)
    {
        if (digits[i] == 0)
        {
            sum *= 10;
            continue;
        }
        sum += (digits[i] * pow(10, size - i - 1));
        // 10 ki power out of range le jaigi
        cout<<"sum : "<<sum<<endl;
    }
    sum += 1;
    vector<int> ans;
    while (sum > 0)
    {
        ans.push_back(sum % 10);
        sum /= 10;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}
*/
/*
vector<int> plusOne(vector<int> &digits)
{

    int last_index = digits.size() - 1;

    if (digits.back() != 9)
    {
        digits.back() = digits.back() + 1;
    }
    else
    {
        last_index--;
        while (last_index >= 0)
        {

            if ((digits[last_index]) != 9)
            {
                digits[last_index] += 1;
                last_index++;
                while (last_index != digits.size())
                {
                    digits[last_index] = 0;
                    last_index++;
                }
                break;
            }
            else
            {
                last_index--;
            }

            last_index--;
        }
    }
    return digits;
}
 */

vector<int> plusOne(vector<int> &digits)
{

    int n = digits.size();

    // Increment the last digit by 1
    digits[n - 1] += 1;

    int carry = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        digits[i] += carry;
        carry = digits[i] / 10;
        if (carry == 0)
        {
            break;
        }
        digits[i] %= 10;
    }

    // If there's a carry left after processing all digits
    if (carry > 0)
    {
        digits.insert(digits.begin(), carry);
    }

    return digits;
}
int main()
{

    vector<int> nums;

    InputVec(nums);
    // PrintVec(nums);

    vector<int> ans = plusOne(nums);
    PrintVec(ans);

    return 0;
}