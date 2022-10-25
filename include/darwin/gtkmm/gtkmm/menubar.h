// Generated by gmmproc 2.66.4 -- DO NOT MODIFY!
#ifndef _GTKMM_MENUBAR_H
#define _GTKMM_MENUBAR_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/*
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

#include <gtkmm/menushell.h>
#include <gtkmm/menuitem.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkMenuBar = struct _GtkMenuBar;
using GtkMenuBarClass = struct _GtkMenuBarClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API MenuBar_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

/** 
 *  @var PackDirection PACK_DIRECTION_LTR
 * Widgets are packed left-to-right.
 * 
 *  @var PackDirection PACK_DIRECTION_RTL
 * Widgets are packed right-to-left.
 * 
 *  @var PackDirection PACK_DIRECTION_TTB
 * Widgets are packed top-to-bottom.
 * 
 *  @var PackDirection PACK_DIRECTION_BTT
 * Widgets are packed bottom-to-top.
 * 
 *  @enum PackDirection
 * 
 * Determines how widgets should be packed inside menubars
 * and menuitems contained in menubars.
 *
 * @ingroup gtkmmEnums
 */
enum PackDirection
{
  PACK_DIRECTION_LTR,
  PACK_DIRECTION_RTL,
  PACK_DIRECTION_TTB,
  PACK_DIRECTION_BTT
};

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::PackDirection> : public Glib::Value_Enum<Gtk::PackDirection>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


/** A standard menu bar which usually holds Gtk::Menu submenu items.
 * The useful methods are in the base class - Gtk::MenuShell.
 *
 * The MenuBar widget looks like this:
 * @image html menubar1.png
 *
 * @ingroup Widgets
 * @ingroup Menus
 */

class GTKMM_API MenuBar : public MenuShell
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef MenuBar CppObjectType;
  typedef MenuBar_Class CppClassType;
  typedef GtkMenuBar BaseObjectType;
  typedef GtkMenuBarClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  MenuBar(MenuBar&& src) noexcept;
  MenuBar& operator=(MenuBar&& src) noexcept;

  // noncopyable
  MenuBar(const MenuBar&) = delete;
  MenuBar& operator=(const MenuBar&) = delete;

  ~MenuBar() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class GTKMM_API MenuBar_Class;
  static CppClassType menubar_class_;

protected:
  explicit MenuBar(const Glib::ConstructParams& construct_params);
  explicit MenuBar(GtkMenuBar* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  GtkMenuBar*       gobj()       { return reinterpret_cast<GtkMenuBar*>(gobject_); }

  /// Provides access to the underlying C GObject.
  const GtkMenuBar* gobj() const { return reinterpret_cast<GtkMenuBar*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


private:


public:
  MenuBar();

  //This is custom-implemented because the gtk_menu_new_from_model() does more
  //than just call g_object_new. See https://bugzilla.gnome.org/show_bug.cgi?id=704671
  //This might be nearly-useless. See https://bugzilla.gnome.org/show_bug.cgi?id=708905
  /** Creates a new MenuBar and populates it with menu items
   * and submenus according to the @a model.
   *
   * The created menu items are connected to actions found in the
   * ApplicationWindow to which the menu bar belongs - typically
   * by means of being contained within the ApplicationWindow's
   * widget hierarchy.
   *
   * @param model
   *
   * @newin{3,10}
   */
  explicit MenuBar(const Glib::RefPtr<Gio::MenuModel>& model);
  

  /** Retrieves the current pack direction of the menubar. 
   * See set_pack_direction().
   * 
   * @newin{2,8}
   * 
   * @return The pack direction.
   */
  PackDirection get_pack_direction() const;
  
  /** Sets how items should be packed inside a menubar.
   * 
   * @newin{2,8}
   * 
   * @param pack_dir A new Gtk::PackDirection.
   */
  void set_pack_direction(PackDirection pack_dir);
  
  /** Retrieves the current child pack direction of the menubar.
   * See set_child_pack_direction().
   * 
   * @newin{2,8}
   * 
   * @return The child pack direction.
   */
  PackDirection get_child_pack_direction() const;
  
  /** Sets how widgets should be packed inside the children of a menubar.
   * 
   * @newin{2,8}
   * 
   * @param child_pack_dir A new Gtk::PackDirection.
   */
  void set_child_pack_direction(PackDirection child_pack_dir);

  // append, prepend and insert are defined in menushell

  /** The pack direction of the menubar. It determines how
   * menuitems are arranged in the menubar.
   * 
   * @newin{2,8}
   *
   * Default value: Gtk::PACK_DIRECTION_LTR
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< PackDirection > property_pack_direction() ;

/** The pack direction of the menubar. It determines how
   * menuitems are arranged in the menubar.
   * 
   * @newin{2,8}
   *
   * Default value: Gtk::PACK_DIRECTION_LTR
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< PackDirection > property_pack_direction() const;

  /** The child pack direction of the menubar. It determines how
   * the widgets contained in child menuitems are arranged.
   * 
   * @newin{2,8}
   *
   * Default value: Gtk::PACK_DIRECTION_LTR
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< PackDirection > property_child_pack_direction() ;

/** The child pack direction of the menubar. It determines how
   * the widgets contained in child menuitems are arranged.
   * 
   * @newin{2,8}
   *
   * Default value: Gtk::PACK_DIRECTION_LTR
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< PackDirection > property_child_pack_direction() const;


private:
  void init_accels_handler_(void);


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
   * @relates Gtk::MenuBar
   */
  GTKMM_API
  Gtk::MenuBar* wrap(GtkMenuBar* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_MENUBAR_H */

