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

void display(struct Node *p){
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void recdisplay(struct Node *p){
    if (p!=NULL)
    {
        recdisplay(p->next);
        printf("%d ",p->data);
    }
}
int count(struct Node *p){
    int l=0;
    while (p)
    {
        l++;
        p=p->next;
    }
    return l;    
}
void insert(struct Node *p, int index, int x){
    struct Node *t;
    if (index<0 || index>count(p))
    {
        return;
    }
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (index==0){
        t->next = head;
        head    = t;
    }
    else{
        for (int i = 0; i < index-1; i++)
        {
            p=p->next;
            t->next = p->next;
            p->next = t;
        }        
    }
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
    insert(head,0,5);
    display(head);
    recdisplay(head);
    return 0;
}