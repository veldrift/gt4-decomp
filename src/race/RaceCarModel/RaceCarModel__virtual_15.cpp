/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Sub { virtual void v0(); virtual void v1(); };
struct Obj { Sub *p; int pad; virtual void v0(); virtual void v1(); virtual void v2(); };
extern char D_00844368[];
extern "C" void func_00450CB8(void *, void *);
extern "C" void RaceCarModel__virtual_15(Obj *o) {
    *(void **)((char *)o + 0x1660) = D_00844368;
    *(void **)((char *)o + 0x1664) = D_00844368;
    o->p->v1();
    func_00450CB8((char *)o + 0x18, o->p);
    o->v2();
}
