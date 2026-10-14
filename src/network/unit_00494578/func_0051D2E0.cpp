struct N { int pad; int active; };
struct Sub { char pad[0x28]; char timer[8]; int enabled; };
struct Context { int state; char pad[0x6C]; N *arr[2]; Sub *sub; };
struct O { int a, b; Context ctx; };
struct V { char pad[0x64]; void (*f64)(); };
extern V *D_0064B4B0;
extern "C" int func_0051D448(O *);
extern "C" int func_0051D538(O *, N *);
extern "C" int func_0051FAF8(N *);
extern "C" int func_0051E378(O *, N *);
extern "C" void func_0053A890(void *, unsigned int *);
extern "C" int func_0051D2E0(O *o, int arg1) {
    int r;
    int state = o->ctx.state;
    if (state == 2) {
        r = func_0051D448(o);
        if (r != 0) return r;
        if (o->ctx.state == state) return r;
    }
    unsigned int i = 0;
    Context *ctx = &o->ctx;
    N **pp = o->ctx.arr;
    N *p;
    do {
        p = *pp++;
        if (p && p->active) {
            r = func_0051D538(o, p);
            if (r != 0) return r;
        }
        i++;
    } while (i < 2);
    pp = ctx->arr;
    i = 0;
    D_0064B4B0->f64();
    do {
        p = *pp++;
        if (p && p->active) {
            r = func_0051FAF8(p);
            if (r != 0) return r;
            if (arg1) {
                r = func_0051E378(o, p);
                if (r != 0) return r;
            }
        }
        i++;
    } while (i < 2);
    if (o->ctx.state == 8) {
        Sub *sub = o->ctx.sub;
        if (sub->enabled) {
            unsigned int elapsed = 0;
            func_0053A890(sub->timer, &elapsed);
            if (elapsed >= 30001) return 0xCB2E;
        }
    }
    return 0;
}
