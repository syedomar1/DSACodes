#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*head=NULL;

void create(int arr[], int n){
    struct Node *t,*last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->next=NULL;
    last  = head;
    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next=NULL;
        last->next=t;
        last  = t;
    }
}
void sortedInsert(struct Node *p, int x){
    struct Node *t,*q=NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (head == NULL) 
    {
        head = t;
    }
    else{
        while (p && p->data<x)  
        {
            q=p;
            p = p->next;
        }
        if (p==head)    
        {
            t->next = head;
            head = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        } 
    }
}
void display(struct Node *p){
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter size of array: \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    create(arr,n);
    sortedInsert(head,20);
    display(head);
    printf("\n\n");
    return 0;
}