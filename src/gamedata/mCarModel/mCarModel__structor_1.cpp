/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Name {
    const char *name;
};

struct Entry {
    char pad[0x14];
};

struct Ref {
    s32 p;
};

struct EVec {
    s32 pad0;
    Entry *begin;
    Entry *end;
    Entry *cap;
};

struct RVec {
    s32 pad0;
    Ref *begin;
    Ref *end;
    Ref *cap;
};

struct Self {
    s32 pad0;
    void *vtbl;
    char pad8[0x68 - 8];
    RVec rv;
    EVec ev;
    char pad88[0x88 - 0x88];
    char f88[0x14];
};

extern char mCarModel__vtable[];
extern char D_0068FBC0[];

extern "C" void func_0021B340(void *arg0, int arg1);
extern "C" void func_0021B5D0(void *arg0, int arg1);
extern "C" void hObject__structor_2(void *p, int flags);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" Name *MModelSet__tf(void);
extern "C" Name *func_005CA378(void);

static inline void destroy_entries(Entry *&first, Entry *last) {
    Entry *p = first;
    if (p != last) {
        do {
            Entry *cur = p;
            p++;
            func_0021B340(cur, 2);
        } while (p != last);
    }
}

static inline void destroy_refs(Ref *&first, Ref *last) {
    Ref *p = first;
    if (p != last) {
        do {
            Ref *cur = p;
            p++;
            func_0021B5D0(cur, 2);
        } while (p != last);
    }
}

extern "C" void mCarModel__structor_1(Self *self, s32 flags) {
    self->vtbl = mCarModel__vtable;
    func_0021B340(self->f88, 2);
    {
        EVec *v = &self->ev;
        Entry *b = v->begin;
        Entry *e = v->end;
        Entry *first = b;
        destroy_entries(first, e);
        b = v->begin;
        {
            s32 n = ((char *)v->cap - (char *)b) >> 2;
            if (b != 0) {
                func_00326798(b, n << 2, 4, func_005CA378()->name);
            }
        }
    }
    {
        RVec *v = &self->rv;
        Ref *b = v->begin;
        Ref *e = v->end;
        Ref *first = b;
        destroy_refs(first, e);
        b = v->begin;
        {
            s32 n = ((char *)v->cap - (char *)b) >> 2;
            if (b != 0) {
                func_00326798(b, n << 2, 4, MModelSet__tf()->name);
            }
        }
    }
    hObject__structor_2(self, 0);
    if (flags & 1) {
        func_00326798(self, 0x9C, 4, D_0068FBC0);
    }
}
