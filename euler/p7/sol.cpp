#include <cstdio>

bool isPrime(unsigned long value){
	for(unsigned long i = 2; i < value; i++){
		if( value % i == 0){
			return false;
		}
	}
	return true;
}

int main(int argc, char** argv){
	int primecount = 6;
	unsigned long current = 13;
	while(primecount != 10001){
		current++;
		if(!isPrime(current)){
			continue;	
		}
		else{
			primecount++;
		}
	}
	printf("%lu\n", current);
	return 0;
}
