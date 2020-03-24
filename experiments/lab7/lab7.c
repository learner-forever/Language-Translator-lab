#include<stdio.h>
#include<string.h>
int main()
{
    int nt,t,i,j,k,l,m,n,count,c,a,b;
    char ans[100], que[100][100];
    printf("Enter new line as grammar rule for every production \n Ex: Instead of A->B|C# Enter A->B#\nA->C#\n");
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
            for(k=3;k<=3&&que[j][k]!='#';k++)
            {
                if(que[j][k]==nt&&que[j][0]!=nt)
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
    printf("Transforming Indirect recursion into direct recursion\n");
      for(i=0;i<count;i++)
        {

                printf(" production %d : %s\n",i+1,que[i]);
        }
        for(i=0;i<count;i++)
        {
            for(j=i+1;j<count;j++)
            {

                if(que[i][0]==que[j][0])
                {

                    for(k=0;k<100&&que[i][k]!='#';k++);
                    que[i][k]='|';
                    k++;
                    for(l=3;l<100&&que[j][l]!='#';l++)
                    {
                        que[i][k]=que[j][l];
                        k++;
                    }

                    que[i][k]='#';
                    for(l=0;l<100&& que[count-1][l]!='#';l++)
                    {
                        que[j][l]=que[count-1][l];
                    }

                    que[j][l]='#';
                    l++;
                    que[j][l]='\0';
                    count--;
                }
            }
        }
        printf("Combining rules with same L.H.S.\n");
        for(i=0;i<count;i++)
        {

                printf(" production %d : %s\n",i+1,que[i]);
        }
        printf("Left Recursion found in :-");
        for(i=0;i<count;i++)
        {
            if(que[i][0]==que[i][3])
            {
                printf("%c\n",que[i][0]);

                    char temp[100][100];
                    c=3;
                    for(j=0;j<100&&que[i][c]!='#';j++)
                    {

                        for(k=0;k<100&&que[i][c]!='|'&&que[i][c]!='#';k++)
                        {
                            temp[j][k]=que[i][c];
                            c++;
                        }

                        temp[j][k]='#';
                        if(que[i][c]=='|')
                            c++;
                    }
                  /*   for(k=0;k<j;k++)
                    {

                            printf("%s\n",temp[k]);
                    }
*/
                count++;
                que[count-1][0]=que[i][0];
                que[count-1][1]='\'';
                que[count-1][2]='-';
                que[count-1][3]='>';
                que[count-1][4]='#';
                que[count-1][5]='|';
                int c1=6;
                c=3;
                for(k=0;k<j;k++)
                {
                    if(temp[k][0]==que[i][0])
                    {
                        for(l=1;l<100&&temp[k][l]!='#';l++)
                        {
                            que[count-1][c1]=temp[k][l];
                            c1++;
                        }
                        que[count-1][c1]=que[count-1][0];
                        c1++;
                        que[count-1][c1]='\'';
                        c1++;
                        que[count-1][c1]='|';
                        c1++;
                        //printf("%d - %s \n",k,que[count-1]);
                    }
                    else
                    {
                        for(l=0;l<100&&temp[k][l]!='#';l++)
                        {
                            que[i][c]=temp[k][l];
                            c++;
                        }
                        que[i][c]=que[i][0];
                        c++;
                        que[i][c]='\'';
                        c++;
                        que[i][c]='|';
                        c++;
                        //printf("%d - %s \n",k,que[i]);
                    }

                }
                que[count-1][c1]='\0';
                que[i][c]='\0';
                c--;
                c1--;
                que[count-1][c1]='#';
                que[i][c]='#';


            }
        }

/*

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
        }*/
        printf("Final Grammar eliminating left recursion:\n");
         for(i=0;i<count;i++)
        {

                printf("%s\n",que[i]);
        }
        scanf("%d",&a);
    return 0;
}
