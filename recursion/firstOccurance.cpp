/*
    Program to find first occurrence of a Number Using Recursion in an array.
    Example: Arr[]={1,2,3,2,3,4,3,4,6,5,3}
    target =4
    Output= 5
*/

#include<iostream>
using namespace std;

void firstOccur(int *arr, int size, int val, int i = 0){
    if(i == size) return;

    if(arr[i] == val){
        cout<<i<<endl;
        return;
    }

    firstOccur(arr, size, val, ++i);

}

int main(){

    int arr[] = {3, 8, 5, 2, 8, 5, 2, 7,};
    int size = sizeof(arr)/sizeof(arr[0]);
    int val = 7;

    firstOccur(arr, size, val);

    return 0;
}