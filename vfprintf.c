#include<stdio.h>

int main () {
	FILE *out = fopen("vfprintf.txt", "w");

	const char *format = "Name: %s, Age: %d\n";
	const char *name = "Anup Sharma";
	int age = 23; 

	vfprintf(out, format, args);
	
}
