/*
    We have 'N' Pokemons and 'M' Money. So to Evolve a single pokemon it takes 'X' cost, If we sell the pokemon we get 'Y' selling Bonus.
    Find how many pokemons can we Evolve.

    N -> No.of Pokemons- 3
    M -> Total Money   - 10
    X -> Evolve Cost   - 4
    Y -> Selling Bonus - 2
*/
#include<iostream>
using namespace std;

bool midEvolves(int totalPokemons, int checkNum, int money, int evolveCost, int sellBonus){
    int Cost_checkNum = checkNum * evolveCost;
    int total_bonus = sellBonus * (totalPokemons - checkNum) + money;

    if(total_bonus >= Cost_checkNum) return true;

    return false;
}


int EvovlePokemon(int n, int m, int x, int y){
    int start = 1, end = n, pokemonEvolved = 0;
    int mid = start + (end-start)/2;
    while(start < end){

        if(midEvolves(n,mid,m,x,y)){
            pokemonEvolved = mid;
            start = mid+1;
            mid = start + (end-start)/2;
        }else{
            end = mid - 1;
            mid = start + (end-start)/2;
        }
    }
    return pokemonEvolved;
}

int main(){
    int N = 10, M = 10, X = 4, Y = 2;

    cout<<"The No.of Pokemons Can be Evolved are "<<EvovlePokemon(N,M,X,Y);

    return 0;
}