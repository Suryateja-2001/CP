// power function when it is postive integer

#include<iostream>

using namespace std;

int powerfun(int num, int power){

    if(power == 0) return 1;

    return (num * powerfun(num, power-1));
}

int main(){

    cout<<"The power function : "<<powerfun(5,2);

    return 0;
}