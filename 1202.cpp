#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

struct Jewel {
	int w = 0;
	int p = 0;
//	Jewel(int W,int P) :w(W), p(P){}
	bool operator<(const Jewel a)const{
		return this->w<a.w;
	}
};

priority_queue<pair<int,Jewel>> left_jewel; //가격 순으로 정렬
vector<int> bag;
vector<Jewel> jewel; //무게 순으로 정렬


long long int jewelTheif() {
	long long int result = 0;
	//입력
	int cnt_jewel = 0;
	int cnt_bag = 0;
	while (cnt_bag < bag.size()) {
		int weight = bag[cnt_bag];
		if (!(cnt_jewel >= jewel.size())) {
			while (jewel[cnt_jewel].w <= weight) {
				left_jewel.push({ jewel[cnt_jewel].p,jewel[cnt_jewel] });
				cnt_jewel += 1;
				if (cnt_jewel >= jewel.size())
					break;
			}
		}
		cnt_bag += 1;
		if (left_jewel.empty())
			continue;
		result += left_jewel.top().first;
		left_jewel.pop();
	}
	return result;
}

int main() {
	
	int N, K;
	cin >> N >> K;
	int M, V;
	for (int i = 0; i < N; i++) {
		Jewel tmp;
		cin >> M >> V;
		tmp.w = M;
		tmp.p = V;
		jewel.push_back(tmp);
	}
	
	int C;
	for (int i = 0; i < K; i++) {
		cin >> C;
		bag.push_back(C);
	}
	/*
	N = 300000;
	K = 300000;
	for (int i = 0; i < N; i++) {
		Jewel tmp;
		tmp.w = 100000;
		tmp.p = 100000;
		jewel.push_back(tmp);
	}
	for (int i = 0; i < K; i++) {
		bag.push_back(1000000);
	}
	*/
	sort(jewel.begin(), jewel.end());
	sort(bag.begin(), bag.end());
	cout << jewelTheif();
	return 0;
}