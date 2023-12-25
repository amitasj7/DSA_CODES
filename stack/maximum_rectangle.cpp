#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    // create leftsmall and rightsmall vector
    vector<int> leftsmall(n, 0);
    vector<int> rightsmall(n, 0);

    stack<int> st;

    // fill left small
    for (int i = 0; i < n; i++)
    {

        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            // pop that element from stack
            st.pop();
        }
        if (st.empty())
        {
            // fill 0 index number
            leftsmall[i] = 0;
        }
        else
        {
            // if not empty that fill top index + 1;
            leftsmall[i] = st.top() + 1;
        }
        // push index of that number in stack
        st.push(i);
    }
    // stack empty kare
    while (!st.empty())
    {
        st.pop();
    }

    // fill right small
    for (int i = n - 1; i >= 0; i--)
    {

        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            // pop that element from stack
            st.pop();
        }
        if (st.empty())
        {
            // fill  last index number
            rightsmall[i] = n - 1;
        }
        else
        {
            // if not empty that fill top index - 1;
            rightsmall[i] = st.top() - 1;
        }
        // push index of that number in stack
        st.push(i);
    }

    int maxArea = 0;
    // area = width * height;

    for (int i = 0; i < n; i++)
    {
        int width = rightsmall[i] - leftsmall[i] + 1;
        int ht = heights[i];

        maxArea = max(maxArea, (width * ht));
        cout << "maxarea: " << maxArea << endl;
        cout << "w: " << width << " " << ht << endl;
    }

    return maxArea;
}
int main()
{

    // vector<int> height = {2, 1, 5, 6, 2, 3, 1};
    vector<int> height = {0, 9};
    cout << largestRectangleArea(height) << endl;

    return 0;
}