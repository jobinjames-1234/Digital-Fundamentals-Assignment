#include <stdio.h>

#define size 100  

int main()
{
    int queue[size];
    int front = -1, rear = -1;
    int value, i, opt;

    void enqueue()
    {
        if (rear == size - 1)
        {
            printf("Queue overflow! Cannot insert more elements.\n");
        }
        else
        {
            printf("Enter the element to insert: ");
            scanf("%d", &value);
            if (front == -1)
                front = 0; 
            queue[++rear] = value;
            printf("%d inserted into queue.\n", value);
        }
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            printf("Queue underflow! Queue is empty.\n");
        }
        else
        {
            printf("Deleted element: %d\n", queue[front++]);
        }
    }

    void display()
    {
        if (front == -1 || front > rear)
        {
            printf("Queue is empty.\n");
        }
        else
        {
            printf("Queue elements are:\n");
            for (i = front; i <= rear; i++)
            {
                printf("%d ", queue[i]);
            }
            printf("\n");
        }
    }


    do
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch (opt)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 0: printf("Exiting program.\n"); break;
            default: printf("Invalid choice!\n"); break;
        }
    } while (opt != 0);

    return 0;
}