#include <stdio.h>
void insert(int arr[], int i) {
    int temp = arr[i];
    int parent = (i - 1)/2;

    while (i > 0 && temp > arr[parent]) {
        arr[i] = arr[parent];
        i = parent;
        parent = (parent - 1)/2;
    }
    arr[i] = temp;
}
void createHeap(int arr[], int n) {
    for(int i = 2; i < n; i++) {
        insert(arr, i);
    }
}

int deleteHeap(int arr[],int n){
    int i,j,x,temp,val;
    val=arr[0];
    x=arr[n-1];
    arr[0] = arr[n-1];
    arr[n-1] = val; 
    i=0;
    j=i*2;
    while (j < n-1)
    {
        if (j+1 < n && arr[j+1]>arr[j])
        {
            j=j+1;
        }
        if (arr[i]<arr[j])
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i=j;
            j=2*j;
        }
        else{
            break;
        }
    }
    return val;
}

void printHeap(int arr[], int n) {
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 20, 30, 25, 5, 40, 35};
    int n = sizeof(arr)/sizeof(arr[0]);
    createHeap(arr, n);
    printf("Deleted value is %d\n",deleteHeap(arr,n));
    printHeap(arr, n);

    return 0;
}
