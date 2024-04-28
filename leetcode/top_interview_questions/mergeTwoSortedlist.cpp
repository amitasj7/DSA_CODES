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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        // if dono khali hai
        if (list1 == NULL && list2 == NULL)
            return list1;

        // if one list is empty
        if (list1 == NULL && list2 != NULL)
            return list2;
        if (list2 == NULL && list1 != NULL)
            return list1;

        ListNode *ans = new ListNode(0);
        ListNode *temp = ans;

        while (list1 != NULL && list2 != NULL)
        {

            // if list1 value less than or equal
            if (list1->val <= list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        // remaining list ko jodane ke liye
        if (list1 == NULL)
        {
            temp->next = list2;
        }
        else
        {
            temp->next = list1;
        }

        temp = ans;
        ans = ans->next;

        temp->next = NULL;

        return ans;
    }
};