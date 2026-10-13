typedef int s32;
typedef float f32;

struct S;
struct C;

struct Obj {
    S *p;
    char pad[0x24];
    s32 n;
};

extern "C" s32 func_0025C2A0(S *arg0);
extern "C" void func_0025BA38(struct C *arg0, int arg1, int arg2);

extern "C" s32 func_0026EEF8(void *arg0, Obj *arg1, Obj *arg2) {
    f32 f[4];
    s32 s0;
    s32 s1;

    s0 = func_0025C2A0(arg1->p);
    s1 = func_0025C2A0(arg2->p);
    if (s0 != s1) {
        func_0025BA38((struct C *)s0, (int)&f[0], (int)&f[1]);
        func_0025BA38((struct C *)s1, (int)&f[2], (int)&f[3]);
        if (f[1] < f[3]) return 1;
        if (f[3] < f[1]) return 0;
        if (f[0] < f[2]) return 1;
        if (f[2] < f[0]) return 0;

        func_0025BA38((struct C *)arg1->p, (int)&f[0], (int)&f[1]);
        func_0025BA38((struct C *)arg2->p, (int)&f[2], (int)&f[3]);
        if (f[1] < f[3]) return 1;
        if (f[3] < f[1]) return 0;
        if (f[0] < f[2]) return 1;
        if (f[2] < f[0]) return 0;
    } else {
        s32 n1 = arg1->n;
        s32 n2 = arg2->n;
        if (n1 < n2) return 1;
        if (n2 < n1) return 0;
    }
    return (unsigned int)arg1->p < (unsigned int)arg2->p;
}
