/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ent { unsigned int key; int val; };
struct Inner { char pad[8]; int count; char pad2[4]; Ent ents[1]; };
extern "C" int func_00449210(void **, unsigned int) throw();
extern "C" int func_00449770(Inner **arg0, int key) {
    int idx = func_00449210((void **)arg0, key);
    if (idx == -1) return idx;
    int n = 1;
    int next, k;
    goto test;
    do {
        if (!(idx < (*arg0)->count)) break;
        idx = next;
        n++;
    test:
        next = idx + 1;
        k = -1;
        if (next >= 0) {
            Inner *t = *arg0;
            if (next < t->count) k = *(int *)((char *)t + (next << 3) + 0x10);
        }
    } while (key == k);
    return n;
}
