/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct Obj { char pad0[4]; char *vtbl; };
struct Hold { Obj *p; s32 pad[3]; };
struct VE { s16 delta; s16 index; void (*fn)(void *, void *, s32, s32); };

static inline bool present(Hold *p) { return p->p != 0; }
extern char D_0083CE50[];
extern "C" void func_002F2A60(Hold *, void *) throw();
extern "C" void func_002F2A08(Hold *, s32) throw();
extern "C" void *func_002F3A48(void *);
extern "C" void *func_002F3A38(void *);
extern "C" void *func_002F3A28(void *);
extern "C" void func_0030BB18(Hold *);
extern "C" void func_003069F8(void *, Hold *, char *);
extern "C" void func_00309378(Hold *, s32);
extern "C" void func_00309CF8(void *, void *);

extern "C" void func_002F2D78(void **a0, void *a1_unused, void *a2) {
    Hold h;
    func_002F2A60(&h, a2);
    void *s0 = func_002F3A48(h.p);
    if (s0 != 0) do {
        if (func_002F3A38(s0) != 0) {
            Hold u;
            Hold *pu = &u;
            func_0030BB18(pu);
            func_003069F8(s0, pu, D_0083CE50);
            if (present(pu)) {
                VE *e = (VE *)(pu->p->vtbl + 0xA8);
                e->fn((char *)pu->p + e->delta, a0, 0, 0);
            }
            func_00309378(pu, 2);
            break;
        }
        s0 = func_002F3A28(s0);
    } while (s0 != 0);
    void *t = *a0;
    func_00309CF8(t, func_002F3A48(h.p));
    func_002F2A08(&h, 2);
}
