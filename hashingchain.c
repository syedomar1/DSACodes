#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
 
void sortedInsert(struct Node **H,int x){
    struct Node *t,*q=NULL,*p=*H;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (*H==NULL)
    {
        *H=t;
    }
    else{
        while(p&&p->data<x){
            q=p;
            p=p->next;
        }
        if (p==*H)
        {
            t->next = *H;
            *H=t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }
}

struct Node *search(struct Node *p,int key){
    while(p!=NULL){
        if (key==p->data)
        {
            return p;
        }
        p=p->next;
    }
    return NULL;
}
int hash(int key){
    return key%11;
}
void insert(struct Node *H[],int key){
    int index=hash(key);
    sortedInsert(&H[index],key);
}
int main()
{
    struct Node *HT[10];
    struct Node *temp;
    for (int i = 0; i < 10; i++)
    {
        HT[i] = NULL;
    }
    insert(HT,12);
    insert(HT,22);
    insert(HT,42);
    
    temp = search(HT[hash(22)],22);
    if(temp != NULL) {
        printf("%d",temp->data);
    } else {
        printf("Element not found");
    }
    return 0;
}
