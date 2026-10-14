typedef int s32;

struct Elem { s32 a, b; };
struct Vec { char pad[4]; Elem *begin; Elem *end; };

extern "C" void free(void *) throw();
extern "C" void func_005C1628(void *) throw();
extern "C" void func_004768C0(Elem *);
extern "C" void func_00398A00(void *, s32);
extern "C" void RaceBGMPS2__structor_1(void *, s32);
extern "C" void ErrorEventView__structor_1(void *, s32);
extern "C" void func_003CC750(void *, s32);
extern "C" void func_003EFBB8(void *, s32);
extern "C" void RigidBodyManager__structor_1(void *, s32);
extern "C" void ParticleManager__structor_1(void *, s32);
extern "C" void func_003E74E0(void *, s32);
extern "C" void func_003B8070(void *, s32);
extern "C" void RaceBase__structor_1(void *, s32);

extern char RacePS2Base__vtable[];

extern "C" void RacePS2Base__structor_1(char *arg0, s32 arg1) {
    Elem *dead[4];
    *(char **)(arg0 + 0x64) = RacePS2Base__vtable;
    free(*(void **)(arg0 + 0xD98));
    free(*(void **)(arg0 + 0xD94));
    void *p = *(void **)(arg0 + 0xE3B0);
    dead[0] = (Elem *)p;
    if (p) free(p);
    Vec *v = (Vec *)(arg0 + 0xE350);
    Elem *b = v->begin;
    Elem *end = v->end;
    Elem *e = b;
    dead[0] = b;
    if (e != end) {
        do {
            func_004768C0(e);
            e++;
        } while (e != end);
    }
    if (v->begin) free(v->begin);
    func_00398A00(arg0 + 0xE170, 2);
    RaceBGMPS2__structor_1(arg0 + 0xCF88, 2);
    ErrorEventView__structor_1(arg0 + 0xCF68, 2);
    func_003CC750(arg0 + 0x3628, 2);
    func_003EFBB8(arg0 + 0x3624, 2);
    RigidBodyManager__structor_1(arg0 + 0x35E8, 2);
    ParticleManager__structor_1(arg0 + 0x3238, 2);
    func_003E74E0(arg0 + 0x31D0, 2);
    func_003B8070(arg0 + 0xDA0, 2);
    RaceBase__structor_1(arg0, 0);
    if (arg1 & 1) func_005C1628(arg0);
}
