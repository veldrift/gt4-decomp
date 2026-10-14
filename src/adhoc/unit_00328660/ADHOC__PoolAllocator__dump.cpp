/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct VE0 { short d; short i; u32 (*fn)(void *); };
struct VE1 { short d; short i; void *(*fn)(void *, u32); };
struct VT { char pad0[0x10]; VE1 get; VE0 size; };
struct Obj { VT *vt; };

extern "C" int HOutput__printf(void *, const char *, ...);
extern "C" void *HOutput__operator_inc(void *);
extern "C" void *HOutput__operator_dec(void *);
extern "C" s32 func_00328A60(void *) throw();
extern "C" s32 func_00328A70(void *) throw();
extern "C" void ADHOC__Pool__dump(void *, void *) throw();
extern "C" double func_0057FB50(f32);
extern char D_0069EE48[];
extern char D_0069ED58[];
extern char D_0069EE60[];

extern "C" void ADHOC__PoolAllocator__dump(Obj *self, void *out) {
    u32 b = 0;
    u32 i = 0;
    u32 a = 0;
    u32 n;
    VE0 *vs = &self->vt->size;
    n = vs->fn((char *)self + vs->d);
    if (n != 0) {
        do {
            VE1 *g;
            HOutput__printf(out, D_0069EE48, i);
            HOutput__operator_inc(out);
            g = (VE1 *)((char *)self->vt + 0x10);
            ADHOC__Pool__dump(g->fn((char *)self + g->d, i), out);
            HOutput__operator_dec(out);
            HOutput__printf(out, D_0069ED58);
            g = (VE1 *)((char *)self->vt + 0x10);
            b += func_00328A60(g->fn((char *)self + g->d, i));
            g = (VE1 *)((char *)self->vt + 0x10);
            u32 j = i;
            i++;
            a += func_00328A70(g->fn((char *)self + g->d, j));
        } while (i < n);
    }
    const char *fmt = D_0069EE60;
    double ratio = func_0057FB50((f32)b / (f32)a * 100.0f);
    HOutput__printf(out, fmt, n, b, a, ratio);
}
