/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Stream { char pad[0x20]; int error; };
struct Pair { float x, y; };
struct Obj {
    char pad[0xA88]; Stream stream;
    char pad2[0x11D8-0xA88-sizeof(Stream)];
    int count; Pair pairs[3];
    void *dest; int size; int used;
};
extern "C" int func_001C7730(void *) throw();
extern "C" float func_001C7738(void *) throw();
extern "C" void func_0046E920(Stream *, int);
extern "C" int func_0046EA08(Stream *);
extern "C" void func_0046EB40(Stream *, void *, int);
extern "C" int func_0057F238(const char *, const char *) throw();
extern const char *D_00618D08, *D_00618D0C;
extern "C" int func_001C7740(Obj *o, int type) {
    char buf[16];
    Stream *s = &o->stream;
    int n = func_0046EA08(s);
    int left = n - 2;
    if (left < 0) return 1;
    switch (type) {
    case 0xFFE8:
        if (left < 9) break;
        left -= 9;
        func_0046EB40(s, buf, 9);
        buf[10] = 0;
        if (func_0057F238(buf, D_00618D08) != 0) break;
        if (s->error) goto error;
        if (left < 4) break;
        left -= 4;
        func_0046EB40(s, buf, 4);
        if (s->error) goto error;
        if (func_001C7730(buf) != 1) break;
        if (left < 4) break;
        left -= 4;
        func_0046EB40(s, buf, 4);
        if (s->error) goto error;
        n = func_001C7730(buf);
        if ((unsigned)n >= 4) break;
        for (int i = 0; i < n; i++) {
            if (left < 8) goto done;
            func_0046EB40(s, buf, 8);
            left -= 8;
            o->pairs[i].x = func_001C7738(buf);
            o->pairs[i].y = func_001C7738(buf + 4);
        }
        o->count = n;
        break;
    case 0xFFE9:
        if (left < 9) break;
        left -= 9;
        func_0046EB40(s, buf, 9);
        buf[10] = 0;
        if (func_0057F238(buf, D_00618D0C) != 0) break;
        if (s->error) goto error;
        if (o->dest && o->size >= left) {
            func_0046EB40(s, o->dest, left);
            o->used = left;
            left = 0;
        }
        break;
    }
done:
    if (left > 0) func_0046E920(s, left);
error:
    return -1;
}
