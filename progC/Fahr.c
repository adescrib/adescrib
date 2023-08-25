#include<stdio.h>
#include<unistd.h>

int main (){

	float f, c;
	int low, up, step;

	low = 0;
	up = 300;
	step = 10;

	f = low;
	printf("Esta es la tabla de conversiones entre temperaturas\n");
	while (f <= up){
	c = 5 * (f -32)/9;
	printf("%3.0f\t%6.1f\n", f, c);
	f = f + step;
	}
}
