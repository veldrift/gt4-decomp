/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Point { char pad[0x1C]; int x; float y; int z; char tail[0xC]; };
struct Info { unsigned char a, count; };
struct Obj { char pad[8]; void *owner; char gap[4]; void *info; char rest[0x7B8-0x14]; Point points[4]; };
extern "C" Info *func_00359510(void *);
extern "C" void func_00395760(void *, Point *);
extern "C" void func_003957F0(void *, Point *);
extern "C" void func_00344458(Obj *self) {
    int n = func_00359510(self->info)->count;
    if (n == 4) {
        func_003957F0(self->owner, self->points);
    } else {
        for (int i = 0; i < n; i++) {
            func_00395760(self->owner, &self->points[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        Point *p = &self->points[i];
        if (p->y < 0.5f) {
            p->x = 0;
            p->y = 1.0f;
            p->z = 0;
        }
    }
}
