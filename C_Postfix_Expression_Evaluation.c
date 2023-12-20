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

void *peek(Stack *stack)
{
  if (isEmpty(stack))
  {
    return "/";
  }
  else
  {
    return stack->head->data;
  }
}

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
    free(temp);
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
    while (*input != '?' && *input != '\0')
    {
      if (isSymbol(*input) && stack->size >= 1)
      {
        int op1 = *(int *)peek(stack);
        pop(stack);
        int op2 = *(int *)peek(stack);
        pop(stack);
        void *sumToPush = malloc(sizeof(int));
        if (*input == '+')
        {
          int sum = op1 + op2;
          sumToPush = (void *)&sum;
          push(stack, sumToPush);
        }
        else if (*input == '-')
        {
          int sum = op1 - op2;
          sumToPush = (void *)&sum;
          push(stack, sumToPush);
        }
        else if (*input == '/')
        {
          int sum = op1 / op2;
          sumToPush = (void *)&sum;
          push(stack, sumToPush);
        }
        else
        {
          int sum = op1 * op2;
          sumToPush = (void *)&sum;
          push(stack, sumToPush);
        }
      }
      else if (!isSymbol(*input) && *input != ' ')
      {
        int num = 0;
        while (*input != ' ' && *input != '\0')
        {
          num *= 10;
          num += (*input - '0');
          input++;
        }
        void *numToPush = malloc(sizeof(int));
        numToPush = (void *)&num;
        printf("num : %d\n", *(int *)numToPush);
        push(stack, numToPush);
      }
      input++;
    }
    printf("%d\n", *(int *)peek(stack));
    freeAll(stack);
    free(input);
  }
  return 0;
}
