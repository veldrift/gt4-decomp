/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; int (*fn)(void *); };
struct Obj { void *f0; char *vtbl; };
extern "C" void func_00211408(void *, int) throw();
extern "C" void func_00211460(void *) throw();
extern "C" void func_00219030(void *, void *, int);
extern "C" void func_002292A0(void *, int);
extern "C" void func_002292F8(void *, void *);

extern "C" void MManager__unloadProject(int a0, int a1, int mode, Obj *o) {
    void *sp0[4];
    char sp10[16];
    if (mode > 0) {
        func_00211460(sp0);
        func_002292F8(sp10, o);
        int flag = 1;
        if (mode == 2) {
            Obj *c = *(Obj **)((char *)o + 4);
            VEntry *e = (VEntry *)(c->vtbl + 0x58);
            flag = e->fn((char *)c + e->delta) != 0;
        }
        func_00219030(sp0[0], sp10, flag);
        func_002292A0(sp10, 2);
        func_00211408(sp0, 2);
    }
}
