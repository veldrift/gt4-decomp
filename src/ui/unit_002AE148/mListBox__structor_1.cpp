typedef int s32;

struct Item {
    s32 x;
    ~Item() __asm__("func_002B5E70");
};

struct Heap { const char *name; };
extern "C" Heap *func_005C11A8(void);
extern "C" Heap *MListItem__tf(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_002F9B38(void *, s32);
extern "C" void mScrollable__structor_1(void *, s32);
extern char mListBox__vtable[];

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };

template<class I> inline Item *value_type(const I &) { return 0; }

static inline void destroy_range(Item *first, Item *last) {
    Item *t = first;
    value_type(t);
    for (; first != last; ++first)
        first->~Item();
}

struct Vec {
    s32 pad0;
    Item *begin;
    Item *end;
    Item *cap;
    void destroy() {
        Item *b = begin;
        Item *e = end;
        Item *t = b;
        value_type(t);
        Item *p = b;
        for (; p != e; ++p)
            p->~Item();
        Item *b2 = begin;
        s32 n = cap - b2;
        if (b2)
            func_00326798(b2, n * 4, 4, MListItem__tf()->name);
    }
};

struct Obj {
    s32 pad0;
    char *vt;
    char pad8[0xC0];
    Vec arr[2];
    char pad_e8[0x6C];
    char *str;
};

extern "C" void mListBox__structor_1(Obj *self, s32 flags) {
    self->vt = mListBox__vtable;
    {
        Rep *q = (Rep *)(self->str) - 1;
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
    func_002F9B38((char *)self + 0x118, 2);
    func_002F9B38((char *)self + 0x114, 2);
    func_002F9B38((char *)self + 0x110, 2);
    if (self->arr) {
        Vec *e = self->arr + 2;
        Vec *a = self->arr;
        while (a != e) {
            --e;
            e->destroy();
        }
    }
    mScrollable__structor_1(self, 0);
    if (flags & 1)
        func_00326798(self, 0x158, 4, "RefCounter");
}
