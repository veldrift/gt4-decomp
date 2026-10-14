/* compiler: ee-gcc2.96-nogcse */
typedef int s32;
struct H { s32 p; s32 pad[3]; };
struct Vec { char pad[4]; s32 *begin; s32 *end; };
struct Self { char pad[0x10]; Vec v; };
extern "C" void func_00309360(void *, void *);
extern "C" void func_00309378(void *, s32);
extern "C" void func_0030BB18(void *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);

extern "C" H *func_002EED68(H *out, Self *self) {
    Vec *v = &self->v;
    if (v->begin != v->end) {
        H tmp;
        func_00309360(&tmp, v->begin);
        s32 *pos = v->begin;
        s32 *src = pos + 1;
        if (src != v->end) {
            s32 *s = src;
            s32 *d = pos;
            s32 n = v->end - s;
            while (n > 0) {
                if (d != s) {
                    s32 nv = *s;
                    if (nv) func_003285A8(nv);
                    if (*d) func_003285F8(*d);
                    *d = nv;
                }
                n--;
                s++;
                d++;
            }
        }
        v->end = v->end - 1;
        func_00309378(v->end, 2);
        func_00309360(out, &tmp);
        func_00309378(&tmp, 2);
    } else {
        func_0030BB18(out);
    }
    return out;
}
