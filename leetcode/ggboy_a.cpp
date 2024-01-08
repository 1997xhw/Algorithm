//
// Created by 徐浩闻 on 2023/12/27.
//
#include "bits/stdc++.h"

using namespace std;

int calculate_min_energy(int N, int K, vector<int>& A) {
    int pairs = N * (N - 1) / 2;

    int total_energy = pairs * 2;

    int lost_energy = 0;
    for (int i : A) {
        lost_energy += i * (N - i) * 2;
    }

    int result = total_energy - lost_energy;

    return result;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> A(K);
    for (int i = 0; i < K; ++i) {
        cin >> A[i];
    }
    cout << calculate_min_energy(N, K, A) << endl;

    return 0;
}
