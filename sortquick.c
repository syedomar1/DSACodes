#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b){
    int temp = *a;
    *a  = *b;
    *b = temp;
}
int partition(int arr[],int l,int h){
    int p=arr[l], i=l, j=h;
    do
    {
        do
        {
            i++;
        } while (arr[i]<=p);
        do
        {
            j--;
        } while (arr[j]>p);
        if (i<j)
        {
            swap(&arr[i],&arr[j]);
        }        
    } while (i<j);
    swap(&arr[l],&arr[j]);
    return j;
}
void quickSort(int arr[], int l, int h){
    int j;
    if (l<h)
    {
        j=partition(arr,l,h);
        quickSort(arr,l,j);
        quickSort(arr,j+1,h);
    }
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
    quickSort(arr,0,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}