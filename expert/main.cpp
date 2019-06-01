

// main.cpp

#include <stdio.h>

#include <time.h>

#include <ctime>

 

#define T 50

 

extern void run(unsigned int[200]);

 

unsigned int arr1[200];

 

static int seed = 3;

static int pseudo_rand(void) {

	seed = seed * 214013 + 2531011;

	return (seed >> 16) & 0x7FFF;

}

 

void makeArr() {

	unsigned int temp;

	for (int k = 0; k < 200; k++) arr1[k] = 0;

	unsigned int arr2[256] = { 0, };

	for (int k = 0; k < 200; k++) {

		for (;;) {

			temp = pseudo_rand() % 255 + 1;

			if (arr2[temp] == 0) break;

		}

		arr2[temp] = 1;

		arr1[k] = temp;

	}

}

 

unsigned int check(unsigned int arr3[200]) {

	unsigned int ret = 0;

	for (int i = 0; i < 200; i++) {

		for (int j = 0; j < 200; j++) {

			if (arr1[i] == arr3[j]) ret += 1;

		}

	}

	for (int i = 0; i < 200; i++) {

		if (arr1[i] == arr3[i]) ret += 256;

	}

	return ret;

}

 

int main() {

	unsigned int arr4[200];

	unsigned int cost = 0;

	time_t start;

	for (int tc = 0; tc < T; tc++) {

		makeArr();

		start = clock();

		run(arr4);

		cost += (unsigned int)(clock() - start) * 1000 / CLOCKS_PER_SEC;

		for (int j = 0; j < 200; j++) {

			if (arr4[j] != arr1[j]) cost += 10000;

		}

	}

	printf("Ans : %u \n", cost);

	if (cost < 3000) printf("PASS\n");

	else printf("FAIL\n");

}