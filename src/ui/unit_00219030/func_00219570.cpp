typedef int s32;
typedef unsigned int u32;

struct Obj1 { char pad[0xD4]; s32 fD4; };
struct Self { char pad[0x20]; Obj1 *f20; char pad24[4]; };
struct H { s32 v; char pad[0xC]; };

extern "C" void *func_00326750(u32, int, const char *);
extern "C" void mUpdateContextPS2__structor_0(void *) throw();
extern "C" s32 func_0024E348(void *, void *);
extern "C" void func_0024E378(void *, int);
extern "C" void func_002EA590(void *, int);
extern "C" s32 func_002EC370(void *, s32);
extern "C" void func_002ECDE0(void *);
extern "C" void func_003041B8(void *, int);
extern "C" void *func_00306638(void *, s32, void *);
extern "C" void func_00323B60(void *, int);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern char D_00697970[];

extern "C" void func_00219570(Self *self, s32 arg1) {
    H a;
    H b;
    H c;
    s32 *p = &c.v;
    void *o = func_00326750(0x434, 4, D_00697970);
    mUpdateContextPS2__structor_0(o);
    *(void **)&c = o;
    func_0024E348(&a, p);
    p = (s32 *)&self->f20;
    if (p != &a.v) {
        s32 nv = a.v;
        if (nv != 0) func_003285A8(nv);
        if (*p != 0) func_003285F8(*p);
        *p = nv;
    }
    func_0024E378(&a, 2);
    H *pb = &b;
    ((Obj1 *)*p)->fD4 = arg1;
    func_002ECDE0(pb);
    func_002EC370(&a, pb->v);
    func_002EA590(pb, 2);
    func_00306638(pb, a.v, (char *)self + 0x24);
    func_00323B60(pb, 2);
    func_003041B8(&a, 2);
}
