#include <bits/stdc++.h>

using namespace std;

int board[7][7];
pair<int, int> blacks[6];
pair<int, int> whites[6];
pair<int, int> neutron;
int ord1[6];
int ord2[6];


void init(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    //init board
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j<=5; j++){
            board[i][j] = -1;
        }
        for(int i = 1; i<=5; i++){
            board[i][1] = i;
        }
        for(int i = 1; i<=5; i++){
            board[i][5] = i+5;
        }
        board[3][3] = 11;
    }
    //init coords
    for(int i = 1; i<= 5; i++){
        blacks[i] = make_pair(i, 1);
        whites[i] = make_pair(i, 5);
    }
    neutron = make_pair(3, 3);
    //init turn numbers
    for(int i = 0; i < 5; i++){
        cin >> ord1[i];
    }
    for(int i = 0; i< 5; i++){
        cin >> ord2[i];
    }
}

pair<int, int> change_dir(int dir){
    int delta_x, delta_y;
    if(dir < 5){
        delta_x = 1;
    }
    else{
        delta_x = -1;
    }
    if(dir < 3 or dir == 8){
        delta_y = -1;
    }
    else{
        delta_y = 1;
    }
    if(dir%4 == 1){
        delta_x = 0;
    }
    if(dir%4 == 3){
        delta_y = 0;
    }
    return(make_pair(delta_x, delta_y));
}

pair<int, int> check_dest(pair<int, int> coords, int dir){
    pair<int, int> delta = change_dir(dir);
    while(board[coords.first + delta.first][coords.second+delta.second] == -1){
        coords.first += delta.first;
        coords.second += delta.second;
    }
    return coords;
}

void print_board(){
    for(int i =1; i <= 5; i++){
        for(int j = 1; j <= 5; j++){
            int xd = board[j][i];
            if(xd == -1){
                cout << ".";
            }
            else if(xd > 0 and xd <= 5){
                cout << "S";
            }
            else if(xd <= 10){
                cout << "F";
            }
            else if(xd==11){
                cout << "*";
            }


        }
        cout << "\n";
    }
}

void displace(int val, pair<int, int> cur, pair<int, int> npos){
    board[cur.first][cur.second] = -1;
    board[npos.first][npos.second] = val;
    if(val <= 5){
        blacks[val] = npos;
    } else if(val <= 10){
        whites[val-5] = npos;
    }else{
        neutron = npos;
    }
}

int MOVE(int player, int move ){
    int first_pos = -1;
    int first_ok = -1;
    for(int i = 1; i<= 8; i++){
        pair<int, int> dest = check_dest(neutron, i);
        if(dest.second == 1){ //top, black
            if(player == 1){
                displace(11, neutron, dest);
                return -1;
            }

        } else if (dest.second < 5){
            //if that actually moves and first_pos is -1, check if that blocks the piece i wanna move. If not, that's first_ok
            if(first_ok == -1 and (dest.first != neutron.first and dest.second != neutron.second)){

            }
        }
        else{
            if(player == 5){ //bottom, white
                displace(11, neutron, dest);
                return -1;
            }

        }
    }


    //return -1 if game ended, else return 0
}


int main(){
    init();
    //loop moves, terminate if returns -1 
    print_board();
}

