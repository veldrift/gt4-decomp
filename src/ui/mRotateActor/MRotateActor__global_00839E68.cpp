/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Tgt { char p[0x1C]; float f1c; char q[0xC]; int f2c; };
struct Obj { Tgt *p; int pad[3]; };
struct VF { short delta; short idx; float (*fn)(void *); };
struct VI { short delta; short idx; int (*fn)(void *); };
struct Src { int a; char *v1; char *v2; };

extern "C" void func_002550B8(void *a, int b);
extern "C" void func_00255110(void *a, void *b);
extern "C" void func_002CC8C8(void *a, int b) throw();
extern "C" void func_002CC920(void *a, void *b) throw();
extern "C" void func_002CDA40(Tgt *a, int b);
extern "C" void func_002CDA98(Tgt *a, int b);
extern "C" void func_002CDAC0(Tgt *a);

extern "C" void MRotateActor__global_00839E68(void *a0, void *a1, int count, Src *src) {
    if (count >= 3) {
        Obj o;
        Obj r;
        func_002CC920(&o, a1);
        Obj *pr = &r;
        func_00255110(pr, src);
        char *s1 = src->v1;
        VF *e1 = (VF *)(*(char **)(s1 + 4) + 0x60);
        float f = e1->fn(s1 + e1->delta);
        func_002CDA40(o.p, (int)pr->p);
        o.p->f1c = f;
        o.p->f2c = 0;
        char *s2 = src->v2;
        Tgt *t = o.p;
        VI *e2 = (VI *)(*(char **)(s2 + 4) + 0x58);
        func_002CDA98(t, e2->fn(s2 + e2->delta) != 0);
        func_002CDAC0(o.p);
        func_002550B8(pr, 2);
        func_002CC8C8(&o, 2);
    }
}
