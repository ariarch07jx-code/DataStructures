#include "cirqueue.h"

void cirqueue_init(CirQueue *q) {
    q->front = 0;
    q->rear = 0;
}

bool cirqueue_is_empty(const CirQueue *q) {
    return q->front == q->rear;
}

// 队尾再进一格就撞上队头，视为满（那一格始终空着，所以最多存 MAX-1 个）
bool cirqueue_is_full(const CirQueue *q) {
    return (q->rear + 1) % CIRQUEUE_MAX == q->front;
}

bool cirqueue_enqueue(CirQueue *q, ElemType e) {
    if (cirqueue_is_full(q)) {
        return false;
    }
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % CIRQUEUE_MAX;
    return true;
}

bool cirqueue_dequeue(CirQueue *q, ElemType *out) {
    if (cirqueue_is_empty(q)) {
        return false;
    }
    *out = q->data[q->front];
    q->front = (q->front + 1) % CIRQUEUE_MAX;
    return true;
}

bool cirqueue_front(const CirQueue *q, ElemType *out) {
    if (cirqueue_is_empty(q)) {
        return false;
    }
    *out = q->data[q->front];
    return true;
}

// 差值 + MAX 再取模，能正确处理 rear 绕回 front 前面（差值为负）的情况
int cirqueue_size(const CirQueue *q) {
    return (q->rear - q->front + CIRQUEUE_MAX) % CIRQUEUE_MAX;
}
