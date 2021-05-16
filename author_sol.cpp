#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long cost = 0;
	int zeroes = 0;
	int negative = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			// count the number of zeroes because we need this to either make
			// it as 1 or -1 to get a total product of 1
			zeroes++;
		} else if (a[i] > 0) {
			// if the number is positive, calculate the distance from 1
			cost += (a[i] - 1);
		} else {
			// if the number is negative, calculate the distance from -1
			cost += (-1 - a[i]);
			// count the negative numbers
			negative++;
		}
	}
	// if the negative numbers is even or there are zeroes present, then
	// add 'zeroes' to cost, otherwise, if there are no zeroes present and
	// the negative numbers are in odd frequency, then it means the final
	// answer that we got is -1, that's why we need to add 2 to make it 1
	cout << cost + (negative % 2 == 0 || zeroes > 0 ? zeroes : 2) << '\n';
	return 0;
}
