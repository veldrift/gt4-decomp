/* compiler: ee-gcc2.96-nsa-nosib-as2004 */
typedef int s32;
struct E { s32 v; char p[0x28]; };
struct Obj { char p[0x1044]; E e[100]; };
struct T { s32 f0; char p4[4]; s32 f8; char pc[4]; s32 f10; char f14[4]; };
extern "C" void func_004F8E20(Obj *, s32, s32, s32, const char *);
extern "C" void func_004F8FB8(Obj *o, T *t) {
    s32 k = 0x7FFFFFFF;
    s32 i;
    for (i = 99; i >= 0; i--) o->e[i].v = k;
    func_004F8E20(o, t->f0, t->f8, t->f10, t->f14);
}
