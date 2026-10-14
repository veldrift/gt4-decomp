/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pair { int a; unsigned b; Pair(int x,unsigned y):a(x),b(y){} Pair(const Pair &p):a(p.a),b(p.b){} };
struct State { int index; int p4; int p8; int pC; char *p10; char *p14; };
struct Slot { int p; unsigned sel; int x; };
extern State D_008468D0;
extern Slot D_006239AC[];
extern "C" void func_00461068(int) throw();
extern "C" void func_004613F0(int) throw();
extern "C" Pair func_00461568(int) throw();
extern "C" void func_00461620(float) throw();
extern "C" char *func_0055C4A8();
extern "C" void func_0055BDF0(char *,int,char *,unsigned,float);
static inline void play(int index, int sel, float volume) {
        func_004613F0(index);
        if(sel==~0U) sel=D_006239AC[index].sel;
        Pair pair=func_00461568(index);
        if(pair.b) sel=sel%pair.b;
        func_00461620(volume);
        char *p=func_0055C4A8();
        if(p) func_0055BDF0(p,D_008468D0.p8,D_008468D0.p10,sel,5000.0f);
        D_008468D0.p14=p;
}
extern "C" int func_004616E8(int index,int sel,float volume) {
    int changed;
    if(index!=D_008468D0.index) {
        changed=1;
        func_00461068(1);
    } else changed=D_008468D0.p14==0;
    if(changed) {
        play(index,sel,volume);
    }
    return changed;
}
