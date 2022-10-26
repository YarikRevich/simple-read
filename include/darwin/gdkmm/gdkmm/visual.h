// Generated by gmmproc 2.66.4 -- DO NOT MODIFY!
#ifndef _GDKMM_VISUAL_H
#define _GDKMM_VISUAL_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* visual.h
 *
 * Copyright (C) 1998-2002 The gtkmm Development Team
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
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include <glibmm/object.h>
#include <gdkmm/screen.h>
#include <gdkmm/types.h>
//#include <gdk/gdk.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GdkVisual = struct _GdkVisual;
using GdkVisualClass = struct _GdkVisualClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gdk
{ class GDKMM_API Visual_Class; } // namespace Gdk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gdk
{

class GDKMM_API Screen;

/** @addtogroup gdkmmEnums gdkmm Enums and Flags */

/** 
 *  @var VisualType VISUAL_STATIC_GRAY
 * Each pixel value indexes a grayscale value
 * directly.
 * 
 *  @var VisualType VISUAL_GRAYSCALE
 * Each pixel is an index into a color map that
 * maps pixel values into grayscale values. The color map can be
 * changed by an application.
 * 
 *  @var VisualType VISUAL_STATIC_COLOR
 * Each pixel value is an index into a predefined,
 * unmodifiable color map that maps pixel values into RGB values.
 * 
 *  @var VisualType VISUAL_PSEUDO_COLOR
 * Each pixel is an index into a color map that
 * maps pixel values into rgb values. The color map can be changed by
 * an application.
 * 
 *  @var VisualType VISUAL_TRUE_COLOR
 * Each pixel value directly contains red, green,
 * and blue components. Use Gdk::Visual::get_red_pixel_details(), etc,
 * to obtain information about how the components are assembled into
 * a pixel value.
 * 
 *  @var VisualType VISUAL_DIRECT_COLOR
 * Each pixel value contains red, green, and blue
 * components as for Gdk::VISUAL_TRUE_COLOR, but the components are
 * mapped via a color table into the final output table instead of
 * being converted directly.
 * 
 *  @enum VisualType
 * 
 * A set of values that describe the manner in which the pixel values
 * for a visual are converted into RGB values for display.
 *
 * @ingroup gdkmmEnums
 */
enum VisualType
{
  VISUAL_STATIC_GRAY,
  VISUAL_GRAYSCALE,
  VISUAL_STATIC_COLOR,
  VISUAL_PSEUDO_COLOR,
  VISUAL_TRUE_COLOR,
  VISUAL_DIRECT_COLOR
};

} // namespace Gdk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GDKMM_API Value<Gdk::VisualType> : public Glib::Value_Enum<Gdk::VisualType>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gdk
{


/** A Gdk::Visual describes a particular video hardware display format.
 * It includes information about the number of bits used for each color, the way the bits are translated into an RGB value
 * for display, and the way the bits are stored in memory. For example, a piece of display hardware might support 24-bit
 * color, 16-bit color, or 8-bit color; meaning 24/16/8-bit pixel sizes. For a given pixel size, pixels can be in different
 * formats; for example the "red" element of an RGB pixel may be in the top 8 bits of the pixel, or may be in the lower 4
 * bits.
 *
 * There are several standard visuals. The visual returned by Gdk::Screen::get_system_visual() is the system's default visual.
 *
 * A number of methods are provided for determining the "best" available visual. For the purposes of making this
 * determination, higher bit depths are considered better, and for visuals of the same bit depth, GDK_VISUAL_PSEUDO_COLOR
 * is preferred at 8bpp, otherwise, the visual types are ranked in the order of (highest to lowest) GDK_VISUAL_DIRECT_COLOR,
 * GDK_VISUAL_TRUE_COLOR, GDK_VISUAL_PSEUDO_COLOR, GDK_VISUAL_STATIC_COLOR, GDK_VISUAL_GRAYSCALE, then
 * GDK_VISUAL_STATIC_GRAY.
 */

class GDKMM_API Visual : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = Visual;
  using CppClassType = Visual_Class;
  using BaseObjectType = GdkVisual;
  using BaseClassType = GdkVisualClass;

  // noncopyable
  Visual(const Visual&) = delete;
  Visual& operator=(const Visual&) = delete;

private:  friend class Visual_Class;
  static CppClassType visual_class_;

protected:
  explicit Visual(const Glib::ConstructParams& construct_params);
  explicit Visual(GdkVisual* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  Visual(Visual&& src) noexcept;
  Visual& operator=(Visual&& src) noexcept;

  ~Visual() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GdkVisual*       gobj()       { return reinterpret_cast<GdkVisual*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GdkVisual* gobj() const { return reinterpret_cast<GdkVisual*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GdkVisual* gobj_copy();

private:

protected:

  Visual();

public:
   
#ifndef GDKMM_DISABLE_DEPRECATED

  /** Get the system’s default visual for the default GDK screen.
   * This is the visual for the root window of the display.
   * The return value should not be freed.
   * 
   * Deprecated: 3.22: Use gdk_screen_get_system_visual (Gdk::Screen::get_default()).
   * 
   * @deprecated Use Gdk::Screen::get_system_visual() (and Gdk::Screen::get_default()) instead.
   * 
   * @return System visual.
   */
  static Glib::RefPtr<Visual> get_system();
#endif // GDKMM_DISABLE_DEPRECATED


#ifndef GDKMM_DISABLE_DEPRECATED

  /** Get the visual with the most available colors for the default
   * GDK screen. The return value should not be freed.
   * 
   * Deprecated: 3.22: Visual selection should be done using
   * Gdk::Screen::get_system_visual() and Gdk::Screen::get_rgba_visual()
   * 
   * @deprecated Visual selection should be done using Gdk::Screen::get_system_visual() and Gdk::Screen::get_rgba_visual().
   * 
   * @return Best visual.
   */
  static Glib::RefPtr<Visual> get_best();
#endif // GDKMM_DISABLE_DEPRECATED


#ifndef GDKMM_DISABLE_DEPRECATED

  /** Get the best visual with depth @a depth for the default GDK screen.
   * Color visuals and visuals with mutable colormaps are preferred
   * over grayscale or fixed-colormap visuals. The return value should
   * not be freed. <tt>nullptr</tt> may be returned if no visual supports @a depth.
   * 
   * Deprecated: 3.22: Visual selection should be done using
   * Gdk::Screen::get_system_visual() and Gdk::Screen::get_rgba_visual()
   * 
   * @deprecated Visual selection should be done using Gdk::Screen::get_system_visual() and Gdk::Screen::get_rgba_visual().
   * 
   * @param depth A bit depth.
   * @return Best visual for the given depth.
   */
  static Glib::RefPtr<Visual> get_best(int depth);
#endif // GDKMM_DISABLE_DEPRECATED


#ifndef GDKMM_DISABLE_DEPRECATED

  /** Get the best visual of the given @a visual_type for the default GDK screen.
   * Visuals with higher color depths are considered better. The return value
   * should not be freed. <tt>nullptr</tt> may be returned if no visual has type
   *  @a visual_type.
   * 
   * Deprecated: 3.22: Visual selection should be done using
   * Gdk::Screen::get_system_visual() and Gdk::Screen::get_rgba_visual()
   * 
   * @deprecated Visual selection should be done using Gdk::Screen::get_system_visual() and Gdk::Screen::get_rgba_visual().
   * 
   * @param visual_type A visual type.
   * @return Best visual of the given type.
   */
  static Glib::RefPtr<Visual> get_best(VisualType visual_type);
#endif // GDKMM_DISABLE_DEPRECATED


#ifndef GDKMM_DISABLE_DEPRECATED

  /** Combines get_best_with_depth() and
   * get_best_with_type().
   * 
   * Deprecated: 3.22: Visual selection should be done using
   * Gdk::Screen::get_system_visual() and Gdk::Screen::get_rgba_visual()
   * 
   * @deprecated Visual selection should be done using Gdk::Screen::get_system_visual() and Gdk::Screen::get_rgba_visual().
   * 
   * @param depth A bit depth.
   * @param visual_type A visual type.
   * @return Best visual with both @a depth
   * and @a visual_type, or <tt>nullptr</tt> if none.
   */
  static Glib::RefPtr<Visual> get_best(int depth, VisualType visual_type);
#endif // GDKMM_DISABLE_DEPRECATED


#ifndef GDKMM_DISABLE_DEPRECATED

  /** Get the best available depth for the default GDK screen.  “Best”
   * means “largest,” i.e. 32 preferred over 24 preferred over 8 bits
   * per pixel.
   * 
   * Deprecated: 3.22: Visual selection should be done using
   * Gdk::Screen::get_system_visual() and Gdk::Screen::get_rgba_visual()
   * 
   * @deprecated Visual selection should be done using Gdk::Screen::get_system_visual() and Gdk::Screen::get_rgba_visual().
   * 
   * @return Best available depth.
   */
  static int get_best_depth();
#endif // GDKMM_DISABLE_DEPRECATED


#ifndef GDKMM_DISABLE_DEPRECATED

  /** Return the best available visual type for the default GDK screen.
   * 
   * Deprecated: 3.22: Visual selection should be done using
   * Gdk::Screen::get_system_visual() and Gdk::Screen::get_rgba_visual()
   * 
   * @deprecated Visual selection should be done using Gdk::Screen::get_system_visual() and Gdk::Screen::get_rgba_visual().
   * 
   * @return Best visual type.
   */
  static VisualType get_best_type();
#endif // GDKMM_DISABLE_DEPRECATED


  /** Gets the screen to which this visual belongs
   * 
   * @newin{2,2}
   * 
   * @return The screen to which this visual belongs.
   */
  Glib::RefPtr<Screen> get_screen();
   
  /** Gets the screen to which this visual belongs
   * 
   * @newin{2,2}
   * 
   * @return The screen to which this visual belongs.
   */
  Glib::RefPtr<const Screen> get_screen() const;


  /** Returns the type of visual this is (PseudoColor, TrueColor, etc).
   * 
   * @newin{2,22}
   * 
   * @return A Gdk::VisualType stating the type of @a visual.
   */
  VisualType get_visual_type() const;
   
  /** Returns the bit depth of this visual.
   * 
   * @newin{2,22}
   * 
   * @return The bit depth of this visual.
   */
  int get_depth() const;
   
#ifndef GDKMM_DISABLE_DEPRECATED

  /** Returns the byte order of this visual.
   * 
   * The information returned by this function is only relevant
   * when working with XImages, and not all backends return
   * meaningful information for this.
   * 
   * @newin{2,22}
   * 
   * Deprecated: 3.22: This information is not useful
   * 
   * @deprecated This information is not useful.
   * 
   * @return A Gdk::ByteOrder stating the byte order of @a visual.
   */
  ByteOrder get_byte_order();
#endif // GDKMM_DISABLE_DEPRECATED


#ifndef GDKMM_DISABLE_DEPRECATED

  /** Returns the size of a colormap for this visual.
   * 
   * You have to use platform-specific APIs to manipulate colormaps.
   * 
   * @newin{2,22}
   * 
   * Deprecated: 3.22: This information is not useful, since GDK does not
   * provide APIs to operate on colormaps.
   * 
   * @deprecated This information is not useful, since GDK does not provide APIs to operate on colormaps.
   * 
   * @return The size of a colormap that is suitable for @a visual.
   */
  int get_colormap_size() const;
#endif // GDKMM_DISABLE_DEPRECATED


#ifndef GDKMM_DISABLE_DEPRECATED

  /** Returns the number of significant bits per red, green and blue value.
   * 
   * Not all GDK backend provide a meaningful value for this function.
   * 
   * @newin{2,22}
   * 
   * Deprecated: 3.22. Use get_red_pixel_details() and its variants to
   * learn about the pixel layout of TrueColor and DirectColor visuals
   * 
   * @deprecated Use get_red_pixel_details() and its variants to learn about the pixel layout of TrueColor and DirectColor visuals.
   * 
   * @return The number of significant bits per color value for @a visual.
   */
  int get_bits_per_rgb() const;
#endif // GDKMM_DISABLE_DEPRECATED


  /** Obtains values that are needed to calculate red pixel values in TrueColor
   * and DirectColor. The “mask” is the significant bits within the pixel.
   * The “shift” is the number of bits left we must shift a primary for it
   * to be in position (according to the "mask"). Finally, "precision" refers
   * to how much precision the pixel value contains for a particular primary.
   * 
   * @newin{2,22}
   * 
   * @param mask A pointer to a #guint32 to be filled in, or <tt>nullptr</tt>.
   * @param shift A pointer to a <tt>int</tt> to be filled in, or <tt>nullptr</tt>.
   * @param precision A pointer to a <tt>int</tt> to be filled in, or <tt>nullptr</tt>.
   */
  void get_red_pixel_details(guint32& mask, int& shift, int& precision) const;
   
  /** Obtains values that are needed to calculate green pixel values in TrueColor
   * and DirectColor. The “mask” is the significant bits within the pixel.
   * The “shift” is the number of bits left we must shift a primary for it
   * to be in position (according to the "mask"). Finally, "precision" refers
   * to how much precision the pixel value contains for a particular primary.
   * 
   * @newin{2,22}
   * 
   * @param mask A pointer to a #guint32 to be filled in, or <tt>nullptr</tt>.
   * @param shift A pointer to a <tt>int</tt> to be filled in, or <tt>nullptr</tt>.
   * @param precision A pointer to a <tt>int</tt> to be filled in, or <tt>nullptr</tt>.
   */
  void get_green_pixel_details(guint32& mask, int& shift, int& precision) const;
   
  /** Obtains values that are needed to calculate blue pixel values in TrueColor
   * and DirectColor. The “mask” is the significant bits within the pixel.
   * The “shift” is the number of bits left we must shift a primary for it
   * to be in position (according to the "mask"). Finally, "precision" refers
   * to how much precision the pixel value contains for a particular primary.
   * 
   * @newin{2,22}
   * 
   * @param mask A pointer to a #guint32 to be filled in, or <tt>nullptr</tt>.
   * @param shift A pointer to a <tt>int</tt> to be filled in, or <tt>nullptr</tt>.
   * @param precision A pointer to a <tt>int</tt> to be filled in, or <tt>nullptr</tt>.
   */
  void get_blue_pixel_details(guint32& mask, int& shift, int& precision) const;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} //namespace Gdk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gdk::Visual
   */
  GDKMM_API
  Glib::RefPtr<Gdk::Visual> wrap(GdkVisual* object, bool take_copy = false);
}


#endif /* _GDKMM_VISUAL_H */

