#include<iostream>
using namespace std;

int coutandsum(int arr[], int size, int target, int* count) {
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		if (arr[i] == target) {
			(*count)++;
			sum += arr[i];
		}
	}
	return sum;
}


int main() {
	int arr[10] = { 1,2,3,2,3,2,4,5,2,6 };
	int c = 0;
	int sum=coutandsum(arr, 10, 2, &c);
	cout << sum << ' ' << c << endl;
	return 0;
}