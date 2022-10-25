// Generated by gmmproc 2.66.4 -- DO NOT MODIFY!
#ifndef _GTKMM_RECENTCHOOSER_H
#define _GTKMM_RECENTCHOOSER_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2006 The gtkmm Development Team
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

#include <glibmm/interface.h>
#include <gtkmm/recentinfo.h>
#include <gtkmm/recentfilter.h>
#include <gtkmm/recentmanager.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
typedef struct _GtkRecentChooserIface GtkRecentChooserIface;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkRecentChooser = struct _GtkRecentChooser;
using GtkRecentChooserClass = struct _GtkRecentChooserClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API RecentChooser_Class; } // namespace Gtk
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

/** 
 *  @var RecentSortType RECENT_SORT_NONE
 * Do not sort the returned list of recently used
 * resources.
 * 
 *  @var RecentSortType RECENT_SORT_MRU
 * Sort the returned list with the most recently used
 * items first.
 * 
 *  @var RecentSortType RECENT_SORT_LRU
 * Sort the returned list with the least recently used
 * items first.
 * 
 *  @var RecentSortType RECENT_SORT_CUSTOM
 * Sort the returned list using a custom sorting
 * function passed using Gtk::RecentChooser::set_sort_func().
 * 
 *  @enum RecentSortType
 * 
 * Used to specify the sorting method to be applyed to the recently
 * used resource list.
 * 
 * @newin{2,10}
 *
 * @ingroup gtkmmEnums
 */
enum RecentSortType
{
  RECENT_SORT_NONE,
  RECENT_SORT_MRU,
  RECENT_SORT_LRU,
  RECENT_SORT_CUSTOM
};

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::RecentSortType> : public Glib::Value_Enum<Gtk::RecentSortType>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


/**  %Exception class for Gtk::RecentChooser errors.
 */
class GTKMM_API RecentChooserError : public Glib::Error
{
public:
  /**  @var Code NOT_FOUND
   * Indicates that a file does not exist.
   * 
   *  @var Code INVALID_URI
   * Indicates a malformed URI.
   * 
   *  @enum Code
   * 
   * These identify the various errors that can occur while calling
   * Gtk::RecentChooser functions.
   * 
   * @newin{2,10}
   */
  enum Code
  {
    NOT_FOUND,
    INVALID_URI
  };

  RecentChooserError(Code error_code, const Glib::ustring& error_message);
  explicit RecentChooserError(GError* gobject);
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
class GTKMM_API Value<Gtk::RecentChooserError::Code> : public Glib::Value_Enum<Gtk::RecentChooserError::Code>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


/** RecentChooser is an interface that can be implemented by widgets
 * displaying the list of recently used files.  In GTK+, the main objects
 * that implement this interface are RecentChooserWidget, RecentChooserDialog
 * and RecentChooserMenu.
 *
 * @newin{2,10}
 *
 * @ingroup RecentFiles
 */

class GTKMM_API RecentChooser : public Glib::Interface
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = RecentChooser;
  using CppClassType = RecentChooser_Class;
  using BaseObjectType = GtkRecentChooser;
  using BaseClassType = GtkRecentChooserIface;

  // noncopyable
  RecentChooser(const RecentChooser&) = delete;
  RecentChooser& operator=(const RecentChooser&) = delete;

private:
  friend class RecentChooser_Class;
  static CppClassType recentchooser_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  RecentChooser();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit RecentChooser(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit RecentChooser(GtkRecentChooser* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  RecentChooser(RecentChooser&& src) noexcept;
  RecentChooser& operator=(RecentChooser&& src) noexcept;

  ~RecentChooser() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GtkRecentChooser*       gobj()       { return reinterpret_cast<GtkRecentChooser*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GtkRecentChooser* gobj() const { return reinterpret_cast<GtkRecentChooser*>(gobject_); }

private:

public:

  
  /** Whether to show recently used resources marked registered as private.
   * 
   * @newin{2,10}
   * 
   * @param show_private <tt>true</tt> to show private items, <tt>false</tt> otherwise.
   */
  void set_show_private(bool show_private =  true);
  
  /** Returns whether @a chooser should display recently used resources
   * registered as private.
   * 
   * @newin{2,10}
   * 
   * @return <tt>true</tt> if the recent chooser should show private items,
   * <tt>false</tt> otherwise.
   */
  bool get_show_private() const;
  
  /** Sets whether @a chooser should display the recently used resources that
   * it didn’t find.  This only applies to local resources.
   * 
   * @newin{2,10}
   * 
   * @param show_not_found Whether to show the local items we didn’t find.
   */
  void set_show_not_found(bool show_not_found =  true);
  
  /** Retrieves whether @a chooser should show the recently used resources that
   * were not found.
   * 
   * @newin{2,10}
   * 
   * @return <tt>true</tt> if the resources not found should be displayed, and
   * <tt>false</tt> otheriwse.
   */
  bool get_show_not_found() const;
  
  /** Sets whether @a chooser can select multiple items.
   * 
   * @newin{2,10}
   * 
   * @param select_multiple <tt>true</tt> if @a chooser can select more than one item.
   */
  void set_select_multiple(bool select_multiple =  true);
  
  /** Gets whether @a chooser can select multiple items.
   * 
   * @newin{2,10}
   * 
   * @return <tt>true</tt> if @a chooser can select more than one item.
   */
  bool get_select_multiple() const;
  
  /** Sets the number of items that should be returned by
   * get_items() and get_uris().
   * 
   * @newin{2,10}
   * 
   * @param limit A positive integer, or -1 for all items.
   */
  void set_limit(int limit);
  void unset_limit();
  
  /** Gets the number of items returned by get_items()
   * and get_uris().
   * 
   * @newin{2,10}
   * 
   * @return A positive integer, or -1 meaning that all items are
   * returned.
   */
  int get_limit() const;
  
  /** Sets whether only local resources, that is resources using the file:// URI
   * scheme, should be shown in the recently used resources selector.  If
   *  @a local_only is <tt>true</tt> (the default) then the shown resources are guaranteed
   * to be accessible through the operating system native file system.
   * 
   * @newin{2,10}
   * 
   * @param local_only <tt>true</tt> if only local files can be shown.
   */
  void set_local_only(bool local_only =  true);
  
  /** Gets whether only local resources should be shown in the recently used
   * resources selector.  See set_local_only()
   * 
   * @newin{2,10}
   * 
   * @return <tt>true</tt> if only local resources should be shown.
   */
  bool get_local_only() const;
  
  /** Sets whether to show a tooltips containing the full path of each
   * recently used resource in a Gtk::RecentChooser widget.
   * 
   * @newin{2,10}
   * 
   * @param show_tips <tt>true</tt> if tooltips should be shown.
   */
  void set_show_tips(bool show_tips =  true);
  
  /** Gets whether @a chooser should display tooltips containing the full path
   * of a recently user resource.
   * 
   * @newin{2,10}
   * 
   * @return <tt>true</tt> if the recent chooser should show tooltips,
   * <tt>false</tt> otherwise.
   */
  bool get_show_tips() const;

  
  /** Sets whether @a chooser should show an icon near the resource when
   * displaying it.
   * 
   * @newin{2,10}
   * 
   * @param show_icons Whether to show an icon near the resource.
   */
  void set_show_icons(bool show_icons =  true);
  
  /** Retrieves whether @a chooser should show an icon near the resource.
   * 
   * @newin{2,10}
   * 
   * @return <tt>true</tt> if the icons should be displayed, <tt>false</tt> otherwise.
   */
  bool get_show_icons() const;
  
  /** Changes the sorting order of the recently used resources list displayed by
   *  @a chooser.
   * 
   * @newin{2,10}
   * 
   * @param sort_type Sort order that the chooser should use.
   */
  void set_sort_type(RecentSortType sort_type);
  
  /** Gets the value set by set_sort_type().
   * 
   * @newin{2,10}
   * 
   * @return The sorting order of the @a chooser.
   */
  RecentSortType get_sort_type() const;


  /** This callback should return -1 if b compares before a, 0 if they compare
   * equal and 1 if a compares after b.
   * For instance, int on_sort_compare(const Glib::RefPtr<Gtk::RecentInfo>& a, const Gtk::RecentInfo& b);
   */
  typedef sigc::slot<int, const Glib::RefPtr<RecentInfo>&, const Glib::RefPtr<RecentInfo>&> SlotCompare;
  

  /** Sets the comparison function used when sorting the list of recently
   * used resources and the sort type is #RECENT_SORT_CUSTOM.
   */
  void set_sort_func(const SlotCompare& slot);

  // TODO: Return type should be void since it will never return false but
  // throwing RecentChooserError instead
  
  /** Sets @a uri as the current URI for @a chooser.
   * 
   * @newin{2,10}
   * 
   * @param uri A URI.
   * @return <tt>true</tt> if the URI was found.
   * 
   * @throws Glib::Error
   */
  bool set_current_uri(const Glib::ustring& uri);
  
  /** Gets the URI currently selected by @a chooser.
   * 
   * @newin{2,10}
   * 
   * @return A newly allocated string holding a URI.
   */
  Glib::ustring get_current_uri() const;
  
  /** Gets the Gtk::RecentInfo currently selected by @a chooser.
   * 
   * @newin{2,10}
   * 
   * @return A Gtk::RecentInfo.  Use Gtk::RecentInfo::unref() when
   * when you have finished using it.
   */
  Glib::RefPtr<RecentInfo> get_current_item();
  
  /** Gets the Gtk::RecentInfo currently selected by @a chooser.
   * 
   * @newin{2,10}
   * 
   * @return A Gtk::RecentInfo.  Use Gtk::RecentInfo::unref() when
   * when you have finished using it.
   */
  Glib::RefPtr<const RecentInfo> get_current_item() const;
  // TODO: Same here
  
  /** Selects @a uri inside @a chooser.
   * 
   * @newin{2,10}
   * 
   * @param uri A URI.
   * @return <tt>true</tt> if @a uri was found.
   * 
   * @throws Glib::Error
   */
  bool select_uri(const Glib::ustring& uri);
  
  /** Unselects @a uri inside @a chooser.
   * 
   * @newin{2,10}
   * 
   * @param uri A URI.
   */
  void unselect_uri(const Glib::ustring& uri);
  
  /** Selects all the items inside @a chooser, if the @a chooser supports
   * multiple selection.
   * 
   * @newin{2,10}
   */
  void select_all();
  
  /** Unselects all the items inside @a chooser.
   * 
   * @newin{2,10}
   */
  void unselect_all();

  //typedef Glib::ListHandle<RecentInfo, RecentInfoTraits> ListHandle_RecentInfos;
 

  /** Gets the list of recently used resources in form of Gtk::RecentInfo objects.
   * 
   * The return value of this function is affected by the “sort-type” and
   * “limit” properties of @a chooser.
   * 
   * @newin{2,10}
   * 
   * @return A newly allocated
   * list of Gtk::RecentInfo objects.
   */
  std::vector<Glib::RefPtr<RecentInfo> > get_items() const;

  /** Gets the URI of the recently used resources.
   *
   * The return value of this function is affected by the "sort-type" and
   * "limit" properties of the recent chooser.
   */
  std::vector<Glib::ustring> get_uris() const;
  

  /** Adds @a filter to the list of Gtk::RecentFilter objects held by @a chooser.
   * 
   * If no previous filter objects were defined, this function will call
   * set_filter().
   * 
   * @newin{2,10}
   * 
   * @param filter A Gtk::RecentFilter.
   */
  void add_filter(const Glib::RefPtr<RecentFilter>& filter);
  
  /** Removes @a filter from the list of Gtk::RecentFilter objects held by @a chooser.
   * 
   * @newin{2,10}
   * 
   * @param filter A Gtk::RecentFilter.
   */
  void remove_filter(const Glib::RefPtr<RecentFilter>& filter);

 
  /** Gets the Gtk::RecentFilter objects held by @a chooser.
   * 
   * @newin{2,10}
   * 
   * @return A singly linked list
   * of Gtk::RecentFilter objects.
   */
  std::vector< Glib::RefPtr<RecentFilter> > list_filters();
 

  /** Gets the Gtk::RecentFilter objects held by @a chooser.
   * 
   * @newin{2,10}
   * 
   * @return A singly linked list
   * of Gtk::RecentFilter objects.
   */
  std::vector< Glib::RefPtr<const RecentFilter> > list_filters() const;

  
  /** Sets @a filter as the current Gtk::RecentFilter object used by @a chooser
   * to affect the displayed recently used resources.
   * 
   * @newin{2,10}
   * 
   * @param filter A Gtk::RecentFilter.
   */
  void set_filter(const Glib::RefPtr<RecentFilter>& filter);
  
  /** Gets the Gtk::RecentFilter object currently used by @a chooser to affect
   * the display of the recently used resources.
   * 
   * @newin{2,10}
   * 
   * @return A Gtk::RecentFilter object.
   */
  Glib::RefPtr<RecentFilter> get_filter();
  
  /** Gets the Gtk::RecentFilter object currently used by @a chooser to affect
   * the display of the recently used resources.
   * 
   * @newin{2,10}
   * 
   * @return A Gtk::RecentFilter object.
   */
  Glib::RefPtr<const RecentFilter> get_filter() const;

  
  /**
   * @par Slot Prototype:
   * <tt>void on_my_%selection_changed()</tt>
   *
   * Flags: Run Last
   *
   * This signal is emitted when there is a change in the set of
   * selected recently used resources.  This can happen when a user
   * modifies the selection with the mouse or the keyboard, or when
   * explicitly calling functions to change the selection.
   * 
   * @newin{2,10}
   */

  Glib::SignalProxy< void > signal_selection_changed();

  
  /**
   * @par Slot Prototype:
   * <tt>void on_my_%item_activated()</tt>
   *
   * Flags: Run Last
   *
   * This signal is emitted when the user "activates" a recent item
   * in the recent chooser.  This can happen by double-clicking on an item
   * in the recently used resources list, or by pressing
   * `Enter`.
   * 
   * @newin{2,10}
   */

  Glib::SignalProxy< void > signal_item_activated();


  //Not wrapped because it's write-only and construct-only: _WRAP_PROPERTY("recent-manager", Glib::RefPtr<RecentManager>)
  /** Whether the private items should be displayed.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_show_private() ;

/** Whether the private items should be displayed.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_show_private() const;

  /** Whether this Gtk::RecentChooser should display a tooltip containing the
   * full path of the recently used resources.
   * 
   * @newin{2,10}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_show_tips() ;

/** Whether this Gtk::RecentChooser should display a tooltip containing the
   * full path of the recently used resources.
   * 
   * @newin{2,10}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_show_tips() const;

  /** Whether this Gtk::RecentChooser should display an icon near the item.
   * 
   * @newin{2,10}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_show_icons() ;

/** Whether this Gtk::RecentChooser should display an icon near the item.
   * 
   * @newin{2,10}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_show_icons() const;

  /** Whether this Gtk::RecentChooser should display the recently used resources
   * even if not present anymore. Setting this to <tt>false</tt> will perform a
   * potentially expensive check on every local resource (every remote
   * resource will always be displayed).
   * 
   * @newin{2,10}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_show_not_found() ;

/** Whether this Gtk::RecentChooser should display the recently used resources
   * even if not present anymore. Setting this to <tt>false</tt> will perform a
   * potentially expensive check on every local resource (every remote
   * resource will always be displayed).
   * 
   * @newin{2,10}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_show_not_found() const;

  /** Allow the user to select multiple resources.
   * 
   * @newin{2,10}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_select_multiple() ;

/** Allow the user to select multiple resources.
   * 
   * @newin{2,10}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_select_multiple() const;

  /** Whether this Gtk::RecentChooser should display only local (file:)
   * resources.
   * 
   * @newin{2,10}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_local_only() ;

/** Whether this Gtk::RecentChooser should display only local (file:)
   * resources.
   * 
   * @newin{2,10}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_local_only() const;

  /** The maximum number of recently used resources to be displayed,
   * or -1 to display all items.
   * 
   * @newin{2,10}
   *
   * Default value: 50
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< int > property_limit() ;

/** The maximum number of recently used resources to be displayed,
   * or -1 to display all items.
   * 
   * @newin{2,10}
   *
   * Default value: 50
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< int > property_limit() const;

  /** Sorting order to be used when displaying the recently used resources.
   * 
   * @newin{2,10}
   *
   * Default value: Gtk::RECENT_SORT_NONE
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< RecentSortType > property_sort_type() ;

/** Sorting order to be used when displaying the recently used resources.
   * 
   * @newin{2,10}
   *
   * Default value: Gtk::RECENT_SORT_NONE
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< RecentSortType > property_sort_type() const;

  /** The Gtk::RecentFilter object to be used when displaying
   * the recently used resources.
   * 
   * @newin{2,10}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< Glib::RefPtr<RecentFilter> > property_filter() ;

/** The Gtk::RecentFilter object to be used when displaying
   * the recently used resources.
   * 
   * @newin{2,10}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::RefPtr<RecentFilter> > property_filter() const;


protected:
  // TODO: How to wrap those vfuncs?
  // TODO: Also: use vectorutils.

  //__CONVERSION(`ListHandle_RecentInfos', `GList*', `($3).data()')
  //__CONVERSION(`Glib::SListHandle<RecentFilter*>', `GSList*', `($3).data()')

  //_WRAP_VFUNC(bool set_current_uri(const Glib::ustring& uri), "set_current_uri", errthrow)
 

    virtual Glib::ustring get_current_uri_vfunc() const;


  //_WRAP_VFUNC(bool select_uri(const Glib::ustring& uri), "select_uri", errthrow)
    virtual void unselect_uri_vfunc(const Glib::ustring& uri);

    virtual void select_all_vfunc();

    virtual void unselect_all_vfunc();

  //_WRAP_VFUNC(ArrayHandle_RecentInfos get_items() const, "get_items")
    virtual Glib::RefPtr<RecentManager> get_recent_manager_vfunc();


    virtual void add_filter_vfunc(const Glib::RefPtr<RecentFilter>& filter);

    virtual void remove_filter_vfunc(const Glib::RefPtr<RecentFilter>& filter);

  //_WRAP_VFUNC(Glib::SListHandle<RecentFilter*> list_filters(), "list_filters")
  //_WRAP_VFUNC(void set_sort_func(const SlotCompare& slot), "set_sort_func")


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_selection_changed().
  virtual void on_selection_changed();
  /// This is a default handler for the signal signal_item_activated().
  virtual void on_item_activated();


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
   * @relates Gtk::RecentChooser
   */
  GTKMM_API
  Glib::RefPtr<Gtk::RecentChooser> wrap(GtkRecentChooser* object, bool take_copy = false);

} // namespace Glib


#endif /* _GTKMM_RECENTCHOOSER_H */

