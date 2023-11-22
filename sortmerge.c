#include <stdio.h>
void merge(int arr[], int l, int mid, int h){
    int i=l,j=mid+1,k=l;
    int arr2[l+h];
    while (i<=mid && j<=h)
    {
        if (arr[i]<arr[j])
        {
            arr2[k++]=arr[i++];
        }
        else{
            arr2[k++]=arr[j++];
        }
    }
    for (; i <=mid; i++)
    {
        arr2[k++]=arr[i];
    }
    for (; j <=h; j++)
    {
        arr2[k++]=arr[j];
    }
    for (i=l; i<=h; i++)
    {
        arr[i]=arr2[i];
    }
}
void mergeSort(int arr[],int l, int h){
    int mid;
    if (l<h)
    {
        mid=(l+h)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,h);
        merge(arr,l,mid,h);
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
    mergeSort(arr,0,n-1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}