/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Net { char pad[0x50]; char *data; };
struct Obj { int x; char *vt; char pad[0x260]; Net *net; };
struct StrEntry { short delta, index; void (*fn)(void *, const char *); };
struct IntEntry { short delta, index; void (*fn)(void *, int); };
extern "C" int func_0057F260(const char *) throw();
extern "C" int func_0057F238(const char *, const char *) throw();
extern "C" int func_004ED570(Net *);
extern char D_0069A580[];
struct RetEntry { short delta, index; int (*fn)(void *, int); };
extern "C" int func_00275830(Obj *o) {
    { const char *value = o->net->data + 0x300; StrEntry *e = (StrEntry *)(o->vt + 0x208); e->fn((char *)o + e->delta, value); }
    { const char *value = o->net->data + 0x400; StrEntry *e = (StrEntry *)(o->vt + 0x218); e->fn((char *)o + e->delta, value); }
    { const char *value = o->net->data + 0x500; StrEntry *e = (StrEntry *)(o->vt + 0x228); e->fn((char *)o + e->delta, value); }
    { const char *value = o->net->data + 0x600; StrEntry *e = (StrEntry *)(o->vt + 0x238); e->fn((char *)o + e->delta, value); }
    { const char *value = o->net->data + 0x700; StrEntry *e = (StrEntry *)(o->vt + 0x248); e->fn((char *)o + e->delta, value); }
    { const char *value = o->net->data + 0xB00; StrEntry *e = (StrEntry *)(o->vt + 0x268); e->fn((char *)o + e->delta, value); }
    { const char *value = o->net->data + 0xC00; StrEntry *e = (StrEntry *)(o->vt + 0x278); e->fn((char *)o + e->delta, value); }
    { int value = (unsigned char)o->net->data[0x1325] == 1; IntEntry *e = (IntEntry *)(o->vt + 0x1D8); e->fn((char *)o + e->delta, value); }
    { int value = (unsigned char)o->net->data[0x1320] == 1; IntEntry *e = (IntEntry *)(o->vt + 0x198); e->fn((char *)o + e->delta, value); }
    if (func_0057F260(o->net->data + 0x600) && func_0057F238(o->net->data + 0x600, D_0069A580)) {
        IntEntry *e = (IntEntry *)(o->vt + 0x1A8); e->fn((char *)o + e->delta, 0);
    } else {
        IntEntry *e = (IntEntry *)(o->vt + 0x1A8); e->fn((char *)o + e->delta, 1);
    }
    int n = func_004ED570(o->net);
    RetEntry *e = (RetEntry *)(o->vt + 0x288);
    return e->fn((char *)o + e->delta, n);
}
