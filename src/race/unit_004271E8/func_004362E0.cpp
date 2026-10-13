extern "C" {
void func_00438BB8(void *arg0, int arg1);
void func_00438F70(void *arg0, int arg1);
void func_00439660(void *arg0, int arg1);
void func_004397D8(void *arg0, int arg1);
void func_0043A408(void *arg0, int arg1);
void func_0043D978(void *arg0, int arg1);
int func_005C1628(void *arg0);
}

extern char D_00687B60[];
extern char D_00687B20[];

extern "C" int func_004362E0(void *arg0, int arg1) {
    *(int *)arg0 = (int)D_00687B60;
    func_00438F70((char *)arg0 + 0x16A4, 2);
    func_004397D8((char *)arg0 + 0x1650, 2);
    func_00439660((char *)arg0 + 0x13F4, 2);
    func_00438BB8((char *)arg0 + 0x1344, 2);
    func_0043D978((char *)arg0 + 0x11D0, 2);
    {
        char *p = (char *)arg0 + 0x11C8;
        *(int *)p = (int)D_00687B20;
        func_0043A408(p, 0);
    }
    func_0043A408(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
