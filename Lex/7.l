
%{
%}
%%
^[+-]?[0-9]*[.][0-9]+$ {
	printf("%s is a float.\n", yytext);
}
. ;
%%
int yywrap(void){};
int main(){
	yylex();
	return 0;
}