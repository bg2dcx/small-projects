#include<iostream>
#include<stdio.h>
using namespace std;
char a[9][9];
int d=0;
int num1=0,num2=0;
int judge(char ch)
{
	if(ch=='+'||ch=='-'||ch=='|')return 0;
	return 1;
}
int judge2(char ch)
{
	if(ch==':'||ch=='.')return 0;
	else return 1;
}
int find(char ch)
{
	int i,j,pos;
	if('A'<=ch&&ch<='Z')for(i=1;i<=8;i++)
	   for(j=1;j<=8;j++){if(a[i][j]==ch){if(ch!='P')cout<<ch;d++;pos='b'+j-2;printf("%c",pos);cout<<i;if(d!=num1)cout<<",";}}
    else for(i=8;i>=1;i--)
	   for(j=1;j<=8;j++)if(a[i][j]==ch){if(ch!='p'){pos=ch-'b'+'B';printf("%c",pos);}d++;pos='b'+j-2;printf("%c",pos);cout<<i;if(d!=num2)cout<<",";}
    return 0;
}
int main()
{
	int  i,col,row,j=0,k;
	char ch;
	d=0;
	for(i=0;i<9;i++)
	for(k=0;k<9;k++)a[i][k]='0';
	for(i=1;i<=561;i++){cin>>ch;if(judge(ch)){j++;if(judge2(ch)){if('a'<ch&&ch<'z')num1++;else num2++;col=(j%24)/3+1;row=8-j/24;a[row][col]=ch;}}}
    cout<<"White: ";
    find('K');find('Q');find('R');find('B');find('N');find('P');
    d=0;
    cout<<endl;
    cout<<"Black: ";
    find('k');find('q');find('r');find('b');find('n');find('p');
    cout<<endl;
	return 0;
}
