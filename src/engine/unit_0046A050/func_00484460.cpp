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
};
struct Obj;
struct Scope;

extern "C" void func_00476A08(Val *) throw();
extern "C" Val func_00477890(Val *v, Scope *s, s32 n, s32 t0, Obj *o);
extern "C" Val *func_00481230(Scope *s, s32 key);

extern "C" Val func_00484460(Scope *s, s32 key, s32 n, s32 t0, Obj *o)
{
    Val *v = func_00481230(s, key);
    if (v != 0)
        return func_00477890(v, s, n, t0, o);
    Val t;
    func_00476A08(&t);
    return t;
}
