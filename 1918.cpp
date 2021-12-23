#include<iostream>
#include<queue>
#include<stack>
using std::cin;
using std::cout;
using std::stack;
using std::string;
using std::pair;
using std::queue;

int prefixOperation() {
	string sen;
	cin >> sen;
	stack<pair<int,char>> sentence;
	stack<pair<int,char>> operators;
	queue<char> result;
	for (int i = sen.size()-1; i >= 0; i--) {
		char tmp = sen[i];
		switch (tmp) {
		case '(':
			sentence.push({ 100,tmp });
			break;
		case ')':
			sentence.push({ 0,tmp });
			break;
		case '*':
			sentence.push({ 2,tmp });
			break;
		case '/':
			sentence.push({ 2,tmp });
			break;
		case '+':
			sentence.push({ 1,tmp });
			break;
		case '-':
			sentence.push({ 1,tmp });
			break;
		default:
			sentence.push({ -1,tmp });
		}
	}
	while (!sentence.empty()) {
		pair<int, char> tmp = sentence.top();
		sentence.pop();
		if (tmp.first == -1) {
			result.push(tmp.second);
			continue;
		}
		if (operators.empty()) {
			if (tmp.second == '(')
				operators.push({ 0,'(' });
			else
				operators.push(tmp);
			continue;
		}
		if (tmp.second == ')') {
			while (operators.top().second != '(') {
				result.push(operators.top().second);
				operators.pop();
			}
			operators.pop();
			continue;
		}
		while (operators.top().first >= tmp.first) {
			result.push(operators.top().second);
			operators.pop();
			if (operators.empty())
				break;
		}
		if (tmp.second == '(')
			operators.push({ 0,'(' });
		else
			operators.push(tmp);
	}
	
	while (!operators.empty()) {
		result.push(operators.top().second);
		operators.pop();
	}
	while (!result.empty()) {
		cout << result.front();
		result.pop();
	}
	cout << "\n";
	return 0;
}


int main() {
	prefixOperation();
	return 0;
}