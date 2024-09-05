#include <cmath>
#include <iostream>

void moreMagic(int *&read, int count, int exp, int *&write) {
	int table[10] = {0};

	for (int c = 0; c < count; c++) {
		const int index = (read[c] / exp) % 10;
		table[index]++;
	}

	for (int c = 1; c < 10; c++) {
		table[c] += table[c - 1];
	}

	for (int c = count - 1; c >= 0; c--) {
		const int index = (read[c] / exp) % 10;
		write[table[index] - 1] = read[c];
		table[index]--;
	}

	int *a = read;
	read = write;
	write = a;
}

void magic(int *a, int count, int *b) {
	if (count < 2) {
		return;
	}
	int find = 0;
	for (int c = 1; c < count; c++) {
		if (a[c] > a[find]) {
			find = c;
		}
	}
	const int target = a[find];
	const int base = log10(target) + 1;

	for (int c = 0, exp = 1; c < base + (base & 1); c++, exp *= 10) {
		moreMagic(a, count, exp, b);
	}
}


int main() {
    int a[200], b[200];
    int n;
    std::cin >> n;
    for (int c = 0; c < n; c++) {
        std::cin >> a[c];
    }
    magic(a, n, b);
    for (int c = 0; c < n; c++) {
        std::cout << a[c] << ' ';
    }

    system("pause");
    return 0;
}