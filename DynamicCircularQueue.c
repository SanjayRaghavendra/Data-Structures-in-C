#include <stdio.h>
#include <stdlib.h>
int deleteq(void);
void display(void);
void addq(void);
typedef struct{
	int key;
}element;

int front=0,rear=0,capacity=1;
element *newq, *q;

void addq(void){
	int j,ele;
	if(front==(rear+1)%capacity){
		printf("queue full doubling size to %d\n", (2*capacity));
		newq = (element*)malloc(2*capacity*sizeof(element));
		for(j=0;j<capacity-1;j++)
			newq[j].key = deleteq();
		front = 2*capacity -1; // pointing to the last element of new queue
		rear = capacity-2;
		capacity = capacity*2;
		free(q);
		q = newq;

	}

	rear = (rear+1)%capacity;
	printf("enter the element ot be entered\n");
	scanf("%d",&ele);
	q[rear].key = ele;
}

int deleteq(void){
	front = (front+1)%capacity;
	return (q[front].key);
}

void display(void){
	printf("remaining elements are\n");
	for(int i = (front+1)%capacity; i!=(rear+1)%capacity; i=(i+1)%capacity)
		printf("%d\t", q[i].key );
	printf("\n");
}
int main(){
	int choice;
	q = (element*)malloc(sizeof(element));
	while(1){
		printf("Enter 1 for adding element, 2 for deleting, 3 for diplay and 4 for exiting\n");
		scanf("%d", &choice);
		switch(choice){
			case 1: addq();
					break;
			case 2: if(front==rear){
						printf("queue is empty\n");
					}
					else
						printf("element %d is deleted from the queue\n", deleteq());
					break;
			case 3: display();			
					break;
			case 4: printf("exiting...\n");
					exit(0);
			default: printf("Invalid choice\n");

		}
	}
	return 0;
}


