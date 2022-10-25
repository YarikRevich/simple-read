// Generated by gmmproc 2.66.4 -- DO NOT MODIFY!
#ifndef _GTKMM_RADIOTOOLBUTTON_H
#define _GTKMM_RADIOTOOLBUTTON_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2003 The gtkmm Development Team
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

#include <gtkmm/toggletoolbutton.h>
#include <gtkmm/radiobuttongroup.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkRadioToolButton = struct _GtkRadioToolButton;
using GtkRadioToolButtonClass = struct _GtkRadioToolButtonClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API RadioToolButton_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A toolbar item that contains a radio button.
 *
 * A %Gtk::RadioToolButton is a Gtk::ToolItem that contains a radio button, that is,
 * a button that is part of a group of toggle buttons where only one button can be
 * active at a time.
 *
 * @ingroup Widgets
 */

class GTKMM_API RadioToolButton : public ToggleToolButton
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef RadioToolButton CppObjectType;
  typedef RadioToolButton_Class CppClassType;
  typedef GtkRadioToolButton BaseObjectType;
  typedef GtkRadioToolButtonClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  RadioToolButton(RadioToolButton&& src) noexcept;
  RadioToolButton& operator=(RadioToolButton&& src) noexcept;

  // noncopyable
  RadioToolButton(const RadioToolButton&) = delete;
  RadioToolButton& operator=(const RadioToolButton&) = delete;

  ~RadioToolButton() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class GTKMM_API RadioToolButton_Class;
  static CppClassType radiotoolbutton_class_;

protected:
  explicit RadioToolButton(const Glib::ConstructParams& construct_params);
  explicit RadioToolButton(GtkRadioToolButton* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  GtkRadioToolButton*       gobj()       { return reinterpret_cast<GtkRadioToolButton*>(gobject_); }

  /// Provides access to the underlying C GObject.
  const GtkRadioToolButton* gobj() const { return reinterpret_cast<GtkRadioToolButton*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


private:

public:
  using Group = RadioButtonGroup;

  /** Creates a new Gtk::RadioToolButton and a new group.
   *
   * The RadioToolButton will have an empty label and will reside in a newly created group.
   * Use get_group() to retrieve this group and pass it to other radio buttons to assign
   * them to this group, or use join_group().
   *
   * @newin{2,4}
   */
  RadioToolButton();

  /** Creates a new Gtk::RadioToolButton and a new group.
   *
   * The RadioToolButton will have the label @a label.
   *
   * @param label The string used to display the label for this RadioToolButton.
   *
   * @newin{3,22}
   */
  explicit RadioToolButton(const Glib::ustring& label);

  /** Creates a new Gtk::RadioToolButton in an existing group.
   *
   * The RadioToolButton will have the label @a label and will be put into the Group
   * @a group.
   *
   * @param group The existing group which will be used for this RadioToolButton.
   * @param label The string used to display the label for this RadioToolButton.
   *
   * @newin{2,4}
   */
  explicit RadioToolButton(Group& group, const Glib::ustring& label = Glib::ustring());
  

#ifndef GTKMM_DISABLE_DEPRECATED
  /** Creates a new Gtk::RadioToolButton in an existing group.
   *
   * The RadioToolButton will be created according to the StockID properties and put into
   * the Group @a group.
   *
   * @param group The existing group which will be used for this RadioToolButton.
   * @param stock_id The StockID which determines the look of the RadioToolButton.
   *
   * @newin{2,4}
   * @deprecated Use one of the other constructors instead.
   */
  RadioToolButton(Group& group, const Gtk::StockID& stock_id);
  
#endif // GTKMM_DISABLE_DEPRECATED

  //This would look too much like a copy constructor:
  //_WRAP_CTOR(RadioToolButton(RadioToolButton& group), gtk_radio_tool_button_new_from_widget)
  //People should use second.join_group(first) instead.
  

  //This does not correspond to any gtk_radio_tool_button_*_new() function,
  //but it should work (it just sets properties), and it makes this class consistent with the
  //other ToolButton classes.

  /** Creates a new Gtk::RadioToolButton with an image and a new group.
   *
   * The RadioToolButton will have the label @a label and an image widget @a icon_widget.
   *
   * @param icon_widget The widget placed as the RadioToolButton's icon.
   * @param label The string used to display the label for this RadioToolButton.
   *
   * @newin{2,4}
   */
  explicit RadioToolButton(Widget& icon_widget, const Glib::ustring& label = Glib::ustring());


  /** Returns the radio button group @a button belongs to.
   * 
   * @newin{2,4}
   * 
   * @return The group @a button belongs to.
   */
  Group get_group();

  /** Adds the radio tool button to @a group, removing it from the group it belonged to before.
   * You can obtain a suitable group from another radio tool button by using get_group().
   *
   * @newin{2,4}
   *
   * @param group An existing radio button group.
   */
  void set_group(Group& group);

  /** Removes the radio tool button from the group.
   *
   * @newin{3,10}
   */
  void reset_group();
  

  /** Joins a Gtk::RadioToolButton object to the group of another Gtk::RadioToolButton object.
   *
   * @newin{3,22}
   *
   * @param group_source A radio tool button object whose group we are joining.
   */
  void join_group(RadioToolButton& group_source);

  /// Note that %property_group() corresponds to join_group(), rather than to get_group() and set_group().
  /** Sets a new group for a radio tool button.
   * 
   * @newin{3,22}
   *
   * @return A PropertyProxy_WriteOnly that allows you to set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_WriteOnly< RadioToolButton* > property_group() ;


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
   * @relates Gtk::RadioToolButton
   */
  GTKMM_API
  Gtk::RadioToolButton* wrap(GtkRadioToolButton* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_RADIOTOOLBUTTON_H */

