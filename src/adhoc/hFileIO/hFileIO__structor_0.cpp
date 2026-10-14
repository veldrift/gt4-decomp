/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};
struct Str { char *p; };
struct Self {
    char pad0[4];
    char *vt;
    char pad8[0xC];
    Str str;
    char unk18[0xEC - 0x18];
    s32 unkEC;
    s32 unkF0;
    s32 unkF4;
    s32 unkF8;
};
extern Rep D_00659FA8;
extern char hFileIO__vtable[];
extern "C" s32 hIO__structor_0(void *);
extern "C" void func_004AFE28(void *);
extern "C" char *func_005C2560(Rep *r);
extern "C" s32 func_005C15B0(s32);

extern "C" void hFileIO__structor_0(Self *arg0, s32 arg1) {
    char *d;
    Rep *r;
    Str *ps = &arg0->str;
    hIO__structor_0(arg0);
    arg0->vt = hFileIO__vtable;
    r = &D_00659FA8;
    if (r->sel != 0) {
        d = func_005C2560(r);
    } else {
        d = (char *)(r + 1);
        r->ref++;
    }
    ps->p = d;
    func_004AFE28(arg0->unk18);
    arg0->unkEC = arg1;
    arg0->unkF0 = 0;
    arg0->unkF4 = 0;
    arg0->unkF8 = 0;
    if (arg1 == 0) {
        s32 v = func_005C15B0(0x800);
        arg0->unkEC = v;
        arg0->unkF8 = 1;
    }
}
