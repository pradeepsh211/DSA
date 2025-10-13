#include <stdio.h>
#define MAX 3
int cqueue[MAX];
int front=-1,rear=-1;
void insert(){
    int item;
    if((rear==MAX-1&&front==0)||(front==rear+1))
        printf("\n Queue Overflow");
    else{
        printf("Enter element to insert:");
        scanf("%d",&item);
        if(front==-1)front=rear=0;
        else if(rear==MAX-1)
            rear=0;
        else
            rear++;
            cqueue[rear]=item;
            printf("Inserted %d\n",item);
    }

}
void delete(){
    if(front==-1)
        printf("Queue underflow\n");
    else{
        printf("Deleted %d\n",cqueue[front]);
        if(front==rear)
            front=rear-1;
        else if(front==MAX-1)
            front=0;
        else
            front++;
    }
}
void display(){
    printf("Queue elements:");
    int i=front;
    while(1){
        printf("%d ",cqueue[i]);
        if(i==rear)
            break;
        i=(i+1)%MAX;
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
