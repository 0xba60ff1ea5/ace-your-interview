#include <stdio.h>
#include <stdlib.h>

// Compile with : gcc -o swap swap.c
// Run with     : ./swap

// Interesting swap function I learned at work
// How to swap 2 integer values without the need for a 3rd 'placeholder' value
// Also demonstrates basic use of pointers in C

// This is how NOT to perform a swap
// Local changes do not persist after function returns
// A copy of the values were passed into the function, not the 'real' values
void BadSwap(int input1, int input2) {
	input1 = input1 + input2;
	input2 = input1 - input2;
	input1 = input1 - input2;
}

// This is how you should perform a swap
// You need to pass the addresses
// The equivalent of passing in the 'real' values instead of the copy
// These work the same :
// void Swap(int * input1, int * input2)
// void Swap(int *input1, int *input2)
// void Swap(int* input1, int* input2)
void Swap(int* input1, int* input2) {
	*input1 = *input1 + *input2;
	*input2 = *input1 - *input2;
	*input1 = *input1 - *input2;
}

// You can swap characters too
// Need to use their ASCII values
// Cast the characters as an integer
// Character int value = ASCII value
// https://www.asciitable.com/
// Refer to the DEC value column on this ^ website
void CharSwap(char* input1, char* input2) {
	// If you were interested in seeing the ASCII values of the chars, then uncomment the following section below by removing the /* and the */
	/*
	printf("In CharSwap(), ASCII values : \n");
	printf("*input1 = %d\n", (int)*input1);
	printf("*input2 = %d\n", (int)*input2);
	printf("\n");
	*/
	*input1 = (int)*input1 + (int)*input2;
	*input2 = (int)*input1 - (int)*input2;
	*input1 = (int)*input1 - (int)*input2;
}

// You could utilize these parameters in main to bypass the calls to scanf()
// int main(int argc, char * argv[])
// But we'll just go with this implementation instead
int main(void) {
	// Your input values
	int in1, in2;
	char c1, c2;

	// Documentation for scanf()
	// https://man7.org/linux/man-pages/man3/scanf.3.html

	// Receive and store input
	printf("Enter the integer values you want to swap : \n");
	scanf("%d", &in1);
	scanf("%d", &in2);
	// fgets(in1, 2, stdin);
	// fgets(in2, 2, stdin);
	printf("\n");

	// Confirm input
	printf("The values you entered : \n");
	printf("in1 = %d\n", in1);
	printf("in2 = %d\n", in2);
	printf("\n");

	// Call BadSwap()
	BadSwap(in1, in2);
	printf("BadSwap() called, adjusted values : \n");
	printf("in1 = %d\n", in1);
	printf("in2 = %d\n", in2);
	printf("\n");

	// Call Swap()
	Swap(&in1, &in2);
	printf("Swap() called, adjusted values : \n");
	printf("in1 = %d\n", in1);
	printf("in2 = %d\n", in2);
	printf("\n");

	// Study these.....
	// https://stackoverflow.com/questions/7898215/how-to-clear-input-buffer-in-c
	// https://www.programiz.com/c-programming/examples/ASCII-value-character
	// https://www.youtube.com/watch?v=z-6_Nt7RK68

	// Receive and store input
	printf("Enter 2 characters you want to swap (No space) : \n");
	scanf("%c", &c1); // Need to call this twice in order to account for carriage return from previous input
	scanf("%c", &c1);
	scanf("%c", &c2);
	// fgets(&c1, 2, stdin);
	// fgets(&c2, 2, stdin);
	printf("\n");

	// Confirm input
	printf("The values you entered : \n");
	printf("c1 = %c\n", c1);
	printf("c2 = %c\n", c2);
	printf("\n");

	// Call CharSwap()
	CharSwap(&c1, &c2);
	printf("CharSwap() called, adjusted values : \n");
	printf("c1 = %c\n", c1);
	printf("c2 = %c\n", c2);
	printf("\n");

	// Return
	return 0;
}
