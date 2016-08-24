#include <cstdio>

int main(int argc, char** argv){
	int sosq = 0;
	int sqos = 0;
	for(int i = 1; i < 101; i++){
		sosq += i*i;
		sqos += i;
	}
	sqos = sqos * sqos;
	printf("%i\n", sqos - sosq);
	return 0;
}
