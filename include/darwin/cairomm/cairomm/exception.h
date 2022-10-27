/* Copyright (C) 2005 The cairomm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#ifndef __CAIRO_EXCEPTION_H
#define __CAIRO_EXCEPTION_H

#include <cairommconfig.h>

#include <cairomm/enums.h>
#include <stdexcept>

#if defined(_MSC_VER) && (_MSC_VER < 1900)
#define _ALLOW_KEYWORD_MACROS 1
#define noexcept _NOEXCEPT
#endif

namespace Cairo
{

/** 
 */
class logic_error: public std::logic_error
{
public:
  CAIROMM_API explicit logic_error(ErrorStatus status);
  CAIROMM_API ~logic_error() noexcept override;

  //virtual const char* what() const noexcept;
  CAIROMM_API ErrorStatus get_status_code() const;

private:
  ErrorStatus m_status;
};

} // namespace Cairo

#endif // __CAIRO_EXCEPTION_H

// vim: ts=2 sw=2 et
