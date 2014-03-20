#include <iostream>
#define MAX 65537
using namespace std;

int state[MAX];
int action[MAX];
int parent[MAX];
int que[MAX];
int head,tail;
int model[16];

void init(){
  for (int i=0;i<MAX;i++){
    state[i]=MAX;
    action[i]=-1;
    que[i]=-1;
    parent[i]=-1;
  }
}

bool check(int value){

    bool allopen=true;
    if (value !=0 ) allopen=false;
    return allopen;
}
int change(int value,int act){
    int row=act/4;
    int colum=act-row*4;
    for (int i=0;i<4;i++){
        int pos=colum+i*4;
        if  ((value & (1<<pos)) == 0) value=value | (1<<pos);
            else value^=1<<pos;
        if (i != colum) {
           pos=i+row*4;
           if  ((value & (1<<pos)) == 0) value=value | (1<<pos);
                else value^=1<<pos;
        }
    }

    return value;
}

void buildmodel(){
  for (int i=0;i<16;i++)
    model[i]=change(0,i);
}

void trace(int value,int steps){
     if (action[value] ==-1){
        cout<<steps<<endl;
     } else{
        int row=action[value]/4;
        int colum=action[value]-row*4;
        trace(parent[value],steps+1);
        cout<<row+1<<' '<<colum+1<<endl;
     }
}

void print(int value){
trace(value,0);
/*
 for (int i=0;i<16;i++){
    if ( (i%4)== 0) cout<<endl;
    if ( (value & (1<<i)) == 0) cout<<0; else cout<<1;
}
cout<<endl;
*/

}


int main()
{
    init();
    int value=0;
    for (int i=0;i<16;i++)
    {
        char r;
        cin>>r;
        if (r=='+') value=value+(1<<i);
    }
    state[value]=0;
    head=tail=0;
    que[head]=value;
    if (check(value)) {cout<<0<<endl; return 0;}
    int current;
    int child;
/*
    current=change(value,0); print(current);
    current=change(current,2); print(current);
    current=change(current,3); print(current);
    current=change(current,12); print(current);
    current=change(current,14); print(current);
    current=change(current,15); print(current);
    cin>>head;
    return 0;
*/
   buildmodel();
   /*for (int i=0;i<16;i++)
    print(model[i]);
    */
   bool findit=false;
   while (head<=tail){
        current=que[head];
        for (int i=0;i<16;i++){
            child=current^model[i];
            if (check(child)){
                action[child]=i;
                parent[child]=current;
                print(child);
                findit=true;
                break;
            }
            if (state[child]==MAX){
                state[child]=head;
                parent[child]=current;
                action[child]=i;
                tail++;
                que[tail]=child;
            }
        }
        if (findit) break;
        head++;
    }
    return 0;
}
