struct Info { char pad[2]; unsigned char kind; };
struct Obj { char pad[0x1C]; void *implementation; };

extern "C" void func_0038CFD8(void *, void *, int);
extern "C" void func_0038D088(void *, void *, int);
extern "C" Info *func_0038DC18(Obj *);
extern "C" void func_0038C108(void *, int);

extern "C" void func_0038DC30(Obj *arg0, void *arg1, void *arg2, int arg3) {
    if (arg1 != 0) {
        func_0038CFD8((char *)arg0 + 0x10, arg1, arg3);
    } else if (arg2 != 0) {
        func_0038D088((char *)arg0 + 0x10, arg2, arg3);
    }
    unsigned char kind = func_0038DC18(arg0)->kind;
    switch(kind) {
    case 10:arg0->implementation=(char *)arg0+0xC;break;
    case 15:{void *special=(char *)arg0+4;func_0038C108(special,arg3);arg0->implementation=special;break;}
    default:arg0->implementation=(char *)arg0+0x10;break;
    }
}
