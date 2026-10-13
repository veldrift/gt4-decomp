typedef int s32;

struct Conn {
    char pad[0x50];
    s32 f50;
};

extern "C" char *func_004ED980(Conn *conn, int value, const char *name, const char *text);
extern "C" s32 func_004ED410(Conn *arg0, s32 arg1);

extern "C" void func_004ED490(Conn *arg0, const char *arg1, const char *arg2) {
    if (func_004ED980(arg0, 0, arg1, arg2) == 0) {
        func_004ED410(arg0, arg0->f50);
    }
}
