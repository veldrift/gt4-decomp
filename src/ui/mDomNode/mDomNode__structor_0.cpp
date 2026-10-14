/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Node { s32 f0; s32 f4; Node *f8; Node *fC; };
struct Lst { s32 f0; Node *head; s32 size; char flag; };
struct Self {
    char pad0[4];
    void *vt;
    char pad8[8];
    Lst a;
    Lst b;
    char *str;
};

extern Rep D_00659FA8;
extern char mDomNode__vtable[];

extern "C" void *hObject__structor_0(void *);
extern "C" void *func_00326750(unsigned int, int, const char *);
extern "C" char *func_005C2560(Rep *);
extern "C" const char **func_005D8210(void);
extern "C" const char **func_005D8260(void);

extern "C" int mDomNode__structor_0(Self *self) {
    s32 spare[4];
    Lst *a = &self->a;
    Lst *b = &self->b;
    hObject__structor_0(self);
    self->vt = mDomNode__vtable;
    char **ps = &self->str;
    a->head = 0;
    Node *n = (Node *)func_00326750(0x18, 4, *func_005D8210());
    a->size = 0;
    a->head = n;
    a->flag = 0;
    n->f0 = 0;
    a->head->f4 = 0;
    a->head->f8 = a->head;
    a->head->fC = a->head;
    b->head = 0;
    Node *m = (Node *)func_00326750(0x18, 4, *func_005D8260());
    b->size = 0;
    b->head = m;
    b->flag = 0;
    m->f0 = 0;
    b->head->f4 = 0;
    b->head->f8 = b->head;
    b->head->fC = b->head;
    Rep *r = &D_00659FA8;
    char *d;
    if (r->sel != 0) {
        d = func_005C2560(r);
    } else {
        d = (char *)(r + 1);
        r->ref++;
    }
    *ps = d;
}
