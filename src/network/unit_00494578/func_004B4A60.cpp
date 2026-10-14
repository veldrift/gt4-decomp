/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x858]; int active; };
struct Entry { signed char type; char pad[3]; short start, end; };
extern "C" void func_004B49B8(Obj *, Entry *, short *, int) throw();
extern "C" void func_004B4A60(Obj *o, short *data, int remaining, int type) {
    int i = 0;
    char *group = (char *)o + (1 - o->active) * 0x41c;
    int count = *(int *)(group + 0x234);
    if (count > 0) {
        Entry *e = (Entry *)(group + 0x238);
        do {
            if (e->type == type) {
                func_004B49B8(o, e, data, remaining);
                data += e->end - e->start;
                remaining -= e->end - e->start;
                if (remaining <= 0) break;
            }
            ++i;
            ++e;
        } while (i < count);
    }
}
