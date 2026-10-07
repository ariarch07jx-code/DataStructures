#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

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

//出队
int dequeue(Queue *Q,ElemType *e){
    if(Q->front == Q->rear){
        printf("Queue is empty.\n");
        return 0;
    }
    *e = Q->data[Q->front];
    Q->front++;
    return 1;
}

//队尾满了，调整队列
int queueFull(Queue *Q){
    if(Q->front > 0){
        int step = Q->front;
        for(int i = Q->front;i < Q->rear;++i){
            Q->data[i-step] = Q->data[i];
        }
        Q->front = 0;
        Q->rear = Q->rear - step;
        return 1;
    }
    else{
        printf("Queue is really full!\n");
        return 0;
    }
}

//入队
int enqueue(Queue *Q,ElemType e){
    if(Q->rear >= MAXSIZE){
        if(!queueFull(Q)){  //判定是否真的满了，否则只移动队列数据位置，不返回0，继续执行下面的命令
            return 0;
        }
    }
    Q->data[Q->rear] = e;
    Q->rear++;
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