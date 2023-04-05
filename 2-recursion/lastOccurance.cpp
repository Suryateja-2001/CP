/*
    Program to find last occurrence of a Number Using Recursion in an array.
    Example: Arr[]={1,2,3,2,3,4,3,4,6,5,3}
    target =4
    Output= 5
*/

#include<iostream>
using namespace std;

void lastOccur(int *arr, int size, int val, int i){
    if(i < 0) return;

    if(arr[i] == val){
        cout<<i<<endl;
        return;
    }

    lastOccur(arr, size, val, --i);
}

int main(){
    int arr[] = {3, 8, 5, 2, 8, 5, 2, 7,};
    int size = sizeof(arr)/sizeof(arr[0]);
    int val = 8;

    lastOccur(arr, size, val, size-1);

    return 0;
}