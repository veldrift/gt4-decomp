/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Ent { short off; short pad; void (*fn)(void *, float); };
struct VT { char p[0x10]; Ent e; };
struct Loc { VT *vptr; int f4; };
struct Loc2 { char *vptr; Loc *owner; float a; float b; };
struct VEntA { short off; short pad; s32 (*fn)(void *, void *); };
struct VEntB { short off; short pad; s32 (*fn)(void *); };
struct Tgt { char *vtbl; };
struct Obj { char pad0[0x4C]; char *vtbl; };
extern VT D_00661718;
extern VT D_0065CE00;
extern char D_00661738[];
struct G { char pad[0xBC30]; };
extern char *D_00622F4C;
extern "C" void func_001CC130(Obj *, s32);
extern "C" s32 func_001CCFB0(Obj *, Tgt *);
extern "C" s32 func_001CCC98(Obj *, Tgt *, s32, s32, Loc2 *);
extern "C" s32 func_001CE630(Obj *, Tgt *);
extern "C" void func_00435A10(void *);

extern "C" s32 func_001CE2A8(Obj *arg0, Tgt *arg1, s32 arg2, s32 arg3, s32 arg4) {
    Loc l;
    l.vptr = &D_00661718;
    VT *fin = &D_0065CE00;
    l.f4 = arg4;
    Ent *e = &l.vptr->e;
    e->fn((char *)&l + e->off, 0.0f);
    {
        VEntA *v = (VEntA *)(arg0->vtbl + 0x38);
        v->fn((char *)arg0 + v->off, arg1);
    }
    func_001CC130(arg0, 1);
    Ent *e2 = &l.vptr->e;
    e2->fn((char *)&l + e2->off, 0x1.999998p-3f);
    s32 ok = func_001CCFB0(arg0, arg1) ^ 1;
    VEntB *vb = (VEntB *)(arg1->vtbl + 0x28);
    s32 ne = vb->fn((char *)arg1 + vb->off) != 2;
    if (ok & ne) {
        l.vptr = fin;
        return 1;
    }
    func_00435A10(D_00622F4C + 0xBC30);
    float f = 0x1.666666p-1f;
    Ent *e3 = &l.vptr->e;
    e3->fn((char *)&l + e3->off, f);
    if (func_001CE630(arg0, arg1) == 0) {
        l.vptr = fin;
        return 1;
    }
    Loc2 o;
    Loc2 *po = &o;
    po->vptr = D_00661738;
    po->owner = &l;
    po->a = f;
    po->b = 1.0f;
    s32 r = func_001CCC98(arg0, arg1, arg2, arg3, po);
    po->vptr = (char *)fin;
    l.vptr = fin;
    return r;
}
