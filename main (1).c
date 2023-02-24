#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int isempty(struct node *f)
{
    if(f==NULL)
    return 1;
    else
    return 0;
}
int isfull()
{
    struct node *n=(struct node *)malloc(sizeof(struct node));
    if(n==NULL)
    return 1;
    else
    return 0;
}
struct node *enqueue(struct node **f,struct node **r,int val)
{
    struct node *nn=(struct node *)malloc(sizeof(struct node));
    if(isfull())
    {
        printf("Queue Is Full\n");
    }
    else
    {
        nn->data=val;
        nn->next=NULL;
        if(*f==NULL)
        {
            *f=*r=nn;
        }
        else
        {
            (*r)->next=nn;
            *r=nn;
        }
    }
};
struct node *dequeue(struct node **f,struct node **r)
{
    if(isempty(*f))
    {
        printf("Cant Dequeue Queue Empty\n");
    }
    else
    {
        struct node *temp=*f;
        *f=(*f)->next;
        printf("Node With Data %d",temp->data);
        printf(" removed\n");
        free(temp);
    }
};
void display(struct node *f,struct node *r)
{
    while(f!=r)
    {
        printf("%d\n",f->data);
        f=f->next;
    }
     printf("%d\n",f->data);
}
int main()
{
    struct node *front=NULL;
    struct node *rear=NULL;
    int ch;
    int data1;
    do
    {
        printf("Option 1 For Pop\n");
        printf("Option 2 For Push\n");
        printf("Option 3 For Display\n");
        printf("Option 4 Exit\n");
        printf("Enter Choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            dequeue(&front,&rear);
            break;
            case 2:
            printf("Enter Node Data\n");
            scanf("%d",&data1);
            enqueue(&front,&rear,data1);
            break;
            case 3:
            display(front,rear);
            break;
        }
    }while(ch!=4);
}