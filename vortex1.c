#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>


#define e(); if(((unsigned int)ptr & 0xff000000)==0xca000000) { setresuid(geteuid(), geteuid(), geteuid()); execlp("/bin/sh", "sh", "-i", NULL); }

void print(unsigned char *buf, int len)
{
        int i;

        printf("[ ");
        for(i=0; i < len; i++) printf("%x ", buf[i]); 
        printf(" ]\n");
}

int main()
{
        unsigned char buf[512];
        unsigned char *ptr = buf + (sizeof(buf)/2);
        unsigned int x;

	execlp("/bin/sh", "sh", "-i", NULL);

        while((x = getchar()) != EOF) {
                switch(x) {
                        case '\n': print(buf, sizeof(buf)); //printf("%x\n", ((unsigned int)ptr & 0xff000000)); 
					//printf("%x\n%x\n%x\n", &ptr, ptr, *ptr);
					continue; break;
                        case '\\': ptr--; //printf("%x\n%u\n", ptr, *ptr);
					break; 
                        default: e(); if(ptr > buf + sizeof(buf)) continue; ptr++[0] = x; //printf("%x\n%u\n", ptr, *ptr);
					break;
                }
        }
        printf("All done\n");
}
