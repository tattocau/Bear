/*  Copyright (C) 2012-2020 by László Nagy
    This file is part of Bear.

    Bear is a tool to generate compilation database for clang tooling.

    Bear is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Bear is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <cstring>
#include <string>

//#include <fmt/format.h>

namespace sys {

    inline std::string error_string(const int error) noexcept
    {
#if defined(__GLIBC__) && defined(_GNU_SOURCE)
        char buffer[256];
        char* result = strerror_r(error, buffer, 255);
        return std::string(result);
#else
        char buffer[256];
        strerror_r(error, buffer, 255);
        return std::string(buffer);
#endif
//#else
//        return fmt::format("{0}", error);
//#endif
    }
}
