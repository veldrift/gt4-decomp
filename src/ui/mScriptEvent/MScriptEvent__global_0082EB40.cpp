/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct H0;
struct H1;
struct H2;
struct H3;
struct H4;

extern "C" void func_0022ACC8(H1 *, s32);
extern "C" void func_0022AD20(H1 *, void *);
extern "C" void func_00239F08(H0 *, s32) throw();
extern "C" void func_00239F60(H0 *, s32) throw();
extern "C" void func_0023A5D0(void *, void *);
extern "C" void func_0023A688(void *, H4 *);
extern "C" void func_002550B8(H2 *, s32);
extern "C" void func_00255110(H2 *, void *);
extern "C" void func_0028EA10(void *, void *);
extern "C" void func_0028EA70(void *, void *);
extern "C" void func_002ED5C0(H4 *, s32);
extern "C" void func_002ED618(H4 *, void *);
extern "C" void func_00312318(H3 *, s32);
extern "C" void func_00312370(H3 *, void *);
extern "C" void *func_00314920(void *);

struct H0 {
    void *p; char pad[12];
    H0(s32 a) { func_00239F60(this, a); }
    ~H0() { func_00239F08(this, 2); }
};
struct H1 {
    void *p; char pad[12];
    H1(void *s) { func_0022AD20(this, s); }
    ~H1() { func_0022ACC8(this, 2); }
};
struct H2 {
    void *p; char pad[12];
    H2(void *s) { func_00255110(this, s); }
    ~H2() { func_002550B8(this, 2); }
};
struct H3 {
    void *p; char pad[12];
    H3(void *s) { func_00312370(this, s); }
    ~H3() { func_00312318(this, 2); }
};
struct H4 {
    void *p; char pad[12];
    H4(void *s) { func_002ED618(this, s); }
    ~H4() { func_002ED5C0(this, 2); }
};

static inline void *ptr(void *h) { return *(void **)h; }

extern "C" void MScriptEvent__global_0082EB40(void *a0, s32 a1, s32 level, char *src) {
    if (level >= 3) {
        H0 h0(a1);
        H1 h1(src);
        func_0028EA10(h0.p, ptr(&h1));
        H2 h2(src + 4);
        func_0028EA70(h0.p, ptr(&h2));
        H3 h3(src + 8);
        {
            void *tp = h0.p;
            func_0023A5D0(tp, func_00314920(ptr(&h3)));
        }
        if (level >= 4) {
            H4 h4(src + 0xC);
            func_0023A688(h0.p, &h4);
        }
    }
}
