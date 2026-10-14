/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_0028BD50(void *, int) throw();
extern "C" void func_0028BDA8(void *, void *) throw();
extern "C" int func_0028CF70(void *, void *, void *, void *, int);
extern "C" void func_002ED5A8(void *, void *);
extern "C" void func_002ED5C0(void *, int);
extern "C" void *func_002ED618(void *, void *);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" int func_002FE250(void *);
extern "C" void func_002FE278(void *, int);
extern "C" void func_00312318(void *, int);
extern "C" void func_00312370(void *, void *);
extern "C" void *func_00314920(void *);
extern "C" void *func_00314AD8(void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
struct H { void *p; char pad[12]; };
static inline void assign(H *dst, H *src) {
    if (dst != src) {
        void *newVal = src->p;
        if (newVal) func_003285A8(newVal);
        void *oldVal = dst->p;
        if (oldVal) func_003285F8(oldVal);
        dst->p = newVal;
    }
}
extern "C" void MDnas__Initialize(H *out, void *target, int count, H *args) {
    H h0, h10, h20, h30, h40, h50, h60, h70, h80, h90, hA0, hB0;
    func_00312370(&h0, args);
    H *list = &h10;
    func_002ED618(list, (char *)args + 4);
    if (count >= 2) {
        if (count == 2) {
            H *l = &h30;
            func_002ED5A8(l, list);
            H *t = &h40;
            func_0028BDA8(t, target);
            void *obj = t->p;
            int r = func_0028CF70(obj, func_00314920(h0.p), l, 0, 0x50);
            H *ret = &h20;
            func_002FE278(ret, r != 0);
            assign(out, ret);
            func_002FC870(ret, 2);
            func_0028BD50(t, 2);
        } else if (count == 3) {
            H *s = &h20;
            func_00312370(s, (char *)args + 8);
            H *l = &h60;
            func_002ED5A8(l, list);
            H *t = &h70;
            func_0028BDA8(t, target);
            void *obj = t->p;
            void *text = func_00314920(h0.p);
            int r = func_0028CF70(obj, text, l, func_00314AD8(s->p), 0x50);
            H *ret = &h50;
            func_002FE278(ret, r != 0);
            assign(out, ret);
            func_002FC870(ret, 2);
            func_0028BD50(t, 2);
            func_00312318(s, 2);
        } else if (count == 4) {
            H *s = &h20;
            func_00312370(s, (char *)args + 8);
            H *num = &h80;
            func_002FC8C8(num, (char *)args + 12);
            H *l = &hA0;
            func_002ED5A8(l, list);
            H *t = &hB0;
            func_0028BDA8(t, target);
            void *obj = t->p;
            void *text = func_00314920(h0.p);
            void *extra = func_00314AD8(s->p);
            int r = func_0028CF70(obj, text, l, extra, func_002FE250(num->p));
            H *ret = &h90;
            func_002FE278(ret, r != 0);
            assign(out, ret);
            func_002FC870(ret, 2);
            func_0028BD50(t, 2);
            func_002FC870(num, 2);
            func_00312318(s, 2);
        }
    }
    func_002ED5C0(list, 2);
    func_00312318(&h0, 2);
}
