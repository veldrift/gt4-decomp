struct S { char data[100]; };
struct T { S text; short length; };
extern "C" int func_0057F260(const char *) throw();
extern "C" int func_0050FCE8(T *, int *);
extern "C" int func_00509810(S s, int *out) {
    T t;
    t.text = s;
    t.length = func_0057F260(s.data);
    *out = 0;
    return func_0050FCE8(&t, out) == 0 ? 0 : -13;
}
