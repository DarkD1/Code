%{
/* Write a simple lex specification to recognize the following words as differnt parts of speech: is, am, are, were.. etc*/
%}

%%
(is|am|are|were|was|be|being|been|do|does|did|well|would|should|can|could|has|have|had|go) {
	printf("%s is a verb", yytext);
}
(very|simply|gently|calmly|fluently) {
	printf("%s is an adverb", yytext);
}
(to|from|behind|between|above) {
	printf("%s is a preposition", yytext);
}
(if|then|and|but|or) {
	printf("%s is a conjunction", yytext);
}
(huge|fantastic|gentle|sharp|perfect) {
	printf("%s is an adjective", yytext);
}
(I|you|he|she|we) {
	printf("%s is a pronoun", yytext);
}
[a-zA-z]+ {
	printf("%s is a noun maybe." ,yytext);
}
%%
int yywrap(void){};
int main(){
	yylex();
	return 0;
}