#include <bits/stdc++.h>
using namespace std;

int minScalarOperations(int n, int *P){
    int M[n][n] = {0};
    int S[n][n] = {0};

    for(int i=0; i<n; i++){
        M[i][i] = 0;
    }

    for(int l=n-2; l>0; l--){

        for(int i=1; i<=l; i++){

            int j = ((n-1) - l) + i;
            int k = i;
            int track_k = k;
            int minScalarOperations = M[i][k] + M[k+1][j] + (P[i-1] * P[k] * P[j]);
            M[i][j] = minScalarOperations;

            for(k; k<j; k++){
                int scalarOperations = M[i][k] + M[k+1][j] + (P[i-1] * P[k] * P[j]);
                if(scalarOperations < M[i][j]){
                    track_k = k;
                    M[i][j] = scalarOperations;
                }
            }
            S[i][j] = track_k;
        }
    }

    cout<<"\nM - Table:"<<endl;
    for(int i=1; i<n; i++){
        for(int s=1; s<i; s++){
            printf("%-10c",' ');
        }
        for(int j=1; j<n; j++){

            if(j>=i){
                printf("%-10d", M[i][j]);
            }
        }
        cout<<endl;
    }

    cout<<"\nS - Table:"<<endl;
    for(int i=1; i<n; i++){
        for(int s=1; s<i; s++){
            printf("%-10c",' ');
        }
        for(int j=2; j<n; j++){

            if(j>i){
                printf("%-10d", S[i][j]);
            }
        }
        cout<<endl;
    }

    return M[1][n-1];
}


int main(){

    int n;
    cout<<"Enter number of dimensions:"<<endl;
    cin>>n;

    int P[n];

    cout<<"Enter dimensions:"<<endl;
    for(int i=0; i<n; i++){
        cin>>P[i];
    }

    cout<<"Minimum number of scalar operations needed is "<<minScalarOperations(n, P)<<endl;

return 0;

}
