#include <bits/stdc++.h>

using namespace std;


int calc_prod(int n){
    int prod = 1;
        int x = sqrt(n);
    for(int i = 2; i < x; i++){
        if(n%i == 0){
            prod *= i;
            while(n%i == 0){
                n/=i;
            }
        }
    }
    prod*=n;
    return prod;
}

int n;
int bs[1000000];
pair<int, int> maks(0, -1);

int main(){
    int x;
    cin >> x;
    cout << calc_prod(x) << endl;

    //1B CAN BE BASHED - NUMBERS ARE IN THE FORM OF 10*2^a5^b for nonneg integers a, b, and finding 10 smallest 2^a5^b can be easily done by writing out a tree where going down-left is multiplying by 2, and going down-right is multiplying by 5
    //RESPONSE TO 1C
    // for(int i = 1; i<= 1000000; i++){
    //     int x = calc_prod(i);
    //     bs[x]++;
    //     if(bs[x] > maks.first){
    //         maks.first = bs[x];
    //         maks.second = x;
    //     }
    // }
    // cout << maks.second << endl;
    // cout << bs[maks.second] << endl;
    // cout << bs[210];

    return 0;
    
}