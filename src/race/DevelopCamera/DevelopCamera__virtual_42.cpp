struct R { int value; ~R() {} };
struct E {short adjust,pad;R (*call)(void *,int);};
struct S{E *table;char pad[0x9b8];int index;};
struct Slot{char pad[0x130];int state;char tail[0x68];inline int get()const{return state;}};
extern "C" int DevelopCamera__virtual_42(S *s){int index=s->index;Slot *slot=(Slot *)((char *)s+0x10)+index;E *e=s->table+42;R r; r=e->call((char *)s+e->adjust,index);int result=1; if((r.value ^ 5)==0)result=slot->get()==-2;return result;}
