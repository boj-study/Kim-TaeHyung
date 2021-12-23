#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void menu(string order, vector<int>& arr) {
	int num = 0;
	if (order == "push") {
		cin >> num;
		arr.push_back(num);
		return;
	}
	else if (order == "pop") {
		if (arr.size() == 0)
			cout << -1 << "\n";
		else {
			cout << arr.back() << "\n";
			arr.pop_back();
		}
		return;
	}
	else if (order == "size") {
		cout << arr.size() << "\n";
		return;
	}
	else if (order == "empty") {
		if (arr.size() == 0)
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
		return;
	}
	else if (order == "top") {
		if (arr.size() == 0)
			cout << -1 << "\n";
		else
			cout << arr.back() << "\n";
		return;
	}

}

int main() {
	int time = 0;
	vector<int> arr;
	string order;
	cin >> time;
	for (int i = 0; i < time; i++) {
		cin >> order;
		menu(order, arr);
	}
	return 0;
}
