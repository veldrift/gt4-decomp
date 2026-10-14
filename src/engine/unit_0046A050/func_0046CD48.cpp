/* compiler: ee-gcc2.96-nogcse */
struct Ent { short adj; short pad; void (*fn)(void *, int); };
struct VTab { char pad[8]; Ent e; };
struct A { char p[0x20]; VTab *v; };
struct B { char p[0x104]; VTab *v; };
extern "C" {
void func_0046CE70(void *);
void func_0046E7E8(void *, int);
void func_0046F5C8(void *, int);
void func_0046F5C8_(void *, int);
int func_005C1628(void *) throw();
}
extern char D_00688900[];
extern "C" int func_0046CD48(char *o, int flags)
{
    char *base = o + 0xDE0;
    *(char **)(o + 0x11D0) = D_00688900;
    func_0046CE70(o);
    if (base != (char *)-0x318) {
        char *t = o + 0x10F8;
        char *p = o + 0x11D0;
        if (t != p) {
            char *end = t;
            do {
                p -= 0x24;
                Ent *e = &((A *)p)->v->e;
                e->fn(p + e->adj, 2);
            } while (end != p);
        }
    }
    if (base != 0) {
        char *q = base + 0x318;
        if (base != q) {
            do {
                q -= 0x108;
                Ent *e = &((B *)q)->v->e;
                e->fn(q + e->adj, 2);
            } while (base != q);
        }
    }
    char *m = o + 8;
    func_0046E7E8(o + 0xA88, 2);
    func_0046F5C8(m, 2);
    if (flags & 1) return func_005C1628(o);
}
