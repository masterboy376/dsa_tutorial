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
        if ((head->data == val) || (head->next == NULL))
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

node* reverseIterative(node *&head)
{
    node *prev = NULL;
    node *curr = head;
    node *next;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}

node* reverseRecursive(node *&head)
{
    if(head==NULL || head->next==NULL){
        return head;
    }

    node* newHead = reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;
}

node* reverseKNode(node *&head, int k){// O(n)
    node* prev = NULL;
    node* curr = head;
    node* next;

    int count = 0;
    while(curr!=NULL && count<k){
        next = curr->next;
        curr->next=prev;

        prev =curr;
        curr=next;
        count++;
    }
    if(next!=NULL){
    head->next=reverseKNode(next, k);
    }
    return prev;
}

// Floyd's algorithm or Hare and Tortoise algorithm
// cycle detection and removal
bool detectCycle(node* head){
    node* slow = head;
    node*fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}

void makeCycle(node* &head, int pos){
    node* temp = head;
    node* startNode;
    int count = 1;
    while(temp->next!=NULL){
        if(count == pos){
            startNode=temp;
        }
        temp=temp->next;
        count++; 
    }
    temp->next = startNode;
}

void removeCycle(node* &head){
    node* slow = head;
    node*fast = head;

    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(slow!=fast);
    fast=head;
    while(fast->next!=slow->next){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next=NULL;
}

int length(node* head){
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp=temp->next;
    }
    return l;
}

node* appendKNode(node* &head, int k){
    node* newHead;
    node* newTail;
    node* tail=head;

    int l = length(head);
    k=k%l;
    int count=1;
    while(tail->next!=NULL){
        if(count==(l-k)){
            newTail=tail;
            newHead=tail->next;
        }
        tail=tail->next;
        count++;
    }
    newTail->next=NULL;
    tail->next=head;
    return newHead;
}

int intersection(node* head1, node* head2){
    int l1= length(head1);
    int l2= length(head2);

    int d=0;
    int count=1;
    node* ptr1;
    node* ptr2;
    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    while(d){
        ptr1=ptr1->next;
        if(ptr1==NULL){
            return -1;
        }
        d--;
    }
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
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
    head = reverseIterative(head);
    display(head);
    head = reverseRecursive(head);
    display(head);
    push(head,10);
    push(head,9);
    display(head);
    head = reverseKNode(head, 3);
    display(head);
    remove(head,5);
    remove(head,8);
    remove(head,7);
    remove(head,6);
    remove(head,9);
    remove(head,10);
    push(head,1);
    push(head,2);
    push(head,3);
    push(head,4);
    push(head,5);
    push(head,6);
    display(head);
    cout<<detectCycle(head)<<endl;
    makeCycle(head,3);
    cout<<detectCycle(head)<<endl;
    removeCycle(head);
    cout<<detectCycle(head)<<endl;
    display(head);
    head=appendKNode(head,3);
    display(head);
    head=appendKNode(head,3);
    display(head);

    return 0;
}