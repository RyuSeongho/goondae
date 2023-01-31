#include <iostream>
using namespace std;

int n, m;
int plain[8][8];
int calplain[8][8];
int dir[8] = {0};
int pos[8] = {0};
int idx = 0;
int chess[6][]

void calleft(){
    for(int i=0; i<idx; i++ ){
        cout << dir[i] << " ";
    }
    cout << endl;

    for(int i =0; i< idx; i++){
        int addi = pos[i] / 8;
        int addj = pos[i] % 8;
        switch(plain[addi][addj]){
            case 1:
                calplain[addi][add]
        }
    }
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
        for(int j=0; j<n; j++){
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

    return 0;
}
