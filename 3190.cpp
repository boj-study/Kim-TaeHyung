#include<iostream>
#include<deque>
#include<queue>
#define INF 104
using namespace std;

int map[INF][INF];
int snake_visit[INF][INF];
int row, col;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
deque<int> menu;
queue<pair<char, int>> snake_move_list;

int snakeGame() {
	int time = 0;
	deque<pair<int, int>> snake_location;
	snake_location.push_back({ 1,1 });
	snake_visit[1][1] = 1;
	while (true) {
		if(!snake_move_list.empty())
			if (time == snake_move_list.front().second) {
				if (snake_move_list.front().first == 'D') {
					int tmp = menu.front();
					menu.pop_front();
					menu.push_back(tmp);
				}
				else {
					int tmp = menu.back();
					menu.pop_back();
					menu.push_front(tmp);
				}
				snake_move_list.pop();
			}
		time += 1;
		int moveMenu = menu.front();
		int nx = snake_location.front().first + dx[moveMenu];
		int ny = snake_location.front().second + dy[moveMenu];
		if (nx > col || nx <= 0)
			return time;
		else if (ny > row || ny <= 0)
			return time;
		else if (snake_visit[nx][ny] != 0)
			return time;

		if (map[nx][ny] == 1) {
			snake_location.push_front({ nx,ny });
			snake_visit[nx][ny] = 1;
			map[nx][ny] = 0;
		}
		else {
			pair<int, int> tmp = snake_location.back();
			snake_location.pop_back();
			snake_location.push_front({ nx,ny });
			snake_visit[tmp.first][tmp.second] = 0;
			snake_visit[nx][ny] = 1;
		}

	}
	return 0;
}
void setData() {
	for (int i = 0; i < INF; i++) {
		for (int j = 0; j < INF; j++) {
			map[j][i] = 0;
			snake_visit[j][i] = 0;
		}
	}
	menu.push_back(0);
	menu.push_back(1);
	menu.push_back(2);
	menu.push_back(3);
	int N, K, L;
	cin >> N;
	col = N;
	row = N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int tmp_row = 0, tmp_col = 0;
		cin >> tmp_row >> tmp_col;
		map[tmp_col][tmp_row] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		char tmp_list;
		int tmp_time = 0;
		cin >> tmp_time >> tmp_list;
		snake_move_list.push({ tmp_list,tmp_time });
	}
}

int main() {
	setData();
	cout << snakeGame();
	/*
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cout << snake_visit[j][i];
		}
		cout << "\n";
	}
	cout << "----------------------------------\n";
	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cout << map[j][i];
		}
		cout << "\n";
	}
	*/
	return 0;
}