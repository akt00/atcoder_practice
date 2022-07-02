// calculate mod on positive and negative integers
int mod(int arg, int n) {
	if (arg < 0) {
		while (arg < 0) arg += n;
		return arg;
	}
	else return arg % n;
}


