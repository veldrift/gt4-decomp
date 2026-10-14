/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Ref {
    s32 p;
};

struct Entry {
    Ref r;
    s32 a;
    s32 b;
    s32 c;
    float f;
};

struct Vec {
    s32 pad0;
    Ref *begin;
    Ref *end;
};

struct EVec {
    s32 pad0;
    Entry *begin;
    Entry *end;
    Entry *cap;
};

struct Self {
    char pad0[0x68];
    Vec v;
    char pad74[0x78 - 0x74 - 0];
    EVec ev;
};

extern "C" s32 func_0021B328(void *dst, void *src);
extern "C" void func_0021B340(void *r, int n);
extern "C" void func_005C9E38(void *vec, void *pos, void *val);

extern "C" void func_001540C8(Self *self, Ref *r, s32 idx, s32 a3, s32 a4, float f) {
    Vec *v = &self->v;
    EVec *ev = &self->ev;
    Entry e;
    Ref tmp;
    s32 n = v->end - v->begin;
    if (!(idx < n)) {
        idx = 0;
    }
    func_0021B328(&tmp, r);
    func_0021B328(&e.r, &tmp);
    e.a = idx;
    e.b = a3;
    e.c = a4;
    e.f = f;
    if (ev->end != ev->cap) {
        Entry *dst = ev->end;
        if (dst != 0) {
            func_0021B328(&dst->r, &e.r);
            dst->a = e.a;
            dst->b = e.b;
            dst->c = e.c;
            dst->f = e.f;
        }
        ev->end = ev->end + 1;
    } else {
        func_005C9E38(ev, ev->end, &e);
    }
    func_0021B340(&e.r, 2);
    func_0021B340(&tmp, 2);
    func_0021B340(r, 2);
}
