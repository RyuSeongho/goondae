#include <iostream>
#include <vector>

using namespace std;

#define PETRI_INIT_NUM 5
int n, m, k;
int plain_yangboon_petri[10][10] = {0};
int plain_yangboon_renew[10][10] = {0};
vector<int> plain_virus[10][10];

void init_petri(){
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            plain_yangboon_petri[i][j] = PETRI_INIT_NUM;
        }
    }
}


int main() {
    cin >> n >> m >> k;
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            cin >> plain_yangboon[i][j];
        }
    }
    for(int i=0; i < m; i++){
        cin >> 
    }
    return 0;
}
