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

void IPreorder(struct Node *p)
{
    struct Stack stk;
    stackCreate(&stk, 100);

    while (p || !isEmptyStack(stk))
    {
        if (p)
        {
            cout << p->data << " ";
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            p = p->rchild;
        }
    }
}

void IInorder(struct Node *p)
{
    struct Stack stk;
    stackCreate(&stk, 100);

    while (p || !isEmptyStack(stk))
    {
        if (p)
        {
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            if (p)
            {
                cout << p->data << " ";
                p = p->rchild;
            }
        }
    }
}

void LevelOrder(struct Node *root)
{
    struct Queue q;
    create(&q, 100);
    cout << root->data<<" ";
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        root = dequeue(&q);
        if (root->lchild)
        {
            cout << root->lchild->data<<" ";
            enqueue(&q, root->lchild);
        }
        if (root->rchild)
        {
            cout << root->rchild->data<<" ";
            enqueue(&q, root->rchild);
        }
    }
}

int count(struct Node* root){
    if(root)
        return count(root->lchild) + count(root->rchild) + 1;
    return 0;
}

int height(struct Node* root){
    int x = 0, y = 0;
    if(root==0)
        return 0;
    x = height(root->lchild);
    y = height(root->rchild);
    if(x>y)
        return x + 1;
    else
        return y + 1;
}

int main(){
    Tcreate();
    preOrder(root);
    return 0;
}
