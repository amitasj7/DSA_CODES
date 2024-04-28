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
    ListNode *partition(ListNode *head, int x)
    {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode *small = new ListNode(0);
        ListNode *last = new ListNode(0);

        ListNode *sp = small;
        ListNode *lp = last;

        while (head != NULL)
        {

            if (head->val < x)
            {
                sp->next = head;
                sp = sp->next;
            }
            else
            {
                lp->next = head;
                lp = lp->next;
            }

            head = head->next;
        }

        sp->next = last->next;
        last->next = NULL;
        lp->next = NULL;

        head = small->next;
        small->next = NULL;

        return head;
    }
};