struct Item{char pad[0x3444];int index;};
struct List{unsigned count;int pad;int items;};
struct S{char pad[0x60];List*list;};
extern "C" void RaceOrganization__movePosition(S*s,int from,int to){
 List*l=s->list;
 int forward=from<to;
 if(from==to)return;
 unsigned count=l->count;
 if(to<0)to=0;
 else if((unsigned)to>=count)to=count-1;
 for(unsigned i=0;i<l->count;i++){
 Item*p=(Item*)((int*)l->items)[i];int n=p->index;
 if(n==from)n=to;
 else if(!forward){if(n>=to){if(n<from)++n;}}
 else {if(n>from){if(n<=to)--n;}}
 p->index=n;
 }
}
