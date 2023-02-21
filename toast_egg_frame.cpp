#include <iostream>
#include <vector>

using namespace std;

int n, L, R;
int plain[50][50];
int plaingen[50][50];
int sumfield[50*50];
int cntfield[50*50];
bool hasDrawn;
int refreshed = 0;

void printPlain(){
    for(int i=0; i <n; i++){
        for(int j=0; j <n; j++){
            cout << plain[i][j] << " ";
        }
        cout << endl;
    }   
    cout << endl;
}

void refreshPlain(){
    refreshed++;
    for(int i=0; i <n; i++){
        for(int j=0; j <n; j++){
            int sumfieldidx = plaingen[i][j];
            sumfield[sumfieldidx] += plain[i][j];
            cntfield[sumfieldidx]++;
        }
    }
    for(int i=0; i <n; i++){
        for(int j=0; j <n; j++){
            int sumfieldidx = plaingen[i][j];
            plain[i][j] = sumfield[sumfieldidx] / cntfield[sumfieldidx];
        }
    }
}

void drawPlainGen(){
    hasDrawn = false;
    int idx = 0;
    for(int i=0; i <n; i++){
        for(int j=0; j <n; j++){
            int cvalue;
            if(i > 0){
                cvalue = abs(plain[i][j] - plain[i-1][j]);
                if(L <= cvalue && cvalue <= R){
                    hasDrawn = true;
                    plaingen[i][j] = plaingen[i-1][j];
                }
            }
            if(j > 0){
                cvalue = abs(plain[i][j] - plain[i][j-1]);
                if(L <= cvalue && cvalue <= R){
                    hasDrawn = true;
                    plaingen[i][j] = plaingen[i][j-1];
                }
            }
        }
    }
    
}

void initPlainGen(){
    int idx = 0;
    for(int i=0; i <n; i++){
        for(int j=0; j <n; j++){
            plaingen[i][j] = idx++;
            sumfield[i*n+j] = 0;
            cntfield[i*n+j] = 0;
        }
    }
}

int main() {
    cin >> n >> L >> R;
    for(int i=0; i <n; i++){
        for(int j=0; j <n; j++){
            cin >> plain[i][j];
        }
    }
    while(true){
        //printPlain();
        initPlainGen();
        drawPlainGen();
        if(hasDrawn == false) break;
        refreshPlain();
    }
    
    cout << refreshed;
    
    return 0;
}
