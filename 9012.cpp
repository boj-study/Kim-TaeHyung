#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void checkArr(string arr) {
	int checkNum = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == '(')
			checkNum += 1;
		else if (arr[i] == ')')
			checkNum -= 1;
		if (checkNum < 0) {
			cout << "NO\n";
			return;
		}
	}
	if (checkNum == 0)
		cout << "YES\n";
	else
		cout << "NO\n";
	return;
}


int main() {
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string arr;
		cin >> arr;
		checkArr(arr);
	}
	return 0;
}
