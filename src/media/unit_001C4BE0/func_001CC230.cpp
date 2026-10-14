struct Ent { long q[8]; };
struct Ent2 { char p[0x1C]; char name[1]; };
struct Vt1 { short off; short pad; int (*fn)(void *, char *, void *, int, int); };
struct Vt2 { short off; short pad; int (*fn)(void *); };
struct Cls1 { char p[0x28]; Vt2 v28; char q[0x68 - 0x30]; Vt1 v68; };
struct Obj { Cls1 *vptr; };
extern char D_00694D88[];
extern char D_00694D90[];
extern char D_00694D98[];
extern "C" void func_0057DA20(char *, char *, char *);
extern "C" int func_0057F238(char *, char *);

extern "C" int func_001CC230(char *arg0, Obj *self, Ent *out) {
    char sp[0x50];
    Ent list[20];
    char *p24 = arg0 + 0x24;
    func_0057DA20(sp, D_00694D88, p24);
    Ent *in = list;
    Vt1 *a = &self->vptr->v68;
    int n = a->fn((char *)self + a->off, sp, (char *)in, 0, 0x14);
    Vt2 *b = &self->vptr->v28;
    if (b->fn((char *)self + b->off) != 0)
        return -1;
    int cnt = 0;
    if (n > 0) {
        do {
            char *name = (char *)in + 0x1C;
            if (func_0057F238(D_00694D90, name) != 0 && func_0057F238(D_00694D98, name) != 0) {
                cnt++;
                *out = *in;
                out++;
            }
            n--;
            in++;
        } while (n != 0);
    }
    return cnt;
}
