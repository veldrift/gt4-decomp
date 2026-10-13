typedef int s32;
typedef short s16;

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

struct Handle {
    void *p;
    char pad[0x1C];
};

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(Str *, void *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

struct S00659988 {
    const char *name;
};

extern char D_0068FFA0[];

extern "C" void func_0015C710(void *out, void *arg);
extern "C" void func_0015C6B8(void *arg0, int flags);
extern "C" void func_002FE278(void *out, s32 value);
extern "C" void func_002FC870(void *arg0, int flags);
extern "C" s32 func_00433AA0(s32 arg0, const char *arg1);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

static inline const char *c_str(Str *s) {
    s32 len = *(s32 *)(s->p - 0x10);
    if (len == 0) return D_0068FFA0;
    s->p[len] = 0;
    return s->p;
}

extern "C" void MCourseRecord__create(s32 *out, void *arg1, s32 arg2, Obj **arg3) {
    if (arg2 > 0) {
        Handle h;
        s32 result;
        {
            Str s;
            Obj *o;
            VEntry *entry;
            Obj *lookup;

            func_0015C710(&h, arg1);
            lookup = *(Obj **)((char *)h.p + 0x10);
            o = *arg3;
            entry = (VEntry *)(o->vtbl + 0x18);
            entry->fn(&s, (char *)o + entry->delta);
            result = func_00433AA0((s32)lookup, c_str(&s)) != 0;
            str_release(&s);
            func_0015C6B8(&h, 2);
        }

        s32 newVal;
        s32 oldVal;
        func_002FE278(&h, result);
        if (out != (s32 *)&h) {
            newVal = (s32)h.p;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *out;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *out = newVal;
        }
        func_002FC870(&h, 2);
    }
}
