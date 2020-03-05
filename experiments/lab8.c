#include<stdio.h>
#include<string.h>

int main()
{
	int a=1,n,i=0;
	char ip[100][100];
	while(a)
	{
		printf("Enter :");
		scanf("%s",ip[i]);
		i++;
		printf("Has More?");
		scanf("%d",&a);
	}
	n=i;
	LF(ip,n);
	/*while(a)
	{
		a=LF(ip,i);
		
	}*/

}

int LF(char str[100][100], int n)
{

	int i,j=0;
	int ans=0;
	char s[100][100];
	char sa[100][100];
	char temp[100];
	int ai[100];
	strcpy(temp,str[0]);
	for (i=0;i<n&&strcmp(temp,"#")!=0;)
	{
		printf("%s\n",temp);
		if(!strcmp(temp,"->"))
		{
			printf("Recieved ->");
			strcpy(s[j],str[i+1]);
			ai[j]=i+1;
			j++;
			i++;	
		}
		if(!strcmp(temp,"|"))
		{
			printf("Recieved |");
			if(j==2)
			{
				if(!strcmp(s[j-1],s[j-2]))
				{
					ans=1;
				
				}
			}
			else
			{
				strcpy(s[j],str[i+1]);
				ai[j]=i+1;
				j++;
				i++;
				
			}
			
		}
		i++;
		strcpy(temp,str[i]);
	}
	if(j==2)
	{
		if(!strcmp(s[j-1],s[j-2]))
		{
			ans=1;
				
		}
	}
	if(ans==1)
	{
		j=0;
		int k=0, y;
		strcpy(sa[0],str[0]);
		for (i=1;i<n&&strcmp(sa[j],"#")!=0;)
		{
			if(i==ai[k])
			{
				j++;
				strcpy(sa[j],str[i]);
				j++;
				strcpy(sa[j],str[0]);
				strcat(sa[j],"'");
				j++;
				strcpy(sa[j],"#");
				j++;
				strcpy(sa[j],sa[j-2]);
				j++;
				strcpy(sa[j],"->");
				i++;
				while((strcmp(str[i],"|")!=0))
				{
					j++;
					strcpy(sa[j],str[i]);
					i++;
				}
				printf("Here %s \n",str[i]);
				j++;
					strcpy(sa[j],str[i]);
					i++;
				
				if(!(strcmp(str[ai[k+1]+1],"#")))
				{
					j++;
					strcpy(sa[j],"^");
				}
				j++;
				strcpy(sa[j],"#");
				for( y=0;y<=j;y++)
				{
					printf("%s",sa[y]);
				}
				return;
			}
			else
			{
				j++;
				strcpy(sa[j],str[i]);
				i++;
			}
		
		}
	}
	
	
}







