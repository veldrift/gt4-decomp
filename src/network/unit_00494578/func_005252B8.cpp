#define NULL 0

struct func_005252B8_entry {
    char pad0[0x10];
    int unk10;
};

struct func_005252B8_arg0 {
    char pad0[0x88];
    void *unk88;
    char pad8C[0x30];
    unsigned int unkBC;
};

int func_005252B8(struct func_005252B8_arg0 *arg0, int arg1, int *arg2) {
    unsigned int temp_a1;
    void *temp_a0;

    temp_a1 = arg1 & 0xFF;
    if (arg2 == NULL) {
        return 2;
    }
    *arg2 = 0;
    if (arg0 == NULL) {
        return 2;
    }
    if (temp_a1 >= arg0->unkBC) {
        return 2;
    }
    temp_a0 = arg0->unk88;
    if (temp_a0 == NULL) {
        return 3;
    }
    *arg2 = ((struct func_005252B8_entry *) ((char *) temp_a0 + temp_a1 * 0x18))->unk10;
    return 0;
}
