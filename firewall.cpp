
#include <iostream>
using namespace std;

int index = 0;
int n, m;
int matrix[2][8][8];
int pos1[64];
int pos2[64];

int min = 64;

void copy(){
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            matrix[1][i][j] = matrix[0][i][j];
        }
    }

}



int spread(){
    int level = 0;
    int sum = 0;
    int spread = -1;
    while(spread != 0){
        spread = 0;
        for(int i=0; i < n; i++){
            for(int j=0; j < n; j++){
                if(matrix[1][i][j] == 2 + level){ //불인 경우

                    if(i - 1 > 0 && j - 1 > 0 && matrix[1][i-1][j-1] == 0 && ++spread > 0) matrix[1][i-1][j-1] == 2 + level + 1;
                    if(i - 1 > 0 && j + 1 < n && matrix[1][i-1][j+1] == 0 && ++spread > 0) matrix[1][i-1][j+1] == 2 + level + 1;
                    if(i + 1 < n && j - 1 > 0 && matrix[1][i+1][j-1] == 0 && ++spread > 0) matrix[1][i+1][j-1] == 2 + level + 1;
                    if(i + 1 < n && j + 1 < n && matrix[1][i+1][j+1] == 0 && ++spread > 0) matrix[1][i+1][j+1] == 2 + level + 1;
                }
            }
        }
        level++;
        sum += spread;
    }

    return sum;
}

void getpos(){
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            if(matrix[1][i][j] > 2){
                pos1[index] = i;
                pos2[index] = j;
                index++;
            }
        }
    }
}

void process(){

    for(int i=0; i < index - 2; i++){
        for(int j=i+1; j < index - 1; j++){
            for(int k=j+1; k < index; k++){
                matrix[1][pos1[i]][pos2[i]] == 1;
                matrix[1][pos1[j]][pos2[j]] == 1;
                matrix[1][pos1[k]][pos2[k]] == 1;
                int result = spread();
                if(min > result) min = result;
                matrix[1][pos1[i]][pos2[i]] == 0;
                matrix[1][pos1[j]][pos2[j]] == 0;
                matrix[1][pos1[k]][pos2[k]] == 0;
            }
        }
    }
}

int gethollow(){
    int result = 0;
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            if(matrix[0][i][j] == 0) result++;
        }
    }

    return result;
}

int main(){
    cin >> n >> m;
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            cin >> matrix[0][i][j];
        }
    }
    copy();
    spread();

    getpos();
    copy();
    process();

    cout << gethollow() - min;
}

//3 개를 놓을 수 있는 자리

//불이 퍼져 나가는 단계에 그 자리에 놓는 걸로
