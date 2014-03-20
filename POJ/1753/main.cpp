#include <iostream>
#define MAXSIZE 65536
using namespace std;

int board[MAXSIZE];
int que[MAXSIZE];
int from[MAXSIZE];
int head,tail;
int steps=0;

bool check(int state){
 bool allzero=true;
 bool allones=true;
 int tmp=1;
 for (int i=0;i<16;i++)
 {
     tmp=(1<<i);
     if ((tmp&state) > 0) allzero=false;
     else allones=false;
 }
 if (allzero || allones) return true;
 return false;
}

int flip(int state, int pos){
    pos++;
    if ( (state&(1<<(pos-1))) > 0 )  state ^= 1<<(pos-1); else state |= (1<<(pos-1));
    if (pos>4) {
        if ((state&(1<<(pos-5))) > 0) state ^= 1<<(pos-5); else state |= (1<<(pos-5));
    }
    if ((pos%4) != 1) {
        if ((state&(1<<(pos-2))) > 0) state ^= 1<<(pos-2); else state |= (1<<(pos-2));
    }
    if ( (pos%4) != 0){
        if ( (state&(1<<pos)) > 0) state ^= 1<<pos; else state |= (1<<pos);
    }
    if (pos<13) {
        if ((state&(1<<(pos+3))) > 0) state ^= 1<<(pos+3); else state |= (1<<(pos+3));
    }
    return state;
}

void bprint(int state){
int number=0;
for (int i=0;i<16;i++){
    number++;
    if ((state&(1<<i)) > 0) cout<<1; else cout<<0;
    if (number==4) {cout<<endl;number=0;}
}
cout<<endl;
}
int main()
{
    for (int i=0;i<MAXSIZE;i++){
        board[i]=MAXSIZE+1;
        que[i]=0;
        from[i]=0;
    }
    char piece;
    int state=0;
    for (int i=0;i<16;i++){
        cin>>piece;
        if (piece=='b') state+=(1<<i);
    }
    board[state]=0;
    head=0;tail=0;
    que[head]=state;
    int currentstate=0;
    if (check(que[head])) {
        cout<<board[que[head]];
        return 0;
    }
    while (head<=tail){
       currentstate=que[head];
       for (int i=0;i<16;i++){
         int newstate=flip(currentstate,i);
         if (check(newstate)) {
            cout<<board[currentstate]+1;
            return 0;
         }
         if (board[currentstate]+1<board[newstate]){
            board[newstate]=board[currentstate]+1;
            from[newstate]=currentstate;
            tail++;
            que[tail]=newstate;
         }
       }
       head++;
    }
    cout<<"Impossible";
    return 0;
}
