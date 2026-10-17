#include <stdio.h>

#define MAXSIZE 100

typedef int ElemType;

typedef struct {
    int row, col;
    ElemType value;
} Triple;

typedef struct {
    Triple data[MAXSIZE + 1];  // data[0] 不用，从下标 1 存
    int rows, cols, nums;      // 总行数、总列数、非零元素个数
} TSMatrix;

// 打印三元组表
void printTriples(TSMatrix M, const char *name) {
    printf("%s (%d 行 x %d 列, %d 个非零元素):\n", name, M.rows, M.cols, M.nums);
    for (int i = 1; i <= M.nums; i++) {
        printf("  (%d, %d) = %d\n", M.data[i].row, M.data[i].col, M.data[i].value);
    }
    printf("\n");
}

// 普通转置：按原矩阵列号逐列扫描，O(cols * nums)
void Transpose(TSMatrix M, TSMatrix *T) {
    T->rows = M.cols;
    T->cols = M.rows;
    T->nums = M.nums;
    if (M.nums == 0) return;

    int q = 1;
    for (int col = 1; col <= M.cols; col++) {
        for (int p = 1; p <= M.nums; p++) {
            if (M.data[p].col == col) {
                T->data[q].row = M.data[p].col;
                T->data[q].col = M.data[p].row;
                T->data[q].value = M.data[p].value;
                q++;
            }
        }
    }
}

// 快速转置：先统计每列个数、算出起始位置，再一遍扫描放到位，O(cols + nums)
void FastTranspose(TSMatrix M, TSMatrix *T) {
    T->rows = M.cols;
    T->cols = M.rows;
    T->nums = M.nums;
    if (M.nums == 0) return;

    int num[MAXSIZE + 1], cpot[MAXSIZE + 1];
    for (int col = 1; col <= M.cols; col++) num[col] = 0;

    for (int p = 1; p <= M.nums; p++)          // 统计每列非零元素个数
        num[M.data[p].col]++;

    cpot[1] = 1;                               // 算每列第一个元素在新表中的位置
    for (int col = 2; col <= M.cols; col++)
        cpot[col] = cpot[col - 1] + num[col - 1];

    for (int p = 1; p <= M.nums; p++) {        // 一遍扫描直接放到位
        int col = M.data[p].col;
        int q = cpot[col];
        T->data[q].row = M.data[p].col;
        T->data[q].col = M.data[p].row;
        T->data[q].value = M.data[p].value;
        cpot[col]++;                           // 该列下一个元素放后一格
    }
}

int main(void) {
    // 原矩阵（3 行 4 列，5 个非零元素）:
    // 1 0 0 4
    // 0 5 0 0
    // 7 0 0 9
    TSMatrix M;
    M.rows = 3;
    M.cols = 4;
    M.nums = 5;
    M.data[1] = (Triple){1, 1, 1};
    M.data[2] = (Triple){1, 4, 4};
    M.data[3] = (Triple){2, 2, 5};
    M.data[4] = (Triple){3, 1, 7};
    M.data[5] = (Triple){3, 4, 9};

    TSMatrix T1, T2;
    Transpose(M, &T1);
    FastTranspose(M, &T2);

    printTriples(M, "原矩阵 M");
    printTriples(T1, "普通转置 T1");
    printTriples(T2, "快速转置 T2");

    return 0;
}
