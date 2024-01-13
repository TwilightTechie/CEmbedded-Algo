#include<stdio.h> 

int main() {
	int i = 0; 
	FILE *fp = fopen("Output.txt", "w");

	//return if could not open the file
	if (fp == NULL) 
		return 0;

	char string[] = "Good Morning\n", received_string[25];

	for (i = 0; string[i] != '\0'; i +=1) {

		//Input string into a file
		//single character at a time
		fputc(string[i], fp);
	}
	fclose(fp);
	fp = fopen("Output.txt", "r");

	//Reading the string from file
	fgets(received_string, 20, fp);

	printf("%s", received_string);

	fclose(fp);
	return 0;
}
