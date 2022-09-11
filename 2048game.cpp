#include <iostream>
#include <vector>
using namespace std;

class node{
    public:
        int* matrix;
        int degree;

        /*node(){
            this.matrix = new int(n*n);
            this.degree = 0;
        }*/
};

void _print(int* matrix, int n){
    for(int i=0; i <n*n; i++){
        if(i%n==0) cout << endl;
        cout << *(matrix+i) << " ";
        
    }
    cout << endl;
}


void _copy(int* orgmatrix, int* matrix, int n){
    for(int i=0; i <n*n; i++){
        *(matrix+i) = *(orgmatrix+i);
    }
}

bool _isValid(int* matrix, int n, int limit, int db_size){
    int sum = 0;
    int valid_limit = limit;
    for(int i=0; i < 5 - db_size; i++) {
        if(valid_limit <= 2) break;
        valid_limit /= 2;
    }
    for(int i=0; i <n*n; i++){
        if(matrix[i] >= valid_limit) sum += matrix[i];
    }
    if(sum >= limit) return true;
    else return false;
}

int _maxof(int* matrix, int n){
    int result = 0;
    for(int i=0; i <n*n; i++){
        if(matrix[i] > result) result = matrix[i];
    }
    return result;
}

void _doProgress(int* matrix, int n){
    vector<int> _stack;
    vector<int> _finalstack;
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            if(*(matrix+(n*i)+j) == 0) continue;
            _stack.push_back(*(matrix+(n*i)+j));
        }
        while(!_stack.empty()){
            if(!_finalstack.empty() && _finalstack.back() == _stack.at(0)){
                _finalstack.back() *= 2;
            }
            else _finalstack.push_back(_stack.at(0));
            _stack.erase(_stack.begin());
        }
        for(int j = 0; j < n; j++){
            if(_finalstack.empty()) {
                *(matrix+(n*i)+j) == 0;
                continue;
            }
            *(matrix+(n*i)+j) = _finalstack.at(0);
            _finalstack.erase(_finalstack.begin());
        }
    }
}

void _turnProgress(int* matrix, int n)
{
    int result_matrix[n*n];
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++)
        *(result_matrix+(n*i)+j) = *(result_matrix+(n*(n-1-j))+i);
    }
    _copy(result_matrix, matrix, n); // 배열복사
}

int main(){
    int n = 0;
    int db_size = 0;
    cin >> n;
    int* curr_matrix = new int[n*n];

    
    for(int i=0; i < n*n; i++) {
        cin >> *(curr_matrix+i);
    }
    node* db = new node[5];
    for(int i=0; i < 5; i++){
        db[i].matrix = new int(n*n);
        db[i].degree = 0;
    }

    _copy(curr_matrix, db[0].matrix, n);
    _print(curr_matrix, n);

    int limit = _maxof(curr_matrix, n) * 2; //극복해야 할 숫자

    bool flag = true;
    int a = 0;

    while(flag){
        _print(curr_matrix, n);
        if(_isValid(curr_matrix, n, limit, db_size)){
            if(db_size >= 3){ //이번에 만지고 있는게 index 4짜리 그러니까 5번째 거
                if(_maxof(curr_matrix, n) >= limit) limit = _maxof(curr_matrix, n);
            }
            else{
                
                _doProgress(curr_matrix, n); // 기능 실행
                _copy(curr_matrix ,db[++db_size].matrix, n); // 기능 한 단계 실행 후 저장
            }
        }
        else{
            if(db[db_size].degree < 3){
                db[db_size].degree++;
                _turnProgress(curr_matrix, n);
            }
            else{
                if(db_size > 0) _copy(curr_matrix, db[--db_size].matrix, n);
                else flag = false;
            }
        }
        a++;
        if(a==100) flag = false;
    }

}
