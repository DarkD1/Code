
%{
%}
%%
['"(){}\[\].,;:-] {
	printf("%s is a punctuation.\n", yytext);
}
. ;
%%
int yywrap(void){};
int main(){
	yylex();
	return 0;
}