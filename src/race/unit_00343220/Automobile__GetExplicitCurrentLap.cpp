struct V{short adjust;short pad;int(*call)(void*);};
struct Sub{char pad[0x4ac];short count;char pad2[4];unsigned char flag;};
struct S{int pad;char*object;};
extern "C" int Automobile__GetExplicitCurrentLap(S*self){Sub*p=(Sub*)((char*)self+0x104);char*obj=self->object;int n=p->count;V*v=(V*)(*(char**)(obj+0x10140)+0x128);v->call(obj+v->adjust);if(n<=0)n=1;else if(p->flag)n=n-1;return n;}
