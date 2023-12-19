#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
  struct Node* next;
  void* data;
}Node;

typedef struct
{
  Node* head;
  int size;
}Stack;


Stack* createStack(){
  Stack *stack = (Stack*)malloc(sizeof(Stack));
  stack->head = NULL;
  stack->size = -1;
  return stack;
}

bool isEmpty(Stack* stack){
  return (stack->size==-1);
}

void push(Stack* stack, void* data){
  stack->size = stack->size+1;
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->next = stack->head;
  stack->head = node;
}

void pop(Stack* stack){
  if(isEmpty(stack)){
    printf("ERROR : Stack is Empty");
  }
  else{
    Node* temp = stack->head;
    stack->head = stack->head->next;
    stack->size = stack->size-1;
    free(temp);
  }
}

void* peek(Stack* stack){
  if(isEmpty(stack)){
    return "/";
  }
  else{
    return stack->head->data;
  }
}


void freeAll(Stack * stack){
    while(!isEmpty(stack)){
      pop(stack);
    }
    free(stack);
}

bool isValid(char *s)
{
    Stack *stack = createStack(100);
    while(*s != '\0'){
        if(*s == '(' || *s == '{' || *s == '[' ){
            char *temp = malloc(sizeof(char));
            *temp = *s;
            push(stack, temp);
        }
        else if(*s == ')' && *(char *)peek(stack) == '('){
            pop(stack);
        }
        else if(*s == ']' && *(char *)peek(stack) == '['){
            pop(stack);
        }
        else if(*s == '}' && *(char *)peek(stack) == '{'){
            pop(stack);
        }
        else{
            freeAll(stack);
            return false;
        }
        s++;
    }
    if(!isEmpty(stack)){
        freeAll(stack);
        return false;
    }
    return true;
}
