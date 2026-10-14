/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Ev {
    char pad0[0x18];
    s32 unk18;
    char d[0x120 - 0x1C];
};

struct Work {
    char pad0[0x1D8];
    Ev slots[16];
    char pad1[0x5B30 - 0x1D8 - 16 * 0x120];
    s32 cnt;
};

struct Sess {
    char pad0[0x5A8];
    char *work;
};

extern "C" {
s32 func_004F0B08(void *, const char *) throw();
s32 func_004F0C38(void *, const char *) throw();
void func_004F87E8(void *, s32);
}

#define NAME "GetPolicyCallback"
extern char D_00645570[];

extern "C" void func_004F1DA0(char *arg0, Sess *s)
{
    if (s == 0) {
        s = (Sess *)D_00645570;
    }
    if (func_004F0C38(s, NAME) != 0) {
        func_004F0B08(s, arg0);
        return;
    }
    s32 done = 0;
    s32 a = *(s32 *)(arg0 + 0x18);
    if (a < 0 || a == 1) {
        func_004F87E8(s, a);
        done = 1;
    }
    if (done) {
        func_004F0B08(s, arg0);
        return;
    }
    s32 n = ((Work *)s->work)->cnt++;
    if (n < 16) {
        ((Work *)s->work)->slots[n] = *(Ev *)arg0;
    }
    if (arg0[0x11C] != 0) {
        func_004F87E8(s, *(s32 *)(arg0 + 0x18));
        if (arg0[0x11C] != 0) {
            func_004F87E8(s, *(s32 *)(arg0 + 0x18));
            func_004F0B08(s, arg0);
        }
    }
}
