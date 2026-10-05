#include<stdio.h>

#define MAXSIZE 100

typedef int ElemType;

//数据类型定义
typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SeqList;

//初始化
void InitList(SeqList *L){
    L->length = 0;
}

//尾部添加元素
int appendElem(SeqList *L,ElemType e){
    if(L->length >= MAXSIZE){
        printf("List is full\n");
        return 0;
    }
    L->data[L->length] = e;
    L->length++;
    return 1;
}

//在指定位置插入元素
int insertElem(SeqList *L,int pos,ElemType e){
    if(pos < 1 || pos > L->length + 1){
        printf("Position is invalid\n");
        return 0;
    }
    if(L->length >= MAXSIZE){
        printf("List is full\n");
        return 0;
    }
    for(int i = L->length - 1;i >= pos - 1;i--){
        L->data[i+1]=L->data[i];
    }
    L->data[pos - 1] = e;
    L->length++;
    return 1;
}

//删除指定位置的元素
int deleteElem(SeqList *L,int pos){
    if(pos < 1 || pos > L->length){
        printf("Position is invalid\n");
        return 0;
    }
    for(int i = pos - 1;i < L->length - 1;i++){
        L->data[i] = L->data[i+1];
    }
    L->length--;
    return 1;
}

//查找元素
int findElem(SeqList *L,ElemType e){
    for(int i = 0;i < L->length;i++){
        if(L->data[i] == e){
            return i + 1; //返回位置，从1开始
        }
    }
    return -1; //未找到
}

//遍历
void traverseList(SeqList *L){
    for(int i = 0;i < L->length;i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}

//主函数
int main(){
    //创建顺序表并初始化
    SeqList L;
    InitList(&L);
    printf("Initial length: %d\n",L.length);
    
    //添加元素
    appendElem(&L,11);
    appendElem(&L,45);
    appendElem(&L,14);
    appendElem(&L,19);
    appendElem(&L,81);
    traverseList(&L);

    //在指定位置插入元素
    insertElem(&L,3,99);
    traverseList(&L);

    //删除指定位置的元素
    deleteElem(&L,5);
    traverseList(&L);

    //查找元素
    int pos = findElem(&L,45);
    if(pos != -1){
        printf("Element found at position: %d\n",pos);
    }else{
        printf("Element not found\n");
    }
    return 0;
}