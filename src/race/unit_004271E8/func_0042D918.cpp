typedef int s32;

extern "C" void func_0042DBF0(s32 v, s32 d);

struct S42D918 {
    s32 n;
    char pad0[8];
    s32 e[1];
};

extern "C" void func_0042D918(struct S42D918 *self, s32 d) {
    s32 i = 0;
    if (self->n > 0) {
        s32 *p = self->e;
        do {
            s32 v = *p;
            s32 nv;
            i++;
            nv = (v == 0) ? 0 : v + d;
            *p = nv;
            p++;
            func_0042DBF0(nv, d);
        } while (i < self->n);
    }
}
