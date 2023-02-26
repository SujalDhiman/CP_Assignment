#include<stdio.h>
#define N 5
int s1[N];
int s2[N];
int top1=-1;
int top2=-1;
int count=0;
void push1(int data)
{
    if(top1==N-1)
    {
        printf("Queue is Full Cant Push\n");
    }
    else
    {
        top1++;
        s1[top1]=data;
    }
}
int pop1()
{
    return s1[top1--];
}
void enqueue(int data)
{
    push1(data);
    count++;
}
void push2(int data)
{
    if(top2==N-1)
    {
        printf("Queue is Full Cant Enqueue\n");
    }
    else
    {
        top2++;
        s2[top2]=data;
    }
}
int pop2()
{
    return s2[top2--];
}
void dequeue()
{
    int x;
    int r;
    if(top1==-1 && top2==-1)
    {
        printf("Queue Is Empty Cant Dequeue");
    }
    else
    {
        for(int i=0;i<count;i++)
        {
            x=pop1();
            push2(x);
        }
        r=pop2();
        printf("Element Removed Is %d\n",r);
        count--;
        for(int i=0;i<count;i++)
        {
            x=pop2();
            push1(x);
        }
    }
}
void display()
{
    if(top1==-1)
    {
        printf("No Element Present\n");
    }
    else
    {
        for(int i=0;i<=top1;i++)
        {
            printf("%d ",s1[i]);
        }
        printf("\n");
    }
}
int main()
{
    int ch;
    int data;
    printf("Option 1 To Enqueue in Queue\n");
    printf("Option 2 To Dequeue From a Queue\n");
    printf("Option 3 To Display Elements\n");
    printf("Option 4 To Exit\n");
    do
    {
        printf("Enter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("Enter The Element\n");
                scanf("%d",&data);
                enqueue(data);
                break;
            }
            case 2:
            {
                dequeue();
                break;
            }
            
            case 3:
            {
                display();
                break;
            }
        }
    }while(ch!=4);
}