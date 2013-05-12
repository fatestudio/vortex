#include <stdio.h>

int main(int argc, char *argv[]){
	printf("Hello, world!\n");

	printf("%d\n", argc);
	if(argc > 0){
		printf("%s\n", argv[0]);
	}	

	return 0;
}
