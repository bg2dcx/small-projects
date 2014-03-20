#include <stdio.h>

int state_arr[4][4] = {0};

int main()
{
// freopen("1.txt", "r", stdin);
for(int i=0; i<4; i++)
{
for(int j=0; j<4; j++)
{
char ch;
ch = getchar();
if(ch == '+')
{
// ij 翻转三次就相当于翻转了一次
state_arr[i][j] = !state_arr[i][j];
for(int n=0; n<4; n++)
{
state_arr[n][j] = !state_arr[n][j];
state_arr[i][n] = !state_arr[i][n];
}
}
}
getchar();
}

int num = 0;
for(int i=0; i<4; i++)
{
for(int j=0; j<4; j++)
{
if(state_arr[i][j])
{
num++;
}
}
}
printf("%d\n", num);

for(int i=0; i<4; i++)
{
for(int j=0; j<4; j++)
{
if(state_arr[i][j])
{
printf("%d %d\n", i + 1, j + 1);
}
}
}
return 0;
}
