#include <iostream>
using namespace std;

int n,k;
bool prime[1001];
void eratos(){
int cnt=0;
for(int i=2;i<=n;i++){

if(prime[i]==false){
    
    cnt++;
    if(cnt==k){ cout << i; return; }
    for(int j=i*i;j<=n;j+=i){
        prime[j] = true;
        cnt++;
        if(cnt==k){cout << j; return;}
    }
}

}

}
int main(){

cin >> n >> k;
eratos();

}
