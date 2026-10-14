/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

extern Rep D_00659FA8;

extern "C" void func_002F54A8(void *arg0, int arg1) throw();
extern "C" void func_002F5500(void *arg0, void *arg1) throw();
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *r);

struct Str {
    char *p;
    char pad[0xC];
    Rep *rep() const { return (Rep *)(p - 0x10); }
    void release() {
        Rep *q = rep();
        if (--q->ref == 0) {
            s32 size = q->cap + 0x10;
            func_00326798(q, size, 4, func_005C11A8()->name);
        }
    }
    Str() {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            s32 n = r->ref + 1;
            r->ref = n;
        }
        p = d;
    }
    Str(const Str &o);
    ~Str() { release(); }
    Str &operator=(const Str &rhs) {
        if (&rhs != this) {
            release();
            Rep *q = rhs.rep();
            char *d;
            if (q->sel != 0) {
                d = func_005C2560(q);
            } else {
                d = (char *)(q + 1);
                s32 n = q->ref + 1;
                q->ref = n;
            }
            p = d;
        }
        return *this;
    }
};

extern "C" void func_002F5DA8(void *self, Str *src);

struct VEntry {
    s16 delta;
    s16 index;
    Str (*fn)(char *);
};

struct Vobj {
    char pad0[4];
    char *vt;
};

struct H {
    void *p;
    char pad[0xC];
};

extern "C" void Exception__global_0083D2C8(void *arg0, void *arg1, s32 arg2, Vobj **arg3) {
    Str s;
    if (arg2 == 1) {
        Vobj *o = *arg3;
        VEntry *e = (VEntry *)(o->vt + 0x18);
        s = e->fn((char *)o + e->delta);
    }
    {
        H t;
        H *pt = &t;
        func_002F5500(pt, arg1);
        func_002F5DA8(pt->p, &s);
        func_002F54A8(pt, 2);
    }
}
