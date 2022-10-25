// Generated by gmmproc 2.66.4 -- DO NOT MODIFY!
#ifndef _GTKMM_CELLAREACONTEXT_H
#define _GTKMM_CELLAREACONTEXT_H

#include <gtkmmconfig.h>


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2010 The gtkmm Development Team
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


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellAreaContext = struct _GtkCellAreaContext;
using GtkCellAreaContextClass = struct _GtkCellAreaContextClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API CellAreaContext_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

class GTKMM_API CellArea;

/** This stores geometrical information for a series of rows in a CellArea.
 *
 * CellAreaContext is used by widgets such as TreeView and IconView,
 * but application developers do not usually need to be aware of it.
 *
 * The CellAreaContext object is created by a given CellArea
 * and is used to store cell sizes and alignments for a series of
 * TreeModel rows that are requested and rendered in the same context.
 *
 * CellLayout widgets can create any number of contexts in which to
 * request and render groups of data rows. However. it's important that the
 * same context which was used to request sizes for a given TreeModel
 * row also be used for the same row when calling other CellArea APIs
 * such as gtk_cell_area_render() and gtk_cell_area_event().
 */

class GTKMM_API CellAreaContext : public Glib::Object
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = CellAreaContext;
  using CppClassType = CellAreaContext_Class;
  using BaseObjectType = GtkCellAreaContext;
  using BaseClassType = GtkCellAreaContextClass;

  // noncopyable
  CellAreaContext(const CellAreaContext&) = delete;
  CellAreaContext& operator=(const CellAreaContext&) = delete;

private:  friend class CellAreaContext_Class;
  static CppClassType cellareacontext_class_;

protected:
  explicit CellAreaContext(const Glib::ConstructParams& construct_params);
  explicit CellAreaContext(GtkCellAreaContext* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  CellAreaContext(CellAreaContext&& src) noexcept;
  CellAreaContext& operator=(CellAreaContext&& src) noexcept;

  ~CellAreaContext() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GtkCellAreaContext*       gobj()       { return reinterpret_cast<GtkCellAreaContext*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GtkCellAreaContext* gobj() const { return reinterpret_cast<GtkCellAreaContext*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GtkCellAreaContext* gobj_copy();

private:

public:


protected:

public:

  
  /** Fetches the Gtk::CellArea this @a context was created by.
   * 
   * This is generally unneeded by layouting widgets; however,
   * it is important for the context implementation itself to
   * fetch information about the area it is being used for.
   * 
   * For instance at Gtk::CellAreaContextClass.allocate() time
   * it’s important to know details about any cell spacing
   * that the Gtk::CellArea is configured with in order to
   * compute a proper allocation.
   * 
   * @newin{3,0}
   * 
   * @return The Gtk::CellArea this context was created by.
   */
  Glib::RefPtr<CellArea> get_area();
  
  /** Fetches the Gtk::CellArea this @a context was created by.
   * 
   * This is generally unneeded by layouting widgets; however,
   * it is important for the context implementation itself to
   * fetch information about the area it is being used for.
   * 
   * For instance at Gtk::CellAreaContextClass.allocate() time
   * it’s important to know details about any cell spacing
   * that the Gtk::CellArea is configured with in order to
   * compute a proper allocation.
   * 
   * @newin{3,0}
   * 
   * @return The Gtk::CellArea this context was created by.
   */
  Glib::RefPtr<const CellArea> get_area() const;

  
  /** Allocates a width and/or a height for all rows which are to be
   * rendered with @a context.
   * 
   * Usually allocation is performed only horizontally or sometimes
   * vertically since a group of rows are usually rendered side by
   * side vertically or horizontally and share either the same width
   * or the same height. Sometimes they are allocated in both horizontal
   * and vertical orientations producing a homogeneous effect of the
   * rows. This is generally the case for Gtk::TreeView when
   * Gtk::TreeView::property_fixed_height_mode() is enabled.
   * 
   * @newin{3,0}
   * 
   * @param width The allocated width for all Gtk::TreeModel rows rendered
   * with @a context, or -1.
   * @param height The allocated height for all Gtk::TreeModel rows rendered
   * with @a context, or -1.
   */
  void allocate(int width, int height);
  
  /** Resets any previously cached request and allocation
   * data.
   * 
   * When underlying Gtk::TreeModel data changes its
   * important to reset the context if the content
   * size is allowed to shrink. If the content size
   * is only allowed to grow (this is usually an option
   * for views rendering large data stores as a measure
   * of optimization), then only the row that changed
   * or was inserted needs to be (re)requested with
   * get_preferred_width().
   * 
   * When the new overall size of the context requires
   * that the allocated size changes (or whenever this
   * allocation changes at all), the variable row
   * sizes need to be re-requested for every row.
   * 
   * For instance, if the rows are displayed all with
   * the same width from top to bottom then a change
   * in the allocated width necessitates a recalculation
   * of all the displayed row heights using
   * get_preferred_height_for_width().
   * 
   * @newin{3,0}
   */
  void reset();

  
  /** Gets the accumulative preferred width for all rows which have been
   * requested with this context.
   * 
   * After reset() is called and/or before ever
   * requesting the size of a Gtk::CellArea, the returned values are 0.
   * 
   * @newin{3,0}
   * 
   * @param minimum_width Location to store the minimum width,
   * or <tt>nullptr</tt>.
   * @param natural_width Location to store the natural width,
   * or <tt>nullptr</tt>.
   */
  void get_preferred_width(int& minimum_width, int& natural_width) const;
  
  /** Gets the accumulative preferred height for all rows which have been
   * requested with this context.
   * 
   * After reset() is called and/or before ever
   * requesting the size of a Gtk::CellArea, the returned values are 0.
   * 
   * @newin{3,0}
   * 
   * @param minimum_height Location to store the minimum height,
   * or <tt>nullptr</tt>.
   * @param natural_height Location to store the natural height,
   * or <tt>nullptr</tt>.
   */
  void get_preferred_height(int& minimum_height, int& natural_height) const;
  
  /** Gets the accumulative preferred height for @a width for all rows
   * which have been requested for the same said @a width with this context.
   * 
   * After reset() is called and/or before ever
   * requesting the size of a Gtk::CellArea, the returned values are -1.
   * 
   * @newin{3,0}
   * 
   * @param width A proposed width for allocation.
   * @param minimum_height Location to store the minimum height,
   * or <tt>nullptr</tt>.
   * @param natural_height Location to store the natural height,
   * or <tt>nullptr</tt>.
   */
  void get_preferred_height_for_width(int width, int& minimum_height, int& natural_height) const;
  
  /** Gets the accumulative preferred width for @a height for all rows which
   * have been requested for the same said @a height with this context.
   * 
   * After reset() is called and/or before ever
   * requesting the size of a Gtk::CellArea, the returned values are -1.
   * 
   * @newin{3,0}
   * 
   * @param height A proposed height for allocation.
   * @param minimum_width Location to store the minimum width,
   * or <tt>nullptr</tt>.
   * @param natural_width Location to store the natural width,
   * or <tt>nullptr</tt>.
   */
  void get_preferred_width_for_height(int height, int& minimum_width, int& natural_width) const;

  
  /** Fetches the current allocation size for @a context.
   * 
   * If the context was not allocated in width or height, or if the
   * context was recently reset with reset(),
   * the returned value will be -1.
   * 
   * @newin{3,0}
   * 
   * @param width Location to store the allocated width, or <tt>nullptr</tt>.
   * @param height Location to store the allocated height, or <tt>nullptr</tt>.
   */
  void get_allocation(int& width, int& height) const;

  
  /** Causes the minimum and/or natural width to grow if the new
   * proposed sizes exceed the current minimum and natural width.
   * 
   * This is used by Gtk::CellAreaContext implementations during
   * the request process over a series of Gtk::TreeModel rows to
   * progressively push the requested width over a series of
   * get_preferred_width() requests.
   * 
   * @newin{3,0}
   * 
   * @param minimum_width The proposed new minimum width for @a context.
   * @param natural_width The proposed new natural width for @a context.
   */
  void push_preferred_width(int minimum_width, int natural_width);
  
  /** Causes the minimum and/or natural height to grow if the new
   * proposed sizes exceed the current minimum and natural height.
   * 
   * This is used by Gtk::CellAreaContext implementations during
   * the request process over a series of Gtk::TreeModel rows to
   * progressively push the requested height over a series of
   * get_preferred_height() requests.
   * 
   * @newin{3,0}
   * 
   * @param minimum_height The proposed new minimum height for @a context.
   * @param natural_height The proposed new natural height for @a context.
   */
  void push_preferred_height(int minimum_height, int natural_height);

  /** The Gtk::CellArea this context was created by
   * 
   * @newin{3,0}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< CellArea* > property_area() const;


  /** The minimum width for the Gtk::CellArea in this context
   * for all Gtk::TreeModel rows that this context was requested
   * for using Gtk::CellArea::get_preferred_width().
   * 
   * @newin{3,0}
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< int > property_minimum_width() const;


  /** The natural width for the Gtk::CellArea in this context
   * for all Gtk::TreeModel rows that this context was requested
   * for using Gtk::CellArea::get_preferred_width().
   * 
   * @newin{3,0}
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< int > property_natural_width() const;


  /** The minimum height for the Gtk::CellArea in this context
   * for all Gtk::TreeModel rows that this context was requested
   * for using Gtk::CellArea::get_preferred_height().
   * 
   * @newin{3,0}
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< int > property_minimum_height() const;


  /** The natural height for the Gtk::CellArea in this context
   * for all Gtk::TreeModel rows that this context was requested
   * for using Gtk::CellArea::get_preferred_height().
   * 
   * @newin{3,0}
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< int > property_natural_height() const;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} //namespace Gtk


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gtk::CellAreaContext
   */
  GTKMM_API
  Glib::RefPtr<Gtk::CellAreaContext> wrap(GtkCellAreaContext* object, bool take_copy = false);
}


#endif /* _GTKMM_CELLAREACONTEXT_H */

