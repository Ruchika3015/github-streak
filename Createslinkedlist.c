#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
void display(struct node*head)
{
    struct node*temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}
int main()
{
    struct node *head,*second,*third;
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    head->data=20;
    head->next=second;
    second->data=40;
    second->next=third;
    third->data=60;
    third->next=NULL;
    display(head);
    return 0;
}
