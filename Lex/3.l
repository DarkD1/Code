
%{
%}
%%
(if|else|while|int|switch|for|char|double|array|enum|struct|class|goto) {
	printf("%s is a keyword.\n", yytext);
}
. ;
%%
int yywrap(void){};
int main(){
	yylex();
	return 0;
}