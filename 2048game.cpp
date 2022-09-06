#include <iostream>

using namespace std;


//블록의 값은 로그를 취한 값으로 하자.

int twonear(int limit){
    int i = 0;
    for(i=0; i*2 < limit; i*=2)
    return i;
}

void rotate(int* plain, int size){
    int result_plain[size*size];
    for(int i=0; i < size; i++){
        for(int j=0; j < size; j++)
        result_plain[i][j] = plain[3-j][i];
    }
    for(int i=0; i < size*size; i++) plain[i] = result_plain[i]; // 배열복사
}

bool decision(int* plain, int left_lvl, int testing_sum){
    int valid_num = testing_sum; //이번 단계에 유효하게 취급되는 가용자원
    for(j=0; j < left_lvl; j++) valid_num /= 2;

    int valid_sum = 0;
    for(int i=0; i < n*n; i++){
        if(plain[i] > valid_num) validsum += plain[i];
    }

    if(testing_sum <= valid_sum) return true;
    else return false;
}


void push(int* plain){

}


void progress(int* testing_plain, int left_lvl, int testing_sum, int size){
    int current_plain[size*size];
    for(int i=0; i < n*n; i++) current_plain[i] = testing_plain[i]; // 배열복사
    if(decision(current_plain, left_lvl, testing_sum)){
        for(int j=0; j<4; j++){
            progress(push(current_plain), left_lv - 1, testing_sum)
            rotate(current_plain)
        }
}

int main(void){
    
    int n;
    int superior_sum = 0; //최고합
    int left_lvl = 5;

    cin >> n;

    int* original_plain = new int[n*n];
    for(int i=0; i < n*n; i++) {
        cin >> plain[i];
        superior_sum += plain[i];
    }

    superior_sum = twonear(sum); //최초최고합

    int testing_sum;
    testing_sum = superior_sum;

    int* testing_plain = new int[n*n];
    for(int i=0; i < n*n; i++) testing_plain[i] = original_plain[i]; // 배열복사








    return 0;
}
