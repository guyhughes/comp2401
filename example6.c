#include <stdio.h>
#include <stdlib.h>

long factorial(int);
long permutation(int, int);
long combination(int, int);
void drawPascalTriangle(int);

int main() {
	int l;
	printf("Enter the number of rows:\n");
	scanf("%d", &l);
	drawPascalTriangle(l);
	return 0;
}

long factorial(int n) {
	if (n <= 0) { 
		return 1;
	} else {
		return factorial(n-1) * n;
	}
}

long permutation(int k, int n) {
	return factorial(n)/factorial(n-k);
}

long combination(int k, int n) {
	return permutation(k,n)/factorial(k);
}

void printBlankSpace(int l) {
	int i;
	for(i = 0; i < l; i++) {
		printf("   ");
	}
}

void drawPascalTriangle(int n) {
	int l;
	int c;
	for (l = 0; l <= n; l++) {
		printBlankSpace(2*n-l);
		for (c = 0; c <= l; c++) {
			printf("  %ld   ", combination(c, l));
		}
		printf("\n\n");
	}
}
