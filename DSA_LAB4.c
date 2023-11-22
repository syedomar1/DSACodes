// Prob 1
/*#include <stdio.h>
int top = -1;
int empty (int arr[])
{
  if (top == -1)
    {
      return 1;
    }
  return 0;
}
int full (int arr[],int n)
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
    if(full(arr,n)==1){
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
    if(empty(arr)==1){
        printf("Stack is empty\n");
        return;
    }
    else{
        printf("Popped element is: %d\n",arr[top]);
        top--;
    }
}
void peek(int arr[]){
    if(empty(arr)==1){
        printf("Stack is empty\n");
    }
    else{
        printf("The peek element is %d\n",arr[top]);
    }
}
void display(int arr[]){
    if(empty(arr)==1){
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
}*/

// Prob 2
/*#include <stdio.h>
int top = -1;
int empty (int arr[])
{
  if (top == -1)
    {
      return 1;
    }
  return 0;
}
int full (int arr[],int n)
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
    if(full(arr,n)==1){
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
    if(empty(arr)==1){
        printf("Stack is empty\n");
        return;
    }
    else{
        printf("Popped element is: %d\n",arr[top]);
        top--;
    }
}

void display(int arr[],int n){
    int stack[n];
    int result[n], top=-1; 

    for (int i = 0; i < n; i++) {
        while (top >= 0 && arr[i] > arr[stack[top]]) {
            result[stack[top--]] = arr[i];
        }
        stack[++top] = i;
    }

    while (top >= 0) {
        result[stack[top--]] = -1;
    }

    for (int i = 0; i < n; i++) {
        printf("%d -> %d\n", arr[i], result[i]);
    }

}

int main ()
{
  int n, ch;
  printf ("Enter no of elements: \n");
  scanf ("%d", &n);
  int arr[n], run=0;
  while(run!=4){
      printf ("Choose from the menu\n");
      printf ("Enter 1 to Push the elements\n");
      printf ("Enter 2 to Pop the elements\n");
      printf ("Enter 3 to Display the elements\n");
      printf ("Enter 4 to Exit\n");
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
          display (arr,n);
          break;
        }
      }
  return 0;
}*/

// Prob 3
#include <stdio.h>
#include <stdlib.h>
int array[100];
int top1=-1;
int top2=100;
void push1(int x)
{
    if(top1<top2-1)
    {
        array[++top1]=x;
    }
    else
    {
        printf("Stack 1 overflow.Cannot push.\n");
    }
}
void push2(int x)
{
    if(top1<top2-1)
    {
        array[--top2]=x;
    }
    else
    {
        printf("Stack 2 overflow.Cannot push.\n");
    }
}
int pop1()
{
    if(top1>=0)
    {
        return array[top1--];
    }
    else
    {
        printf("Stack 1 is empty.Cannot pop.\n");
        return -1;
    }
}
int pop2()
{
    if(top2<100)
    {
        return array[top2++];
    }
    else
    {
        printf("Stack 2 is empty.Cannot pop.\n");
        return -1;
    }
}
void display1()
{
    if(top1>=0)
    {
        printf("Stack 1 elements:\n");
        for(int i=0;i<=top1;i++)
        {
            printf("%d ",array[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Stack 1 is empty.\n");
    }
}
void display2()
{
    if(top2<100)
    {
        printf("Stack 2 elements:\n");
        for(int i=99;i>=top2;i--)
        {
            printf("%d ",array[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Stack 2 is empty.\n");
    }
}
int main()
{
    int choice,item;
    do
    {
        printf("1. Push to Stack 1\n");
        printf("2. Push to Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Display Stack 1\n");
        printf("6. Display Stack 2\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter item to push to Stack 1: ");
                scanf("%d",&item);
                push1(item);
                break;
            case 2:
                printf("Enter item to push to Stack 2: ");
                scanf("%d",&item);
                push2(item);
                break;
            case 3:
                printf("Popped from Stack 1: %d\n",pop1());
                break;
            case 4:
                printf("Popped from Stack 2: %d\n",pop2());
                break;
            case 5:
                display1();
                break;
            case 6:
                display2();
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.Please try again.\n");
        }
    }while(choice!=7);
    return 0;
}

