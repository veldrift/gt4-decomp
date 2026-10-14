/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Link { short next; short pad; const char *text; };
struct Table { union { Link links[1]; struct { int pad[2]; int head; int free; int x; int y; } h; } u; };
extern char D_00623838[];
extern char D_006A2620[];
extern "C" void func_001056A0(void *);
extern "C" void func_004AB040(int);
extern "C" void func_0044D9B8(void *, const char *);
extern "C" void func_0044DF20(void *, float, float, float, float);
extern "C" void func_0044DC50(void *, int, int);
extern "C" void func_0044E088(void *, const char *, ...);
extern "C" void func_003B72F8(Table *t, void *a) {
    func_001056A0(a);
    func_004AB040(5);
    func_004AB040(8);
    func_0044D9B8(D_00623838, D_006A2620);
    func_0044DF20(D_00623838, 0.8f, 0.8f, 0.8f, 0.8f);
    int x = t->u.h.x;
    int i = t->u.h.head;
    int y = t->u.h.y;
    while (i >= 0) {
        Link *e = &t->u.links[i];
        int old_y = y;
        y += 18;
        func_0044DC50(D_00623838, x, old_y);
        func_0044E088(D_00623838, e->text);
        i = e->next;
    }
}
