#include <bits/stdc++.h>

using namespace std;
const int N = 12;

int t[N];
int reses[N][N];

int calc(int a, int b){
    cout << "WCHODZE DO " << a << "; " << b << endl;
    if(reses[a][b] != -1){
        return reses[a][b];
    }
    if(a == b){
        return 1;
    }
    if(a == b+1){
        return 1;
    }
    int sum = 1;
    int s = a;
    int f = b;
    while(t[s] == t[f] && s<f){
        cout << "PRZECHODZE Z " << a << " " << b << " DO: " << s+1 << " " << f-1 << endl;
        sum += calc(s+1, f-1);
        s++;
        f--;
    }
    reses[a][b] = sum;
    cout << "RES OF " << a << " " << b << " IS " << sum << endl;
    return sum;
}
string n;

int main(){
    for(int i = 0; i< N; i++){
        for(int j = 0; j < N; j++){
            reses[i][j] = -1;
        }
    }
    cin >> n;
    cout << "DOSTAŁEM " << n << endl;
    for(int i = 0; i < n.length(); i++){
        t[i] = n[i];
    }
    cout << calc(0, n.length()-1)-1;

}