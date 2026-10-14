/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct E { short d; short pad; void (*fn)(void *, void *, void *); };
struct E1 { short d; short pad; s32 (*fn)(void *, void *, void *); };
struct VO { char pad[4]; char *vt; };
struct H { VO *p; char pad[12]; };
extern "C" void func_00304188(void *, void *) throw();
extern "C" void func_003041B8(void *, int) throw();
extern "C" s32 func_00304258(void *, void *) throw();
extern "C" void func_00309378(void *, s32);
extern "C" s32 func_0030BB18(void *);
extern "C" s32 *func_0030F628(void *, void *, s32);
extern "C" s32 func_0030F648(void *);

extern "C" void func_00306B08(s32 arg0, VO **arg1, void *arg2) {
    H h0;
    H h1;
    H h2;
    s32 sp30;
    s32 last;
    sp30 = arg0;
    s32 i = 0;
    func_00304188(&h0, &sp30);
    func_0030BB18(&h1);
    s32 n = func_0030F648(arg2);
    if (n > 0) {
        last = n - 1;
        do {
            E1 *e = (E1 *)(h0.p->vt + 0x198);
            char *t = (char *)h0.p + e->d;
            func_0030F628(&h2, arg2, i);
            e->fn(t, arg1, &h2);
            if (*arg1 == 0) {
                func_00309378(&h1, 2);
                func_003041B8(&h0, 2);
                return;
            }
            if (i == last) break;
            VO *o = *arg1;
            E *e2 = (E *)(o->vt + 0x48);
            i++;
            char *t2 = (char *)o + e2->d;
            func_0030BB18(&h2);
            e2->fn(t2, &h1, &h2);
            func_00309378(&h2, 2);
            func_00304258(&h0, &h1);
        } while (i < n);
    }
    func_00309378(&h1, 2);
    func_003041B8(&h0, 2);
}
