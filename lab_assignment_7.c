#include <stdio.h>
#include <stdlib.h>

typedef struct tuple{
    int first;
    int second;
} tuple;

void bubbleSort(tuple* a, int n){
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < i; j++){
            if(a[j].first > a[j+1].first){
                a[j].second++;
                a[j+1].second++;
                tuple temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void selectionSort(tuple* a, int n){
    for(int i = 0; i < n; i++){
        int mn = a[i].first, mni = i;
        for(int j = i+1; j < n; j++){
            if(a[j].first < mn){
                mn = a[j].first;
                mni = j;
            }
        }
        if (i != mni){
            a[i].second++;
            a[mni].second++;
            tuple temp = a[i];
            a[i] = a[mni];
            a[mni] = temp;
        }
        
    }
}

int main(void){
    tuple nums[9], nums2[9];
    for(int i = 0; i < 9; i++){
        tuple new, new2;
        scanf("%d", &new.first);
        new2.first = new.first;
        new.second = 0;
        new2.second = 0;
        nums[i] = new;
        nums2[i] = new2;
    }

    bubbleSort(nums, 9);
    selectionSort(nums2, 9);

    printf("Bubble Sort:\n");
    int total = 0;
    for(int i = 0; i < 9; i++){
        total += nums[i].second;
        printf("%d:%d\n", nums[i].first, nums[i].second);
    }
    printf("Total:%d\n", total / 2);
    
    printf("Selection Sort:\n");
    total = 0;
    for(int i = 0; i < 9; i++){
        total += nums2[i].second;
        printf("%d:%d\n", nums2[i].first, nums2[i].second);
    }
    printf("Total:%d\n", total / 2);

    return(0);
}

// 97  16  45  63  13  22  7  58  72
// 90  80  70  60  50  40  30  20  10