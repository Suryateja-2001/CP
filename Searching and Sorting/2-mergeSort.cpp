// Merge Sort

#include<iostream>
using namespace std;

void mergeArr(int *arr,int left,int mid,int right){
    int temparr[right+1];
    int index = 0,i = left, j = mid+1;

    while(i <= mid && j <= right){

        if(arr[i] > arr[j]){
            temparr[index++] = arr[j++];
        }else{
            temparr[index++] = arr[i++];
        }
    }

    while(i <= mid){
        temparr[index++] = arr[i++];
    }
    while(j <= right){
        temparr[index++] = arr[j++];
    }

    i = left;
    index = 0;
    while(i<=right){
        arr[i++] = temparr[index++];
    }
}

void mergeSort(int *arr,int left,int right){

    int mid = left + (right-left)/2;

    if(left == right) return;

    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);

    mergeArr(arr,left,mid,right);
}

int main(){

    int arr[] = {4,7,2,9,5,1,3,8,6};
    int size = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr,0,size);

    for (int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    

    return 0;
}