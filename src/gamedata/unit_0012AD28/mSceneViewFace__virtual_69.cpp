/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef int s32;

struct Rep { u32 len; u32 res; u32 ref; u32 selfish; };
struct Str { char *dat; };
struct Heap { const char *name; };
extern Rep D_00659FA8;
extern "C" char *func_005C2560(Rep *r);
extern "C" u32 func_0057F260(const char *s) throw();
extern "C" Heap *func_005C11A8(void);
extern "C" void func_00326798(void *p, u32 n, u32 align, const char *name);
extern "C" Str *func_005C2630(Str *self, u32 pos, u32 n1, const char *s, u32 n2);

static inline char *grab(Rep *r) {
    if (r->selfish)
        return func_005C2560(r);
    ++r->ref;
    return (char *)(r + 1);
}
static inline Str &assign(Str *str, const char *s, u32 n) { return *func_005C2630(str, 0, (u32)-1, s, n); }
static inline Str &assign(Str *str, const char *s) { return assign(str, s, func_0057F260(s)); }
static inline void construct(Str *str, const char *s) { str->dat = grab(&D_00659FA8); assign(str, s); }
static inline void construct(Str *str) { str->dat = grab(&D_00659FA8); }
static inline Rep *rep(const Str *str) { return (Rep *)str->dat - 1; }
static inline void deallocate(void *p, u32 n) { func_00326798(p, n, 4, func_005C11A8()->name); }
static inline void rep_delete(void *ptr) { deallocate(ptr, sizeof(Rep) + ((Rep *)ptr)->res); }
static inline void release(Rep *r) { if (--r->ref == 0) rep_delete(r); }
static inline void destroy(Str *str) { release(rep(str)); }

struct Obj;
struct Ent { short delta; short pad; void *fn; };
struct Table { char pad[0x198]; Ent emit; };
struct Obj { int z; Table *vt; char pad[0x98]; int a0, a4, a8, ac, b0; float b4,b8; int bc; };
struct InputTable { char pad[0x230]; Ent get; };
struct Root { char pad[0x64]; InputTable *vt; };
extern Root *D_00618840;
struct Thread { char pad[0x38]; void (*fn)(Obj *); Obj *arg; int flag; };
struct ThreadConfig { int z, size; };
struct Slot { int value; char pad[12]; };
extern "C" void mColorChipFace__virtual_69(Obj *,void *,int);
extern "C" Thread *func_005750C0(ThreadConfig *,int);
extern "C" int func_005788B8(Thread *);
extern "C" void func_0012B908(Obj *);
extern "C" void func_00548228(int *,int *,int *);
extern "C" int RaceInput__getButtonDown(void *);
extern "C" void func_00323D08(Slot *);
extern "C" int HSymID__GetID(Str *);
extern "C" void *func_002EFBF0(Slot *);
extern "C" void func_0023A538(Slot *,void *,Obj *,Str *,Slot *);
extern "C" void func_002319A0(void *,Slot *);
extern "C" void func_00239F08(Slot *,int);
extern "C" void func_002ED5C0(Slot *,int);
extern "C" void func_00323B60(Slot *,int);
extern char D_0068E7A8[];
extern "C" void mSceneViewFace__virtual_69(Obj *self,void *arg,int enabled) {
    mColorChipFace__virtual_69(self,arg,enabled);
    if (enabled) {
        union { ThreadConfig cfg; Str str; } u;
        Slot sig, h, cb, tmp;
        if (D_00618840 && self->a0) {
            if (self->a8 == 0) {
                if (!self->a4) {
                    self->a4 = 1;
                    u.cfg.size = 0x4000;
                    u.cfg.z = 0;
                    Thread *p = func_005750C0(&u.cfg,0);
                    p->flag = 1;
                    p->arg = self;
                    p->fn = func_0012B908;
                    func_005788B8(p);
                }
            } else {
                self->a0 = 0;
                self->b4 = -0.5f;
            }
        }
        sig.value = 0;
        func_00548228(0,0,&sig.value);
        if (!sig.value) {
            Root *root = D_00618840;
            Ent *entry = &root->vt->get;
            void *input = ((void *(*)(void *))entry->fn)((char *)root + entry->delta);
            if ((RaceInput__getButtonDown(input)&0x40) && !self->bc) {
                sig.value = 1;
                self->bc = 1;
            }
        }
        if (sig.value) {
            construct(&u.str,D_0068E7A8);
            Slot *ph = &h;
            func_00323D08(ph);
            Slot *pc = &cb;
            pc->value = HSymID__GetID(&u.str);
            Ent *entry = &self->vt->emit;
            ((void (*)(void *, Slot *, Slot *))entry->fn)((char *)self + entry->delta,ph,pc);
            if (__builtin_expect(ph->value, 0)) {
                Slot *pt = &tmp;
                func_002EFBF0(pt);
                func_0023A538(pc,arg,self,&u.str,pt);
                func_002319A0(arg,pc);
                func_00239F08(pc,2);
                func_002ED5C0(pt,2);
            }
            func_00323B60(ph,2);
            destroy(&u.str);
        }
        float speed = self->b4;
        if (speed != 0.0f) {
            float v = self->b8 + 0.016666666f / speed;
            self->b8 = v;
            if (speed > 0.0f) {
                if (v >= 1.0f) { self->b8 = 1.0f; self->b4 = 0.0f; }
            } else if (v <= 0.0f) { self->b8 = 0.0f; self->b4 = 0.0f; }
        }
    }
}
