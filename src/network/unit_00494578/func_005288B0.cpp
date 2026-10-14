static inline int count(const unsigned short&n){return n*2+4;}char*func_005288B0(char*p){if(*(unsigned short*)p&0x4000){unsigned short n=*(unsigned short*)(p+2);return p+count(n);}return p+2;}
