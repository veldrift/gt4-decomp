/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Node { s32 a; s32 b; Node *c; Node *d; };
struct Tree { char pad0[4]; Node *head; s32 size; u8 flag; };

extern Rep D_00659FA8;
extern char mManager__vtable[];
extern char D_00697958[];
extern "C" s32 func_0024E348(void *, void *);
extern "C" int func_00306E00(void *, void *);
extern "C" s32 hObject__structor_0(void *);
extern "C" Node *func_00326750(unsigned int, int, const char *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);
extern "C" void func_005C2630(void *, s32, s32, const char *, s32);
extern "C" const char **func_005D9F58(void);

static inline void assign(char **d, const char *s, s32 n) { func_005C2630(d, 0, -1, s, n); }
static inline void setp(char **d, char *p) { *d = p; }
static inline void str_release(char **pp) {
    Rep *q = (Rep *)(*pp - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void mManager__structor_0(char *arg0) {
    struct { char pad[0x20]; char *s[4]; s32 z; } fr;
    hObject__structor_0(arg0);
    Tree *t = (Tree *)(arg0 + 0x10);
    *(char **)(arg0 + 4) = mManager__vtable;
    t->head = 0;
    Node *n = func_00326750(0x18, 4, *func_005D9F58());
    t->size = 0;
    t->head = n;
    t->flag = 0;
    n->a = 0;
    t->head->b = 0;
    t->head->c = t->head;
    t->head->d = t->head;
    fr.z = 0;
    func_0024E348(arg0 + 0x20, &fr.z);
    const char *str = D_00697958;
    char **ps = fr.s;
    char *p;
    if (D_00659FA8.sel != 0) {
        p = func_005C2560(&D_00659FA8);
    } else {
        p = (char *)&D_00659FA8 + 0x10;
        D_00659FA8.ref = D_00659FA8.ref + 1;
    }
    setp(ps, p);
    assign(ps, str, func_0057F260(str));
    func_00306E00(arg0 + 0x24, fr.s);
    str_release(fr.s);
    *(s32 *)(arg0 + 0x28) = 0;
    *(s32 *)(arg0 + 0x2C) = 0;
}
