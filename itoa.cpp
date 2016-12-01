/*Define itoa function conversion of int to string
*/

#include "itoa.h"

char* itoa(int i, char* str) {
	char* decplace = str;
	int numlen = log10(i)+1;

	while(decplace-str < numlen) {
		*decplace = (i/(int)pow(10,(int)log10(i))) + ZEROCHAR;
		i = (int)(i%(int)(pow(10,(int)log10(i))));
		decplace++;
	}

	*decplace = '\0';

	return str;
}