/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;
struct Ent { short off; short pad; s32 (*fn)(void*); };
struct VT { char p[0x64]; char *tbl; };
struct Obj { char p[0x64]; char *vt; };
struct S { char p0[0x58]; void *u58; char p5c[0x4C]; Obj *uA8; char pAC[0x174]; };
extern char D_00693E70[];
extern char *D_00622F4C_;
extern "C" void func_00109A28(void *, void *);
extern "C" int GranTurismo4__MenuGameObject__startProject(void *, char *, void *);
extern "C" void func_001C85E0(void *);
extern "C" void func_001C8778(void *, int);
extern "C" void func_0042F448(void *, void *, int, unsigned char, unsigned char, int);
extern "C" void func_0044CA98(int, int, int, int);
extern "C" void func_0044CB10();
extern "C" void func_0055F9F8(void *);
extern "C" void func_0055FA30(void *, s32);
extern char *D_00622F4C;

extern "C" int func_001C79A8() {
    S sp;
    char sp220[0x40];
    func_0044CA98(0x30000, 2, 1, 0xB00000);
    func_001C85E0(&sp);
    func_0055F9F8(sp220);
    Obj *o;
    sp.u58 = sp220;
    o = sp.uA8;
    Ent *e = (Ent *)(o->vt + 0x4A8);
    func_00109A28(&sp, (void *)e->fn((char *)o + e->off));
    int r = GranTurismo4__MenuGameObject__startProject(&sp, D_00693E70, sp.pAC);
    char *g = D_00622F4C;
    func_0042F448(g + 0x568, g + 4, 5, 0xF, 0xE, 0x157529FF);
    func_0055FA30(sp220, 2);
    func_001C8778(&sp, 2);
    func_0044CB10();
    return r;
}
