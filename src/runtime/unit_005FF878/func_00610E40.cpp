struct Value_00610E40 {
    int w[11];
};

struct Node_00610E40 {
    char pad0[0x30];
    struct Value_00610E40 value;
};

extern "C" void func_00610E40(struct Node_00610E40 *node, const struct Value_00610E40 *v) {
    node->value = *v;
}
