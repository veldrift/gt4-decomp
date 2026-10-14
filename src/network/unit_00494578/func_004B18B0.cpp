/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Obj { char pad0[0xA8]; char *unkA8; char padAC[8]; char *unkB4; };
extern "C" s32 func_0057F260(const char *) throw();
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" void func_004B18B0(Obj *self, char *dst) {
    s32 a = func_0057F260(self->unkA8);
    s32 b = func_0057F260(self->unkB4);
    func_005A4724(dst, self->unkA8, a);
    dst += a;
    if (a != 0 && dst[-1] != 0x2F) {
        *dst = 0x2F;
        dst++;
    }
    func_005A4724(dst, self->unkB4, b);
    dst[b] = 0;
}
