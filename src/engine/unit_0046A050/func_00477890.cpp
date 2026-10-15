/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Val;
extern "C" void func_004768C0(Val *);
extern "C" Val *func_00476768(Val *, const Val *);

struct Val {
    s32 type;
    s32 v;
    Val() : type(1) {}
    Val(const Val &o) { func_00476768(this, &o); }
    ~Val() { func_004768C0(this); }
    bool isObj() const { return type == 13; }
};
/* the same two words passed by value: the callee owns the copy, no destructor runs here */
struct ValRaw {
    s32 a;
    s32 b;
};

struct Holder { char pad[8]; char *item; };
struct Obj { char pad[0x164]; Holder *h; };

extern "C" Val func_0047A400(s32 p, s32 a2, s32 n, s32 t0, Obj *o);
extern "C" void func_00475DF8(Obj *, s32, const char *) throw();
extern "C" s32 func_00475E60(Obj *, const char *, const char *);
extern "C" void func_00475EB8(Obj *, ValRaw *, const char *) throw();
extern "C" void func_00475F38(Obj *) throw();
extern "C" void func_004762C0(Obj *, int) throw();
extern "C" void func_00476350(Obj *, ValRaw *) throw();
extern "C" void func_00476B30(Val *, s32) throw();
extern "C" const char *strobe__Any__toString(Val *) throw();
extern "C" float func_00477460(Val *) throw();
extern "C" void func_004787B8(Val *, int) throw();
extern "C" void func_004788C0(Val *);
extern "C" s32 func_00478968(Val *);
extern "C" s32 func_004789B8(Val *);
extern "C" void func_00480F78(Holder *);
extern "C" void func_00480FA0(Holder *, s32);
extern char D_006AD5C0[];

static inline int indexOf(Val *v) {
    func_004787B8(v, 10);
    return (int)func_00477460(v) - 1;
}

#define ITEM(h) ((Val *)((h)->item - 8))

extern "C" Val func_00477890(Val *v, s32 a2, s32 n, s32 t0, Obj *o)
{
    Holder *h = o->h;
    switch (v->type) {
    case 13:
        return func_0047A400(v->v, a2, n, t0, o);
    case 17:
        if (n != 0) {
            Val t(*ITEM(h));
            func_004788C0(&t);
            func_00480FA0(h, n);
            return t;
        }
        break;
    case 18:
        if (n != 0) {
            Val t(*ITEM(h));
            strobe__Any__toString(&t);
            func_00480FA0(h, n);
            return t;
        }
        break;
    case 19:
    case 20:
        if (n != 0) {
            Val t(*ITEM(h));
            func_004787B8(&t, 10);
            func_00480FA0(h, n);
            return t;
        }
        break;
    case 21:
        if (n != 0) {
            Val t(*ITEM(h));
            n--;
            func_00480F78(h);
            int base = n == 0 ? 10 : (int)func_00477460(ITEM(h));
            func_00480FA0(h, n);
            func_004787B8(&t, base);
            return t;
        }
        break;
    case 22:
        if (n != 0) {
            Val t;
            func_00476B30(&t, func_00478968(ITEM(h)));
            func_00480FA0(h, n);
            return t;
        }
        break;
    case 23:
        if (n != 0) {
            Val t;
            func_00476B30(&t, func_004789B8(ITEM(h)));
            func_00480FA0(h, n);
            return t;
        }
        break;
    case 24:
        if (n != 0) {
            Val t(*ITEM(h));
            n--;
            func_00480F78(h);
            const char *name = D_006AD5C0;
            if (n != 0)
                name = strobe__Any__toString(ITEM(h));
            if (t.isObj()) {
                ValRaw c;
                func_00476768((Val *)&c, &t);
                func_00475EB8(o, &c, name);
            } else if (func_00478968(&t) != 0) {
                func_00475E60(o, strobe__Any__toString(&t), name);
            } else {
                int i = indexOf(&t);
                if (i >= 0)
                    func_00475DF8(o, i, name);
            }
            func_00480FA0(h, n);
        } else {
            func_00475DF8(o, -1, D_006AD5C0);
        }
        break;
    case 25:
        func_00480FA0(h, n);
        func_00475F38(o);
        break;
    case 26: {
        int k = 0;
        if (n != 0)
            k = (int)func_00477460(ITEM(h));
        func_00480FA0(h, n);
        func_004762C0(o, k);
        break;
    }
    case 27:
        if (n != 0) {
            ValRaw c;
            func_00476768((Val *)&c, ITEM(h));
            func_00476350(o, &c);
            func_00480FA0(h, n);
        } else {
            ValRaw c;
            c.a = 1;
            func_00476350(o, &c);
        }
        break;
    }
    return Val();
}
