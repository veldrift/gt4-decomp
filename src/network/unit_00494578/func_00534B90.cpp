struct Pair { unsigned int a,b; };
struct Data { Pair p; int n; };
struct Entry { Pair p; int n,z; void (*cb)(); int time; int *obj; unsigned int idx; };
struct Msg { int a; signed char idx,kind; char pad[10]; };
struct Global { char pad[0x5c]; int n; };
struct Obj { char pad[0x118]; int *p; };
extern Entry D_008A05B0[];
extern Global *D_0064B47C;
extern Obj *D_0064B4B4;
extern "C" void func_00534A50();
extern "C" int func_00534A08() throw();
extern "C" int func_00531CA8() throw();
extern "C" int func_0052EAF8(signed char,int *,unsigned int,int,int,int,Msg *) throw();
extern "C" Data *func_00535C88(int *,unsigned int);
extern "C" void func_00534B90(unsigned int idx) {
    Msg m;
    if (idx < 64) {
        m.kind=1;
        m.idx=func_00534A08();
        if (m.idx != 127) {
            Obj *o=D_0064B4B4;
            if (o) {
                int *obj=o->p;
                Entry *e=D_008A05B0+(unsigned char)m.idx;
                if (obj) {
                    m.a=D_0064B47C->n;
                    func_0052EAF8(-128,obj,idx,0,1,8,&m);
                    Data *p=func_00535C88(obj,idx);
                    if (p) {
                        e->time=func_00531CA8();
                        e->cb=func_00534A50;
                        e->obj=D_0064B4B4->p;
                        e->p=p->p;
                        e->n=p->n;
                        e->z=1;
                        e->idx=idx;
                    }
                }
            }
        }
    }
}
