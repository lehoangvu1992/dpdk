/*
 *   BSD LICENSE
 *
 *   Copyright (C) Cavium networks Ltd. 2017.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *     * Neither the name of Cavium networks nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __SSOVF_EVDEV_H__
#define __SSOVF_EVDEV_H__

#include <rte_config.h>
#include <rte_io.h>

#define EVENTDEV_NAME_OCTEONTX_PMD event_octeontx

#ifdef RTE_LIBRTE_PMD_OCTEONTX_SSOVF_DEBUG
#define ssovf_log_info(fmt, args...) \
	RTE_LOG(INFO, EVENTDEV, "[%s] %s() " fmt "\n", \
		RTE_STR(EVENTDEV_NAME_OCTEONTX_PMD), __func__, ## args)
#define ssovf_log_dbg(fmt, args...) \
	RTE_LOG(DEBUG, EVENTDEV, "[%s] %s() " fmt "\n", \
		RTE_STR(EVENTDEV_NAME_OCTEONTX_PMD), __func__, ## args)
#else
#define ssovf_log_info(fmt, args...)
#define ssovf_log_dbg(fmt, args...)
#endif

#define ssovf_func_trace ssovf_log_dbg
#define ssovf_log_err(fmt, args...) \
	RTE_LOG(ERR, EVENTDEV, "[%s] %s() " fmt "\n", \
		RTE_STR(EVENTDEV_NAME_OCTEONTX_PMD), __func__, ## args)

#define PCI_VENDOR_ID_CAVIUM              0x177D
#define PCI_DEVICE_ID_OCTEONTX_SSOGRP_VF  0xA04B

#define SSO_MAX_VHGRP                     (64)

/* SSO VF register offsets */
#define SSO_VHGRP_QCTL                    (0x010ULL)
#define SSO_VHGRP_INT                     (0x100ULL)
#define SSO_VHGRP_INT_W1S                 (0x108ULL)
#define SSO_VHGRP_INT_ENA_W1S             (0x110ULL)
#define SSO_VHGRP_INT_ENA_W1C             (0x118ULL)
#define SSO_VHGRP_INT_THR                 (0x140ULL)
#define SSO_VHGRP_INT_CNT                 (0x180ULL)
#define SSO_VHGRP_XAQ_CNT                 (0x1B0ULL)
#define SSO_VHGRP_AQ_CNT                  (0x1C0ULL)
#define SSO_VHGRP_AQ_THR                  (0x1E0ULL)
#define SSO_VHGRP_PF_MBOX(x)              (0x200ULL | ((x) << 3))

/* BAR2 */
#define SSO_VHGRP_OP_ADD_WORK0            (0x00ULL)
#define SSO_VHGRP_OP_ADD_WORK1            (0x08ULL)


#endif /* __SSOVF_EVDEV_H__ */