/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Rd { char pad0[0x10]; u32 f10; char pad14[0xC]; int f20; };
struct Q { int flag; int v[64]; int padq; };
struct Obj {
    int f0, f4;
    char pad8[0xA88 - 8];
    Rd rd;
    char pad_[0xDDC - 0xA88 - sizeof(Rd)];
    u32 flags;
    Q q[3];
};
extern int D_006ABCB8[];
extern "C" void func_0046D748(Obj *) throw();
extern "C" int func_0046D770(Obj *) throw();
extern "C" int func_0046E978(Rd *);
extern "C" int func_0046EA08(Rd *);

static inline void error(Obj *o, const int &code) { o->f0 = code; o->f4 = 1; }
static inline void set(Q *q, int flag) { q->flag = flag; }
extern "C" int func_0046E508(Obj *o) {
    Rd *r = &o->rd;
    u32 end = r->f10 + (func_0046EA08(r) - 2);
    for (;;) {
        int v = func_0046E978(r);
        u32 pq = (u32)v >> 4;
        u32 tq = v & 0xF;
        if (pq < 2 && tq < 3) {
            Q *q = &o->q[tq];
            set(q,1);
            int *zp;
            int i;
            if (pq == 0) {
                for (i = 0, zp = D_006ABCB8; i < 64; i++) {
                    int idx = *zp++;
                    q->v[idx] = func_0046E978(r);
                }
            } else {
                zp = D_006ABCB8;
                for (i = 63; i >= 0; i--) {
                    int idx = *zp++;
                    q->v[idx] = func_0046EA08(r);
                }
            }
            if (!func_0046D770(o)) return 0;
            if (r->f10 >= end) {
                if (r->f10 == end && r->f20 == 0) {
                    o->flags |= 2;
                    return 1;
                }
                func_0046D748(o);
                return 0;
            }
        } else {
            goto invalid;
        }
    }
invalid:
    o->f0 = 5;
    o->f4 = 1;
    return 0;
}
