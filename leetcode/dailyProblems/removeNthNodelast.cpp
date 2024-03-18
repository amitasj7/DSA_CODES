#include <bits/stdc++.h>
using namespace std;

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
    int listlength(ListNode *head)
    {
        int size = 0;

        ListNode *temp = head;

        while (temp != NULL)
        {
            temp = temp->next;

            size++;
        }

        return size;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int length = listlength(head);

        int move = length - n - 1;

        ListNode *temp = head;

        // move temp till node-1
        while (move--)
        {
            temp = temp->next;
        }

        ListNode *dlt_node = temp->next;

        temp->next = dlt_node->next;

        dlt_node->next = NULL;
        // delete that node
        delete dlt_node;
        return head;
    }
};