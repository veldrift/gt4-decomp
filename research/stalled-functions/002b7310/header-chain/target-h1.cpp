/* compiler: ee-gcc2.96-no-strict-aliasing */
// Main templates for the -*- C++ -*- string classes.
// Copyright (C) 1994, 1995, 1999 Free Software Foundation

// This file is part of the GNU ANSI C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

// As a special exception, if you link this library with files
// compiled with a GNU compiler to produce an executable, this does not cause
// the resulting executable to be covered by the GNU General Public License.
// This exception does not however invalidate any other reasons why
// the executable file might be covered by the GNU General Public License.

// Written by Jason Merrill based upon the specification by Takanori Adachi
// in ANSI X3J16/94-0013R2.
// Adapted relevant header chain; upstream provenance in research notes.
typedef unsigned int size_t;
typedef unsigned int u32;
typedef int s32;
struct Heap { const char *name; };
extern "C" Heap *func_005C11A8();
extern "C" void func_00326798(void *, size_t, size_t, const char *);
extern "C" size_t func_0057F260(const char *) throw();
extern char D_0069C110[];
struct GameAlloc {
    static void deallocate(void *p, size_t n) {
        func_00326798(p, n, 4, func_005C11A8()->name);
    }
};
struct traits {
    typedef char char_type;
    static size_t length(const char *s) { return func_0057F260(s); }
    static void assign(char &c, const char &d) { c = d; }
    static char eos() { return 0; }
};
class basic_string {
    typedef char charT;
    typedef GameAlloc Allocator;
    struct Rep {
        size_t len, res, ref;
        bool selfish;
        charT *data() { return reinterpret_cast<charT *>(this + 1); }
        charT &operator[](size_t s) { return data()[s]; }
        charT *grab() { if (selfish) return clone(); ++ref; return data(); }
        void release() { if (--ref == 0) delete this; }
        inline static void operator delete(void *);
        charT *clone() __asm__("func_005C2560");
    };
    Rep *rep() const { return reinterpret_cast<Rep *>(dat) - 1; }
    static charT eos() { return traits::eos(); }
    void terminate() const { traits::assign((*rep())[length()], eos()); }
    static Rep nilRep __asm__("D_00659FA8");
    charT *dat;
public:
    typedef size_t size_type;
    static const size_type npos = static_cast<size_type>(-1);
    const charT *data() const { return rep()->data(); }
    size_type length() const { return rep()->len; }
    size_type size() const { return rep()->len; }
    bool empty() const { return size() == 0; }
    basic_string &operator=(const basic_string &str) {
        if (&str != this) { rep()->release(); dat = str.rep()->grab(); }
        return *this;
    }
    explicit basic_string() : dat(nilRep.grab()) {}
    basic_string(const basic_string &str) : dat(str.rep()->grab()) {}
    basic_string(const charT *s, size_type n) : dat(nilRep.grab()) { assign(s, n); }
    basic_string(const charT *s) : dat(nilRep.grab()) { assign(s); }
    ~basic_string() { rep()->release(); }
    basic_string &assign(const charT *s, size_type n) { return replace(0, npos, s, n); }
    basic_string &assign(const charT *s) { return assign(s, traits::length(s)); }
    basic_string &operator=(const charT *s) { return assign(s); }
    basic_string &replace(size_type, size_type, const charT *, size_type) __asm__("func_005C2630");
    const charT *c_str() const {
        if (length() == 0) return D_0069C110;
        terminate();
        return data();
    }
};
inline void basic_string::Rep::operator delete(void *ptr) {
    Allocator::deallocate(ptr, sizeof(Rep) + reinterpret_cast<Rep *>(ptr)->res * sizeof(charT));
}
typedef basic_string String;

extern char D_0069C118[];
extern char D_008386A8[];
extern "C" void func_005769F0(void *);
extern "C" void func_00576A28(void *);
struct LocalizedText {
    char pad0[8];
    String key;
    String text;
};

extern "C" void func_002B7310(LocalizedText *self, String *value) throw() {
    func_005769F0(D_008386A8);
    String *destination = &self->text;
    if (value->length() == 0) {
        String fallback(D_0069C118);
        *destination = fallback;
    } else {
        *destination = value->c_str();
    }
    func_00576A28(D_008386A8);
}
