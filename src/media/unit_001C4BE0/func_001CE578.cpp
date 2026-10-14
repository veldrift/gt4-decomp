/* compiler: ee-gcc2.96-nogcse */
typedef int s32;
struct Elem { char p[0x178]; };
struct Obj { void *vt; int pad; Elem arr[3]; char tail[0x50]; };
extern char D_00688280[];
extern "C" void func_0043A408(void *, s32);
extern "C" void *func_0043DC20(void *);
extern "C" s32 func_0043DED8(void *);
extern "C" void SPEC_DATABASE__CarEquipments__setVariationOrder(void *, int);

extern "C" s32 func_001CE578() {
    Obj o;
    func_0043DC20(&o);
    s32 n = func_0043DED8(&o);
    s32 r = ((n + 0x47) & ~0x3F) * 1000 + 0x40;
    o.vt = D_00688280;
    if (o.arr != 0) {
        Elem *e = o.arr + 3;
        if (o.arr != e) {
            do {
                e--;
                SPEC_DATABASE__CarEquipments__setVariationOrder(e, 2);
            } while (o.arr != e);
        }
    }
    func_0043A408(&o, 0);
    return r;
}
