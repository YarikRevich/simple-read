// Generated by gmmproc 2.66.4 -- DO NOT MODIFY!
#ifndef _GTKMM_GLAREA_H
#define _GTKMM_GLAREA_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/*
 * Copyright (C) 2015 The gtkmm Development Team
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


#include <gdkmm/glcontext.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkGLArea = struct _GtkGLArea;
using GtkGLAreaClass = struct _GtkGLAreaClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{ class GTKMM_API GLArea_Class; } // namespace Gtk
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gtk
{

/** A widget used for drawing with OpenGL.
 * @newin{3,18}
 * @ingroup Widgets
 */

class GTKMM_API GLArea : public Widget
{
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
  typedef GLArea CppObjectType;
  typedef GLArea_Class CppClassType;
  typedef GtkGLArea BaseObjectType;
  typedef GtkGLAreaClass BaseClassType;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

  GLArea(GLArea&& src) noexcept;
  GLArea& operator=(GLArea&& src) noexcept;

  // noncopyable
  GLArea(const GLArea&) = delete;
  GLArea& operator=(const GLArea&) = delete;

  ~GLArea() noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

private:
  friend class GTKMM_API GLArea_Class;
  static CppClassType glarea_class_;

protected:
  explicit GLArea(const Glib::ConstructParams& construct_params);
  explicit GLArea(GtkGLArea* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  /// Provides access to the underlying C GObject.
  GtkGLArea*       gobj()       { return reinterpret_cast<GtkGLArea*>(gobject_); }

  /// Provides access to the underlying C GObject.
  const GtkGLArea* gobj() const { return reinterpret_cast<GtkGLArea*>(gobject_); }


public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_create_context().
  virtual Glib::RefPtr<Gdk::GLContext> on_create_context();
  /// This is a default handler for the signal signal_render().
  virtual bool on_render(const Glib::RefPtr<Gdk::GLContext>& context);
  /// This is a default handler for the signal signal_resize().
  virtual void on_resize(int width, int height);


private:

public:

  GLArea();

  
  /** Retrieves the Gdk::GLContext used by @a area.
   * 
   * @newin{3,18}
   * 
   * @return The Gdk::GLContext.
   */
  Glib::RefPtr<Gdk::GLContext> get_context();
  
  /** Retrieves the Gdk::GLContext used by @a area.
   * 
   * @newin{3,18}
   * 
   * @return The Gdk::GLContext.
   */
  Glib::RefPtr<const Gdk::GLContext> get_context() const;
  
  /** Ensures that the Gdk::GLContext used by @a area is associated with
   * the Gtk::GLArea.
   * 
   * This function is automatically called before emitting the
   * Gtk::GLArea::signal_render() signal, and doesn't normally need to be called
   * by application code.
   * 
   * @newin{3,18}
   */
  void make_current();
  
  /** Marks the currently rendered data (if any) as invalid, and queues
   * a redraw of the widget, ensuring that the Gtk::GLArea::signal_render() signal
   * is emitted during the draw.
   * 
   * This is only needed when the gtk_gl_area_set_auto_render() has
   * been called with a <tt>false</tt> value. The default behaviour is to
   * emit Gtk::GLArea::signal_render() on each draw.
   * 
   * @newin{3,18}
   */
  void queue_render();
  
  /** Ensures that the @a area framebuffer object is made the current draw
   * and read target, and that all the required buffers for the @a area
   * are created and bound to the frambuffer.
   * 
   * This function is automatically called before emitting the
   * Gtk::GLArea::signal_render() signal, and doesn't normally need to be called
   * by application code.
   * 
   * @newin{3,18}
   */
  void attach_buffers();
  /** Check if any error is currently set on this <i>area</i>.
   *
   * The error may be obtained by using throw_if_error() and
   * set using set_error().
   *
   * @newin{3,18}
   *
   * @return true if an error is currently set.
   */
  bool has_error() const;

  
  /** Will throw the correct Glib::Error subclass if
   * any is currently set on this <i>area</i>.
   *
   * @newin{3,18}
   *
   * @throw Throws any currently set error (e.g. Gdk::GLError).
   */
  void throw_if_error() const;

 
  /** Sets an error on the <i>area</i> which will be shown
   * instead of GL rendering.
   *
   * This is useful in the signal_create_context() handler
   * if GL context creation fails.
   *
   * @newin{3,18}
   *
   * @param error The error to set on the <i>area</i>.
   */
  void set_error(const Glib::Error& error);
  /** Clears any previous set error on this <i>area</i> made with set_error().
   *
   * @newin{3,18}
   */
  void unset_error();
  
  /** Returns whether the area has an alpha component.
   * 
   * @newin{3,18}
   * 
   * @return <tt>true</tt> if the @a area has an alpha component, <tt>false</tt> otherwise.
   */
  bool get_has_alpha() const;
  
  /** If @a has_alpha is <tt>true</tt> the buffer allocated by the widget will have
   * an alpha channel component, and when rendering to the window the
   * result will be composited over whatever is below the widget.
   * 
   * If @a has_alpha is <tt>false</tt> there will be no alpha channel, and the
   * buffer will fully replace anything below the widget.
   * 
   * @newin{3,18}
   * 
   * @param has_alpha <tt>true</tt> to add an alpha component.
   */
  void set_has_alpha(bool has_alpha =  true);
  
  /** Returns whether the area has a depth buffer.
   * 
   * @newin{3,18}
   * 
   * @return <tt>true</tt> if the @a area has a depth buffer, <tt>false</tt> otherwise.
   */
  bool get_has_depth_buffer() const;
  
  /** If @a has_depth_buffer is <tt>true</tt> the widget will allocate and
   * enable a depth buffer for the target framebuffer. Otherwise
   * there will be none.
   * 
   * @newin{3,18}
   * 
   * @param has_depth_buffer <tt>true</tt> to add a depth buffer.
   */
  void set_has_depth_buffer(bool has_depth_buffer =  true);
  
  /** Returns whether the area has a stencil buffer.
   * 
   * @newin{3,18}
   * 
   * @return <tt>true</tt> if the @a area has a stencil buffer, <tt>false</tt> otherwise.
   */
  bool get_has_stencil_buffer() const;
  
  /** If @a has_stencil_buffer is <tt>true</tt> the widget will allocate and
   * enable a stencil buffer for the target framebuffer. Otherwise
   * there will be none.
   * 
   * @newin{3,18}
   * 
   * @param has_stencil_buffer <tt>true</tt> to add a stencil buffer.
   */
  void set_has_stencil_buffer(bool has_stencil_buffer =  true);
  
  /** Returns whether the area is in auto render mode or not.
   * 
   * @newin{3,18}
   * 
   * @return <tt>true</tt> if the @a area is auto rendering, <tt>false</tt> otherwise.
   */
  bool get_auto_render() const;
  
  /** If @a auto_render is <tt>true</tt> the Gtk::GLArea::signal_render() signal will be
   * emitted every time the widget draws. This is the default and is
   * useful if drawing the widget is faster.
   * 
   * If @a auto_render is <tt>false</tt> the data from previous rendering is kept
   * around and will be used for drawing the widget the next time,
   * unless the window is resized. In order to force a rendering
   * gtk_gl_area_queue_render() must be called. This mode is useful when
   * the scene changes seldomly, but takes a long time to redraw.
   * 
   * @newin{3,18}
   * 
   * @param auto_render A boolean.
   */
  void set_auto_render(bool auto_render =  true);
  
  /** Retrieves the required version of OpenGL set
   * using gtk_gl_area_set_required_version().
   * 
   * @newin{3,18}
   * 
   * @param major Return location for the required major version.
   * @param minor Return location for the required minor version.
   */
  void get_required_version(int& major, int& minor) const;
  
  /** Sets the required version of OpenGL to be used when creating the context
   * for the widget.
   * 
   * This function must be called before the area has been realized.
   * 
   * @newin{3,18}
   * 
   * @param major The major version.
   * @param minor The minor version.
   */
  void set_required_version(int major, int minor);
  
  /** Retrieves the value set by gtk_gl_area_set_use_es().
   * 
   * @newin{3,22}
   * 
   * @return <tt>true</tt> if the Gtk::GLArea should create an OpenGL ES context
   * and <tt>false</tt> otherwise.
   */
  bool get_use_es() const;
  
  /** Sets whether the @a area should create an OpenGL or an OpenGL ES context.
   * 
   * You should check the capabilities of the Gdk::GLContext before drawing
   * with either API.
   * 
   * @newin{3,22}
   * 
   * @param use_es Whether to use OpenGL or OpenGL ES.
   */
  void set_use_es(bool use_es =  true);

  /** If set to <tt>true</tt> the Gtk::GLArea::signal_render() signal will be emitted every time
   * the widget draws. This is the default and is useful if drawing the widget
   * is faster.
   * 
   * If set to <tt>false</tt> the data from previous rendering is kept around and will
   * be used for drawing the widget the next time, unless the window is resized.
   * In order to force a rendering gtk_gl_area_queue_render() must be called.
   * This mode is useful when the scene changes seldomly, but takes a long time
   * to redraw.
   * 
   * @newin{3,18}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_auto_render() ;

/** If set to <tt>true</tt> the Gtk::GLArea::signal_render() signal will be emitted every time
   * the widget draws. This is the default and is useful if drawing the widget
   * is faster.
   * 
   * If set to <tt>false</tt> the data from previous rendering is kept around and will
   * be used for drawing the widget the next time, unless the window is resized.
   * In order to force a rendering gtk_gl_area_queue_render() must be called.
   * This mode is useful when the scene changes seldomly, but takes a long time
   * to redraw.
   * 
   * @newin{3,18}
   *
   * Default value: <tt>true</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_auto_render() const;

  /** The Gdk::GLContext used by the Gtk::GLArea widget.
   * 
   * The Gtk::GLArea widget is responsible for creating the Gdk::GLContext
   * instance. If you need to render with other kinds of buffers (stencil,
   * depth, etc), use render buffers.
   * 
   * @newin{3,18}
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< Glib::RefPtr<Gdk::GLContext> > property_context() const;


  /** If set to <tt>true</tt> the buffer allocated by the widget will have an alpha channel
   * component, and when rendering to the window the result will be composited over
   * whatever is below the widget.
   * 
   * If set to <tt>false</tt> there will be no alpha channel, and the buffer will fully
   * replace anything below the widget.
   * 
   * @newin{3,18}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_has_alpha() ;

/** If set to <tt>true</tt> the buffer allocated by the widget will have an alpha channel
   * component, and when rendering to the window the result will be composited over
   * whatever is below the widget.
   * 
   * If set to <tt>false</tt> there will be no alpha channel, and the buffer will fully
   * replace anything below the widget.
   * 
   * @newin{3,18}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_has_alpha() const;

  /** If set to <tt>true</tt> the widget will allocate and enable a depth buffer for the
   * target framebuffer.
   * 
   * @newin{3,18}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_has_depth_buffer() ;

/** If set to <tt>true</tt> the widget will allocate and enable a depth buffer for the
   * target framebuffer.
   * 
   * @newin{3,18}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_has_depth_buffer() const;

  /** If set to <tt>true</tt> the widget will allocate and enable a stencil buffer for the
   * target framebuffer.
   * 
   * @newin{3,18}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_has_stencil_buffer() ;

/** If set to <tt>true</tt> the widget will allocate and enable a stencil buffer for the
   * target framebuffer.
   * 
   * @newin{3,18}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_has_stencil_buffer() const;

  /** If set to <tt>true</tt> the widget will try to create a Gdk::GLContext using
   * OpenGL ES instead of OpenGL.
   * 
   * See also: gdk_gl_context_set_use_es()
   * 
   * @newin{3,22}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< bool > property_use_es() ;

/** If set to <tt>true</tt> the widget will try to create a Gdk::GLContext using
   * OpenGL ES instead of OpenGL.
   * 
   * See also: gdk_gl_context_set_use_es()
   * 
   * @newin{3,22}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_use_es() const;


  /**
   * @par Slot Prototype:
   * <tt>Glib::RefPtr<Gdk::GLContext> on_my_%create_context()</tt>
   *
   * Flags: Run Last
   *
   * The signal_create_context() signal is emitted when the widget is being
   * realized, and allows you to override how the GL context is
   * created. This is useful when you want to reuse an existing GL
   * context, or if you want to try creating different kinds of GL
   * options.
   * 
   * If context creation fails then the signal handler can use
   * gtk_gl_area_set_error() to register a more detailed error
   * of how the construction failed.
   * 
   * @newin{3,18}
   * 
   * @return A newly created Gdk::GLContext;
   * the Gtk::GLArea widget will take ownership of the returned value.
   */

  Glib::SignalProxy< Glib::RefPtr<Gdk::GLContext> > signal_create_context();

 
  /**
   * @par Slot Prototype:
   * <tt>bool on_my_%render(const Glib::RefPtr<Gdk::GLContext>& context)</tt>
   *
   * Flags: Run Last
   *
   * The signal_render() signal is emitted every time the contents
   * of the Gtk::GLArea should be redrawn.
   * 
   * The @a context is bound to the @a area prior to emitting this function,
   * and the buffers are painted to the window once the emission terminates.
   * 
   * @newin{3,18}
   * 
   * @param context The Gdk::GLContext used by @a area.
   * @return <tt>true</tt> to stop other handlers from being invoked for the event.
   * <tt>false</tt> to propagate the event further.
   */

  Glib::SignalProxy< bool,const Glib::RefPtr<Gdk::GLContext>& > signal_render();

  
  /**
   * @par Slot Prototype:
   * <tt>void on_my_%resize(int width, int height)</tt>
   *
   * Flags: Run Last
   *
   * The signal_resize() signal is emitted once when the widget is realized, and
   * then each time the widget is changed while realized. This is useful
   * in order to keep GL state up to date with the widget size, like for
   * instance camera properties which may depend on the width/height ratio.
   * 
   * The GL context for the area is guaranteed to be current when this signal
   * is emitted.
   * 
   * The default handler sets up the GL viewport.
   * 
   * @newin{3,18}
   * 
   * @param width The width of the viewport.
   * @param height The height of the viewport.
   */

  Glib::SignalProxy< void,int,int > signal_resize();


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
   * @relates Gtk::GLArea
   */
  GTKMM_API
  Gtk::GLArea* wrap(GtkGLArea* object, bool take_copy = false);
} //namespace Glib


#endif /* _GTKMM_GLAREA_H */

