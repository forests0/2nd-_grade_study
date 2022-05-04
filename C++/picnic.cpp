#include <iostream>
using namespace std;
int n, m;
bool relation[10][10];

int CountParing(bool taken[]) {
	bool check = true;
	int first = -1;
	for(int i = 0; i < n; i++) {
		if(!taken[i]) {
			check = false;
			first = i;
			break;
		}
	}
		if(check) {
			return 1;
		}
	int count = 0;
		for(int j = first + 1; j < n; j++) {
			if(!taken[j] && relation[first][j]) {
				taken[first] = true;
				taken[j] = true;
				count += CountParing(taken);
				taken[first] = false;
				taken[j] = false;
			}
		}
	return count;
}

int main() {
	bool taken[10];
	cin >> n, m;
	for(int i = 0; i < m; i++) {
		int s1, s2;
		cin>>s1,s2;
		relation[s1][s2] = true;
		relation[s2][s1] = true;
	}
	for(int i = 0; i < 10; i++) {
		taken[i] = false;
	}
	CountParing(taken);
	return 0;
}