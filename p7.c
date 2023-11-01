#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[10];
int i, error;
void E();
void T();
void Eprime();
void Tprime();
void F();

main()
{
	printf("\nRecursivedescentparsingfor thefollowinggrammar\n");
	printf("\nE -> E+T |T\nT -> T*F |F\nF -> (E) |id\n");
	i = 0;
	error = 0;
	printf("\nEnteranarithmeticexpression : "); // Eg:a+a*a gets(input); E();
	if (strlen(input) == i && error == 0)
		printf("\nParsing Successful..!!!\n");
	else
		printf("\nError..!!!\n");
}

void E()
{
	T();
	Eprime();
}
void Eprime()
{
	if (input[i] == '+')
	{
		i++;
		T();
		Eprime();
	}
}
void T()
{
	F();
	Tprime();
}
void Tprime()
{
	if (input[i] == '*')
	{
		i++;
		F();
		Tprime();
	}
}
void F()
{
	if (isalnum(input[i]))
		i++;
	else if (input[i] == '(')

	{
		i++;
		E();
		if (input[i] == ')')
			i++;

		else
			error = 1;
	}

	else
		error = 1;
}
