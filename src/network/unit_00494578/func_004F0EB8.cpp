/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pair { int a; int b; };
extern "C" int func_00523190(const char *, Pair *);
extern "C" void func_005223B8(void *, Pair);
extern "C" int func_004F0EB8(void *unused, const char *name, void *out) {
    Pair p;
    if (func_00523190(name, &p) != 0) return 0;
    func_005223B8(out, p);
    return 1;
}
