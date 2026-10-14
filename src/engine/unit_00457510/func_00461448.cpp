/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_0057F238(const char *, const char *) throw();
extern "C" unsigned int func_0057F260(const char *) throw();
extern "C" void func_005A6AB0(void *, const void *, int) throw();
extern unsigned char D_006D0E79[];
struct Entry { const char *name; int a,b; };
extern Entry D_006239A8[];
extern "C" int func_00461448(const char *arg0) {
    char buf[64];
    func_005A6AB0(buf,arg0,64);
    unsigned int n = func_0057F260(buf);
    for(unsigned int i=0;i<n;i++) {
        int c = buf[i];
        if (*(unsigned char *)(0x006D0E79+c) & 1) c += 32;
        buf[i] = c;
    }
    int result=-1;
    for (unsigned int i=0;i<10;i++) {
        if (func_0057F238(buf,D_006239A8[i].name)==0) {
            result=i;
            break;
        }
    }
    return result;
}
