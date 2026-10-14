/* compiler: ee-gcc2.96-no-strict-aliasing */
struct P { char *p; int len; };
struct A { char pad[0x14]; int flag; };
struct O {
    char pad0[0x1C]; char *begin; char *cur; char *end;
    char pad28[0x3294 - 0x28]; int active; A *a; char pad329C[8];
    P next; int result; int status;
};
extern "C" void func_00574EB0(void *);
extern "C" void func_00574EE8(void *);
extern "C" int func_004B03F0(O *o, A *a, P *b) {
    int r = 0;
    if (a->flag == 0) {
        if (o->active == 0) {
            o->a = a;
            o->status = 0;
            char *p = b->p;
            char *end = p + b->len;
            o->active = 1;
            o->cur = p;
            o->end = end;
            o->begin = p;
            func_00574EE8((char *)o + 0x3170);
        } else {
            o->next = *b;
            func_00574EE8((char *)o + 0x3230);
        }
        func_00574EB0((char *)o + 0x3260);
        r = o->status;
        if (r == 0) r = o->result;
    }
    return r;
}
