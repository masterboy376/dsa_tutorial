#include "bits/stdc++.h"
using namespace std;

bool redundantParentheses(string a){
    stack<char> st;
    for(int i = 0; i<a.size(); i++){
        if(a[i]=='('){
            st.push(a[i]);
        }
        else if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/' || a[i]=='^'){
            st.push(a[i]);
        }
        else if(a[i]==')'){
            if(st.top()=='('){
                return true;
            }
            else{
                while(st.top()!='('){
                    st.pop();
                }
                st.pop();
            }
        }
    }
    return false;
}

int main()
{
    string a = "(a+(a+b))";
    cout<<redundantParentheses(a)<<endl;

    return 0;
}