#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // if 0 or 1 node hai then return
        if (head == NULL || head->next == NULL)
            return head;

        Node *curr = head;

        // create a new list with same value
        while (curr != NULL)
        {
            // create a NewNode
            Node *newNode = new Node(curr->val);

            newNode->next = curr->next;
            curr->next = newNode;

            // update current
            curr = newNode->next;
        }

        // Copy random pointer
        curr = head;
        while (curr != NULL)
        {
            curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // separate two list
        Node *newHead = head->next;
        curr = head;
        Node *newCurr = newHead;

        while (curr != NULL)
        {
            // update current
            curr->next = newCurr->next;
            curr = curr->next;

            if (curr != NULL)
            {
                // update newCurrent
                newCurr->next = curr->next;
                newCurr = newCurr->next;
            }
        }

        return newHead;
    }
};