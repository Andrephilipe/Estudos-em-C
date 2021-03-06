/*******************************************************************
 *
 *      Copyright (c) 2006 Oracle. All rights reserved.
 *
 *      This material is the confidential property of Oracle Corporation
 *      or its licensors and may be used, reproduced, stored or transmitted
 *      only in accordance with a valid Oracle license or sublicense agreement.
 *
 *******************************************************************/

#ifndef lint
static	char	Sccs_id[] = "@(#)%Portal Version: fm_cust_custom_insert_obj.c:BillingVelocityInt:2:2006-Sep-05 04:27:08 %";
#endif

/*******************************************************************
 * Contains AC_OP_CUST_INSERT_OBJ operation. 
 *******************************************************************/


#include <stdio.h> 
#include <string.h> 
 
#include "pcm.h"
#include "ops/inv.h"
#include "cm_fm.h"
#include "pin_errs.h"
#include "pinlog.h"
#include "custom_ops.h"

/*******************************************************************
 * Routines contained within.
 *******************************************************************/
EXPORT_OP void
op_cust_custom_insert_obj(
	cm_nap_connection_t	*connp,
	int32			opcode,
	int32			flags,
	pin_flist_t		*i_flistp,
	pin_flist_t		**o_flistpp,
	pin_errbuf_t		*ebufp);

static void
fm_cust_custom_insert_obj(
	pcm_context_t		*ctxp,
	int32			flags,
	pin_flist_t		*i_flistp,
	pin_flist_t		**ret_flistpp,
	pin_errbuf_t		*ebufp);

/*******************************************************************
 * Main routine for the PCM_op_cust_custom_insert_obj operation.
 *******************************************************************/
void
op_cust_custom_insert_obj(
	cm_nap_connection_t	*connp,
	int32			opcode,
	int32			flags,
	pin_flist_t		*i_flistp,
	pin_flist_t		**o_flistpp,
	pin_errbuf_t		*ebufp)
{
	pcm_context_t		*ctxp = connp->dm_ctx;
	pin_flist_t		*r_flistp = NULL;


	if (PIN_ERR_IS_ERR(ebufp)) {
		return;
	}
	PIN_ERR_CLEAR_ERR(ebufp);

	/***********************************************************
	 * Invalid call
	 ***********************************************************/
	if (opcode != AC_OP_CUST_INSERT_OBJ) {
		pin_set_err(ebufp, PIN_ERRLOC_FM,
			PIN_ERRCLASS_SYSTEM_DETERMINATE,
			PIN_ERR_BAD_OPCODE, 0, 0, opcode);
		PIN_ERR_LOG_EBUF(PIN_ERR_LEVEL_ERROR,
			"op_cust_custom_insert_obj opcode error", ebufp);
		return;
	}

	/***********************************************************
	 * Debug: What we got.
	 ***********************************************************/
	PIN_ERR_LOG_FLIST(PIN_ERR_LEVEL_DEBUG,
		"op_cust_custom_insert_obj input flist", i_flistp);

	/***********************************************************
	 * Implementation
	 ***********************************************************/
	fm_cust_custom_insert_obj(ctxp, flags, i_flistp, &r_flistp, ebufp);

	/***********************************************************
	 * Results.
	 ***********************************************************/
	if (PIN_ERR_IS_ERR(ebufp)) {

		/***************************************************
		 * Log errors
		 ***************************************************/
		PIN_ERR_LOG_EBUF(PIN_ERR_LEVEL_ERROR,
			"op_cust_custom_insert_obj error", ebufp);

		PIN_FLIST_DESTROY_EX(&r_flistp, NULL);

		*o_flistpp = NULL;

	} else {

		/***************************************************
		 * Point the real return flist to the right thing.
		 ***************************************************/
		*o_flistpp = r_flistp;

		/***************************************************
		 * Return flist log
		 ***************************************************/
		PIN_ERR_LOG_FLIST(PIN_ERR_LEVEL_DEBUG,
			"op_cust_custom_insert_obj return flist", r_flistp);

	}

	return;
}

/*******************************************************************
 * fm_inv_pol_mycustomop():
 *
 *******************************************************************/
static void
fm_cust_custom_insert_obj(
	pcm_context_t		*ctxp,
	int32			flags,
	pin_flist_t		*i_flistp,
	pin_flist_t		**ret_flistpp,
	pin_errbuf_t		*ebufp)
{
	pin_flist_t		*r_flistp = NULL;

	if (PIN_ERR_IS_ERR(ebufp)) {
		return;
	}
	PIN_ERR_CLEAR_ERR(ebufp);

	/***********************************************************
	 * Variables.
	 ***********************************************************/
	pin_flist_t *out_flistp = NULL;
	/***********************************************************
	 * Prepare the return flist.
	 ***********************************************************/
	*ret_flistpp = (pin_flist_t *)NULL;

	PIN_ERR_LOG_FLIST(PIN_ERR_LEVEL_DEBUG, "fm_cust_custom_cliente_create: search flist in", i_flistp);
	PCM_OP(ctxp, PCM_OP_WRITE_FLDS, 0, i_flistp, &out_flistp, ebufp);
	PIN_ERR_LOG_FLIST(PIN_ERR_LEVEL_DEBUG, "fm_cust_custom_cliente_create: search flist out", out_flistp);

	r_flistp = PIN_FLIST_COPY(out_flistp, ebufp);
 

	/***********************************************************
	 * Empty policy
	 ***********************************************************/

	/***********************************************************
	 * Error?
	 ***********************************************************/
	if (PIN_ERR_IS_ERR(ebufp)) {
		PIN_ERR_LOG_EBUF(PIN_ERR_LEVEL_ERROR, 
			"fm_inv_pol_mycustomop: error", ebufp);
	}else {
		*ret_flistpp = r_flistp;
	}

	return;
}
