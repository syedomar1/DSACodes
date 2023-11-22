#include <stdio.h>
#define SIZE 10

int hash(int key){
    return key%SIZE;
}

int probe(int H[],int key){
    int index = hash(key);
    int i=0;
    while (H[(index+i*i)%SIZE]!=0) // Change this line
    {
        i++;
    }
    return (index+i*i)%SIZE; // And this line
}

void insert(int H[], int key){
    int index = hash(key);
    if (H[index]!=0)
    {
        index = probe(H,key);
    }
    H[index] = key;
}

int search(int H[], int key){
    int index = hash(key);
    int i=0;
    while (H[(index+i*i)%SIZE] != 0) // And this line
    {
        if(H[(index+i*i)%SIZE] == key) // And this line
        {
            return (index+i*i)%SIZE; // And this line
        }
        i++;
    }
    return -1;
}

int main(){
    int HT[10]={0};
    insert(HT,12);
    insert(HT,25);
    insert(HT,36);
    insert(HT,26);

    int result = search(HT,26);
    if(result != -1) {
        printf("Key found at %d\n", result);
    } else {
        printf("Key not found\n");
    }
    return 0;
}
