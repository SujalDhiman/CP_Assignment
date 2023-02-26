#include <stdio.h>
#define N 100
int queue[N];
int front = -1;
int rear = -1;

void enqueue(int data) 
{
    if (rear == N - 1) 
    {
        printf("Queue is full\n");
    }
    else 
    {
        if (front == -1) 
        {
            front = 0;
        }
        rear++;
        queue[rear] = data;
    }
}

int dequeue() 
{
    if (front == -1) 
    {
        printf("Queue is empty\n");
        return -1;
    } 
    else 
    {
        int value = queue[front];
        front++;
        return value;
    }
}

void push(int data) 
{
    enqueue(data);
}

int pop() 
{
    int i;
    int size = rear - front + 1;
    int stack[size];
    for (i = 0; i < size; i++) 
    {
        stack[i] = dequeue();
    }
    int rem = stack[size - 1];
    front = -1;
    rear = -1;
    for (i = 0; i<=size-2; i++) 
    {
        enqueue(stack[i]);
    }
    return rem;
}
void display()
{
    for(int i=0;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");
}
int main() 
{
    int ch;
    int data;
    printf("Option 1 To Push in Stack\n");
    printf("Option 2 To Pop From a Stack\n");
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
                push(data);
                break;
            }
            case 2:
            {
                printf("Element Popped Is %d\n",pop());
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