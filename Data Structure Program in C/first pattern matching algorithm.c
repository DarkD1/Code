#include <stdio.h>
#include <string.h>
int index(char a[], char b[]){
		int i = 0,j = 0,k = 0,counter;
		if(strlen(a) < strlen(b)) return -1;
		for (i = 0; i < strlen(a); ++i)
		{
			if(a[i] == b[j]){
				counter = 0;
				for (j = 0, k = i; j < strlen(b); ++j,++k)	if(a[k] == b[j]) counter++;
				if(counter == strlen(b)) return i;
			}
		}
		return -1;
}

int main(){
	char a[] = "Sazzad";
	char b[] = "zz";
	int res = index(a,b);
	res == -1? printf("No match found!!\n"): printf("Match found in %d index\n", res);
	return 0;
}
