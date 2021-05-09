//
// Created by volund on 5/9/21.
//

#ifndef MUDSTRING_COLOR_H
#define MUDSTRING_COLOR_H

#include <cstdint>
#include <string>

namespace mudstring {

    enum ColorSystem : uint8_t {
        DefaultColor = 0,
        StandardColor = 1,
        XtermColor = 2,
        TrueColor = 3
    };

    struct ColorTriplet {
        uint16_t r, g, b;
        [[nodiscard]] std::string ansi_codes() const;
    };

    // This struct covers both Standard and Xterm - in Standard mode, values should not go higher than 7.
    struct ColorXtermData {
        uint8_t val;
    };

    struct ColorTrueData {
        ColorTriplet triplet;
    };

    union ColorData {
        ColorXtermData xterm;
        ColorTrueData truecol;
    };

    struct Color {
        ColorSystem ctype;
        ColorData data;
        Color(ColorSystem ctype, uint8_t val);
        Color(ColorSystem ctype, ColorTriplet triplet);

        [[nodiscard]] bool is_system_defined() const;
        [[nodiscard]] bool is_default() const;
        [[nodiscard]] std::string get_ansi_codes(bool foreground) const;
        [[nodiscard]] Color downgrade(ColorSystem downto) const;
    };
}

#endif //MUDSTRING_COLOR_H
