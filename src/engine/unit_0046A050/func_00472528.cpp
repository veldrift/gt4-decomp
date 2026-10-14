/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ent { int k; int v; };
struct Tbl { Ent e[13]; };
extern char D_006AD2F0[];
extern "C" int func_00472400(int) throw() __attribute__((const));
extern "C" void func_00472408(int, int) throw();

extern "C" void func_00472528(int self, int key) {
    Tbl local = *(Tbl *)D_006AD2F0;
    int r = func_00472400(self);
    for (int i=0;i<12;i++) {
        int k=local.e[i].k;
        if(k == -1) break;
        if(k == key) { r=local.e[i].v; break; }
    }
    func_00472408(self, r);
}
