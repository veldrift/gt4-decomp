/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Obj { char pad[0x1C]; float f1C; float f20; };
struct H { Obj *o; char pad[0xC]; };
struct W { s32 v; char pad[0xC]; };

extern "C" void func_0020B340(void *, int) throw();
extern "C" void func_0020B398(void *, void *) throw();
extern "C" void func_0020C288(void *, s32);
extern "C" void func_0020C300(void *, s32);
extern "C" void func_0020C3E0(void *);
extern "C" void func_002550B8(void *, int);
extern "C" void func_00255110(void *, void *);
extern "C" void func_002F7B68(void *, int);
extern "C" void func_002F7BC0(void *, void *);
extern "C" float func_002F9158(s32);

struct Number {
    int v; char pad[12];
    Number(char *p) { func_002F7BC0(this, p); }
    ~Number() { func_002F7B68(this, 2); }
    operator float() { return func_002F9158(v); }
};

extern "C" void MFadeActor__global_0082AD80(void *arg0, void *arg1, s32 arg2, char *arg3) {
    if (arg2 > 0) {
        H h;
        W v;
        float a = 1.0f;
        float b;
        func_0020B398(&h, arg1);
        W *pv = &v;
        func_00255110(pv, arg3);
        if (arg2 >= 2) {
            a = Number(arg3 + 4);
        }
        b = 0.0f;
        if (arg2 >= 3) {
            b = Number(arg3 + 8);
        }
        func_0020C288(h.o, pv->v);
        h.o->f1C = a;
        h.o->f20 = b;
        func_0020C300(h.o, 1);
        func_0020C3E0(h.o);
        func_0020C300(h.o, 0);
        func_002550B8(pv, 2);
        func_0020B340(&h, 2);
    }
}
