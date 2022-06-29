#include <bits/stdc++.h>
using namespace std;

void lpsConstruct(string pattern, int patternLength, int *lps){

    int i=0, j=1;
    lps[0] = 0;

    while(j<patternLength){

        if(pattern[i] == pattern[j]){
            lps[j] = i+1;
            i++;
            j++;
        }
        else{
            if(i==0){
                lps[j] = 0;
                j++;
            }
            else{
                i = lps[i-1];
            }
        }
    }
}

void KMP(string text, string pattern, int textLength, int patternLength){

    int lps[patternLength];
    lpsConstruct(pattern, patternLength, lps);

    cout<<"\nLPS Table of "<<pattern<<" is: ";
    for(int i=0; i<patternLength; i++){
        cout<<lps[i]<<" ";
    }
    cout<<"\n\n";

    int textIndex = 0;
    int patternIndex = 0;

    while(textIndex<textLength){

        if(text[textIndex] == pattern[patternIndex]){
            textIndex++;
            patternIndex++;

            if(patternIndex == patternLength){
                int strPos = textIndex - patternIndex;
                cout<<"Found pattern at index "<<strPos<<endl;
                patternIndex = lps[patternIndex-1];
            }
        }
        else{
            if(patternIndex>0){
                patternIndex = lps[patternIndex-1];
            }
            else{
                textIndex++;
            }
        }
    }

}

int main(){

    string text, pattern;
    cout<<"Enter the text: ";
    getline(cin, text);
    cout<<"Enter the pattern: ";
    cin>>pattern;

    int textLength = text.length();
    int patternLength = pattern.length();

    cout<<"Length of the Text: "<<textLength<<endl;
    cout<<"Length of the Pattern: "<<patternLength<<endl;

    KMP(text, pattern, textLength, patternLength);

return 0;

}
