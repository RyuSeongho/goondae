#include <iostream>
using namespace std;

class dice{
private:
    int number[3][4]; //평면도

public:
    dice(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 4; j++){
                if(i == 1 || j == 1) number[i][j] = 0;
                else number[i][j] = -1;
            }
        }
    }



    int roll(int dir){
        int temp;
        switch(dir){
            case 1: // 동
                temp = number[1][0];
                for(int i=0; i< 3; i++){
                    number[1][i] = number[1][i+1];
                }
                number[1][3] = temp;
                break;
            case 2: // 서
                temp = number[1][3];
                for(int i=3; i > 0; i--){
                    number[1][i] = number[1][i - 1];
                }
                number[1][0] = temp;
                break;
            case 3: // 북
                temp = number[1][3];
                number[1][3] = number[2][1];
                number[2][1] = number[1][1];
                number[1][1] = number[0][1];
                number[0][1] = temp;
                break;
            case 4: // 남
                temp = number[1][3];
                number[1][3] = number[0][1];
                number[0][1] = number[1][1];
                number[1][1] = number[2][1];
                number[2][1] = temp;
                break;
            default:
                return -1;
                break;
        }
        return number[1][1];
    }

    void copy(int numb){
        number[1][1] = numb;
    }

    int get(){
        return number[1][3];
    }
};

int m, n; // 말판의 가로 세로 크기
int x, y; // 정육면체의 위치
int k; // 굴리기 횟수

int matrix[20][20]; // 말판

int roll[1000]; //굴리기 방향 저장

dice d; // 주사위




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
                y++;
                break;
            case 2:
                y--;
                break;
            case 3:
                x--;
                break;
            case 4:
                x++;
                break;
            default:
                break;
        }
        if(x >= n) x = n - 1;
        else if(x < 0) x = 0;
        else if(y >= m) y = m - 1;
        else if(y < 0) y = 0;
        else {
            int current = matrix[x][y]; //칸에 적힌 숫자
            int result = d.roll(input); //주사위에 적힌 숫자
            if(current == 0){
                matrix[x][y] = result; // 주사위를 칸에 복사
            }
            else{
                d.copy(current);
                matrix[x][y] = 0;
            }
            cout << d.get() << endl;
        }
    }

    return 0;
}
