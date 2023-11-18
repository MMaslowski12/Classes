#include <bits/stdc++.h>
#include <chrono>
using namespace std;

const int N = 50;

int p, s, n;
int seq[N];
int t[N][N];
queue<pair<int,int> > q4s;

void add(int x, int y){
    t[x][y]++;
    if(t[x][y] >= 4){
        q4s.push(make_pair(x, y));
    }
}

void pop_4s(){
    while(q4s.size() > 0){
        pair<int, int> coords = q4s.front();
        q4s.pop();
        if(t[coords.first][coords.second] >= 4){
            if((coords.first == 0) or (coords.second == 0)){
                cout << "ERROR \n";
            }
            else if(coords.first == 50 or coords.second == 0){
                cout << "ERROR \n";
            }
            for(int i = -1; i<=1; i+=2){
                add(coords.first+i, coords.second);
            }
            for(int i = -1; i<=1; i+=2){
                add(coords.first, coords.second+i);
            }
            t[coords.first][coords.second] -= 4;
            if(t[coords.first][coords.second] >= 4){
                q4s.push(coords);
            }
        }
    }
}

pair<int, int> read_p(int p){
    int x = (p-1)%5+1;
    int y = (p-1)/5+1;
    return make_pair(x+20, y+20);
}





int main(){
    
    //1 to 20 - backup
    //21 to 25 - actual map
    //26 - 50 - backup
    cin >> p >> s >> n;
    for(int i = 0; i < s; i++){
        cin >> seq[i];
    }
    auto start = chrono::high_resolution_clock::now();
    pair<int, int> coords = read_p(p);
    add(coords.first, coords.second);
    pop_4s();

    for(int i = 0; i < n-1; i++){
        p += seq[i%s];
        p = (p-1)%25+1;
        coords = read_p(p);
        add(coords.first, coords.second);
        pop_4s();
    }

    for(int i = 21; i <= 25; i++){
        for(int j = 21; j <= 25; j++){
            cout << t[j][i] << " ";
        }
        cout << endl;
    }

    auto end = chrono::high_resolution_clock::now();
    auto dur = chrono::duration_cast<chrono::milliseconds>(end-start).count();
    cout << dur << endl;
}