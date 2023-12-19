#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
  void** arr;
  int size;
  int cap;
}Stack;

Stack* createStack(int capacity){
  Stack *stack = (Stack*)malloc(sizeof(Stack));
  *stack->arr = (void**)malloc(capacity * sizeof(void**));
  stack->cap = capacity;
  stack->size = -1;
  return stack;
}

bool isFull(Stack* stack){
  return (stack->size == stack->cap);
}

bool isEmpty(Stack* stack){
  return (stack->size == -1);
}

void push(Stack* stack,void** data){
  if(isFull(stack)){
    printf("ERROR : Stack Overflow");
  }
  else{
    stack->arr[++stack->size] = *data;
  }
}

void pop(Stack* stack){
  if(isEmpty(stack)){
    printf("ERROR : Stack is Empty");
  }
  else{
    stack->size = stack->size-1;
  }
}

void** peek(Stack* stack){
  if(isEmpty(stack)){
    printf("ERROR : Stack is Empty");
  }
  else{
    int s = stack->size -1;
    return stack->arr[s];
  }
}

int main(){
  Stack* stack = createStack(5);
  int x = 20;
  int * a = &x;
  void** b= (void**)&a;
  push(stack,b);
  printf("%d",*(int*)peek(stack));

}
