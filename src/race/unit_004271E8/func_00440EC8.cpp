typedef long s64;
struct Item { char pad[0x166]; char flag; char pad2[0x178 - 0x167]; };
struct Obj { char pad[8]; Item items[3]; char pad2[0x4A0 - 8 - 3 * 0x178]; char sub[1]; };
extern "C" void func_00343420(void *, int);
extern "C" void func_00343900(void *);
extern "C" void func_0043E240(unsigned char *);
extern "C" void func_0043FA10(void *);
extern "C" int func_00444440(void *, s64);
extern "C" int func_00448820(long, void *);
extern "C" int func_00448948(void *);
extern "C" int func_00440EC8(Obj *o, long arg) {
    char buf[0x20];
    int i = 0;
    Item *it;
    int fl;
    int r;
    func_0043E240((unsigned char *)o);
    func_00448820(arg, buf);
    it = o->items;
    fl = func_00448948(buf) != 0;
    do {
        r = func_00444440(it, arg);
        if (r == 0) return r;
        i++;
        it->flag = fl;
        it++;
    } while (i < 3);
    func_0043FA10(o);
    func_00343420(o->sub, fl);
    func_00343900(o->sub);
    return 1;
}
