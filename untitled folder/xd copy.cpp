#include <bits/stdc++.h>
using namespace std;

int char_to_no(char z){
    return int(z)-64;
}
int no_to_char(int n){
    return char(n+64);
}

string encode(string zn){
    string xd = "";
    xd[0] = zn[0];
    for(int i = 1; i < zn.length(); i++){
        xd[i] = no_to_char((char_to_no(zn[i]) + char_to_no(zn[i-1]))%26);
    }
    return xd;
}


int main(){
    // string in;
    // cin >> in;
    // int last = 0;

    // for(int i = 0; i < in.length(); i++){
    //     int xd = char_to_no(in[i]);
    //     in[i] = no_to_char((char_to_no(in[i])-last+26-1)%26+1);
    //     last = xd;
        
    // }
    // cout << in << endl;
    cout << encode("ENCRYPT");
    string key = "OLYMPIAD";
    string key2 = encode(key);
    int it = 1;
    while(key != key2){
        key2 = encode(key2);
        it++;
    }
    cout << it << endl;

}