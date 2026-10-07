#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

//栈的链式结构实现
typedef struct stack{
    ElemType data;
    struct stack *next;
}Stack;

//初始化（将链表中头节点的下一个节点视为栈顶，尾节点视为栈底）
Stack* initStack(){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data = 0;
    s->next = NULL;

    return s;
}

//判断栈是否为空
int isEmpty(Stack *s){
    if(s->next == NULL){
        printf("Stack is empty.\n");
        return 1;
    }
    else{
        return 0;
    }
}

//压栈（相当于链表中的头插法）
int push(Stack *s,ElemType e){
    Stack *p = (Stack*)malloc(sizeof(Stack));
    p->data = e;
    p->next = s->next;
    s->next = p;
    return 1;
}

//出栈（删除头节点后一个节点的数据）
int pop(Stack *s,ElemType *e){
    if(s->next == NULL){
        printf("Stack is empty.\n");
        return 0;
    }
    *e = s->next->data;
    Stack *q = s->next;
    s->next = s->next->next;
    free(q);
    return 1;
}

//获取栈顶元素
int getTop(Stack *s,ElemType *e){
    if(s->next == NULL){
        printf("Stack is empty.\n");
        return 0;
    }
    *e = s->next->data;
    return 1;
}

int main(){
    //创建并初始化
    Stack *s = initStack();

    //入栈
    push(s,11);
    push(s,45);
    push(s,14);

    ElemType e;
    //出栈
    pop(s,&e);
    printf("%d\n",e);

    //获取栈顶元素
    getTop(s,&e);
    printf("%d\n",e);
    
    return 0;
}