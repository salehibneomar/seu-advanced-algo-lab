#include <bits/stdc++.h>
using namespace std;

int row, col;

unsigned int pathCount(){

    unsigned int table[row][col];

    for(int i=0; i<col; i++){
        table[0][i] = 1;
    }

    for(int i=0; i<row; i++){
        table[i][0] = 1;
    }

    for(int i=1; i<row; i++){
        for(int j=1; j<col; j++){
            table[i][j] = table[i-1][j] + table[i][j-1];
        }
    }


    return (row==0 || col==0) ? 0 : table[row-1][col-1];
}

int main(){

    cout<<"Enter number of Rows and Columns respectably:"<<endl;
    cin>>row>>col;

    cout<<"Number of paths to reach from the initial point to the last point = "<<pathCount()<<endl;


return 0;

}
