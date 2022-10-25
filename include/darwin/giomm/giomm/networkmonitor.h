// Generated by gmmproc 2.74.0 -- DO NOT MODIFY!
#ifndef _GIOMM_NETWORKMONITOR_H
#define _GIOMM_NETWORKMONITOR_H


#include <glibmm/ustring.h>
#include <sigc++/sigc++.h>

/* Copyright (C) 2014 The giomm Development Team
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

#include <glibmm/interface.h>
#include <giomm/asyncresult.h>
#include <giomm/cancellable.h>
#include <giomm/socketconnectable.h>
#include <gio/gio.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GNetworkMonitorInterface GNetworkMonitorInterface;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GNetworkMonitor = struct _GNetworkMonitor;
using GNetworkMonitorClass = struct _GNetworkMonitorClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gio
{ class GIOMM_API NetworkMonitor_Class; } // namespace Gio
#endif // DOXYGEN_SHOULD_SKIP_THIS

namespace Gio
{

/** @addtogroup giommEnums giomm Enums and Flags */

/** 
 *  @var NetworkConnectivity LOCAL
 * The host is not configured with a
 * route to the Internet; it may or may not be connected to a local
 * network.
 * 
 *  @var NetworkConnectivity LIMITED
 * The host is connected to a network, but
 * does not appear to be able to reach the full Internet, perhaps
 * due to upstream network problems.
 * 
 *  @var NetworkConnectivity PORTAL
 * The host is behind a captive portal and
 * cannot reach the full Internet.
 * 
 *  @var NetworkConnectivity FULL
 * The host is connected to a network, and
 * appears to be able to reach the full Internet.
 * 
 *  @enum NetworkConnectivity
 * 
 * The host's network connectivity state, as reported by NetworkMonitor.
 * 
 * @newin{2,44}
 *
 * @ingroup giommEnums
 */
enum class NetworkConnectivity
{
  LOCAL = 1,
  LIMITED,
  PORTAL,
  FULL
};


} // namespace Gio

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class GIOMM_API Value<Gio::NetworkConnectivity> : public Glib::Value_Enum<Gio::NetworkConnectivity>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

namespace Gio
{


/** Network status monitor.
 *
 * %NetworkMonitor provides an easy-to-use cross-platform API
 * for monitoring network connectivity. On Linux, the available
 * implementations are based on the kernel's netlink interface and
 * on NetworkManager.
 *
 * There is also an implementation for use inside Flatpak sandboxes.

 * @newin{2,44}
 */

class GIOMM_API NetworkMonitor : public Glib::Interface
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  using CppObjectType = NetworkMonitor;
  using CppClassType = NetworkMonitor_Class;
  using BaseObjectType = GNetworkMonitor;
  using BaseClassType = GNetworkMonitorInterface;

  // noncopyable
  NetworkMonitor(const NetworkMonitor&) = delete;
  NetworkMonitor& operator=(const NetworkMonitor&) = delete;

private:
  friend class NetworkMonitor_Class;
  static CppClassType networkmonitor_class_;

#endif /* DOXYGEN_SHOULD_SKIP_THIS */
protected:
  /**
   * You should derive from this class to use it.
   */
  NetworkMonitor();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  /** Called by constructors of derived classes. Provide the result of
   * the Class init() function to ensure that it is properly
   * initialized.
   *
   * @param interface_class The Class object for the derived type.
   */
  explicit NetworkMonitor(const Glib::Interface_Class& interface_class);

public:
  // This is public so that C++ wrapper instances can be
  // created for C instances of unwrapped types.
  // For instance, if an unexpected C type implements the C interface.
  explicit NetworkMonitor(GNetworkMonitor* castitem);

protected:
#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:

  NetworkMonitor(NetworkMonitor&& src) noexcept;
  NetworkMonitor& operator=(NetworkMonitor&& src) noexcept;

  ~NetworkMonitor() noexcept override;

  static void add_interface(GType gtype_implementer);

  /** Get the GType for this class, for use with the underlying GObject type system.
   */
  static GType get_type()      G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GNetworkMonitor*       gobj()       { return reinterpret_cast<GNetworkMonitor*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GNetworkMonitor* gobj() const { return reinterpret_cast<GNetworkMonitor*>(gobject_); }

private:


public:
  
  /** Gets the default NetworkMonitor for the system.
   * 
   * @newin{2,44}
   * 
   * @return A NetworkMonitor, which will be
   * a dummy object if no network monitor is available.
   */
  static Glib::RefPtr<NetworkMonitor> get_default();

  
  /** Checks if the network is available. "Available" here means that the
   * system has a default route available for at least one of IPv4 or
   * IPv6. It does not necessarily imply that the public Internet is
   * reachable. See NetworkMonitor::property_network_available() for more details.
   * 
   * @newin{2,44}
   * 
   * @return Whether the network is available.
   */
  bool get_network_available() const;

  
  /** Checks if the network is metered.
   * See NetworkMonitor::property_network_metered() for more details.
   * 
   * @newin{2,46}
   * 
   * @return Whether the connection is metered.
   */
  bool get_network_metered() const;

  
  /** Gets a more detailed networking state than
   * g_network_monitor_get_network_available().
   * 
   * If NetworkMonitor::property_network_available() is <tt>false</tt>, then the
   * connectivity state will be Gio::NetworkConnectivity::LOCAL.
   * 
   * If NetworkMonitor::property_network_available() is <tt>true</tt>, then the
   * connectivity state will be Gio::NetworkConnectivity::FULL (if there
   * is full Internet connectivity), Gio::NetworkConnectivity::LIMITED (if
   * the host has a default route, but appears to be unable to actually
   * reach the full Internet), or Gio::NetworkConnectivity::PORTAL (if the
   * host is trapped behind a "captive portal" that requires some sort
   * of login or acknowledgement before allowing full Internet access).
   * 
   * Note that in the case of Gio::NetworkConnectivity::LIMITED and
   * Gio::NetworkConnectivity::PORTAL, it is possible that some sites are
   * reachable but others are not. In this case, applications can
   * attempt to connect to remote servers, but should gracefully fall
   * back to their "offline" behavior if the connection attempt fails.
   * 
   * @newin{2,44}
   * 
   * @return The network connectivity state.
   */
  NetworkConnectivity get_connectivity() const;

  
  /** Attempts to determine whether or not the host pointed to by
   *  @a connectable can be reached, without actually trying to connect to
   * it.
   * 
   * This may return <tt>true</tt> even when NetworkMonitor::property_network_available()
   * is <tt>false</tt>, if, for example, @a monitor can determine that
   *  @a connectable refers to a host on a local network.
   * 
   * If @a monitor believes that an attempt to connect to @a connectable
   * will succeed, it will return <tt>true</tt>. Otherwise, it will return
   * <tt>false</tt> and set @a error to an appropriate error (such as
   * Gio::Error::HOST_UNREACHABLE).
   * 
   * Note that although this does not attempt to connect to
   *  @a connectable, it may still block for a brief period of time (eg,
   * trying to do multicast DNS on the local network), so if you do not
   * want to block, you should use g_network_monitor_can_reach_async().
   * 
   * @newin{2,44}
   * 
   * @param connectable A SocketConnectable.
   * @param cancellable A Cancellable, or <tt>nullptr</tt>.
   * @return <tt>true</tt> if @a connectable is reachable, <tt>false</tt> if not.
   * 
   * @throws Glib::Error
   */
  bool can_reach(const Glib::RefPtr<SocketConnectable>& connectable, const Glib::RefPtr<Cancellable>& cancellable);

  /// A can_reach() convenience overload.
  bool can_reach(const Glib::RefPtr<SocketConnectable>& connectable);

  //TODO:
  void can_reach_async(const Glib::RefPtr<SocketConnectable>& connectable, const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable);
  

  /** Finishes an async network connectivity test.
   * See g_network_monitor_can_reach_async().
   * 
   * @newin{2,44}
   * 
   * @param result A AsyncResult.
   * @return <tt>true</tt> if network is reachable, <tt>false</tt> if not.
   * 
   * @throws Glib::Error
   */
  bool can_reach_finish(const Glib::RefPtr<AsyncResult>& result);

  
  /**
   * @par Slot Prototype:
   * <tt>void on_my_%network_changed(bool available)</tt>
   *
   * Flags: Run Last
   *
   * Emitted when the network configuration changes.
   * 
   * @newin{2,44}
   * 
   * @param available The current value of NetworkMonitor::property_network_available().
   */

  Glib::SignalProxy<void(bool)> signal_network_changed();


  //TODO: Wrap vfuncs?

  /** Whether the network is considered available. That is, whether the
   * system has a default route for at least one of IPv4 or IPv6.
   * 
   * Real-world networks are of course much more complicated than
   * this; the machine may be connected to a wifi hotspot that
   * requires payment before allowing traffic through, or may be
   * connected to a functioning router that has lost its own upstream
   * connectivity. Some hosts might only be accessible when a VPN is
   * active. Other hosts might only be accessible when the VPN is
   * not active. Thus, it is best to use g_network_monitor_can_reach()
   * or g_network_monitor_can_reach_async() to test for reachability
   * on a host-by-host basis. (On the other hand, when the property is
   * <tt>false</tt>, the application can reasonably expect that no remote
   * hosts at all are reachable, and should indicate this to the user
   * in its UI.)
   * 
   * See also NetworkMonitor::signal_network_changed().
   * 
   * @newin{2,44}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_network_available() const;


  /** More detailed information about the host's network connectivity.
   * See g_network_monitor_get_connectivity() and
   * NetworkConnectivity for more details.
   * 
   * @newin{2,44}
   *
   * Default value: Gio::NetworkConnectivity::FULL
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< NetworkConnectivity > property_connectivity() const;


  /** Whether the network is considered metered. That is, whether the
   * system has traffic flowing through the default connection that is
   * subject to limitations set by service providers. For example, traffic
   * might be billed by the amount of data transmitted, or there might be a
   * quota on the amount of traffic per month. This is typical with tethered
   * connections (3G and 4G) and in such situations, bandwidth intensive
   * applications may wish to avoid network activity where possible if it will
   * cost the user money or use up their limited quota.
   * 
   * If more information is required about specific devices then the
   * system network management API should be used instead (for example,
   * NetworkManager or ConnMan).
   * 
   * If this information is not available then no networks will be
   * marked as metered.
   * 
   * See also NetworkMonitor::property_network_available().
   * 
   * @newin{2,46}
   *
   * Default value: <tt>false</tt>
   *
   * @return A PropertyProxy_ReadOnly that allows you to get the value of the property,
   * or receive notification when the value of the property changes.
   */
  Glib::PropertyProxy_ReadOnly< bool > property_network_metered() const;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::
  /// This is a default handler for the signal signal_network_changed().
  virtual void on_network_changed(bool available);


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
   * @relates Gio::NetworkMonitor
   */
  GIOMM_API
  Glib::RefPtr<Gio::NetworkMonitor> wrap(GNetworkMonitor* object, bool take_copy = false);

} // namespace Glib


#endif /* _GIOMM_NETWORKMONITOR_H */

