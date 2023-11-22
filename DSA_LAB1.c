// Prob 1
/*#include <stdio.h>
#include <string.h>
int main() {
    long int n;
    int p,digit;
    scanf("%ld",&n);
    scanf("%d",&p);
    char num[30];
    sprintf(num,"%ld",n);
    digit = num[p-1];
    if (digit%2==0){
        printf("Even");
    } 
    else {
        printf("Odd");
    }
    return 0;
}*/

// Prob 2
/*#include <stdio.h>
int main() {
    int n,d=0; 
    scanf("%d",&n);
    int arr[n], new[n];
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for (int i=0;i<n;i++){
        int c=0;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[i]){
                c=1;
                break;
            }
        }
    if(c==1){
        continue;
     }
    else{
        new[d]=arr[i];
        d++;
    }
    }
    printf("top elements are ");
    for (int i=0;i<d-1;i++){
        printf("%d, ",new[i]);
    }
    printf("and %d",arr[n-1]);
    return 0;
}*/

// Prob 3
/*#include <stdio.h>
int main(){
    int n, dia1=0,dia2=0;
    scanf("%d",&n);
    int mat[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&mat[i][j]);
            if (i==j)
            {
                dia1+=mat[i][j];
            }
            if (n==i+j+1)
            {
                dia2+=mat[i][j];
            }
        }
    }
    printf("Sum across the first diagonal: %d\n",dia1);
    printf("Sum across the second diagonal: %d\n",dia2);
    int diff = dia1-dia2;
    diff = diff<0? -1*diff: diff;
    printf("Absolute Difference=%d",diff);
    return 0;
}*/

// Prob 4
/*#include <stdio.h>
int main(){
    int k1,k2,n;
    scanf("%d",&n);
    scanf("%d",&k1);
    scanf("%d",&k2);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for (int i = k1-1; i < k2; i++)
    {
        printf("%d, ",arr[i]);
    }
}*/


// Prob 5
/*#include <stdio.h>
int main() {
    int n,ch,c;
    scanf("%d",&n);
    int reg[n];
    for (int i=0;i<n;i++){
        scanf("%d",&reg[i]);
    }
    scanf("%d",&ch);
    for (int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if (reg[j]>reg[j+1]){
                int temp = reg[j];
                reg[j] = reg[j+1];
                reg[j+1] = temp;
            }
        }
    }
    for (int i=0;i<n;i++){
        printf("%d\n",reg[i]);
    }
    for (int i=0;i<n;i++){
        if(ch==reg[i]){
            printf("Yes\n");
            printf("%d",i+1);
            c=1;
            break;
        }
    }
    if(c!=1){
        printf("-1");
    }
    return 0;
}*/

// Prob 6
#include <stdio.h>
int main() {
    int n,x,pos;
    scanf("%d",&n);
    int arr[n+1];
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&x);
    scanf("%d",&pos);
    if (pos<0 || pos>n){
        printf("-1");
    }
    else{
        for(int i=n;i>=pos;i--){
            arr[i+1] = arr[i];
        }
        arr[pos] = x;
        for (int i = 0; i < n+1; i++)
        {
            printf("%d\n",arr[i]);
        }
    }
    return 0;
}


