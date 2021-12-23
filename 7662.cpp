#include<iostream>
#include<time.h>
#include<ctime>
#include<queue>
#define INF 1000004

using namespace std;
bool id[INF];
priority_queue<pair<long long,int>> quMin;
priority_queue<pair<long long,int>> quMax;

void double_priority_queue() {
	int nowId = 1;
	int count = 0;
	cin >> count;
	for (int i = 0; i < count; i++) {
		char menu;
		cin >> menu;
		switch (menu) {
		case 'I': {
			long long iNum;
			cin >> iNum;
			quMin.push({ -iNum,nowId });
			quMax.push({ iNum,nowId });
			id[nowId] = false;
			nowId += 1;
			break;
		}
		case 'D': {
			int dMenu;
			cin >> dMenu;
			if (dMenu == 1&&!quMax.empty()) {
				id[quMax.top().second] = true;
				quMax.pop();
			}
			else if(dMenu==-1&&!quMin.empty()) {
				id[quMin.top().second] = true;
				quMin.pop();
			}
			while (!quMax.empty()) {
				if (id[quMax.top().second] == false)
					break;
				quMax.pop();
			}
			while (!quMin.empty()) {
				if (id[quMin.top().second] == false)
					break;
				quMin.pop();
			}
			break;
		}
		default: {
		}
		}
	}
	if (quMin.empty() && quMax.empty()) {
		cout << "EMPTY\n";
	}
	else{
		cout << quMax.top().first << " " << -quMin.top().first << "\n";
	}
}

int main() {
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		for (int i = 0; i < INF; i++)
			id[i] = true;
		while (!quMin.empty())
			quMin.pop();
		while (!quMax.empty())
			quMax.pop();
		double_priority_queue();
	}
	/*
	int startTime = clock();
	for (int i = 0; i < 1000000; i++) {
		int num = rand() % 32000;
		quMin.push({ -num,num });
		quMax.push({ num,num });
	}
	int endTime = clock();
	cout << "total time : " << endTime - startTime << "\n";
	*/
	return 0;
}