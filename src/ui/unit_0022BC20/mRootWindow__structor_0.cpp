/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct Node { Node *a; Node *b; s32 c; };
struct List { s32 pad; Node *head; };
struct Vec { s32 pad; s32 a; s32 b; s32 c; };
struct Obj {
    char pad0[4];
    char *vptr;
    char pad1[0xB8];
    List list;           /* 0xC0 */
    s32 unkC8;
    Vec vec;             /* 0xCC */
    Str s1;              /* 0xDC */
    Str s2;              /* 0xE0 */
    s32 unkE4;
    u32 flags;           /* 0xE8 */
    s32 unkEC;
};
extern Rep D_00659FA8;
extern char mRootWindow__vtable[];
extern char D_00698888[];
extern "C" void func_00206858(void *, s32);
extern "C" void *mFBox__structor_0(void *);
extern "C" void *func_00326750(s32, s32, const char *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" char *func_005C2560(Rep *);
extern "C" Str *func_005C2630(Str *, s32, s32, const char *, s32);
extern "C" const char **func_005DBBC0(void);

static inline void vinit(Vec *v) { v->a = 0; v->b = 0; v->c = 0; }

extern "C" void mRootWindow__structor_0(Obj *self) {
    s32 spare[4];
    (void)&spare;
    Str *p1 = &self->s1;
    Str *p2 = &self->s2;
    List *lp = &self->list;
    mFBox__structor_0(self);
    self->vptr = mRootWindow__vtable;
    Node *n = (Node *)func_00326750(0xC, 4, *func_005DBBC0());
    lp->head = n;
    n->a = n;
    lp->head->b = lp->head;
    self->unkC8 = 0;
    vinit(&self->vec);
    const char *src = D_00698888;
    {
        Rep *r = &D_00659FA8;
        char *d = (char *)(r + 1);
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            r->ref++;
        }
        p1->p = d;
    }
    func_005C2630(p1, 0, -1, src, func_0057F260(src));
    {
        Rep *r = &D_00659FA8;
        char *d = (char *)(r + 1);
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            r->ref++;
        }
        p2->p = d;
    }
    self->unkE4 = 0;
    self->unkEC = 0;
    s32 one = 1, c5 = -5, c9 = -9;
    u32 f = self->flags;
    f &= ~1u;
    f |= 2;
    f &= c5;
    f &= c9;
    f &= ~0x10u;
    f &= ~0x20u;
    self->flags = f;
    func_00206858(self, one);
}
