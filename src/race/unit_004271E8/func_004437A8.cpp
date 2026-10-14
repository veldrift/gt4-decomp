struct B11 { char x[11]; };
extern "C" void func_00329F50(char *, int, const char *);
extern "C" int func_004438F0(int *, int);
extern "C" int func_00443A20(int *, int);
extern "C" int func_00443B50(int *);
extern "C" int func_00443C68(int *);
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" void func_005A5DC8(void *, void *);
extern char D_006A6D40[];
extern char D_006A6D50[];
extern char D_006A6D60[];
extern signed char D_00623798[];

extern "C" void func_004437A8(int *self) {
    char buf[0x80];
    *(B11 *)buf = *(B11 *)D_006A6D40;
    func_005A48D8(buf + 11, 0, 0x75);
    func_00329F50(buf, 0x80, D_006A6D50);
    func_005A5DC8(self + 2, buf);
    func_005A5DC8(self + 2, D_006A6D60);
    *self = 0;
    int i = 0;
    do {
        *self += func_004438F0(self, i++);
    } while (i < 0x2B);
    int j = 0;
    while (D_00623798[j] != 0x2B) {
        *self += func_00443A20(self, D_00623798[j]);
        j++;
    }
    *self += func_00443B50(self);
    *self += func_00443C68(self);
}
