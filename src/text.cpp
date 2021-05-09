//
// Created by volund on 5/9/21.
//

#include "mudstring/text.hpp"

namespace mudstring {


    std::string Text::render(ColorSystem cs, bool mxp) const {
        std::string out;

        for(const auto &s : spans) {
            auto st = plain.substr(s.start, s.end-s.start);
            if(s.style.has_value()) {
                out.append(s.style.value()->render(st, cs, mxp));
            } else {
                // gotta escape MXP here normally...
                out.append(st);
            }
        }

        return out;
    }

}