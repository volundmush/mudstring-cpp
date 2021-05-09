//
// Created by volund on 5/9/21.
//

#ifndef MUDSTRING_STYLE_H
#define MUDSTRING_STYLE_H

#include "mudstring/color.hpp"
#include <optional>
#include <unordered_map>
#include <vector>

namespace mudstring {

    enum Styling : uint16_t {
        Bold = 1,
        Dim = 2,
        Italic = 4,
        Underline = 8,
        Blink = 16,
        Blink2 = 32,
        Reverse = 64,
        Conceal = 128,
        Strike = 256,
        Underline2 = 512,
        Frame = 1024,
        Encircle = 2048,
        Overline = 4096
    };

    struct MxpData {
        std::string tag;
        std::unordered_map<std::string, std::string> attr;
    };

    struct Style {
        std::optional<Color> color, bgcolor;
        uint16_t styling = 0;
        std::optional<MxpData> mxp;
        void set_color(Color &col);
        void clear_color();
        void set_bgcolor(Color &col);
        void clear_bgcolor();
        void add_styling(uint16_t to_add);
        void rem_styling(uint16_t to_rem);
        void set_mxp(MxpData &mx);
        void clear_mxp();

        std::string ansi_codes(ColorSystem cs) const;

        std::string render(std::string &in, ColorSystem cs, bool mx) const;

    };

}




#endif //MUDSTRING_STYLE_H
