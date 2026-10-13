typedef int s32;

struct Entry { s32 pad; void (*fn)(s32, s32); };
extern char D_006ADC80[];
extern char D_006ADCA0[];
extern char D_00624800[];

extern "C" void *func_00606DD8(void *arg0, char *arg1, int arg2);
extern "C" void func_0057D9C0(const char *fmt, ...);

static inline const char *c_str(void **p) {
    s32 len = *(s32 *)((char *)*p - 0x10);
    if (len == 0)
        return D_006ADC80;
    ((char *)*p)[len] = 0;
    return (char *)*p;
}

extern "C" s32 func_0047C970(s32 *arg0, void **arg1, s32 arg2) {
    Entry *e = (Entry *)func_00606DD8((void *)c_str(arg1), D_00624800, 1);
    if (e) {
        e->fn(*arg0, arg2);
        return 1;
    }
    func_0057D9C0(D_006ADCA0, c_str(arg1));
    return 0;
}
