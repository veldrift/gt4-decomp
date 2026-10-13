typedef int s32;
typedef long s64;
struct V { char tag; s64 val; };
extern "C" s32 func_00440B18(s32 a);
extern "C" void func_0042F0E0(void *self, V *v);
extern "C" void func_0042F408(void *self, s32 x) {
    V v;
    v.tag = 7;
    v.val = func_00440B18(x);
    func_0042F0E0(self, &v);
}
