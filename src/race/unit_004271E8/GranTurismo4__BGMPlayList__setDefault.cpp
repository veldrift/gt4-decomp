/* compiler: ee-gcc2.96-no-strict-aliasing */
struct LEnt { int pad; int key; char pad2[0x10]; };
struct List { LEnt *data; unsigned count; int x; };
struct Ent { long long id; char t8; char t9; signed char a; signed char b; char pad[4]; };
struct Obj { int n; int pad0; short s8; char pad[6]; Ent e[128]; };
extern "C" void *func_00461E50(void *, int);
extern "C" short func_00579358();
extern "C" long long func_0044FEC0(int);
extern "C" void func_00437E98(Obj *, signed char);

extern "C" void GranTurismo4__BGMPlayList__setDefault(Obj *o, int s) {
    List l;
    func_00461E50(&l, 0xC);
    unsigned i;
    if (s == 0) {
        i = 0;
        o->s8 = func_00579358();
    } else {
        o->s8 = s;
        i = 0;
    }
    for (i = 0; i < 128; i++) {
        o->e[i].t8 = 0;
        o->e[i].t9 = 1;
        o->e[i].id = 0;
        o->e[i].a = -1;
        o->e[i].b = -1;
    }
    o->n = 0;
    for (i = 0; i < l.count; i++) {
        int key = l.data[i].key;
        Ent *p = &o->e[o->n];
        p->id = func_0044FEC0(key);
        p->t9 = 1;
        p->a = (unsigned char)o->n;
        p->b = (unsigned char)o->n;
        o->n++;
    }
    func_00437E98(o, 0);
}
