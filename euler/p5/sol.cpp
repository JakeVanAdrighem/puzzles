#include <cstdio>

int main(int argc, char** argv){
	int value = 0;
	bool cont = true;
	while(cont){
		cont = false;
		value++;
		for( int i = 20; i > 0; i--){
			if( value % i != 0 ){
				cont = true;
				break;
			}
		}
	}
	printf("%i\n", value);
	return 0;
}
