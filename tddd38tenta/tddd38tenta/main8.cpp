#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
	int N, T;
	cin >> N >> T;
	vector<int> input_values (N);
	copy_n(istream_iterator<int>{cin}, N, begin(input_values));

	vector<int> sums(N);

	partial_sum(begin(input_values), end(input_values), begin(sums));  // 5
	for_each(istream_iterator<int>{cin}, istream_iterator<int>{},
		[=](int t) {cout << sums[t - 1] << endl; });

	return 0;
}

