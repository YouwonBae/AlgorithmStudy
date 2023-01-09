#include<iostream>
#include<cstring>

#define MAX 21

using namespace std;

int N; // 2 <= N <= 20
int M; // 2 <= M <= 20
int K; // 1 <= K <= 1000
int C_cnt;
int point;

int dr[] = { 0, 1, 0, -1 };
int dc[] = { 1, 0, -1, 0 };

int map[MAX][MAX];
int ch[MAX][MAX];
int dice[7]; // 1 2 3 4 5 6

typedef struct {
	int r;
	int c;
	int d;
}rcd;
rcd dice_data;

void Input() {
	cin >> N >> M >> K;

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			cin >> map[r][c];
		}
	}

	for (int i = 1; i <= 6; i++) {
		dice[i] = i;
	}

	dice_data.r = 1;
	dice_data.c = 1;
	dice_data.d = 0;
}

void Output() {
	cout << point;
}

void InitData() {
	memset(ch, 0, sizeof(ch));
}

rcd RotateDice(int A, rcd data) {
	int now_r = data.r;
	int now_c = data.c;
	int dir = data.d;
	int B = map[now_r][now_c];

	if (A > B) {
		dir++;
		if (dir > 3) {
			dir = 0;
		}
	}
	else if (A < B) {
		dir--;
		if (dir < 0) {
			dir = 3;
		}
	}
	else;

	data.d = dir;

	return data;
}

void FindPath(int now_r, int now_c, int num) {
	for (int i = 0; i < 4; i++) {
		int next_r = now_r + dr[i];
		int next_c = now_c + dc[i];

		if (next_r >= 1 && next_r <= N && next_c >= 1 && next_c <= M && map[next_r][next_c] == num && ch[next_r][next_c] == false) {
			ch[next_r][next_c] = true;
			C_cnt++;
			FindPath(next_r, next_c, num);
		}
	}
}

int TakePoint(rcd data) {
	int point = 0;
	int now_r = data.r;
	int now_c = data.c;
	int num = map[now_r][now_c];

	C_cnt = 1;
	ch[now_r][now_c] = true;

	FindPath(now_r, now_c, num);
	point = num * C_cnt;

	return point;
}

void RollDice(int dir) {
	if (dir == 0) { // µ¿
		dice[0] = dice[1];
		dice[1] = dice[4];
		dice[4] = dice[6];
		dice[6] = dice[3];
		dice[3] = dice[0];
		dice[0] = 0;
	}
	else if (dir == 2) { // ¼­
		dice[0] = dice[1];
		dice[1] = dice[3];
		dice[3] = dice[6];
		dice[6] = dice[4];
		dice[4] = dice[0];
		dice[0] = 0;
	}
	else if (dir == 1) { // ³²
		dice[0] = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[6];
		dice[6] = dice[5];
		dice[5] = dice[0];
		dice[0] = 0;
	}
	else { // ºÏ
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[6];
		dice[6] = dice[2];
		dice[2] = dice[0];
		dice[0] = 0;
	}
}

rcd MoveDice(rcd data) {
	int now_r = data.r;
	int now_c = data.c;
	int dir = data.d;

	int next_r = now_r + dr[dir];
	int next_c = now_c + dc[dir];

	if (!(next_r >= 1 && next_r <= N && next_c >= 1 && next_c <= M)) {
		if (dir == 0) {
			dir = 2;
		}
		else if (dir == 1) {
			dir = 3;
		}
		else if (dir == 2) {
			dir = 0;
		}
		else {
			dir = 1;
		}
	}

	RollDice(dir);

	data.r = now_r + dr[dir];
	data.c = now_c + dc[dir];
	data.d = dir;

	return data;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input();

	while (K--) {
		InitData();
		dice_data = MoveDice(dice_data);
		point += TakePoint(dice_data);
		dice_data = RotateDice(dice[6], dice_data);
	}

	Output();

	return 0;
}