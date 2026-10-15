typedef int s32;
typedef unsigned int u32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 selfish;
};
struct HeapInfo { const char *name; };
extern Rep D_00659FA8;
extern char D_0069C110[];
extern const char D_0069C118[];
extern char D_008386A8[];
extern "C" char *func_005C2560(Rep *);
extern "C" HeapInfo *func_005C11A8(void);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" u32 func_0057F260(const char *) throw();
extern "C" void func_005769F0(void *);
extern "C" void func_00576A28(void *);
extern "C" struct String *func_005C2630(struct String *, u32, u32, const char *, u32);

static inline char *grab(Rep *r) {
    char *data;
    if (r->selfish) data = func_005C2560(r);
    else { data = (char *)(r + 1); s32 count = r->ref + 1; r->ref = count; }
    return data;
}

struct String {
    char *p;
    Rep *rep() const { return (Rep *)p - 1; }
    s32 length() const { return rep()->len; }
    const char *c_str() const {
        if (length() == 0) return D_0069C110;
        p[length()] = 0;
        return p;
    }
    String() : p(grab(&D_00659FA8)) {}
    explicit String(const char *value) {
        p = grab(&D_00659FA8);
        func_005C2630(this, 0, (u32)-1, value, func_0057F260(value));
    }
    ~String() {
        Rep *r = rep();
        if (--r->ref == 0) {
            s32 size = r->cap + 0x10;
            func_00326798(r, size, 4, func_005C11A8()->name);
        }
    }
    String &operator=(const String &src) {
        if (&src != this) {
            Rep *old = rep();
            if (--old->ref == 0) {
                s32 size = old->cap + 0x10;
                func_00326798(old, size, 4, func_005C11A8()->name);
            }
            p = grab(src.rep());
        }
        return *this;
    }
    String &operator=(const char *src) {
        func_005C2630(this, 0, (u32)-1, src, func_0057F260(src));
        return *this;
    }
};

struct LocalizedText {
    char pad0[8];
    String key;
    String text;
};

extern "C" void func_002B7310(LocalizedText *self, String *value) throw() {
    func_005769F0(D_008386A8);
    String *destination = &self->text;
    if (value->length() == 0) {
        String fallback(D_0069C118);
        *destination = fallback;
    } else {
        *destination = value->c_str();
    }
    func_00576A28(D_008386A8);
}
