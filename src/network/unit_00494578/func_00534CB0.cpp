struct Pair { unsigned int a,b; };
struct Entry { Pair p; int n,z,arg,time; int *obj; unsigned int idx; };
struct Msg { int a; signed char idx,kind; char pad[10]; };
struct Global { char pad[0x6c]; int n; };
extern Entry D_008A05B0[];
extern Global *D_0064B47C;
extern "C" int func_00534A08() throw();
extern "C" int func_00531CA8() throw();
extern "C" int func_0052EAF8(signed char,int *,unsigned int,int,int,int,Msg *) throw();
extern "C" Pair *func_00535C88(int *,unsigned int);
extern "C" Pair func_00535D78(int *);
extern "C" int func_00534CB0(int *obj,unsigned int idx,int arg) {
    Msg m;
    if (!obj) return 23;
    if (idx >= 64 && idx != 65535) return 23;
    if (!arg) return 23;
    if (idx == (unsigned int)-1) return 8;
    int id = func_00534A08();
    if (id == 127) return 25;
    Entry *e = D_008A05B0 + id;
    m.a=0; m.kind=1; m.idx=id;
    func_0052EAF8(-128,obj,idx,0,1,8,&m);
    int n;
    if (idx == 65535) {
        Pair p = func_00535D78(obj);
        Global *g = D_0064B47C;
        e->obj=0;
        e->p=p;
        n=g->n;
        e->idx=64;
    } else {
        Pair *p = func_00535C88(obj,idx);
        if (!p) return 23;
        e->p=*p;
        e->obj=obj;
        n=*((int *)(p+1));
        e->idx=idx;
    }
    e->n=n; e->arg=arg; e->z=0;
    e->time=func_00531CA8();
    return 0;
}
