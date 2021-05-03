#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int>leaf;
void findLeaf(int root, int remove, vector<vector<int> >&tree){

    queue<int>q;
    q.push(root);
    if(root==remove) return;
    while(!q.empty()){

        int curr = q.front();
        q.pop();
        bool ok = false;
        for(int i=0;i<tree[curr].size();i++){
            int next = tree[curr][i];
            if(next!=remove){
                q.push(next);
                ok = true;
            }
        }
        if(ok == false)leaf.push_back(curr);
    }
    return;
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int> > tree(n);
    int root = -1;
    for(int i=0;i<n;i++){
        int a; cin >> a;
        if(a==-1){
            root = i;
            continue;
        }
        tree[a].push_back(i);
    }
    int remove; cin >> remove;
    tree[remove].clear();
    findLeaf(root,remove,tree);
    cout << leaf.size();
}