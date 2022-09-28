#include <iostream>
#include <string>
using namespace std;

char chair[5][8];

int k;

int pc[100];
int pd[100];

void print(){
    for(int i=1; i < 5; i++){
        for(int j=0; j < 8; j++){
            cout << chair[i][j];
        }
        cout << endl;
    }
}

int isConnected(int chnum){
    bool isleft = false;
    int count = 0;
    if(chnum != 4 && chair[chnum][2] != chair[chnum+1][6]){
        count++;
    }
    if(chnum != 1 && chair[chnum-1][2] != chair[chnum][6]){
        count++;
        isleft = true;
    }
    if(isleft) count *= -1;
    return count;
}

void turn(int chnum, int dir){
    char temp;
    if(dir == 1){ //시계방향
        temp = chair[chnum][7];
        for(int i=7; i > 0; i--){
            chair[chnum][i] = chair[chnum][i-1];
        }
        chair[chnum][0] = temp;
    }
    else if(dir == -1){ //반시계방향
        temp = chair[chnum][0];
        for(int i=0; i < 7; i++){
            chair[chnum][i] = chair[chnum][i+1];
        }
        chair[chnum][7] = temp;
    }
    
}

void get_all_will_be_turned(int* will_be_turned, int curr_chair, int curr_dir){
    *(will_be_turned + curr_chair) = curr_dir; //회전예약
    if(isConnected(curr_chair) == -1 && *(will_be_turned + curr_chair - 1) == 0){ //왼쪽하고 연결됨, 아직 회전한 적 없음
        get_all_will_be_turned(will_be_turned, curr_chair - 1, curr_dir * -1);
    }
    else if(isConnected(curr_chair) == 1 && *(will_be_turned + curr_chair + 1) == 0){ //오른쪽하고 연결됨, 아직 회전한 적 없음
        get_all_will_be_turned(will_be_turned, curr_chair + 1, curr_dir * -1);
    }
    else if(isConnected(curr_chair) == -2){ //양쪽하고 연결됨
        if(*(will_be_turned + curr_chair - 1) == 0){ //왼쪽 회전한 적 없음
            get_all_will_be_turned(will_be_turned, curr_chair - 1, curr_dir * -1);
        }
        if(*(will_be_turned + curr_chair + 1) == 0){ //오른쪽 회전한 적 없음
            get_all_will_be_turned(will_be_turned, curr_chair + 1, curr_dir * -1);
        }
    }
    return;
}

int get_result(){
    int result = 0;
    int coef = 1;
    for(int i=1; i<5; i++){
        if(chair[i][0] == '1') result += coef;
        coef *= 2;
    }

    return result;
}

int main(){
    for(int i=1; i < 5; i++){
        scanf("%s", chair[i]);
    }
    cin >> k;
    for(int i=0; i < k; i++){
        int will_be_turned[5] = {0};
        int curr_chair, curr_dir;
        cin >> curr_chair >> curr_dir;
        //cout << isConnected(curr_chair) << " ";

        get_all_will_be_turned(will_be_turned, curr_chair, curr_dir);

        for(int i=1; i<5; i++){
            turn(i, will_be_turned[i]);
        }
        //print();
        //cout << endl;

        
    }

    cout << get_result();
    


}
