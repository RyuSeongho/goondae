#include <iostream>
using namespace std;

int n, m;
int plain[8][8];
int calplain[8][8];
int dir[8] = {0};
int pos[8] = {0};
int idx = 0;
int diriarr[4] = {-1,0,1,0};
int dirjarr[4] = {0,1,0,-1};
int mmin = 64;

void printcalplain(){
    for(int i =0; i< n; i++){
        for(int j=0; j<m; j++){
            cout << calplain[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void init(){
    for(int i =0; i< n; i++){
        for(int j=0; j<m; j++){
            calplain[i][j] = plain[i][j];
        }
    }
}

int countleft(){
    int sum = 0;
    for(int i =0; i< n; i++){
        for(int j=0; j<m; j++){
            if(calplain[i][j] == 0) sum++;
        }
    }
    return sum;
}

void move(int i, int j, int d){
    d--;
    while(i >= 0 && j >= 0 && i < n && j < m){
        i += diriarr[d];
        j += dirjarr[d];
        if(calplain[i][j] == 0) calplain[i][j] = 7;
        else if(calplain[i][j] == 6) break;
    }
    
}

int rotate(int org, int power){
    int rtr = org + power;
    if(rtr > 4) rtr -=4;
    return rtr;
}

void calleft(){
    init();
    for(int i =0; i< idx; i++){
        int addi = pos[i] / 8;
        int addj = pos[i] % 8;
        switch(plain[addi][addj]){
            case 1:
                move(addi, addj, dir[i]);
                break;
            case 2:
                move(addi, addj, dir[i]);
                move(addi, addj, rotate(dir[i], 2));
                break;
            case 3:
                move(addi, addj, dir[i]);
                move(addi, addj, rotate(dir[i], 1));
                break;
            case 4:
                move(addi, addj, dir[i]);
                move(addi, addj, rotate(dir[i], 1));
                move(addi, addj, rotate(dir[i], 3));
                break;
            case 5:
                move(addi, addj, 1);
                move(addi, addj, 2);
                move(addi, addj, 3);
                move(addi, addj, 4);
                break;
            default:
                break;
        }
    }
    
    int cleft = countleft();
    //cout << "[!]" << cleft << " " << endl;
    if(cleft < mmin) mmin = cleft;
    if(cleft > 20) printcalplain();
}

void process(int i){

    if(i < idx - 1) process(i + 1);

    dir[i]++;
    
    if(dir[i] > 4) {
        dir[i] = 1;
        return;
    } else{
        calleft();
        process(i);
    }
}

int main() {
    cin >> n >> m;
    for(int i =0; i< n; i++){
        for(int j=0; j<m; j++){
            cin >> plain[i][j];
            if(plain[i][j] >= 1 && plain[i][j] <= 5){
                dir[idx] = 1;
                pos[idx] = i*8+j;
                idx++;
            }
        }
    }
    calleft();
    process(0);

    cout << mmin;

    return 0;
}
