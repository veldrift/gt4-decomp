typedef int s32;
typedef float f32;
struct CM { char pad0[0x48]; char *vptr; s32 f4C; s32 f50; s32 f54; s32 f58; };
struct VE { short delta; short idx; void (*fn)(void *, void *, void *); };
extern char CompatibleModel__vtable[];
extern "C" int MModel__structor_0(void *);
extern "C" void MModel__structor_1(void *, s32);
extern "C" void func_0021A768(void *, void *);
extern "C" void func_0021A7A0(void *, s32);
extern "C" void func_0021A7B0(void *, s32);
extern "C" void func_0021A7C0(void *, void *);
extern "C" void func_0021A7D0(void *, s32);
extern "C" void func_0021A7F0(void *, f32);
extern "C" void func_0021A800(void *, s32);
extern "C" void func_0021A810(void *, s32);

extern "C" void CompatibleModel__structor_0(char *self, s32 *p, void *a2, void *a3, s32 t0, s32 t1, s32 t2, s32 t3,
                              s32 s0a, s32 s1a, s32 s10, s32 s18, s32 s20, f32 f0, f32 f1) {
    CM A;
    CM B;
    MModel__structor_0(&A);
    A.f58 = s1a;
    A.f54 = s0a;
    A.vptr = CompatibleModel__vtable;
    A.f4C = t2;
    A.f50 = t3;
    func_0021A768(&A, a2);
    func_0021A7C0(&A, a3);
    func_0021A7A0(&A, t0);
    func_0021A7B0(&A, t1);
    func_0021A7D0(&A, *p);
    func_0021A7F0(&A, f0);
    func_0021A800(&A, s10);
    func_0021A810(&A, ((s32 *)a3)[1]);
    MModel__structor_0(&B);
    B.vptr = CompatibleModel__vtable;
    B.f4C = t2;
    B.f50 = t3;
    B.f54 = s18;
    B.f58 = s20;
    func_0021A7F0(&B, f1);
    {
        VE *e = (VE *)(*(char **)(self + 4) + 0x208);
        e->fn(self + e->delta, &A, (s18 != 0 && f1 >= 0.02f) ? &B : 0);
    }
    B.vptr = CompatibleModel__vtable;
    MModel__structor_1(&B, 0);
    A.vptr = CompatibleModel__vtable;
    MModel__structor_1(&A, 0);
}
