/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Rec {
    char pad0[0x15];
    char name[0x11];
    char pad26[2];
    s32 unk28;
    s32 unk2C;
    char unk30;
    char text[0x3F];
};
struct Obj { char pad0[0x5A8]; Rec *unk5A8; char pad5AC[0xAF8 - 0x5AC]; char unkAF8[0x11]; };
extern "C" s32 func_004F0C88(void *) throw();
extern "C" s32 func_004F0CD0(void *, s32) throw();
extern "C" s32 func_0057F260(const char *) throw();
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" void *func_005A6AB0(void *, void *, s32) throw();
extern "C" s32 func_004F7CB8(Obj *arg0, char *arg1, s32 arg2, s32 arg3) {
    if (func_004F0C88(arg0) == 0) return 0;
    func_005A48D8(arg0->unk5A8, 0, 0x70);
    Rec *r = arg0->unk5A8;
    func_005A6AB0(r->name, arg0->unkAF8, 0x11);
    func_005A6AB0(r->text, arg1, 0x3F);
    func_0057F260(arg1);
    r->unk30 = arg3;
    r->unk2C = arg2;
    r->unk28 = (arg2 != -1);
    return func_004F0CD0(arg0, 0x1D);
}
