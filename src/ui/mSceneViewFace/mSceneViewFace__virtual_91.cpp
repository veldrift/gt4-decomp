/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VEntry3 {
    s16 delta;
    s16 index;
    void (*fn)(char *, s32, s32);
};
struct VEntry4 {
    s16 delta;
    s16 index;
    void (*fn)(char *, s32, char *);
};

struct Node {
    Node *next;
    Node *prev;
    char *data;
};

struct Iter {
    Node *n;
    Iter(Node *x): n(x) {}
    Iter(const Iter &x): n(x.n) {}
    Iter operator++(int) { Iter t(*this); n=n->next; return t; }
    bool operator!=(const Iter &x) const { return n!=x.n; }
};

struct Self {
    char pad0[4];
    char *vt;
    char pad8[0x58];
    char pad60[4];
    Node *head;
};

struct Vobj {
    char pad0[4];
    char *vt;
};

extern "C" s32 func_0022F350(char *p);
extern "C" s32 func_002319C0(char *p);
extern "C" void *func_00235C00(char *p);
extern "C" s32 func_00265DC8(char *p);
extern "C" void func_00266100(char *p, s32 a);
extern "C" void func_002661A0(char *p, s32 a);

static inline Iter begin(char *l) { return Iter((*(Node **)(l+4))->next); }
static inline Iter end(char *l) { return Iter(*(Node **)(l+4)); }
extern "C" void mSceneViewFace__virtual_91(char *arg0, s32 arg1) {
    if (func_00265DC8(arg0) != 0) {
        VEntry3 *v = (VEntry3 *)(((Self *)arg0)->vt + 0x230);
        v->fn(arg0 + v->delta, arg1, 1);
        char *l = arg0 + 0x60;
        for (Iter it=begin(l); it!=end(l); it++) {
            char *o=it.n->data;
            VEntry4 *w=(VEntry4 *)(((Vobj *)o)->vt+0x1A8);
            w->fn(o+w->delta,arg1,arg0);
        }
    }
    func_00266100(arg0, (char *)func_00235C00((char *)func_002319C0((char *)arg1)) == arg0);
    func_002661A0(arg0, (char *)func_0022F350((char *)arg1) == arg0);
}
