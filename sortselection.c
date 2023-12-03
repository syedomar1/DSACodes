#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
void selection(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        int min = i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }   
        if(min!=i)     
        swap(&arr[i],&arr[min]);            
    }
}
void selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int max=arr[0];
        int ind=0;
        for(int j=1;j<n-i-1;j++){
            if(arr[j]>max){
                max=arr[j];
                ind=j;
            }
        }
        arr[ind]=arr[n-i-1];
        arr[n-1-i]=max;
        for (int i = 0; i < n; i++)
        {
            printf("%d ",arr[i]);
        }
        printf("\n");
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
    selection(arr,n);
    // selection_sort( arr,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;

}