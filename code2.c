#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *create()
{
    printf("Enter The Data\n");
    int val;
    scanf("%d",&val);
    struct node *n=(struct node *)malloc(sizeof(struct node));
    n->data=val;
    n->next=NULL;
    return n;
}
struct node *create_circularlinkedlist(struct node **l,struct node **r)
{
    struct node *temp=create();
    if(*l==NULL && *r==NULL)
    {
        *l=*r=temp;
    }
    else
    {
        (*r)->next=temp;
        *r=temp;
        (*r)->next=*l;
    }
}
struct node *insert(struct node **l,struct node **r,int pos)
{
    int c=1;
    struct node *temp=create();
    struct node *prev=NULL;
    struct node *cur=*l;
    if(pos==1)
    {
        temp->next=*l;
        *l=temp;
        (*r)->next=*l;
    }
    else
    {
        while(c!=pos)
        {
            prev=cur;
            cur=cur->next;
            c++;
        }
        prev->next=temp;
        temp->next=cur;
    }
};
struct node *delete(struct node **l,struct node **r,int pos1)
{
    int c=1;
    if(pos1==1)
    {
        *l=(*l)->next;
        (*r)->next=*l;
    }
    else
    {
        struct node *temp=*l;
        while(c!=pos1-1)
        {
            c++;
            temp=temp->next;
        }
        temp->next=temp->next->next;
    }
};
int search(struct node **l,int search_value)
{
    int f=1;
    struct node *temp=*l;
    while(temp->next!=*l)
    {
        if(temp->data==search_value)
        return 1;
        temp=temp->next;
    }
    if(temp->data==search_value)
    return 1;
    else    
    return 0;
}
void display(struct node **l)
{
    struct node *temp=*l;
    while(temp->next!=*l)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
    printf("\n");
}
int main()
{
    struct node *left=NULL;
    struct node *right=NULL;
    int ch;
    int data1;
    int position;
    int search1;
    do
    {
        printf("Option 1 For Creating Circular Linked List \n");
        printf("Option 2 For Insering a Node\n");
        printf("Option 3 For Deleting a Node\n");
        printf("Option 4 For Searching a Node\n");
        printf("Option 5 To Display\n");
        printf("Option 6 To Exit\n");
        printf("Enter Choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            create_circularlinkedlist(&left,&right);
            break;
            case 2:
            printf("Enter The Position To Insert Node\n");
            scanf("%d",&position);
            insert(&left,&right,position);
            break;
            case 3:
            printf("Enter The Position To Delete Node\n");
            scanf("%d",&position);
            delete(&left,&right,position);
            break;
            case 4:
            printf("Enter The Value Of Node To Search\n");
            scanf("%d",&search1);
            int ans=search(&left,search1);
            if(ans)
            printf("Node Found\n");
            else
            printf("Node Not Found\n");
            break;
            case 5:
            display(&left);
            break;
        }
    }while(ch!=6);
}