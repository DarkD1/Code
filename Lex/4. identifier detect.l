%{
/* Write a simple lex specification to recognize keyword*/
%}

%%
^[a-zA-Z_][a-zA-Z0-9_]* {
	printf("%s is a identifier!", yytext);
}
.$ {
	printf("%s is not a indentifier! :/", yytext);
}
%%
int yywrap(void){};
int main(){
	yylex();
	return 0;
}