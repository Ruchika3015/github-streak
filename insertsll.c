#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node* inserthead(struct node*head,int value)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));

    temp->data=value;
    temp->next=head;
    head=temp;
    return head;
}
struct node* insertend(struct node*head,int value)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    if (head==NULL)
    return newnode;
    else
    {
        struct node *temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    return head;
}
struct node* insertpos(struct node*head,int pos,int value)
{
    if (pos==1)
    return inserthead(head,value);
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    struct node*temp=head;
    for (int i=0;i<(pos-2)&&temp!=NULL;i++)
    {
        temp=temp->next;
    }
    if (temp==NULL)
    {
        printf("Invalid positon\n");
        free(newnode);
        return head;
    }
    newnode->next=temp->next;
    temp->next=newnode;    
    return head;
}
struct node* insertbpos(struct node*head,int pos,int value)
{
    if(pos<=1)
    return inserthead(head,value);
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    struct node*temp=head;
    for (int i=1;i<pos-2&&temp!=NULL;i++)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Invalid positon\n");
        free(newnode);
        return head;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}
struct node* insertapos(struct node*head,int value,int pos)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    struct node *temp=head;
    for(int i=1;i<pos&&temp!=NULL;i++)
    {
        temp=temp->next;
    }
    if (temp==NULL)
    {
        printf("Invalid position\n");
        free(newnode);
        return head;
    }
    newnode->next=temp->next;
    temp->next=newnode;
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
    struct node*head,*second,*third;
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    head->data=34;
    head->next=second;
    second->data=45;
    second->next=third;
    third->data=90;
    third->next=NULL;
    head=inserthead(head,21);
    display(head);
    head=insertend(head,70);
    printf("\n");
    display(head);
    head=insertpos(head,2,29);
    printf("\n");
    display(head);
    printf("\n");
    head=insertbpos(head,4,12);
    display(head);
    printf("\n");
    head=insertapos(head,100,5);
    display(head);
    return 0;
}
