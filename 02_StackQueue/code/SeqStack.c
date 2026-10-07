#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef int ElemType;

//栈的顺序结构实现
typedef struct stack{
    ElemType data[MAXSIZE];
    int top;
}Stack;

//初始化
void initstack(Stack *s){
    s->top = -1;
}

/*
//栈的动态内存分配初始化构建
typedef struct stack{
    ElemType *data;
    int top;
}Stack;

//初始化
Stack* initStack(){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    s->top = -1;
    return s;
}
*/
//判断栈是否为空
int IsEmpty(Stack *s){
    if(s->top == -1){
        printf("Empty.\n");
        return 1;
    }
    else{
        return 0;
    }
}

//进栈/压栈/入栈
int push(Stack *s,ElemType e){
    if(s->top >= MAXSIZE-1){
        printf("Stack is full.\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = e;

    return 1;
}

//出栈
int pop(Stack *s,ElemType *e){
    if(s->top == -1){
        printf("Stack is empty.\n");
        return 0;
    }
    *e = s->data[s->top];
    s->top--;
    return 1;
}

//获取栈顶元素
int getTop(Stack *s,ElemType *e){
    if(s->top == -1){
        printf("Stack is empty.\n");
        return 0;
    }
    *e = s->data[s->top];
    return 1;
}

int main(){
    //创建栈并初始化
    Stack s;
    initstack(&s); 

    //入栈
    push(&s,11);
    push(&s,45);
    push(&s,14);

    //出栈
    ElemType e;
    pop(&s,&e);
    printf("%d\n",e);
    getTop(&s,&e);
    printf("%d\n",e);

}