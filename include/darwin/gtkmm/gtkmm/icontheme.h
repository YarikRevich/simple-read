// Generated by gmmproc 2.66.4 -- DO NOT MODIFY!
#ifndef _GTKMM_ICONTHEME_H
#define _GTKMM_ICONTHEME_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2003 The gtkmm Development Team
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

#include <vector>

#include <gdkmm/pixbuf.h>
#include <gdkmm/screen.h>

#include <gtkmm/iconinfo.h>
#include <giomm/icon.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkIconTheme = struct _GtkIconTheme;
using GtkIconThemeClass = struct _GtkIconThemeClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API IconTheme_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

/** 
 *  @var IconLookupFlags ICON_LOOKUP_NO_SVG
 * Never get SVG icons, even if gdk-pixbuf
 * supports them. Cannot be used together with Gtk::ICON_LOOKUP_FORCE_SVG.
 * 
 *  @var IconLookupFlags ICON_LOOKUP_FORCE_SVG
 * Get SVG icons, even if gdk-pixbuf
 * doesn’t support them.
 * Cannot be used together with Gtk::ICON_LOOKUP_NO_SVG.
 * 
 *  @var IconLookupFlags ICON_LOOKUP_USE_BUILTIN
 * When passed to
 * Gtk::IconTheme::lookup_icon() includes builtin icons
 * as well as files. For a builtin icon, Gtk::IconInfo::get_filename()
 * is <tt>nullptr</tt> and you need to call Gtk::IconInfo::get_builtin_pixbuf().
 * 
 *  @var IconLookupFlags ICON_LOOKUP_GENERIC_FALLBACK
 * Try to shorten icon name at '-'
 * characters before looking at inherited themes. This flag is only
 * supported in functions that take a single icon name. For more general
 * fallback, see Gtk::IconTheme::choose_icon(). @newin{2,12}
 * 
 *  @var IconLookupFlags ICON_LOOKUP_FORCE_SIZE
 * Always get the icon scaled to the
 * requested size. @newin{2,14}
 * 
 *  @var IconLookupFlags ICON_LOOKUP_FORCE_REGULAR
 * Try to always load regular icons, even
 * when symbolic icon names are given. @newin{3,14}
 * 
 *  @var IconLookupFlags ICON_LOOKUP_FORCE_SYMBOLIC
 * Try to always load symbolic icons, even
 * when regular icon names are given. @newin{3,14}
 * 
 *  @var IconLookupFlags ICON_LOOKUP_DIR_LTR
 * Try to load a variant of the icon for left-to-right
 * text direction. @newin{3,14}
 * 
 *  @var IconLookupFlags ICON_LOOKUP_DIR_RTL
 * Try to load a variant of the icon for right-to-left
 * text direction. @newin{3,14}
 * 
 *  @enum IconLookupFlags
 * 
 * Used to specify options for Gtk::IconTheme::lookup_icon()
 *
 * @ingroup gtkmmEnums
 * @par Bitwise operators:
 * <tt>%IconLookupFlags operator|(IconLookupFlags, IconLookupFlags)</tt><br>
 * <tt>%IconLookupFlags operator&(IconLookupFlags, IconLookupFlags)</tt><br>
 * <tt>%IconLookupFlags operator^(IconLookupFlags, IconLookupFlags)</tt><br>
 * <tt>%IconLookupFlags operator~(IconLookupFlags)</tt><br>
 * <tt>%IconLookupFlags& operator|=(IconLookupFlags&, IconLookupFlags)</tt><br>
 * <tt>%IconLookupFlags& operator&=(IconLookupFlags&, IconLookupFlags)</tt><br>
 * <tt>%IconLookupFlags& operator^=(IconLookupFlags&, IconLookupFlags)</tt><br>
 */
enum IconLookupFlags
{
  ICON_LOOKUP_NO_SVG = 1 << 0,
  ICON_LOOKUP_FORCE_SVG = 1 << 1,
  ICON_LOOKUP_USE_BUILTIN = 1 << 2,
  ICON_LOOKUP_GENERIC_FALLBACK = 1 << 3,
  ICON_LOOKUP_FORCE_SIZE = 1 << 4,
  ICON_LOOKUP_FORCE_REGULAR = 1 << 5,
  ICON_LOOKUP_FORCE_SYMBOLIC = 1 << 6,
  ICON_LOOKUP_DIR_LTR = 1 << 7,
  ICON_LOOKUP_DIR_RTL = 1 << 8
};

/** @ingroup gtkmmEnums */
inline IconLookupFlags operator|(IconLookupFlags lhs, IconLookupFlags rhs)
  { return static_cast<IconLookupFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline IconLookupFlags operator&(IconLookupFlags lhs, IconLookupFlags rhs)
  { return static_cast<IconLookupFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline IconLookupFlags operator^(IconLookupFlags lhs, IconLookupFlags rhs)
  { return static_cast<IconLookupFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline IconLookupFlags operator~(IconLookupFlags flags)
  { return static_cast<IconLookupFlags>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline IconLookupFlags& operator|=(IconLookupFlags& lhs, IconLookupFlags rhs)
  { return (lhs = static_cast<IconLookupFlags>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline IconLookupFlags& operator&=(IconLookupFlags& lhs, IconLookupFlags rhs)
  { return (lhs = static_cast<IconLookupFlags>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline IconLookupFlags& operator^=(IconLookupFlags& lhs, IconLookupFlags rhs)
  { return (lhs = static_cast<IconLookupFlags>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }


/**  %Exception class for Gtk::IconTheme errors.
 */
class GTKMM_API IconThemeError : public Glib::Error
{
public:
  /**  @var Code ICON_THEME_NOT_FOUND
   * The icon specified does not exist in the theme.
   * 
   *  @var Code ICON_THEME_FAILED
   * An unspecified error occurred.
   * 
   *  @enum Code
   * 
   * %Error codes for GtkIconTheme operations.
   */
  enum Code
  {
    ICON_THEME_NOT_FOUND,
    ICON_THEME_FAILED
  };

  IconThemeError(Code error_code, const Glib::ustring& error_message);
  explicit IconThemeError(GError* gobject);
  Code code() const;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
private:

  static void throw_func(GError* gobject);

  friend GTKMM_API void wrap_init(); // uses throw_func()

  #endif //DOXYGEN_SHOULD_SKIP_THIS
};

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::IconThemeError::Code> : public Glib::Value_Enum<Gtk::IconThemeError::Code>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


class GTKMM_API IconTheme : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = IconTheme;
  using CppClassType = IconTheme_Class;
  using BaseObjectType = GtkIconTheme;
  using BaseClassType = GtkIconThemeClass;

  // noncopyable
  IconTheme(const IconTheme&) = delete;
  IconTheme& operator=(const IconTheme&) = delete;

private:  friend class IconTheme_Class;
  static CppClassType icontheme_class_;

protected:
  explicit IconTheme(const Glib::ConstructParams& construct_params);
  explicit IconTheme(GtkIconTheme* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  IconTheme(IconTheme&& src) noexcept;
  IconTheme& operator=(IconTheme&& src) noexcept;

  ~IconTheme() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GtkIconTheme*       gobj()       { return reinterpret_cast<GtkIconTheme*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GtkIconTheme* gobj() const { return reinterpret_cast<GtkIconTheme*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GtkIconTheme* gobj_copy();

private:

  
protected:
  IconTheme();
public:
  
  static Glib::RefPtr<IconTheme> create();


  /** Gets the icon theme for the default screen. See
   * get_for_screen().
   * 
   * @newin{2,4}
   * 
   * @return A unique Gtk::IconTheme associated with
   * the default screen. This icon theme is associated with
   * the screen and can be used as long as the screen
   * is open. Do not ref or unref it.
   */
  static Glib::RefPtr<IconTheme> get_default();
  
  /** Gets the icon theme object associated with @a screen; if this
   * function has not previously been called for the given
   * screen, a new icon theme object will be created and
   * associated with the screen. Icon theme objects are
   * fairly expensive to create, so using this function
   * is usually a better choice than calling than new()
   * and setting the screen yourself; by using this function
   * a single icon theme object will be shared between users.
   * 
   * @newin{2,4}
   * 
   * @param screen A Gdk::Screen.
   * @return A unique Gtk::IconTheme associated with
   * the given screen. This icon theme is associated with
   * the screen and can be used as long as the screen
   * is open. Do not ref or unref it.
   */
  static Glib::RefPtr<IconTheme> get_for_screen(const Glib::RefPtr<Gdk::Screen>& screen);
  
  /** Sets the screen for an icon theme; the screen is used
   * to track the user’s currently configured icon theme,
   * which might be different for different screens.
   * 
   * @newin{2,4}
   * 
   * @param screen A Gdk::Screen.
   */
  void set_screen(const Glib::RefPtr<Gdk::Screen>& screen);
  void set_search_path(const std::vector<Glib::ustring>& path);
  std::vector<Glib::ustring> get_search_path() const;
  
  /** Appends a directory to the search path. 
   * See set_search_path(). 
   * 
   * @newin{2,4}
   * 
   * @param path Directory name to append to the icon path.
   */
  void append_search_path(const Glib::ustring& path);
  
  /** Prepends a directory to the search path. 
   * See set_search_path().
   * 
   * @newin{2,4}
   * 
   * @param path Directory name to prepend to the icon path.
   */
  void prepend_search_path(const Glib::ustring& path);

  
  /** Adds a resource path that will be looked at when looking
   * for icons, similar to search paths.
   * 
   * This function should be used to make application-specific icons
   * available as part of the icon theme.
   * 
   * The resources are considered as part of the hicolor icon theme
   * and must be located in subdirectories that are defined in the
   * hicolor icon theme, such as ` @a path/16x16/actions/run.png`.
   * Icons that are directly placed in the resource path instead
   * of a subdirectory are also considered as ultimate fallback.
   * 
   * @newin{3,14}
   * 
   * @param path A resource path.
   */
  void add_resource_path(const std::string& path);

  
  /** Sets the name of the icon theme that the Gtk::IconTheme object uses
   * overriding system configuration. This function cannot be called
   * on the icon theme objects returned from get_default()
   * and get_for_screen().
   * 
   * @newin{2,4}
   * 
   * @param theme_name Name of icon theme to use instead of
   * configured theme, or <tt>nullptr</tt> to unset a previously set custom theme.
   */
  void set_custom_theme(const Glib::ustring& theme_name);
  
  /** Checks whether an icon theme includes an icon
   * for a particular name.
   * 
   * @newin{2,4}
   * 
   * @param icon_name The name of an icon.
   * @return <tt>true</tt> if @a icon_theme includes an
   * icon for @a icon_name.
   */
  bool has_icon(const Glib::ustring& icon_name) const;

  std::vector<int> get_icon_sizes(const Glib::ustring& icon_name) const;
  

  /** Looks up a named icon and returns a structure containing
   * information such as the filename of the icon. The icon
   * can then be rendered into a pixbuf using
   * Gtk::IconInfo::load_icon(). (load_icon()
   * combines these two steps if all you need is the pixbuf.)
   * 
   * @newin{2,4}
   * 
   * @param icon_name The name of the icon to lookup.
   * @param size Desired icon size.
   * @param flags Flags modifying the behavior of the icon lookup.
   * @return An IconInfo structure containing information
   * about the icon. IconInfo::operator bool() will return false if the icon wasn't found.
   * For instance, if (icon_info) { ... }.
   */
  IconInfo lookup_icon(const Glib::ustring& icon_name, int size, IconLookupFlags flags =  (IconLookupFlags)0) const;
  
  /** Looks up a named icon for a particular window scale and returns a
   * Gtk::IconInfo containing information such as the filename of the
   * icon. The icon can then be rendered into a pixbuf using
   * Gtk::IconInfo::load_icon(). (load_icon() combines
   * these two steps if all you need is the pixbuf.)
   * 
   * @newin{3,10}
   * 
   * @param icon_name The name of the icon to lookup.
   * @param size Desired icon size.
   * @param scale The desired scale.
   * @param flags Flags modifying the behavior of the icon lookup.
   * @return A Gtk::IconInfo object
   * containing information about the icon, or <tt>nullptr</tt> if the
   * icon wasn’t found.
   */
  IconInfo lookup_icon(const Glib::ustring& icon_name, int size, int scale, IconLookupFlags flags =  (IconLookupFlags)0) const;
  
  /** Looks up an icon and returns a Gtk::IconInfo containing information
   * such as the filename of the icon. The icon can then be rendered
   * into a pixbuf using Gtk::IconInfo::load_icon().
   * 
   * When rendering on displays with high pixel densities you should not
   * use a @a size multiplied by the scaling factor returned by functions
   * like gdk_window_get_scale_factor(). Instead, you should use
   * lookup_by_gicon_for_scale(), as the assets loaded
   * for a given scaling factor may be different.
   * 
   * @newin{2,14}
   * 
   * @param icon The Gio::Icon to look up.
   * @param size Desired icon size.
   * @param flags Flags modifying the behavior of the icon lookup.
   * @return A Gtk::IconInfo containing
   * information about the icon, or <tt>nullptr</tt> if the icon wasn’t
   * found. Unref with Glib::object_unref().
   */
  IconInfo lookup_icon(const Glib::RefPtr<const Gio::Icon>& icon, int size, IconLookupFlags flags =  (IconLookupFlags)0) const;
  
  /** Looks up an icon and returns a Gtk::IconInfo containing information
   * such as the filename of the icon. The icon can then be rendered into
   * a pixbuf using Gtk::IconInfo::load_icon().
   * 
   * @newin{3,10}
   * 
   * @param icon The Gio::Icon to look up.
   * @param size Desired icon size.
   * @param scale The desired scale.
   * @param flags Flags modifying the behavior of the icon lookup.
   * @return A Gtk::IconInfo containing
   * information about the icon, or <tt>nullptr</tt> if the icon wasn’t
   * found. Unref with Glib::object_unref().
   */
  IconInfo lookup_icon(const Glib::RefPtr<const Gio::Icon>& icon, int size, int scale, IconLookupFlags flags =  (IconLookupFlags)0) const;

   
  /** Looks up a named icon and returns a structure containing
   * information such as the filename of the icon. The icon
   * can then be rendered into a pixbuf using
   * Gtk::IconInfo::load_icon(). (load_icon()
   * combines these two steps if all you need is the pixbuf.)
   * 
   * If @a icon_names contains more than one name, this function 
   * tries them all in the given order before falling back to 
   * inherited icon themes.
   * 
   * @newin{2,12}
   * 
   * @param icon_names Array of icon names to lookup.
   * @param size Desired icon size.
   * @param flags Flags modifying the behavior of the icon lookup.
   * @return A Gtk::IconInfo structure containing information
   * about the icon. IconInfo::operator bool() will be false if the icon wasn't found - 
   * for instance, if (icon_info) { ... }.
   */
  IconInfo choose_icon(const std::vector<Glib::ustring>& icon_names, int size, IconLookupFlags flags =  (IconLookupFlags)0);
  
  /** Looks up a named icon for a particular window scale and returns
   * a Gtk::IconInfo containing information such as the filename of the
   * icon. The icon can then be rendered into a pixbuf using
   * Gtk::IconInfo::load_icon(). (load_icon()
   * combines these two steps if all you need is the pixbuf.)
   * 
   * If @a icon_names contains more than one name, this function 
   * tries them all in the given order before falling back to 
   * inherited icon themes.
   * 
   * @newin{3,10}
   * 
   * @param icon_names <tt>nullptr</tt>-terminated
   * array of icon names to lookup.
   * @param size Desired icon size.
   * @param scale Desired scale.
   * @param flags Flags modifying the behavior of the icon lookup.
   * @return A Gtk::IconInfo object
   * containing information about the icon, or <tt>nullptr</tt> if the
   * icon wasn’t found.
   */
  IconInfo choose_icon(const std::vector<Glib::ustring>& icon_names, int size, int scale, IconLookupFlags flags =  (IconLookupFlags)0);

  
  /** Looks up an icon in an icon theme, scales it to the given size
   * and renders it into a pixbuf. This is a convenience function;
   * if more details about the icon are needed, use
   * lookup_icon() followed by Gtk::IconInfo::load_icon().
   * 
   * Note that you probably want to listen for icon theme changes and
   * update the icon. This is usually done by connecting to the
   * GtkWidget::style-set signal. If for some reason you do not want to
   * update the icon when the icon theme changes, you should consider
   * using gdk_pixbuf_copy() to make a private copy of the pixbuf
   * returned by this function. Otherwise GTK+ may need to keep the old
   * icon theme loaded, which would be a waste of memory.
   * 
   * @newin{2,4}
   * 
   * @param icon_name The name of the icon to lookup.
   * @param size The desired icon size. The resulting icon may not be
   * exactly this size; see Gtk::IconInfo::load_icon().
   * @param flags Flags modifying the behavior of the icon lookup.
   * @return The rendered icon; this may be
   * a newly created icon or a new reference to an internal icon, so
   * you must not modify the icon. Use Glib::object_unref() to release
   * your reference to the icon. <tt>nullptr</tt> if the icon isn’t found.
   * 
   * @throws Glib::Error
   */
  Glib::RefPtr<Gdk::Pixbuf> load_icon(const Glib::ustring& icon_name, int size, IconLookupFlags flags =  (IconLookupFlags)0) const;
    
  /** Looks up an icon in an icon theme for a particular window scale,
   * scales it to the given size and renders it into a pixbuf. This is a
   * convenience function; if more details about the icon are needed,
   * use lookup_icon() followed by
   * Gtk::IconInfo::load_icon().
   * 
   * Note that you probably want to listen for icon theme changes and
   * update the icon. This is usually done by connecting to the
   * GtkWidget::style-set signal. If for some reason you do not want to
   * update the icon when the icon theme changes, you should consider
   * using gdk_pixbuf_copy() to make a private copy of the pixbuf
   * returned by this function. Otherwise GTK+ may need to keep the old
   * icon theme loaded, which would be a waste of memory.
   * 
   * @newin{3,10}
   * 
   * @param icon_name The name of the icon to lookup.
   * @param size The desired icon size. The resulting icon may not be
   * exactly this size; see Gtk::IconInfo::load_icon().
   * @param scale Desired scale.
   * @param flags Flags modifying the behavior of the icon lookup.
   * @return The rendered icon; this may be
   * a newly created icon or a new reference to an internal icon, so
   * you must not modify the icon. Use Glib::object_unref() to release
   * your reference to the icon. <tt>nullptr</tt> if the icon isn’t found.
   * 
   * @throws Glib::Error
   */
  Glib::RefPtr<Gdk::Pixbuf> load_icon(const Glib::ustring& icon_name, int size, int scale, IconLookupFlags flags =  (IconLookupFlags)0) const;

  
  /** Looks up an icon in an icon theme for a particular window scale,
   * scales it to the given size and renders it into a cairo surface. This is a
   * convenience function; if more details about the icon are needed,
   * use lookup_icon() followed by
   * Gtk::IconInfo::load_surface().
   * 
   * Note that you probably want to listen for icon theme changes and
   * update the icon. This is usually done by connecting to the
   * GtkWidget::style-set signal.
   * 
   * @newin{3,10}
   * 
   * @param icon_name The name of the icon to lookup.
   * @param size The desired icon size. The resulting icon may not be
   * exactly this size; see Gtk::IconInfo::load_icon().
   * @param scale Desired scale.
   * @param for_window Gdk::Window to optimize drawing for, or <tt>nullptr</tt>.
   * @param flags Flags modifying the behavior of the icon lookup.
   * @return The rendered icon; this may be
   * a newly created icon or a new reference to an internal icon, so
   * you must not modify the icon. Use cairo_surface_destroy() to
   * release your reference to the icon. <tt>nullptr</tt> if the icon isn’t
   * found.
   * 
   * @throws Glib::Error
   */
  ::Cairo::RefPtr< ::Cairo::Surface> load_surface(const Glib::ustring& icon_name, int size, int scale, const Glib::RefPtr<Gdk::Window>& for_window, IconLookupFlags flags =  (IconLookupFlags)0);

 
  /** Lists a subset of icons in the current icon theme, by providing a context string.
   * The set of values for the context string is system dependent,
   * but will typically include such values as 'Applications' and
   * 'MimeTypes'.
   * 
   * @newin{2,4}
   * 
   * @param context A string identifying a particular type of icon.
   * @return The names of all the
   * icons in the theme.
   */
  std::vector<Glib::ustring> list_icons(const Glib::ustring& context) const;

  /** Lists the icons in the current icon theme.
   *
   * @return A list holding the names of all the
   * icons in the theme.
   *
   * @newin{2,10}
   */
   std::vector<Glib::ustring> list_icons() const;

  
  /** Gets the list of contexts available within the current
   * hierarchy of icon themes.
   * 
   * @newin{2,12}
   * 
   * @return A list holding the names of all the
   * contexts in the theme.
   */
  std::vector<Glib::ustring> list_contexts() const;

  
  /** Gets the name of an icon that is representative of the
   * current theme (for instance, to use when presenting
   * a list of themes to the user.)
   * 
   * @newin{2,4}
   */
  Glib::ustring get_example_icon_name() const;
  
  /** Checks to see if the icon theme has changed; if it has, any
   * currently cached information is discarded and will be reloaded
   * next time @a icon_theme is accessed.
   * 
   * @newin{2,4}
   * 
   * @return <tt>true</tt> if the icon theme has changed and needed
   * to be reloaded.
   */
  bool rescan_if_needed();
  
#ifndef GTKMM_DISABLE_DEPRECATED

  /** Registers a built-in icon for icon theme lookups. The idea
   * of built-in icons is to allow an application or library
   * that uses themed icons to function requiring files to
   * be present in the file system. For instance, the default
   * images for all of GTK+’s stock icons are registered
   * as built-icons.
   * 
   * In general, if you use add_builtin_icon()
   * you should also install the icon in the icon theme, so
   * that the icon is generally available.
   * 
   * This function will generally be used with pixbufs loaded
   * via gdk_pixbuf_new_from_inline().
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.14: Use add_resource_path()
   * to add application-specific icons to the icon theme.
   * 
   * @deprecated Use add_resource_path() to add application-specific icons to the icon theme.
   * 
   * @param icon_name The name of the icon to register.
   * @param size The size in pixels at which to register the icon (different
   * images can be registered for the same icon name at different sizes.).
   * @param pixbuf Gdk::Pixbuf that contains the image to use for @a icon_name.
   */
  static void add_builtin_icon(const Glib::ustring& icon_name, int size, const Glib::RefPtr<Gdk::Pixbuf>& pixbuf);
#endif // GTKMM_DISABLE_DEPRECATED


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%changed()</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the current icon theme is switched or GTK+ detects
   * that a change has occurred in the contents of the current
   * icon theme.
   */

  Glib::SignalProxy< void > signal_changed();


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_changed().
  virtual void on_changed();


};

} // namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::IconTheme
   */
  GTKMM_API
  Glib::RefPtr<Gtk::IconTheme> wrap(GtkIconTheme* object, bool take_copy = false);
}


#endif /* _GTKMM_ICONTHEME_H */

