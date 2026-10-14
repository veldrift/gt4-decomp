/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { Node *next, *prev; int value; };
extern "C" int hObject__structor_0(void *);
extern "C" void func_00318508(void *, const void *);
extern "C" void *func_005F1BC0(void);
extern "C" void *func_00326750(unsigned int, int, const char *);
extern char hThreadGroup__vtable[];
struct Alloc {
    int value;
    Alloc():value(0) {}
    Alloc(const Alloc &o) { func_00318508(this, &o); }
};
struct EmptyAllocator { EmptyAllocator() {} EmptyAllocator(const EmptyAllocator &) {} };
struct List {
    int allocator;
    Node *head;
    void init() {
        head = (Node *)func_00326750(12, 4, *(const char **)func_005F1BC0());
        head->next = head;
        head->prev = head;
    }
};
struct Self { int word; void *vt; int words[2]; Alloc alloc; List list; };
static inline Alloc zero() { return Alloc(); }
static inline void init(Self *self, const Alloc &alloc = zero()) {
    func_00318508(&self->alloc, &alloc);
    self->list.init();
}
extern "C" int hThreadGroup__structor_0(Self *self) {
    hObject__structor_0(self);
    self->vt = hThreadGroup__vtable;
    struct InitArgs { int reserved[4]; int value; } args;
    args.value = 0;
    func_00318508(&self->alloc, &args.value);
    self->list.init();
}
