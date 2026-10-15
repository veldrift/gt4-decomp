/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta; short pad; void (*fn)(void *, int); };
struct Inner { int pad; char *vt; };
struct Ref { Inner *p; Inner *get() { return p; } };
struct Obj { char pad[8]; Ref out; char pad2[0x14]; int indent; };
extern "C" void func_002F7060(Inner *, const char *, __builtin_va_list);
extern "C" void func_0020ED68(Obj *o, const char *fmt, ...) {
    __builtin_va_list ap;
    for (int i = 0; i < o->indent; i++) {
        Inner *s = o->out.get();
        Entry *e = (Entry *)(s->vt + 0x1c0);
        e->fn((char *)s + e->delta, '\t');
    }
    __builtin_stdarg_start(ap, fmt);
    func_002F7060(o->out.get(), fmt, ap);
    __builtin_va_end(ap);
}
