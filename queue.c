#include <stdio.h>
#include <stdbool.h>
int size;
int fr;
int back=-1;
bool empty(){
    if ((fr>back)|(back==-1))
    {
        return true;
    }
    return false;
}
bool full(){
    if (back==size-1)
    {
        return true;
    }
    return false;
}
void enqueue(int stk[]){
    int val;
    if (full())
    {
        printf("Queue is full");
    }
    else{
        scanf("%d",&val);
        stk[++back]=val;
        if (back==0)
        {
            fr=0;
        }
    }
}
int dequeue(int stk[]){
    if (empty()){
        printf("Queue is empty\n");
        return -1;
    }
    else{
        int val = stk[fr++];
        if (fr>back)
        {
            fr=back=-1;
        }
        printf("Removed element is %d", val);
    }
}
void display(int stk[]){
    if (empty()) {
        printf("Queue is empty\n");
        return;
    }
    else{
        for (int i = fr; i <= back; i++)
        {
            printf("%d ",stk[i]);
        }
        printf("\n");
    }
}
int main()
{
  int n, ch;
  printf ("Enter no of elements: \n");
  scanf ("%d", &n);
  size = n; // Update size to be equal to n
  fr = 0;
  int arr[n], run=0;
  while(run!=4){
      printf ("Choose from the menu\n");
      printf ("Enter 1 to Enqueue the elements\n");
      printf ("Enter 2 to Dequeue the elements\n");
      printf ("Enter 3 to Display the elements\n");
      printf ("Enter 4 to Exit\n");
      scanf ("%d", &ch);
      run=ch;
      switch (ch)
        {
        case 1:
          enqueue(arr);
          break;
        case 2:
          dequeue(arr);
          break;
        case 3:
          display (arr);
          break;
        }
      }
  return 0;
}