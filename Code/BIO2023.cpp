#include <bits/stdc++.h>

using namespace std;



int a, b;


int gcd(int a, int b){
    if(b > a){ //a >= b
        swap(a, b);
    }
    if(b == 0){
        return a;
    }
    else{
        return gcd(a-b, b);
    }
}


int main(){
    //a*n mod 60*24 = b*n mod 60*24
    // |b-a| * n mod 60*24 = 0
    //n = 60*24/gcd(60*24, |b-a|), simple as that 
    cin >> a >> b;
    int diff = abs(a-b);
    int g = gcd(60*24, diff);
    int n = 60*24/g;
    int hour = (n*(60+a)/60)%24;
    int minute = (a*n)%60;
    if(hour < 10){
        cout << "0";
    }
    cout << to_string(hour);
    cout << ":";
    if(minute < 10){
        cout << "0";
    }
    cout << to_string(minute);
}