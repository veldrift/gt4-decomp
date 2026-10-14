/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
typedef int s32;
struct VEntry { s16 delta; s16 pad; void (*fn)(void *, void *, s32, void *); };
struct Vt { char pad[4]; VEntry *vtbl; };
extern "C" void func_002FC870(void *, s32);
extern "C" void func_002FC8C8(void *, void *);
extern "C" s32 func_002FE250(void *);
extern "C" void func_00309348(void *, void *);
extern "C" void func_00309378(void *, s32);
extern "C" void func_0030BB18(void *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
struct Handle {
    void *p;
    Handle() __asm__("func_0030BB18");
    ~Handle() __asm__("func_00309378");
    Handle &operator=(const Handle &src) {
        if (this != &src) {
            void *n=src.p;
            if(n) func_003285A8(n);
            if(p) func_003285F8(p);
            p=n;
        }
        return *this;
    }
};
struct Temp { void *p; char pad[12]; void *get() const { return p; } };
extern "C" s32 func_002DBCA8(Vt **self, void *a1, void *a2) {
    if (*self) {
        Handle hs[2];
        Temp d;
        Temp e;
        void *t1=a1;
        func_00309348(&d,&t1);
        hs[0]=*(Handle *)&d;
        func_00309378(&d,2);
        Handle *h2=hs+1;
        void *t2=a2;
        func_00309348(&d,&t2);
        *h2=*(Handle *)&d;
        func_00309378(&d,2);
        func_0030BB18(&d);
        Vt *o=*self;
        VEntry *v=o->vtbl+0xA8/8;
        v->fn((char *)o+v->delta,&d,2,hs);
        func_002FC8C8(&e,&d);
        s32 r=func_002FE250(e.get());
        func_002FC870(&e,2);
        func_00309378(&d,2);
        return r;
    }
    return 0;
}
