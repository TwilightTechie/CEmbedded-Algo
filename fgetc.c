#include<stdio.h>

int main() {
	
	//open a file
	FILE *fp = fopen("test.txt", "r");

	//return if could not open the file
	if (fp == NULL) {
		return 0;
	}
	
	do
	{
		//taking input signle character at a time.
		char c = fgetc(fp);

		//checking for end of line.
		if(feof(fp)) {
			break;
		}

		printf("%c", c);
	} while(1);

	fclose(fp);
	return 0;
}
