#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nn,mm;
string com[101][101];
string string_sum(string a, string b){

    string ans="";
    int ret[101];
    for(int i=0;i<101;i++)ret[i]=0;
    if(a.size()==b.size()){
        for(int i=a.size()-1;i>=0;i--){
            int hab = (a[i]-'0')+(b[i]-'0');
            ret[i+1] += hab;
            if(ret[i+1]>9){
                ret[i]+=ret[i+1]/10;
                ret[i+1] %= 10;
            }
        }
    }
    else if(a.size()>b.size()){
        int s = a.size()-b.size();
        for(int i=b.size()-1;i>=0;i--){
            int hab = (a[i+s]-'0')+(b[i]-'0');
            ret[i+s+1] += hab;
            if(ret[i+s+1]>9){
                ret[i+s]+=ret[i+s+1]/10;
                ret[i+s+1] %= 10;
            }
        }
        for(int i=s;i>0;i--){
            ret[i] += a[i-1]-'0';
            if(ret[i]>9){
                ret[i-1] += ret[i]/10;
                ret[i] %= 10;
            }
        }
    }
    else if(b.size()>a.size()){
        int s = b.size()-a.size();
        for(int i=a.size()-1;i>=0;i--){
            int hab = (a[i]-'0')+(b[i+s]-'0');
            ret[i+s+1] += hab;
            if(ret[i+s+1]>9){
                ret[i+s]+=ret[i+s+1]/10;
                ret[i+s+1] %= 10;
            }
        }
        for(int i=s;i>0;i--){
            ret[i] += b[i-1]-'0';
            if(ret[i]>9){
                ret[i-1] += ret[i]/10;
                ret[i] %= 10;
            }
        }
    }
    int SIZE = max(a.size(),b.size());
    int i;
    if(ret[0]==0) i=1;
    else i=0;
    //cout << i << "######";
    for(;i<=SIZE;i++){
        ans += ret[i]+'0';
       //cout << ret[i] << " ";
    }
    //cout << a << " " << b << " " << ans <<"\n";
    return ans;
}
string solve(int n, int m){

    if(m==0) return "1";
    if(n==m) return "1";

    if(com[n][m]!="-1") return com[n][m];

    com[n][m] = string_sum(solve(n-1,m-1),solve(n-1,m));
    
    return com[n][m];
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++)com[i][j]="-1";
    }
    cin >> nn >> mm;
    
   cout << solve(nn,mm);

    //cout << string_sum("45","990");

}