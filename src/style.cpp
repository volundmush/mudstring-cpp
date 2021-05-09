//
// Created by volund on 5/9/21.
//

#include "mudstring/style.hpp"
#include <boost/algorithm/string/join.hpp>

namespace mudstring {

    void Style::set_color(Color &col) {
        color = col;
    }

    void Style::clear_color() {
        color.reset();
    }

    void Style::set_bgcolor(Color &col) {
        bgcolor = col;
    }

    void Style::clear_bgcolor() {
        bgcolor.reset();
    }

    void Style::add_styling(uint16_t to_add) {
        styling &= to_add;
    }

    void Style::rem_styling(uint16_t to_rem) {
        if (styling & to_rem) {
            styling -= to_rem;
        }
    }

    void Style::set_mxp(MxpData &mx) {
        mxp = mx;
    }

    void Style::clear_mxp() {
        mxp.reset();
    }

    std::string Style::ansi_codes(ColorSystem cs) const {
        std::vector<std::string> outdata;

        if(styling & Bold) {
            outdata.emplace_back("1");
        }
        if(styling & Dim) {
            outdata.emplace_back("2");
        }
        if(styling & Italic) {
            outdata.emplace_back("3");
        }
        if(styling & Underline) {
            outdata.emplace_back("4");
        }
        if(styling & Blink) {
            outdata.emplace_back("5");
        }
        if(styling & Blink2) {
            outdata.emplace_back("6");
        }
        if(styling & Reverse) {
            outdata.emplace_back("7");
        }
        if(styling & Conceal) {
            outdata.emplace_back("8");
        }
        if(styling & Strike) {
            outdata.emplace_back("9");
        }
        if(styling & Underline2) {
            outdata.emplace_back("21");
        }
        if(styling & Frame) {
            outdata.emplace_back("51");
        }
        if(styling & Encircle) {
            outdata.emplace_back("52");
        }
        if(styling & Overline) {
            outdata.emplace_back("53");
        }

        if(color.has_value()) {
            if(cs < color.value().ctype) {
                auto col = color.value().downgrade(cs);
                outdata.push_back(col.get_ansi_codes(true));
            } else {
                outdata.push_back(color.value().get_ansi_codes(true));
            }
        }

        if(bgcolor.has_value()) {
            if(cs < bgcolor.value().ctype) {
                auto col = bgcolor.value().downgrade(cs);
                outdata.push_back(col.get_ansi_codes(false));
            } else {
                outdata.push_back(bgcolor.value().get_ansi_codes(false));
            }
        }

        return boost::join(outdata, ";");
    }

    std::string Style::render(std::string &in, ColorSystem cs, bool mx) const {
        std::string out;

        if(cs > 0) {
            out.append("\x1b[" + ansi_codes(cs) + "m" + in + "\x1b[0m");
        }

        if(mx) {
            // TODO: implement MXP here.
        }

        return out;
    }
}