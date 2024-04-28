#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int helper(string &ring, string &key, unordered_map<int, string> &visited, int ri, int ki, int steps)
    {

        // BASE CASE
        if (ki == key.size())
        {
            return -1;
        }

        // LOGIC
        int clock = 0;
        int antiClock = 0;

        if (ri < 0)
        {
            ri = ring.size() - 1;
        }
        else if (ri >= ring.size())
        {
            ri = 0;
        }

        if (ring[ri] == key[ki])
        {
            steps += 1;
            // mark visited

            antiClock = helper(ring, key, visited, ri + 1, ki + 1, steps + 1);
            clock = helper(ring, key, visited, ri - 1, ki + 1, steps + 1);
        }
        else
        {
            antiClock = helper(ring, key, visited, ri + 1, ki, steps + 1);
            clock = helper(ring, key, visited, ri - 1, ki, steps + 1);
        }

        // RETURN

        return steps + min(antiClock, clock);
    }
    int findRotateSteps(string ring, string key)
    {
        int rs = ring.size();
        unordered_map<int, string> visited;
        // <ring String , keyString>
        int steps = 0;

        int ans = helper(ring, key, visited, 0, 0, steps);

        return ans;
    }
};