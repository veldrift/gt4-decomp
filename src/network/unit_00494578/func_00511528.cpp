typedef int s32;

struct Node {
    s32 a;
    s32 pad4;
    Node *next;
};

struct Entry {
    s32 key;
    Node *head;
};

struct Obj;
typedef s32 (*Fn4C)(void *, s32, s32);
typedef s32 (*Fn50)(s32, s32, s32);
typedef void (*Fn54)(s32, s32, s32);

struct Obj {
    char pad0[0x3C];
    void *ctx;
    s32 pad40;
    s32 x44;
    Entry *tbl;
    Fn4C fn4c;
    Fn50 fn50;
    Fn54 fn54;
    s32 count;
    Node *cur;
    s32 x60;
    void *x64;
    char pad68[4];
    Obj *parent;
};

extern "C" {
s32 func_00512020(void *, void *);
s32 func_00512350(void *arg0, s32 *arg1);
}

extern "C" s32 func_00511528(Obj *self, s32 arg1) {
    s32 v = 1;
    if (self != 0) {
        s32 idx = self->fn4c(self->ctx, arg1, self->x44);
        Node *s2;
        if (self->cur != 0 && self->fn50(self->cur->a, arg1, self->x44) != 0) {
            s2 = self->cur;
        } else {
            s2 = self->tbl[idx].head;
            while (s2 != 0 && self->fn50(s2->a, arg1, self->x44) == 0) {
                s2 = s2->next;
            }
        }
        self->cur = 0;
        if (s2 != 0) {
            Obj *par = self->parent;
            self->count = self->count - 1;
            if (par != 0) {
                par->fn54(s2->a, par->x44, par->x60);
                func_00511528(par, par->x60);
            }
            func_00512020(self->tbl + idx, s2);
            func_00512350(self->x64, (s32 *)s2);
            v = 0;
        } else {
            v = 3;
        }
    }
    return v;
}
