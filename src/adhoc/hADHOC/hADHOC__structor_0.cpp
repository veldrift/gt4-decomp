/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct MNode { MNode *a; s32 b; MNode *c; MNode *d; };
struct SNode { SNode *a; SNode *b; };
struct Map { s32 f0; MNode *head; s32 size; char color; };
struct Set { s32 f0; SNode *head; };
struct Obj {
    char pad0[4]; void *vt;
    Map m8;
    char pad18[0];
};
extern Rep D_00659FA8;
extern char hADHOC__vtable[];
extern "C" void *func_00326750(unsigned int, int, const char *);
extern "C" int RefCounter__structor_0(void *);
extern "C" const char **func_005EC158(void);
extern "C" const char **func_005EC198(void);
extern "C" const char **func_005EC1E8(void);
extern "C" const char **func_005EC228(void);
extern "C" int func_00306E80(void *);
extern "C" char *func_005C2560(Rep *);
extern "C" void func_00574D78(void *, char *);
extern "C" void func_002EFBF0(void *);

extern "C" void hADHOC__structor_0(char *o) {
    RefCounter__structor_0(o);
    char padv[16];
    char **p40 = (char **)(o + 0x40);
    Map *m8 = (Map *)(o + 8);
    Set *s18 = (Set *)(o + 0x18);
    *(void **)(o + 4) = hADHOC__vtable;
    Set *s20 = (Set *)(o + 0x20);
    m8->head = 0;
    Map *m28 = (Map *)(o + 0x28);
    {
        MNode *n = (MNode *)func_00326750(0x18, 4, *func_005EC228());
        m8->size = 0;
        m8->head = n;
        m8->color = 0;
        n->a = 0;
        MNode *h1 = m8->head;
        h1->b = 0;
        MNode *h2 = m8->head;
        h2->c = h2;
        MNode *h3 = m8->head;
        h3->d = h3;
    }
    {
        SNode *n = (SNode *)func_00326750(0xC, 4, *func_005EC158());
        s18->head = n;
        n->a = n;
        n = s18->head;
        n->b = n;
    }
    {
        SNode *n = (SNode *)func_00326750(0xC, 4, *func_005EC1E8());
        s20->head = n;
        n->a = n;
        n = s20->head;
        n->b = n;
    }
    m28->head = 0;
    {
        MNode *n = (MNode *)func_00326750(0x18, 4, *func_005EC198());
        m28->size = 0;
        m28->head = n;
        m28->color = 0;
        n->a = 0;
        MNode *h1 = m28->head;
        h1->b = 0;
        MNode *h2 = m28->head;
        h2->c = h2;
        MNode *h3 = m28->head;
        h3->d = h3;
    }
    func_00306E80(o + 0x38);
    func_00306E80(o + 0x3C);
    char *d;
    Rep *r = &D_00659FA8;
    {
        s32 sel = r->sel;
        if (sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        *p40 = d;
    }
    func_00574D78(o + 0x44, d);
    func_002EFBF0(o + 0x74);
}
