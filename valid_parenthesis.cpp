#include <bits/stdc++.h>

using namespace std;

stack<char> openingBracketsStack;

bool hasBrackets(string expression){

    bool status = (expression.find('(') == string::npos &&
                   expression.find(')') == string::npos &&
                   expression.find('{') == string::npos &&
                   expression.find('}') == string::npos &&
                   expression.find('[') == string::npos &&
                   expression.find(']') == string::npos) ? false : true;

    return status;
}

bool pairChecker(char topOpeningItem, char closingItem){

    bool status = ((closingItem==')' && topOpeningItem!='(') ||
                   (closingItem=='}' && topOpeningItem!='{') ||
                   (closingItem==']' && topOpeningItem!='[')) ? false : true;

    return status;
}

void validityChecker(string expression){

    if(hasBrackets(expression)){
        bool invalid = false;

        for(int i=0; i<expression.length(); i++){
            if(expression[i]=='(' ||
               expression[i]=='{' ||
               expression[i]=='['){

               openingBracketsStack.push(expression[i]);
               continue;
            }

            if(openingBracketsStack.empty() &&
               (expression[i]==')' ||
                expression[i]=='}' ||
                expression[i]==']')){

                cout<<"Invalid expression, no opening found for "<<expression[i]<<endl;
                invalid = true;
                break;
            }

            if(!openingBracketsStack.empty() &&
               (expression[i]==')' ||
                expression[i]=='}' ||
                expression[i]==']')){

                char topOpeningItem = openingBracketsStack.top();
                char closingItem    = expression[i];

                openingBracketsStack.pop();

                if(!pairChecker(topOpeningItem, closingItem)){
                    cout<<"Invalid expression, no opening found for "<<closingItem<<", instead encountered "<<topOpeningItem<<endl;
                    invalid = true;
                    break;
                }
            }
        }

        if(openingBracketsStack.empty() && !invalid){
            cout<<"The given expression is valid"<<endl;
        }
        else if(!openingBracketsStack.empty()){

            string msg = "Invalid expression, missing closing for the followings ";
            string missings = "";

            while(!openingBracketsStack.empty()){
               missings+=openingBracketsStack.top();
                openingBracketsStack.pop();
            }

            reverse(missings.begin(),missings.end());
            cout<<msg+missings<<endl;
        }

    }
    else{
        cout<<"No parenthesis, braces, and square brackets found in the given expression"<<endl;
    }
}

int main(){

string expression;

    cout<<"Enter an arithmetic expression:"<<endl;
    cin>>expression;


validityChecker(expression);


return 0;

}
