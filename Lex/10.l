
%{
%}
%%
[0-9]+ {
	printf("%s is a digit.\n", yytext);
}
. ;
%%
int yywrap(void){};
int main(){
	yylex();
	return 0;
}