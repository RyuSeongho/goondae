#include <iostream>
using namespace std;

int n;
int p[20][20] = {0};
bool arr[20] = {0};
int mmin = 2147483647;

void getmin(){
    int tsum = 0;
    int fsum = 0;
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            if(arr[i] == arr[j]){
                if(arr[i]) tsum += p[i][j];
                else fsum += p[i][j];
            }
        }
    }
    int cmin = abs(fsum - tsum);
    if(cmin < mmin) mmin = cmin;
}

void dfs(int idx, bool flag, int truenum){
    int maxtruenum = n - idx + truenum;
    if(maxtruenum < n/2) return; //halt
    if(idx >= n){ //halt
        getmin();
        return;
    }
    arr[idx++] = flag; //apply
    if(flag) truenum++;
    if(truenum < n/2) dfs(idx, true, truenum);
    dfs(idx, false, truenum);
}

int main() {
    cin >> n;
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            cin >> p[i][j];
        }
    }
    
    dfs(0, true, 0);

    cout << mmin;
    return 0;
}
