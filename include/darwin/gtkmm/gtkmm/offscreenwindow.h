// Generated by gmmproc 2.66.4 -- DO NOT MODIFY!
#ifndef _GTKMM_OFFSCREENWINDOW_H
#define _GTKMM_OFFSCREENWINDOW_H

#include <gtkmmconfig.h>


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2010 The gtkmm Development Team
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


#include <gtkmm/window.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkOffscreenWindow = struct _GtkOffscreenWindow;
using GtkOffscreenWindowClass = struct _GtkOffscreenWindowClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API OffscreenWindow_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A top-level container widget used to manage offscreen rendering of child widgets.
 * OffscreenWindow is strictly intended to be used for obtaining
 * snapshots of widgets that are not part of a normal widget hierarchy.
 * It differs from Gtk::Widget::get_snapshot() in that the widget you
 * want to get a snapshot of need not be displayed on the user's screen
 * as a part of a widget hierarchy.  However, since OffscreenWindow
 * is a top-level widget you cannot obtain snapshots of a full window
 * with it since you cannot pack a toplevel widget in another toplevel.
 *
 * The idea is to take a widget and manually set the state of it,
 * add it to an OffscreenWindow and then retrieve the snapshot
 * as a Gdk::Pixbuf.
 *
 * OffscreenWindow derives from Window only as an implementation
 * detail.  Applications should not use any API specific to #GtkWindow
 * to operate on this object.  It should be treated as a Bin that
 * has no parent widget.
 *
 * When contained offscreen widgets are redrawn, OffscreenWindow
 * will emit a "damage-event" signal.
 *
 * @newin{2,20}
 * @ingroup Containers
 * @ingroup Widgets
 */

class GTKMM_API OffscreenWindow : public Window
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef OffscreenWindow CppObjectType;
  typedef OffscreenWindow_Class CppClassType;
  typedef GtkOffscreenWindow BaseObjectType;
  typedef GtkOffscreenWindowClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  OffscreenWindow(OffscreenWindow&& src) noexcept;
  OffscreenWindow& operator=(OffscreenWindow&& src) noexcept;

  // noncopyable
  OffscreenWindow(const OffscreenWindow&) = delete;
  OffscreenWindow& operator=(const OffscreenWindow&) = delete;

  ~OffscreenWindow() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class GTKMM_API OffscreenWindow_Class;
  static CppClassType offscreenwindow_class_;

protected:
  explicit OffscreenWindow(const Glib::ConstructParams& construct_params);
  explicit OffscreenWindow(GtkOffscreenWindow* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  GtkOffscreenWindow*       gobj()       { return reinterpret_cast<GtkOffscreenWindow*>(gobject_); }

  /// Provides access to the underlying C GObject.
  const GtkOffscreenWindow* gobj() const { return reinterpret_cast<GtkOffscreenWindow*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


private:

  
public:
  OffscreenWindow();

  //TODO: Should this always be const?
 

  /** Retrieves a snapshot of the contained widget in the form of
   * a #cairo_surface_t.  If you need to keep this around over window
   * resizes then you should add a reference to it.
   * 
   * @newin{2,20}
   * 
   * @return A #cairo_surface_t pointer to the offscreen
   * surface, or <tt>nullptr</tt>.
   */
  Cairo::RefPtr<Cairo::Surface> get_surface();
  
  /** Retrieves a snapshot of the contained widget in the form of
   * a #cairo_surface_t.  If you need to keep this around over window
   * resizes then you should add a reference to it.
   * 
   * @newin{2,20}
   * 
   * @return A #cairo_surface_t pointer to the offscreen
   * surface, or <tt>nullptr</tt>.
   */
  Cairo::RefPtr<const Cairo::Surface> get_surface() const;


  /** Retrieves a snapshot of the contained widget in the form of
   * a Gdk::Pixbuf.  This is a new pixbuf with a reference count of 1,
   * and the application should unreference it once it is no longer
   * needed.
   * 
   * @newin{2,20}
   * 
   * @return A Gdk::Pixbuf pointer, or <tt>nullptr</tt>.
   */
  Glib::RefPtr<Gdk::Pixbuf> get_pixbuf();
  
  /** Retrieves a snapshot of the contained widget in the form of
   * a Gdk::Pixbuf.  This is a new pixbuf with a reference count of 1,
   * and the application should unreference it once it is no longer
   * needed.
   * 
   * @newin{2,20}
   * 
   * @return A Gdk::Pixbuf pointer, or <tt>nullptr</tt>.
   */
  Glib::RefPtr<const Gdk::Pixbuf> get_pixbuf() const;


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
   * @relates Gtk::OffscreenWindow
   */
  GTKMM_API
  Gtk::OffscreenWindow* wrap(GtkOffscreenWindow* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_OFFSCREENWINDOW_H */

