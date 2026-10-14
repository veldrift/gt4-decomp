/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Blob {
    char pad0[0x98];
    s32 unk98;
};

struct Sess;

struct W {
    char pad0[4];
    s32 unk4;
    Blob blob;
    char pad8[0xA4 - 8 - 0x9C];
    void (*f_A4)();
    Sess *s_A8;
    void (*f_AC)();
    Sess *s_B0;
    void (*f_B4)();
    Sess *s_B8;
    void (*f_BC)();
    Sess *s_C0;
    void (*f_C4)();
    Sess *s_C8;
};

struct Sess {
    char pad0[0x5A8];
    W *work;
    char pad5AC[0x218C - 0x5AC];
    Blob blob;
};

extern "C" {
s32 func_004F0C88() throw();
s32 func_004F0CD0(void *, s32) throw();
s32 func_00533650(void *);
void *func_005A48D8(void *, int, unsigned int);
void func_004F70D0();
void func_004F70F8();
void func_004FAC58();
void func_004FACC8();
void func_004F7118();
}

extern "C" s32 func_004F6480(Sess *s)
{
    if (func_004F0C88() != 0) {
        W *w;
        func_005A48D8(s->work, 0, 0x13C);
        w = s->work;
        func_00533650(w);
        w->unk4 = 6;
        w->blob = s->blob;
        w->f_A4 = func_004F70D0;
        w->f_AC = func_004F70F8;
        w->f_B4 = func_004FAC58;
        w->f_BC = func_004FACC8;
        w->f_C4 = func_004F7118;
        w->s_A8 = s;
        w->s_B0 = s;
        w->s_B8 = s;
        w->s_C0 = s;
        w->s_C8 = s;
        return func_004F0CD0(s, 0x30);
    }
}
