#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include "../../src/common.hpp"
#include "../../src/util/printer.hpp"

std::stringstream ss;
Printer printer{ss};

class C
{
public:
    C(int s_) : s{s_} {}
    friend Ostream& operator<<(Ostream& os, const C& cls) { return os << "{" << cls.s << "}"; }

private:
    int s;
};

void valTest()
{
    {
        const int v = 100;
        printer(v);
        assert(ss.str() == "100");
        ss.str("");

        printer.ln(v);
        assert(ss.str() == "100\n");
        ss.str("");

        printer.el(v);
        assert(ss.str() == "100\n");
        ss.str("");
    }

    {
        const char c = 'a';
        printer(c);
        assert(ss.str() == "a");
        ss.str("");

        printer.ln(c);
        assert(ss.str() == "a\n");
        ss.str("");

        printer.el(c);
        assert(ss.str() == "a\n");
        ss.str("");
    }

    {
        const Str s = "abcABC012";
        printer(s);
        assert(ss.str() == "abcABC012");
        ss.str("");

        printer.ln(s);
        assert(ss.str() == "abcABC012\n");
        ss.str("");

        printer.el(s);
        assert(ss.str() == "abcABC012\n");
        ss.str("");
    }

    {
        const C cls{100};
        printer(cls);
        assert(ss.str() == "{100}");
        ss.str("");

        printer.ln(cls);
        assert(ss.str() == "{100}\n");
        ss.str("");

        printer.el(cls);
        assert(ss.str() == "{100}\n");
        ss.str("");
    }
}

void valsTest()
{
    const int v = 100;
    const char c = 'a';
    const Str s = "abcABC012";
    const C cls{100};

    printer(v, c, s, cls);
    assert(ss.str() == "100 a abcABC012 {100}");
    ss.str("");

    printer.ln(v, c, s, cls);
    assert(ss.str() == "100 a abcABC012 {100}\n");
    ss.str("");

    printer.el(v, c, s, cls);
    assert(ss.str() == "100 a abcABC012 {100}\n");
    ss.str("");
}

int main()
{
    valTest();
    valsTest();
    out.ln("Hello World");
    return 0;
}
