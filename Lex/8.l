
%{
%}
%%
^[+]?[0-9]+$ {
	printf("%s is positive integer.\n", yytext);
}

^[-][0-9]+$ {
	printf("%s is negative integer.\n", yytext);
}

^[+]?[0-9]*[.][0-9]+$ {
	printf("%s is positive float.\n", yytext);
}

^[-][0-9]*[.][0-9]+$ {
	printf("%s is negative float.\n", yytext);
}
. ;
%%
int yywrap(void){};
int main(){
	yylex();
	return 0;
}