#include <stdio.h>
#define MAX 3
int queue[MAX];
int front=-1,rear=-1;
void insert(){
    int item;
    if(rear==MAX-1)
        printf("\n Queue Overflow");
    else{
        printf("Enter element to insert:");
        scanf("%d",&item);
        if(front==-1)front=0;
        rear++;
        queue[rear]=item;
        printf("Inserted %d\n",item);
    }
}
void delete(){
    if(front==-1||front>rear)
        printf("Queue underflow\n");
    else{
        printf("Deleted %d\n",queue[front]);
        front++;
    }
}
void display(){
    printf("Queue elements:");
    for(int i=front;i<=rear;i++){
        printf("%d",queue[i]);
    }
}
int main(){
    int choice;
    printf("Queue implementation using array\n");
    while(1){
        printf("\n 1.Insert, 2.Delete, 3.Display, 4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:insert();
                break;
            case 2:delete();
                break;
            case 3:display();
                break;
            case 4:return 0;
            default:printf("Invalid choice\n");
        }
    }return 0;
}
