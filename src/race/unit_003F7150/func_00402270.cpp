/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta, index; int (*fn)(void *); };
struct Obj { char *vt; };
struct Type { char pad[2]; unsigned char type; };
struct Data { char pad[0x6A]; unsigned short type; };
extern "C" void func_00386608(int *, int);
extern "C" Type *func_0038DC18(Obj *);
extern "C" Data *func_0038DC00(Obj *);
extern "C" int func_00402270(Obj *p, int arg1) {
    int sp;
    func_00386608(&sp, arg1);
    int result = 0;
    if (func_0038DC18(p)) {
    Entry *e = (Entry *)(p->vt + 0x180);
    if (e->fn((char *)p + e->delta)) return 1;
    Type *t = func_0038DC18(p);
    if (t && t->type == 15) return 2;
    Data *d = func_0038DC00(p);
    if (d) {
        int type = d->type;
        if (type == 3) return 3;
        if (type == 4) return 4;
        if (type == 5) return 5;
    }
    }
    return result;
}
