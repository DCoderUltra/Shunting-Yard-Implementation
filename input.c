#include<stdio.h>
#include<stdlib.h>

char *input(FILE *fp, size_t size)
{
	char *str;
	char ch;
	size_t len = 0;
	str = malloc(sizeof(*str)*size);
	while((ch=fgetc(fp))!=EOF && ch!='\n')
	{
		str[len++]=ch;
		str = realloc(str, sizeof(*str)+sizeof(char)*16);
	}
	str[len++]='\0';
	str = realloc(str, sizeof(*str)+sizeof(char));
	return str;

}
/* To put on the main.c file
int main()
{
	char *s;
	printf("Introduza uma string de qualquer tamanho: ");
	s = input(stdin, 1); //
	puts(s);
}
*/

