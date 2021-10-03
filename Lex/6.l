
%{
%}
%%
^[+-]?[0-9]+$ {
	printf("%s is an integer.\n", yytext);
}
. ;
%%
int yywrap(void){};
int main(){
	yylex();
	return 0;
}