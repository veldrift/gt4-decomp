/* compiler: ee-gcc2.96-as2004 */
typedef int s32;
typedef unsigned int u32;
typedef unsigned long long T __attribute__((aligned(4)));
struct Vt {
    char pad0[0x74];
    s32 (*f74)(unsigned long long, T);
};
struct Arg1 { T unk0; s32 unk8; };
extern Vt *D_0064B4B0;
extern "C" s32 func_00529320(void *, void *, void *, s32 *);
extern "C" s32 func_00527D38(s32 *arg0, Arg1 *arg1, s32 *arg2) {
    volatile unsigned long long sp0[2];
    s32 sp10;
    s32 *p = arg0 + 1;
    u32 i = 0;
    do {
        s32 v = *p;
        if (v != 0) {
            s32 r = func_00529320((void *)*arg0, (void *)v, (void *)sp0, &sp10);
            if (r != 0) return r;
            unsigned long long a = sp0[0];
            T b = arg1->unk0;
            if (D_0064B4B0->f74(a, b) != 0) {
                if (sp10 == arg1->unk8) {
                    *arg2 = *p;
                    *p = 0;
                    return 0;
                }
            }
        }
        i++;
        p++;
    } while (i < 0x20);
    return 0;
}
