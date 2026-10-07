#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

//结点结构
typedef struct qnode{
    ElemType data;
    struct qnode *next;
}QNode;

//队列的链式结构实现（带头节点）
typedef struct queue{
    QNode *front;   //队头指针（指向头节点）
    QNode *rear;    //队尾指针（指向队尾节点）
}Queue;

//初始化
Queue* initQueue(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    QNode *node = (QNode*)malloc(sizeof(QNode));
    node->data = 0;
    node->next = NULL;
    q->front = node;
    q->rear = node;
    return q;
}

//判断是否为空
int IsEmpty(Queue *Q){
    if(Q->front->next == NULL){
        printf("Queue is empty.\n");
        return 1;
    }
    else{
        return 0;
    }
}

//入队（尾插法）
int enqueue(Queue *Q,ElemType e){
    QNode *p = (QNode*)malloc(sizeof(QNode));
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;   //接到队尾
    Q->rear = p;         //更新队尾指针
    return 1;
}

//出队（删除队头元素）
int dequeue(Queue *Q,ElemType *e){
    if(Q->front->next == NULL){
        printf("Queue is empty.\n");
        return 0;
    }
    QNode *q = Q->front->next;   //队头元素
    *e = q->data;
    Q->front->next = q->next;   //头结点越过它
    if(Q->rear == q){           //若删的是最后一个元素，rear 回退到头结点
        Q->rear = Q->front;
    }
    free(q);
    return 1;
}

//获取队头数据
int getHead(Queue *Q,ElemType *e){
    if(Q->front->next == NULL){
        printf("Queue is empty.\n");
        return 0;
    }
    *e = Q->front->next->data;
    return 1;
}

//主函数
int main(){
    //创建队列并初始化
    Queue *q = initQueue();

    //添加元素
    enqueue(q,11);
    enqueue(q,45);
    enqueue(q,14);
    enqueue(q,19);
    enqueue(q,81);

    //出队
    ElemType e;
    dequeue(q,&e);
    printf("%d\n",e);
    dequeue(q,&e);
    printf("%d\n",e);
    getHead(q,&e);
    printf("%d\n",e);

    return 0;
}
