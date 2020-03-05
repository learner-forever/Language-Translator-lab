#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int main(int argc, char **argv)
{
    //++argv, --argc;
    argc=1;
    argv[0]="f.c";
    if(argc>0)
	{
	    FILE *filePointer ;
        char input[1000];
        filePointer = fopen(argv[0], "r") ;
        if ( filePointer == NULL )
        {
            printf( "file error\n" ) ;
        }
        else
        {
            while( fgets ( input, 1000, filePointer ) != NULL )
            {
                scanf("%s",input);
            }

             fclose(filePointer) ;
        }
	}
	else
    {
        printf("Give file name as command line input\n");
    }
	return 0;
}
void scan(char a[])
{
    int l=strlen(a);
    int i=0,isFloat=0;
    char ch=a[i];
    printf("%s ---",a);
    while(i<l)
    {
        char token[1000]="";
        int j=0;
        token[j]=ch;
        if(isdigit(ch))
        {
            isFloat=0;
            while(i<l)
            {
                i++;
                ch=a[i];
                if(isdigit(ch))
                {
                    j++;
                    token[j]=ch;
                }
                else if(ch=='.')
                {
                    isFloat=1;
                    j++;
                    token[j]=ch;
                }
                else
                {
                    i--;
                    break;
                }

            }
            j++;
            token[j]='\0';
            if(isFloat==1)
                printf("%s - This is float number\n",token);
            else
                printf("%s - This is integer\n",token);
        }
        else if(isalpha(ch))
        {
            while(i<l)
            {
                i++;
                ch=a[i];
                if(isalpha(ch))
                {
                    j++;
                    token[j]=ch;
                }
                else
                {
                    j++;
                    token[j]='\0';
                    i--;
                    if(!strcmp(token,"if")||!strcmp(token,"else")||!strcmp(token,"while")||!strcmp(token,"do")||!strcmp(token,"for")||!strcmp(token,"exit")||!strcmp(token,"case")||!strcmp(token,"switch")||!strcmp(token,"until"))
                    {
                        printf("%s is a keyword\n",token);
                        break;
                    }
                    else
                    {
                        printf("%s - This is a variable\n",token);
                    }
                    break;
                }
            }

        }
        else if(isspace(ch))
        {
            printf("%c is whitespace\n",ch);
        }
        else if(ch=='=')
        {

            if(a[i+1]=='=')
            {
                j++;
                token[j]='=';
                i+=1;
                j++;
                token[j]='\0';
                printf("%s is an operator\n",token);

            }
            else
            {
                printf("%c is an invalid token\n",token[0]);
            }
        }
        else if(ch=='+'||ch=='-'||ch=='%')
        {
            printf("%c is an operator\n",token[0]);
        }
        else if(ch=='*')
        {

            if(a[i+1]=='*')
            {
                if(a[i+2]=='*')
                {
                    j++;
                    token[j]='*';
                    j++;
                    token[j]='*';
                    i+=2;
                    while(i<l)
                    {
                        i++;
                        ch=a[i];
                        if(ch!='\n')
                        {
                            j++;
                            token[j]=ch;
                        }
                        else
                        {
                            j++;
                            token[j]=ch;
                            j++;
                            token[j]='\0';
                            i--;
                            break;
                        }
                    }
                    printf("%s is a comment\n",token);
                }
                else
                {
                    j++;
                    token[j]='\0';
                    printf("%c is an invalid token\n",token);
                }
            }
            else
            {
                printf("%c is an operator\n",token[0]);
            }
        }
        else if(ch=='!')
        {
            if(a[i+1]=='=')
            {
                i+=1;
                j++;
                token[j]='=';
                j++;
                token[j]='\0';
                printf("%s is ne operator\n",token);
            }
            else
            {
                printf("%c is invalid token\n",ch);
            }
        }
        else if(ch=='<')
        {
            if(a[i+1]=='=')
            {
                i++;
                j++;
                token[j]='=';
                j++;
                token[j]='\0';
                printf("%s is an operator\n",token);
            }
            else if(a[i+1]=='>')
            {
                i++;
                j++;
                token[j]='>';
                j++;
                token[j]='\0';
                printf("%s is an operator\n",token);
            }
            else
            {
                printf("%c is an invalid token\n",token[0]);
            }
        }
        else if(ch=='>')
        {
            if(a[i+1]=='=')
            {
                i++;
                j++;
                token[j]='=';
                printf("%c is ge operator\n",token[0]);
            }
            else
            {
                printf("%c is an invalid token\n",token[0]);
            }
        }
        else if(ch==':')
        {
            if(a[i+1]=='=')
            {
                i++;
                j++;
                token[j]='=';
                printf("%c is an operator\n",token[0]);
            }
            else
            {
                printf("%c is an invalid token\n",token[0]);
            }
        }
        else if(ch=='('||ch==')'||ch=='['||ch==']'||ch=='{'||ch=='}'||ch==',')
        {
             printf("%c is a punctuation\n",token[0]);
        }
        else if(ch=='\'')
        {
            while(i<l)
            {
                i++;
                ch=a[i];
                if(ch!='\'')
                {
                    j++;
                    token[j]=ch;
                }
                else
                {
                    j++;
                    token[j]=ch;
                    j++;
                    token[j]='\0';
                    break;
                }
            }
            printf("%s is a string",token);
        }
        else
        {
            printf("%c is invalid\n",ch);
        }
        i++;
        ch=a[i];
    }
}


