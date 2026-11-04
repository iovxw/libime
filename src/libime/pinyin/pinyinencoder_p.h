/*
 * SPDX-FileCopyrightText: 2026 CSSlayer <wengxt@gmail.com>
 *
 * SPDX-License-Identifier: LGPL-2.1-or-later
 */
#ifndef _FCITX_LIBIME_PINYIN_PINYINENCODER_P_H_
#define _FCITX_LIBIME_PINYIN_PINYINENCODER_P_H_

#include <algorithm>
#include <cstddef>
#include <vector>
#include <libime/pinyin/pinyinencoder.h>

namespace libime {

// Return the fix that exactly covers the segment [from, to), if any.
// The fixes are ordered and non-overlapping, so a binary search by start_
// finds the only candidate.
inline const PinyinSegmentFix *
findExactFix(const std::vector<PinyinSegmentFix> &fixes, size_t from,
             size_t to) {
    const auto iter =
        std::ranges::lower_bound(fixes, from, {}, &PinyinSegmentFix::start_);
    if (iter != fixes.end() && iter->start_ == from && iter->end_ == to) {
        return &*iter;
    }
    return nullptr;
}

} // namespace libime

#endif // _FCITX_LIBIME_PINYIN_PINYINENCODER_P_H_
