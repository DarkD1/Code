
%{
%}
%%
^[+-]?[0-9]*[.]?[0-9]+$ {
	printf("%s is a real number.\n", yytext);
}
. ;
%%
int yywrap(void){};
int main(){
	yylex();
	return 0;
}