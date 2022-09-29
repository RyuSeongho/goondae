#include <iostream>
using namespace std;

int matrix[100][100];

int n, L;

bool row_start(int row){
    int curr = 0;
    int* p = matrix[row];
    int slad[100] = {0};
    bool flag = true;
    //cout << endl;
    while(curr < (n - 1)){
        //for(int i =0; i< n; i++) cout << slad[i] << " ";
        //cout << endl;
        if(*(p + curr) != *(p + curr + 1)){ // 다음 게 달라
            if(*(p + curr) + 1 == *(p + curr + 1)){ //한 칸 올라감
                if(curr - L + 1 < 0){
                    return false;
                }
                for(int i=0; i < L; i++){
                    if(slad[curr-i] == 1) return false; //이미 깔려 있어도 나가리
                    if(*(p + curr - i) != *(p + curr)) return false; //높이가 일정하지 않으면 나가리
                    slad[curr - i] = 1;
                }
            }
            else if(*(p + curr) - 1 == *(p + curr + 1)){ //한 칸 내려감
                if(curr + L >= n){
                    return false;
                }
                for(int i=1; i <= L; i++){
                    if(*(p + curr + i) != *(p + curr + 1)) return false; //높이가 일정하지 않으면 나가리
                    slad[curr + i] = 1;
                }
            }
            else{ //두 칸 차이
                return false;
            }
        }
        curr++;
    }
    return true;
}


void turn()
{
    int result_matrix[100][100];
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++) result_matrix[i][j] = matrix[n-1-j][i];
    }
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++) matrix[i][j] = result_matrix[i][j];
    }
}

int main(){
    int capable = 0;
    cin >> n >> L;
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            cin >> matrix[i][j];
        }
    }

    for(int i =0; i < n; i++){
        if(row_start(i)) capable++;
    }
    turn();
    for(int i =0; i < n; i++){
        if(row_start(i)) capable++;
    }

    cout << capable;
}
