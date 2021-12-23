#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;

void menu(string order, deque<int>& arr) {
	int x = 0;
	if (order == "push_front") {
		cin >> x;
		arr.push_front(x);
		return;
	}
	else if (order == "push_back") {
		cin >> x;
		arr.push_back(x);
		return;
	}
	else if (order == "pop_front") {
		if (arr.size() == 0)
			cout << -1 << "\n";
		else {
			cout << arr.front() << "\n";
			arr.pop_front();
		}
		return;
	}
	else if (order == "pop_back") {
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
	else if (order == "front") {
		if (arr.size() == 0)
			cout << -1 << "\n";
		else {
			cout << arr.front() << "\n";
		}
		return;
	}
	else if (order == "back") {
		if (arr.size() == 0)
			cout << -1 << "\n";
		else {
			cout << arr.back() << "\n";
		}
		return;
	}
}


int main() {
	int time = 0;
	string order = "";
	deque<int> a;
	cin >> time;
	for (int i = 0; i < time; i++) {
		cin >> order;
		menu(order, a);
	}

	return 0;
}
