// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GIOMM_DATAINPUTSTREAM_H
#define _GIOMM_DATAINPUTSTREAM_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2007 The gtkmm Development Team
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
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <giomm/bufferedinputstream.h>
#include <giomm/enums.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GDataInputStream = struct _GDataInputStream;
using GDataInputStreamClass = struct _GDataInputStreamClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API DataInputStream_Class; } // namespace Gio
#endif //DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/**
 * An implementation of BufferedInputStream that allows for high-level data
 * manipulation of arbitrary data (including binary operations).
 *
 * @ingroup Streams
 *
 * @newin{2,16}
 */

class GIOMM_API DataInputStream : public Gio::BufferedInputStream
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = DataInputStream;
  using CppClassType = DataInputStream_Class;
  using BaseObjectType = GDataInputStream;
  using BaseClassType = GDataInputStreamClass;

  // noncopyable
  DataInputStream(const DataInputStream&) = delete;
  DataInputStream& operator=(const DataInputStream&) = delete;

private:  friend class DataInputStream_Class;
  static CppClassType datainputstream_class_;

protected:
  explicit DataInputStream(const Glib::ConstructParams& construct_params);
  explicit DataInputStream(GDataInputStream* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  DataInputStream(DataInputStream&& src) noexcept;
  DataInputStream& operator=(DataInputStream&& src) noexcept;

  ~DataInputStream() noexcept override;

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS


  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GDataInputStream*       gobj()       { return reinterpret_cast<GDataInputStream*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GDataInputStream* gobj() const { return reinterpret_cast<GDataInputStream*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GDataInputStream* gobj_copy();

private:


protected:
    explicit DataInputStream(const Glib::RefPtr<InputStream>& base_stream);


public:

  
  static Glib::RefPtr<DataInputStream> create(const Glib::RefPtr<InputStream>& base_stream);


  /** This function sets the byte order for the given @a stream. All subsequent
   * reads from the @a stream will be read in the given @a order.
   * 
   * @param order A DataStreamByteOrder to set.
   */
  void set_byte_order(DataStreamByteOrder order);
  
  /** Gets the byte order for the data input stream.
   * 
   * @return The @a stream's current DataStreamByteOrder.
   */
  DataStreamByteOrder get_byte_order() const;
  
  /** Sets the newline type for the @a stream.
   * 
   * Note that using G_DATA_STREAM_NEWLINE_TYPE_ANY is slightly unsafe. If a read
   * chunk ends in "CR" we must read an additional byte to know if this is "CR" or
   * "CR LF", and this might block if there is no more data available.
   * 
   * @param type The type of new line return as DataStreamNewlineType.
   */
  void set_newline_type(DataStreamNewlineType type);
  
  /** Gets the current newline type for the @a stream.
   * 
   * @return DataStreamNewlineType for the given @a stream.
   */
  DataStreamNewlineType get_newline_type() const;

  
  /** Reads an unsigned 8-bit/1-byte value from @a stream.
   * 
   * @param cancellable Optional Cancellable object, <tt>nullptr</tt> to ignore.
   * @return An unsigned 8-bit/1-byte value read from the @a stream or `0`
   * if an error occurred.
   * 
   * @throws Glib::Error
   */
  guchar read_byte(const Glib::RefPtr<Cancellable>& cancellable);

  /// A read_byte() convenience overload.
  guchar read_byte();

  
  /** Reads a 16-bit/2-byte value from @a stream.
   * 
   * In order to get the correct byte order for this read operation, 
   * see g_data_input_stream_get_byte_order() and g_data_input_stream_set_byte_order().
   * 
   * @param cancellable Optional Cancellable object, <tt>nullptr</tt> to ignore.
   * @return A signed 16-bit/2-byte value read from @a stream or `0` if
   * an error occurred.
   * 
   * @throws Glib::Error
   */
  gint16 read_int16(const Glib::RefPtr<Cancellable>& cancellable);

  /// A read_int16() convenience overload.
  gint16 read_int16();

  
  /** Reads an unsigned 16-bit/2-byte value from @a stream.
   * 
   * In order to get the correct byte order for this read operation, 
   * see g_data_input_stream_get_byte_order() and g_data_input_stream_set_byte_order().
   * 
   * @param cancellable Optional Cancellable object, <tt>nullptr</tt> to ignore.
   * @return An unsigned 16-bit/2-byte value read from the @a stream or `0` if
   * an error occurred.
   * 
   * @throws Glib::Error
   */
  guint16 read_uint16(const Glib::RefPtr<Cancellable>& cancellable);

  /// A read_uint16() convenience overload.
  guint16 read_uint16();

  
  /** Reads a signed 32-bit/4-byte value from @a stream.
   * 
   * In order to get the correct byte order for this read operation, 
   * see Glib::data_stream_get_byte_order() and Glib::data_stream_set_byte_order().
   * 
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED.
   * 
   * @param cancellable Cancellable object.
   * @return A signed 32-bit/4-byte value read from the @a stream or %0 if 
   * an error occurred.
   * 
   * @throws Glib::Error
   */
  gint32 read_int32(const Glib::RefPtr<Cancellable>& cancellable);

  /// A read_int32() convenience overload.
  gint32 read_int32();

  
  /** Reads an unsigned 32-bit/4-byte value from @a stream.
   * 
   * In order to get the correct byte order for this read operation, 
   * see Glib::data_stream_get_byte_order() and Glib::data_stream_set_byte_order().
   * 
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED.
   * 
   * @param cancellable Cancellable object.
   * @return An unsigned 32-bit/4-byte value read from the @a stream or %0 if 
   * an error occurred.
   * 
   * @throws Glib::Error
   */
  guint32 read_uint32(const Glib::RefPtr<Cancellable>& cancellable);

  /// A read_uint32() convenience overload.
  guint32 read_uint32();

  
  /** Reads a 64-bit/8-byte value from @a stream.
   * 
   * In order to get the correct byte order for this read operation, 
   * see Glib::data_stream_get_byte_order() and Glib::data_stream_set_byte_order().
   * 
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED.
   * 
   * @param cancellable Cancellable object.
   * @return A signed 64-bit/8-byte value read from @a stream or %0 if 
   * an error occurred.
   * 
   * @throws Glib::Error
   */
  gint64 read_int64(const Glib::RefPtr<Cancellable>& cancellable);

  /// A read_int64() convenience overload.
  gint64 read_int64();

  
  /** Reads an unsigned 64-bit/8-byte value from @a stream.
   * 
   * In order to get the correct byte order for this read operation, 
   * see Glib::data_stream_get_byte_order().
   * 
   * The operation can be cancelled by
   * triggering the cancellable object from another thread. If the operation
   * was cancelled, a Gio::Error will be thrown with CANCELLED.
   * 
   * @param cancellable Cancellable object.
   * @return An unsigned 64-bit/8-byte read from @a stream or %0 if 
   * an error occurred.
   * 
   * @throws Glib::Error
   */
  guint64 read_uint64(const Glib::RefPtr<Cancellable>& cancellable);

  /// A read_uint64() convenience overload.
  guint64 read_uint64();

  //Note that we return a bool because we can't use std::string to distinguish between an empty string and a nullptr.

  /** Reads a line from the data input stream.
   *
   * The operation can be cancelled by triggering the cancellable object from
   * another thread. If the operation
   * was cancelled, a Gio::Error with CANCELLED will be thrown.
   *
   * @param[out] line A string to fill with the read data (without the newlines).
   * @param cancellable A cancellable object.
   * @result true if the read succeeded without error.
   */
  bool read_line(std::string& line, const Glib::RefPtr<Cancellable>& cancellable);
  

  /** A non-cancellable version of read_line().
   *
   * @param[out] line A string to fill with the read data (without the newlines).
   * @result true if the read succeeded without error.
   */
  bool read_line(std::string& line);

 
  /** Reads a UTF-8 encoded line from the data input stream.
   *
   * If @a cancellable is supplied and not equal to Glib::RefPtr<Cancellable>(),
   * then the operation can be cancelled by triggering the cancellable object
   * from another thread. If the operation was cancelled, Gio::Error with
   * code() == Gio::Error::CANCELLED will be thrown.
   *
   * @newin{2,30}
   *
   * @param[out] line A UTF-8 string with the line that was read in (without the newlines).
   *   Supply @a length to get the length of the read line. On an error,
   *   @a line is set to an empty string and an exception is thrown. For UTF-8
   *   conversion errors, a Glib::ConvertError is thrown. If there's no content
   *   to read, @a line will still be set to an empty string, but no exception
   *   will be thrown.
   * @param cancellable Optional Cancellable object.
   * @param[out] length An optional gsize to get the length of the data read in.
   */
  void read_line_utf8(std::string& line, const Glib::RefPtr<Cancellable>& cancellable, gsize& length);

  /// A read_line_utf8() convenience overload.
  void read_line_utf8(std::string& line, const Glib::RefPtr<Cancellable>& cancellable);

  /// A read_line_utf8() convenience overload.
  void read_line_utf8(std::string& line, gsize& length);

  /// A read_line_utf8() convenience overload.
  void read_line_utf8(std::string& line);

  /** The asynchronous version of read_line(). It is
   * an error to have two outstanding calls to this function.
   *
   * @param slot The slot to call when the request is satisfied.
   * @param cancellable A cancellable object.
   * @param io_priority The I/O priority of the request.
   */
  void read_line_async(const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, int io_priority = Glib::PRIORITY_DEFAULT);
  

  /** Finish an asynchronous call started by read_line_async().
   *
   * @param result The AsyncResult that was provided to the callback slot.
   * @param[out] data A string to fill with the read data.
   * @result true if the read succeeded without error.
   */
  bool read_line_finish(const Glib::RefPtr<AsyncResult>& result, std::string& data);
  

  /** Finish an asynchronous call started by read_line_async().
   *
   * @newin{2,30}
   *
   * @param result The AsyncResult that was provided to the callback.
   * @param[out] data A UTF-8 string with the line that was read in (without the newlines).
   *   Supply @a length to get the length of the read line. On an error,
   *   @a line is set to an empty string and an exception is thrown. For UTF-8
   *   conversion errors, a Glib::ConvertError is thrown. If there's no content
   *   to read, @a line will still be set to an empty string, but no exception
   *   will be thrown.
   * @param[out] length An optional gsize to get the length of the data read in.
   */
  void read_line_finish_utf8(const Glib::RefPtr<AsyncResult>& result, std::string& data, gsize& length);

  /// A read_line_finish_utf8() convenience overload.
  void read_line_finish_utf8(const Glib::RefPtr<AsyncResult>& result, std::string& data);

  
 /** Reads a string from the data input stream, up to the first
   * occurrence of any of the stop characters.
   *
   * This method does <em>not</em> consume the stop character. You have
   * to use read_byte() to get it before calling %read_upto() again.
   *
   * @param[out] data A string to fill with the read data.
   * @param stop_chars Characters to terminate the read.
   * @param cancellable A cancellable object.
   * @result true if the read succeeded without error.
   */
  bool read_upto(std::string& data, const std::string& stop_chars, const Glib::RefPtr<Cancellable>& cancellable);
  

  /** A non-cancellable version of read_upto().
   * @param[out] data A string to fill with the read data.
   * @param stop_chars Characters to terminate the read.
   * @result true if the read succeeded without error.
   */
  bool read_upto(std::string& data, const std::string& stop_chars);

  //TODO: Add a version that takes the stop_chars length, to allow a 0 in the middle?

  /** The asynchronous version of read_upto(). It is
   * an error to have two outstanding calls to this function.
   *
   * This method does <em>not</em> consume the stop character. You have
   * to use read_byte() to get it before calling %read_upto_async() again.
   *
   * @param stop_chars Characters to terminate the read.
   * @param slot The slot to call when the request is satisfied.
   * @param cancellable A cancellable object.
   * @param io_priority The I/O priority of the request.
   */
  void read_upto_async(const std::string& stop_chars, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, int io_priority = Glib::PRIORITY_DEFAULT);
  

  /** Finish an asynchronous call started by read_upto_async().
   *
   * Note that this function does <em>not</em> consume the
   * stop character. You have to use read_byte() to
   * get it before calling read_upto_async() again.
   *
   * @param result The AsyncResult that was provided to the callback slot.
   * @param[out] data A string to fill with the read data.
   * @result true if the read succeeded without error.
   */
  bool read_upto_finish(const Glib::RefPtr<AsyncResult>& result, std::string& data);
  

  /** The :byte-order property determines the byte ordering that
   * is used when reading multi-byte entities (such as integers)
   * from the stream.
   *
   * Default value: Gio::DataStreamByteOrder::BIG_ENDIAN
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< DataStreamByteOrder > property_byte_order() ;

/** The :byte-order property determines the byte ordering that
   * is used when reading multi-byte entities (such as integers)
   * from the stream.
   *
   * Default value: Gio::DataStreamByteOrder::BIG_ENDIAN
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< DataStreamByteOrder > property_byte_order() const;

  /** The :newline-type property determines what is considered
   * as a line ending when reading complete lines from the stream.
   *
   * Default value: Gio::DataStreamNewlineType::LF
   *
   * @return A PropertyProxy that allows you to get or set the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy< DataStreamNewlineType > property_newline_type() ;

/** The :newline-type property determines what is considered
   * as a line ending when reading complete lines from the stream.
   *
   * Default value: Gio::DataStreamNewlineType::LF
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< DataStreamNewlineType > property_newline_type() const;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gio


namespace Glib
{
  /** A Glib::wrap() method for this object.
   *
   * @param object The C instance.
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   *
   * @relates Gio::DataInputStream
   */
  GIOMM_API
  Glib::RefPtr<Gio::DataInputStream> wrap(GDataInputStream* object, bool take_copy = false);
}


#endif /* _GIOMM_DATAINPUTSTREAM_H */

