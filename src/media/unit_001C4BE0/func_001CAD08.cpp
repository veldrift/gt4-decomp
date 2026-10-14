/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Root;
struct File;
struct Ent { short delta, index; void (*fn)(void *, int); };
struct Obj { char pad[0x78]; char *vtbl; };
extern "C" const char *func_001CB3A0(Root *);
extern "C" const char *func_001CB668(Root *, const char *);
extern "C" File *func_001CB698(File *, Root *, char *, int, int, int);
extern "C" void func_001CB738(File *, int);
extern "C" int func_001CB7D0(File *, void *, int);
extern "C" int func_0057DA20(char *, const char *, ...);
extern "C" int func_0057F260(const char *) throw();
extern "C" void func_005C1628(void *) throw();
extern char D_00694BD0[], D_00694BD8[], D_00694BE8[];
struct Buffer {
    void *p;
    Buffer() { p = 0; }
    ~Buffer() { func_005C1628(p); }
};
struct Holder {
    Obj *p;
    Holder() { p = 0; }
    ~Holder() {
        Obj *o = p;
        if (o) {
            Ent *e = (Ent *)(o->vtbl + 0x40);
            e->fn((char *)o + e->delta, 3);
        }
    }
};
struct Root { int word; Buffer buffer; Holder obj; int pad; };
struct File {
    int word, fd;
    File(Root *r, char *name) { func_001CB698(this, r, name, 1, 1, 0); }
    ~File() { func_001CB738(this, 2); }
    operator void *() { return ((unsigned int)fd >> 31) == 0 ? this : 0; }
};
extern "C" const char *func_001CAD08(const char *path, const char *fmt, int count, void *data, int len) {
    Root root;
    const char *r = func_001CB3A0(&root);
    if (r) return r;
    func_001CB668(&root, path);
    char buf[0x40];
    int i = 0;
    while (i < count) {
        func_0057DA20(buf, D_00694BD0, path);
        func_0057DA20(buf + func_0057F260(buf), fmt, i);
        File f(&root, buf);
        i++;
        if (f) {
            if (func_001CB7D0(&f, data, len) < 0) return D_00694BD8;
            return 0;
        }
    }
    return D_00694BE8;
}
