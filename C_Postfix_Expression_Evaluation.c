#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
  struct Node *next;
  void *data;
} Node;

typedef struct
{
  Node *head;
  int size;
} Stack;

Stack *createStack()
{
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->head = NULL;
  stack->size = -1;
  return stack;
}

bool isEmpty(Stack *stack)
{
  return (stack->size == -1);
}

void *peek(Stack *stack);

void push(Stack *stack, void *data)
{
  stack->size = stack->size + 1;
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->next = stack->head;
  stack->head = node;
  printf("push : %d,\n", *(int *)peek(stack));
}

void pop(Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("ERROR : Stack is Empty");
  }
  else
  {
    Node *temp = stack->head;
    stack->head = stack->head->next;
    stack->size = stack->size - 1;
    printf("pop : %d,\n", *(int *)peek(stack));
    free(temp->data);
    free(temp);
  }
}

void *peek(Stack *stack)
{
  if (isEmpty(stack))
  {
    return NULL;
  }
  else
  {
    return stack->head->data;
  }
}

void freeAll(Stack *stack)
{
  while (!isEmpty(stack))
  {
    pop(stack);
  }
  free(stack);
}

bool isSymbol(char input)
{
  if (input == '+' || input == '-' || input == '*' || input == '/' || input == '^')
    return true;
  return false;
}

int main()
{
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    char *input = (char *)malloc(100 * sizeof(char));
    Stack *stack = createStack();
    scanf("%s", input);
    char *token = strtok(input, " ");
    while (token != NULL)
    {
      if (isSymbol(*token) && stack->size >= 1)
      {
        int op2 = *(int *)peek(stack); // Second operand
        pop(stack);
        int op1 = *(int *)peek(stack); // First operand
        pop(stack);
        int *sumToPush = malloc(sizeof(int));
        if (*token == '+')
        {
          *sumToPush = op1 + op2;
          push(stack, sumToPush);
        }
        else if (*token == '-')
        {
          *sumToPush = op1 - op2;
          push(stack, sumToPush);
        }
        else if (*token == '/')
        {
          *sumToPush = op1 / op2;
          push(stack, sumToPush);
        }
        else
        {
          *sumToPush = op1 * op2;
          push(stack, sumToPush);
        }
      }
      else if (!isSymbol(*token) && *token != ' ')
      {
        int num = atoi(token);
        int *numToPush = malloc(sizeof(int));
        *numToPush = num;
        push(stack, numToPush);
      }
      token = strtok(NULL, " ");
    }
    printf("ans : %d\n", *(int *)peek(stack));
    freeAll(stack);
    free(input);
  }
  return 0;
}

