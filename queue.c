#include <stdio.h>
#include <stdbool.h>

int size=50;
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











/*
#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void relative_Sort(int arr1[], int arr2[], int n1, int n2) {
    int c = 0;

    // Sort arr1 using Insertion Sort
    insertionSort(arr1, n1);

    // Find and move elements from arr1 to the beginning based on arr2
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n1; j++) {
            if (arr2[i] == arr1[j]) {
                // Swap elements to move them to the beginning of arr1
                int temp = arr1[j];
                for (int k = j; k > c; k--) {
                    arr1[k] = arr1[k - 1];
                }
                arr1[c] = temp;
                c++;
            }
        }
    }
}

int main() {
    int n1, n2;

    printf("Enter no. of elements in A1: \n");
    scanf("%d", &n1);
    int arr1[n1];
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter no. of elements in A2: \n");
    scanf("%d", &n2);
    int arr2[n2];
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    relative_Sort(arr1, arr2, n1, n2);

    printf("Sorted array: ");
    for (int i = 0; i < n1 - 1; i++) {
        printf("%d, ", arr1[i]);
    }
    printf("%d", arr1[n1 - 1]);

    return 0;
}
*/