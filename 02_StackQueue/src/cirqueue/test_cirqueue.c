#include <assert.h>
#include <stdio.h>

#include "cirqueue.h"

// 基础行为：空判、入队、FIFO 出队、读队头
static void test_basic(void) {
    CirQueue q;
    cirqueue_init(&q);
    assert(cirqueue_is_empty(&q));
    assert(cirqueue_size(&q) == 0);

    ElemType v;
    assert(cirqueue_dequeue(&q, &v) == false);  // 空队出队失败
    assert(cirqueue_front(&q, &v) == false);    // 空队读队头失败

    assert(cirqueue_enqueue(&q, 11));
    assert(cirqueue_enqueue(&q, 45));
    assert(cirqueue_enqueue(&q, 14));
    assert(!cirqueue_is_empty(&q));
    assert(cirqueue_size(&q) == 3);

    assert(cirqueue_front(&q, &v) && v == 11);   // 读队头不删除
    assert(cirqueue_dequeue(&q, &v) && v == 11); // FIFO
    assert(cirqueue_dequeue(&q, &v) && v == 45);
    assert(cirqueue_dequeue(&q, &v) && v == 14);
    assert(cirqueue_is_empty(&q));
}

// 判满 + 环形环绕后的顺序正确性
static void test_full_and_wrap(void) {
    CirQueue q;
    cirqueue_init(&q);
    ElemType v;

    // 填满到 CIRQUEUE_MAX - 1 个
    for (int i = 0; i < CIRQUEUE_MAX - 1; i++) {
        assert(cirqueue_enqueue(&q, i));
    }
    assert(cirqueue_is_full(&q));
    assert(cirqueue_enqueue(&q, 999) == false); // 满了，入队失败

    // 出队一半，再补一半，制造 rear 绕回数组头部的情况
    for (int i = 0; i < CIRQUEUE_MAX / 2; i++) {
        assert(cirqueue_dequeue(&q, &v) && v == i);
    }
    for (int i = 0; i < CIRQUEUE_MAX / 2; i++) {
        assert(cirqueue_enqueue(&q, i + 1000));
    }

    // 环绕后仍按 FIFO 顺序
    for (int i = CIRQUEUE_MAX / 2; i < CIRQUEUE_MAX - 1; i++) {
        assert(cirqueue_dequeue(&q, &v) && v == i);
    }
    for (int i = 0; i < CIRQUEUE_MAX / 2; i++) {
        assert(cirqueue_dequeue(&q, &v) && v == i + 1000);
    }
    assert(cirqueue_is_empty(&q));
    assert(cirqueue_size(&q) == 0);
}

int main(void) {
    test_basic();
    test_full_and_wrap();
    printf("All tests passed.\n");
    return 0;
}
