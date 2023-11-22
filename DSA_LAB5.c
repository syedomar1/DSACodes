// Prob 1
#include <stdio.h>

#define size 50

int top = -1;
int evearr[size];
int oddarr[size];
int a = 0;
int b = 0;

int empty() {
    if (top == -1) {
        return 1;
    }
    return 0;
}

int full() {
    if (top == size - 1) {
        return 1;
    }
    return 0;
}

void push(int arr[], int value) {
    if (full()) {
        return;
    } else {
        arr[++top] = value;
    }
}

void pop(int arr[]) {
    if (empty()) {
        return;
    } else {
        if (arr[top] % 2 == 0) {
            evearr[a] = arr[top];
            a++;
        } else {
            oddarr[b] = arr[top];
            b++;
        }
        top--;
    }
}

void display(int arr[]) {
    for (int i = 0; i <= top; i++) {
        printf("%d\n", arr[i]);
    }
    
    if (b == 0) {
        printf("-1\n");
    } else {
        for (int j = 0; j < b; j++) {
            printf("%d\n", oddarr[j]);
        }
    }
    
    if (a == 0) {
        printf("-99\n");
    } else {
        for (int k = 0; k < a; k++) {
            printf("%d\n", evearr[k]);
        }
    }
}

int main() {
    while (1) {
        int ch;
        scanf("%d", &ch);
        
        if (ch == 1) {
            int n;
            scanf("%d", &n);
            int arr[size];
            for (int i = 0; i < n; i++) {
                int ele;
                scanf("%d", &ele);
                push(arr, ele);
            }
        } else if (ch == 2) {
            int n;
            scanf("%d", &n);
            int arr[size];
            for (int i = 0; i < n; i++) {
                pop(arr);
            }
        }
        
        int n1;
        scanf("%d", &n1);
        if (n1 == 1) {
            a = 0;
            b = 0;
            continue;
        } else {
            int arr[size];
            display(arr);
            if (n1 == 99) {
                break;
            }
        }
    }
    return 0;
}
