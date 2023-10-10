#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
    int data;
    struct stack *next;
}stack;

//taking top golablly to avoid complexity
stack *top = NULL;

void push(int val);
int pop();
void display();

int main(){

    pop();
    push(10);
    push(20);
    push(30);
    push(40);
    pop();
    pop();

    display();
}

void push(int val){
    stack *newNode = (stack*)malloc(sizeof(stack));
    if(newNode==NULL)
        printf("Stack Overflowed");
    else{
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }
}

int pop(){
    int x =-1;
    if(top == NULL)
        printf("Stack Underflow\n");
    else{
        x = top->data;
        stack *ptr = top;
        top = top->next;
        free(ptr);
    }
    return x;
}
void display(){
    stack *ptr = top;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}