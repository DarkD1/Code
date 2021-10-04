
%{
%}
%%
[+*/=<>%-] {
	printf("%s is an operator.\n", yytext);
}
. ;
%%
int yywrap(void){};
int main(){
	yylex();
	return 0;
}