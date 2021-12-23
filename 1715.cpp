#include<iostream>
#include<queue>
using std::cout;
using std::cin;
using std::priority_queue;

int cardShupple(int n) {
	priority_queue<int> card;
	int result = 0;
	int tmp_num;
	for (int i = 0; i < n; i++) {
		cin >> tmp_num;
		card.push(-tmp_num);
	}
	while (card.size() >= 2) {
		int first = 0, second = 0;
		first = -card.top();
		card.pop();
		second = -card.top();
		card.pop();
		result += (first + second);
		card.push(-(first + second));
	}
	return result;
	return 0;
}


int main() {
	int n = 0;
	cin >> n;
	cout << cardShupple(n);
	return 0;
}