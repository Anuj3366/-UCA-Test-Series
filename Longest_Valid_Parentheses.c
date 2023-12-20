#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
  struct Node *next;
  int index;
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

void push(Stack *stack, int index)
{
  stack->size = stack->size + 1;
  Node *node = (Node *)malloc(sizeof(Node));
  node->index = index;
  node->next = stack->head;
  stack->head = node;
}

void pop(Stack *stack)
{
  if (!isEmpty(stack))
  {
    Node *temp = stack->head;
    stack->head = stack->head->next;
    stack->size = stack->size - 1;
    free(temp);
  }
}

int peek(Stack *stack)
{
  if (isEmpty(stack))
  {
    return -1;
  }
  else
  {
    return stack->head->index;
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

int longestValidParentheses(char *s)
{
  int max = 0;
  Stack *stack = createStack();
  push(stack, -1);
  for (int i = 0; s[i] != '\0'; i++)
  {
    if (s[i] == '(')
    {
      push(stack, i);
    }
    else
    {
      pop(stack);
      if (isEmpty(stack))
      {
        push(stack, i);
      }
      else
      {
        int length = i - peek(stack);
        max = length > max ? length : max;
      }
    }
  }
  freeAll(stack);
  return max;
}
