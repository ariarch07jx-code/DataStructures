#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

// 结点类型：ATOM=原子（存值），LIST=子表（存表头 + 表尾）
typedef enum { ATOM, LIST } ElemTag;

typedef struct GLNode {
    ElemTag tag;
    union {
        ElemType value;         // 原子结点存的值
        struct {
            struct GLNode *hp;  // 表头指针
            struct GLNode *tp;  // 表尾指针
        } ptr;
    };
} GLNode;

// 创建原子结点
GLNode* atom(ElemType v) {
    GLNode *p = (GLNode*)malloc(sizeof(GLNode));
    p->tag = ATOM;
    p->value = v;
    return p;
}

// 创建表结点：hp = 表头，tp = 表尾（空表尾用 NULL 表示）
GLNode* cons(GLNode *hp, GLNode *tp) {
    GLNode *p = (GLNode*)malloc(sizeof(GLNode));
    p->tag = LIST;
    p->ptr.hp = hp;
    p->ptr.tp = tp;
    return p;
}

// 求深度：空表 = 1，原子 = 0，表 = 所有子表深度的最大值 + 1
int GListDepth(GLNode *L) {
    if (L == NULL) return 1;        // 空表
    if (L->tag == ATOM) return 0;   // 原子

    int max = 0;
    for (GLNode *p = L; p != NULL; p = p->ptr.tp) {
        int d = GListDepth(p->ptr.hp);
        if (d > max) max = d;
    }
    return max + 1;
}

// 释放（递归）。注意：若有子表被共享，直接这样释放会重复 free，
// 共享场景需要引用计数，这里测试用例没有共享，所以没问题。
void destroyList(GLNode *L) {
    if (L == NULL) return;
    if (L->tag == ATOM) {
        free(L);
    } else {
        destroyList(L->ptr.hp);
        destroyList(L->ptr.tp);
        free(L);
    }
}

int main(void) {
    // A = ()，空表，深度 1
    GLNode *A = NULL;

    // B = (1)，深度 1
    GLNode *B = cons(atom(1), NULL);

    // C = (1, (2, 3, 4))，深度 2
    GLNode *bcd = cons(atom(2), cons(atom(3), cons(atom(4), NULL))); // (2,3,4)
    GLNode *C = cons(atom(1), cons(bcd, NULL));                       // (1,(2,3,4))

    // D = (1, (2, (3)))，深度 3
    GLNode *d3 = cons(atom(3), NULL);                                 // (3)
    GLNode *d2 = cons(atom(2), cons(d3, NULL));                       // (2,(3))
    GLNode *D = cons(atom(1), cons(d2, NULL));                        // (1,(2,(3)))

    printf("A = ()            depth = %d\n", GListDepth(A));
    printf("B = (1)           depth = %d\n", GListDepth(B));
    printf("C = (1,(2,3,4))   depth = %d\n", GListDepth(C));
    printf("D = (1,(2,(3)))   depth = %d\n", GListDepth(D));

    destroyList(B);
    destroyList(C);
    destroyList(D);

    return 0;
}
