#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>ans;
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    int BIT=0;
    for(int p=0;p<n;p++){

        string a; cin >> a;
        if(a=="all"){
            BIT = -1;
        }
        else if(a=="empty"){
            BIT = 0;
        }
        else{
            int i; cin >> i;

            if(a=="add"){
                BIT |= (1 << i);
            }
            else if(a=="remove"){
                BIT &= ~(1 << i);
            }
            else if(a=="toggle"){
                BIT ^= (1 << i);
            }
            else if(a=="check"){
                bool ok = BIT & (1 << i);
                if(ok)cout << "1\n";
                else cout << "0\n";
            }
        }

    }
}