#include <iostream>
using namespace std;

int n, m;
int matrix[200][200];

int xlen[5] = {1,4,2,3,2};
int ylen[5] = {4,1,2,2,3};

int x = 0;
int y = 0;

int _max = 0;

int cal_twothree(){
    int _min = 2000;
    int sum = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            sum += matrix[x + i][y + j];
        }
    }
    //sum도 계산 완료

    int i = x;
    int j = y;

    int curr;
    curr = matrix[i][j] + matrix[i][j+1];
    if(curr < _min) _min = curr;
    curr = matrix[i][j+1] + matrix[i][j+2];
    if(curr < _min) _min = curr;
    curr = matrix[i+1][j] + matrix[i+1][j+1];
    if(curr < _min) _min = curr;
    curr = matrix[i+1][j+1] + matrix[i+1][j+2];
    if(curr < _min) _min = curr;

    curr = matrix[i][j] + matrix[i+1][j+2];
    if(curr < _min) _min = curr;
    curr = matrix[i+1][j] + matrix[i][j+2];
    if(curr < _min) _min = curr;

    curr = matrix[i][j] + matrix[i][j+2];
    if(curr < _min) _min = curr;
    curr = matrix[i+1][j] + matrix[i+1][j+2];
    if(curr < _min) _min = curr;

    return sum - _min;    
}

int cal_threetwo(){
    int _min = 2000;
    int sum = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            sum += matrix[x + i][y + j];
        }
    }
    //sum도 계산 완료

    int i = x;
    int j = y;


    int curr;
    curr = matrix[i][j] + matrix[i+1][j];
    if(curr < _min) _min = curr;
    curr = matrix[i+1][j] + matrix[i+2][j];
    if(curr < _min) _min = curr;
    curr = matrix[i][j+1] + matrix[i+1][j+1];
    if(curr < _min) _min = curr;
    curr = matrix[i+1][j+1] + matrix[i+2][j+1];
    if(curr < _min) _min = curr;

    curr = matrix[i][j] + matrix[i+2][j+1];
    if(curr < _min) _min = curr;
    curr = matrix[i][j+1] + matrix[i+2][j];
    if(curr < _min) _min = curr;

    curr = matrix[i][j] + matrix[i+2][j];
    if(curr < _min) _min = curr;
    curr = matrix[i][j+1] + matrix[i+2][j+1];
    if(curr < _min) _min = curr;

    return sum - _min;
    
}

int cal_sum(int shape){
    int result = 0;
    switch(shape){
        case 3:
            result = cal_threetwo();
            break;
        case 4:
            result = cal_twothree();
            break;
        default:
            for(int i = 0; i < xlen[shape]; i++){
                for(int j = 0; j < ylen[shape]; j++){
                    result += matrix[x+i][y+j];
                }
            }
            break;
    }
    //cout << "!" << result << " ";
    return result;
}

bool next(int shape){
    y++;
    if(y + ylen[shape] - 1 >= m){ //out of bound
        y = 0;
        x++;
        if(x + xlen[shape] - 1 >= n){ //out of bound, end
            x--;
            return false;
        }
    }
    int result = cal_sum(shape);
    if(_max < result) _max = result;
    return true;
}


int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    for(int i =0; i < 5; i++){
        //cout << endl << "new shape!" << endl;
        x = 0;
        y = 0;
        int result = cal_sum(i);
        if(_max < result) _max = result;

        while(next(i)){
        }
        

    }

    cout << _max;




}
