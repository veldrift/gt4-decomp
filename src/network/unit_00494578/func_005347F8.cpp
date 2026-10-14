struct P8 { int x,y; };
struct Packet { P8 a,b; int x,y; };
struct Rec { int kind; char value[16]; int number; };
struct In { int valid; Rec r[2]; };
struct Res { int flag,err; };
struct Obj { char pad[0x164]; int handle; };
struct A { char pad[0x80]; void (*fn)(P8 *,void *); };
struct B { char pad[0x30]; int (*fn)(int,Packet *); };
extern A *D_0064B4B0;
extern B *D_0064B4B8;
extern int D_0064B4F0;
extern "C" void *func_005A48D8(void *,int,unsigned int);
extern "C" int func_005347F8(Obj *self, In *in, Res *res) {
    Packet p;
    P8 tmp;
    if (!res) return 0x17;
    res->err=0x1e;
    res->flag=1;
    if (!in) { res->err=0x17; return 0x17; }
    if (!in->valid) { res->err=0x26; return 0x26; }
    if (!D_0064B4F0) { res->err=0x1a; return 0x1a; }
    Rec *r=in->r;
    func_005A48D8(&p,0,24);
    unsigned int i=0;
    do {
        D_0064B4B0->fn(&tmp,r->value);
        if (r->kind==2) { p.a=tmp; p.x=r->number; }
        else if (r->kind==1) { p.b=tmp; p.y=r->number; }
        ++i; ++r;
    } while(i<2);
    if (D_0064B4B8->fn(self->handle,&p)) res->err=0x25;
    else res->err=0;
    return res->err;
}
