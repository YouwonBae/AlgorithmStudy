#include<iostream>
#include<cmath>
#include<queue>
#include<vector>

#define M_MAX 2047

using namespace std;

int H, K, R;
int monkey_cnt;
int tail_start;
int tail_end;
int result;

int tree[M_MAX];
typedef struct{
	int n;
	int h;
}nh;
queue<nh> Q;
queue<int> work[M_MAX][2];

void Input(){
	cin >> H >> K >> R;

	for(int i = 0; i <= H; i++){
		monkey_cnt += pow(2, i);
	}

	tail_start = monkey_cnt - pow(2, H);
	tail_end = monkey_cnt - 1;

	for(int i = tail_start; i <= tail_end; i++){
		for(int j = 0; j < K; j++){
			int w;
			cin >> w;
			work[i][0].push(w);
		}
	}
}

void SetTree(){
	Q.push({0, 0});
	int i = 0;

	while(!Q.empty()){
		int now_n = Q.front().n;
		int now_h = Q.front().h;
		Q.pop();

		if(now_h < H){
			i++;
			tree[i] = now_n;
			Q.push({i, now_h + 1});

			i++;
			tree[i] = now_n;
			Q.push({i, now_h + 1});
		}
	}
}

void SendWork(){
	int day = 0;
	
	while(R--){
		day++;

		int lr = 0;
		if(day % 2 == 1){ // È¦¼ö
			lr = 0;
		}else{            // Â¦¼ö
			lr = 1;
		}

		for(int i = 0; i < monkey_cnt; i++){
			if(i >= 0 && i < tail_start){
				if(!work[i][lr].empty()){
					int senior = tree[i];
					int junior_w = work[i][lr].front();
					work[i][lr].pop();

					if(i == 0){
						result += junior_w;
					}else{
						if(i%2 == 1){ // ¿ÞÂÊ
							work[senior][0].push(junior_w);
						}else{        // ¿À¸¥ÂÊ
							work[senior][1].push(junior_w);
						}
					}
				}
			}else{
				if(!work[i][0].empty()){
					int senior = tree[i];
					int junior_w = work[i][0].front();
					work[i][0].pop();

					if(i%2 == 1){ // ¿ÞÂÊ
						work[senior][0].push(junior_w);
					}else{         // ¿À¸¥ÂÊ
						work[senior][1].push(junior_w);
					}
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Input();
	SetTree();
	SendWork();

	cout << result;

	return 0;
}