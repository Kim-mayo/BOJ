#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector <int> bin;
vector <int> ten;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n; cin >> n;
    int s = n.size();

    while(1){
        if(s%3==0)break;
        bin.push_back(0);
        s++;
    }
    for(int i=0;i<n.size();i++){
        int num = n[i]-'0';
        bin.push_back(num);
    }
    
    //for(int i=0;i<bin.size();i++)cout << bin[i] << " ";
    //cout << "\n";
    //cout << bin.size() << "\n";
    int ret=0;
    
    for(int i=0;i<s;i+=3){
        int r=0;
        int a=bin[i];
        int b=bin[i+1];
        int c=bin[i+2];
        if(a==1)r+=4;
        if(b==1)r+=2;
        if(c==1)r+=1;
        
        ten.push_back(r); 
       // cout << r << "\n";
    }
    for(int i=0;i<ten.size();i++){
        //if(ten[i]==0)
        cout << ten[i];
    }
}