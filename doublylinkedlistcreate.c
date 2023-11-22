#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*head=NULL;

void create(int arr[],int n){
    struct Node *t,*last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = arr[0];
    head ->prev = head->next = NULL;
    last = head;
    for (int i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }    
}

void display(struct Node *p){
    while (p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int length(struct Node *p){
    int len=0;
    while (p)
    {
        len++;
        p=p->next;
    }
    return len;
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
    display(head);
    return 0;
}

