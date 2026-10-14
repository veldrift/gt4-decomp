/* compiler: ee-gcc2.96-no-strict-aliasing */
struct St { char p[0x1c]; float x, y, z; int a, b; };
struct Ent { int p0; char *t4; char *t8; int pC; };
struct Tab { char p[0x10]; Ent *ents; };
struct A { int f0; Tab *f4; };
extern "C" void *func_0042A918(St *s, int a, int b);
extern "C" void func_0042A958(St *s, int n);
extern "C" float func_0042A4A8(char *p, float t);
extern "C" float func_0042D430(char *p, float t);
extern "C" float func_0042C300(Ent *e, int i, St *s, float t);
extern "C" float func_0042C348(Ent *e, int i, St *s, float t, float u);

extern "C" void func_00428E08(A *self, int arg1, int arg2, int arg3, int arg4, int arg5, float *out3, float *outp, float f0, float f1) {
    St st;
    int idx;
    int sel;
    if (self->f0 != 0 && self->f4 != 0) {
        if (arg2 >= 0) {
            idx = arg2;
            sel = 1;
        } else {
            if (arg3 < 0) return;
            idx = arg3;
            sel = 0;
        }
        func_0042A918(&st, self->f0, arg3);
        st.a = arg5;
        st.b = arg4;
        Ent *e = self->f4->ents + arg1;
        float t;
        if (sel) t = func_0042D430(e->t4 + (idx << 5), f0);
        else t = func_0042A4A8(e->t8 + (idx << 5), f0);
        if (outp) *outp = t;
        if (sel) func_0042C300(e, idx, &st, t);
        else func_0042C348(e, idx, &st, t, f1);
        out3[0] = st.x;
        out3[1] = st.y;
        out3[2] = st.z;
        func_0042A958(&st, 2);
    }
}
