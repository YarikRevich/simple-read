// Generated by gmmproc 2.66.2 -- DO NOT MODIFY!
#ifndef _PANGOMM_FONT_H
#define _PANGOMM_FONT_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* font.h
 * 
 * Copyright (C) 1998-1999 The gtkmm Development Team 
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


#include <glibmm/object.h>
#include <pangomm/rectangle.h>
#include <pangomm/language.h>
#include <pangomm/glyph.h>
#include <pangomm/fontdescription.h>
#include <pangomm/fontmetrics.h>
#include <pangomm/coverage.h>
#include <pango/pango.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using PangoFont = struct _PangoFont;
using PangoFontClass = struct _PangoFontClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Pango
{ class PANGOMM_API Font_Class; } // namespace Pango
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Pango
{

const int    SCALE          = 1024;
const double SCALE_XX_SMALL = 0.5787037037037;
const double SCALE_X_SMALL  = 0.6444444444444;
const double SCALE_SMALL    = 0.8333333333333;
const double SCALE_MEDIUM   = 1.0;
const double SCALE_LARGE    = 1.2;
const double SCALE_X_LARGE  = 1.4399999999999;
const double SCALE_XX_LARGE = 1.728;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
class PANGOMM_API FontFace;
class PANGOMM_API FontMap;
#endif //DOXYGEN_SHOULD_SKIP_THIS

/** A Pango::Font is used to represent a font in a rendering-system-independent matter.
 */

class PANGOMM_API Font : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Font;
  using CppClassType = Font_Class;
  using BaseObjectType = PangoFont;
  using BaseClassType = PangoFontClass;

  // noncopyable
  Font(const Font&) = delete;
  Font& operator=(const Font&) = delete;

private:  friend class Font_Class;
  static CppClassType font_class_;

protected:
  explicit Font(const Glib::ConstructParams& construct_params);
  explicit Font(PangoFont* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Font(Font&& src) noexcept;
  Font& operator=(Font&& src) noexcept;

  ~Font() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  PangoFont*       gobj()       { return reinterpret_cast<PangoFont*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const PangoFont* gobj() const { return reinterpret_cast<PangoFont*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  PangoFont* gobj_copy();

private:

   // Deprecated

public:
  
  /** Returns a description of the font, with font size set in points.
   * Use describe_with_absolute_size() if you want the font
   * size in device units.
   * 
   * @return A newly-allocated Pango::FontDescription object.
   */
  FontDescription describe() const;
  
  /** Returns a description of the font, with absolute font size set
   * (in device units). Use describe() if you want the font
   * size in points.
   * 
   * @newin{1,14}
   * 
   * @return A newly-allocated Pango::FontDescription object.
   */
  FontDescription describe_with_absolute_size() const;
  
  /** Computes the coverage map for a given font and language tag.
   * 
   * @param language The language tag.
   * @return A newly-allocated Pango::Coverage
   * object.
   */
  Glib::RefPtr<Coverage> get_coverage(const Language& language) const;

  /** Gets overall metric information for a font.
   * The metrics may be substantially different for different scripts.
   * However, this function overload returns the metrics for the entire font.
   */
  FontMetrics get_metrics() const;
  
  /** Gets overall metric information for a font. Since the metrics may be
   * substantially different for different scripts, a language tag can
   * be provided to indicate that the metrics should be retrieved that
   * correspond to the script(s) used by that language.
   * 
   * @param language Language tag used to determine which script to get the metrics
   * for.
   * @return A Pango::Metrics object.
   */
  FontMetrics get_metrics(const Language& language) const;

  
  /** Gets the logical and ink extents of a glyph within a font. The
   * coordinate system for each rectangle has its origin at the
   * base line and horizontal origin of the character with increasing
   * coordinates extending to the right and down. The macros PANGO_ASCENT(),
   * PANGO_DESCENT(), PANGO_LBEARING(), and PANGO_RBEARING can be used to convert
   * from the extents rectangle to more traditional font metrics. The units
   * of the rectangles are in 1/PANGO_SCALE of a device unit.
   * 
   * @param glyph The glyph index.
   * @param ink_rect Rectangle used to store the extents of the glyph as drawn.
   * @param logical_rect Rectangle used to store the logical extents of the glyph.
   */
  void get_glyph_extents(Glyph glyph, Rectangle& ink_rect, Rectangle& logical_rect) const;

  
  /** Gets the font map for which the font was created.
   * 
   * Note that the font maintains a <firstterm>weak</firstterm> reference
   * to the font map, so if all references to font map are dropped, the font
   * map will be finalized even if there are fonts created with the font
   * map that are still alive.  In that case this function will return <tt>nullptr</tt>.
   * It is the responsibility of the user to ensure that the font map is kept
   * alive.  In most uses this is not an issue as a Pango::Context holds
   * a reference to the font map.
   * 
   * @newin{1,10}
   * 
   * @return The Pango::FontMap for the
   * font, or <tt>nullptr</tt> if @a font is <tt>nullptr</tt>.
   */
  Glib::RefPtr<FontMap> get_font_map();
  
  /** Gets the font map for which the font was created.
   * 
   * Note that the font maintains a <firstterm>weak</firstterm> reference
   * to the font map, so if all references to font map are dropped, the font
   * map will be finalized even if there are fonts created with the font
   * map that are still alive.  In that case this function will return <tt>nullptr</tt>.
   * It is the responsibility of the user to ensure that the font map is kept
   * alive.  In most uses this is not an issue as a Pango::Context holds
   * a reference to the font map.
   * 
   * @newin{1,10}
   * 
   * @return The Pango::FontMap for the
   * font, or <tt>nullptr</tt> if @a font is <tt>nullptr</tt>.
   */
  Glib::RefPtr<const FontMap> get_font_map() const;

  
  /** Gets the Pango::FontFace to which @a font belongs.
   * 
   * @newin{1,46}
   * 
   * @return The Pango::FontFace.
   */
  Glib::RefPtr<FontFace> get_face();
  
  /** Gets the Pango::FontFace to which @a font belongs.
   * 
   * @newin{1,46}
   * 
   * @return The Pango::FontFace.
   */
  Glib::RefPtr<const FontFace> get_face() const;

  
  /** Returns whether the font provides a glyph for this character.
   * 
   * @newin{1,44}
   * 
   * @param wc A Unicode character.
   * @return <tt>true</tt> if @a font can render @a wc.
   */
  bool has_char(gunichar wc) const;

  /** Get the ink extents of a glyph within the font.
   * @param glyph The glyph index.
   * @return The extents of the glyph as drawn.
   */
  Rectangle get_glyph_ink_extents(Glyph glyph) const;

  /** Gets the logical extents of a glyph within the font.
   * @param glyph The glyph index.
   * @return The logical extents of the glyph.
   */
  Rectangle get_glyph_logical_extents(Glyph glyph) const;

// PangoFontClass is hidden when PANGO_DISABLE_DEPRECATED is defined.
// Don't wrap vfuncs.


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} /* namespace Pango */


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Pango::Font
   */
  PANGOMM_API
  Glib::RefPtr<Pango::Font> wrap(PangoFont* object, bool take_copy = false);
}


#endif /* _PANGOMM_FONT_H */

