typedef int s32;

struct S {
    char p0[0xBC];
    s32 fBC;
};

extern "C" void func_002D6770(S *self);
extern "C" void func_002D73C8(S *self, s32 oldIndex, s32 newIndex);
extern "C" void func_0057CE40(s32 *arg0, s32 arg1);

extern "C" void func_002D7288(S *arg0, s32 arg1) {
    s32 *p = &arg0->fBC;
    s32 old = *p;
    func_0057CE40(p, arg1);
    func_002D73C8(arg0, old, arg1);
    func_002D6770(arg0);
}
