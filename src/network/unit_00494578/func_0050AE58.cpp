struct Event { int data[6]; int last; };
extern "C" void func_0057D9C0(const char *, ...);
extern "C" int func_0050BE40(void *);
extern "C" void *func_005A48D8(void *,int,unsigned int);
extern char D_008537D0[];
extern int D_008A01A4;
extern void (*D_008A03CC)(Event *,int);
extern "C" void func_0050AE58(void) {
    Event event;
    func_0057D9C0("IDF... BillingLogoutCallback\n");
    if (func_0050BE40(D_008537D0)) {
        func_005A48D8(&event,0,0x1C);
        event.last = 0;
        if (D_008A03CC) D_008A03CC(&event,D_008A01A4);
    }
}
