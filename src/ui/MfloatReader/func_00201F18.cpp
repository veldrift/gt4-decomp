#define NULL 0

typedef struct { char b[64]; } Block64;

extern "C" void func_00201F18(void *arg0, void *arg1) {
    *(Block64 *)((char *)arg0 + 0x28) = *(Block64 *)arg1;
}
