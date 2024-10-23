#include <stdio.h>
#define MAX_size 4

typedef struct
{
    int arr[MAX_size];
    int front;
    int rear;
}Queue;

void inisialisasi(Queue* queue){
    queue -> front = -1;
    queue -> rear = -1;
}

int isEmpty(Queue* queue){
    return (queue -> front == -1 && queue ->rear == -1);
}

int isFull(Queue* queue){
    return ((queue -> rear + 1) % MAX_size == queue ->front);
}

void display(Queue* queue){
    if(isEmpty(queue)){
        printf("Queue kosong!\n");
        return;
    }
    int i = queue->front;
    do {
        printf("%d ", queue->arr[i]);
        i = (i + i) % MAX_size;
    }while (i != (queue->rear + 1)% MAX_size);
    printf("\n");
}

int dequeue(Queue* queue){
    if(isEmpty(queue)){
        printf("\nQUEUE UNDERFLOW");
        return -1;
    }
    int value = queue -> arr[queue->front];
    if (queue -> front == queue -> rear){
        queue -> front = -1;
        queue -> rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_size;
    }
    printf("%d  telah dihapus dari queue\n", value);
    return value;
}
int enqueue(Queue* queue, int value){
    if(isFull(queue)){
        printf("\nQUEUE OVERFLOW");
        return;
    }
    if(isEmpty(queue)){
        queue -> front = 0;
        queue -> rear = 0;
    }else{
        queue->rear=(queue->rear + 1) % MAX_size;
    }
    queue->arr[queue->rear] = value;
    printf("%d telah ditambahkan ke dalam queue\n", value);

}
int main(){
    Queue queue;
    inisialisasi(&queue);

    enqueue(&queue,101);
    enqueue(&queue,102);
    enqueue(&queue,103);
    display(&queue);
    dequeue(&queue);
    dequeue(&queue);
    
    return 0;
    
}