struct Data { char pad[0x34]; int value,a,b,c,d; char tail[0xB8]; };
extern "C" void func_00539688(Data *) throw();
extern "C" void func_00539340(Data *, int) throw();
extern "C" void func_00539718(int a) {
    Data data;
    func_00539688(&data);
    data.value = a;
    a = *(volatile int *)0x10000000;
    data.a = a;
    a = *(volatile int *)0x10000800;
    data.b = a;
    a = *(volatile int *)0x10001000;
    data.c = a;
    a = *(volatile int *)0x10001800;
    data.d = a;
    func_00539340(&data, 0x40);
}
