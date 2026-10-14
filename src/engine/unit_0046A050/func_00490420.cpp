typedef unsigned int u32;
struct Node { int next; int key; int val; };
struct HT { Node *b[15]; int freelist; };
struct Rec { char p[0x16]; unsigned char f16; };
struct O { char p[0xC]; void *fC; Rec *f10; Rec *f14; int f18; };
extern HT D_008496D8;
extern "C" int func_00491C10(void *, int);
extern "C" u32 func_00494460(const unsigned char *);
extern "C" int func_0057F238(const char *, const char *);

static inline Rec *lookup(const char *k) {
    Node *n = D_008496D8.b[func_00494460((const unsigned char *)k) % 15];
    if (n) {
        do {
            if (func_0057F238((const char *)n->key, k) == 0) return (Rec *)n->val;
            n = (Node *)n->next;
        } while (n);
    }
    return 0;
}

extern "C" int func_00490420(O *o, const char *name) {
    Rec *r = lookup(name);
    if (r == 0) {
        r = o->f10;
        if (r == 0) return 0;
    }
    o->f14 = r;
    if (o->fC) o->f18 = func_00491C10(o->fC, r->f16);
    return 1;
}
