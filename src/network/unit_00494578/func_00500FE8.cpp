/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_00689740[];
extern "C" void func_00500E48(void *, int) throw();
extern "C" void func_005041B0(void *, int);
extern "C" void func_005C1628(void *) throw();
struct Base {
    char pad[0x48]; char *vt;
    ~Base() { func_00500E48(this,0); }
};
struct Member {
    int a,b;
    ~Member() { func_005041B0(this,2); }
};
struct Owner : Base {
    Member members[16];
    ~Owner() { vt = D_00689740; }
};
extern "C" void func_00500FE8(Owner *o, int flags) {
    o->~Owner();
    if (flags & 1) return func_005C1628(o);
}
