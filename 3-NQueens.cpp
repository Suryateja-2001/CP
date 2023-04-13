// N Queen Problem

#include<iostream>
#include<vector>
using namespace std;

bool check(int index, vector<string> &vec){
    if(vec.empty()){
        return true;
    }

    for(int j=0;j<vec.size();j++){
        for(int i=0;i<vec[j].size();i++){
            int QueenAttack = index > i? index - vec.size() + j : index + vec.size()-j ;
            if(vec[j][i] == 'Q' && i == index || vec[j][i] == 'Q' && i == QueenAttack ) return false;
        }
    }
    return true;
}
string queenAt(int i, int n){
    string rowstr="";

    for(int j=0;j<n;j++){
        if(j==i){
            rowstr += 'Q';
        }else{
            rowstr += '.';
        }
    }
    return rowstr;
}

void permute(vector<vector<string>> &ans,vector<string> &vec,int n,int start){

    if(start == n){
        ans.push_back(vec);
        return; 
    }
    
    for(int i=0; i<n; i++){
        if(check(i, vec)){
            vec.push_back(queenAt(i, n));
            permute(ans,vec,n,start+1);
            vec.pop_back();
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> vec;

    permute(ans, vec, n, 0);

    return ans;
}

int main(){
    int n;
    cout<<"Enter Dimension of keyboard: ";
    cin>>n;

    vector<vector<string>>ans = solveNQueens(n);

    for(auto arr : ans){
        for(auto ele : arr){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}