/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rec { int a; int b; float w; int pad[3]; };
struct Ent { int f0; char data[0x300]; };
struct List { int count; int p4; int *arr; };
struct Self { char p[0x60]; List *list; };
extern "C" void func_0040A6F0(Self *, void *) throw();
extern "C" int func_00445880(void *, int);
extern "C" int SPEC_DATABASE__CarEquipments__getVariationOrder(void *);
extern "C" float func_00578598(int);

extern "C" void func_0040AA48(Self *self, int arg1) {
    Ent buf[6];
    int n = self->list->count;
    int j;
    for (j = 0; j < n; j++) {
        char *e = (char *)self->list->arr[j] + 0x20;
        if (SPEC_DATABASE__CarEquipments__getVariationOrder(e) == -1) {
            func_0040A6F0(self, buf);
            Rec *r = (Rec *)buf[j].data;
            int c = r[0].a - 1;
            int i = 0;
            while (i < c) {
                if (func_00578598(arg1) < r[i].w) break;
                i++;
            }
            Rec *selected = r + i;
            func_00445880(e, selected->b);
        }
    }
}
