
%{
%}
%%
(is|am|are|were|go) {
	printf("%s is a verb", yytext);
}
(very|simply|gently|quickly) {
	printf("%s is an adverb", yytext);
}
(to|from|behind|between) {
	printf("%s is a preposition", yytext);
}
(if|then) {
	printf("%s is a conjunction", yytext);
}
. ;
%%
int yywrap(void){};
int main(){
	yylex();
	return 0;
}