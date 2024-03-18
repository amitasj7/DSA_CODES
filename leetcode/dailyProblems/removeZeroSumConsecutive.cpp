#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {

        // take a dummy node and point it starting

        ListNode *dummy = new ListNode(0, head);
        // 0 insert into map

        unordered_map<int, ListNode *> mp;

        mp[0] = dummy;

        int prefixSum = 0;

        // move head pointer till last node
        while (head != NULL)
        {

            prefixSum += head->val;

            // if not find then insert it otherwise delete it
            if (mp.find(prefixSum) == mp.end())
            {
                mp[prefixSum] = head;
            }
            else
            {
                // take a start and temp pointer
                ListNode *start = mp[prefixSum];
                ListNode *temp = start->next;
                int pSum = prefixSum;

                while (temp != head)
                {

                    pSum += temp->val;

                    mp.erase(pSum);
                    temp = temp->next;
                }

                start->next = head->next;
            }

            head = head->next;
        }
        return dummy->next;
    }
};