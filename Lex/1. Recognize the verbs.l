%{
/* Write a simple lex specification to recognize the following verb: is, am, are, were.. etc*/
%}

%%
(is|am|are|were|was|be|being|been|do|does|did|well|would|should|can|could|has|have|had|go) {
	printf("%s is a valid verb", yytext);
}
%%
int yywrap(void){};
int main(){
	yylex();
	return 0;
}