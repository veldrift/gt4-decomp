/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct P4C {
    char pad0[0x30];
    void *f30;
};

struct Arg1 {
    char pad0[0x4C];
    P4C *f4C;
    char pad50[0x84 - 0x50];
    s32 f84;
};

extern char D_0065B7E0[];

struct Local {
    void *vt;
    char rest[0x58 - 4];
    ~Local() { vt = D_0065B7E0; }
};

struct Obj {
    char pad0[0xEC];
    char fEC[0x150 - 0xEC];
    s32 f150;
    char pad154[0x160 - 0x154];
    s32 f160;
    char pad164[0x178 - 0x164];
    char f178[0x188 - 0x178];
    s32 f188;
    char pad18C[0x1B4 - 0x18C];
    char f1B4[0x1D0 - 0x1B4];
    s32 f1D0;
    char pad1D4[0x1D8 - 0x1D4];
    s32 f1D8;
    char pad1DC[0x2A4 - 0x1DC];
    char f2A4[0x864 - 0x2A4];
    char f864[0x8A0 - 0x864];
    void *f8A0;
};

extern "C" void func_00154C18(void *) throw();
extern "C" void func_00154CE0(void *, void *) throw();
extern "C" void func_001564D8(Obj *, void *);
extern "C" void func_00450C48(void *);
extern "C" s32 func_00450C88(void *);
extern "C" void func_00450CB8(void *, void *);
extern "C" void func_00453480(void *, void *);
extern "C" void func_00454410(void *);
extern "C" void func_00459780(Local *, void *);
extern "C" void func_004AFD50(void *);
extern "C" void free(void *) throw();
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void func_005ADF20(s32);

extern "C" void func_00155B50(Obj *self, Arg1 *arg1) {
    char *s4 = self->fEC;
    char *s2 = self->f2A4;
    void *old;
    func_00576788(s4);
    self->f150 = 0;
    old = 0;
    P4C *p = arg1->f4C;
    if (arg1->f84 == 0) {
        void *s0 = p->f30;
        func_00454410(s0);
        self->f188 = 0;
        func_00154CE0(self->f1B4, self->f178);
        old = self->f8A0;
        self->f8A0 = s0;
        func_00450C88(s2);
        func_00453480(s2, self->f8A0);
        func_00450C48(s2);
        func_005ADF20(0);
        self->f188 = 1;
        self->f1D0 = 1;
        if (self->f1D8 != 0) {
            func_001564D8(self, self->f864);
        } else {
            Local L;
            func_00459780(&L, self->f864);
            func_00450CB8(s2, &L);
        }
    } else {
        func_004AFD50(p);
    }
    func_005767C0(s4);
    if (old != 0) {
        if (self->f160 == 0) {
            func_00154C18(self->f1B4);
        }
        free(old);
    }
}
