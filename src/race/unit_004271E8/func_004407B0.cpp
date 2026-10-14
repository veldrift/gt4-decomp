typedef int s32;
typedef long s64;
typedef unsigned char u8;
typedef signed char s8;

struct Self { char pad0[0x490]; s32 n; };

extern "C" void func_00440080(char *arg0, s32 arg1);
extern "C" s32 func_004452A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

extern "C" void func_004407B0(char *self, s64 arg1, char *arg2) {
    char *e = self + ((Self *)self)->n * 0x178;
    e += 8;
    *(s64 *)(e + 0xE8) = arg1;
    func_00440080(self, (s32)arg2);
    *(s8 *)(e + 0x156) = (s8)func_004452A8((s32)e, 1, ((u8 *)arg2)[0x119], ((u8 *)arg2)[0x116]);
}
