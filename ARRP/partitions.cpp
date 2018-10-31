#include <iostream>
using namespace std;

int array[1000000];

int main(void) {
	ios_base::sync_with_stdio(0);
	int numTestCases;

	cin >> numTestCases;

	for (int i = 0; i < numTestCases; i++) {
		int N;
		long long int total = 0;

		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> array[j];
			total += array[j];
		}

		/* 1 partition is always possible */
		cout << "1";
		for (int K = 2; K <= N; K++) {
			if (total % K) {
				cout << "0";
			} else {
				int idx = 0;
				int m;

				/* K-1 partition ==> K partitions */
				/* No bound check needed */
				for (m = 0; m < K - 1; m++) {
					long long int sum = 0;

					while (sum < total/K) {
						sum += array[idx];
						idx++;
					}

					if (sum != total/K) {
						break;
					}
				}
				if (m == K - 1)
					cout <<"1";
				else
					cout << "0";
			}
		}
		cout << endl;
	}

	return 0;
}
