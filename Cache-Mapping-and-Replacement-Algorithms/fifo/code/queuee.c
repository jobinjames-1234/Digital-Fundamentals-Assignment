#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;
int hits = 0, misses = 0;
int isPresent(int value) {
    for (int i = front; i <= rear; i++) {
        if (queue[i] == value)
            return 1;
    }
    return 0;
}

void displayQueue() {
    printf("| ");
    for (int i = 0; i < SIZE; i++) {
        if (front != -1 && i >= front && i <= rear)
            printf("%d ", queue[i]);
        else
            printf("- ");
    }
    printf("|");
}

void enqueue(int value) {

    printf("Enqueue %d  ", value);

    if (isPresent(value)) {
        hits++;
        displayQueue();
        printf("  Hit\n");
        return;
    }

    misses++;

    if (rear == SIZE - 1) {
        for (int i = 0; i < SIZE - 1; i++)
            queue[i] = queue[i + 1];
        queue[rear] = value;
    } else {
        if (front == -1)
            front = 0;
        queue[++rear] = value;
    }

    displayQueue();
    printf("  Miss\n");
}

void dequeue() {

    printf("Dequeue     ");

    if (front == -1 || front > rear) {
        displayQueue();
        printf("  Underflow\n");
        return;
    }

    front++;
    displayQueue();
    printf("  Deleted\n");
}

int main() {

    printf("QUEUE SIZE = %d\n", SIZE);
    printf("------------------------------------------------\n");
    printf("Operation    Queue Content        Result\n");
    printf("------------------------------------------------\n");

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(20);   
    dequeue();
    enqueue(40);
    enqueue(50);
    enqueue(60);   
    dequeue();
    enqueue(30);   
    dequeue();

    printf("------------------------------------------------\n");
    printf("Total Hits   = %d\n", hits);
    printf("Total Misses = %d\n", misses);
    printf("Hit Ratio = %.2f\n", (float)hits / (hits + misses));

    return 0;
}
