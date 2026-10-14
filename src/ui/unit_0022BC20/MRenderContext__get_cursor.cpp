typedef int s32;
typedef short s16;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; char pad[0xC]; };
struct S00659988 { const char *name; };
struct VEntry { s16 delta; s16 index; void (*fn)(Str *, void *); };
struct VObj { char pad0[4]; char *vtbl; };

extern "C" void func_0022ACC8(void *, s32) throw();
extern "C" void func_0022AD20(void *) throw();
extern "C" void func_00230788(void *, s32);
extern "C" void func_002308E8(s32, void *);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_00312318(void *, s32);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void MRenderContext__get_cursor(s32 *arg0, s32 unused, s32 sel, void **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    Str s2;
    Str s3;
    if (sel == 0) {
        func_0022AD20(buf0);
        func_00230788(&s2, buf0[0]);
        s32 *p1 = buf1;
        func_00314B20(p1, &s2);
        if (arg0 != p1) {
            s32 newVal = *p1;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            s32 oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_00312318(p1, 2);
        str_release(&s2);
        func_0022ACC8(buf0, 2);
    } else if (sel == 1) {
        func_0022AD20(buf0);
        s32 h = buf0[0];
        char *o = (char *)*arg3;
        VEntry *e = (VEntry *)(((VObj *)o)->vtbl + 0x18);
        e->fn(&s3, o + e->delta);
        func_002308E8(h, &s3);
        str_release(&s3);
        func_0022ACC8(buf0, 2);
    }
}
