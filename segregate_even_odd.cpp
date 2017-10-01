#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
};

void printlist(Node* head)
{
    Node* temp = head;

    while(temp!=NULL) {
        cout<<temp->data<<" ";
        temp = temp->link;
    }
}

void push(Node** head,int data)
{
    Node* node = new Node;
    node->data = data;
    node->link = *head;
    *head = node;
}

void dividelist(Node* head)
{
    Node* evenstart = NULL;
    Node* oddstart = NULL;
    Node* evenend = NULL;
    Node* oddend = NULL;
    Node* currenthead = head;

    while(currenthead!=NULL) {

        if(currenthead->data % 2 == 0) {
            if(evenstart == NULL) {
                evenstart = currenthead ;
                evenend = currenthead ;
            }
            else {
                evenend->link = currenthead;
                evenend = currenthead ;
            }
        }
        else if(currenthead->data % 2 != 0) {
            if(oddstart == NULL) {
                oddstart = currenthead ;
                oddend = currenthead ;
            }
            else {
                oddend->link = currenthead;
                oddend = currenthead ;
            }
        }

        currenthead = currenthead->link ;
    }

    evenend->link = oddstart;
    oddend->link = NULL;

    printlist(evenstart);

}
int main()
{
    Node* head = NULL;

   
    push(&head,9);
    push(&head,8);
    push(&head,7);
    push(&head,6);
    push(&head,5);
    push(&head,4);
    push(&head,3);
    push(&head,2);
    push(&head,1);
    push(&head,0);

    printlist(head);
    cout<<endl;

    dividelist(head);
    

    return 0;
}