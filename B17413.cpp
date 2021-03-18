#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <stack>
using namespace std;

#define INF 1e9
stack<char>st;
queue<char>q;
string ans ="";
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s; getline(cin,s);
    for(int i=0;i<s.size();i++){

        if(s[i]=='<'){
            while(s[i]!='>'){
                ans += s[i];
                i++;
            }
            ans+=s[i];
        }
        else{ㄴ

            while(s[i]!=' '&&s[i]!='<'&&i!=s.size()){
                st.push(s[i]);
                i++;
            }
            while(!st.empty()){
                char me = st.top();
                st.pop();
                ans += me;
            }
            if(i==s.size())break;
            if(s[i]=='<')i--;
            else ans+=s[i];

        }
    }

    cout << ans;
    return 0;
}