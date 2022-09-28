#include <iostream>
using namespace std;

int n, m;
int x, y, d;
int xarr[4] = { -1, 0, 1, 0 };
int yarr[4] = { 0, 1, 0, -1 };
int matrix[50][50];

int s = 0;
int a = 1;

void one();
void two();
void three();
void four();

void one(){
    //d-1이 바라보는 방향 왼쪽

    int _d = (d + 4 - 1) % 4;
    int xdif = xarr[_d];
    int ydif = yarr[_d];
    //cout << xdif << " " << ydif << endl;

    if(matrix[x+xdif][y+ydif] == 0){ //그냥 도로라면
        d = _d;
        s = 0;
        
        x = x + xdif;
        y = y + ydif;
        //cout << "좌회전하고 전진합니다" << endl;
        matrix[x][y] = 2;
        a++;
        one();
        
    }
    else{
        d = _d;
        
        two();
    }
}

void two(){
    s++;
    //cout << "전진" << s << "번 실패"<< endl;
    if(s >= 4) three();
    else one();
    
}

void three(){
    s = 0;

    int xdif = xarr[d];
    int ydif = yarr[d];
    x -= xdif;
    y -= ydif;
    //후진했는데
    switch(matrix[x][y]){
        case 0: //도로라면
            matrix[x][y] = 2;
            a++;
            one();
            //cout << "후진" << endl;
            break;
        case 1: //인도라면
            four();
            break;
        case 2: //이미 간 길이라면
            //cout << "후진" << endl;
            one();
            
            break;
        default:
            cout << "error";
            break;
    }
    
}

void four(){
    cout << a;
    return;
}





int main(){
    cin >> n >> m;
    cin >> x >> y >> d;
    for(int i=0 ; i< n; i++){
        for(int j=0; j < m; j++){
            cin >> matrix[i][j];
        }
    }

    matrix[x][y] = 2;

    one();

    return 0;
}
