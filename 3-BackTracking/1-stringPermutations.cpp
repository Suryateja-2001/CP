// printing the all the possible permutations.
#include<iostream>
using namespace std;

void permute(string str, int left, int right){
    if(left == right){
        cout<<str<<endl;
        return ;
    }

    for(int i=left;i<=right;i++){

        swap(str[i],str[left]);

        permute(str,left+1,right);

        swap(str[i],str[left]);

    }
} 

int main(){

    string str = "ABCD";

    permute(str,0,3);

    return 0;
}