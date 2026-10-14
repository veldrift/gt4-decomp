/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32; typedef unsigned short u16; typedef float f32;
#define M2C_FIELD(p,t,o) (*(t)((char *)(p) + (o)))
extern "C" void func_0043A138(void *) throw();
extern "C" float func_0043BAC8(int) throw() __attribute__((const));
extern "C" void func_0043BBC0(void *, void *, void *, int) throw();
extern "C" void func_0043C4D0(void *, void *, void *, int) throw();
extern "C" void func_0043C768(void *, void *, void *, int) throw();
extern "C" void func_0043CA78(void *, void *, void *, int) throw();
extern "C" void func_0043D288(void *, void *, void *, int);
extern "C" short func_0055EF50(void *, int);
extern "C" int func_0055F048(void *, int);
extern "C" int func_0055F0A0(void *, int);
extern "C" void *func_0055F1F0(void *);
static inline int word(char *p) { return M2C_FIELD(p,u16 *,2); }
static inline int has(int v, int mask) { return (v & mask) == mask; }
static inline int modeIs(int v, int k) { return v == k; }
static inline int merge(int bits, int value) { return bits | value; }
static inline int buttons(int flags, int mask) {
    int result;
            result = 0;
            if (flags & 0x800) result |= 1;
            if (flags & 0x200) result |= 0x8000;
            if ((flags & mask) == mask) {
                result |= 0x80;
                if (flags & 0x80) result |= 0x100;
                if (flags & 0x20) result |= 0x200;
            }
            if ((flags & mask) == 0) {
                if (flags & 0x10) result |= 0x20;
                result = merge(flags & 0x40, result);
                if (flags & 0x80) result |= 4;
                if (flags & 0x20) result |= 8;
            }
            if (flags & 0x1000) result |= 0x10000;
            if (flags & 0x2000) result |= 0x20000;
            if (flags & 0x4000) result |= 0x2800;
    return result;
}
static inline void *run(char *arg0, void *arg1, char *arg2, s32 arg3, int mode2) {
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_a2_3;
    s32 temp_a2_4;
    s32 temp_a2_5;
    s32 temp_a3;
    char *temp_s0;
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_v0;
    void *temp_v0_2;
    s32 var_a2;
    s32 var_v0;
    s32 var_v1;
    int temp_a0;

    temp_s0 = arg2 + 4;
    M2C_FIELD(arg0, s32 *, 4) = (s32) M2C_FIELD(arg2, u16 *, 2);
    func_0043A138(arg1);
    int bits = func_0055F048(func_0055F1F0(arg2), 0);
    M2C_FIELD(arg1, s32 *, 0x18) |= bits;
    M2C_FIELD(arg1, f32 *, 8) = func_0043BAC8(func_0055EF50(temp_s0, 2));
    M2C_FIELD(arg1, f32 *, 0xC) = (f32) -func_0043BAC8(func_0055EF50(temp_s0, 3));
    M2C_FIELD(arg1, f32 *, 0x10) = func_0043BAC8(func_0055EF50(temp_s0, 0));
    M2C_FIELD(arg1, f32 *, 0x14) = (f32) -func_0043BAC8(func_0055EF50(temp_s0, 1));
    if ((arg3 == 0) || (arg3 == mode2)) {
        temp_a0 = word(arg2);
        temp_v0 = ((s32) temp_a0 >> 4) & 0xF;
        if (temp_v0 < 6) {
            if (__builtin_expect(temp_v0, 0)) {
                func_0043BBC0(arg0 + 0x18, arg1, arg2, arg3);
            }
        }
        var_v1 = word(arg2) & 0xF;
        switch (var_v1) {                           /* irregular */
        case 1:
            func_0043C4D0(arg0 + 0x48, arg1, arg2, arg3);
            break;
        case 2:
            func_0043C768(arg0 + 0x64, arg1, arg2, arg3);
            break;
        case 3:
            func_0043CA78(arg0 + 0x8C, arg1, arg2, arg3);
            break;
        }
    }
    switch (arg3) {
    case 1:
        func_0043D288(arg0, arg1, arg2, 1);
        break;
    case 3:
    case 4: {
            func_0043D288(arg0, arg1, arg2, arg3);
            temp_v0_2 = func_0055F1F0(arg2);
            temp_s1 = func_0055F048(temp_v0_2, 1);
            temp_s1_2 = temp_s1 | func_0055F0A0(temp_v0_2, 1);
            var_a2 = buttons(temp_s1_2, 0x400);
            M2C_FIELD(arg1, s32 *, 0x1C) |= var_a2;
        break;
        }
    }
    return arg1;
}

extern "C" void *func_0043CF90(char *a, void *b, char *c, int d) { return run(a,b,c,d,2); }
