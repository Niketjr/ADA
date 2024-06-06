#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_SIZE 1000 

typedef struct {
    int stack1[MAX_SIZE];
    int top1;
    int stack2[MAX_SIZE];
    int top2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->top1 = -1; 
    obj->top2 = -1; 
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    if (obj->top1 == MAX_SIZE - 1) {
        
        return;
    }
    obj->stack1[++obj->top1] = x; 
}

int myQueuePop(MyQueue* obj) {
    if (obj->top2 == -1) {
        
        while (obj->top1 != -1) {
            obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
        }
    }
    if (obj->top2 == -1) {
        
        return 0;
    }
    return obj->stack2[obj->top2--]; 
}

int myQueuePeek(MyQueue* obj) {
    if (obj->top2 == -1) {
        
        while (obj->top1 != -1) {
            obj->stack2[++obj->top2] = obj->stack1[obj->top1--];
        }
    }
    if (obj->top2 == -1) {
        
        return 0;
    }
    return obj->stack2[obj->top2]; 
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->top1 == -1 && obj->top2 == -1; 
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}
