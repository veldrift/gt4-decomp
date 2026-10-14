/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len, cap, ref, sel; };
struct Str { char *p; char pad[12]; };
struct Handle { void *p; char pad[12]; };
struct TypeInfo { const char *name; };
extern Rep D_00659FA8;
extern char D_00698770[], D_00698788[], D_00698790[], D_006987A0[];
extern "C" void func_00204D30(void *, int);
extern "C" void func_00204FC8(void *);
extern "C" void *func_00206868(void *);
extern "C" void func_00211408(void *, int);
extern "C" void func_002117A0(void *);
extern "C" void MWidgetReader__structor_2(void *, void *, void *, int);
extern "C" void func_002A0D20(void *, int);
extern "C" void func_002A1120(void *);
extern "C" void func_003069F8(void *, void *, void *);
extern "C" void *HSymID__GetID(void *);
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" int func_0057F260(const char *) throw();
extern "C" TypeInfo *func_005C11A8();
extern "C" char *func_005C2560(Rep *);
extern "C" Str *func_005C2630(Str *, unsigned, unsigned, const char *, unsigned);
static inline void init(Str *s, const char *text) {
    Rep *r = &D_00659FA8;
    char *p;
    if (r->sel) p = func_005C2560(r);
    else { ++r->ref; p = (char *)(r + 1); }
    s->p = p;
    func_005C2630(s, 0, -1, text, func_0057F260(text));
}
static inline void copy(Str *s, const Str *src) {
    char *p = src->p;
    Rep *r = (Rep *)(p - 16);
    if (r->sel) p = func_005C2560(r);
    else ++r->ref;
    s->p = p;
}
static inline void release(Str *s) {
    Rep *r = (Rep *)(s->p - 16);
    if (--r->ref == 0) {
        int size = r->cap + 16;
        const char *name = func_005C11A8()->name;
        func_00326798(r, size, 4, name);
    }
}
extern "C" void func_0022EBD8(char *self) {
    Str path;
    Handle reader;
    union { Str str; Handle obj; } out;
    Str appended;
    Handle id1;
    Str str1;
    Handle id2;
    Str str2;
    init(&path, D_00698770);
    func_002117A0(&reader);
    Handle *reader_ptr = &reader;
    void *rd = reader_ptr->p;
    const char *suffix = D_00698788;
    Str *ap = &appended;
    copy(ap, &path);
    func_005C2630(ap, ((Rep *)(ap->p - 16))->len, 0, suffix, func_0057F260(suffix));
    Str *output = &out.str;
    copy(output, ap);
    release(ap);
    void *obj = self + 0x1D04;
    MWidgetReader__structor_2(rd, obj, output, 1);
    release(output);
    Handle *model = (Handle *)output;
    func_00204FC8(model);
    obj = *(void **)obj;
    Handle *id = &id1;
    init(&str1, D_00698790);
    id->p = HSymID__GetID(&str1);
    func_003069F8(obj, model, id);
    release(&str1);
    *(void **)(self + 0x1D08) = model->p;
    func_002A1120(id);
    obj = model->p;
    Handle *id_next = &id2;
    init(&str2, D_006987A0);
    id_next->p = HSymID__GetID(&str2);
    func_003069F8(obj, id, id_next);
    release(&str2);
    if (id->p) *(void **)(self + 0x1D0C) = id->p;
    else *(void **)(self + 0x1D0C) = func_00206868(model->p);
    func_002A0D20(id, 2);
    func_00204D30(model, 2);
    func_00211408(&reader, 2);
    release(&path);
}
