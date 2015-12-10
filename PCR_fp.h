/*
 * Copyright 2015 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef __TPM2_PCR_FP_H
#define __TPM2_PCR_FP_H

TPM_RC PCRAllocate(
        TPML_PCR_SELECTION        *allocate,           //   IN: required allocation
        UINT32                    *maxPCR,             //   OUT: Maximum number of PCR
        UINT32                    *sizeNeeded,         //   OUT: required space
        UINT32                    *sizeAvailable       //   OUT: available space
        );
TPMI_YES_NO PCRCapGetAllocation(
        UINT32                   count,               // IN: count of return
        TPML_PCR_SELECTION      *pcrSelection         // OUT: PCR allocation list
);
void PCRComputeCurrentDigest(
        TPMI_ALG_HASH             hashAlg,            // IN: hash algorithm to compute digest
        TPML_PCR_SELECTION       *selection,          // IN/OUT: PCR selection (filtered on
        //     output)
        TPM2B_DIGEST             *digest              // OUT: digest
        );
TPMI_ALG_HASH PCRGetAuthPolicy(
        TPMI_DH_PCR          handle,            // IN: PCR handle
        TPM2B_DIGEST        *policy             // OUT: policy of PCR
                               );
TPMI_YES_NO PCRCapGetHandles(
        TPMI_DH_PCR       handle,             // IN: start handle
        UINT32            count,              // IN: count of returned handle
        TPML_HANDLE      *handleList          // OUT: list of handle
);
TPMI_YES_NO PCRCapGetProperties(
        TPM_PT_PCR                       property,             // IN: the starting PCR property
        UINT32                           count,                // IN: count of returned propertie
        TPML_TAGGED_PCR_PROPERTY        *select                // OUT: PCR select
);
void PCRGetAuthValue(
        TPMI_DH_PCR          handle,            // IN: PCR handle
        TPM2B_AUTH          *auth               // OUT: authValue of PCR
                     );
void PCRExtend(
        TPMI_DH_PCR          handle,              //   IN:    PCR handle to be extended
        TPMI_ALG_HASH        hash,                //   IN:    hash algorithm of PCR
        UINT32               size,                //   IN:    size of data to be extended
        BYTE                *data                 //   IN:    data to be extended
               );
BOOL PCRIsExtendAllowed(
        TPMI_DH_PCR          handle               // IN: PCR handle to be extended
                        );
BOOL PCRIsStateSaved(
        TPMI_DH_PCR         handle                // IN: PCR handle to be extended
                     );
void PCRSimStart(
        void
        );

#endif // __TPM2_PCR_FP_H
