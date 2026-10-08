#ifndef CIRQUEUE_H
#define CIRQUEUE_H

#include <stdbool.h>

// 循环队列：数组实现，牺牲一个位置来区分「队空」和「队满」。
// 所以最多只能存 CIRQUEUE_MAX - 1 个元素。
#define CIRQUEUE_MAX 100

typedef int ElemType;

typedef struct {
    ElemType data[CIRQUEUE_MAX];
    int front;  // 队头下标
    int rear;   // 队尾的下一个位置（下次入队写入这里）
} CirQueue;

// 初始化
void cirqueue_init(CirQueue *q);

// 判空 / 判满
bool cirqueue_is_empty(const CirQueue *q);
bool cirqueue_is_full(const CirQueue *q);

// 入队 / 出队（out 带回取出的元素）
bool cirqueue_enqueue(CirQueue *q, ElemType e);
bool cirqueue_dequeue(CirQueue *q, ElemType *out);

// 读队头但不删除
bool cirqueue_front(const CirQueue *q, ElemType *out);

// 当前元素个数
int cirqueue_size(const CirQueue *q);

#endif
