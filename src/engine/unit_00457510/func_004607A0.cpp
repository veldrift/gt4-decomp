/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_0057F238(const char *, const char *) throw();
extern "C" int func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void func_00461360();
extern "C" void func_00461508(const char *);
extern char D_006AB438[], D_006AB440[], D_00846890[];
struct Shared { int a,refs; };
extern Shared D_008468C0;
static inline int acquire(const char *arg0, int first) {
    void *mutex = D_00846890;
    func_00576788(mutex);
    if (++D_008468C0.refs==first) {
        func_00461360();
        func_00461508(arg0);
    }
    func_005767C0(mutex);
    return -1;
}
extern "C" int func_004607A0(const char *arg0) {
    if (func_0057F238(arg0,D_006AB438)==0) return -2;
    if (func_0057F238(arg0,D_006AB440)==0) return -3;
    return acquire(arg0,1);
}
