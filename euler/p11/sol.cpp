#include <cstdio>

int countDivisors(unsigned int triangular, unsigned int previousTriangular, int maxDivs){
	//Just autoinclude 1 and number
	unsigned int divCount = maxDivs;
	for(unsigned int i = previousTriangular; i < triangular; i++){
		if(triangular % i == 0) divCount++;
	}
	return divCount;
}

int main(int argc, char** argv){
	unsigned int triangular = 28;
	unsigned int currentNum = 7;
	unsigned int previousTriangular = 21;
	int maxDivs = 6;
	while(maxDivs <= 500){
		previousTriangular = triangular;
		currentNum++;
		triangular += currentNum; 
		maxDivs = countDivisors(triangular, previousTriangular, maxDivs);
	}
	printf("%i\n", triangular);
	return 0;
}
