// Generated by gmmproc 2.66.4 -- DO NOT MODIFY!
#ifndef _GTKMM_WIDGETPATH_H
#define _GTKMM_WIDGETPATH_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright 2010 The gtkmm Development Team
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

#include <gtkmm/enums.h>
#include <vector>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C" { typedef struct _GtkWidgetPath GtkWidgetPath; }
#endif

namespace Gtk
{

//TODO: Add all of the C documentation, including translating the code examples to C++.
/** This represents a widget hierarchy from the topmost widget, typically a toplevel, to any child.
 * This widget path abstraction is used in StyleContext on behalf of the real
 * widget in order to query style information.
 *
 * If you are using gtkmm widgets, you probably will not need to use
 * this API directly, as there is Widget::get_path(), and the style
 * context returned by Widget::get_style_context() will be automatically
 * updated on widget hierarchy changes.
 *
 * @newin{3,0}
 */
class GTKMM_API WidgetPath
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  using CppObjectType = WidgetPath;
  using BaseObjectType = GtkWidgetPath;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type() G_GNUC_CONST;

  WidgetPath();

  explicit WidgetPath(GtkWidgetPath* gobject, bool make_a_copy = true);

  WidgetPath(const WidgetPath& other);
  WidgetPath& operator=(const WidgetPath& other);

  WidgetPath(WidgetPath&& other) noexcept;
  WidgetPath& operator=(WidgetPath&& other) noexcept;

  ~WidgetPath() noexcept;

  void swap(WidgetPath& other) noexcept;

  ///Provides access to the underlying C instance.
  GtkWidgetPath*       gobj()       { return gobject_; }

  ///Provides access to the underlying C instance.
  const GtkWidgetPath* gobj() const { return gobject_; }

  ///Provides access to the underlying C instance. The caller is responsible for freeing it. Use when directly setting fields in structs.
  GtkWidgetPath* gobj_copy() const;

protected:
  GtkWidgetPath* gobject_;

private:

  
public:

  
  /** Dumps the widget path into a string representation. It tries to match
   * the CSS style as closely as possible (Note that there might be paths
   * that cannot be represented in CSS).
   * 
   * The main use of this code is for debugging purposes, so that you can
   * Glib::print() the path or dump it in a gdb session.
   * 
   * @newin{3,2}
   * 
   * @return A new string describing @a path.
   */
  Glib::ustring to_string() const;
  
  /** Returns the number of Gtk::Widget Types between the represented
   * widget and its topmost container.
   * 
   * @newin{3,0}
   * 
   * @return The number of elements in the path.
   */
  int path_length() const;

  
  /** Appends a widget type to the widget hierarchy represented by @a path.
   * 
   * @newin{3,0}
   * 
   * @param type Widget type to append.
   * @return The position where the element was inserted.
   */
  int path_append_type(GType type);
  
  /** Prepends a widget type to the widget hierachy represented by @a path.
   * 
   * @newin{3,0}
   * 
   * @param type Widget type to prepend.
   */
  void prepend_type(GType type);

  
  /** Returns the object GType that is at position @a pos in the widget
   * hierarchy defined in @a path.
   * 
   * @newin{3,0}
   * 
   * @param pos Position to get the object type for, -1 for the path head.
   * @return A widget type.
   */
  GType iter_get_object_type(int pos) const;
  
  /** Sets the object type for a given position in the widget hierarchy
   * defined by @a path.
   * 
   * @newin{3,0}
   * 
   * @param pos Position to modify, -1 for the path head.
   * @param type Object type to set.
   */
  void iter_set_object_type(int pos, GType type);

  
  /** Returns the name corresponding to the widget found at
   * the position @a pos in the widget hierarchy defined by
   *  @a path
   * 
   * @param pos Position to get the widget name for, -1 for the path head.
   * @return The widget name, or <tt>nullptr</tt> if none was set.
   */
  Glib::ustring iter_get_name(int pos) const;
  
  /** Sets the widget name for the widget found at position @a pos
   * in the widget hierarchy defined by @a path.
   * 
   * @newin{3,0}
   * 
   * @param pos Position to modify, -1 for the path head.
   * @param name Widget name.
   */
  void iter_set_name(int pos, const Glib::ustring& name);
  
  /** Returns <tt>true</tt> if the widget at position @a pos has the name @a name,
   * <tt>false</tt> otherwise.
   * 
   * @newin{3,0}
   * 
   * @param pos Position to query, -1 for the path head.
   * @param name A widget name.
   * @return <tt>true</tt> if the widget at @a pos has this name.
   */
  bool iter_has_name(int pos, const Glib::ustring& name) const;
  //TODO: _WRAP_METHOD(bool iter_has_qname(int pos, GQuark qname) const, gtk_widget_path_iter_has_qname)


  /** Returns the list of siblings for the element at @a pos. If the element
   * was not added with siblings, <tt>nullptr</tt> is returned.
   * 
   * @param pos Position to get the siblings for, -1 for the path head.
   * @return <tt>nullptr</tt> or the list of siblings for the element at @a pos.
   */
  WidgetPath iter_get_siblings(int pos =  -1) const;
  
  /** Returns the index into the list of siblings for the element at @a pos as
   * returned by iter_get_siblings(). If that function would
   * return <tt>nullptr</tt> because the element at @a pos has no siblings, this function
   * will return 0.
   * 
   * @param pos Position to get the sibling index for, -1 for the path head.
   * @return 0 or the index into the list of siblings for the element at @a pos.
   */
  guint get_sibling_index(int pos =  -1);

  
  /** Adds the class @a name to the widget at position @a pos in
   * the hierarchy defined in @a path. See
   * Gtk::StyleContext::add_class().
   * 
   * @newin{3,0}
   * 
   * @param pos Position to modify, -1 for the path head.
   * @param name A class name.
   */
  void iter_add_class(int pos, const Glib::ustring& name);
  
  /** Removes the class @a name from the widget at position @a pos in
   * the hierarchy defined in @a path.
   * 
   * @newin{3,0}
   * 
   * @param pos Position to modify, -1 for the path head.
   * @param name Class name.
   */
  void iter_remove_class(int pos, const Glib::ustring& name);
  
  /** Removes all classes from the widget at position @a pos in the
   * hierarchy defined in @a path.
   * 
   * @newin{3,0}
   * 
   * @param pos Position to modify, -1 for the path head.
   */
  void iter_clear_classes(int pos =  -1);

 
  /** Returns a list with all the class names defined for the widget
   * at position @a pos in the hierarchy defined in @a path.
   * 
   * @newin{3,0}
   * 
   * @param pos Position to query, -1 for the path head.
   * @return The list of
   * classes, This is a list of strings, the SList contents
   * are owned by GTK+.
   */
  std::vector<Glib::ustring> iter_list_classes(int pos =  -1) const;

  
  /** Returns <tt>true</tt> if the widget at position @a pos has the class @a name
   * defined, <tt>false</tt> otherwise.
   * 
   * @newin{3,0}
   * 
   * @param pos Position to query, -1 for the path head.
   * @param name Class name.
   * @return <tt>true</tt> if the class @a name is defined for the widget at @a pos.
   */
  bool iter_has_class(int pos, const Glib::ustring& name) const;
  //TODOL_WRAP_METHOD(bool iter_has_qclass(int pos, GQuark qname) const, gtk_widget_path_iter_has_qclass)

  
#ifndef GTKMM_DISABLE_DEPRECATED

  /** Adds the region @a name to the widget at position @a pos in
   * the hierarchy defined in @a path. See
   * Gtk::StyleContext::add_region().
   * 
   * Region names must only contain lowercase letters
   * and “-”, starting always with a lowercase letter.
   * 
   * @newin{3,0}
   * 
   * Deprecated: 3.14: The use of regions is deprecated.
   * 
   * @deprecated The use of regions is deprecated.
   * 
   * @param pos Position to modify, -1 for the path head.
   * @param name Region name.
   * @param flags Flags affecting the region.
   */
  void iter_add_region(int pos, const Glib::ustring& name, RegionFlags flags);
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Removes the region @a name from the widget at position @a pos in
   * the hierarchy defined in @a path.
   * 
   * @newin{3,0}
   * 
   * Deprecated: 3.14: The use of regions is deprecated.
   * 
   * @deprecated The use of regions is deprecated.
   * 
   * @param pos Position to modify, -1 for the path head.
   * @param name Region name.
   */
  void iter_remove_region(int pos, const Glib::ustring& name);
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Removes all regions from the widget at position @a pos in the
   * hierarchy defined in @a path.
   * 
   * @newin{3,0}
   * 
   * Deprecated: 3.14: The use of regions is deprecated.
   * 
   * @deprecated The use of regions is deprecated.
   * 
   * @param pos Position to modify, -1 for the path head.
   */
  void iter_clear_regions(int pos =  -1);
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Returns a list with all the region names defined for the widget
   * at position @a pos in the hierarchy defined in @a path.
   * 
   * @newin{3,0}
   * 
   * Deprecated: 3.14: The use of regions is deprecated.
   * 
   * @deprecated The use of regions is deprecated.
   * 
   * @param pos Position to query, -1 for the path head.
   * @return The list of
   * regions, This is a list of strings, the SList contents
   * are owned by GTK+.
   */
  std::vector<Glib::ustring> iter_list_regions(int pos =  -1) const;
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Returns <tt>true</tt> if the widget at position @a pos has the class @a name
   * defined, <tt>false</tt> otherwise.
   * 
   * @newin{3,0}
   * 
   * Deprecated: 3.14: The use of regions is deprecated.
   * 
   * @deprecated The use of regions is deprecated.
   * 
   * @param pos Position to query, -1 for the path head.
   * @param name Region name.
   * @param flags Return location for the region flags.
   * @return <tt>true</tt> if the class @a name is defined for the widget at @a pos.
   */
  bool iter_has_region(int pos, const Glib::ustring& name, RegionFlags& flags) const;
#endif // GTKMM_DISABLE_DEPRECATED


   //deprecated

  
  /** Returns the topmost object type, that is, the object type this path
   * is representing.
   * 
   * @newin{3,0}
   * 
   * @return The object type.
   */
  GType get_object_type() const;

  
  /** Returns <tt>true</tt> if the widget type represented by this path
   * is @a type, or a subtype of it.
   * 
   * @newin{3,0}
   * 
   * @param type Widget type to match.
   * @return <tt>true</tt> if the widget represented by @a path is of type @a type.
   */
  bool is_type(GType type) const;
  
  /** Returns <tt>true</tt> if any of the parents of the widget represented
   * in @a path is of type @a type, or any subtype of it.
   * 
   * @newin{3,0}
   * 
   * @param type Widget type to check in parents.
   * @return <tt>true</tt> if any parent is of type @a type.
   */
  bool has_parent(GType type) const;


};

} //namespace Gtk


namespace Gtk
{

/** @relates Gtk::WidgetPath
 * @param lhs The left-hand side
 * @param rhs The right-hand side
 */
inline void swap(WidgetPath& lhs, WidgetPath& rhs) noexcept
  { lhs.swap(rhs); }

} // namespace Gtk

namespace Glib
{

/** A Glib::wrap() method for this object.
 *
 * @param object The C instance.
 * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
 * @result A C++ instance that wraps this C instance.
 *
 * @relates Gtk::WidgetPath
 */

Gtk::WidgetPath wrap(GtkWidgetPath* object, bool take_copy = false);

#ifndef DOXYGEN_SHOULD_SKIP_THIS
template <>
class  Value<Gtk::WidgetPath> : public Glib::Value_Boxed<Gtk::WidgetPath>
{};
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

} // namespace Glib


#endif /* _GTKMM_WIDGETPATH_H */

