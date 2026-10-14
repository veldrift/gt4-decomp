struct Node { char pad0[4]; int f4; int f8; char padc[0x30 - 0xC]; int f30; unsigned int f34; int *f38tab; };
struct Node2 { char pad[0x38]; int *tab; };
struct Obj { char pad[0x104]; unsigned int id; char pad108[0x150 - 0x108]; int count; };
struct Glob { char pad[0x104]; int n; char pad108[0x118 - 0x108]; Obj *cur; char pad11c[0xE638 - 0x11C]; signed char st[1]; };
struct Other { char pad[0x5C]; unsigned int lim; };
extern Glob D_00854038;
extern Other *D_0064B47C;
extern "C" Node2 *func_00515DD8(unsigned int);
extern "C" void func_00517798(int, int, int);
extern "C" void func_005178D8(int, int);
extern "C" int func_0051B8A8(Obj *, int);

extern "C" void func_005189B0() {
    Obj *o = D_00854038.cur;
    if (o == 0) return;
    unsigned int id = o->id;
    if (id >= 0x40) return;
    for (int i = 0; i < D_00854038.n; i++) {
        if (D_00854038.st[i] != 2) continue;
        Node *nd = (Node *)func_00515DD8(i);
        if (nd == 0) continue;
        if (!(id == nd->f4 || (nd->f4 == -1 && id == nd->f8))) continue;
        unsigned int a = nd->f34;
        if (a == 0 || (nd->f30 != 0 && a + nd->f30 < D_0064B47C->lim)) {
            func_005178D8(-1, i);
        } else {
            for (int j = 0; j < o->count; j++) {
                if (func_0051B8A8(o, j) != 0) {
                    Node2 *n2 = func_00515DD8(i);
                    if (n2 != 0 && j != id && n2->tab[j] == 0) func_005178D8(j, i);
                }
            }
            func_00517798(i, 0, 0);
        }
    }
}
