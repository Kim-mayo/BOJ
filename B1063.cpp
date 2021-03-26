#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string king; cin >> king;
    int kingr = king[1]-'0';
    int kingc = king[0]-'A';
    string stone; cin >> stone;
    int stoner = stone[1]-'0';
    int stonec = stone[0]-'A';

    int n; cin >> n;
    for(int i=0;i<n;i++){
        string order; cin >> order;
        int kc = kingc;
        int kr = kingr;
        int sc = stonec;
        int sr = stoner;
        bool ok = true;
        if (order == "T"){
            if (kr + 1 > 8){ok = false;}
            kr += 1;
            if (kr == sr && kc == sc){
                sr += 1;
                if (sr > 8){ok = false;}
            }
        }
        else if (order == "B"){
            if (kr - 1 <= 0){ok = false;}
            kr -= 1;
            if (kr == sr && kc == sc){
                sr -= 1;
                if (sr <= 0){ok = false; }
            }
        }
        else if (order == "L"){
            if (kc - 1 < 0){ok = false;}
            kc -= 1;
            if (kc == sc && kr == sr){
                sc -= 1;
                
                if (sc< 0){ok = false;}
            }
        }
        else if (order == "R")  {
            if (kc + 1 >= 8){ok = false; }
            kc += 1;
            if (kc == sc && kr == sr){
                sc += 1;
                if (sc>= 8){ok = false; }
            }
        }
        else if (order == "RT"){
            if(kc+1>=8||kr+1>8){ok=false;}
            kc+=1; kr+=1;
            if(kc==sc&&kr==sr){
                sc+=1; sr+=1;
                if(sc>=8||sr>8){ok=false;}
            }
        }
        else if(order == "LT"){
            if(kc-1<0||kr+1>8) {ok=false;}
            kc-=1; kr+=1;
            if(kc==sc&&kr==sr){
                sc-=1; sr+=1;
                if(sc<0||sr>8){ok=false; }
            } 
        }
        else if(order == "RB"){
            if(kc+1>=8||kr-1<=0){ok=false;}
            kc+=1; kr-=1;
            if(kc==sc&&kr==sr){
                sc+=1; sr-=1;
                if(sc>=8||sr<=0){ok=false; }
            }
        }
        else if(order == "LB"){
            if(kc-1<0||kr-1<=0){ok=false;}
            kc-=1; kr-=1;
            if(kc==sc&&kr==sr){
                sc-=1; sr-=1;
                if(sc<0||sr<=0){ok=false; }
            }
        }
        if(ok){
                kingr = kr; stoner = sr;
                kingc = kc; stonec = sc;
            }
    }
    cout << char(kingc+'A') << kingr << "\n";
    cout << char(stonec+'A') << stoner << "\n";
}