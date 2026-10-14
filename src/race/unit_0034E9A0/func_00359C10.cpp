struct E{int a,start,delta,b,value;char pad[0x14f4-20];};struct O{char pad[0x11c];int pos;char pad2[0x2c];E*entries;};struct S{char*owner;int a,b;O*object;char pad[0x534];unsigned char tag;};struct Q;
extern "C" void func_003B76F0(Q*,int,int,int);
static inline E&entry(O*p,int i){return p->entries[i];}
extern "C" void func_00359C10(S*p,int i,int value,int enabled){func_003B76F0((Q*)(p->owner+0xf4),15,p->tag,0);if(enabled){O*o=p->object;E&e=entry(o,i);int pos=o->pos;e.value=value;e.delta=pos-e.start;}}
