struct Buffer { float f[16]; };
struct Out { float f[8]; };
struct Ops { char pad[0x50]; void (*fn)(Buffer *); };
extern Ops *D_0064B4B0;
extern "C" int func_00531590(Out *o) {
    if (!o) return 0x17;
    Buffer t;
    D_0064B4B0->fn(&t);
    float a=t.f[6], b=t.f[7], c=t.f[3], d=t.f[4];
    float e=t.f[12], f=t.f[13], g=t.f[9], h=t.f[10];
    o->f[2]=a; o->f[3]=b; o->f[0]=c; o->f[1]=d;
    o->f[6]=e; o->f[7]=f; o->f[4]=g; o->f[5]=h;
    return 0;
}
