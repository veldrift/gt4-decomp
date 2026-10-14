struct VEntry { short delta, index; int (*fn)(void *); };
struct Value { int first; VEntry *vt; };
struct Vec4 { int x,y,z,w; };
struct Data { char pad[0x1184]; Vec4 v; };
struct Input { char pad[0x10]; Data *data; };
struct Handle { void *p; char pad[12]; };
extern "C" void func_0017FAD0(Handle *, int) throw();
extern "C" void func_0017FB28(Handle *, void *) throw();
extern "C" void func_002ED5C0(Handle *, int);
extern "C" void func_002ED618(Handle *, void *);
extern "C" void func_002EEEB0(Handle *, void *, Handle *);
extern "C" void func_002EFBF0(Handle *);
extern "C" Value **HArray__operator_index(Handle *, int);
extern "C" void func_002FC870(Handle *, int);
extern "C" void func_002FE278(Handle *, int);
extern "C" void func_00309378(Handle *, int);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
static inline int get(Handle *h, int i) {
    Value *p = *HArray__operator_index(h, i);
    VEntry *v = (VEntry *)((char *)p->vt + 0x58);
    return v->fn((char *)p + v->delta);
}
static inline void store(Handle *p, const Vec4 *v) {
    ((Input *)p->p)->data->v = *v;
    func_0017FAD0(p, 2);
}
extern "C" void MOption__get_race_color_correction(void **ret, void *input, int n, void *arg) {
    union { Vec4 v; Handle h; } a;
    Handle b,c,d,e,f,g,h;
    if (n > 0) {
        func_002ED618(&b, arg);
        a.v.x = get(&b, 0);
        a.v.y = get(&b, 1);
        a.v.z = get(&b, 2);
        a.v.w = get(&b, 3);
        func_0017FB28(&c, input);
        store(&c, &a.v);
        func_002ED5C0(&b, 2);
        return;
    }
    func_0017FB28(&a.h, input);
    Data *data = ((Input *)a.h.p)->data;
    func_0017FAD0(&a.h, 2);
    func_002EFBF0(&a.h);
    Vec4 *v = &data->v;
    Handle *dest = &d;
    { void *p = a.h.p;
    func_002FE278(&e, v->x);
    func_002EEEB0(dest, p, &e);
    func_00309378(dest, 2);
    func_002FC870(&e, 2);
    }
    { void *p = a.h.p;
    func_002FE278(&f, v->y);
    func_002EEEB0(dest, p, &f);
    func_00309378(dest, 2);
    func_002FC870(&f, 2);
    }
    { void *p = a.h.p;
    func_002FE278(&g, v->z);
    func_002EEEB0(dest, p, &g);
    func_00309378(dest, 2);
    func_002FC870(&g, 2);
    }
    { void *p = a.h.p;
    func_002FE278(&h, v->w);
    func_002EEEB0(dest, p, &h);
    func_00309378(dest, 2);
    func_002FC870(&h, 2);
    }
    if (ret != &a.h.p) {
        void *p = a.h.p;
        if (p) func_003285A8(p);
        if (*ret) func_003285F8(*ret);
        *ret = p;
    }
    func_002ED5C0(&a.h, 2);
}
