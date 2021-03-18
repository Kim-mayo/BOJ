#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

deque<int>dq;
stack<int>st;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    cout << n;
    vector<int>arr(n,-1);
    for(int i=0;i<n;i++){
        int a; cin >> a;
        arr[i]=a;
    }
   cout << arr[0] << " ";
   for(int i=n-1;i>=0;i--){

       for(int j=0; j<arr[i];j++){
           int curr = dq.front();
           dq.pop_front();
           st.push(curr);
       }
        
        int me = i+1;
        dq.push_front(me);
        for(int j=0;j<arr[i];j++){
            int curr = st.top();
            st.pop();
            dq.push_front(curr);
        }

   }


    while(!dq.empty()){
        cout << dq.front() << " ";
        dq.pop_front();
    }
    return 0;
}