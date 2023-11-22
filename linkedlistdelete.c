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
int count(struct Node *p){
    int l=0;
    while (p)
    {
        l++;
        p=p->next;
    }
    return l;    
}

int delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1;
    if (index<1 || index > count(p))   
    {
        return -1;
    }
    if (index == 1)
    {
        q = head;
        x = head-> data;
        head = head->next;
        free(q);
        return x;
    }
    else{
        for (int i = 0; i < index-1; i++)
        {
            q=p;
            p=p->next;
        }
        q->next = p->next;
        x=p->data;
        free(p);
        return x;        
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
    printf("Deleted element is %d\n", delete(head,1));
    display(head);
    return 0;
}