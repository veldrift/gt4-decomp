/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;

extern "C" int func_0035D6B0(void *arg0) throw();

static inline bool more(int i) { if (i < 3) return true; return false; }
extern "C" int func_0035D920(char *arg0) {
    f32 *p = (f32 *)(arg0 + 0x104);
    int i = 0;
    f32 sb = 0.0f;
    f32 sc = 0.0f;
    f32 *c = (f32 *)(arg0 + 0x14C);
    f32 *a = (f32 *)(arg0 + 0x648);
    f32 *b = (f32 *)(arg0 + 0x140);
    do {
        f32 x = *a++;
        f32 y = *b++;
        f32 z = *c++;
        i++;
        sb += y * x;
        sc += z * x;
    } while (more(i));
    p[0x53C / 4] = sb;
    p[0x540 / 4] = sc;
    return func_0035D6B0(arg0);
}
