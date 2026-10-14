/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Work { char pad[0x14]; short n; char pad16[0x482]; char status; char len; short pad49a; int count; };
struct Ctx { char pad[0x28]; void *p28; int *p2c; Work *p30; };
extern Ctx *D_006452D4;
extern "C" {
void func_004BBCB8();
int func_004BBF58(Ctx *);
void func_004BC6E8(Ctx *);
void func_004BC728(void *, void *);
void func_004BC740(void *, void *);
int func_004C5D48(Ctx *, void *, int, Work *);
int func_004C8718(Ctx *, void *, int, void *, Work *);
void *func_004C8C20(Ctx *, int);
void func_004C8C38(Ctx *, void *);
int func_004C8ED0(void *);
void func_004C8F08(void *, void *);
void func_004C8FD8(void *, void *);
void func_004C9138(void *, void *, int);
int func_004C9330(char *);
int func_004C93F8(void *);
int func_004C9410(void *);
}
extern "C" int func_004B9F90(void *arg0, char *arg1, unsigned arg2) {
    struct Buffers { char a[0x60]; char b[0x60]; } sp;
    Ctx **gp = &D_006452D4;
    if (*(*gp)->p2c == 0x65) return 0x80000245;
    if (arg2-1 >= 0x7fffU) return 0x80001545;
    if (!arg1) return 0x80001645;
    if (!arg0) return 0x80001745;
    int check = func_004C93F8(arg0);
    if (check >= 0x2b || check == 0) return 0x80001145;
    func_004BC6E8(*gp);
    func_004BC728(sp.b, arg0);
    func_004C8FD8(sp.a, sp.b);
    int r = func_004BBF58(*gp);
    if (r < 0) return r;
    func_004C8F08((*gp)->p28, sp.a);
    *(*gp)->p2c = 0x65;
    int status = func_004C5D48(*gp, (*gp)->p28, 0, (*gp)->p30);
    if (status < 0) { func_004BBCB8(); return status; }
    (*gp)->p30->status = status;
    (*gp)->p30->len = func_004C8ED0((*gp)->p28);
    int size = (arg2 >> 1)*2+2;
    (*gp)->p30->count = (*gp)->p30->n;
    void *buf = func_004C8C20(*gp,size);
    if (!buf) { func_004BBCB8(); return 0x80000345; }
    r = func_004C8718(*gp,buf,size,(*gp)->p28,(*gp)->p30);
    if (r < 0) { func_004BBCB8(); func_004C8C38(*gp,buf); return r; }
    void *out = func_004C8C20(*gp,size);
    if (!out) { func_004BBCB8(); func_004C8C38(*gp,buf); return 0x80000345; }
    func_004C9138(out,buf,r);
    func_004C8C38(*gp,buf);
    int n = func_004C9410(out);
    n += func_004C9410(sp.b);
    n += 2;
    n = arg2 < (unsigned)n;
    if (n) { func_004BBCB8(); func_004C8C38(*gp,out); return 0x80001045; }
    func_004BC740(arg1,out);
    func_004C8C38(*gp,out);
    func_004BC740(arg1+func_004C9330(arg1)+1,sp.b);
    return status;
}
