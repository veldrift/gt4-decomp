/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

struct Self {
    char pad[0xF8A0];
    s32 n;
    s32 ids[1];
};
struct Car { char pad[0x5B3]; u8 rank; };

extern "C" Car *func_0034C190(void *arg0, s32 id);
extern "C" u32 func_0035E3F0(void *c);

extern "C" void DynamicsConductorFreePractice__ComputeStandings(Self *a) {
    s32 i, j;
    for (i = 1; i < a->n; i++) {
        s32 key = a->ids[i];
        for (j = i - 1; j >= 0; j--) {
            u32 s0 = func_0035E3F0(func_0034C190(a, a->ids[j]));
            if (!(func_0035E3F0(func_0034C190(a, key)) < s0)) {
                break;
            }
            a->ids[j + 1] = a->ids[j];
        }
        a->ids[j + 1] = key;
    }
    for (i = 0; i < a->n; i++) {
        func_0034C190(a, a->ids[i])->rank = i + 1;
    }
}
