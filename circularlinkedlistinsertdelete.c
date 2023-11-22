#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*head;
void create(int arr[], int n){
    struct Node *t,*last;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data=arr[0];
    head->next=head;
    last = head;
    for (int i = 1; i < n; i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next = last->next;
        last -> next = t ;
        last = t;
    }
}

int length(struct Node *p){
    int len = 0;
    do
    {
        len++;
        p=p->next;
    } while (p!=head);
    return len;    
}

void insert(struct Node *p, int index, int x){
    struct Node *t;
    if (index<0 || index> length(p)) 
        return;
    if (index==0)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data =x;
        if (head == NULL)
        {
            head = t;
            head ->next = head;
        }
        else{
            while (p->next!=head)
            {
                p=p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }        
    }
    else{
        for (int i = 0; i < index-1; i++)
        {
            p=p->next;
        }
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int delete(struct Node *p, int index){
    struct Node *q;
    int x;
    if (index<0 || index>length(head))
    {
        return -1;
    }
    if (index==1)
    {
        while (p->next != head)
        {
            p=p->next;
        }
        x=head->data;
        if (head == p)
        {
            free(head);
            head = NULL;
        }
        else{
            p->next = head->next;
            free(head);
            head=p->next;
        }        
    }
    else{
        for (int i = 0; i < index-2; i++)
        {
            p=p->next;
        }
        q=p->next;
        p->next = q->next;
        x=q->data;
        free(q);        
    }
    return x;    
}

void display(struct Node *t){
    do
    {
        printf("%d ",t->data);
        t=t->next;
    } while (t!=head);
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
    insert(head,2,33);
    delete(head,3);
    display(head);
    return 0;
}