#include<bits/stdc++.h>

using namespace std;

class ac
{
public:
    int id, pal[11], solve[11], tl_pal, sub;
    set<int> s;

};
bool comp(ac a,ac b)
{
    if(a.s.size() == b.s.size()){
        if(a.tl_pal == b.tl_pal)  return a.id < b.id;
        return (a.tl_pal < b.tl_pal);
    }
    return (a.s.size() > b.s.size());
}

int main(){
    ac obj[102];
    int t,i,j,k,l,id,prb,pal;
    char L,input[250];
    scanf("%d\n",&t);
    while(t--)
    {
        for(i=0; i<101; i++){
            memset(obj[i].pal,0,sizeof(obj[i].pal));
            memset(obj[i].solve,0,sizeof(obj[i].solve));
            obj[i].tl_pal=0;
            obj[i].sub=0;
            obj[i].s.clear();
        }
        while(gets(input) && strlen(input)){
            sscanf(input,"%d %d %d %c", &id, &prb, &pal, &L);
            obj[id].id = id;
            obj[id].sub++;
            if(L == 'C'){
                if(!obj[id].solve[prb]){
                    obj[id].solve[prb] = 1;
                    obj[id].tl_pal += pal + (obj[id].pal[prb]*20);
                    obj[id].s.insert(prb);
                }
            }
            else if(L == 'I' && obj[id].solve[prb] == 0)  obj[id].pal[prb]++;
        }
        sort(obj,obj+101,comp);
        for(i=0; i<101; i++)    if(obj[i].sub > 0)    printf("%d %d %d\n",obj[i].id,obj[i].s.size(),obj[i].tl_pal);
        if(t>0) printf("\n");
    }

    return 0;
}
