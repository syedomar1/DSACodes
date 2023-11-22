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
void display(struct Node *t){
    do
    {
        printf("%d ",t->data);
        t=t->next;
    } while (t!=head);
    printf("\n");
}

void recDisplay(struct Node *t){
    static int flag = 0;
    if (t!=head || flag ==0)
    {
        flag = 1;
        printf("%d ",t->data);
        recDisplay(t->next);
    }
    flag = 0;    
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
    recDisplay(head);
    return 0;
}