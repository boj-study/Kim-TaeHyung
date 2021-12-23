#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<deque>
using namespace std;

/*
아스키 코드  공백: 32 a: 97 A: 65 0: 48
*/


int main() {
    deque<int> josephus;
    vector<int> result;
    int num = 0;
    int t = 0;
    cin >> num;
    cin >> t;
    for (int i = 1; i <= num; i++)
        josephus.push_back(i);
    int i = 1;
    while (josephus.size() != 0) {
        if (i == t) {
            result.push_back(josephus.front());
            josephus.pop_front();
            i = 1;
        }
        else {
            josephus.push_back(josephus.front());
            josephus.pop_front();
            i++;
        }
    }
    cout << "<";
    for (int i = 0; i < result.size(); i++) {
        if (i == result.size() - 1)
            cout << result[i];
        else
            cout << result[i] << ", ";
    }
    cout << ">";

    return 0;

}
