#include<bits/stdc++.h>
#include"Queue.h"
using namespace std;

struct Node *root = NULL;

void Tcreate(){
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q,100);

    cout << "Enter root value : " ;
    cin >> x;
    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
        cout << "Enter left child of "<<p->data<<" :";
        cin >> x;
        if(x!=-1){
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        cout << "Enter right child of " << p->data << " :";
        cin >> x;
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
    
}

void preOrder(struct Node *p){
    if(p){
        cout << p->data<<" ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}
void inOrder(struct Node *p){
    if(p){
        inOrder(p->lchild);
        cout << p->data<<" ";
        inOrder(p->rchild);
    }
}
void postOrder(struct Node *p){
    if(p){
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout << p->data<<" ";
    }
}

int main(){
    Tcreate();
    preOrder(root);
    return 0;
}