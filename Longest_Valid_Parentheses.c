#include <stdbool.h>
#include <stdlib.h>

struct Stack
{
  char data;
  struct Stack *prev;
} *tail = NULL;

void insert(char input)
{
  struct Stack *temp = (struct Stack *)malloc(sizeof(struct Stack));
  temp->data = input;
  temp->prev = NULL;
  if (tail == NULL)
  {
    tail = temp;
  }
  else
  {
    temp->prev = tail;
    tail = temp;
  }
}

void removeTop()
{
  struct Stack *temp = tail;
  tail = tail->prev;
  free(temp);
}

void freeAll()
{
  struct Stack *temp = tail;
  while (tail != NULL)
  {
    tail = tail->prev;
    free(temp);
    temp = tail;
  }
}

char onTop()
{
  if (tail == NULL)
    return ')';
  return tail->data;
}
int longestValidParentheses(char *s)
{
  int max = 0;
}