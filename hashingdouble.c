#include <stdio.h>
#define SIZE 10

int hash1(int key){
    return key%SIZE;
}

int hash2(int key){
    return 7 - (key % 7); // Secondary hash function. 7 is a prime number less than SIZE
}

int doubleHash(int H[],int key){
    int index = hash1(key);
    int i=0;
    while (H[(index+i*hash2(key))%SIZE]!=0) // Change this line
    {
        i++;
    }
    return (index+i*hash2(key))%SIZE; // And this line
}

void insert(int H[], int key){
    int index = hash1(key);
    if (H[index]!=0)
    {
        index = doubleHash(H,key);
    }
    H[index] = key;
}

int search(int H[], int key){
    int index = hash1(key);
    int i=0;
    while (H[(index+i*hash2(key))%SIZE] != 0) // And this line
    {
        if(H[(index+i*hash2(key))%SIZE] == key) // And this line
        {
            return (index+i*hash2(key))%SIZE; // And this line
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

    int result = search(HT,12);
    if(result != -1) {
        printf("Key found at %d\n", result);
    } else {
        printf("Key not found\n");
    }
    return 0;
}
