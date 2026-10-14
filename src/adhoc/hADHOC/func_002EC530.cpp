typedef int s32;
typedef unsigned char u8;

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

struct Node {
    void (*f0)(void);
    void (*f1)(void);
    s32 pad8;
    Node *next;
};

extern s32 D_00620178[];
extern s32 D_0083C5D0;

extern "C" s32 func_00324FF0(void *arg0);
extern "C" s32 *HBuiltinModule__Get(s32 *arg0);
extern "C" void func_003041B8(void *arg0, int arg1);
extern "C" void func_003069F8(void *arg0, void *arg1, s32 arg2);
extern "C" void *func_0030D928(void *ret);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *r);

static inline void str_release(char *p) {
    Rep *q = (Rep *)(p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void func_002EC530(void *arg0) {
    s32 buf0[4];
    s32 *g = D_00620178;

    if (g[1] == 0) {
        g[1] = 1;
        Node *p = (Node *)func_00324FF0(0);
        Node *first = p;
        for (; p != 0; p = p->next) {
            p->f0();
        }
        p = first;
        for (; p != 0; p = p->next) {
            p->f1();
        }
        HBuiltinModule__Get(buf0);

        s32 *pslot = (s32 *)((char *)arg0 + 0x38);
        if ((void *)pslot != (void *)buf0) {
            s32 newVal = buf0[0];
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            s32 oldVal = *pslot;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *pslot = newVal;
        }

        func_003041B8(buf0, 2);
        func_003069F8((void *)*pslot, (char *)arg0 + 0x3C, (s32)&D_0083C5D0);

        func_0030D928(buf0);

        Str *ps = (Str *)((char *)arg0 + 0x40);
        if ((void *)buf0 != (void *)ps) {
            str_release(ps->p);
            char *v = (char *)buf0[0];
            Rep *r = (Rep *)(v - 0x10);
            if (r->sel != 0) {
                v = func_005C2560(r);
            } else {
                r->ref = r->ref + 1;
            }
            ps->p = v;
        }

        str_release((char *)buf0[0]);
    }
}
