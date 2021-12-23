#include<iostream>
#include<queue>
using namespace std;

queue<pair<int, int>> printer_queue; // first = �߿䵵, second = index
//int max_priority = 0;
priority_queue<int> max_priority;

int printerQueue(int index) {
	int result_cnt = 0;
	while (!printer_queue.empty()) {
		pair<int, int> tmp = printer_queue.front();
		printer_queue.pop();
		if (tmp.first < max_priority.top())
			printer_queue.push(tmp);
		else {
			result_cnt += 1;
			max_priority.pop();
			if (tmp.second == index)
				return result_cnt;
		}
	}
	return 0;
}
int main() {
	int test_case = 0;
	cin >> test_case;
	for (int t = 0; t < test_case; t++) {
		int N, M;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			int tmp;
			cin >> tmp;
			printer_queue.push({ tmp,i });
			max_priority.push(tmp);
		}
		cout << printerQueue(M) << "\n";
		while (!max_priority.empty())
			max_priority.pop();
		while (!printer_queue.empty())
			printer_queue.pop();
	}
	return 0;
}
