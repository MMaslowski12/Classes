#include <bits/stdc++.h>
using namespace std;

double amount = 100;
double ist;
double rpm;
double sum = 0;

int calc_rpm(){
    return min(amount, max(50.00, amount*ist));
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(0)
    cin >> ist >> rpm;333
    
    ist /= 100;
    rpm /= 100;
    while(amount > 0){
        amount *= 1+ist;
        cout << "amount increased to " << amount << endl;
        int x = calc_rpm();
        sum += x;
        amount -= x;
        cout << "amount decreased to " << amount << endl;
    }
    cout << sum << endl;
    return 0;

}