/*
    finding the contact of a person using the keypad. If the person enters 1 it will search for all possible combinations 'ABC'. 
*/
#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

unordered_map<int,string>stringMapping;

void permute(vector<string> &ans, string combination,string digits, int start){

    if(start == digits.size()){
        ans.push_back(combination);
        return;
    }

    int num = digits[start] - '0';
    string str = stringMapping[num];

    for(int i = 0; i < str.size(); i++){
        combination.push_back(str[i]);
        permute(ans, combination, digits, start+1);
        combination.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> answer;
    string combination;

    if(digits.size() == 0) return answer;

    stringMapping[2] = "abc";
    stringMapping[3] = "def";
    stringMapping[4] = "ghi";
    stringMapping[5] = "jkl";
    stringMapping[6] = "mno";
    stringMapping[7] = "pqrs";
    stringMapping[8] = "tuv";
    stringMapping[9] = "wxyz";
    permute(answer, combination, digits, 0);

    return answer;
}

int main(){
    string number,alphabets="";

    cout<<"Enter the number: ";
    cin>>number;

    vector<string> mp = letterCombinations(number);

    for(auto str : mp){
        cout<<str<<endl;
    }

    return 0;
}