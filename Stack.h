#ifndef Stack_h
#define Stack_h
#include"Queue.h"
#include <bits/stdc++.h>
using namespace std;

struct Stack{
    int size;
    int top;
    struct Node **S;
};

void stackCreate(struct Stack *st, int size){
    st->size = size;
    st->top = -1;
    st->S = (struct Node **)malloc(st->size * sizeof(struct Node *));
}

void push(struct Stack *st, struct Node *x){
    if(st->top==st->size-1){
        cout << "Stack Overflown";
    }
    else{
        st->top++;
        st->S[st->top] = x;
    }
}

struct Node *pop(struct Stack *st){
    struct Node *x = NULL;

    if(st->top==-1)
        cout << "Stack Underflown";
    else{
        x = st->S[st->top--];
    }
    return x;
}

int isEmptyStack(struct Stack st){
    if(st.top==-1)
        return 1;
    return 0;
}

int isFullStack(struct Stack st){
    return st.top == st.size - 1;
}

#endif