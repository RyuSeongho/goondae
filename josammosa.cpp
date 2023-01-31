#include <iostream>
#include <limits>
using namespace std;

int n;
int p[20][20] = {0};
bool arr[20];
int mmin = 2147483647;

void cal(){

}

void getmin(){
    for(int i=0; i< n; i++){
        cout << arr[i] << " ";
    }
    int tsum = 0;
    int fsum = 0;
    for(int i=0; i < n; i++){
        if(arr[i]){
            for(int j=0; j < n; j++){
                if(arr[j]) tsum += arr[j];
            }
        } else {
            for(int j=0; j < n; j++){
                if(!arr[j]) fsum += arr[j];
            }
        }
    }
    cout << endl << fsum << " ";
    cout << tsum << endl << endl;
    int cmin = abs(fsum - tsum);
    if(cmin < mmin) mmin = cmin;
}

void dfs(int size, int indic, bool isSame){
    if(indic >= n && size != n/2) return;
    if(size < n/2){ //아직 다 안 찼으면
        if(isSame) arr[indic] = arr[indic-1];
        else arr[indic] = !arr[indic-1];
        if(arr[indic]) size++;
        dfs(size, indic + 1, true);
        dfs(size, indic + 1, false);
    } else { //true가 다 차면
        for(; indic < n; indic++){
            arr[indic] = false;
        }
        getmin();
    }
    
}

int main() {
    cin >> n;
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            cin >> p[i][j];
        }
    }
    
    arr[0] = true;
    dfs(1, 1, true);
    dfs(1, 1, false);

    cout << mmin;
    return 0;
}
