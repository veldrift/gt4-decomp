/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Vec3 {
    float x, y, z;
};

class Node {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3 position();
};

struct Item {
    Node *node;
};

extern "C" int func_0049B330(Vec3 *, Vec3 *);

extern "C" int func_00340550(Item *item)
{
    Vec3 p = item->node->position();
    Vec3 lo, hi;
    float *px = &p.x, *py = &p.y, *pz = &p.z;
    lo.x = *px - 4.0f;
    lo.y = *py - 4.0f;
    lo.z = *pz - 4.0f;
    hi.x = *px + 4.0f;
    hi.y = *py + 4.0f;
    hi.z = *pz + 4.0f;
    return func_0049B330(&lo, &hi) != 0;
}
