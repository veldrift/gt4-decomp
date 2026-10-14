/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct B20 { char d[0x20]; };
struct Rec {
    char pad0[0x15];
    char name[0x11];
    char pad26[2];
    s32 unk28;
    char unk2C;
    B20 blob;
};
struct Obj { char pad0[0x5A8]; Rec *unk5A8; char pad5AC[0xAF8 - 0x5AC]; char unkAF8[0x11]; };
extern "C" s32 func_004F0C88(void *) throw();
extern "C" s32 func_004F0CD0(void *, s32) throw();
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" void *func_005A6AB0(void *, void *, s32) throw();
extern "C" s32 func_004F2448(Obj *arg0, B20 *arg1) {
    if (func_004F0C88(arg0) == 0) return 0;
    func_005A48D8(arg0->unk5A8, 0, 0x50);
    Rec *r = arg0->unk5A8;
    func_005A6AB0(r->name, arg0->unkAF8, 0x11);
    r->unk28 = 2;
    r->unk2C = 0x20;
    r->blob = *arg1;
    return func_004F0CD0(arg0, 0xD);
}
