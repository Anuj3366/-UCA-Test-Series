#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
  int *arr;
  int front;
  int rear;
  int capacity;
} MyCircularQueue;

MyCircularQueue *myCircularQueueCreate(int k)
{
  MyCircularQueue *queue = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
  queue->arr = (int *)malloc(sizeof(int) * k);
  queue->capacity = k;
  queue->front = -1;
  queue->rear = -1;
  return queue;
}

bool myCircularQueueEnQueue(MyCircularQueue *obj, int value)
{
  if((obj->rear + 1) % obj->capacity == obj->front){
    return false;
  }
  if(obj->front == -1)obj->front = 0;
  obj->rear = (obj->rear + 1) % obj->capacity;
  obj->arr[obj->rear] = value;
  return true;
}

bool myCircularQueueDeQueue(MyCircularQueue *obj)
{
  if(obj->front == -1){
    return false;
  }
  if(obj->front == obj->rear){
    obj->front = -1;
    obj->rear = -1;
    return true;
  }
  obj->front = (obj->front + 1) % obj->capacity;
  return true;
}

int myCircularQueueFront(MyCircularQueue *obj)
{
  if(obj->front == -1){
    return -1;
  }
  return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue *obj)
{
  if(obj->rear == -1){
    return -1;
  }
  return obj->arr[obj->rear];
}

bool myCircularQueueIsEmpty(MyCircularQueue *obj)
{
  return obj->front == -1;
}

bool myCircularQueueIsFull(MyCircularQueue *obj)
{
  return (((obj->rear + 1) % obj->capacity )== obj->front);
}

void myCircularQueueFree(MyCircularQueue *obj)
{
  free(obj->arr);
  free(obj);
}