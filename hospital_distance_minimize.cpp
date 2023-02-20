#include <iostream>
#include <vector>
using namespace std;

int n, m;

vector<pair<int,int>> patients;
vector<pair<int,int>> hospitals;
vector<int> selected_hospital_index;

int gmin = 100 * 100;

int getNearestHospitalDistance(int patient_idx){
    pair<int,int> patient_loc = patients[patient_idx];
    int fmin = 100;
    for(int i=0; i < selected_hospital_index.size(); i++){
        int selected_idx = selected_hospital_index[i];
        pair<int,int> hospital_loc = hospitals[selected_idx];
        int distance_first = abs(hospital_loc.first - patient_loc.first);
        int distance_second = abs(hospital_loc.second - patient_loc.second);
        int distance = distance_first + distance_second;
        if(distance < fmin) fmin = distance;
    }
    return fmin;
}

void distanceCalculation(){
    int fsum = 0;
    for(int i=0; i < patients.size(); i++){
        fsum += getNearestHospitalDistance(i);
    }
    if(fsum < gmin) gmin = fsum;
}

void hospitalDistributionDfs(int idx, int left, int limit){
    if(left <= 0) {
        distanceCalculation();
        return;
    }
    if(idx >= limit) return;


    hospitalDistributionDfs(idx + 1, left, limit);
    selected_hospital_index.push_back(idx);
    hospitalDistributionDfs(0, left - 1, idx);
    selected_hospital_index.pop_back();
}

int main() {

    cin >> n >> m;

    for(int i=0; i< n; i++){
        for(int j=0; j<n; j++){
            int input;
            cin >> input;
            switch(input){
                case 1:
                    patients.push_back(make_pair(i,j));
                    break;
                case 2:
                    hospitals.push_back(make_pair(i,j));
                    break;
                default:
                    break;

            }
        }
    }
    
    hospitalDistributionDfs(0, m, hospitals.size());
    cout << gmin;
    
    return 0;
}
