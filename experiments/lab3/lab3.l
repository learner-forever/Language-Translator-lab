%{
	int count = 0;
%}

%%
"'"[^.]*"'"					{printf("%s - is a string\n",yytext);}
if|for|while|do|else|case|switch|until|exit     {printf("%s - is a keyword\n",yytext);}
[a-z]([a-z]|[0-9])*				{printf("%s - is an identifier\n",yytext);}
([0-9])+"."([0-9])*				{printf("%s- is a floating point number",yytext);}
([0-9])+					{printf("%s - is a simple number\n",yytext);}
[ \t\n]						{printf("%s - is a whitespace\n",yytext);}
"["|"]"|"{"|"}"|"("|")"|","			{printf("%s - is a punctuation\n",yytext);}
"***"[^.]*"\n"					{printf("%s - is a comment\n",yytext); }
":="|"<>"|"=="|"!="|"<="|">="			{printf("%s - is a relational operator \n",yytext);}
"+"|"-"|"*"|"%"					{printf("%s - is a mathematical operator\n",yytext);}
.        					{printf("%s - is not a valid input \n");}
%%
int yywrap(){}

int main(argc, argv)
int argc;
char **argv;
{
	 ++argv;
	 --argc;  /* skip over program name */
         if (argc>0)
                     yyin = fopen( argv[0], "r" );
             else
                     yyin = stdin;	 
             yylex();
             printf("Completed scanning");
             return 0;
}

