struct Item { char pad[0x14]; int *p14; };
struct G { int items[2]; int n; char pad2[4]; int a; int b; };
extern "C" Item *func_0048FB58(G *, char *);
extern "C" void func_0057DA20(char *, const char *, ...);
extern "C" int func_0048FED0(G *g, const char *name) {
    char buf[0x80];
    func_0057DA20(buf, "%s%s", "/font/", name);
    Item *it = func_0048FB58(g, buf);
    if (!g->a) g->a = it->p14[0];
    if (g->b == 0) g->b = g->a;
    g->items[g->n] = (int)it;
    g->n = g->n + 1;
    return (int)it;
}
