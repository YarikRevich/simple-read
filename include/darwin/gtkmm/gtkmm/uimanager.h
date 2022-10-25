// Generated by gmmproc 2.66.4 -- DO NOT MODIFY!
#ifndef _GTKMM_UIMANAGER_H
#define _GTKMM_UIMANAGER_H


#ifndef GTKMM_DISABLE_DEPRECATED


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

#include <vector>

#include <gtkmm/widget.h>
#include <gtkmm/action.h>
#include <gtkmm/actiongroup.h>


 // This whole file is deprecated.

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkUIManager = struct _GtkUIManager;
using GtkUIManagerClass = struct _GtkUIManagerClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API UIManager_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

#ifndef GTKMM_DISABLE_DEPRECATED
/** 
 *  @var UIManagerItemType UI_MANAGER_AUTO
 * Pick the type of the UI element according to context.
 * 
 *  @var UIManagerItemType UI_MANAGER_MENUBAR
 * Create a menubar.
 * 
 *  @var UIManagerItemType UI_MANAGER_MENU
 * Create a menu.
 * 
 *  @var UIManagerItemType UI_MANAGER_TOOLBAR
 * Create a toolbar.
 * 
 *  @var UIManagerItemType UI_MANAGER_PLACEHOLDER
 * Insert a placeholder.
 * 
 *  @var UIManagerItemType UI_MANAGER_POPUP
 * Create a popup menu.
 * 
 *  @var UIManagerItemType UI_MANAGER_MENUITEM
 * Create a menuitem.
 * 
 *  @var UIManagerItemType UI_MANAGER_TOOLITEM
 * Create a toolitem.
 * 
 *  @var UIManagerItemType UI_MANAGER_SEPARATOR
 * Create a separator.
 * 
 *  @var UIManagerItemType UI_MANAGER_ACCELERATOR
 * Install an accelerator.
 * 
 *  @var UIManagerItemType UI_MANAGER_POPUP_WITH_ACCELS
 * Same as Gtk::UI_MANAGER_POPUP, but the
 * actions’ accelerators are shown.
 * 
 *  @enum UIManagerItemType
 * 
 * These enumeration values are used by gtk_ui_manager_add_ui() to determine
 * what UI element to create.
 * 
 * Deprecated: 3.10
 * @deprecated Because Gtk::UIManager is deprecated.
 * 
 *
 * @ingroup gtkmmEnums
 * @par Bitwise operators:
 * <tt>%UIManagerItemType operator|(UIManagerItemType, UIManagerItemType)</tt><br>
 * <tt>%UIManagerItemType operator&(UIManagerItemType, UIManagerItemType)</tt><br>
 * <tt>%UIManagerItemType operator^(UIManagerItemType, UIManagerItemType)</tt><br>
 * <tt>%UIManagerItemType operator~(UIManagerItemType)</tt><br>
 * <tt>%UIManagerItemType& operator|=(UIManagerItemType&, UIManagerItemType)</tt><br>
 * <tt>%UIManagerItemType& operator&=(UIManagerItemType&, UIManagerItemType)</tt><br>
 * <tt>%UIManagerItemType& operator^=(UIManagerItemType&, UIManagerItemType)</tt><br>
 */
enum UIManagerItemType
{
  UI_MANAGER_AUTO = 0x0,
  UI_MANAGER_MENUBAR = 1 << 0,
  UI_MANAGER_MENU = 1 << 1,
  UI_MANAGER_TOOLBAR = 1 << 2,
  UI_MANAGER_PLACEHOLDER = 1 << 3,
  UI_MANAGER_POPUP = 1 << 4,
  UI_MANAGER_MENUITEM = 1 << 5,
  UI_MANAGER_TOOLITEM = 1 << 6,
  UI_MANAGER_SEPARATOR = 1 << 7,
  UI_MANAGER_ACCELERATOR = 1 << 8,
  UI_MANAGER_POPUP_WITH_ACCELS = 1 << 9
};

/** @ingroup gtkmmEnums */
inline UIManagerItemType operator|(UIManagerItemType lhs, UIManagerItemType rhs)
  { return static_cast<UIManagerItemType>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline UIManagerItemType operator&(UIManagerItemType lhs, UIManagerItemType rhs)
  { return static_cast<UIManagerItemType>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline UIManagerItemType operator^(UIManagerItemType lhs, UIManagerItemType rhs)
  { return static_cast<UIManagerItemType>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline UIManagerItemType operator~(UIManagerItemType flags)
  { return static_cast<UIManagerItemType>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline UIManagerItemType& operator|=(UIManagerItemType& lhs, UIManagerItemType rhs)
  { return (lhs = static_cast<UIManagerItemType>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline UIManagerItemType& operator&=(UIManagerItemType& lhs, UIManagerItemType rhs)
  { return (lhs = static_cast<UIManagerItemType>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline UIManagerItemType& operator^=(UIManagerItemType& lhs, UIManagerItemType rhs)
  { return (lhs = static_cast<UIManagerItemType>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }
#endif // GTKMM_DISABLE_DEPRECATED

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

#ifndef GTKMM_DISABLE_DEPRECATED
template <>
class GTKMM_API Value<Gtk::UIManagerItemType> : public Glib::Value_Flags<Gtk::UIManagerItemType>
{
public:
  static GType value_type() G_GNUC_CONST;
};
#endif // GTKMM_DISABLE_DEPRECATED

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


/** Constructing menus and toolbars from an XML description.
 *
 * A Gtk::UIManager constructs a user interface (menus and toolbars) from one or more UI definitions,
 * which reference actions from one or more action groups.
 *
 * \par UI Definitions
 *
 * The UI definitions are specified in an XML format which can be roughly described by the following DTD.
 * \code
 * <!ELEMENT ui          (menubar|toolbar|popup|accelerator)* >
 * <!ELEMENT menubar     (menuitem|separator|placeholder|menu)* >
 * <!ELEMENT menu        (menuitem|separator|placeholder|menu)* >
 * <!ELEMENT popup       (menuitem|separator|placeholder|menu)* >
 * <!ELEMENT toolbar     (toolitem|separator|placeholder)* >
 * <!ELEMENT placeholder (menuitem|toolitem|separator|placeholder|menu)* >
 * <!ELEMENT menuitem     EMPTY >
 * <!ELEMENT toolitem     (menu?) >
 * <!ELEMENT separator    EMPTY >
 * <!ELEMENT accelerator  EMPTY >
 * <!ATTLIST menubar      name                  #IMPLIED
 *                      action                #IMPLIED >
 * <!ATTLIST toolbar      name                  #IMPLIED
 *                      action                #IMPLIED >
 * <!ATTLIST popup        name                  #IMPLIED
 *                      action                #IMPLIED >
 * <!ATTLIST placeholder  name                  #IMPLIED
 *                       action                #IMPLIED >
 * <!ATTLIST separator    name                  #IMPLIED
 *                       action                #IMPLIED
 *                       expand   (true|false) #IMPLIED >
 * <!ATTLIST menu         name                  #IMPLIED
 *                       action                #REQUIRED
 *                       position (top|bot)    #IMPLIED >
 * <!ATTLIST menuitem     name                  #IMPLIED
 *                      action                #REQUIRED
 *                      position (top|bot)    #IMPLIED >
 * <!ATTLIST toolitem     name                  #IMPLIED
 *                      action                #REQUIRED
 *                      position (top|bot)    #IMPLIED >
 * <!ATTLIST accelerator  name                  #IMPLIED
 *                       action                #REQUIRED >
 * \endcode
 *
 * There are some additional restrictions beyond those specified in the DTD, e.g.
 * every toolitem must have a toolbar in its anchestry and every menuitem must have a +
 * menubar or popup in its anchestry. Since a GMarkup parser is used to parse the UI description,
 * it must not only be valid XML, but valid GMarkup.
 *
 * If a name is not specified, it defaults to the action. If an action is not specified either,
 * the element name is used. The name and action attributes must not contain '/' characters after
 * parsing (since that would mess up path lookup) and must be usable as XML attributes when
 * enclosed in doublequotes, thus they must not '"' characters or references to the &quot; entity.
 *
 * \par Example: UI Definition
 * \code
 * <ui>
 * <menubar>
 *   <menu name="FileMenu" action="FileMenuAction">
 *     <menuitem name="New" action="New2Action" />
 *     <placeholder name="FileMenuAdditions" />
 *   </menu>
 *   <menu name="JustifyMenu" action="JustifyMenuAction">
 *     <menuitem name="Left" action="justify-left"/>
 *     <menuitem name="Centre" action="justify-center"/>
 *     <menuitem name="Right" action="justify-right"/>
 *     <menuitem name="Fill" action="justify-fill"/>
 *   </menu>
 * </menubar>
 * <toolbar action="toolbar1">
 *   <placeholder name="JustifyToolItems">
 *     <separator/>
 *     <toolitem name="Left" action="justify-left"/>
 *     <toolitem name="Centre" action="justify-center"/>
 *     <toolitem name="Right" action="justify-right"/>
 *     <toolitem name="Fill" action="justify-fill"/>
 *     <separator/>
 *   </placeholder>
 * </toolbar>
 * </ui>
 * \endcode
 *
 * The constructed widget hierarchy is very similar to the element tree of the XML,
 * with the exception that placeholders are merged into their parents. The correspondence
 * of XML elements to widgets should be almost obvious:
 * - menubar 	a Gtk::MenuBar
 * - toolbar 	a Gtk::Toolbar
 * - popup  a toplevel Gtk::Menu
 * - menu  a Gtk::Menu attached to a menuitem
 * - menuitem  a Gtk::MenuItem subclass, the exact type depends on the action
 * - toolitem  a Gtk::ToolItem subclass, the exact type depends on the action.
 * Note that toolitem elements may contain a menu element, but only if their
 * associated action specifies a Gtk::MenuToolButton as proxy.
 * - separator  a Gtk::SeparatorMenuItem or Gtk::SeparatorToolItem
 * - accelerator 	a keyboard accelerator
 *
 * The "position" attribute determines where a constructed widget is positioned wrt.
 * to its siblings in the partially constructed tree. If it is "top", the widget is
 * prepended, otherwise it is appended.
 *
 * \par UI Merging
 *
 * The most remarkable feature of Gtk::UIManager is that it can overlay a set of menuitems
 * and toolitems over another one, and demerge them later.
 *
 * Merging is done based on the names of the XML elements. Each element is identified by
 * a path which consists of the names of its anchestors, separated by slashes. For example,
 * the menuitem named "Left" in the example above has the path /ui/menubar/JustifyMenu/Left
 * and the toolitem with the same name has path /ui/toolbar1/JustifyToolItems/Left.
 *
 * \par Accelerators
 *
 * Every action has an accelerator path. Accelerators are installed together with menuitem
 * proxies, but they can also be explicitly added with \<accelerator\> elements in the
 * UI definition. This makes it possible to have accelerators for actions even
 * if they have no visible proxies.
 *
 * \par Smart Separators
 *
 * The separators created by Gtk::UIManager are "smart", i.e. they do not show up in
 * the UI unless they end up between two visible menu or tool items. Separators which are
 * located at the very beginning or end of the menu or toolbar containing them, or multiple
 * separators next to each other, are hidden. This is a useful feature, since the merging
 * of UI elements from multiple sources can make it hard or impossible to determine in
 * advance whether a separator will end up in such an unfortunate position.
 *
 * For separators in toolbars, you can set expand="true" to turn them from a small,
 * visible separator to an expanding, invisible one. Toolitems following an expanding
 * separator are effectively right-aligned.
 *
 * \par Empty Menus
 *
 * Submenus pose similar problems to separators inconnection with merging. It is impossible
 * to know in advance whether they will end up empty after merging. Gtk::UIManager offers
 * two ways to treat empty submenus:
 *
 * - make them disappear by hiding the menu item they're attached to
 * - add an insensitive "Empty" item
 *
 * The behaviour is chosen based on the "hide_if_empty" property of the action to which the submenu is associated.
 *
 * @newin{2,4}
 *
 * @deprecated Use Gtk::Builder instead.<br>
 * The menus and toolbars examples in the
 * <a href="https://developer.gnome.org/gtkmm-tutorial/stable/">Programming with gtkmm 3</a>
 * book show how to construct menus and toolbars with Gtk::Builder.
 */

class GTKMM_API UIManager : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = UIManager;
  using CppClassType = UIManager_Class;
  using BaseObjectType = GtkUIManager;
  using BaseClassType = GtkUIManagerClass;

  // noncopyable
  UIManager(const UIManager&) = delete;
  UIManager& operator=(const UIManager&) = delete;

private:  friend class UIManager_Class;
  static CppClassType uimanager_class_;

protected:
  explicit UIManager(const Glib::ConstructParams& construct_params);
  explicit UIManager(GtkUIManager* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  UIManager(UIManager&& src) noexcept;
  UIManager& operator=(UIManager&& src) noexcept;

  ~UIManager() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GtkUIManager*       gobj()       { return reinterpret_cast<GtkUIManager*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GtkUIManager* gobj() const { return reinterpret_cast<GtkUIManager*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GtkUIManager* gobj_copy();

private:

protected:
  UIManager();

public:
  
  static Glib::RefPtr<UIManager> create();


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Sets the “add_tearoffs” property, which controls whether menus 
   * generated by this Gtk::UIManager will have tearoff menu items. 
   * 
   * Note that this only affects regular menus. Generated popup 
   * menus never have tearoff menu items.
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.4: Tearoff menus are deprecated and should not
   * be used in newly written code.
   * 
   * @deprecated Tearoff menus are deprecated and should not be used in newly written code.
   * 
   * @param add_tearoffs Whether tearoff menu items are added.
   */
  void set_add_tearoffs(bool add_tearoffs =  true);
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Returns whether menus generated by this Gtk::UIManager
   * will have tearoff menu items. 
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.4: Tearoff menus are deprecated and should not
   * be used in newly written code.
   * 
   * @deprecated Tearoff menus are deprecated and should not be used in newly written code.
   * 
   * @return Whether tearoff menu items are added.
   */
  bool get_add_tearoffs() const;
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Inserts an action group into the list of action groups associated 
   * with @a manager. Actions in earlier groups hide actions with the same 
   * name in later groups. 
   * 
   * If @a pos is larger than the number of action groups in @a manager, or
   * negative, @a action_group will be inserted at the end of the internal
   * list.
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.10
   * 
   * @deprecated Use Gio::ActionGroup and Gtk::Widget::insert_action_group() instead.
   * 
   * @param action_group The action group to be inserted.
   * @param pos The position at which the group will be inserted.
   */
  void insert_action_group(const Glib::RefPtr<ActionGroup>& action_group, int pos =  0);
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Removes an action group from the list of action groups associated 
   * with @a manager.
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.10
   * 
   * @deprecated Use Gio::ActionGroup and Gtk::Widget::remove_action_group() instead.
   * 
   * @param action_group The action group to be removed.
   */
  void remove_action_group(const Glib::RefPtr<ActionGroup>& action_group);
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Returns the list of action groups associated with @a manager.
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.10
   * 
   * @deprecated Use Gtk::Widget::list_action_prefixes() and Gtk::Widget::get_action_group() instead.
   * 
   * @return A List of
   * action groups. The list is owned by GTK+
   * and should not be modified.
   */
  std::vector< Glib::RefPtr<ActionGroup> > get_action_groups();
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Returns the list of action groups associated with @a manager.
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.10
   * 
   * @deprecated Use Gtk::Widget::list_action_prefixes() and Gtk::Widget::get_action_group() instead.
   * 
   * @return A List of
   * action groups. The list is owned by GTK+
   * and should not be modified.
   */
  std::vector< Glib::RefPtr<const ActionGroup> > get_action_groups() const;
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Returns the Gtk::AccelGroup associated with @a manager.
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.10
   * 
   * @deprecated Use Gio::ActionGroup and the accelerator group on an associated Gtk::Menu instead.
   * 
   * @return The Gtk::AccelGroup.
   */
  Glib::RefPtr<AccelGroup> get_accel_group();
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Returns the Gtk::AccelGroup associated with @a manager.
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.10
   * 
   * @deprecated Use Gio::ActionGroup and the accelerator group on an associated Gtk::Menu instead.
   * 
   * @return The Gtk::AccelGroup.
   */
  Glib::RefPtr<const AccelGroup> get_accel_group() const;
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Looks up a widget by following a path. 
   * The path consists of the names specified in the XML description of the UI. 
   * separated by “/”. Elements which don’t have a name or action attribute in 
   * the XML (e.g. <popup>) can be addressed by their XML element name 
   * (e.g. "popup"). The root element ("/ui") can be omitted in the path.
   * 
   * Note that the widget found by following a path that ends in a <menu>;
   * element is the menuitem to which the menu is attached, not the menu it
   * manages.
   * 
   * Also note that the widgets constructed by a ui manager are not tied to 
   * the lifecycle of the ui manager. If you add the widgets returned by this 
   * function to some container or explicitly ref them, they will survive the
   * destruction of the ui manager.
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.10
   * 
   * @deprecated Use Gtk::Builder::get_widget() instead.
   * 
   * @param path A path.
   * @return The widget found by following the path,
   * or <tt>nullptr</tt> if no widget was found.
   */
  Widget* get_widget(const Glib::ustring& path);
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Looks up a widget by following a path. 
   * The path consists of the names specified in the XML description of the UI. 
   * separated by “/”. Elements which don’t have a name or action attribute in 
   * the XML (e.g. <popup>) can be addressed by their XML element name 
   * (e.g. "popup"). The root element ("/ui") can be omitted in the path.
   * 
   * Note that the widget found by following a path that ends in a <menu>;
   * element is the menuitem to which the menu is attached, not the menu it
   * manages.
   * 
   * Also note that the widgets constructed by a ui manager are not tied to 
   * the lifecycle of the ui manager. If you add the widgets returned by this 
   * function to some container or explicitly ref them, they will survive the
   * destruction of the ui manager.
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.10
   * 
   * @deprecated Use Gtk::Builder::get_widget() instead.
   * 
   * @param path A path.
   * @return The widget found by following the path,
   * or <tt>nullptr</tt> if no widget was found.
   */
  const Widget* get_widget(const Glib::ustring& path) const;
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Obtains a list of all toplevel widgets of the requested types.
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.10
   * 
   * @deprecated There is no corresponding replacement when using Gtk::Builder.
   * 
   * @param types Specifies the types of toplevel widgets to include. Allowed
   * types are Gtk::UI_MANAGER_MENUBAR, Gtk::UI_MANAGER_TOOLBAR and
   * Gtk::UI_MANAGER_POPUP.
   * @return A newly-allocated SList of
   * all toplevel widgets of the requested types.
   */
  std::vector<Widget*> get_toplevels(UIManagerItemType types);
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Obtains a list of all toplevel widgets of the requested types.
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.10
   * 
   * @deprecated There is no corresponding replacement when using Gtk::Builder.
   * 
   * @param types Specifies the types of toplevel widgets to include. Allowed
   * types are Gtk::UI_MANAGER_MENUBAR, Gtk::UI_MANAGER_TOOLBAR and
   * Gtk::UI_MANAGER_POPUP.
   * @return A newly-allocated SList of
   * all toplevel widgets of the requested types.
   */
  std::vector<const Widget*> get_toplevels(UIManagerItemType types) const;
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Looks up an action by following a path. See gtk_ui_manager_get_widget()
   * for more information about paths.
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.10
   * 
   * @deprecated There is no corresponding replacement when using Gtk::Builder.
   * 
   * @param path A path.
   * @return The action whose proxy widget is found by following the path, 
   * or <tt>nullptr</tt> if no widget was found.
   */
  Glib::RefPtr<Action> get_action(const Glib::ustring& path);
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Looks up an action by following a path. See gtk_ui_manager_get_widget()
   * for more information about paths.
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.10
   * 
   * @deprecated There is no corresponding replacement when using Gtk::Builder.
   * 
   * @param path A path.
   * @return The action whose proxy widget is found by following the path, 
   * or <tt>nullptr</tt> if no widget was found.
   */
  Glib::RefPtr<const Action> get_action(const Glib::ustring& path) const;
#endif // GTKMM_DISABLE_DEPRECATED


  typedef guint ui_merge_id;

#ifndef GTKMM_DISABLE_DEPRECATED

  /** Parses a string containing a UI definition and
   * merges it with the current contents. An enclosing &lt;ui&gt;
   * element is added if it is missing.
   *
   * @param buffer the string to parse
   * @result  The merge id for the merged UI. The merge id can be used to unmerge the UI with remove_ui(). If an error occurred, the return value is 0.
   * @throws exception
   * @newin{2,4}
   * @deprecated Use Gtk::Builder::add_from_string() instead.
   */
  ui_merge_id add_ui_from_string(const Glib::ustring& buffer);
#endif // GTKMM_DISABLE_DEPRECATED

  
#ifndef GTKMM_DISABLE_DEPRECATED

  /** Parses a file containing a [UI definition][XML-UI] and 
   * merges it with the current contents of @a manager. 
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.10
   * 
   * @deprecated Use Gtk::Builder::add_from_file() instead.
   * 
   * @param filename The name of the file to parse.
   * @return The merge id for the merged UI. The merge id can be used
   * to unmerge the UI with gtk_ui_manager_remove_ui(). If an error occurred,
   * the return value is 0.
   * 
   * @throws Glib::Error
   */
  ui_merge_id add_ui_from_file(const Glib::ustring& filename);
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Parses a resource file containing a [UI definition][XML-UI] and
   * merges it with the current contents of @a manager.
   * 
   * @newin{3,4}
   * 
   * Deprecated: 3.10
   * 
   * @deprecated Use Gtk::Builder::add_from_resource() instead.
   * 
   * @param resource_path The resource path of the file to parse.
   * @return The merge id for the merged UI. The merge id can be used
   * to unmerge the UI with gtk_ui_manager_remove_ui(). If an error occurred,
   * the return value is 0.
   * 
   * @throws Glib::Error
   */
  ui_merge_id add_ui_from_resource(const Glib::ustring& resource_path);
#endif // GTKMM_DISABLE_DEPRECATED


//TODO: Is top=true a good default?

  
#ifndef GTKMM_DISABLE_DEPRECATED

  /** Adds a UI element to the current contents of @a self.
   * 
   * If @a type is Gtk::UI_MANAGER_AUTO, GTK+ inserts a menuitem, toolitem or
   * separator if such an element can be inserted at the place determined by
   *  @a path. Otherwise @a type must indicate an element that can be inserted at
   * the place determined by @a path.
   * 
   *  @a see add_ui_separator().
   * 
   * @newin{2,4}
   * 
   * @deprecated There is no corresponding replacement when using Gtk::Builder.
   * 
   * @param merge_id The merge id for the merged UI, see gtk_ui_manager_new_merge_id().
   * @param path A path.
   * @param name The name for the added UI element.
   * @param action The name of the action to be proxied, if this is not a separator.
   * @param type The type of UI element to add.
   * @param top If <tt>true</tt>, the UI element is added before its siblings, otherwise it
   * is added after its siblings.
   */
  void add_ui(ui_merge_id merge_id, const Glib::ustring& path, const Glib::ustring& name, const Glib::ustring& action, UIManagerItemType type =  Gtk::UI_MANAGER_AUTO, bool top =  true);
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Adds a separator UI element to the current contents.
   *
   * If @a type  is Gtk::UI_MANAGER_AUTO, GTK+ inserts a menuitem, toolitem or
   * separator if such an element can be inserted at the place determined by
   *  @a path . Otherwise @a type  must indicate an element that can be inserted at
   * the place determined by @a path.
   *
   * @see add_ui().
   *
   * @newin{2,4}
   *
   * @param merge_id The merge id for the merged UI, see gtk_ui_manager_new_merge_id().
   * @param path A path.
   * @param name The name for the added UI element.
   * @param type The type of UI element to add.
   * @param top If <tt>true</tt>, the UI element is added before its siblings, otherwise it
   * is added after its siblings.
   * @deprecated There is no corresponding replacement when using Gtk::Builder.
   */
  void add_ui_separator(ui_merge_id merge_id, const Glib::ustring& path, const Glib::ustring& name = "", UIManagerItemType type = Gtk::UI_MANAGER_AUTO, bool top = true);
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Unmerges the part of @a manager's content identified by @a merge_id.
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.10
   * 
   * @deprecated There is no corresponding replacement when using Gtk::Builder.
   * 
   * @param merge_id A merge id as returned by gtk_ui_manager_add_ui_from_string().
   */
  void remove_ui(ui_merge_id merge_id);
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Creates a [UI definition][XML-UI] of the merged UI.
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.10
   * 
   * @deprecated There is no corresponding replacement when using Gtk::Builder.
   * 
   * @return A newly allocated string containing an XML representation of 
   * the merged UI.
   */
  Glib::ustring get_ui() const;
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Makes sure that all pending updates to the UI have been completed.
   * 
   * This may occasionally be necessary, since Gtk::UIManager updates the 
   * UI in an idle function. A typical example where this function is
   * useful is to enforce that the menubar and toolbar have been added to 
   * the main window before showing it:
   * 
   * [C example ellipted]
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.10
   * 
   * @deprecated There is no corresponding replacement when using Gtk::Builder.
   */
  void ensure_update();
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /** Returns an unused merge id, suitable for use with 
   * gtk_ui_manager_add_ui().
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.10
   * 
   * @deprecated There is no corresponding replacement when using Gtk::Builder.
   * 
   * @return An unused merge id.
   */
  ui_merge_id new_merge_id();
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%add_widget(Widget* widget)</tt>
   *
   * Flags: Run First, No Recurse
   *
   * The signal_add_widget() signal is emitted for each generated menubar and toolbar.
   * It is not emitted for generated popup menus, which can be obtained by 
   * gtk_ui_manager_get_widget().
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.10
   * 
   * @deprecated There is no corresponding replacement when using Gtk::Builder.
   * 
   * @param widget The added widget.
   */

  Glib::SignalProxy< void,Widget* > signal_add_widget();
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%actions_changed()</tt>
   *
   * Flags: Run First, No Recurse
   *
   * The signal_actions_changed() signal is emitted whenever the set of actions
   * changes.
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.10
   * 
   * @deprecated There is no corresponding replacement when using Gtk::Builder.
   */

  Glib::SignalProxy< void > signal_actions_changed();
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%connect_proxy(const Glib::RefPtr<Action>& action, Widget* widget)</tt>
   *
   * Flags: Run First, No Recurse
   *
   * The signal_connect_proxy() signal is emitted after connecting a proxy to
   * an action in the group. 
   * 
   * This is intended for simple customizations for which a custom action
   * class would be too clumsy, e.g. showing tooltips for menuitems in the
   * statusbar.
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.10
   * 
   * @deprecated There is no corresponding replacement when using Gtk::Builder.
   * 
   * @param action The action.
   * @param widget The proxy.
   */

  Glib::SignalProxy< void,const Glib::RefPtr<Action>&,Widget* > signal_connect_proxy();
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%disconnect_proxy(const Glib::RefPtr<Action>& action, Widget* widget)</tt>
   *
   * Flags: Run First, No Recurse
   *
   * The signal_disconnect_proxy() signal is emitted after disconnecting a proxy
   * from an action in the group. 
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.10
   * 
   * @deprecated There is no corresponding replacement when using Gtk::Builder.
   * 
   * @param action The action.
   * @param widget The proxy.
   */

  Glib::SignalProxy< void,const Glib::RefPtr<Action>&,Widget* > signal_disconnect_proxy();
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%pre_activate(const Glib::RefPtr<Action>& action)</tt>
   *
   * Flags: Run First, No Recurse
   *
   * The signal_pre_activate() signal is emitted just before the @a action
   * is activated.
   * 
   * This is intended for applications to get notification
   * just before any action is activated.
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.10
   * 
   * @deprecated There is no corresponding replacement when using Gtk::Builder.
   * 
   * @param action The action.
   */

  Glib::SignalProxy< void,const Glib::RefPtr<Action>& > signal_pre_activate();
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

  /**
   * @par Slot Prototype:
   * <tt>void on_my_%post_activate(const Glib::RefPtr<Action>& action)</tt>
   *
   * Flags: Run First, No Recurse
   *
   * The signal_post_activate() signal is emitted just after the @a action
   * is activated.
   * 
   * This is intended for applications to get notification
   * just after any action is activated.
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.10
   * 
   * @deprecated There is no corresponding replacement when using Gtk::Builder.
   * 
   * @param action The action.
   */

  Glib::SignalProxy< void,const Glib::RefPtr<Action>& > signal_post_activate();
#endif // GTKMM_DISABLE_DEPRECATED


#ifndef GTKMM_DISABLE_DEPRECATED

/** The "add-tearoffs" property controls whether generated menus 
   * have tearoff menu items. 
   * 
   * Note that this only affects regular menus. Generated popup 
   * menus never have tearoff menu items.   
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.4: Tearoff menus are deprecated and should not
   * be used in newly written code.
   * 
   * @deprecated Tearoff menus are deprecated and should not be used in newly written code.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_add_tearoffs() ;

/** The "add-tearoffs" property controls whether generated menus 
   * have tearoff menu items. 
   * 
   * Note that this only affects regular menus. Generated popup 
   * menus never have tearoff menu items.   
   * 
   * @newin{2,4}
   * 
   * Deprecated: 3.4: Tearoff menus are deprecated and should not
   * be used in newly written code.
   * 
   * @deprecated Tearoff menus are deprecated and should not be used in newly written code.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_add_tearoffs() const;

#endif // GTKMM_DISABLE_DEPRECATED

  
#ifndef GTKMM_DISABLE_DEPRECATED

/** An XML string describing the merged UI.
   * @deprecated There is no corresponding replacement when using Gtk::Builder.
   *
   * Default value: "<ui>\n</ui>\n"
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::ustring > property_ui() const;


#endif // GTKMM_DISABLE_DEPRECATED


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_add_widget().
  virtual void on_add_widget(Widget* widget);
  /// This is a default handler for the signal signal_actions_changed().
  virtual void on_actions_changed();
  /// This is a default handler for the signal signal_connect_proxy().
  virtual void on_connect_proxy(const Glib::RefPtr<Action>& action, Widget* widget);
  /// This is a default handler for the signal signal_disconnect_proxy().
  virtual void on_disconnect_proxy(const Glib::RefPtr<Action>& action, Widget* widget);
  /// This is a default handler for the signal signal_pre_activate().
  virtual void on_pre_activate(const Glib::RefPtr<Action>& action);
  /// This is a default handler for the signal signal_post_activate().
  virtual void on_post_activate(const Glib::RefPtr<Action>& action);


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
   * @relates Gtk::UIManager
   */
  GTKMM_API
  Glib::RefPtr<Gtk::UIManager> wrap(GtkUIManager* object, bool take_copy = false);
}


#endif // GTKMM_DISABLE_DEPRECATED


#endif /* _GTKMM_UIMANAGER_H */

