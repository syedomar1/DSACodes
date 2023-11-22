// Prob 1
#include <stdio.h>
void Fsort(int arr[], int n)
{
    int freq[100] = {0};
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        int maxFreq = -1, maxIndex = -1;
        for (int j = 0; j < n; j++)
        {
            if (freq[arr[j]] > maxFreq)
            {
                maxFreq = freq[arr[j]];
                maxIndex = j;
            }
        }
        if (maxFreq != -1)
        {
            for (int k = 0; k < freq[arr[maxIndex]]; k++)
            {
                printf("%d ", arr[maxIndex]);
            }
            freq[arr[maxIndex]] = -1;
        }
    }
}
int main()
{
    int n;
    printf("Enter the number of elements: \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Sorted array based on decreasing frequency: ");
    Fsort(arr, n);
    return 0;
}

// Prob 2
/*#include <stdio.h>
void swap(int *a, int *b){
    int temp =*a;
    *a=*b;
    *b=temp;
}
void Bsort(int arr[], int n){
    int flag=0;
    for(int i=0;i<n-1;i++){
        flag=0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                flag=1;
                swap(&arr[j],&arr[j+1]);
            }
        }
        if(flag==0){
            break;
        }
    }
    for(int i=0;i<n-1;i++){
        printf("%d, ",arr[i]);
    }
    printf("%d",arr[n-1]);
}
int main()
{
    int n;
    printf("Enter no. of elements: \n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    Bsort(arr,n);
    return 0;
}*/

// Prob 3
/*#include <stdio.h>
void swap(int *a, int *b){
    int temp =*a;
    *a=*b;
    *b=temp;
}
void relative_Sort(int arr1[], int arr2[],int n1,int n2){
    int c=0;
    for(int i=0;i<n2;i++){
        for(int j=0;j<n1;j++){
            if(arr2[i]==arr1[j]){
                swap((arr1+j),(arr1+c));
                c+=1;
            }
        }
    }
    for(int i=c;i<n1;i++){
        for(int j=i+1;j<n1;j++){
            if(arr1[i]>arr1[j]){
                swap((arr1+i),(arr1+j));
            }
        }
    }
}
int main()
{
    int n1,n2;
    printf("Enter no. of elements in A1: \n");
    scanf("%d",&n1);
    int arr1[n1];
    for(int i=0;i<n1;i++){
        scanf("%d",&arr1[i]);
    }
    printf("Enter no. of elements in A2: \n");
    scanf("%d",&n2);
    int arr2[n2];
    for(int i=0;i<n2;i++){
        scanf("%d",&arr2[i]);
    }
    relative_Sort(arr1,arr2,n1,n2);
    for(int i=0;i<n1-1;i++){
        printf("%d, ",arr1[i]);
    }
    printf("%d",arr1[n1-1]);
    return 0;
}*/

// Prob 4
/*#include <stdio.h>
void swap(int *a, int *b){
    int temp =*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[], int low, int high){
    int x=arr[high], i=low-1;
    for(int j=low;j<=high-1;j++){
        if (arr[j] <= x){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return (i+1);
}
void quicksort(int arr[],int low, int high){
    if(low<high){
            int q= partition(arr,low,high);
            quicksort(arr,low,q-1);
            quicksort(arr,q+1,high);
        }
}
int main()
{
    int n, p=0;
    printf("Enter no. of elements: \n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quicksort(arr,p,n-1);
    for(int i=0;i<n-1;i++){
        printf("%d, ",arr[i]);
    }
    printf("%d",arr[n-1]);
    return 0;
}*/
