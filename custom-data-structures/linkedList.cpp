#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void push(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

void removeHead(node *&head)
{
    node *toDelete = head;
    head = head->next;
    delete toDelete;
}

void remove(node *&head, int val)
{
    if (head != NULL)
    {
        if ((head->data == val)||(head->next==NULL))
        {
            removeHead(head);
            return;
        }
        else
        {
            node *temp = head;
            while (temp->next->data != val)
            {
                temp = temp->next;
            }
            node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }
    else
    {
        cout << "linked list is empty!" << endl;
    }
}

int main()
{
    node *head = NULL;
    push(head, 5);
    push(head, 6);
    push(head, 7);
    push(head, 8);
    display(head);
    cout << search(head, 9) << endl;
    remove(head, 5);
    display(head);
    push(head, 5);
    display(head);

    return 0;
}