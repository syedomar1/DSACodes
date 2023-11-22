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
int delete(struct Node *p,int index){
    struct Node *t;
    int x= -1;
    if (index<1 || index>length(p))
    {
        return -1;
    }
    if (index==1)
    {
            head = head->next;
            if (head)
            {
                head->prev = NULL;
            }
            x= p->data;
            free(p);           
    }
    else{
        for (int i = 0; i < index-1; i++)
        {
            p=p->next;
        }
        p->prev->next = p->next;
        if (p->next)
        {
            p->next->prev = p->prev;
        }
        p->data;
        free(p);
    }
    return x;
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
    delete(head,0);
    display(head);
    return 0;
}