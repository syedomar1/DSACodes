#include <stdio.h>
#include <stdlib.h>
int findMax(int arr[], int n){
    int max=-1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]>max)
        {
            max=arr[i];
        }        
    }
    return max;
}

void countSort(int arr[],int n){
    int max,*c;
    max=findMax(arr,n);
    c=(int *)malloc(sizeof(int)*(max+1));
    for (int i = 0; i < max+1; i++)
    {
        c[i]=0;
    }
    for (int i = 0; i < n; i++)
    {
        c[arr[i]]++;
    }
    int i=0,j=0;
    while (j<max+1)
    {
        if (c[j]>0)
        {
            arr[i++]=j;
            c[j]--;
        }
        else{
            j++;
        }
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
    countSort(arr,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}