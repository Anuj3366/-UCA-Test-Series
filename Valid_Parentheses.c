#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Stack
{
  int data;
  struct Stack *next;
} *top = NULL, *tail = NULL;

void insert(int input)
{
  struct Stack *temp;
  temp->data = input;
  temp->next = NULL;
  if (top == NULL)
  {
    top = temp;
    tail = temp;
  }
  else
  {
    tail->next = temp;
    tail = temp;
  }
}
int onTop()
{
  return top->data;
}
void remove()
{
  struct Stack *temp = top;
  free(temp);
  top = top->next;
}

bool isValid(char *s)
{
  while(s != NULL)
  {
    if(s == '(' || s == '{' || s == '[')
    {
      insert(s);
    }
    else if(s == ')' || s == '}' || s == ']')
    {
      if(onTop() == '(' && s == ')')
      {
        remove();
      }
      else if(onTop() == '{' && s == '}')
      {
        remove();
      }
      else if(onTop() == '[' && s == ']')
      {
        remove();
      }
      else
      {
        return false;
      }
    }
    s++;
  }
}