#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

//数据类型定义
typedef struct node{
    ElemType data;
    struct node *next;
} Node;

//初始化
Node* InitList(){
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    return head;
}

//头插法插入元素
void insertHead(Node *L,ElemType e){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = e;
    newNode->next = L->next;
    L->next = newNode;
}

//尾插法插入元素
void insertTail(Node *L,ElemType e){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = e;
    newNode->next = NULL;

    Node *p = L;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = newNode;
}

//在指定位置插入元素
int insertElem(Node *L,int pos,ElemType e){
    if(pos < 1 || pos > MAXSIZE){
        printf("Position is invalid\n");
        return 0;
    }
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = e;
    Node *p = L;
    for(int i = 1;i < pos;i++){
        if(p->next == NULL){
            printf("Position is invalid\n");
            free(newNode);
            return 0;
        }
        p = p->next;
    }
    newNode->next = p->next;
    p->next = newNode;
    return 1;
}

//查找元素
Node* searchElem(Node *L,ElemType e){
    Node *p = L->next;
    while(p != NULL){
        if(p->data == e){
            return p;
        }
        p = p->next;
    }
    printf("Element not found\n");
    return NULL;
}

//查找倒数第k个元素
Node* searchKthElem(Node *L,int k){
    if(k < 1 || k > MAXSIZE){
        printf("Position is invalid\n");
        return NULL;
    }
    //快慢指针法
    Node *p = L->next;
    Node *q = L->next;
    for(int i = 0;i < k;i++){
        if(q == NULL){
            printf("Position is invalid\n");
            return NULL;
        }
        q = q->next;
    }
    while(q != NULL){
        p = p->next;
        q = q->next;
    }
    return p;
}

//反转链表
Node* reverseList(Node *L){
    Node *prev = NULL;
    Node *curr = L->next;
    while(curr != NULL){
        Node *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    L->next = prev;
    return L;
}

//删除节点
int deleteElem(Node *L,int pos){
    if(pos < 1 || pos > MAXSIZE){
        printf("Position is invalid\n");
        return 0;
    }
    Node *p = L;
    for(int i = 1;i < pos;i++){
        if(p->next == NULL){
            printf("Position is invalid\n");
            return 0;
        }
        p = p->next;
    }
    Node *temp = p->next;
    p->next = temp->next;
    free(temp);
    return 1;
}

//遍历
void traverseList(Node *L){
    Node *p = L->next;
    while(p != NULL){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

//释放链表
void freeList(Node *L){
    Node *p =L;
    while(p != NULL){
        Node *temp = p;
        p = p->next;
        free(temp);
    }
}

//主函数
int main(){
    //创建链表并初始化
    Node *head = InitList();

    //插入元素
    insertHead(head, 11);
    insertHead(head, 45);
    insertHead(head, 14);
    traverseList(head);
    insertTail(head, 19);
    insertTail(head, 81);
    insertTail(head, 10);
    traverseList(head);

    //在指定位置插入元素
    insertElem(head, 3, 66);
    traverseList(head);

    //删除节点
    deleteElem(head, 4);
    traverseList(head);

    //释放链表
    freeList(head);
    return 0;
}