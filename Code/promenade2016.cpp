#include <bits/stdc++.h>

using namespace std;



int gcd(int a, int b){
    if(a < b){
        swap(a, b);
    }
    if(b == 0){
        return a;
    }
    else{
        return gcd(a-b, b);
    }
}

pair<int, int> add(pair<int, int> a, pair<int, int> b){
    pair<int, int> res = make_pair(a.first+b.first, a.second+b.second);
    int g = gcd(res.first, res.second);
    res = make_pair(res.first/g, res.second/g);
    return res;
}



const int N = 11;

string xd;


int main(){
    pair<int, int> last_left = make_pair(1, 0);
    pair<int, int> last_right = make_pair(0, 1);
    pair<int, int> last_val = make_pair(1, 1);
    cin >> xd;
    auto start = chrono::high_resolution_clock::now();
    for(int i = 0; i < xd.length(); i++){
        if(char(xd[i]) == 'L'){
            last_left = last_val;
        } else if(char(xd[i]) == 'R'){
            last_right = last_val;
        }
        else{
            cout << "ERROR" << endl;
            return 2137;
        }
        last_val = add(last_left, last_right);
    }
    cout << last_val.first << " / " << last_val.second << "\n";
    auto end = chrono::high_resolution_clock::now();
    auto dur = chrono::duration_cast<chrono::milliseconds>(end-start).count();
    // cout << dur << endl;
    // cout << float(last_val.first)/float(last_val.second) - 17.0/20.0 << endl;
    // return 0;

    //1b - 6 / 11 = LRRRRRLR
    //1c - 999 999 Ls, 0 Rs
    //1d - no, we can do that by induction: all promenades shorter than n have both nonnegative nominator and denominator, n = 1 works, induction: (l+r)/(m+s) is positive when all l, r, m, s are nonnegative
}