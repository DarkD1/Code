%{
/* Write a simple lex specification to recognize keyword*/
%}

%%
(auto|int|float|double|main|char) {
	printf("%s is a keyword!", yytext);
}
.$ {
	printf("%s is not a keyword! :/", yytext);
}
%%
int yywrap(void){};
int main(){
	yylex();
	return 0;
}