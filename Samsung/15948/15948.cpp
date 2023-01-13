/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<cstring>
#include<string>

#define MAX 21

using namespace std;

int R; // 1 <= R <= 20
int C; // 1 <= C <= 20

int purchase;
int p_max;

int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };

int souvenir[MAX][MAX];
bool spot_ch[MAX][MAX];
bool souv_ch[26];

void InitData() {
	p_max = 0;
}

void Input() {

	cin >> R >> C;

	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			char s;
			cin >> s;

			souvenir[r][c] = s - 65;
		}
	}
}

void MoveSpot(int now_r, int now_c) {
	int souv_num = souvenir[now_r][now_c];

	if (now_r >= 1 && now_r <= R && now_c >= 1 && now_c <= C && spot_ch[now_r][now_c] == false && souv_ch[souv_num] == false) {
		purchase++;
		spot_ch[now_r][now_c] = true;
		souv_ch[souv_num] = true;

		for (int i = 0; i < 4; i++) {
			int next_r = now_r + dr[i];
			int next_c = now_c + dc[i];

			MoveSpot(next_r, next_c);
		}

		purchase--;
		spot_ch[now_r][now_c] = false;
		souv_ch[souv_num] = false;
	}
	else {
		p_max = max(p_max, purchase);
		return;
	}
}

void Output(int c, int p) {
	cout << "#" << c << " " << p << "\n";
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int test_case;
	int T;
	/*
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;

	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		InitData();
		Input();
		MoveSpot(1, 1);
		Output(test_case, p_max);
		/////////////////////////////////////////////////////////////////////////////////////////////


	}

	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}