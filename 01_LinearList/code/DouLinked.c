#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef int ElemType;  

typedef struct DNode{
    ElemType data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

//初始化
DNode* InitList(){
    DNode *head = (DNode*)malloc(sizeof(DNode));
    head->data = 0;
    head->prev = NULL;
    head->next = NULL;
    return head;
}

//头插法插入元素
void insertHead(DNode *L,ElemType e){
    DNode *newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = e;
    newNode->next = L->next;
    newNode->prev = L;
    if(L->next != NULL){
        L->next->prev = newNode;
    }
    L->next = newNode;
}

//尾插法插入元素
void insertTail(DNode *L,ElemType e){
    DNode *newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = e;
    newNode->next = NULL;
    DNode *p = L;
    while(p->next != NULL){
        p = p->next;
    }
    newNode->prev = p;
    p->next = newNode;
}

//在指定位置插入元素
int insertElem(DNode *L,int pos,ElemType e){
    if(pos < 1 || pos > MAXSIZE){
        printf("Position is invalid\n");
        return 0;
    }
    DNode *newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = e;
    DNode *p = L;
    //找到指定位置的前置节点
    for(int i = 1;i < pos;i++){
        if(p->next == NULL){
            printf("Position is invalid\n");
            free(newNode);
            return 0;
        }
        p = p->next;
    }
    newNode->next = p->next;
    newNode->prev = p;
    if(newNode->next != NULL){
        newNode->next->prev = newNode;
    }
    p->next = newNode;
    return 1;
}

//删除指定位置元素
int deleteElem(DNode *L,int pos){
    if(pos < 1 || pos > MAXSIZE){
        printf("Position is invalid\n");
        return 0;
    }
    DNode *p = L;
    //找到要删除位置的前置节点
    for(int i = 1;i < pos;i++){
        if(p->next == NULL){
            printf("Position is invalid\n");
            return 0;
        }
        p = p->next;
    }
    DNode *temp = p->next;
    p->next = temp->next;
    if(temp->next != NULL){
        temp->next->prev = p;
    }
    free(temp);
    return 1;
}

//遍历链表
void traverseList(DNode *L){
    DNode *p = L->next;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

//主函数
int main(){
    //创建链表并初始化
    DNode *head = InitList();

    //头插法插入元素
    insertHead(head, 11);
    insertHead(head, 45);
    insertHead(head, 14);
    traverseList(head);

    //尾插法插入元素
    insertTail(head, 19);
    insertTail(head, 81);
    insertTail(head, 10);
    traverseList(head);

    //在指定位置插入元素
    insertElem(head,3,77);
    traverseList(head);

    //删除指定位置的元素
    deleteElem(head,4);
    traverseList(head);

    return 0;
}