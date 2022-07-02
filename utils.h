// calculate mod on positive and negative integers
int mod(int arg, int n) {
	if (arg < 0) {
		while (arg < 0) arg += n;
		return arg;
	}
	else return arg % n;
}

// parser: 1111 -> {1, 1, 1, 1}
void ParseConsecutiveInt(vector<int>& row, int input) {

	int count = 1;
	while (true) {
		int val = input % 10;
		row[row.size() - count] = val;
		input /= 10;
		count++;
		if (input <= 0) return;
	}
}


// move matrix cell by 1 in one of 8 directions, overflow-proof
pair<int, int> NextIndex(int dir, int n, const pair<int, int>& p) {

	// cout << p.first << " " << p.second << endl;
	// dir 0 = right;
	auto copy = p;
	if (dir == 0) {
		copy.second += 1;
		if (copy.second == n) copy.second = 0;
	}
	if (dir == 1) {
		copy.first += 1;
		if (copy.first == n) copy.first = 0;
		copy.second += 1;
		if (copy.second == n) copy.second = 0;
	}
	if (dir == 2) {
		copy.first += 1;
		if (copy.first == n) copy.first = 0;
	}
	if (dir == 3) {
		copy.first -= 1;
		if (copy.first < 0) copy.first = n-1;
		copy.second += 1;
		if (copy.second == n) copy.second = 0;
	}
	if (dir == 4) {
		copy.second -= 1;
		if (copy.second < 0) copy.second = n - 1;
	}
	if (dir == 5) {
		copy.first -= 1;
		if (copy.first < 0) copy.first = n-1;
		copy.second -= 1;
		if (copy.second < 0) copy.second = n - 1;
	}
	if (dir == 6) {
		copy.first -= 1;
		if (copy.first < 0) copy.first = n - 1;
	}
	if (dir == 7) {
		copy.first -= 1;
		if (copy.first < 0) copy.first = n-1;
		copy.second += 1;
		if (copy.second == n) copy.second = 0;
	}

	// cout << copy.first << " " << copy.second << endl;
	return copy;
}
