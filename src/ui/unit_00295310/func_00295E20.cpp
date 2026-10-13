typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

extern "C" void func_002106E0(void *arg0, s32 *arg1);
extern "C" void func_00210710(void *arg0, int arg1);
extern "C" void func_00265F48(void *arg0, s32 arg1);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *r);

extern "C" void func_00295E20(char *arg0, char **arg1) {
    s32 buf0[4];
    s32 sp10;
    s32 newVal;
    s32 oldVal;
    s32 *dst;
    char *self = arg0;
    char **s2 = (char **)(self + 0xF4);

    if ((void *)arg1 != (void *)s2) {
        Rep *q = (Rep *)(*s2 - 0x10);
        if (--q->ref == 0) {
            s32 size = q->cap + 0x10;
            func_00326798(q, size, 4, func_005C11A8()->name);
        }
        char *v = *arg1;
        Rep *r = (Rep *)(v - 0x10);
        if (r->sel != 0) {
            v = func_005C2560(r);
        } else {
            r->ref++;
        }
        *s2 = v;
    }

    dst = (s32 *)(self + 0x114);
    sp10 = 0;
    func_002106E0(buf0, &sp10);
    if ((void *)dst != (void *)buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *dst;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *dst = newVal;
    }
    func_00210710(buf0, 2);
    func_00265F48(self, 0);
}
