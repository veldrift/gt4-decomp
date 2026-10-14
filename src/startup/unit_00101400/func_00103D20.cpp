typedef int s32;
typedef unsigned int u32;
struct Result { s32 err; s32 p4; u32 size; s32 pc; s32 pad[4]; };
extern "C" {
void *func_00103CB8(void *, void *);
void func_00103F18(s32);
s32 func_00329F50(void *, s32, const char *);
s32 func_00435FB0(void);
void func_00435FD0(void *, s32, s32);
void func_004AE6B0(Result *, void *);
s32 func_00578CF0(s32, u32);
}
extern char D_006DE8D8[];
extern s32 D_00618498, D_0061849C, D_00618310, D_00618314, PDISTD__LOCALE;
extern "C" void func_00103D20(void) {
    char path[0x10];
    char obj[0x80];
    Result r;
    if (func_00329F50(D_006DE8D8, 0x40, "RaceEndLoadingAdvertiseFile") == 0) {
        D_0061849C = D_00618498;
        return;
    }
    s32 i = 0;
    s32 n = func_00435FB0();
    u32 best = 0;
    if (n > 0) do {
        Result *rp = &r;
        s32 k = i;
        i++;
        func_00435FD0(path, 0x10, k);
        func_004AE6B0(rp, func_00103CB8(obj, path));
        if (rp->err == 0) {
            if (best < r.size) best = r.size;
        }
    } while (i < n);
    D_00618310 = best;
    if (best != 0) {
        D_00618314 = func_00578CF0(0x80, best);
        func_00103F18(PDISTD__LOCALE);
    }
}
