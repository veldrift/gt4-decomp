typedef int s32;

struct HOutput {
    s32 count;
    s32 enabled;
};

extern void (*HOutput__Handler_)(void *);

extern "C" s32 func_0057DD28(s32 arg0, s32 arg1, s32 arg2);

extern "C" void HOutput__printf(void *arg0, const char *fmt, ...) {
    __builtin_va_list ap;
    char buf[0x400];
    HOutput *self = (HOutput *)arg0;
    char *b = buf;
    char *p = b;
    __builtin_stdarg_start(ap, fmt);
    if (self->enabled != 0) {
        s32 n = self->count;
        if (n > 0) {
            do {
                n--;
                *p = 9;
                p++;
            } while (n != 0);
        }
    }
    func_0057DD28((s32)p, (s32)fmt, (s32)ap);
    HOutput__Handler_(b);
}
