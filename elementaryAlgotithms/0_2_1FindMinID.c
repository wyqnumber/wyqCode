#include <stdio.h>

#define N 1000000
#define WORD_LENGTH sizeof(int) * 8

// set和test应该类似于hash表的作用
void setbit (unsigned int* bits, unsigned int i){
	bits[i / WORD_LENGTH] |= 1 << (i % WORD_LENGTH);
}

int testbit(unsigned int* bits, unsigned int i){
	return bits[i / WORD_LENGTH] & (1 << (i % WORD_LENGTH));
}

unsigned int bits[N / WORD_LENGTH + 1];

int min_free(int * xs, int n){
	int i, len = N / WORD_LENGTH + 1;
	for (i = 0; i < len; ++i)  //表示有几个WORD_LENGTH
		bits[i] = 0;
	for (i = 0; i < n; ++i)
		if (xs[i] < n)
			setbit(bits, xs[i]);
	for (i = 1; i <= n; ++i){
		if(!testbit(bits, i))
			return i;
	}
}

int main(){
	int x[15] = {18, 4, 9, 8, 16, 1, 2, 3, 5, 6, 7, 11, 14, 15, 17};
	// printf("%d\n", sizeof(int));  4
	// Ubuntu官网的原因：NOTE: In Ubuntu 8.10 and later versions this option is enabled by default for C, C++, ObjC, ObjC++. 
	// To disable, use -Wformat=0. 加上 gcc -o 0_2_1FindMinID 0_2_1FindMinID.c -Wformat=0 就可以了.
	int result = min_free(x, 15);
	printf("%d\n", result);
}
