#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack
{
  struct Stack *next;
  int data;
} *top = NULL;

void push(int input)
{
  struct Stack *temp = (struct Stack *)malloc(sizeof(struct Stack));
  temp->data = input;
  temp->next = top;
  top = temp;
}

int peek()
{
  return top->data;
}

bool isEmpty()
{
  return (top == NULL);
}

void pop()
{
  if (!isEmpty())
  {
    struct Stack *temp = top;
    top = top->next;
    free(temp);
  }
}

bool isOperator(char input)
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
    scanf("%s", input);
    while (*input != '?')
    {
      if (isOperator(*input))
      {
        int op1 = peek();
        pop();
        int op2 = peek();
        pop();
        if (*input == '+')
          push(op1 + op2);
        else if (*input == '-')
          push(op1 - op2);
        else if (*input == '/')
          push(op1 / op2);
        else
          push(op1 * op2);
      }
      else if (!isOperator(*input) && *input != ' ')
      {
        int num = 0;
        while (*input >= '0' && *input <= '9')
        {
          num *= 10;
          num += (*input - '0');
          input++;
        }
        push(num);
        printf("%d\n", num);
      }
      input++;
    }
    printf("%d\n", peek());
    pop();
  }
  return 0;
}
