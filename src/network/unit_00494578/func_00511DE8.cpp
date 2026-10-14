/* compiler: ee-gcc2.96-nogcse */
struct Item { int f0; int f4; int f8; };
struct Hook { char pad[0x44]; int f44; char pad2[0xC]; int f54; char pad3[8]; int f5C; int f60; };
struct Hk { char pad[0x44]; int f44; char pad48[0xC]; void (*f54)(int, int, int); char pad58[8]; int f60; };
struct P { char pad[0x48]; char *f48; int f4C; char pad50[8]; int f58; Item *f5C; int f60p; int f64; int pad68; Hk *f6C; };
struct O { char pad[0x18]; P *f18; int f1C; int f20; Item *f24; int f28; int f2C; };
extern "C" int func_00511528(Hk *, int) throw();
extern "C" int func_00512020(void *, Item *, P *);
extern "C" int func_00512350(int, Item *);
extern "C" int func_00511DE8(O *o) {
    Item *it = o->f24;
    if (it == 0) return 3;
    P *p = o->f18;
    Item *x = p->f5C;
    P *q = p;
    if (x != 0 && x == it) {
        p->f5C = 0;
        it = o->f24;
    }
    Hk *h = q->f6C;
    o->f28 = it->f8;
    o->f2C = it->f4;
    if (h != 0) {
        h->f54(it->f0, h->f44, h->f60);
        func_00511528(h, h->f60);
        it = o->f24;
        p = o->f18;
    }
    func_00512020(p->f48 + o->f20 * 8, it, p);
    func_00512350(o->f18->f64, o->f24);
    o->f24 = 0;
    o->f18->f58--;
    return 0;
}
