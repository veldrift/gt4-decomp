/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Table { char pad[0xDA20]; unsigned char bytes[6][4][2]; };
extern "C" short func_003FA4B0(char *t, int i, int j, unsigned char *out)
{
    if (out) {
        out[0] = ((Table *)t)->bytes[i][j][0];
        out[1] = ((Table *)t)->bytes[i][j][1];
    }
    return *(short *)(t + (i * 4 + j) * 2 + 0xD9F0);
}
