#include <cstdio>

const int iters = 1000000;

int main(int argc, char** argv){
	int longest = 0;
	int starter = 0;
	int val;

	for(int i = 2; i <= iters; i++){
		int chain = 0;
		val = i;
		while(val != 1){
			if((val % 2) == 0){
				val = val / 2;
			} else {
				val = val * 3 + 1;
			}
			chain++;
		}
		if( chain > longest ){
			longest = chain;
			starter = i;
		}
	}
	printf("%i\n", starter);
}
