#include<stdio.h>

int front = -1;
int rear = -1;
int size = 3;
int burstTime = 4;
long ProcessQ[3];

typedef struct process {
    int id;
    int exeTime;
} p;

p processes[3] = {{1, 12}, {2, 14}, {3, 9}};  // Default processes with execution times

void enqueue(int id) {
    if ((rear + 1) % size == front) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        ProcessQ[0] = id;
    } else {
        rear = (rear + 1) % size;
        ProcessQ[rear] = id;
    }
}

int dequeue() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return -1;
    }
    int id = ProcessQ[front];
    if (front == rear) {
        front = rear = -1;  // Queue is now empty
    } else {
        front = (front + 1) % size;
    }
    return id;
}

void roundRobin() {
    int time = 0;  // Time tracker

    // Enqueue all processes initially
    for (int i = 0; i < size; i++) {
        enqueue(processes[i].id);
    }

    while (front != -1) {  // Continue until the queue is empty
        int processId = dequeue();

        // Find the corresponding process
        for (int i = 0; i < size; i++) {
            if (processes[i].id == processId) {
                // Execute the process
                printf("Executing Process %d for %d seconds\n", processes[i].id, burstTime);

                if (processes[i].exeTime <= burstTime) {
                    time += processes[i].exeTime;
                    printf("Process %d finished at time %d seconds\n", processes[i].id, time);
                    processes[i].exeTime = 0;  // Mark as finished
                } else {
                    time += burstTime;
                    processes[i].exeTime -= burstTime;  // Decrease the remaining time
                    printf("Process %d has %d seconds remaining\n", processes[i].id, processes[i].exeTime);

                    // Re-enqueue the process if it is not finished
                    enqueue(processes[i].id);
                }
                break;
            }
        }
    }
}

int main() {
    roundRobin();
    return 0;
}