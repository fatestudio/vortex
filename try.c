#include <stdio.h>

int main(){
	char buf[512] = "Hello World!";
	int *ptr = buf + (sizeof(buf)/2);
	
	print
	printf("%x\n%x\n", buf, ptr);

	return 0;
}
