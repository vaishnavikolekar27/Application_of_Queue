#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

typedef struct node
{
    void *dataptr;
    struct node *next;
}QUEUE_NODE;

typedef struct
{
    QUEUE_NODE * front;
    QUEUE_NODE * rear;
    int count;
}QUEUE;

 QUEUE * createqueue(void)
 {
     QUEUE *queue;
     queue=(QUEUE*)malloc(sizeof(QUEUE));
     if(queue)
     {
         queue->front=NULL;
         queue->rear=NULL;
         queue->count=0;
     }
     return queue;

 }

 bool enqueue(QUEUE *queue, void *itemptr)
 {
     QUEUE_NODE *newptr;
     newptr=(QUEUE_NODE*)malloc(sizeof(QUEUE_NODE));
     if(newptr==NULL)
        {
            return false;
        }
        else
        {
            newptr->dataptr=itemptr;
     newptr->next=NULL;
        }
     if(queue->count==0)
        queue->front=newptr;
     else
        queue->rear->next=newptr;
        (queue->count)++;
        queue->rear=newptr;
        return true;
 }
 int  queuecount(QUEUE *queue)
 {
     return(queue->count);
 }

 void displayqueue(QUEUE *queue)
 {
     if((queue->front && queue->rear)==NULL)
    {
        printf("queue is empty\n");
    }
    while((queue->front && queue->rear)!=NULL)
    {
        printf("%d\n",queue->front->dataptr);
        queue->front=queue->front->next;
    }
 }



int main()
{
    QUEUE *queue1;
    QUEUE *queue2;
    QUEUE *queue3;
    QUEUE *queue4;

    queue1=createqueue();
    queue2=createqueue();
    queue3=createqueue();
    queue4=createqueue();

    int choice,data;
    while(1)
    {
        printf("1.ENQUEUE\n2.COUNT OF QUEUE 1\n3.COUNT OF QUEUE 2\n4.COUNT OF QUEUE 3\n5.COUNT OF QUEUE 4\n6.DISPLAY QUEUE 1\n7.DISPLAY QUEUE 2\n8.DISPLAY QUEUE 3\n9.DISPLAY QUEUE 4\n10.exit\n");
        printf("enter the choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("enter the number to be added to the queue:\n");
                    scanf("%d",&data);
                    if(data>0 && data <=24)
                    {
                        if(enqueue(queue1,data)==NULL)
                        {
                            printf("memory not allocated\n");

                        }
                        else
                            printf("data inserted in queue\n");
                    }
                    if(data>25 && data <=49)
                    {
                        if(enqueue(queue2,data)==NULL)
                        {
                            printf("memory not allocated\n");

                        }
                        else
                            printf("data inserted in queue\n");
                    }
                    if(data>50 && data <=74)
                    {
                        if(enqueue(queue3,data)==NULL)
                        {
                            printf("memory not allocated\n");

                        }
                        else
                            printf("data inserted in queue\n");
                    }
                    if(data>75 && data <=100)
                    {
                        if(enqueue(queue4,data)==NULL)
                        {
                            printf("memory not allocated\n");

                        }
                        else
                            printf("data inserted in queue\n");
                    }
                    break;

                    case 2:printf("the number of elements in queue 1 are %d\n",queuecount(queue1));
                        break;
                    case 3:printf("the number of elements in queue 2 are %d\n",queuecount(queue2));
                        break;
                    case 4:printf("the number of elements in queue 3 are %d\n",queuecount(queue3));
                        break;
                    case 5:printf("the number of elements in queue 4 are %d\n",queuecount(queue4));
                        break;
                    case 6:printf("the numbers present in queue1 are:\n");
                    displayqueue(queue1);
                            break;
                    case 7:printf("the numbers present in queue 2 are:\n");
                    displayqueue(queue2);
                            break;
                    case 8:printf("the numbers present in queue 3 are:\n");
                    displayqueue(queue3);
                            break;
                    case 9:printf("the numbers present in queue 4 are:\n");
                    displayqueue(queue4);
                            break;
                    case 10:exit(1);
                    default:
                        printf("invalid choice\n");


        }
    }
    return 0;


}
