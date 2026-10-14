/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V { float x, y; };
struct T {
    void *vt;
    int a4;
    char pad8[0x30];
    V v;
    int i40, i44, i48, i4c;
};
extern "C" void func_00104218(T *) throw();
extern char D_00659C90[];
extern "C" int func_001049A0(T *t) {
    func_00104218(t);
    t->vt = D_00659C90;
    V *v = &t->v;
    v->y = v->x = 0.0f;
    t->i40 = 0;
    t->i44 = 0;
    t->i48 = 0;
    t->i4c = 0;
    t->a4 = 0;
}
