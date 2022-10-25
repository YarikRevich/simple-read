// Generated by gmmproc 2.66.4 -- DO NOT MODIFY!
#ifndef _GTKMM_CELLRENDERER_H
#define _GTKMM_CELLRENDERER_H

#include <gtkmmconfig.h>


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 1998-2002 The gtkmm Development Team
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


#include <gtkmm/widget.h>
#include <gtkmm/celleditable.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkCellRenderer = struct _GtkCellRenderer;
using GtkCellRendererClass = struct _GtkCellRendererClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API CellRenderer_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** @addtogroup gtkmmEnums gtkmm Enums and Flags */

/** 
 *  @var CellRendererState CELL_RENDERER_SELECTED
 * The cell is currently selected, and
 * probably has a selection colored background to render to.
 * 
 *  @var CellRendererState CELL_RENDERER_PRELIT
 * The mouse is hovering over the cell.
 * 
 *  @var CellRendererState CELL_RENDERER_INSENSITIVE
 * The cell is drawn in an insensitive manner.
 * 
 *  @var CellRendererState CELL_RENDERER_SORTED
 * The cell is in a sorted row.
 * 
 *  @var CellRendererState CELL_RENDERER_FOCUSED
 * The cell is in the focus row.
 * 
 *  @var CellRendererState CELL_RENDERER_EXPANDABLE
 * The cell is in a row that can be expanded. @newin{3,4}
 * 
 *  @var CellRendererState CELL_RENDERER_EXPANDED
 * The cell is in a row that is expanded. @newin{3,4}
 * 
 *  @enum CellRendererState
 * 
 * Tells how a cell is to be rendered.
 *
 * @ingroup gtkmmEnums
 * @par Bitwise operators:
 * <tt>%CellRendererState operator|(CellRendererState, CellRendererState)</tt><br>
 * <tt>%CellRendererState operator&(CellRendererState, CellRendererState)</tt><br>
 * <tt>%CellRendererState operator^(CellRendererState, CellRendererState)</tt><br>
 * <tt>%CellRendererState operator~(CellRendererState)</tt><br>
 * <tt>%CellRendererState& operator|=(CellRendererState&, CellRendererState)</tt><br>
 * <tt>%CellRendererState& operator&=(CellRendererState&, CellRendererState)</tt><br>
 * <tt>%CellRendererState& operator^=(CellRendererState&, CellRendererState)</tt><br>
 */
enum CellRendererState
{
  CELL_RENDERER_SELECTED = 1 << 0,
  CELL_RENDERER_PRELIT = 1 << 1,
  CELL_RENDERER_INSENSITIVE = 1 << 2,
  CELL_RENDERER_SORTED = 1 << 3,
  CELL_RENDERER_FOCUSED = 1 << 4,
  CELL_RENDERER_EXPANDABLE = 1 << 5,
  CELL_RENDERER_EXPANDED = 1 << 6
};

/** @ingroup gtkmmEnums */
inline CellRendererState operator|(CellRendererState lhs, CellRendererState rhs)
  { return static_cast<CellRendererState>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline CellRendererState operator&(CellRendererState lhs, CellRendererState rhs)
  { return static_cast<CellRendererState>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline CellRendererState operator^(CellRendererState lhs, CellRendererState rhs)
  { return static_cast<CellRendererState>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs)); }

/** @ingroup gtkmmEnums */
inline CellRendererState operator~(CellRendererState flags)
  { return static_cast<CellRendererState>(~static_cast<unsigned>(flags)); }

/** @ingroup gtkmmEnums */
inline CellRendererState& operator|=(CellRendererState& lhs, CellRendererState rhs)
  { return (lhs = static_cast<CellRendererState>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline CellRendererState& operator&=(CellRendererState& lhs, CellRendererState rhs)
  { return (lhs = static_cast<CellRendererState>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs))); }

/** @ingroup gtkmmEnums */
inline CellRendererState& operator^=(CellRendererState& lhs, CellRendererState rhs)
  { return (lhs = static_cast<CellRendererState>(static_cast<unsigned>(lhs) ^ static_cast<unsigned>(rhs))); }

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::CellRendererState> : public Glib::Value_Flags<Gtk::CellRendererState>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{

/** 
 *  @var CellRendererMode CELL_RENDERER_MODE_INERT
 * The cell is just for display
 * and cannot be interacted with.  Note that this doesn’t mean that eg. the
 * row being drawn can’t be selected -- just that a particular element of
 * it cannot be individually modified.
 * 
 *  @var CellRendererMode CELL_RENDERER_MODE_ACTIVATABLE
 * The cell can be clicked.
 * 
 *  @var CellRendererMode CELL_RENDERER_MODE_EDITABLE
 * The cell can be edited or otherwise modified.
 * 
 *  @enum CellRendererMode
 * 
 * Identifies how the user can interact with a particular cell.
 *
 * @ingroup gtkmmEnums
 */
enum CellRendererMode
{
  CELL_RENDERER_MODE_INERT,
  CELL_RENDERER_MODE_ACTIVATABLE,
  CELL_RENDERER_MODE_EDITABLE
};

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GTKMM_API Value<Gtk::CellRendererMode> : public Glib::Value_Enum<Gtk::CellRendererMode>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gtk
{


/** CellRenderers are used by Gtk::TreeView columns to render the Gtk::TreeModel column data appropriately.
 * They display, and allow editing of, the values of their properties.
 * In most cases, Gtk::TreeView::append_column() will automatically choose the appropriate renderer for the mode column's data type,
 * so you will rarely need to worry about these classes.
 *
 * @ingroup TreeView
 */

class GTKMM_API CellRenderer :
  public Object
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef CellRenderer CppObjectType;
  typedef CellRenderer_Class CppClassType;
  typedef GtkCellRenderer BaseObjectType;
  typedef GtkCellRendererClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  CellRenderer(CellRenderer&& src) noexcept;
  CellRenderer& operator=(CellRenderer&& src) noexcept;

  // noncopyable
  CellRenderer(const CellRenderer&) = delete;
  CellRenderer& operator=(const CellRenderer&) = delete;

  ~CellRenderer() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class GTKMM_API CellRenderer_Class;
  static CppClassType cellrenderer_class_;

protected:
  explicit CellRenderer(const Glib::ConstructParams& construct_params);
  explicit CellRenderer(GtkCellRenderer* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  GtkCellRenderer*       gobj()       { return reinterpret_cast<GtkCellRenderer*>(gobject_); }

  /// Provides access to the underlying C GObject.
  const GtkCellRenderer* gobj() const { return reinterpret_cast<GtkCellRenderer*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_editing_canceled().
  virtual void on_editing_canceled();
  /// This is a default handler for the signal signal_editing_started().
  virtual void on_editing_started(CellEditable* editable, const Glib::ustring& path);


private:

public:

   //Deprecated

  
  /** Gets whether the cell renderer prefers a height-for-width layout
   * or a width-for-height layout.
   * 
   * @newin{3,0}
   * 
   * @return The Gtk::SizeRequestMode preferred by this renderer.
   */
  SizeRequestMode get_request_mode() const;
  
  /** Retreives a renderer’s natural size when rendered to @a widget.
   * 
   * @newin{3,0}
   * 
   * @param widget The Gtk::Widget this cell will be rendering to.
   * @param minimum_width Location to store the minimum size, or <tt>nullptr</tt>.
   * @param natural_width Location to store the natural size, or <tt>nullptr</tt>.
   */
  void get_preferred_width(Widget& widget, int& minimum_width, int& natural_width) const;
  
  /** Retreives a cell renderers’s minimum and natural height if it were rendered to 
   *  @a widget with the specified @a width.
   * 
   * @newin{3,0}
   * 
   * @param widget The Gtk::Widget this cell will be rendering to.
   * @param width The size which is available for allocation.
   * @param minimum_height Location for storing the minimum size, or <tt>nullptr</tt>.
   * @param natural_height Location for storing the preferred size, or <tt>nullptr</tt>.
   */
  void get_preferred_height_for_width(Widget& widget, int width, int& minimum_height, int& natural_height) const;
  
  /** Retreives a renderer’s natural size when rendered to @a widget.
   * 
   * @newin{3,0}
   * 
   * @param widget The Gtk::Widget this cell will be rendering to.
   * @param minimum_height Location to store the minimum size, or <tt>nullptr</tt>.
   * @param natural_height Location to store the natural size, or <tt>nullptr</tt>.
   */
  void get_preferred_height(Widget& widget, int& minimum_height, int& natural_height) const;
  
  /** Retreives a cell renderers’s minimum and natural width if it were rendered to 
   *  @a widget with the specified @a height.
   * 
   * @newin{3,0}
   * 
   * @param widget The Gtk::Widget this cell will be rendering to.
   * @param height The size which is available for allocation.
   * @param minimum_width Location for storing the minimum size, or <tt>nullptr</tt>.
   * @param natural_width Location for storing the preferred size, or <tt>nullptr</tt>.
   */
  void get_preferred_width_for_height(Widget& widget, int height, int& minimum_width, int& natural_width) const;
  
  /** Retrieves the minimum and natural size of a cell taking
   * into account the widget’s preference for height-for-width management.
   * 
   * @newin{3,0}
   * 
   * @param widget The Gtk::Widget this cell will be rendering to.
   * @param minimum_size Location for storing the minimum size, or <tt>nullptr</tt>.
   * @param natural_size Location for storing the natural size, or <tt>nullptr</tt>.
   */
  void get_preferred_size(Widget& widget, Requisition& minimum_size, Requisition& natural_size) const;

  //TODO: Use a return value intead?
  
  /** Gets the aligned area used by @a cell inside @a cell_area. Used for finding
   * the appropriate edit and focus rectangle.
   * 
   * @newin{3,0}
   * 
   * @param widget The Gtk::Widget this cell will be rendering to.
   * @param flags Render flags.
   * @param cell_area Cell area which would be passed to render().
   * @param aligned_area The return location for the space inside @a cell_area
   * that would acually be used to render.
   */
  void get_aligned_area(Widget& widget, CellRendererState flags, const Gdk::Rectangle& cell_area, Gdk::Rectangle& aligned_area);

  
  /** Invokes the virtual render function of the Gtk::CellRenderer. The three
   * passed-in rectangles are areas in @a cr. Most renderers will draw within
   *  @a cell_area; the xalign, yalign, xpad, and ypad fields of the Gtk::CellRenderer
   * should be honored with respect to @a cell_area. @a background_area includes the
   * blank space around the cell, and also the area containing the tree expander;
   * so the @a background_area rectangles for all cells tile to cover the entire
   *  @a window.
   * 
   * @param cr A cairo context to draw to.
   * @param widget The widget owning @a window.
   * @param background_area Entire cell area (including tree expanders and maybe 
   * padding on the sides).
   * @param cell_area Area normally rendered by a cell renderer.
   * @param flags Flags that affect rendering.
   */
  void render(const ::Cairo::RefPtr< ::Cairo::Context>& cr, Widget& widget, const Gdk::Rectangle& background_area, const Gdk::Rectangle& cell_area, CellRendererState flags);

  
  /** Passes an activate event to the cell renderer for possible processing.  
   * Some cell renderers may use events; for example, Gtk::CellRendererToggle 
   * toggles when it gets a mouse click.
   * 
   * @param event A Gdk::Event.
   * @param widget Widget that received the event.
   * @param path Widget-dependent string representation of the event location; 
   * e.g. for Gtk::TreeView, a string representation of Gtk::TreePath.
   * @param background_area Background area as passed to render().
   * @param cell_area Cell area as passed to render().
   * @param flags Render flags.
   * @return <tt>true</tt> if the event was consumed/handled.
   */
  bool activate(GdkEvent* event, Widget& widget, const Glib::ustring& path, const Gdk::Rectangle& background_area, const Gdk::Rectangle& cell_area, CellRendererState flags);

  
  /** Starts editing the contents of this @a cell, through a new Gtk::CellEditable
   * widget created by the Gtk::CellRendererClass.start_editing virtual function.
   * 
   * @param event A Gdk::Event.
   * @param widget Widget that received the event.
   * @param path Widget-dependent string representation of the event location;
   * e.g. for Gtk::TreeView, a string representation of Gtk::TreePath.
   * @param background_area Background area as passed to render().
   * @param cell_area Cell area as passed to render().
   * @param flags Render flags.
   * @return A new Gtk::CellEditable for editing this
   *  @a cell, or <tt>nullptr</tt> if editing is not possible.
   */
  CellEditable* start_editing(GdkEvent* event, Widget& widget, const Glib::ustring& path, const Gdk::Rectangle& background_area, const Gdk::Rectangle& cell_area, CellRendererState flags =  CellRendererState(0));

  
  /** Sets the renderer size to be explicit, independent of the properties set.
   * 
   * @param width The width of the cell renderer, or -1.
   * @param height The height of the cell renderer, or -1.
   */
  void set_fixed_size(int width, int height);
  
  /** Fills in @a width and @a height with the appropriate size of @a cell.
   * 
   * @param width Location to fill in with the fixed width of the widget.
   * @param height Location to fill in with the fixed height of the widget.
   */
  void get_fixed_size(int& width, int& height) const;

  
  /** Sets the renderer’s alignment within its available space.
   * 
   * @newin{2,18}
   * 
   * @param xalign The x alignment of the cell renderer.
   * @param yalign The y alignment of the cell renderer.
   */
  void set_alignment(float xalign, float yalign);
  
  /** Fills in @a xalign and @a yalign with the appropriate values of @a cell.
   * 
   * @newin{2,18}
   * 
   * @param xalign Location to fill in with the x alignment of the cell, or <tt>nullptr</tt>.
   * @param yalign Location to fill in with the y alignment of the cell, or <tt>nullptr</tt>.
   */
  void get_alignment(float& xalign, float& yalign) const;

  
  /** Sets the renderer’s padding.
   * 
   * @newin{2,18}
   * 
   * @param xpad The x padding of the cell renderer.
   * @param ypad The y padding of the cell renderer.
   */
  void set_padding(int xpad, int ypad);
  
  /** Fills in @a xpad and @a ypad with the appropriate values of @a cell.
   * 
   * @newin{2,18}
   * 
   * @param xpad Location to fill in with the x padding of the cell, or <tt>nullptr</tt>.
   * @param ypad Location to fill in with the y padding of the cell, or <tt>nullptr</tt>.
   */
  void get_padding(int& xpad, int& ypad) const;

  
  /** Sets the cell renderer’s visibility.
   * 
   * @newin{2,18}
   * 
   * @param visible The visibility of the cell.
   */
  void set_visible(bool visible =  true);
  
  /** Returns the cell renderer’s visibility.
   * 
   * @newin{2,18}
   * 
   * @return <tt>true</tt> if the cell renderer is visible.
   */
  bool get_visible() const;
  
  /** Sets the cell renderer’s sensitivity.
   * 
   * @newin{2,18}
   * 
   * @param sensitive The sensitivity of the cell.
   */
  void set_sensitive(bool sensitive =  true);
  
  /** Returns the cell renderer’s sensitivity.
   * 
   * @newin{2,18}
   * 
   * @return <tt>true</tt> if the cell renderer is sensitive.
   */
  bool get_sensitive() const;
  
  /** Checks whether the cell renderer can do something when activated.
   * 
   * @newin{3,0}
   * 
   * @return <tt>true</tt> if the cell renderer can do anything when activated.
   */
  bool is_activatable() const;

  
  /** Informs the cell renderer that the editing is stopped.
   * If @a canceled is <tt>true</tt>, the cell renderer will emit the 
   * Gtk::CellRenderer::signal_editing_canceled() signal. 
   * 
   * This function should be called by cell renderer implementations 
   * in response to the Gtk::CellEditable::signal_editing_done() signal of 
   * Gtk::CellEditable.
   * 
   * @newin{2,6}
   * 
   * @param canceled <tt>true</tt> if the editing has been canceled.
   */
  void stop_editing(bool canceled =  false);

  
  /** Translates the cell renderer state to Gtk::StateFlags,
   * based on the cell renderer and widget sensitivity, and
   * the given Gtk::CellRendererState.
   * 
   * @newin{3,0}
   * 
   * @param widget A Gtk::Widget, or <tt>nullptr</tt>.
   * @param cell_state Cell renderer state.
   * @return The widget state flags applying to @a cell.
   */
  StateFlags get_state(Widget& widget, CellRendererState cell_state) const;


  /** Translates the cell renderer state to StateFlags,
   * based on the cell renderer and
   * the given CellRendererState.
   *
   * @param cell_state The cell renderer state.
   *
   * @result The widget state flags applying to the cell renderer.
   *
   * @newin{3,0}
   */
  StateFlags get_state(CellRendererState cell_state) const;

  /** Returns the property that this CellRenderer renders.
   * For instance, property_text for CellRendererText, and property_active for CellRendererToggle
   * Needs to be overridden in derived classes.
   */
  virtual Glib::PropertyProxy_Base _property_renderable();

  
  /**
   * @par Slot Prototype:
   * <tt>void on_my_%editing_canceled()</tt>
   *
   * Flags: Run First
   *
   * This signal gets emitted when the user cancels the process of editing a
   * cell.  For example, an editable cell renderer could be written to cancel
   * editing when the user presses Escape. 
   * 
   * See also: Gtk::CellRenderer::stop_editing().
   * 
   * @newin{2,4}
   */

  Glib::SignalProxy< void > signal_editing_canceled();


  /**
   * @par Slot Prototype:
   * <tt>void on_my_%editing_started(CellEditable* editable, const Glib::ustring& path)</tt>
   *
   * Flags: Run First
   *
   * This signal gets emitted when a cell starts to be edited.
   * The intended use of this signal is to do special setup
   * on @a editable, e.g. adding a Gtk::EntryCompletion or setting
   * up additional columns in a Gtk::ComboBox.
   * 
   * See Gtk::CellEditable::start_editing() for information on the lifecycle of
   * the @a editable and a way to do setup that doesn’t depend on the @a renderer.
   * 
   * Note that GTK+ doesn't guarantee that cell renderers will
   * continue to use the same kind of widget for editing in future
   * releases, therefore you should check the type of @a editable
   * before doing any specific setup, as in the following example:
   * 
   * [C example ellipted]
   * 
   * @newin{2,6}
   * 
   * @param editable The Gtk::CellEditable.
   * @param path The path identifying the edited cell.
   */

  Glib::SignalProxy< void,CellEditable*,const Glib::ustring& > signal_editing_started();


  /** Editable mode of the CellRenderer.
   *
   * Default value: Gtk::CELL_RENDERER_MODE_INERT
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< CellRendererMode > property_mode() ;

/** Editable mode of the CellRenderer.
   *
   * Default value: Gtk::CELL_RENDERER_MODE_INERT
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< CellRendererMode > property_mode() const;

  /** Display the cell.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_visible() ;

/** Display the cell.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_visible() const;

  /** Display the cell sensitive.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_sensitive() ;

/** Display the cell sensitive.
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_sensitive() const;

  /** The x-align.
   *
   * Default value: 0.5
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< float > property_xalign() ;

/** The x-align.
   *
   * Default value: 0.5
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< float > property_xalign() const;

  /** The y-align.
   *
   * Default value: 0.5
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< float > property_yalign() ;

/** The y-align.
   *
   * Default value: 0.5
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< float > property_yalign() const;

  /** The xpad.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< unsigned int > property_xpad() ;

/** The xpad.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< unsigned int > property_xpad() const;

  /** The ypad.
   *
   * Default value: 0
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< unsigned int > property_ypad() ;

/** The ypad.
   *
   * Default value: 0
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< unsigned int > property_ypad() const;

  /** The fixed width.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< int > property_width() ;

/** The fixed width.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< int > property_width() const;

  /** The fixed height.
   *
   * Default value: -1
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< int > property_height() ;

/** The fixed height.
   *
   * Default value: -1
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< int > property_height() const;

  /** Row has children.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_is_expander() ;

/** Row has children.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_is_expander() const;

  /** Row is an expander row, and is expanded.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_is_expanded() ;

/** Row is an expander row, and is expanded.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_is_expanded() const;

  /** Cell background color as a string.
   *
   * Default value: ""
   *
   * @return A PropertyProxy_WriteOnly that allows you to set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_WriteOnly< Glib::ustring > property_cell_background() ;


#ifndef GTKMM_DISABLE_DEPRECATED

/** Cell background as a Gdk::Color
   * 
   * Deprecated: 3.4: Use Gtk::CellRenderer::property_cell_background_rgba() instead.
   * 
   * @deprecated Use property_cell_background_rgba() instead.
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< Gdk::Color > property_cell_background_gdk() ;

/** Cell background as a Gdk::Color
   * 
   * Deprecated: 3.4: Use Gtk::CellRenderer::property_cell_background_rgba() instead.
   * 
   * @deprecated Use property_cell_background_rgba() instead.
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Gdk::Color > property_cell_background_gdk() const;

#endif // GTKMM_DISABLE_DEPRECATED

  /** Cell background as a Gdk::RGBA
   * 
   * @newin{3,0}
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< Gdk::RGBA > property_cell_background_rgba() ;

/** Cell background as a Gdk::RGBA
   * 
   * @newin{3,0}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Gdk::RGBA > property_cell_background_rgba() const;

  /** Whether the cell background color is set.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_cell_background_set() ;

/** Whether the cell background color is set.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_cell_background_set() const;

  /** Whether the cell renderer is currently in editing mode.
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_editing() const;


protected:
  CellRenderer();


    virtual SizeRequestMode get_request_mode_vfunc() const;

    virtual void get_preferred_width_vfunc(Widget& widget, int& minimum_width, int& natural_width) const;

    virtual void get_preferred_height_for_width_vfunc(Widget& widget, int width, int& minimum_height, int& natural_height) const;

    virtual void get_preferred_height_vfunc(Widget& widget, int& minimum_height, int& natural_height) const;

    virtual void get_preferred_width_for_height_vfunc(Widget& widget, int height, int& minimum_width, int& natural_width) const;


    virtual void render_vfunc(const ::Cairo::RefPtr< ::Cairo::Context>& cr, Widget& widget, const Gdk::Rectangle& background_area, const Gdk::Rectangle& cell_area, CellRendererState flags);


    virtual bool activate_vfunc(GdkEvent* event, Widget& widget, const Glib::ustring& path, const Gdk::Rectangle& background_area, const Gdk::Rectangle& cell_area, CellRendererState flags);


    virtual CellEditable* start_editing_vfunc(GdkEvent* event, Widget& widget, const Glib::ustring& path, const Gdk::Rectangle& background_area, const Gdk::Rectangle& cell_area, CellRendererState flags);


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
   * @relates Gtk::CellRenderer
   */
  GTKMM_API
  Gtk::CellRenderer* wrap(GtkCellRenderer* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_CELLRENDERER_H */

