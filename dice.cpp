class dice{
private:
    int x_pos = 1;
    int y_pos = 1;
    int number[3][4]; //평면도

    void good_pos(){
        if(x_pos < 0) x_pos += 4;
        else if(x_pos > 3) x_pos -= 4;
        if(y_pos < 0) y_pos += 4;
        if(y_pos > 2) {
            x_pos == 3;
            y_pos == 1;
        }
    }

    void find_vert(){
        good_pos();
        if(number[y_pos][x_pos] == -1){
            y_pos = 1;
        }
    }
    void find_horz(){
        good_pos();
        if(number[y_pos][x_pos] == -1){
            x_pos = 1;
        }
    }


public:
    roll(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 4; j++){
                if(i == 1 || j == 1) number[i][j] = 0;
                else number[i][j] = -1;
            }
        }
    }



    int roll(int dir){
        switch(dir){
            case 1: // 동
                x_pos++;
                find_vert();
                break;
            case 2: // 서
                x_pos--;
                find_vert();
                break;
            case 3: // 북
                y_pos--;
                find_horz();
                break;
            case 4: // 남
                y_pos++;
                find_horz();
                break;
            default:
                return -1;
                break;
        }
        return number[y_pos][x_pos];
    }

    void copy(int numb){
        number[y_pos][x_pos] == numb;
    }

    int get(){
        int org_x = x_pos;
        int org_y = y_pos;
        x_pos += 2;
        find_vert();

        int rtr = number[y_pos][x_pos];
        
        x_pos = org_x;
        y_pos = org_y;

        return rtr;
    }
};

int m, n; // 말판의 가로 세로 크기
int x, y; // 정육면체의 위치
int k; // 굴리기 횟수

int matrix[20][20]; // 말판

int roll[1000]; //굴리기 방향 저장

dice d; // 주사위

#include <iostream>
using namespace std;



int main(){
    cin >> n >> m >> x >> y >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> matrix[i][j];
        }
    }
    for(int i=0; i<k; i++){
        int input;
        cin >> input;

        switch(input){
            case 1:
                x++;
                break;
            case 2:
                x--;
                break;
            case 3:
                y--;
                break;
            case 4:
                y++;
                break;
            default:
                break;
        }
        if(x >= m) x == m;
        else if(x < 0) x == 0;
        else if(y >= n) y == n;
        else if(y < 0) y == 0;
        else {
            int current = matrix[x][y]; //칸에 적힌 숫자
            int result = d.roll(input); //주사위에 적힌 숫자
            if(current == 0){
                current = result; // 주사위를 칸에 복사
            }
            else{
                d.copy(current);
                matrix[x][y] = 0;
            }
            cout << d.get();
        }
    }

    return 0;
}
