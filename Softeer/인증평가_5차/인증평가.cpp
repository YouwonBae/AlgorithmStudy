#include<iostream>
#include<algorithm>
#include<vector>

#define MAX 100000

using namespace std;

int N; // 3 <= N <= 100000

typedef struct{
	int s;
	int i;
}si;

vector<si> test_1;
vector<si> test_2;
vector<si> test_3;
vector<si> sum;

int result[MAX];

int SortByScore(si a, si b){
	if(a.s == b.s){
		return a.i < b.i;
	}else{
		return a.s > b.s;
	}
}

void TestCheck(vector<si> test){
	int num = 1;
	int same = 0;

	sort(test.begin(), test.end(), SortByScore);
	
	for(int i = 1; i < test.size(); i++){

		//cout << test[i].s << ", " << test[i].i << "\n";

		if(test[i - 1].s > test[i].s){
			if(same){
				result[test[i - 1].i] = num;
				num += same;
			}else{
				result[test[i - 1].i] = num;
			}

			if(i == test.size() - 1){
				result[test[i].i] = num + 1;
			}

			same = 0;
			num++;

		}else{ // 5 4 3 3 3 2 /  1 2 3 3 3 6
			same++;

			result[test[i - 1].i] = num;
			
			if(i == test.size() - 1){
				result[test[i].i] = num;
			}
		}
	}

	
	for(int i = 0; i < N; i++){
		cout << result[i] << " ";
	}
	cout << "\n";
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> N;

	for(int j = 0; j < N; j++){
		int score = 0;
		cin >> score;
		test_1.push_back({score, j});
	}
	for(int j = 0; j < N; j++){
		int score = 0;
		cin >> score;
		test_2.push_back({score, j});
	}
	for(int j = 0; j < N; j++){
		int score = 0;
		cin >> score;
		test_3.push_back({score, j});
	}
	for(int i = 0; i < N; i++){
		sum.push_back({test_1[i].s + test_2[i].s + test_3[i].s, i});
	}

	TestCheck(test_1);
	TestCheck(test_2);
	TestCheck(test_3);
	TestCheck(sum);
	
	return 0;
}