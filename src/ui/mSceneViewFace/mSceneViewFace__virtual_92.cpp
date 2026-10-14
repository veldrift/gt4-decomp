struct V{short adjust,pad;void(*fn)(void*,int,int);};
struct S{int z;char* table;char pad[0x90];unsigned flags;};
extern "C" int func_00265DC8(S*);
extern "C" int func_00231CC8(int);
static inline V& entry(S*p){return *(V*)(p->table+0x238);}
extern "C" void mSceneViewFace__virtual_92(S*p,int n){if(func_00265DC8(p)&&func_00231CC8(n)&&(p->flags&0x40000)){V&e=entry(p);e.fn((char*)p+e.adjust,n,1);}}
