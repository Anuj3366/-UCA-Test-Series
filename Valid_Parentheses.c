#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Stack {
  struct Stack* next;
  int data;
};

struct Stack head = {NULL, NULL};
struct Stack tail = {NULL, NULL};

void push(int data) {
  struct Stack* new_node = (struct Stack*)malloc(sizeof(struct Stack));
  new_node->data = data;
  new_node->next = &tail;
  tail = new_node;
  if (head == NULL) {
    head = new_node;
  }
}

int pop() {
  if (head == NULL) {
    // Handle empty stack
    return -1;
  }
  struct Stack* temp = head;
  int data = temp->data;
  head = head->next;
  free(temp);
  if (head == NULL) {
    tail = NULL;
  }
  return data;
}

int top() {
  if (head == NULL) {
    // Handle empty stack
    return -1;
  }
  return head->data;
}

int isEmpty() {
  return head == NULL;
}

// Additional functions or operations can be implemented here as needed

void destroyStack() {
  while (head) {
    struct Stack* temp = head;
    head = head->next;
    free(temp);
  }
  tail = NULL;
}

int main() {
  // Example usage
  push(10);
  push(20);
  push(30);

  int popped = pop();
  printf("Popped element: %d\n", popped);

  popped = top();
  printf("Top element: %d\n", popped);

  printf("Is stack empty: %s\n", isEmpty() ? "Yes" : "No");

  destroyStack();

  return 0;
}



bool isValid(char* s) {
    
}