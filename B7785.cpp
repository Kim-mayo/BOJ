#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

set <string> st;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    string a;
    getline(cin,a);
    for(int i=0;i<n;i++){
        string s; getline(cin,s);
        int index=0;
        int next_index = s.find(' ',index);
        string a = s.substr(index,next_index-index);
        string b = s.substr(next_index+1,s.size()-next_index-1);
        
       if(b=="enter"){
           st.insert(a);
       }
       else{
           st.erase(a);
       }
    }
    
    set <string> :: reverse_iterator it;
    for(it=st.rbegin();it!=st.rend();it++){
        cout << *it << "\n";
    }
}