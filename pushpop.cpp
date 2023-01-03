#include "stdio.h"
#include "stdlib.h"

#define MAXOFSTACK 10

int toCount=0;

struct stack{
    int data[MAXOFSTACK];
    int top;
};

typedef struct stack st;

int isStackIsFull(st *myStack){
    if(myStack->top == MAXOFSTACK-1){
        return 1;
    }else{
        return 0;
    }
}

int isStackIsEmpty(st *myStack){
    if(myStack->top == -1){
        return 1;
    }else{
        return 0;
    }
}

void create_emptyStack(st *myStack){
    myStack->top = -1;
}

void pushToStack(st *myStack,int value){
    if(isStackIsFull(myStack)){
        printf("Stack is full");
    }else{
        myStack->top++;
        myStack->data[myStack->top] = value;
    }

    toCount++;
}

void showData(st *myStack,int size){

    for (int i = 0; i < size; ++i) {
        printf("Push data is %d\n",myStack->data[i]);
    }
}

void popFromStack(st *myStack){

    if(isStackIsEmpty(myStack)){
        printf("Stack is empty");
    }else {
        printf("Remove data is %d\n", myStack->data[myStack->top]);
        myStack->top--;
    }

    toCount--;
}

int main(){

    st *myStack = (st*)malloc(sizeof(st));

    create_emptyStack(myStack);

    pushToStack(myStack,10);
    pushToStack(myStack,15);
    pushToStack(myStack,20);
    pushToStack(myStack,25);

    showData(myStack,toCount);

    printf("\n");

    isStackIsEmpty(myStack);

    popFromStack(myStack);
    popFromStack(myStack);
    popFromStack(myStack);
    popFromStack(myStack);


    return 0;
}

