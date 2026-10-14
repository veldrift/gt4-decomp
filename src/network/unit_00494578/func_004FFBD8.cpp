/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Context { char pad[0xF70]; char flag; };
extern Context D_00645570;
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" int func_005A6AB0(void *, const void *, int) throw();
extern "C" int func_00505B88(void *);
extern "C" int func_004FFBD8(const void *src, Context *ctx) {
    char buf[0x68];
    if (!ctx) ctx = &D_00645570;
    func_005A48D8(buf, 0, 0x68);
    func_005A6AB0(buf, src, 0x15);
    buf[0x15] = ctx->flag ? -12 : 0;
    buf[0x16] = 0;
    return func_00505B88(buf) == 0 ? 0 : -12;
}
