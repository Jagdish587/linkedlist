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

void splitlist(Node* head)
{
    Node* res1 = NULL;
    Node* temp1 = NULL;
    Node* prev1 = NULL;

    Node* res2 = NULL;
    Node* temp2 = NULL;
    Node* prev2 = NULL;

    int counter = 1;

    while(head!=NULL) {

        
        if(counter == 1) {
            temp1 = new Node;
            temp1->data = head->data;
            temp1->link = NULL;

            if(res1==NULL)
                res1=temp1;
            else
                prev1->link = temp1;

                prev1 = temp1;
                head = head->link ;
                
                counter = 2;
        }
        else if(counter == 2) {
            temp2 = new Node;
            temp2->data = head->data;
            temp2->link = NULL;

            if(res2 == NULL)
                res2 = temp2;
            else
                prev2->link = temp2;

                prev2 = temp2;
                head = head->link;

                counter = 1;
        }
    }

    printlist(res1);
    cout<<endl;
    printlist(res2);
    cout<<endl;
}
int main()
{
	cout<<"Entered Main \n ";
    Node* head = NULL;

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

    splitlist(head);

    return 0;
}
