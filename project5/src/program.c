/*
Do not modify this file.
Make all of your changes to main.c instead.
*/

#include "program.h"

#include <stdio.h>
#include <stdlib.h>

static int compare_bytes( const void *pa, const void *pb )
{
	unsigned char a = *(unsigned char*)pa;
	unsigned char b = *(unsigned char*)pb;

	if(a<b) {
		return -1;
	} else if(a==b) {
		return 0;
	} else {
		return 1;
	}

}

void alpha_program( unsigned char *data, int length )
{
	unsigned long total=0;
	int i,j;

	srand48(38290);

	for(i=0;i<length;i++) {
		data[i] = 0;
	}

	for(j=0;j<100;j++) {
		int start = lrand48()%length;
		int size = 25;
		for(i=0;i<100;i++) {
			data[ (start+lrand48()%size)%length ] = lrand48();
		}
	}

	for(i=0;i<length;i++) {
		total += data[i];
	}

	printf("alpha result is %lu\n",total);
}

void beta_program( unsigned char *data, int length )
{
	unsigned total = 0;
	int i;

	srand48(4856);

	for(i=0;i<length;i++) {
		data[i] = lrand48();
	}

	qsort(data,length,1,compare_bytes);

	for(i=0;i<length;i++) {
		total += data[i];
	}

	printf("beta result is %u\n",total);

}

void gamma_program( unsigned char *data, int length )
{
	unsigned i, j;
	unsigned char *a = data;
	unsigned char *b = &data[length/2];
	unsigned total = 0;

	for(i=0;i<length/2;i++) {
		a[i] = i%256;
		b[i] = i%171;
	}

	for(j=0;j<10;j++) {
		for(i=0;i<length/2;i++) {
			total += a[i]*b[i];
		}
	}

	printf("gamma result is %u\n",total);
}

void delta_program( unsigned char *data, int length )
{
	unsigned i, j;
	unsigned total = 0;

	for(i=0;i<length;i++) {
		data[i] = i%256;
	}

	for(j=0;j<10;j++) {
		for(i=0;i<length;i++) {
			total += data[i];
		}
		for(i=length-1;i>0;i--) {
			total += data[i];
		}
	}

	printf("delta result is %u\n",total);
}
