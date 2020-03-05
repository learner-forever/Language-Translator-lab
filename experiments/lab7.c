#include<stdio.h>
#include<string.h>
int main()
{
    int nt,t,i,j,k,l,m,n,count,c,a,b;
    char ans[100], que[100][100];
    printf("Enter number of productions:");
    scanf("%d",&count);
    for(i=0;i<count;i++)
    {
        printf("Enter production %d:",i+1);
        scanf("%s",que[i]);
    }
    for(i=0;i<count;i++)
        {

                printf("%s\n",que[i]);
        }
        scanf("%d",&a);
    for(i=count-1;i>=0;i--)
    {
        nt=que[i][0];
        for(j=i-1;j>=0;j--)
        {
            for(k=3;k<=100&&que[j][k]!='#';k++)
            {
                if(que[j][k]==nt)
                {
                    char temp[100];
                    c=0;
                    for(l=0;l<100&&que[j][k+l+1]!='#';l++)
                    {
                        temp[l]=que[j][k+l+1];
                        c++;
                    }
                    temp[l]='#';
                    c++;
                    for(l=0;l<100&&que[i][3+l]!='#';l++)
                    {
                        que[j][k+l]=que[i][3+l];
                    }
                    for(b=0;b<c;l++,b++)
                    {
                        que[j][k+l]=temp[b];
                    }
                }
            }
        }


    }
      for(i=0;i<count;i++)
        {

                printf(" production %d : %s\n",i+1,que[i]);
        }


        for(i=0;i<count;i++)
        {
            if(que[i][0]==que[i][3])
            {
                printf("%c\n",que[i][0]);

                    char temp[100];
                    c=0;
                    for(l=0;l<100&&que[j][k+l+1]!='#';l++)
                    {
                        temp[l]=que[j][k+l+1];
                        c++;
                    }
                    temp[l]='#';
                    c++;
                    que[i][3]='#';
                    que[i][4]='\0';
                    que[count][0]=que[i][0];
                    que[count][1]='\'';
                    que[count][2]='-';
                    que[count][3]='>';
                    que[count][5]='#';
                    que[count][6]='|';

                    for(b=0;b<c;b++)
                    {
                        que[count][7+b]=temp[b];
                    }
                    que[count][7+b]=que[i][0];
                    b++;
                    que[count][7+b]='\'';
                    b++;
                    que[count][7+b]='#';
                    b++;
                    count++;
                    que[count][7+b]='\0';
            }
        }
         for(i=0;i<count;i++)
        {

                printf("%s\n",que[i]);
        }
        scanf("%d",&a);
    return 0;
}
