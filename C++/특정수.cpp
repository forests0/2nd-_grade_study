#include <iostream>
using namespace std;

int arr[1000000];
int N, x;

int first(int start, int end) {
	if(start > end) return -1;
	int mid = (start + end) / 2;
	if(arr[mid]==x && (mid==0 || arr[mid-1]<x))
		return mid;
	else if(arr[mid]>=x)
		return first(start, mid-1);
	else
		return first(mid+1, end);
}

int last(int start, int end) {
	if(start > end) return -1;
	int mid = (start + end) / 2;
	if(arr[mid]==x && (mid==end || arr[mid+1]>x))
		return mid;
	else if(arr[mid] <= x)
		return last(mid+1, end);
	else
		return last(start, mid-1);
}

int main() {
	cin >> N >> x;
	for(int i = 0 ; i < N ; i++)
		cin >> arr[i];
	
	int start_index = first(0, N-1);
	if(start_index == -1)
		cout << -1 << endl;
	else {
		int end_index = last(0, N-1);
		cout << end_index - start_index + 1 << endl;
	}
	return 0;
}