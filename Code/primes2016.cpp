#include<bits/stdc++.h>
using namespace std;

const int L = 1024*1024*4+5;
const int N = 1024*1024*4+5;
bool pr[L];
vector<int> primes;
vector<int> sas[N];
bool vis[N];
int l, p, q;
queue<pair<int, int> > BFS_q;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> l >> p >> q;
    auto start = chrono::high_resolution_clock::now();

    int x = 1024*2;
    for(int i = 2; i < l; i++){
        if(not pr[i]){
            primes.push_back(i);
            if(i <= x){
                for(int j = i; j*i <= l; j++){
                    pr[j*i] = 1;
                }
            }
            for(int j = 1; j <= i; j*=2){
                if(not pr[i-j]){
                    sas[i].push_back(i-j);
                    sas[i-j].push_back(i);
                }

            }
        }
    }
    BFS_q.push(make_pair(p, 0));
    while (BFS_q.size() > 0){
        int a = BFS_q.front().first;
        int i = BFS_q.front().second;
        BFS_q.pop();
        if(a == q){
            cout << i+1 << endl;
            auto end = chrono::high_resolution_clock::now();
            auto dur = chrono::duration_cast<chrono::milliseconds>(end-start).count();
            cout << dur << endl;
            return 0;
        }
        vis[a] = 1;
        for(int s: sas[a]){
            if(not vis[s]){
                BFS_q.push(make_pair(s, i+1));
            }
        }
    }


}