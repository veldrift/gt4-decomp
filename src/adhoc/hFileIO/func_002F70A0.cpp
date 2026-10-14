struct H{int length,size,refs,clone;};struct S00659988{void*name;};
extern "C" S00659988*func_005C11A8();
extern "C" void func_00326798(void*,int,int,void*);
extern "C" char*func_005C2560(H*,char*);
extern "C" int func_004AFED8(void*,char*,int);
struct Str{char*p;Str&operator=(const Str&s){if(&s!=this){H*h=(H*)p-1;if(!--h->refs){int n=h->size;n+=16;S00659988*t=func_005C11A8();func_00326798(h,n,4,t->name);}char*q=s.p;H*k=(H*)q-1;if(k->clone)q=func_005C2560(k,q);else ++k->refs;p=q;}return *this;}};
struct V{short adjust,pad;void(*fn)(void*);};struct S{int z;char*table;char pad[12];Str str;char member[0xd0];int error;};
static inline int truth(int n){return n!=0;}
static inline V&entry(S*p){return *(V*)(p->table+0x1b0);}
extern "C" int func_002F70A0(S*p,Str*in,int flag){V&e=entry(p);e.fn((char*)p+e.adjust);char*q=in->p;int n=((H*)q-1)->length;if(n){q[n]=0;if(func_004AFED8(p->member,in->p,truth(flag&2))<0){p->error=4;return 0;}p->str=*in;}return 1;}
