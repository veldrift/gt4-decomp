struct Rec { long w[6]; };
struct Obj { long pad; Rec r[10]; };
extern "C" void func_00432E40(Rec *);
extern "C" void func_00432E80(Rec *);
extern "C" void func_004330D0(Obj *o, unsigned idx, int flag) {
    if (idx < 10) {
        int i = idx;
        if (i < 9) {
            do {
                o->r[i] = o->r[i + 1];
                i++;
            } while (i < 9);
        }
        if (flag) func_00432E80(&o->r[9]);
        else func_00432E40(&o->r[9]);
    }
}
