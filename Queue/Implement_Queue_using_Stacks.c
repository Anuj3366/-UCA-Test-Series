#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
  int arr[100];
  int start;
  int end;
  int count;
} MyQueue;

MyQueue *myQueueCreate()
{
  MyQueue *obj = (MyQueue *)malloc(sizeof(MyQueue));
  obj->start = 0;
  obj->end = 0;
  obj->count = 0;
  return obj;
}

void myQueuePush(MyQueue *obj, int x)
{
  if (obj == NULL)
    return;
  obj->arr[obj->end] = x;
  obj->end++;
  obj->count++;
}

int myQueuePop(MyQueue *obj)
{
  if (obj == NULL)
    return NULL;
  int temp = obj->arr[obj->start];
  obj->start++;
  obj->count--;
  return temp;
}

int myQueuePeek(MyQueue *obj)
{
  if (obj == NULL)
    return NULL;
  return obj->arr[obj->start];
}

bool myQueueEmpty(MyQueue *obj)
{
  return obj->count == 0;
}

void myQueueFree(MyQueue *obj)
{
  free(obj);
}