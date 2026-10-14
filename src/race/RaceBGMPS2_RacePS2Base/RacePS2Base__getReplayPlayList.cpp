struct Blob { long long d[258]; };

extern "C" void RacePS2Base__getReplayPlayList(char *arg0, Blob *out) {
    *out = *(Blob *)(arg0 + 0xD150);
}
