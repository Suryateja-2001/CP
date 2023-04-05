/*
    Jhon loves the pizza. He wants to try out all the pizzas in shop. Now the city has different pizzarea,
    which has different pizza prices. But Jhon wants to classic pizza, each day jhon gets different amount of pocket money from his mother 
    and has to return the remaing amount back to his mother. He starts from the first pizzarea and continues to till he runs out of money.
    Jhon does this every day, your task is find out how much total amount he would return to his mother at the end of the day.

    input:-
    -> no.of days
    -> no.of pizzareas (N)
    -> prices of classic pizza in the shop at arr[i] for arr[N]
    -> money received from mother.

    output:- Remaning Total amount 
*/

#include<iostream>
using namespace std;

int remaningMoney(int *arr, int size, int money){
    int start = 0, end = size-1, mid = start+(end - start)/2,leftMoney = 0;

    // finding the cumulative price of each shop.
    for(int i =1;i<size;i++){
        arr[i] +=arr[i-1];
    }


    // finding remaning amount
    while(start < end){
        if(money > arr[mid]){
            leftMoney = max(money - arr[mid],leftMoney);
            start = mid + 1;
        }else if(money < arr[mid]){
            end = mid-1;
        }else if(money == arr[mid]){
            return 0;
        }
        mid = start + (end-start)/2;
    }
    return leftMoney;
}

int main(){
    int days;

    cout<<"Enter the No.of days to eat: ";
    cin>>days;
    cout<<endl;

    while(days--){
        int shops,money;

        cout<<"Enter no.of shops present: ";
        cin>>shops;
        cout<<endl;

        int price[shops];
        cout<<"Enter the price in each shop: ";
        for (int i = 0; i < shops; i++){
            cin>>price[i];
        }
        cout<<"\nEnter the money recieved from mother: ";
        cin>>money;
        
        cout<<remaningMoney(price,shops,money)<<" ";
    }

    return 0;
}