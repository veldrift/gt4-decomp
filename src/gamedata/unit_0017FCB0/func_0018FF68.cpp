struct VEntry{short delta,index;int(*fn)(void*);};
struct Obj{int m0;VEntry*vt;};
struct Handle{Obj*p;char pad[12];};
extern "C" void func_002405A8(void*,void*);
extern "C" void func_002403C8(void*,int);
extern "C" int func_0018FDD8(void*,Obj*,void*);
static inline int valid(Obj*obj){VEntry*e=(VEntry*)((char*)obj->vt+0x198);return e->fn((char*)obj+e->delta);}
extern "C" int func_0018FF68(void*arg0,void*arg1,void*arg2){Handle buf;func_002405A8(&buf,arg1);
if(buf.p==0){func_002403C8(&buf,2);return 0;}if(!valid(buf.p)){func_002403C8(&buf,2);return 0;}int r=func_0018FDD8(arg0,buf.p,arg2);func_002403C8(&buf,2);return r;}
