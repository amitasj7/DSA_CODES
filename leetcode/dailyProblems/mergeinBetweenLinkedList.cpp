#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {

        // traverse till a-1

        ListNode *t1 = list1;
        int x = a - 1;
        while (x != 0)
        {

            t1 = t1->next;
            x--;
        }

        ListNode *t2 = t1->next;
        // connect a node to list2
        t1->next = list2;

        int y = b - a;
        while (y != 0)
        {
            // delete node
            ListNode *temp = t2;

            t2 = t2->next;

            temp->next = NULL;
            delete (temp);

            y--;
        }
        while (t1->next != NULL)
        {
            // update t1
            t1 = t1->next;
        }

        t1->next = t2->next;

        t2->next = NULL;
        delete (t2);

        return list1;
    }
};