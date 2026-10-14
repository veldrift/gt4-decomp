/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct V { short d, i; void (*fn)(void *, s32); };
struct W { short d, i; void (*fn)(void *); };
struct VT { char p[8]; W v8; V v10; };
struct Obj { char p[0x60]; VT *vt; };
extern "C" void func_00556380(int);
extern "C" Obj *func_00556390(void);
extern Obj *D_006182D0;
extern "C" void func_00102438(void) {
    func_00556380(1);
    Obj *o = func_00556390();
    D_006182D0 = o;
    V *a = &o->vt->v10;
    a->fn((char *)o + a->d, 0);
    W *b = &D_006182D0->vt->v8;
    b->fn((char *)D_006182D0 + b->d);
}
