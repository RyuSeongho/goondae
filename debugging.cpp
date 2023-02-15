#include <iostream>

using namespace std;

int plain[30][10] = {0};
int n, m, h;
int result = -1;

void printplain(){
    for(int i=0; i < h; i++){
        for(int j=0; j <n; j++) cout << plain[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

bool checkSuccess(){
    for(int i=0; i < n; i++){
        int curr = i;
        for(int j=0; j < h; j++){
           curr += plain[j][curr];
        }
        if(curr != i) return false;
    }
    return true;
}

int getind1(int ind){
    return ind / n;
}
int getind2(int ind){
    return ind % n;
}

bool checkOutBound(int ind){
    if(ind >= n * h) return true;
    return false;
}

bool checkNoLineLeft(int leftline){
    if(leftline <= 0) return true;
    return false;
}

bool checkOutOfSecondArrayBound(int ind2){
    if(ind2 >= n) return true;
    return false;
}

bool checkCannotCreateLine(int ind){
    if(checkOutBound(ind)) return true;
    if(checkOutOfSecondArrayBound(getind2(ind) + 1)) return true;
    if(plain[getind1(ind)][getind2(ind)] !=0) return true;

    ind++;

    if(checkOutBound(ind)) return true;
    if(plain[getind1(ind)][getind2(ind)] !=0) return true;

    return false;
}

void create_line(int ind, int& leftline){
    leftline--;

    plain[getind1(ind)][getind2(ind)] = 1;

    ind++;
    
    plain[getind1(ind)][getind2(ind)] = -1;
}

void delete_line(int ind){
    plain[getind1(ind)][getind2(ind)] = 0;

    ind++;
    
    plain[getind1(ind)][getind2(ind)] = 0;
}

void dfs(int ind, int leftline){
    
    if(checkSuccess() && result < leftline) result = leftline;
    if(checkOutBound(ind)) return;
    if(checkNoLineLeft(leftline)) return;

    dfs(ind+1, leftline);
    if(checkCannotCreateLine(ind)) return;
    create_line(ind, leftline);
    //printplain();
    dfs(ind+2, leftline);
    delete_line(ind);
}

int main() {
    cin >> n >> m >> h;
    for(int i = 0; i < m; i++){
        int t1, t2;
        cin >> t1 >> t2;
        plain[t1-1][t2-1] = 1;
        plain[t1-1][t2-1+1] = -1;
    }

    dfs(0, 3);

    if(result != -1) result = 3- result;
    cout << result;
    return 0;
}
