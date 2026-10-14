typedef int s32;
typedef long s64;
struct Ent { s64 id; char name[1]; };
extern "C" void func_00448F18(void *);
extern "C" int func_00448FF8(void *, const char *);
extern "C" s32 func_0057F260(const char *);
extern "C" int func_005A5A30(char *, unsigned, const char *, ...);
extern "C" void *exception__structor_0(s32);
extern void *D_00623800[];
extern const char *D_00623560[];
extern Ent D_006235A8;
extern char D_006A6F98[];

extern "C" s32 func_00447A78(s32 idx) {
    if (D_00623800[idx] != 0) return 1;
    {
        void *o = exception__structor_0(0x6C);
        func_00448F18(o);
        const char *base = (const char *)&D_006235A8;
        base += 8;
        const char *s = D_00623560[idx];
        D_00623800[idx] = o;
        s32 n = func_0057F260(base);
        n += func_0057F260(s);
        char *buf = (char *)__builtin_alloca(n + 0x14 & ~0xF);
        func_005A5A30(buf, n + 5, D_006A6F98, base, s);
        func_00448FF8(D_00623800[idx], buf);
    }
    return 1;
}
