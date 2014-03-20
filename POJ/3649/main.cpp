#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#define MAXROW 25
#define PADDING 30
using namespace std;

struct GLYPH
{
    char shape[25][25];
    int length;
} glyphs[21];

char input[MAXROW][500];

char ans[MAXROW][500];

int numOfRows,len,current,numOfGlyphs,prev,maxlen;

int toRight[MAXROW],toleft[MAXROW],maxl[MAXROW];

void init()
{
    for (int i=0;i<MAXROW;i++)
        for (int j=0;j<500;j++)
    {
        input[i][j]='.';
        ans[i][j]='.';
    }
    for (int k=0;k<21;k++)
    {
        for (int i=0;i<MAXROW;i++)
        {
            for (int j=0;j<MAXROW;j++)
                glyphs[k].shape[i][j]='.';
        }
    }
    numOfGlyphs=0;
    len=0;
    current=0;
}

void solve(int number)
{
    int maxTrans=0;
    for (int i=0;i<numOfRows;i++)
    {
        toRight[i]=-1;
        if (maxl[i] != -1)
            toRight[i]=maxlen-maxl[i];
        toleft[i]=0;
        int tmp=0;
        while (glyphs[number].shape[i][tmp] == '.' && tmp<glyphs[number].length)
        {
            tmp++;
        }
        toleft[i]=tmp;
        if (toleft[i]>maxTrans)
            maxTrans=toleft[i];
    }
    maxTrans+=1+maxlen;
    for (int i=0;i<numOfRows;i++)
    {
        if (! (toRight[i] == -1 || toleft[i]==glyphs[number].length))
            if (toRight[i]+toleft[i]-1<maxTrans)
                maxTrans=toRight[i]+toleft[i]-1;
    }
    int tmpMax=0;
    for (int i=0;i<numOfRows;i++)
    {
        for (int j=0;j<glyphs[number].length;j++)
            if (glyphs[number].shape[i][j] != '.')
        {
            ans[i][maxlen+1+j-maxTrans]=glyphs[number].shape[i][j];
            if (maxlen+1+j-maxTrans>tmpMax)
                tmpMax=maxlen+1+j-maxTrans;
            if (maxlen+1+j-maxTrans>maxl[i])
                maxl[i]=maxlen+1+j-maxTrans;
        }
    }
    if (tmpMax>maxlen)
        maxlen=tmpMax;
}

int main()
{
    FILE *fp;
    fp=fopen("typesetting.in","r");
    fscanf(fp,"%d",&numOfRows);
    int numofCases=0;
    while (numOfRows !=0)
    {
        init();
        for (int i=0;i<numOfRows;i++)
         {
             fscanf(fp,"%*c");
             fscanf(fp,"%[^\n]",input[i]);
         }
        len=strlen(input[0]);
        current=0;
        prev=0;
        while (current<len)
        {
            prev=current;
            while (current<len && input[0][current]!=' ')
                current++;
            for (int k=0;k<numOfRows;k++)
            {
                for (int i=prev;i<current;i++)
                    glyphs[numOfGlyphs].shape[k][i-prev]=input[k][i];
                glyphs[numOfGlyphs].shape[k][current-prev]='\0';
                glyphs[numOfGlyphs].length=current-prev;
            }
            numOfGlyphs++;
            current++;
        }
        len=strlen(glyphs[0].shape[0]);
        for (int i=0;i<numOfRows;i++)
            for (int j=0;j<len;j++)
                ans[i][j+PADDING]=glyphs[0].shape[i][j];
        maxlen=-1;
        for (int i=0;i<numOfRows;i++)
        {
            maxl[i]=-1;
            for (int j=0;j<len+PADDING;j++)
                if (ans[i][j] == '#' || ans[i][j]=='0')
                    if (j>maxl[i])
                        maxl[i]=j;
            if (maxl[i]>maxlen)
                maxlen=maxl[i];
        }
        for (int i=1;i<numOfGlyphs;i++)
            solve(i);
        numofCases++;
        cout<<numofCases<<endl;
        int minilen=500;
        for (int i=0;i<numOfRows;i++)
            for (int j=0;j<=maxlen;j++)
                if (ans[i][j] == '#')
                  if (j<minilen)
                    minilen=j;
        int outputMax=0;
        for (int i=0;i<numOfRows;i++)
            for (int j=0;j<=maxlen;j++)
                if (ans[i][j] == '#')
                  if (j>outputMax)
                    outputMax=j;
        for (int i=0;i<numOfRows;i++)
        {
            for (int j=minilen;j<=outputMax;j++)
                if (ans[i][j] == '#')
                    cout<<'#';
                else cout<<'.';
            cout<<endl;
        }
        fscanf(fp,"%d",&numOfRows);
    }
    return 0;
}
