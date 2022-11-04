/*
	17. Write a program to perform file operations.
*/

#include <stdio.h>

void open(char path[20], char mode) {
	FILE * fp = fopen(path, mode);
}

void read(char path[20]) {
	FILE * fp = fopen(path, "r");
	char ch;
	while((ch = getc(fp)) != EOF) {
		printf("%c", ch);
	}
	fclose(fp);
}

void write(char path[20], char string[]) {
	FILE * fp = fopen(path, "w");
	fprintf(fp, "%s", string);
	fclose(fp);
}

int main() {
	int input;
	char path[20], string[256];
	char mode;
	printf("Enter the name of the file: ");
	scanf("%s", path);
	while(1) {
		printf("\n");
		printf("Enter 1 to Open\nEnter 2 to Read\nEnter 3 to Write: ");
		scanf("%d", &input);
		switch(input) {
			case 1:
				printf("Enter the mode: ");
				scanf("%c", &mode);
				open(path, mode);
				break;
			case 2:
				read(path);
				break;
			case 3:
				printf("Enter Some Text: ");
				scanf("%s", string);
				write(path, string);
				break;
			default:
				printf("Wrong Input!");
				break;
		}
	}
	return 0;
}