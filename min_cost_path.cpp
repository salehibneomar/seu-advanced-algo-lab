#include <bits/stdc++.h>
using namespace std;

int minimumCost(int row, int col, vector< vector<int> > &costTable){

    int dpTable[row][col];
    dpTable[0][0] = costTable[0][0];

    for(int i=1; i<col; i++){
        dpTable[0][i] = costTable[0][i] + dpTable[0][i-1];
    }

    for(int i=1; i<row; i++){
        dpTable[i][0] = costTable[i][0] + dpTable[i-1][0];
    }

    for(int i=1; i<row; i++){
        for(int j=1; j<col; j++){
            dpTable[i][j] = costTable[i][j] + min(dpTable[i-1][j], dpTable[i][j-1]);
        }
    }

    return dpTable[row-1][col-1];
}

int main(){

    int row, col;
    vector< vector<int> > costTable;

    cout<<"Enter Row value and Column value respectively:"<<endl;
    cin>>row>>col;

    if(row!=0 && col!=0){
        cout<<"Enter each column cost:"<<endl;

        for(int i=0; i<row; i++){
            vector<int> tempColValues;
            for(int j=0; j<col; j++){
                int cost;
                cin>>cost;
                tempColValues.push_back(cost);
            }
            costTable.push_back(tempColValues);
            tempColValues.clear();
        }

        cout<<"Minimum cost to reach from the initial point to the ending point is = "
            <<minimumCost(row, col, costTable)
            <<endl;
    }
    else{
        cout<<"Invalid matrix formation!"<<endl;
    }


return 0;

}
