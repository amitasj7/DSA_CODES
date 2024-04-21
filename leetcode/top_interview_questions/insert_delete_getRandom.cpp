#include <bits/stdc++.h>
using namespace std;

class RandomizedSet
{
    vector<int> nums;
    unordered_map<int, int> mp;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {

        if (mp.find(val) != mp.end())
            return false;

        // insert val at last index
        nums.push_back(val);

        int n = nums.size();

        mp[val] = n - 1;

        return true;
    }

    bool remove(int val)
    {
        // if val is not find into nums than return false
        if (mp.find(val) == mp.end())
            return false;

        // removeEle = val
        int removeIndex = mp[val];

        int lastIndex = nums.size() - 1;
        int lastEle = nums[lastIndex];

        nums[removeIndex] = lastEle;
        nums.pop_back();

        mp[lastEle] = removeIndex;
        mp.erase(val);
        

        return true;
    }

    int getRandom()
    {
        int n = nums.size();

        int randomIndex = rand() % n;

        return nums[randomIndex];
    }
};