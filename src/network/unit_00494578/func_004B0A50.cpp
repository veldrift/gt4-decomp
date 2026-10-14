/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Node { char pad[0x38]; void *u38; char pad3C[0xC]; s32 u48; };
struct Owner { char pad[0xA8]; char *uA8; char *uAC; };
extern "C" void func_004AC5D0(void *);
extern "C" Node *func_004AC660(void);
extern "C" s32 func_004AC778(s32);
extern "C" s32 func_004AC798(s32);
extern "C" void func_004AC7B8(s32);
extern "C" void func_004AD300(void *, void *);
extern "C" void func_004AEAE8(s32, void *);
extern "C" void func_004AEBB8(s32, s32);
extern "C" s32 func_004AE908(void *, void *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" Node *func_004B0A50(Owner *o, char *name, Node *n) {
    if (n == 0) {
        n = func_004AC660();
        if (n == 0) return n;
    } else {
        func_004AC5D0(n);
    }
    n->u38 = o;
    s32 len = func_0057F260(o->uA8);
    s32 blk = func_004AC778(len + func_0057F260(name) + 2);
    n->u48 = blk;
    s32 x = func_004AC798(blk);
    func_004AEAE8(x, o->uA8);
    func_004AEBB8(x, func_004AE908(o->uAC, name));
    func_004AC7B8(blk);
    func_004AD300(o, n);
    return n;
}
