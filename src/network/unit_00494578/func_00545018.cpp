extern "C" void *func_005A4724(void *,const void *,unsigned);
extern "C" int func_00544A18(unsigned *,int) throw();
extern "C" int func_00544950(unsigned *,unsigned) throw();
extern "C" int func_005448B8(unsigned *) throw();
extern "C" int func_00544908(unsigned *,unsigned *) throw();
extern "C" int func_00545C58(unsigned *,unsigned);
extern "C" int func_00545558(unsigned *,unsigned *,unsigned *,unsigned *);
extern "C" int func_00546668(unsigned *,unsigned *,unsigned *,unsigned *);
extern "C" int func_00545018(unsigned *a,unsigned *b) {
    unsigned orig[32], tempBuf[32], resultBuf[32];

    unsigned n = 0;
    func_005A4724(orig,a,128);
    func_00544A18(orig,1);
    unsigned *temp = tempBuf;
    func_005A4724(temp,orig,128);
    while (func_00544950(temp,n) == 0) ++n;
    if (n) func_00545C58(temp,n);
    unsigned *result = resultBuf;
    func_00545558(result,b,temp,a);
    if (func_005448B8(result)) return 1;
    unsigned i;
    if (func_00544908(result,orig) == 0) {
        i = 1;
        goto test;
    }
success:
    return 1;
loop:
    func_00546668(result,result,result,a);
    if (func_00544908(result,orig)) goto success;
    if (func_005448B8(result)) return 0;
test:
    if (i < n) { ++i; goto loop; }
    return 0;
}
