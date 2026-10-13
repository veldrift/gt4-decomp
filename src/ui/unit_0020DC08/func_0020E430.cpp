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

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern "C" void func_0020E640(void *);
extern "C" void func_002F6748(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" struct S00659988 *func_005C1100(void);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_005C1628(void *) throw();

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void func_0020E430(void *arg0, s32 arg1) {
    char *o = (char *)arg0;
    volatile s32 tmp[4];
    char *v1;
    char *begin;
    s32 n;

    func_0020E640(arg0);

    v1 = o + 0x10;
    begin = *(char **)(v1 + 0x4);
    n = (*(s32 *)(v1 + 0xC) - (s32)begin) >> 2;
    *(volatile s32 *)&tmp[0] = (s32)begin;
    if (begin != 0) {
        func_00326798(begin, n << 2, 4, func_005C1100()->name);
    }

    str_release((Str *)(o + 0xC));

    func_002F6748(o + 8, 2);

    str_release((Str *)o);

    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
