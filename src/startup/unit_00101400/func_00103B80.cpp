typedef int s32;
struct Base { char pad[0x64]; virtual void v0(); virtual void v1(); };
struct Obj : public Base { char pad2[0x1000]; };
extern "C" {
void func_00102840(void *);
void func_001031D0();
void func_001031F0(void *, void *);
s32 func_00103B40(const char *) throw();
void func_00498B28(void *);
char *func_00575070(s32);
void func_005788B8(void *);
void *exception__structor_0(s32);
}
extern s32 D_00618300;
extern s32 D_00618304;
extern s32 D_00618308;
extern s32 D_00618318;
extern s32 D_0061831C;
extern s32 D_006184A0;
extern const char D_0068BE40[];
extern char D_0068C080[];
extern Obj D_006DE820;

extern "C" void func_00103B80(void) {
    if (D_00618300 == 0) {
        D_00618300 = (s32)D_0068C080;
        func_00498B28(D_0068C080);
    }
    s32 *q = &D_00618304;
    if (*q == 0) {
        *q = func_00103B40(D_0068BE40);
    }
    if (D_00618308 == 0) {
        D_00618308 = func_00103B40((const char *)D_006184A0);
    }
    if (D_00618318 == 0) {
        char *t = func_00575070(0);
        s32 *p = (s32 *)&D_0061831C;
        *(void **)(t + 0x38) = (void *)func_001031D0;
        void *c = exception__structor_0(0x6C);
        func_001031F0(c, t);
        *p = (s32)c;
        *(void **)(t + 0x3C) = c;
        func_005788B8(t);
        Obj *o = &D_006DE820;
        if (o) func_00102840(o);
        D_00618318 = (s32)o;
        o->v1();
    }
}
