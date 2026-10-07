#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

//循环队列的大部分操作和顺序队列其实是一样的，只是在某些判断是否满，和入队时队尾的取值有一些差别
typedef struct queue{
    ElemType data[MAXSIZE];
    int front;
    int rear;
}Queue;

//初始化
void initQueue(Queue *Q){
    Q->front = 0;
    Q->rear = 0;
}

//判断是否为空
int IsEmpty(Queue *Q){
    if(Q->front == Q->rear){
        printf("Queue is empty.\n");
        return 1;
    } 
    else{
        return 0;
    }
}

//入队(这里发现循环队列似乎有一个bug，就是最多只能装进MAXSIZE-1个元素，因此上面的判断为空不需要考虑同余的情况)
int enqueue(Queue *Q,ElemType e){
    if((Q->rear + 1) % MAXSIZE == Q->front){
        printf("Queue is full.\n");
        return 0;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return 1; 
}

//出队
int dequeue(Queue *Q,ElemType *e){
    if(Q->rear == Q->front){
        printf("Queue is empty.\n");
        return 0;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 1;
}

//获取队头数据
int getHead(Queue *Q,ElemType *e){
    if(Q->front == Q->rear){
        printf("Queue is empty.\n");
        return 0;
    }
    *e = Q->data[Q->front];
    return 1;
}

//主函数
int main(){
    //创建队列并初始化
    Queue Q;
    initQueue(&Q);

    //添加元素
    enqueue(&Q,11);
    enqueue(&Q,45);
    enqueue(&Q,14);
    enqueue(&Q,19);
    enqueue(&Q,81);

    //出队
    ElemType e;
    dequeue(&Q,&e);
    printf("%d\n",e);
    dequeue(&Q,&e);
    printf("%d\n",e);
    getHead(&Q,&e);
    printf("%d\n",e);

    return 0;
}