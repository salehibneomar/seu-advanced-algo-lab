#include <bits/stdc++.h>
using namespace std;

struct GOLD{
    int value;
    int pos;
};

struct cmp {
    bool operator ()(GOLD const &a, GOLD const &b)
    {
        return a.value < b.value;
    }
};

priority_queue <GOLD, vector<GOLD>, cmp> maxGoldUnit;

int goldMine(int row, int col, vector < vector<int> > &goldValueGrid){
    int modifiedRow = row+2;
    vector < vector<int> > dpTable(modifiedRow, vector<int>(col, 0));

    for(int i=1; i<=row; i++){
        dpTable[i][0] = goldValueGrid[i-1][0];
    }

    for(int j=1; j<col; j++){
        for(int i=1; i<=row; i++){
            int maxValue = max(max(dpTable[i][j-1], dpTable[i-1][j-1]), dpTable[i+1][j-1]);
            dpTable[i][j] =  maxValue + goldValueGrid[i-1][j];
        }
    }

    for(int i=1; i<=row; i++){
        GOLD gold;
        gold.pos   = i-1;
        gold.value = dpTable[i][col-1];
        maxGoldUnit.push(gold);
    }

    return (maxGoldUnit.top()).value;
}

void pintMaxUnitPos(int col){
    cout<<"Maximum unit found at position/positions is/are printed below:"<<endl;;
    while(!maxGoldUnit.empty()){
        GOLD gold = maxGoldUnit.top();
        cout<<"("<<gold.pos<<","<<col<<")"<<endl;;
        maxGoldUnit.pop();
        if((maxGoldUnit.top()).value<gold.value){
            break;
        }
    }
    cout<<endl;
}

int main(){

    int row,col;
    cout<<"Enter row and col value respectively:"<<endl;
    cin>>row>>col;
    vector < vector<int> > goldValueGrid;

    cout<<"Enter gold values according to row and column number:"<<endl;
    for(int i=0; i<row; i++){
        vector <int> tmp;
        for(int j=0; j<col; j++){
            int v;
            cin>>v;
            tmp.push_back(v);
        }
        goldValueGrid.push_back(tmp);
        tmp.clear();
    }

    cout<<"\nMaximum amount of gold can be collected from this mine is = "
        <<goldMine(row, col, goldValueGrid)
        <<" units"<<endl;
    pintMaxUnitPos(col-1);

return 0;

}
