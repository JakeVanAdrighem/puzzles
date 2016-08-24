#include <cstdio>

bool isPythagTriplet(int a, int b, int c){
	if(a < b && b < c){
		if((a*a) + (b*b) == (c*c)){
			return true;
		}
		else{
			return false;
		}
	}
	return false;
}


int main(int argc, char** argv){
	for(int x = 0; x < 1001; x++){
		for(int y = 0; y < 1001; y++){
			for(int z = 0; z < 1001; z++){
				if((x+y+z == 1000) && isPythagTriplet(x,y,z)){
					printf("%i\n", (x*y*z));
					return 0;
				}
			}
		}
	}
	return 1;
}
