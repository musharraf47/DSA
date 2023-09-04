#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node *&tail, Node *curr)
{
    tail->next = curr;
    tail = curr;
}

Node *segregate(Node *head)
{

    // Approach-1
    int zeroCount = 0, oneCount = 0, twoCount = 0;
    Node *temp = head;

    // count no of 0s 1s and 2s
    while (temp != NULL)
    {
        if (temp->data == 0)
            zeroCount++;
        else if (temp->data == 1)
            oneCount++;
        else
            twoCount++;

        temp = temp->next;
    }

    // replace List data
    temp = head;
    while (temp != NULL)
    {
        if (zeroCount != 0)
        {
            temp->data = 0;
            zeroCount--;
        }
        else if (oneCount != 0)
        {
            temp->data = 1;
            oneCount--;
        }
        else if (twoCount != 0)
        {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }

    return head;

    // Approach-2

    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;

    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head;

    // seperate 0s 1s and 2s
    while (curr != NULL)
    {

        int value = curr->data;

        if (value == 0)
            insertAtTail(zeroTail, curr);
        else if (value == 1)
            insertAtTail(oneTail, curr);
        else if (value == 2)
            insertAtTail(twoTail, curr);

        curr = curr->next;
    }

    // Merge all 3

    // if 1s list is not empty
    if (oneHead->next != NULL)
        zeroTail->next = oneHead->next;
    else
        // if 1s list is empty
        zeroTail->next = twoHead->next;

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // setup HEAD
    head = zeroHead->next;

    // delete dummy Nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}