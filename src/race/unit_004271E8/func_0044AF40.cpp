/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef long s64;
typedef unsigned char u8;
extern "C" void func_0044AC98(void *, s32) throw();
extern "C" void func_0044ADF8(void *, void *, s32) throw();
extern "C" void func_0044AEF0(void *) throw();
extern "C" s64 func_00548918(void);
extern "C" s32 func_0057F260(const char *) throw();

extern "C" s32 func_0044AF40(s32 arg0, const char *arg1) {
    u8 ctx[0x20];
    s32 t;
    func_0044AC98(ctx, arg0);
    t = (s32)(func_00548918() + ((((s64)-0x32 << 16 | 0xAEF0) << 16) | 0xA4C0));
    func_0044ADF8(ctx, &t, 4);
    if (arg1) {
        func_0044ADF8(ctx, (void *)arg1, func_0057F260(arg1));
    }
    func_0044AEF0(ctx);
    return (ctx[4] ^ ctx[12] ^ (ctx[16] ^ ctx[8]))
         | ((ctx[5] ^ ctx[13] ^ (ctx[17] ^ ctx[9])) << 8)
         | ((ctx[6] ^ ctx[14] ^ (ctx[18] ^ ctx[10])) << 16)
         | ((ctx[7] ^ ctx[15] ^ (ctx[19] ^ ctx[11])) << 24);
}
