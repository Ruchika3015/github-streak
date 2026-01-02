#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node* delh(struct node*head)
{
    if (head==NULL)
    return NULL;
    struct node*temp=head;
    head=head->next;
    free(temp);
    return head;
}
struct node * dele(struct node*head)
{
    if (head==NULL)
    return NULL;
    if(head->next==NULL)
    return NULL;
    
    struct node *temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
return head;
}
struct node* delp(struct node* head, int pos)
{
    if (head == NULL)
        return NULL;

    if (pos == 1)
        return delh(head);

    struct node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL)
    {
        printf("Invalid position\n");
        return head;
    }

    struct node* del = temp->next;
    temp->next = del->next;
    free(del);

    return head;
}

struct node* delb(struct node*head,int pos)
{
     if (head == NULL || pos <= 1)
    {
        printf("Invalid position\n");
        return head;
    }

    // delete head (before position 2)
    if (pos == 2)
        return delh(head);
    struct node*temp=head;
    for(int i=1;i<pos-2&&temp->next!=NULL;i++)
    {
        temp=temp->next;
    }
    if (temp->next == NULL)
    {
        printf("Invalid position\n");
        return head;
    }
    struct node*del=temp->next;
    temp->next=del->next;
    free(del);
    return head;
}
struct node *dela(struct node*head,int pos)
{
    if (head==NULL)
    return head;
    struct node *temp=head;
    for(int i=1;i<pos&&temp->next!=NULL;i++)
    {
        temp=temp->next;
    }
    if (temp==NULL||temp->next==NULL)
    return head;
    struct node *del=temp->next;
    temp->next=del->next;
    free(del);
    return head;
}
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
    struct node*head,*second,*third,*forth;
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    forth=(struct node*)malloc(sizeof(struct node));
    head->data=10;
    head->next=second;
    second->data=20;
    second->next=third;
    third->data=30;
    third->next=forth;
    forth->data=40;
    forth->next=NULL;
    display(head);
    head=delh(head);
    printf("\n");
    display(head);
    printf("\n");
    //head=delp(head,1);
    //dele(head);
    //head=delb(head,2);
    head=dela(head,1);
    display(head);
}
