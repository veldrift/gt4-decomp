struct Node {unsigned char flag,p1,type,p3;int owner,cur;char pad[0x2c];int *arr;};
struct Entry {int a,b,start,len;unsigned pos,count;};
struct Event {int type,obj,idx,data;};
struct Context {char p[0x104];int n;char q[0x10];int obj;char r[0xe638-0x11c];signed char flags[4096];};
struct Callback {char p[0x128];void (*cb)(Event*);int data;};
extern Callback *D_0064B4B4;
extern Context D_00854038;
extern signed char D_00862670[];
extern "C" Entry* func_00535C88(int,int);
extern "C" Entry* func_0051B8A8(int,unsigned);
extern "C" int func_00515F98(int*,int) throw();
extern "C" int func_00519748(int,int,int*);
extern "C" Node* func_00515DD8(unsigned) throw();
extern "C" Node* func_00515EC8(unsigned) throw();
extern "C" void func_00516030(int,int,unsigned) throw();
extern "C" void func_00516130(int) throw();
extern "C" void func_00531738(int*);
extern "C" void func_0051B9B8(int,unsigned);
extern "C" void func_00519468(int obj,int idx){
 Event event;int value;int i=0x100;int result=i;
 if(!obj)return;
 Node *node=(Node*)&D_00854038;
 if(obj!=((Context*)node)->obj)return;
 Entry *e=func_00535C88(obj,idx);if(!e)return;
 e->len=2;e->pos=0;e->count=0;
 Entry *entry=func_0051B8A8(obj,idx);if(!entry)return;
 func_00515F98(&value,obj);result=value;
 if(idx==value){if(func_00519748(obj,idx,&result))return;if(result==i)return;}
 Callback *c=D_0064B4B4;
 if(c->cb){event.data=c->data;event.type=1;event.obj=obj;event.idx=idx;c->cb(&event);}
 i=0;
 if(i<((Context*)node)->n){Context *ctx=(Context*)node;int invalid=-1;signed char *p=ctx->flags;do{
  if(*p==2){node=func_00515DD8(i);if(node){
   node->arr[idx]=0;
   if(node->cur==idx){
    if((unsigned char)(node->type+0xfd)<2){
     func_00515F98(&node->cur,obj);
     if(node->owner==idx){node->owner=invalid;func_00516030(-1,i,-2);}
    }else{func_00516130(i);*p=0;}
   }else if(node->owner==idx){node->owner=invalid;func_00516030(-1,i,-2);}
  }}
 i++;p++;}while(i<ctx->n); }
 i=entry->start;
 if(i<entry->start+entry->len){int active=1;signed char *f=D_00862670+i;do{if(*f==active)*f=0;i++;f++;}while(i<entry->start+entry->len);}
 if(entry->pos<0x200){
  unsigned k=0;
  for(;k<entry->count;){Node *n=func_00515EC8(k+entry->pos);k++;if(n){if(n->flag==2 && n->type)func_00531738((int*)((char*)n+0x10));n->flag=0;}}
 }
 func_0051B9B8(obj,idx);
}
