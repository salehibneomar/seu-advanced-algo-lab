#include <bits/stdc++.h>

using namespace std;

vector<int> coins;

void assignCoins(int numberOfCoin){

    cout<<"Enter coins"<<endl;
    int coin;
    for(int i=0; i<numberOfCoin; i++){
        cin>>coin;
        coins.push_back(coin);
    }
}

int coinChange(int numberOfCoin, int amount){

    int table[++numberOfCoin][++amount];
    table[0][0] = 1;

    for(int i=1; i<amount; i++){
        table[0][i] = 0;
    }

    for(int i=1; i<numberOfCoin; i++){

        int coinValue = coins.at(i-1);

        for(int j=0; j<amount; j++){

            if(coinValue>j){
                table[i][j] = table[i-1][j];
            }
            else{
                int currentRowColumn = j - coinValue;
                table[i][j] = table[i-1][j] + table[i][currentRowColumn];
            }
        }
    }

    return table[numberOfCoin-1][amount-1];
}

int main(){

int amount, numberOfCoin;

    cout<<"Enter the number of coins you want to add:"<<endl;
    cin>>numberOfCoin;
    assignCoins(numberOfCoin);

    cout<<"Enter an Amount(Money):"<<endl;
    cin>>amount;

    cout<<"To make: "<<amount
        <<", we can use "
        <<coinChange(numberOfCoin, amount)
        <<" ways of coin change combination."<<endl;


return 0;

}
