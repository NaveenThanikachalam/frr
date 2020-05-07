/*
 * Copyright (C) 2020  Cumulus Networks, Inc.
 * Chirag Shah
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; see the file COPYING; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <zebra.h>
#include "northbound.h"
#include "libfrr.h"
#include "zebra_nb.h"

/* clang-format off */
const struct frr_yang_module_info frr_zebra_info = {
	.name = "frr-zebra",
	.nodes = {
		{
			.xpath = "/frr-zebra:zebra/mcast-rpf-lookup",
			.cbs = {
				.modify = zebra_mcast_rpf_lookup_modify,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/ip-forwarding",
			.cbs = {
				.modify = zebra_ip_forwarding_modify,
				.destroy = zebra_ip_forwarding_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/ipv6-forwarding",
			.cbs = {
				.modify = zebra_ipv6_forwarding_modify,
				.destroy = zebra_ipv6_forwarding_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/workqueue-hold-timer",
			.cbs = {
				.modify = zebra_workqueue_hold_timer_modify,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/zapi-packets",
			.cbs = {
				.modify = zebra_zapi_packets_modify,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/import-kernel-table/table-id",
			.cbs = {
				.modify = zebra_import_kernel_table_table_id_modify,
				.destroy = zebra_import_kernel_table_table_id_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/import-kernel-table/distance",
			.cbs = {
				.modify = zebra_import_kernel_table_distance_modify,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/import-kernel-table/route-map",
			.cbs = {
				.modify = zebra_import_kernel_table_route_map_modify,
				.destroy = zebra_import_kernel_table_route_map_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/allow-external-route-update",
			.cbs = {
				.create = zebra_allow_external_route_update_create,
				.destroy = zebra_allow_external_route_update_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/dplane-queue-limit",
			.cbs = {
				.modify = zebra_dplane_queue_limit_modify,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/vrf-vni-mapping",
			.cbs = {
				.create = zebra_vrf_vni_mapping_create,
				.destroy = zebra_vrf_vni_mapping_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/vrf-vni-mapping/vni-id",
			.cbs = {
				.modify = zebra_vrf_vni_mapping_vni_id_modify,
				.destroy = zebra_vrf_vni_mapping_vni_id_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/vrf-vni-mapping/prefix-only",
			.cbs = {
				.create = zebra_vrf_vni_mapping_prefix_only_create,
				.destroy = zebra_vrf_vni_mapping_prefix_only_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/debugs/debug-events",
			.cbs = {
				.modify = zebra_debugs_debug_events_modify,
				.destroy = zebra_debugs_debug_events_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/debugs/debug-zapi-send",
			.cbs = {
				.modify = zebra_debugs_debug_zapi_send_modify,
				.destroy = zebra_debugs_debug_zapi_send_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/debugs/debug-zapi-recv",
			.cbs = {
				.modify = zebra_debugs_debug_zapi_recv_modify,
				.destroy = zebra_debugs_debug_zapi_recv_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/debugs/debug-zapi-detail",
			.cbs = {
				.modify = zebra_debugs_debug_zapi_detail_modify,
				.destroy = zebra_debugs_debug_zapi_detail_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/debugs/debug-kernel",
			.cbs = {
				.modify = zebra_debugs_debug_kernel_modify,
				.destroy = zebra_debugs_debug_kernel_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/debugs/debug-kernel-msg-send",
			.cbs = {
				.modify = zebra_debugs_debug_kernel_msg_send_modify,
				.destroy = zebra_debugs_debug_kernel_msg_send_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/debugs/debug-kernel-msg-recv",
			.cbs = {
				.modify = zebra_debugs_debug_kernel_msg_recv_modify,
				.destroy = zebra_debugs_debug_kernel_msg_recv_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/debugs/debug-rib",
			.cbs = {
				.modify = zebra_debugs_debug_rib_modify,
				.destroy = zebra_debugs_debug_rib_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/debugs/debug-rib-detail",
			.cbs = {
				.modify = zebra_debugs_debug_rib_detail_modify,
				.destroy = zebra_debugs_debug_rib_detail_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/debugs/debug-fpm",
			.cbs = {
				.modify = zebra_debugs_debug_fpm_modify,
				.destroy = zebra_debugs_debug_fpm_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/debugs/debug-nht",
			.cbs = {
				.modify = zebra_debugs_debug_nht_modify,
				.destroy = zebra_debugs_debug_nht_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/debugs/debug-nht-detail",
			.cbs = {
				.modify = zebra_debugs_debug_nht_detail_modify,
				.destroy = zebra_debugs_debug_nht_detail_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/debugs/debug-mpls",
			.cbs = {
				.modify = zebra_debugs_debug_mpls_modify,
				.destroy = zebra_debugs_debug_mpls_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/debugs/debug-vxlan",
			.cbs = {
				.modify = zebra_debugs_debug_vxlan_modify,
				.destroy = zebra_debugs_debug_vxlan_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/debugs/debug-pw",
			.cbs = {
				.modify = zebra_debugs_debug_pw_modify,
				.destroy = zebra_debugs_debug_pw_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/debugs/debug-dplane",
			.cbs = {
				.modify = zebra_debugs_debug_dplane_modify,
				.destroy = zebra_debugs_debug_dplane_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/debugs/debug-dplane-detail",
			.cbs = {
				.modify = zebra_debugs_debug_dplane_detail_modify,
				.destroy = zebra_debugs_debug_dplane_detail_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:zebra/debugs/debug-mlag",
			.cbs = {
				.modify = zebra_debugs_debug_mlag_modify,
				.destroy = zebra_debugs_debug_mlag_destroy,
			}
		},
		{
			.xpath = "/frr-zebra:get-route-information",
			.cbs = {
				.rpc = get_route_information_rpc,
			}
		},
		{
			.xpath = "/frr-zebra:get-v6-mroute-info",
			.cbs = {
				.rpc = get_v6_mroute_info_rpc,
			}
		},
		{
			.xpath = "/frr-zebra:get-vrf-info",
			.cbs = {
				.rpc = get_vrf_info_rpc,
			}
		},
		{
			.xpath = "/frr-zebra:get-vrf-vni-info",
			.cbs = {
				.rpc = get_vrf_vni_info_rpc,
			}
		},
		{
			.xpath = "/frr-zebra:get-evpn-info",
			.cbs = {
				.rpc = get_evpn_info_rpc,
			}
		},
		{
			.xpath = "/frr-zebra:get-vni-info",
			.cbs = {
				.rpc = get_vni_info_rpc,
			}
		},
		{
			.xpath = "/frr-zebra:get-evpn-vni-rmac",
			.cbs = {
				.rpc = get_evpn_vni_rmac_rpc,
			}
		},
		{
			.xpath = "/frr-zebra:get-evpn-vni-nexthops",
			.cbs = {
				.rpc = get_evpn_vni_nexthops_rpc,
			}
		},
		{
			.xpath = "/frr-zebra:clear-evpn-dup-addr",
			.cbs = {
				.rpc = clear_evpn_dup_addr_rpc,
			}
		},
		{
			.xpath = "/frr-zebra:get-evpn-macs",
			.cbs = {
				.rpc = get_evpn_macs_rpc,
			}
		},
		{
			.xpath = "/frr-zebra:get-evpn-arp-cache",
			.cbs = {
				.rpc = get_evpn_arp_cache_rpc,
			}
		},
		{
			.xpath = "/frr-zebra:get-pbr-ipset",
			.cbs = {
				.rpc = get_pbr_ipset_rpc,
			}
		},
		{
			.xpath = "/frr-zebra:get-pbr-iptable",
			.cbs = {
				.rpc = get_pbr_iptable_rpc,
			}
		},
		{
			.xpath = "/frr-zebra:get-debugs",
			.cbs = {
				.rpc = get_debugs_rpc,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-zebra:zebra/ip-addrs",
			.cbs = {
				.create = lib_interface_zebra_ip_addrs_create,
				.destroy = lib_interface_zebra_ip_addrs_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-zebra:zebra/ip-addrs/label",
			.cbs = {
				.modify = lib_interface_zebra_ip_addrs_label_modify,
				.destroy = lib_interface_zebra_ip_addrs_label_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-zebra:zebra/ip-addrs/ip4-peer",
			.cbs = {
				.modify = lib_interface_zebra_ip_addrs_ip4_peer_modify,
				.destroy = lib_interface_zebra_ip_addrs_ip4_peer_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-zebra:zebra/multicast",
			.cbs = {
				.modify = lib_interface_zebra_multicast_modify,
				.destroy = lib_interface_zebra_multicast_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-zebra:zebra/link-detect",
			.cbs = {
				.modify = lib_interface_zebra_link_detect_modify,
				.destroy = lib_interface_zebra_link_detect_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-zebra:zebra/shutdown",
			.cbs = {
				.modify = lib_interface_zebra_shutdown_modify,
				.destroy = lib_interface_zebra_shutdown_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-zebra:zebra/bandwidth",
			.cbs = {
				.modify = lib_interface_zebra_bandwidth_modify,
				.destroy = lib_interface_zebra_bandwidth_destroy,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-zebra:zebra/state/up-count",
			.cbs = {
				.get_elem = lib_interface_zebra_state_up_count_get_elem,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-zebra:zebra/state/down-count",
			.cbs = {
				.get_elem = lib_interface_zebra_state_down_count_get_elem,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-zebra:zebra/state/zif-type",
			.cbs = {
				.get_elem = lib_interface_zebra_state_zif_type_get_elem,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-zebra:zebra/state/ptm-status",
			.cbs = {
				.get_elem = lib_interface_zebra_state_ptm_status_get_elem,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-zebra:zebra/state/vlan-id",
			.cbs = {
				.get_elem = lib_interface_zebra_state_vlan_id_get_elem,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-zebra:zebra/state/vni-id",
			.cbs = {
				.get_elem = lib_interface_zebra_state_vni_id_get_elem,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-zebra:zebra/state/remote-vtep",
			.cbs = {
				.get_elem = lib_interface_zebra_state_remote_vtep_get_elem,
			}
		},
		{
			.xpath = "/frr-interface:lib/interface/frr-zebra:zebra/state/mcast-group",
			.cbs = {
				.get_elem = lib_interface_zebra_state_mcast_group_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib",
			.cbs = {
				.create = lib_vrf_ribs_rib_create,
				.destroy = lib_vrf_ribs_rib_destroy,
				.get_next = lib_vrf_ribs_rib_get_next,
				.get_keys = lib_vrf_ribs_rib_get_keys,
				.lookup_entry = lib_vrf_ribs_rib_lookup_entry,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route",
			.cbs = {
				.get_next = lib_vrf_ribs_rib_route_get_next,
				.get_keys = lib_vrf_ribs_rib_route_get_keys,
				.lookup_entry = lib_vrf_ribs_rib_route_lookup_entry,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/prefix",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_prefix_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry",
			.cbs = {
				.get_next = lib_vrf_ribs_rib_route_route_entry_get_next,
				.get_keys = lib_vrf_ribs_rib_route_route_entry_get_keys,
				.lookup_entry = lib_vrf_ribs_rib_route_route_entry_lookup_entry,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/protocol",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_protocol_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/instance",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_instance_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/distance",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_distance_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/metric",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_metric_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/tag",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_tag_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/selected",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_selected_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/installed",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_installed_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/failed",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_failed_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/queued",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_queued_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/internal-flags",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_internal_flags_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/internal-status",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_internal_status_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/uptime",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_uptime_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/nexthop-group",
			.cbs = {
				.get_next = lib_vrf_ribs_rib_route_route_entry_nexthop_group_get_next,
				.get_keys = lib_vrf_ribs_rib_route_route_entry_nexthop_group_get_keys,
				.lookup_entry = lib_vrf_ribs_rib_route_route_entry_nexthop_group_lookup_entry,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/nexthop-group/name",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_nexthop_group_name_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/nexthop-group/frr-nexthops/nexthop",
			.cbs = {
				.get_next = lib_vrf_ribs_rib_route_route_entry_nexthop_group_frr_nexthops_nexthop_get_next,
				.get_keys = lib_vrf_ribs_rib_route_route_entry_nexthop_group_frr_nexthops_nexthop_get_keys,
				.lookup_entry = lib_vrf_ribs_rib_route_route_entry_nexthop_group_frr_nexthops_nexthop_lookup_entry,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/nexthop-group/frr-nexthops/nexthop/nh-type",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_nexthop_group_frr_nexthops_nexthop_nh_type_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/nexthop-group/frr-nexthops/nexthop/vrf",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_nexthop_group_frr_nexthops_nexthop_vrf_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/nexthop-group/frr-nexthops/nexthop/gateway",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_nexthop_group_frr_nexthops_nexthop_gateway_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/nexthop-group/frr-nexthops/nexthop/interface",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_nexthop_group_frr_nexthops_nexthop_interface_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/nexthop-group/frr-nexthops/nexthop/bh-type",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_nexthop_group_frr_nexthops_nexthop_bh_type_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/nexthop-group/frr-nexthops/nexthop/onlink",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_nexthop_group_frr_nexthops_nexthop_onlink_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/nexthop-group/frr-nexthops/nexthop/mpls-label-stack/entry",
			.cbs = {
				.get_next = lib_vrf_ribs_rib_route_route_entry_nexthop_group_frr_nexthops_nexthop_mpls_label_stack_entry_get_next,
				.get_keys = lib_vrf_ribs_rib_route_route_entry_nexthop_group_frr_nexthops_nexthop_mpls_label_stack_entry_get_keys,
				.lookup_entry = lib_vrf_ribs_rib_route_route_entry_nexthop_group_frr_nexthops_nexthop_mpls_label_stack_entry_lookup_entry,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/nexthop-group/frr-nexthops/nexthop/mpls-label-stack/entry/id",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_nexthop_group_frr_nexthops_nexthop_mpls_label_stack_entry_id_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/nexthop-group/frr-nexthops/nexthop/mpls-label-stack/entry/label",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_nexthop_group_frr_nexthops_nexthop_mpls_label_stack_entry_label_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/nexthop-group/frr-nexthops/nexthop/mpls-label-stack/entry/ttl",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_nexthop_group_frr_nexthops_nexthop_mpls_label_stack_entry_ttl_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/nexthop-group/frr-nexthops/nexthop/mpls-label-stack/entry/traffic-class",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_nexthop_group_frr_nexthops_nexthop_mpls_label_stack_entry_traffic_class_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/nexthop-group/frr-nexthops/nexthop/duplicate",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_nexthop_group_frr_nexthops_nexthop_duplicate_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/nexthop-group/frr-nexthops/nexthop/recursive",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_nexthop_group_frr_nexthops_nexthop_recursive_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/nexthop-group/frr-nexthops/nexthop/active",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_nexthop_group_frr_nexthops_nexthop_active_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/nexthop-group/frr-nexthops/nexthop/fib",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_nexthop_group_frr_nexthops_nexthop_fib_get_elem,
			}
		},
		{
			.xpath = "/frr-vrf:lib/vrf/frr-zebra:ribs/rib/route/route-entry/nexthop-group/frr-nexthops/nexthop/weight",
			.cbs = {
				.get_elem = lib_vrf_ribs_rib_route_route_entry_nexthop_group_frr_nexthops_nexthop_weight_get_elem,
			}
		},
		{
			.xpath = NULL,
		},
	}
};
