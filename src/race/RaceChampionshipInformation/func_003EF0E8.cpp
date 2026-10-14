/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Raw {char pad[0x150]; char data[0x30];};
typedef int s32;
typedef signed char s8;
typedef unsigned char u8;
typedef long long s64;

extern "C" void func_005A609C(char *arg0, s32 arg1);
extern "C" s32 func_0057F260(char *arg0) throw();
extern "C" void func_003BB440(char *arg0, s32 arg1, s32 *arg2, s32 arg3);
extern "C" void SPEC_DATABASE__RaceSpec__loadEnemyInfo(char *arg0, s64 arg1);

static inline void increment(char *base, int index) { base[index]++; }

extern "C" void func_003EF0E8(char *arg0, s32 arg1, s32 arg2) {
    if (arg2 == 0) {
        func_005A609C(arg0 + 0x130, arg1);
        char *s2 = arg0 + 0x150;
        func_005A609C(s2, arg1);
        s32 v0 = func_0057F260(s2);
        s32 k = 5;
        u8 *last=(u8 *)(arg0 + (v0 + 0x14F));
        char *p = arg0 + 0xAA0;
        increment(arg0, v0 + 0x14f);
        *(s32 *)(arg0 + 0x170) = 0;
        s32 t = ((Raw *)arg0)->data[v0 - 3] - 0x31;
        *(s32 *)(arg0 + 0x174) = t;
        *(s32 *)(arg0 + 0x174) = t + ((Raw *)arg0)->data[v0 - 4] * 10 - 0x1E0;
        do {
            k -= 1;
            *(s32 *)p = 0;
            p -= 0x188;
        } while (k >= 0);
        func_003BB440(arg0, (s32)s2, (s32 *)p, k);
        SPEC_DATABASE__RaceSpec__loadEnemyInfo(arg0, *(s64 *)(arg0 + 0x98));
    }
}
