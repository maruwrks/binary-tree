#include <stdio.h>
#define MAX_Size 4

typedef struct
{
    int arr[MAX_Size];
    int top;        
}Stack;

void inisialisasi(Stack* stack){
    stack->top = -1;
}

int isEmpty(Stack* stack){
    return stack->top == -1;
}

int isFull(Stack* stack){
    return stack->top == MAX_Size - 1;
}

void Display(Stack* stack){
    if (isEmpty(stack)){
        printf("Stack Kosong!\n");
        return;
    }
}

void push(Stack* stack, int value){
    if(isFull(stack)){
        printf("Stack overflow!\n");
        return;
    }
    stack->arr[++stack->top] = value;
    printf("Piring dengan ID %d ditambahkan ke tumpukan \n",value);
}
int pop(Stack* stack){
    if(isEmpty(stack)){
        printf("\nStack overflow");
        return -1;
    }
    int value = stack -> arr[stack->top--];
    printf("piring ke %d diambil dari tumpukan\n", value);
}

int main(){
    Stack stack;
    inisialisasi(&stack);
    push(&stack, 4);
    push(&stack, 5);
    push(&stack, 6);
    push(&stack, 7);
    Display(&stack);
    pop(&stack);
    pop(&stack);

    return 0;
}
