typedef struct Iface Iface;
typedef struct Item Item;
typedef struct Cl Cl;
typedef struct ObjX ObjX;
struct Iface { char pad[0x18]; void (*f18)(int); };
struct Item { char pad[0x1C]; int f1c; char pad20[0x4C]; char t[1]; };
struct Cl { char pad[0x6C]; char t[1]; };
struct Obj { char pad0[8]; int f8; char pad0c[0x78 - 0xC]; Item *tab[2]; Item *cl; };
struct ObjX { char pad0[8]; int f8; char pad0c[0x78 - 0xC]; Item *tab[2]; Item *cl80; };
extern Iface *D_0064B4B0;
extern void *D_0064AE18;
extern ObjX *func_0051DD50();
extern int func_0051F930(Item *, void *, int, int);
extern int func_0051FD80(int);
extern int func_00538338(void *, char *, int);
extern int func_00538530(char *, int *);

extern void func_0051D060() {
    int sp[4];
    int out;
    unsigned i;
    Item *c;
    Item **pp;
    ObjX *o = func_0051DD50();
    if (o == 0) return;
    if (o->f8 == 1) return;
    if (o->f8 == 8) {
        c = o->cl80;
        if (c != 0) {
            char *t = c->t;
            out = 0;
            func_00538530(t, &out);
            if (out != 0) {
                func_0051FD80(out);
                if (func_00538338(D_0064AE18, t, out) == 0) {
                    func_0051F930(c, D_0064AE18, out, 0x2710);
                    if (func_00538530(t, &out) == 0 && out != 0) {
                        func_0051FD80(out);
                        if (func_00538338(D_0064AE18, t, out) == 0)
                            func_0051F930(c, D_0064AE18, out, 0x2710);
                    }
                }
            }
            o->f8 = 9;
            sp[0] = 0;
            ((unsigned char *)sp)[0] = 1;
            func_0051F930(c, sp, 3, 0x2710);
        }
    }
    o->f8 = 0xA;
    for (i = 0; i < 2; i++) {
        c = o->tab[i];
        if (c != 0) D_0064B4B0->f18(c->f1c);
    }
    o->f8 = 1;
}
