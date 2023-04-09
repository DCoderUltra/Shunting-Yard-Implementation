#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>
#define SEP ' '

// Removes all white spaces
void remove_spaces(char *s){
	char tmp[strlen(s)];
	int i,j;
	for(i=0, j=0; s[i]!='\0'; i++){
		if(s[i]!=' ') tmp[j++]=s[i];
	}
	tmp[j]='\0'; strcpy(s,tmp);
}

int verify(char *s){
	int par = 0;
	// Matching Parentheses Check
	for(int i=0; s[i]!='\0'; i++){
		if(s[i]=='(') par++;
		if(s[i]==')') par--;
	}
	if(par!=0){
		fprintf(stderr, "Unmatched Parentheses\n");
		return -1;
	}
	// Operators Bad use
	for(int i=1; s[i]!='\0'; i++){
		if(isdigit(s[i-1]) || isdigit(s[i]) || isalpha(s[i-1]) || isalpha(s[i]));
		else if( s[i-1]=='(' || s[i]=='(' || s[i-1]==')' || s[i]==')' );
		else{
			fprintf(stderr, "Bad usage of operators\n");
			return -1;
		}
	}
	return 0;
}

// Writtes string in propper notation
void regular(char *s){
	char *opers= "+-*/^()";
	char *tmp = (char *) malloc(sizeof(char)*strlen(s)*5); // *5 just for memory safety
	int tmp_size = strlen(s)*5, i=0, j=0, b=0;
	memset(tmp,'\0',tmp_size);

	// If founds a simple operator adds a separator
	if(strchr(opers, s[0])!=NULL){
		if(s[0]=='-'){
			tmp[j++]='0';
			tmp[j++]=SEP;
		}
		tmp[j++]=s[0];
		tmp[j++]=SEP;
		i++;
	}
	while(s[i]!='\0'){
		if(strchr(opers, s[i])!=NULL){
			if(s[i]=='-' & s[i-1]=='('){ // Subs (-x for (0-x)
				tmp[j++]=SEP;
				tmp[j++]='0';
				tmp[j++]=SEP;
			}
			tmp[j++]=SEP;
			tmp[j++]=s[i];
			tmp[j++]=SEP;
		}
		else tmp[j++]=s[i];
		i++;
	}
	tmp[j]='\0'; strcpy(s,tmp); memset(tmp,'\0',strlen(tmp));

	// Erases multiples separators
	for(int i=0, j=0; s[i]!='\0'; i++){
		if(s[0]==SEP) continue;
		if(s[i]=='\n') continue;
		if(s[i]==SEP && s[i+1]==SEP) continue;
		tmp[j++]=s[i];
	}
	while((tmp[0]==SEP)) tmp++;
	tmp_size=strlen(tmp);
	if(tmp[tmp_size-1]==SEP) tmp[tmp_size-1]='\0';
	strcpy(s, tmp); free(tmp);
}

// Counts separators i.e. number of tokens
int count_toks(char *s){
	int n_toks=0;
	for(int i=0; s[i]!='\0'; i++)
		if(s[i]==SEP)
			n_toks++;
	return n_toks+1;
}

