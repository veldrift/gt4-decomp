/* compiler: ee-gcc2.96-no-strict-aliasing */
struct E { char pad0; signed char state; char pad2[14]; void *value; };
struct S { char pad[0xC38]; E entries[32]; char padEB8[6]; signed char index; char padEBF[5]; void *other; };
extern "C" int func_004AAA20(S *, int) throw();
extern "C" void func_004AAD78(S *, int) throw();
extern "C" int func_004AAF38(S *, void *);
extern "C" int func_004AAE50(S *s, int arg1, void *arg2) {
    int i = s->index;
    if (i >= 0) {
        if (arg2 && s->entries[i].value == arg2) return i;
        func_004AAD78(s, i);
        s->index = -1;
    }
    if (arg2 && arg2 != s->other) {
        i = func_004AAF38(s, arg2);
        if (i >= 0) { s->index = i; return i; }
    }
    i = func_004AAA20(s, arg1);
    if (i >= 0) {
        s->entries[i].value = arg2;
        s->entries[i].state = 0;
        s->index = i;
        if (arg2 == s->other) s->other = 0;
    }
    return i;
}
