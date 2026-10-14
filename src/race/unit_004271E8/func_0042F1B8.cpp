struct Rec { char f0; char f1; char f2; long long id; };
extern "C" long long func_00447BB8(int);
extern "C" void func_0042F0E0(void *, Rec *);
extern "C" void func_0042F1B8(void *a, int b, int c, int d) {
    Rec r;
    r.f0 = 1;
    r.id = func_00447BB8(b);
    r.f1 = c;
    r.f2 = d;
    func_0042F0E0(a, &r);
}
