/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned short u16;
struct Inner { s32 unk0; };
struct Obj { char pad0[4]; Inner *unk4; };
extern "C" int func_004BEC88(Obj *self, void *arg) throw();
extern "C" void func_004BD7B0(Obj *, char *, u16 *, s32) throw();
extern "C" s32 func_004BDD68(Obj *, s32, char *, s32, s32, u16 *, s32 *) throw();
extern "C" s32 func_004BF2D0(Obj *self, u16 a1, u16 *a2, s32 a3, u16 *out1, s32 *out2) {
    char buf[0x40];
    if (self->unk4->unk0 == 0) {
        func_004BEC88(self, (void *)1);
    }
    s32 ret;
    *out2 = 0;
    ret = 0;
    *out1 = 0;
    if (!((u16)a3 < 0x40)) return ret;
    s32 r;
    func_004BD7B0(self, buf, a2, 0);
    r = func_004BDD68(self, a1, buf, a3, 0, out1, out2);
    ret = 0x80001E72;
    if (r >= 0) ret = r;
    return ret;
}
