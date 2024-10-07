#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
string in;
stack<char> myStack;
stack<int> myStack2;
vector<char> inFix, postFix;
void getInfix(){
    cout<<"Enter the infix expression: "; //getting the INFIX expression
    cin>>in;
    for(int i=0;i<in.length();i++){
        inFix.push_back(in[i]);
    }
    
}

int precedance(char symbol){
    switch (symbol)
    {
    case '^':
        return 3;
    case '*':
        return 2;
    case '/':
        return 2;
    case '+':
        return 1;
    case '-':
        return 1;
    default:
        return 0;
    }
}


void conversion() {
    for(char symbol:inFix){  //coverting to postfix
        switch (symbol)
        {
        case '(':
            myStack.push(symbol);
            break;
        case ')':
            while(myStack.top() != '('){
                postFix.push_back(myStack.top());  
                myStack.pop();
            }
            myStack.pop();
            break;
        case '+':
            while(!myStack.empty() && precedance(myStack.top()) >= precedance(symbol)){
                postFix.push_back(myStack.top());
                myStack.pop();
            }
            myStack.push(symbol);
            break;
        case '-':
            while(!myStack.empty() && precedance(myStack.top()) >= precedance(symbol)){
                postFix.push_back(myStack.top());
                myStack.pop();
            }
            myStack.push(symbol);
            break;
        case '*':
            while(!myStack.empty() && precedance(myStack.top()) >= precedance(symbol)){
                postFix.push_back(myStack.top());
                myStack.pop();
            }
            myStack.push(symbol);
            break;
        case '/':
            while(!myStack.empty() && precedance(myStack.top()) >= precedance(symbol)){
                postFix.push_back(myStack.top());
                myStack.pop();
            }
            myStack.push(symbol);
            break;
        case '^':
            while(!myStack.empty() && precedance(myStack.top()) >= precedance(symbol)){
                postFix.push_back(myStack.top());
                myStack.pop();
            }
            myStack.push(symbol);
            break;
        
        default:
            postFix.push_back(symbol);
            break;
        }
    }
    while(!myStack.empty()){
        postFix.push_back(myStack.top());
        myStack.pop();
    }
}

void showPostFix(){
    for(char i:postFix){
        cout<<i<<" ";
    }
}

int eval(char symbol){
    int b = myStack2.top();
  
    myStack2.pop();
    int a = myStack2.top();
    
    myStack2.pop();
    switch (symbol){
    case '+':
        
        return a+b;
    case '-':
        return a-b;
    case '*':
        return a*b;
    case '/':
        return a/b;
    case '^':
        return a^b;
    default:
        return 1;
    }
}

void ansFromPostfix(){
    for(char symbol:postFix){
        if(symbol >= '0' && symbol <= '9'){
            
            myStack2.push(symbol-'0');
        } else {
            int result = eval(symbol);  // Call eval once and store the result
            myStack2.push(result);
        }
    }
    cout<<"\nAnswer: "<<myStack2.top();
    myStack2.pop();
}

int main(){
    getInfix();
    conversion();
    showPostFix();
    ansFromPostfix();
}

