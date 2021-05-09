//
// Created by volund on 5/9/21.
//

#ifndef MUDSTRING_TEXT_H
#define MUDSTRING_TEXT_H
#include "mudstring/style.hpp"
#include <vector>
#include <memory>

namespace mudstring {

    struct Span {
        std::size_t start = 0, end = 0;
        std::optional<std::shared_ptr<Style>> style;
    };

    struct Segment {
        std::string text;
        std::optional<std::shared_ptr<Style>> style;
    };

    struct Text {
        std::string plain;
        std::vector<Span> spans;
        std::string render(ColorSystem cs, bool mxp) const;
    };

}

#endif //MUDSTRING_TEXT_H
