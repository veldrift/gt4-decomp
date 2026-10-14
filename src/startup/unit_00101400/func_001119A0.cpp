typedef int s32;
struct VEnt { short adj; short pad; void (*fn)(void *); };
struct Vt { char pad[0x2C0]; VEnt e; };
struct Sub { s32 f0; char pad[0xDC - 4]; s32 fDC; };
struct Self {
    char pad[0x64]; Vt *vt; char pad1[4]; s32 sub;
    char pad2[0xD48 - 0x70]; s32 fD48;
};
#define SUB(a) ((Sub *)(a)->sub)
extern char D_0068D3B8[];
extern "C" void func_0010FE40(void *);
extern "C" void func_0012BFC0(int);
extern "C" void func_0012BFD0(int);
extern "C" void func_00387EF0(void *, int, int);

extern "C" void func_001119A0(Self *arg0) {
    s32 one = 1;
    Sub *s = SUB(arg0);
    s->fDC = one;
    s32 saved = s->f0;
    SUB(arg0)->f0 = 0;
    arg0->fD48 = one;
    func_00387EF0(arg0, 4, 1);
    func_0012BFC0((int)arg0);
    func_0012BFD0(1);
    func_0010FE40(D_0068D3B8);
    func_0012BFC0(0);
    VEnt *e = &arg0->vt->e;
    e->fn((char *)arg0 + e->adj);
    arg0->fD48 = 0;
    SUB(arg0)->fDC = 0;
    SUB(arg0)->f0 = saved;
}
