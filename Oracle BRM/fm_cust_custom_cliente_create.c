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
static	char	Sccs_id[] = "@(#)%Portal Version: fm_cust_custom_cliente_create.c:BillingVelocityInt:2:2006-Sep-05 04:27:08 %";
#endif

/*******************************************************************
 * Contains AC_OP_CUST_CUSTOM_CLIENTE_CREATE operation. 
 *******************************************************************/


#include <stdio.h> 
#include <string.h> 
 
#include "pcm.h"
#include "ops/inv.h"
#include "cm_fm.h"
#include "pin_errs.h"
#include "pinlog.h"
#include "custom_ops.h"
#include "custom_filds.h"

/*******************************************************************
 * Routines contained within.
 *******************************************************************/
EXPORT_OP void
op_cust_custom_cliente_create(
	cm_nap_connection_t	*connp,
	int32			opcode,
	int32			flags,
	pin_flist_t		*i_flistp,
	pin_flist_t		**o_flistpp,
	pin_errbuf_t		*ebufp);

static void
fm_cust_custom_cliente_create(
	pcm_context_t		*ctxp,
	int32			flags,
	pin_flist_t		*i_flistp,
	pin_flist_t		**ret_flistpp,
	pin_errbuf_t		*ebufp);

/*******************************************************************
 * Main routine for the AC_OP_CUST_CUSTOM_CLIENTE_CREATE operation.
 *******************************************************************/
void
op_cust_custom_cliente_create(
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
	if (opcode != AC_OP_CUST_CUSTOM_CLIENTE_CREATE) {
		pin_set_err(ebufp, PIN_ERRLOC_FM,
			PIN_ERRCLASS_SYSTEM_DETERMINATE,
			PIN_ERR_BAD_OPCODE, 0, 0, opcode);
		PIN_ERR_LOG_EBUF(PIN_ERR_LEVEL_ERROR,
			"op_cust_custom_cliente_create opcode error", ebufp);
		return;
	}

	/***********************************************************
	 * Debug: What we got.
	 ***********************************************************/
	PIN_ERR_LOG_FLIST(PIN_ERR_LEVEL_DEBUG,
		"op_cust_custom_cliente_create input flist", i_flistp);

	/***********************************************************
	 * Implementation
	 ***********************************************************/
	fm_cust_custom_cliente_create(ctxp, flags, i_flistp, &r_flistp, ebufp);

	/***********************************************************
	 * Results.
	 ***********************************************************/
	if (PIN_ERR_IS_ERR(ebufp)) {

		/***************************************************
		 * Log errors
		 ***************************************************/
		PIN_ERR_LOG_EBUF(PIN_ERR_LEVEL_ERROR,
			"op_cust_custom_cliente_create error", ebufp);

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
			"op_cust_custom_cliente_create return flist", r_flistp);

	}

	return;
}

/*******************************************************************
 * fm_cust_custom_cliente_create():
 *
 *******************************************************************/
static void
fm_cust_custom_cliente_create(
	pcm_context_t		*ctxp,
	int32			flags,
	pin_flist_t		*i_flistp,
	pin_flist_t		**ret_flistpp,
	pin_errbuf_t		*ebufp)
{
	
	if (PIN_ERR_IS_ERR(ebufp)) {
		return;
	}
	PIN_ERR_CLEAR_ERR(ebufp);

	/***********************************************************
	 * Variables
	 ***********************************************************/
	pin_flist_t		*r_flistp = NULL;
	pin_flist_t		*create_out_flistp = NULL;
	pin_flist_t 	*create_in_flistp = NULL;
	pin_flist_t     *search_in_flistp = NULL;
	pin_flist_t     *search_out_flistp = NULL;
	pin_flist_t 	*search_args_flistp = NULL;
	pin_flist_t     *search_result_flistp = NULL;
	pin_flist_t 	*search_args_array_flistp = NULL;
	pin_flist_t 	*results_flistp = NULL;
    pin_flist_t     *err_flistp = NULL;

	poid_t 		*search_pdp = NULL;
	poid_t 		*account_pdp = NULL;
    poid_t      *err_pdp = NULL;

	int 	database = 1;
	int 	search_flag = 0;

	char template_search[256] = "select x from /account where F1 = V1";
	char *client_name = NULL;

	/***********************************************************
	 * Prepare the return flist.
	 ***********************************************************/
	*ret_flistpp = (pin_flist_t *)NULL;

	client_name = PIN_FLIST_FLD_GET (i_flistp, PIN_FLD_NAME, 0, ebufp);

	search_in_flistp = PIN_FLIST_CREATE (ebufp);
	search_pdp = PIN_POID_CREATE (database, "/search", -1, ebufp);
	PIN_FLIST_FLD_PUT (search_in_flistp, PIN_FLD_POID, search_pdp, ebufp);
	PIN_FLIST_FLD_SET (search_in_flistp, PIN_FLD_FLAGS, &search_flag, ebufp);
	PIN_FLIST_FLD_SET (search_in_flistp, PIN_FLD_TEMPLATE, template_search, ebufp);

	search_args_flistp = PIN_FLIST_ELEM_ADD (search_in_flistp, PIN_FLD_ARGS, 1, ebufp);
	search_args_array_flistp = PIN_FLIST_ELEM_ADD (search_args_flistp, PIN_FLD_NAMEINFO, PIN_ELEMID_ANY, ebufp);
	PIN_FLIST_FLD_SET (search_args_array_flistp, PIN_FLD_FIRST_NAME, client_name, ebufp);

	search_result_flistp = PIN_FLIST_ELEM_ADD (search_in_flistp, PIN_FLD_RESULTS, 0, ebufp);
	PIN_FLIST_FLD_SET (search_result_flistp, PIN_FLD_POID, NULL, ebufp);

	PIN_ERR_LOG_FLIST(PIN_ERR_LEVEL_DEBUG, "fm_cust_custom_cliente_create: search flist in", search_in_flistp);
	PCM_OP(ctxp, PCM_OP_SEARCH, 0, search_in_flistp, &search_out_flistp, ebufp);
	PIN_ERR_LOG_FLIST(PIN_ERR_LEVEL_DEBUG, "fm_cust_custom_cliente_create: search flist out", search_out_flistp);

	if (search_out_flistp != NULL)
	{
		results_flistp = PIN_FLIST_ELEM_GET (search_out_flistp, PIN_FLD_RESULTS, PIN_ELEMID_ANY, 0, ebufp);

		if(results_flistp != NULL)
		{
			account_pdp = PIN_FLIST_FLD_GET (results_flistp, PIN_FLD_POID, 0, ebufp);

			if(account_pdp != NULL)
			{
				create_in_flistp = PIN_FLIST_COPY (i_flistp, ebufp);
				PIN_FLIST_FLD_SET (create_in_flistp, PIN_FLD_ACCOUNT_OBJ, account_pdp, ebufp);
				PIN_ERR_LOG_FLIST(PIN_ERR_LEVEL_DEBUG, "fm_cust_custom_cliente_create: create flist in", create_in_flistp);
				PCM_OP(ctxp, PCM_OP_CREATE_OBJ, 0, create_in_flistp, &create_out_flistp, ebufp);
				PIN_ERR_LOG_FLIST(PIN_ERR_LEVEL_DEBUG, "fm_cust_custom_cliente_create: create flist out", create_out_flistp);

                r_flistp = PIN_FLIST_COPY(create_out_flistp, ebufp);
			}
		}
	}else{

		err_flistp = PIN_FLIST_CREATE(ebufp);
		err_pdp = PIN_POID_CREATE(database, "/dummy", -1, ebufp);
		PIN_FLIST_FLD_PUT(err_flistp, PIN_FLD_POID, err_pdp, ebufp);
		PIN_FLIST_FLD_SET(err_flistp, PIN_FLD_STATUS_MSG, "Erro no cliente", ebufp);
		PIN_ERR_LOG_FLISTP(PIN_ERR_LEVEL_ERROR, "fm_cust_custom_cliente_create: search NULL", err_flistp);
        
		r_flistp = PIN_FLIST_COPY(err_flistp, ebufp);

	}

	r_flistp = PIN_FLIST_COPY(create_out_flistp, ebufp);
	//PIN_FLIST_FLD_SET(r_flistp, PIN_FLD_FIRST_NAME, (void *)name, ebufp);
        

	/***********************************************************
	 * Empty policy
	 ***********************************************************/

	/***********************************************************
	 * Error?
	 ***********************************************************/
	if (PIN_ERR_IS_ERR(ebufp)) {
		PIN_ERR_LOG_EBUF(PIN_ERR_LEVEL_ERROR, 
			"fm_cust_custom_cliente_create: error", ebufp);
	}else {
		*ret_flistpp = r_flistp;
	}

	PIN_FLIST_DESTROY_EX(&create_out_flistp, ebufp);
	PIN_FLIST_DESTROY_EX(&create_in_flistp, ebufp);
	PIN_FLIST_DESTROY_EX(&search_in_flistp, ebufp);
	PIN_FLIST_DESTROY_EX(&search_out_flistp, ebufp);

	return;
}


