//
// Created by volund on 5/9/21.
//

#include "mudstring/color.hpp"

namespace mudstring {

    std::string ColorTriplet::ansi_codes() const {
        return std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b);
    }

    Color::Color(ColorSystem ctype, uint8_t val) {
        this->ctype = ctype;
        this->data.xterm.val = val;
    }

    Color::Color(ColorSystem ctype, ColorTriplet triplet) {
        this->ctype = ctype;
        this->data.truecol.triplet = triplet;
    }

    bool Color::is_default() const {
        return this->ctype == ColorSystem::DefaultColor;
    }

    bool Color::is_system_defined() const {
        return is_default();
    }

    std::string Color::get_ansi_codes(bool foreground) const {
        switch(this->ctype) {

            case DefaultColor:
                if(foreground) {
                    return std::string("39");
                } else {
                    return std::string("49");
                }
                break;
            case StandardColor:
                if(foreground) {
                    return std::to_string(this->data.xterm.val + 30);
                } else {
                    return std::to_string(this->data.xterm.val + 40);
                }
                break;
            case XtermColor:
                if(foreground) {
                    return std::string("38;5;" + std::to_string(this->data.xterm.val));
                } else {
                    return std::string("48;5;" + std::to_string(this->data.xterm.val));
                }
                break;
            case TrueColor:
                if(foreground) {
                    return std::string("38;2;" + this->data.truecol.triplet.ansi_codes());
                } else {
                    return std::string("48;2;" + this->data.truecol.triplet.ansi_codes());
                }
                break;
            default:
                if(foreground) {
                    return std::string("39");
                } else {
                    return std::string("49");
                }
                break;
        }
    }

    Color Color::downgrade(ColorSystem downto) const {
        // Not currently functional!
        Color out = *this;
        return out;
    }

}