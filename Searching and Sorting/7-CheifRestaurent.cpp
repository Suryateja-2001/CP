/* [ -> tells include and ) -> tells not to include i.e, [2,4) -> tells include 2 but not 4 (i.e, 2 to 3 only).
    Chef is a cook and he has recently opened a restaurant.

    The restaurant is open during N time intervals [L1,R1),[L2,R2),…,[LN,RN). No two of these intervals overlap — formally, 
    for each valid i, j such that i≠j, either Ri<Lj or Rj<Li. M people (numbered 1 through M) are planning to eat at the restaurant; 
    let's denote the time when the i-th person arrives by Pi. If the restaurant is open at that time, this person does not have to wait, 
    but if it is closed, this person will wait until it is open. Note that if this person arrives at an exact time when the restaurant is closing, 
    they have to wait for the next opening time.

    For each person, calculate how long they have to wait (possibly 0 time), or determine that they will wait forever for the restaurant to open.


    Input:-
    The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
    The first line of the input contains two space-separated integers N and M.
    N lines follow. For each valid i, the i-th of these lines contains two space-separated integers Li and Ri.
    M lines follow. For each valid i, the i-th of these lines contains a single integer Pi.
    

    Output:-
    For each test case, print M
    lines. For each valid i, the i-th of these lines should contain a single integer — the time person i has to wait, or −1 if person i has to wait forever.
*/
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

bool isOntime(vector<pair<int,int>>& arrPair, int personTime, int mid){
    if(arrPair[mid].first <= personTime && arrPair[mid].second > personTime){
        return true;
    }
    return false;
}

void waitingTime(vector<pair<int,int>>& arrPair, int personTime, int N, int M){
    
    int start = 0, end = N-1, mid = start + (end-start)/2;

    while(start <= end){
        if(isOntime(arrPair,personTime,mid)){
            cout<<"0 ";
            break;
        }else if(arrPair[mid].second <= personTime){
            
            if(arrPair[mid+1].first > personTime){
                cout<<arrPair[mid+1].first - personTime<<" ";
                break;
            }else if(mid+1 == end && personTime >= arrPair[mid+1].second){
                cout<<"-1 ";
                break;
            }
            start = mid+1;
        }else if(arrPair[mid].first > personTime){

            if(mid-1 > start && arrPair[mid-1].first > personTime){  
                end = mid-1 ;
                continue;
            }
            cout<<arrPair[mid-1].first - personTime<<" ";
            break;
        }
        mid = start + (end - start)/2;
    }
    
}

int main(){
    int N,x, M, personTime;
    vector<pair<int,int>>arrPair;

    cout<<"Enter the no.of time intervals: ";
    cin>>N;
    x = N;
    cout<<"\nEnter the No.of Persons: ";
    cin>>M;

    cout<<"\nEnter the time intervals: ";
    while(N--){
        pair<int,int>item;
        int x,y;
        cin>>x>>y;
        item = {x,y}; // or item = make_pair(x,y);
        arrPair.push_back(item);
    }
    sort(arrPair.begin(),arrPair.end());


    cout<<"\nEnter the person arriving time: ";
    for (int i = 0; i < M; i++){
        cin>>personTime;
        waitingTime(arrPair, personTime, x, M);
    }

    return 0;
}