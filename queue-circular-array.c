/*
 *	Circular array implementation in C
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10 

int Q[SIZE];
int front = -1;
int rear = -1;

int IsEmpty()
{
	return (front == -1 && rear == -1);
}

int IsFull()
{
	return (rear + 1) % SIZE == front ? 1 : 0;
}

void Push(int x)
{
	if(IsFull())
	{
		printf("\n[X] Error. Queue is full. ''%d'' could not be added to the queue. \n\n",x);
		return ;
	}
	else if(IsEmpty())
		front = rear = 0;
	else
		rear = (rear + 1) % SIZE;
		
	Q[rear] = x;
}

int Pop()
{
	int value; // return value
	
	if(IsEmpty())
	{
		printf("\n[X] Error. Queue is empty. Return value '-1'\n");
		return -1;
	}
	else if(front == rear)
	{
		value = Q[front];
		front = rear = -1;
	}
	else
	{
		value = Q[front];
		front = (front + 1) % SIZE;
	}
	return value;
	
}

void Print()
{
	int i;
	int count = (rear + SIZE - front) % SIZE + 1;
	printf("Queue -->  ");
	for(i = 0; i < count; i++)
	{
		int index = (front + i) % SIZE;
		printf("%d ",Q[index]);
	}
	printf("\n");
}

int main()
{
	Push(1);  
	Print();  
   	Push(2);  
   	Print();  
  	Push(3);  
  	Print();
  	Pop();   
  	Print();
  	Push(4);  
  	Print();
  	Push(5);  
	Print();  
   	Push(6);  
   	Print();  
  	Push(7);  
  	Print();
  	Pop();   
  	Print();
  	Push(8);  
  	Print();
  	Push(9);  
	Print();  
   	Push(10);  
   	Print();  
  	Push(11);  
  	Print();
  	Pop();   
  	Print();
  	Push(12);  
  	Print();
  	Push(13);  
  	Print();
  	Push(14);
  	//Print();
  	int i;
  	for(i = 0; i < 11; ++i)
  		printf("Deleted: %d \n",Pop());

  	printf("\n");
}

