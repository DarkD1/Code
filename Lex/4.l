
%{
%}
%%
(if|else|while|int|switch|for|char|double|array|enum|struct|class|goto) {
}
[0-9][_a-zA-Z0-9]* {
}
[_a-zA-Z][_a-zA-Z0-9]* {
	printf("%s is an identifier.\n", yytext);
}
. ;
%%
int yywrap(void){};
int main(){
	yylex();
	return 0;
}
