#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
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

void inssterAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }

    head = n;
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
        n->prev = temp;
    }
}

void removeHead(node *&head)
{
    node *toDelete = head;
    head = head->next;
    head->prev = NULL;
    delete toDelete;
}

void remove(node *&head, int val)
{
    if (head != NULL)
    {
        if ((head->data == val) || (head->next == NULL))
        {
            removeHead(head);
            return;
        }
        else
        {
            node *temp = head;
            while (temp->data != val)
            {
                temp = temp->next;
            }
            node *toDelete = temp->next;
            temp->prev->next = temp->next;
            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }
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
    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 4);
    push(head, 5);
    push(head, 6);
    display(head);
    remove(head, 6);
    display(head);
    inssterAtHead(head, 1);
    display(head);

    return 0;
}