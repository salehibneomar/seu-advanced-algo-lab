#include <bits/stdc++.h>
using namespace std;

vector<int> numberSet;

void assignNumberSet(int setSize){

    cout<<"Enter values in the set:"<<endl;
    int value;

    for(int i=0; i<setSize; i++){
        cin>>value;
        numberSet.push_back(value);
    }
}

bool hasSubsetSum(int setSize, int sum){

    bool table[++setSize][++sum];

    for(int i=0; i<setSize; i++){

        int currSetValue = i==0 ? 0 : numberSet.at(i-1);

        for(int j=0; j<sum; j++){
            if(i==0){
                if(j==0){
                    table[i][j] = true;
                }
                else{
                    table[i][j] = false;
                }
            }
            else{
                if(currSetValue>j){
                    table[i][j] = table[i-1][j];
                }
                else{
                    table[i][j] = table[i-1][j] || table[i-1][j-currSetValue];
                }
            }
        }
    }

    return table[--setSize][--sum];
}

int main(){

    int setSize, sum;
    cout<<"Enter set size:"<<endl;
    cin>>setSize;
    assignNumberSet(setSize);

    cout<<"Enter the sum value:"<<endl;
    cin>>sum;
    if(hasSubsetSum(setSize, sum)){
        cout<<"True! there is a subset for the sum "<<sum<<endl;

    }
    else{
        cout<<"False! there is no subset for the sum "<<sum<<endl;
    }

return 0;

}
