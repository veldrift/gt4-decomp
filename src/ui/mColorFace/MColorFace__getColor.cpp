/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Handle { void *p; char pad[12]; };
extern "C" void func_00284B70(void *, void *) throw();
extern "C" void func_00284B18(void *, int) throw();
extern "C" void func_002FC8C8(void *, void *);
extern "C" int func_002FE250(void *);
extern "C" void func_002FC870(void *, int);
extern "C" int func_002861D8(void *, int);
extern "C" void func_00204558(void *, int);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" void func_00203620(void *, int);
static inline void *get(Handle *h) { return h->p; }
static inline void assign(Handle *out, const Handle *src) {
    if (out != src) {
        void *p = src->p;
        if (p) func_003285A8(p);
        if (out->p) func_003285F8(out->p);
        out->p = p;
    }
}
extern "C" void MColorFace__getColor(Handle *out, void *src, int n, void *arg) {
    Handle copy;
    Handle temp;
    func_00284B70(&copy, src);
    int index = -1;
    if (n > 0) {
        func_002FC8C8(&temp, arg);
        index = func_002FE250(get(&temp));
        func_002FC870(&temp, 2);
    }
    func_00204558(&temp, func_002861D8(copy.p, index));
    assign(out, &temp);
    func_00203620(&temp, 2);
    func_00284B18(&copy, 2);
}
