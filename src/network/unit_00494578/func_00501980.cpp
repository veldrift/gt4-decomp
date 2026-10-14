/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node;
extern "C" Node *func_00501248(Node **, const char *);
extern "C" Node *func_00501980(char *self, const char *name) {
    Node *result = func_00501248((Node **)(self + 0x1E4), name);
    Node **second = (Node **)(self + 0x1F0);
    while (!result) {
        result = func_00501248(second, name);
        break;
    }
    return result;
}
