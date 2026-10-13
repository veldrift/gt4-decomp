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

extern "C" void func_002106E0(void *, s32 *);
extern "C" void func_00210710(void *, s32);
extern "C" void func_00265F48(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *r);

extern "C" void func_002966B8(void *arg0, s32 *arg1) {
    char *s4 = (char *)arg0;
    char **s2 = (char **)(s4 + 0x108);
    char **s3 = (char **)arg1;
    s32 buf0[4];
    s32 buf1[4];
    s32 *h;
    s32 newVal;
    s32 oldVal;

    if (s3 != s2) {
        {
            Rep *q = (Rep *)(*s2 - 0x10);
            if (--q->ref == 0) {
                s32 size = q->cap + 0x10;
                func_00326798(q, size, 4, func_005C11A8()->name);
            }
        }
        {
            char *d = *s3;
            Rep *r = (Rep *)(d - 0x10);
            if (r->sel != 0) {
                d = func_005C2560(r);
            } else {
                r->ref++;
            }
            *s2 = d;
        }
    }

    h = (s32 *)(s4 + 0x128);
    buf1[0] = 0;
    func_002106E0(buf0, buf1);
    if (h != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *h;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *h = newVal;
    }
    func_00210710(buf0, 2);
    func_00265F48(s4, 0);
}
