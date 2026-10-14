/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Args { int a, b, stride, count; char *p, *q; };
struct Desc { int x, stride, count, c, d, type; int (*callback)(Args *); };
struct Obj { unsigned char id; char pad[0x1b]; char *p, *q; };
struct Inner { char pad[0x20]; Desc *desc[64]; int offset[64]; };
struct Record { char pad[8]; Inner inner; };
extern Record D_0085C330[];
extern "C" int func_00517CE0(Desc *, char *, char *) throw();
extern "C" int func_005182D8(Obj *o, int arg, unsigned char idx) {
    if (!o) return 0;
    Record *r = &D_0085C330[o->id];
    Inner *base = &r->inner;
    if (!r) return 0;
    Desc *d = base->desc[idx];
    if (!d) return 0;
    int off = base->offset[idx];
    char *p = o->p + off;
    if (!p) return 0;
    char *q = o->q + off;
    if (!q) return 0;
    if (d->type == 5) {
        Args a;
        a.a = arg; a.b = idx; a.p = p; a.stride = d->stride; a.q = q; a.count = d->count;
        if (d->callback) return d->callback(&a);
        return 0;
    }
    for (int i=0; i<d->count; i++) {
        if (func_00517CE0(d, p, q)) return 1;
        p += d->stride;
        q += d->stride;
    }
    return 0;
}
