/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short adj; short pad; int (*fn)(char *, int, int); };
struct VE2 { short adj; short pad; int (*fn)(char *, int); };
struct VT { char pad[0x38]; VE2 e38; VE e40; };
struct Obj { char pad[0xA4]; VT *vt; };
struct Node { Obj *obj; int pad; Node *next; };
extern Node *D_006318B0;
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern char D_00631880[];
extern "C" int func_004ACE58(int a0, int a1) {
    int r = 0;
    Node *n;
    func_00576788(D_00631880);
    n = D_006318B0;
    if (n != 0) {
        do {
            Obj *o = n->obj;
            VE2 *e = &o->vt->e38;
            if (e->fn((char *)o + e->adj, a0) != 0) {
                VE *e2 = &o->vt->e40;
                r = e2->fn((char *)o + e2->adj, a0, a1);
                break;
            }
            n = n->next;
        } while (n != 0);
    }
    func_005767C0(D_00631880);
    return r;
}
