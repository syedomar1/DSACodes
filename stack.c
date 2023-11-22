#include <stdio.h>
int top = -1;
int empty ()
{
  if (top == -1)
    {
      return 1;
    }
  return 0;
}
int full (int n)
{
  if (top == n - 1)
    {
      return 1;
    }
  return 0;
}
void push (int arr[], int n)
{
    int value=0;
    if(full(n)==1){
        printf("Stack is full\n");
        return;
    }
    else{
        printf("Enter a value\n");
        scanf("%d",&value);
        arr[++top] = value;
        printf("Value added succesfully\n");
    }
}
void pop(int arr[]){
    if(empty()==1){
        printf("Stack is empty\n");
        return;
    }
    else{
        printf("Popped element is: %d\n",arr[top]);
        top--;
    }
}
void peek(int arr[]){
    if(empty()==1){
        printf("Stack is empty\n");
    }
    else{
        printf("The peek element is %d\n",arr[top]);
    }
}
void display(int arr[]){
    if(empty()==1){
        printf("Stack is empty\n");
        return;
    }
    printf("Top: %d\n",arr[top]);
    for(int i=top-1;i>=0;i--){
        printf("%d\n",arr[i]);
    }
}

int main ()
{
  int n, ch;
  printf ("Enter no of elements: \n");
  scanf ("%d", &n);
  int arr[n], run=0;
  while(run!=5){
      printf ("Choose from the menu\n");
      printf ("Enter 1 to Push the elements\n");
      printf ("Enter 2 to Pop the elements\n");
      printf ("Enter 3 to Peek\n");
      printf ("Enter 4 to Display the elements\n");
      printf ("Enter 5 to Exit\n");
      scanf ("%d", &ch);
      run=ch;
      switch (ch)
        {
        case 1:
          push (arr, n);
          break;
        case 2:
          pop (arr);
          break;
        case 3:
          peek (arr);
          break;
        case 4:
          display (arr);
          break;
        }
      }
  return 0;
}
