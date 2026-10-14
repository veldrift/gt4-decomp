typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Node { Node *a; Node *b; Node *c; Node *d; };
struct Tree { char pad0[4]; Node *head; Node *size; u8 flag; Node *key; char padz[0x1c]; };
struct Obj { char pad0[4]; s32 f4; u16 f8; char padA[6]; s32 f10; char pad14[8]; s32 f1C; };
struct Ctx { char pad[0x164]; s32 f164; };
struct Vec { s32 a; void *p; s32 b; s32 c; s32 d; char padv[0xc]; };
extern "C" void free(void *);
extern "C" void *func_00575E60(int, int);
extern "C" void func_00606258(void *, void *);
extern "C" void func_0047A2A8(Obj *, Tree *, s32, s32);
extern "C" void strobe__ActionInstance__doAction(s32, s32, s32, u16, void *, Tree *, Ctx *);
extern "C" void func_00485368(Vec *, s32);

extern "C" s32 func_0047A400(s32 arg0, Obj *o, s32 arg2, s32 arg3, Obj *p, Ctx *c) {
    Node *key = (Node *)o->f10;
    Tree t;
    Vec v;
    void *volatile keep;
    volatile u8 fl = 0;
    volatile u8 *pf = &fl;
    t.head = 0;
    Node *n = (Node *)func_00575E60(0x10, 0x1C);
    t.head = n;
    t.size = 0;
    t.flag = *pf;
    n->a = 0;
    t.head->b = 0;
    t.head->c = t.head;
    t.head->d = t.head;
    *(Node *volatile *)&t.key = key;
    func_0047A2A8(o, &t, *(volatile s32 *)&c->f164, arg3);
    s32 x = o->f1C;
    if (p->f10 == x) {
        strobe__ActionInstance__doAction(arg0, arg2, o->f4, o->f8, p, &t, c);
        if (t.size != 0) {
            func_00606258(&t, t.head->b);
            t.head->c = t.head;
            t.head->b = 0;
            t.head->d = t.head;
            t.size = 0;
        }
        free(t.head);
    } else {
        v.p = 0; v.b = 0; v.c = 0; v.d = 0;
        func_00485368(&v, x);
        strobe__ActionInstance__doAction(arg0, arg2, o->f4, o->f8, &v, &t, c);
        void *q = v.p;
        keep = q;
        if (q) free(q);
        if (t.size != 0) {
            func_00606258(&t, t.head->b);
            t.head->c = t.head;
            t.head->b = 0;
            t.head->d = t.head;
            t.size = 0;
        }
        free(t.head);
    }
    return arg0;
}
