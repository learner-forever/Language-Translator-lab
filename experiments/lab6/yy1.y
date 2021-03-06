%{
#include<stdio.h>
#include<stdlib.h>
%}
%token PLUS MUL NEWLINE
%left + *
%token NUMBER

%%
lines 	: lines line
        |
	    ;
line    : expr NEWLINE		  { printf("%d\n> ", $1); }
        ;
expr    : expr PLUS term	  { $$ = $1 + $3; }
        | term			      { $$ = $1; }
        ;
term    : term MUL factor	  { $$ = $1 * $3; }
        | factor		      { $$ = $1; }
        ;
factor  : NUMBER		      { $$ = $1; }
	    ;
%%
yylex() {
	int c;
	do {
		c=getchar();
		switch (c)
		{
			case '0': 
			case '1': 
			case '2': 
			case '3': 
			case '4': 
			case '5': 
			case '6':
			case '7':
			case '8':
			case '9':
					yylval= c -'0';
					return NUMBER;
					
			case '+': return PLUS;
			case '\n': return NEWLINE;
		}
	} while (c!= EOF);
	return(EOF);
}
main() {
	yyparse();
}

