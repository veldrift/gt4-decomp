typedef int s32;
typedef unsigned int u32;

struct Handle {
    void *p;
    char pad[0xC];
};

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; char pad[0xC]; };
struct S00659988 { const char *name; };



extern StringRep D_00659FA8;


extern "C" char *func_005C2560(StringRep *r);
extern "C" String *func_005C2630(String *str, u32 pos, u32 n1, const char *s, u32 n2);
extern "C" u32 func_0057F260(const char *s);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);


extern "C" s32 func_001F1368(void *);
extern void mUpdateContext__Sync(int);
extern "C" s32 func_004F73D8(void *, s32);
extern "C" s32 func_001F1368(void *);
extern void mUpdateContext__Sync(int);
extern "C" void func_002ED590(Handle *, int *);
extern "C" Handle *func_002EFBF0(Handle *);
extern "C" void func_002EEEB0(Handle *, void *, Handle *);
extern "C" void func_00309378(Handle *, int);
extern "C" void func_002ED5C0(Handle *, int);
extern "C" void func_002ED5A8(Handle *, Handle *);
extern "C" void func_002FE278(Handle *, int);
extern "C" void func_002FC870(Handle *, int);
extern "C" Handle *func_00314B20(Handle *, String *);
extern "C" void func_00312318(Handle *, int);

static inline char *grab(StringRep *r) {
    if (r->selfish)
        return func_005C2560(r);
    ++r->ref;
    return (char *)(r + 1);
}

static inline String &assign(String *str, const char *s, u32 n) {
    return *func_005C2630(str, 0, (u32)-1, s, n);
}

static inline void construct(String *str, const char *s) {
    str->dat = grab(&D_00659FA8);
    assign(str, s, func_0057F260(s));
}

static inline void construct(String *str, const char *s, u32 n) {
    str->dat = grab(&D_00659FA8);
    assign(str, s, n);
}

static inline void release(String *s) {
    StringRep *q = (StringRep *)(s->dat - 0x10);
    if (--q->ref == 0) {
        s32 size = q->res + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}




static inline void *get(Handle *h) { return h->p; }
static inline void add_str(void *a, String *s, Handle *v, Handle *tmp) {
    func_00314B20(v, s);
    func_002EEEB0(tmp, a, v);
    func_00309378(tmp, 2);
    func_00312318(v, 2);
    release(s);
}
static inline void add_int(void *a, Handle *v, Handle *tmp) {
    func_002EEEB0(tmp, a, v);
    func_00309378(tmp, 2);
    func_002FC870(v, 2);
}



struct Record {
    char name[0x20];
    s32 a;
    s32 b;
    s32 key;
};

struct Net { char pad[0x1020]; Record recs[100]; };
extern Net D_00645570;

extern "C" void func_005D34A8(void *v, Record *pos, const Record *x);
extern "C" void func_005D3828(Record *first, Record *last, Record *, int depth);
extern "C" void func_005D39E0(Record *first, Record *last);
extern "C" S00659988 *func_005D4D48(void);

template <class I> inline Record *value_type(const I &) { return 0; }

template <class T> inline T lg(T n) {
    T k;
    for (k = 0; n != 1; n >>= 1)
        ++k;
    return k;
}

inline void sort_records(Record *first, Record *last) {
    if (first != last) {
        func_005D3828(first, last, value_type(first), lg(last - first) * 2);
        func_005D39E0(first, last);
    }
}

inline void destroy_one(Record *) {}

inline void destroy_range(Record *first, Record *last, Record *) {
    for (; first != last; ++first)
        destroy_one(&*first);
}

inline void destroy_all(Record *first, Record *last) {
    destroy_range(first, last, value_type(first));
}

struct RecVec {
    int alloc;
    Record *start;
    Record *finish;
    Record *eos;
    RecVec() : start(0), finish(0), eos(0) {}
    ~RecVec() {
        destroy_all(start, finish);
        dealloc(start, eos - start);
    }
    void dealloc(Record *p, u32 n) {
        if (p)
            func_00326798(p, n * sizeof(Record), 4, func_005D4D48()->name);
    }
    u32 size() const { return finish - start; }
    void push_back(const Record &x) {
        if (finish != eos) {
            if (finish)
                *finish = x;
            ++finish;
        } else {
            func_005D34A8(this, finish, &x);
        }
    }
};

extern "C" Handle *func_001F8060(Handle *ret) {
    RecVec vec;
    s32 pad[4];
    int n;
    Net *net = &D_00645570;
    for (n = 0; n < 100; n++) {
        Record *e = &net->recs[n];
        if (e->b != 0x7FFFFFFF)
            vec.push_back(*e);
    }
    sort_records(vec.start, vec.finish);
    Handle list;
    Handle row;
    Handle tmp;
    Handle v;
    String s;
    Handle v2;
    Handle v3;
    Handle v4;
    u32 i = 0;
    func_002EFBF0(&list);
    for (; i < vec.size(); i++) {
        Handle *ptmp = &tmp;
        func_002EFBF0(&row);
        Record *r = &vec.start[i];
        { void *p = get(&row); construct(&s, r->name); add_str(p, &s, &v, ptmp); }
        { void *p = get(&row); func_002FE278(&v2, r->a); add_int(p, &v2, ptmp); }
        { void *p = get(&row); func_002FE278(&v3, r->b); add_int(p, &v3, ptmp); }
        { void *p = get(&row); func_002FE278(&v4, r->key); add_int(p, &v4, ptmp); }
        func_002EEEB0(ptmp, list.p, &row);
        func_00309378(ptmp, 2);
        func_002ED5C0(&row, 2);
    }
    func_002ED5A8(ret, &list);
    func_002ED5C0(&list, 2);
    return ret;
}
