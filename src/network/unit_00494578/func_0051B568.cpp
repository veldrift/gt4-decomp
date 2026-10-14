struct Item { int value; char pad4[8]; int idx; char pad10[0x10]; };
struct Slot;
struct Root {
    char pad0[0xF4];
    unsigned int cur;
    char pad[0x2F8 - 0xF8];
    Item items[1];
};
struct Slot { int a; int n; char pad[0x20 - 8 + 0x18 - 0x18]; };
extern Root *D_0064B4B4;
extern int D_0064AE00;
extern int D_00863670[];
extern "C" char *func_005A6AB0(void *, const char *, unsigned) throw();
extern "C" void func_0051B448(void *, void *, int) throw();

extern "C" int func_0051B568(unsigned int *out, const char *a1, int a2) {
    int i = 0;
    if (out == 0) return 0x17;
    if (a1 == 0) return 0x17;
    if (a2 <= 0) return 0x17;
    unsigned int cur = D_0064B4B4->cur;
    if (cur >= 0x10) return 8;
    char *base = (char *)D_0064B4B4 + cur * 0x228;
    int *slot = (int *)(base + 0x82F8);
    if (slot == 0) return 0xA;
    {
        slot[0] = a2;
        char *arr = base + 0x8300;
        slot[1] = 0;
        func_005A6AB0(arr, a1, 0x20);
        if (D_0064AE00 > 0) {
            int *ip = D_00863670;
            do {
                if (slot[1] >= 0x40) return 8;
                char *root = (char *)D_0064B4B4;
                Item *it = (Item *)(root + (*ip << 5) + 0x2F8);
                ip++;
                if (it != 0) {
                    int k = it->idx;
                    if (k >= 0x10) {
                        func_0051B448(slot, root + k * 0x228 + 0x6078, it->value);
                    } else {
                        *(int *)(arr + slot[1] * 4 + 0x120) = it->value;
                        int n = slot[1];
                        slot[1] = n + 1;
                        *(Item **)(arr + n * 4 + 0x20) = it;
                    }
                }
                i++;
            } while (i < D_0064AE00);
        }
        *out = D_0064B4B4->cur;
        D_0064B4B4->cur = D_0064B4B4->cur + 1;
        return 0;
    }
}
