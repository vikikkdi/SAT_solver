/*============================================================================*/
/*                                                                            */
/*                                                                            */
/*                              reLOC 0.21-robik                              */
/*                                                                            */
/*                      (C) Copyright 2019 Pavel Surynek                      */
/*                http://www.surynek.com | <pavel@surynek.com>                */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
/* encodings_mdd.cpp / 0.21-robik_020                                         */
/*----------------------------------------------------------------------------*/
//
// Multi-robot path-finding encodings based on
// MDDs and calculating cost-optimal solutions.
//
/*----------------------------------------------------------------------------*/
#ifndef __ENCODINGS_MDD_CPP__
#define __ENCODINGS_MDD_CPP__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <limits.h>

#include <map>

#include "config.h"
#include "reLoc_compile.h"
#include "version.h"
#include "defs.h"
#include "types.h"
#include "result.h"
#include "cnf.h"
#include "multirobot.h"
#include "compress.h"
#include "statistics.h"


using namespace sReloc;


/*----------------------------------------------------------------------------*/

namespace sReloc
{


/*----------------------------------------------------------------------------*/
// sMultirobotInstance encodings

    void sMultirobotInstance::to_Screen_MddCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_MddCNFsat(stdout, encoding_context, indent, verbose);
    }


    void sMultirobotInstance::to_Screen_MddUmtexCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_MddUmtexCNFsat(stdout, encoding_context, indent, verbose);
    }


    void sMultirobotInstance::to_Screen_MddMutexCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_MddMutexCNFsat(stdout, encoding_context, indent, verbose);
    }    


    void sMultirobotInstance::to_Screen_GMddCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_GMddCNFsat(stdout, encoding_context, indent, verbose);
    }


    void sMultirobotInstance::to_Screen_GEMddCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_GEMddCNFsat(stdout, encoding_context, indent, verbose);
    }        


    void sMultirobotInstance::to_Screen_MddCNFsat_avoid(sMultirobotEncodingContext_CNFsat &encoding_context, const Arrangements_vector &unfolded_solution, const sString &indent, bool verbose)
    {
	to_Stream_MddCNFsat_avoid(stdout, encoding_context, unfolded_solution, indent, verbose);
    }


    void sMultirobotInstance::to_Screen_RelaxedMddCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_RelaxedMddCNFsat(stdout, encoding_context, indent, verbose);
    }


    void sMultirobotInstance::to_Screen_TokenMddCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_TokenMddCNFsat(stdout, encoding_context, indent, verbose);
    }


    void sMultirobotInstance::to_Screen_TokenEmptyMddCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_TokenEmptyMddCNFsat(stdout, encoding_context, indent, verbose);
    }    


    void sMultirobotInstance::to_Screen_PermutationMddCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_PermutationMddCNFsat(stdout, encoding_context, indent, verbose);
    }


    void sMultirobotInstance::to_Screen_CapacitatedPermutationMddCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_CapacitatedPermutationMddCNFsat(stdout, encoding_context, indent, verbose);
    }            

    
    void sMultirobotInstance::to_Screen_MddPlusCNFsat_avoid(sMultirobotEncodingContext_CNFsat &encoding_context, const Arrangements_vector &unfolded_solution, const sString &indent, bool verbose)
    {
	to_Stream_MddPlusCNFsat_avoid(stdout, encoding_context, unfolded_solution, indent, verbose);
    }    


    void sMultirobotInstance::to_Screen_MddPlusPlusCNFsat_avoid(sMultirobotEncodingContext_CNFsat &encoding_context, const Arrangements_vector &unfolded_solution, const sString &indent, bool verbose)
    {
	to_Stream_MddPlusPlusCNFsat_avoid(stdout, encoding_context, unfolded_solution, indent, verbose);
    }

    
    void sMultirobotInstance::to_Screen_MmddCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_MmddCNFsat(stdout, encoding_context, indent, verbose);
    }

    
    void sMultirobotInstance::to_Screen_MmddCNFsat_avoid(sMultirobotEncodingContext_CNFsat &encoding_context, const Arrangements_vector &unfolded_solution, const sString &indent, bool verbose)
    {
	to_Stream_MmddCNFsat_avoid(stdout, encoding_context, unfolded_solution, indent, verbose);
    }


    void sMultirobotInstance::to_Screen_RelaxedMmddCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_RelaxedMmddCNFsat(stdout, encoding_context, indent, verbose);
    }


    void sMultirobotInstance::to_Screen_TokenMmddCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_TokenMmddCNFsat(stdout, encoding_context, indent, verbose);
    }


    void sMultirobotInstance::to_Screen_TokenEmptyMmddCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_TokenEmptyMmddCNFsat(stdout, encoding_context, indent, verbose);
    }        


    void sMultirobotInstance::to_Screen_PermutationMmddCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_PermutationMmddCNFsat(stdout, encoding_context, indent, verbose);
    }


    void sMultirobotInstance::to_Screen_CapacitatedPermutationMmddCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_CapacitatedPermutationMmddCNFsat(stdout, encoding_context, indent, verbose);
    }        

    
    void sMultirobotInstance::to_Screen_MmddPlusCNFsat_avoid(sMultirobotEncodingContext_CNFsat &encoding_context, const Arrangements_vector &unfolded_solution, const sString &indent, bool verbose)
    {
	to_Stream_MmddPlusCNFsat_avoid(stdout, encoding_context, unfolded_solution, indent, verbose);
    }    


    void sMultirobotInstance::to_Screen_MmddPlusPlusCNFsat_avoid(sMultirobotEncodingContext_CNFsat &encoding_context, const Arrangements_vector &unfolded_solution, const sString &indent, bool verbose)
    {
	to_Stream_MmddPlusPlusCNFsat_avoid(stdout, encoding_context, unfolded_solution, indent, verbose);
    }        


    void sMultirobotInstance::to_Screen_RXMddCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_RXMddCNFsat(stdout, encoding_context, indent, verbose);
    }


    void sMultirobotInstance::to_Screen_NoMddCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_NoMddCNFsat(stdout, encoding_context, indent, verbose);
    }


    void sMultirobotInstance::to_Screen_RXNoMddCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_RXNoMddCNFsat(stdout, encoding_context, indent, verbose);
    }

    
    void sMultirobotInstance::to_Screen_MddPlusCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_MddPlusCNFsat(stdout, encoding_context, indent, verbose);
    }


    void sMultirobotInstance::to_Screen_MmddPlusCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_MmddPlusCNFsat(stdout, encoding_context, indent, verbose);
    }


    void sMultirobotInstance::to_Screen_MddPlusPlusCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_MddPlusPlusCNFsat(stdout, encoding_context, indent, verbose);
    }


    void sMultirobotInstance::to_Screen_MddPlusPlusMutexCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_MddPlusPlusMutexCNFsat(stdout, encoding_context, indent, verbose);
    }    


    void sMultirobotInstance::to_Screen_MddPlusPlusFuelCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_MddPlusPlusFuelCNFsat(stdout, encoding_context, indent, verbose);
    }    


    void sMultirobotInstance::to_Screen_LMddPlusPlusCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_LMddPlusPlusCNFsat(stdout, encoding_context, indent, verbose);
    }
    

    void sMultirobotInstance::to_Screen_MmddPlusPlusCNFsat(sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	to_Stream_MmddPlusPlusCNFsat(stdout, encoding_context, indent, verbose);
    }    
    

/*----------------------------------------------------------------------------*/
    
    sResult sMultirobotInstance::to_File_MddCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_MddCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }


    sResult sMultirobotInstance::to_File_MddUmtexCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_MddUmtexCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }


    sResult sMultirobotInstance::to_File_MddMutexCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_MddMutexCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }    


    sResult sMultirobotInstance::to_File_GMddCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_GMddCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }

    
    sResult sMultirobotInstance::to_File_GEMddCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_GEMddCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }        


    sResult sMultirobotInstance::to_File_RelaxedMddCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_RelaxedMddCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }


    sResult sMultirobotInstance::to_File_TokenMddCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_TokenMddCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }


    sResult sMultirobotInstance::to_File_TokenEmptyMddCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_TokenEmptyMddCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }    


    sResult sMultirobotInstance::to_File_PermutationMddCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_PermutationMddCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }


    sResult sMultirobotInstance::to_File_CapacitatedPermutationMddCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_CapacitatedPermutationMddCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }                

    
    sResult sMultirobotInstance::to_File_MddCNFsat_avoid(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const Arrangements_vector &unfolded_solution, const sString &indent, bool verbose)
    {
	sResult result;
	
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	if (sFAILED(result = to_Stream_MddCNFsat_avoid(fw, encoding_context, unfolded_solution, indent, verbose)))
	{
	    fclose(fw);
	    return result;
	}
	fclose(fw);
	
	if (result == sMULTIROBOT_SOLUTION_COMPRESSOR_MDD_DISCO_INFO)
	{
	    if (unlink(filename.c_str()) < 0)
	    {
		return sMULTIROBOT_SOLUTION_COMPRESSOR_UNLINK_ERROR;
	    }	    
	    return result;
	}
	return sRESULT_SUCCESS;
    }

    
    sResult sMultirobotInstance::to_File_MddPlusCNFsat_avoid(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const Arrangements_vector &unfolded_solution, const sString &indent, bool verbose)
    {
	sResult result;
	
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	if (sFAILED(result = to_Stream_MddPlusCNFsat_avoid(fw, encoding_context, unfolded_solution, indent, verbose)))
	{
	    fclose(fw);
	    return result;
	}
	fclose(fw);
	
	if (result == sMULTIROBOT_SOLUTION_COMPRESSOR_MDD_DISCO_INFO)
	{
	    if (unlink(filename.c_str()) < 0)
	    {
		return sMULTIROBOT_SOLUTION_COMPRESSOR_UNLINK_ERROR;
	    }	    
	    return result;
	}
	return sRESULT_SUCCESS;
    }


    sResult sMultirobotInstance::to_File_MddPlusPlusCNFsat_avoid(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const Arrangements_vector &unfolded_solution, const sString &indent, bool verbose)
    {
	sResult result;
	
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	if (sFAILED(result = to_Stream_MddPlusPlusCNFsat_avoid(fw, encoding_context, unfolded_solution, indent, verbose)))
	{
	    fclose(fw);
	    return result;
	}
	fclose(fw);
	
	if (result == sMULTIROBOT_SOLUTION_COMPRESSOR_MDD_DISCO_INFO)
	{
	    if (unlink(filename.c_str()) < 0)
	    {
		return sMULTIROBOT_SOLUTION_COMPRESSOR_UNLINK_ERROR;
	    }	    
	    return result;
	}
	return sRESULT_SUCCESS;
    }


    sResult sMultirobotInstance::to_File_MmddCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_MmddCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }


    sResult sMultirobotInstance::to_File_RelaxedMmddCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_RelaxedMmddCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }


    sResult sMultirobotInstance::to_File_TokenMmddCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_TokenMmddCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }


    sResult sMultirobotInstance::to_File_TokenEmptyMmddCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_TokenEmptyMmddCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }            


    sResult sMultirobotInstance::to_File_PermutationMmddCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_PermutationMmddCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }


    sResult sMultirobotInstance::to_File_CapacitatedPermutationMmddCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_CapacitatedPermutationMmddCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }            
    

    sResult sMultirobotInstance::to_File_MmddCNFsat_avoid(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const Arrangements_vector &unfolded_solution, const sString &indent, bool verbose)
    {
	sResult result;
	
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	if (sFAILED(result = to_Stream_MmddCNFsat_avoid(fw, encoding_context, unfolded_solution, indent, verbose)))
	{
	    fclose(fw);
	    return result;
	}
	fclose(fw);
	
	if (result == sMULTIROBOT_SOLUTION_COMPRESSOR_MMDD_DISCO_INFO)
	{
	    if (unlink(filename.c_str()) < 0)
	    {
		return sMULTIROBOT_SOLUTION_COMPRESSOR_UNLINK_ERROR;
	    }
	    return result;
	}
	return sRESULT_SUCCESS;
    }


    sResult sMultirobotInstance::to_File_MmddPlusCNFsat_avoid(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const Arrangements_vector &unfolded_solution, const sString &indent, bool verbose)
    {
	sResult result;
	
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	if (sFAILED(result = to_Stream_MmddPlusCNFsat_avoid(fw, encoding_context, unfolded_solution, indent, verbose)))
	{
	    fclose(fw);
	    return result;
	}
	fclose(fw);
	
	if (result == sMULTIROBOT_SOLUTION_COMPRESSOR_MMDD_DISCO_INFO)
	{
	    if (unlink(filename.c_str()) < 0)
	    {
		return sMULTIROBOT_SOLUTION_COMPRESSOR_UNLINK_ERROR;
	    }	    
	    return result;
	}
	return sRESULT_SUCCESS;
    }


    sResult sMultirobotInstance::to_File_MmddPlusPlusCNFsat_avoid(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const Arrangements_vector &unfolded_solution, const sString &indent, bool verbose)
    {
	sResult result;
	
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	if (sFAILED(result = to_Stream_MmddPlusPlusCNFsat_avoid(fw, encoding_context, unfolded_solution, indent, verbose)))
	{
	    fclose(fw);
	    return result;
	}
	fclose(fw);
	
	if (result == sMULTIROBOT_SOLUTION_COMPRESSOR_MMDD_DISCO_INFO)
	{
	    if (unlink(filename.c_str()) < 0)
	    {
		return sMULTIROBOT_SOLUTION_COMPRESSOR_UNLINK_ERROR;
	    }	    
	    return result;
	}
	return sRESULT_SUCCESS;
    }        


    sResult sMultirobotInstance::to_File_RXMddCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_RXMddCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }


    sResult sMultirobotInstance::to_File_NoMddCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_NoMddCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }


    sResult sMultirobotInstance::to_File_RXNoMddCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_RXNoMddCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }


    sResult sMultirobotInstance::to_File_MddPlusCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_MddPlusCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }


    sResult sMultirobotInstance::to_File_MmddPlusCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_MmddPlusCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }    

    
    sResult sMultirobotInstance::to_File_MddPlusPlusCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_MddPlusPlusCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }


    sResult sMultirobotInstance::to_File_MddPlusPlusMutexCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_MddPlusPlusMutexCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }    


    sResult sMultirobotInstance::to_File_MddPlusPlusFuelCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_MddPlusPlusFuelCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }    


    sResult sMultirobotInstance::to_File_LMddPlusPlusCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_LMddPlusPlusCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }    
    

    sResult sMultirobotInstance::to_File_MmddPlusPlusCNFsat(const sString &filename, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	FILE *fw;
	if ((fw = fopen(filename.c_str(), "w")) == NULL)
	{
	    return sMULTIROBOT_CNF_OPEN_ERROR;
	}
	to_Stream_MmddPlusPlusCNFsat(fw, encoding_context, indent, verbose);
	fclose(fw);

	return sRESULT_SUCCESS;
    }    


/*----------------------------------------------------------------------------*/
    
    void sMultirobotInstance::to_Stream_MddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Stream_MddCNFsat(fw, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Stream_MddCNFsat(fw, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }


    void sMultirobotInstance::to_Stream_MddUmtexCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Stream_MddUmtexCNFsat(fw, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Stream_MddUmtexCNFsat(fw, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }


    void sMultirobotInstance::to_Stream_MddMutexCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Stream_MddMutexCNFsat(fw, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Stream_MddMutexCNFsat(fw, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }    


    void sMultirobotInstance::to_Stream_GMddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Stream_GMddCNFsat(fw, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Stream_GMddCNFsat(fw, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }


    void sMultirobotInstance::to_Stream_GEMddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);

	RobotMDD_vector unified_MDD;
	unify_MDD(m_the_MDD, unified_MDD);
	
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Stream_GEMddCNFsat(fw, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, unified_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Stream_GEMddCNFsat(fw, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, unified_MDD, indent, verbose);
	}
    }        


    void sMultirobotInstance::to_Memory_MddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Memory_MddCNFsat(solver, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Memory_MddCNFsat(solver, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }


    void sMultirobotInstance::to_Memory_MddUmtexCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Memory_MddUmtexCNFsat(solver, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Memory_MddUmtexCNFsat(solver, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }


    void sMultirobotInstance::to_Memory_MddMutexCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Memory_MddMutexCNFsat(solver, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Memory_MddMutexCNFsat(solver, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }    


    void sMultirobotInstance::to_Memory_GMddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Memory_GMddCNFsat(solver, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Memory_GMddCNFsat(solver, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }

    
    void sMultirobotInstance::to_Memory_GEMddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	RobotMDD_vector unified_MDD;
	unify_MDD(m_the_MDD, unified_MDD);		

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Memory_GEMddCNFsat(solver, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, unified_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Memory_GEMddCNFsat(solver, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, unified_MDD, indent, verbose);
	}
    }            


    void sMultirobotInstance::to_Stream_RelaxedMddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Stream_RelaxedMddCNFsat(fw, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Stream_RelaxedMddCNFsat(fw, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }


    void sMultirobotInstance::to_Stream_TokenMddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Stream_TokenMddCNFsat(fw, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Stream_TokenMddCNFsat(fw, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }


    void sMultirobotInstance::to_Stream_TokenEmptyMddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Stream_TokenEmptyMddCNFsat(fw, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Stream_TokenEmptyMddCNFsat(fw, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }        


    void sMultirobotInstance::to_Stream_PermutationMddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Stream_PermutationMddCNFsat(fw, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Stream_PermutationMddCNFsat(fw, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }


    void sMultirobotInstance::to_Stream_CapacitatedPermutationMddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Stream_CapacitatedPermutationMddCNFsat(fw, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Stream_CapacitatedPermutationMddCNFsat(fw, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }
        
    

    void sMultirobotInstance::to_Memory_RelaxedMddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Memory_RelaxedMddCNFsat(solver, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Memory_RelaxedMddCNFsat(solver, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }


    void sMultirobotInstance::to_Memory_TokenMddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Memory_TokenMddCNFsat(solver, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Memory_TokenMddCNFsat(solver, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }


    void sMultirobotInstance::to_Memory_TokenEmptyMddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Memory_TokenEmptyMddCNFsat(solver, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Memory_TokenEmptyMddCNFsat(solver, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }    


    void sMultirobotInstance::to_Memory_PermutationMddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Memory_PermutationMddCNFsat(solver, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Memory_PermutationMddCNFsat(solver, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }


    void sMultirobotInstance::to_Memory_CapacitatedPermutationMddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Memory_CapacitatedPermutationMddCNFsat(solver, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Memory_CapacitatedPermutationMddCNFsat(solver, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }                    


    sResult sMultirobotInstance::to_Stream_MddCNFsat_avoid(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const Arrangements_vector &unfolded_solution, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	reduce_MDD(unfolded_solution, m_the_MDD, m_the_reduced_MDD);
	reduce_MDD(unfolded_solution, m_the_extra_MDD, m_the_reduced_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (!check_Connectivity(m_the_reduced_MDD))
	{
	    return sMULTIROBOT_SOLUTION_COMPRESSOR_MDD_DISCO_INFO;
	}
	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Stream_MddCNFsat(fw, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_reduced_MDD, m_the_reduced_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Stream_MddCNFsat(fw, encoding_context, extra_cost, mdd_depth, m_the_reduced_MDD, m_the_reduced_extra_MDD, indent, verbose);
	}
	return sRESULT_SUCCESS;
    }


    sResult sMultirobotInstance::to_Memory_MddCNFsat_avoid(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const Arrangements_vector &unfolded_solution, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	reduce_MDD(unfolded_solution, m_the_MDD, m_the_reduced_MDD);
	reduce_MDD(unfolded_solution, m_the_extra_MDD, m_the_reduced_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (!check_Connectivity(m_the_reduced_MDD))
	{
	    return sMULTIROBOT_SOLUTION_COMPRESSOR_MDD_DISCO_INFO;
	}
	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Memory_MddCNFsat(solver, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_reduced_MDD, m_the_reduced_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Memory_MddCNFsat(solver, encoding_context, extra_cost, mdd_depth, m_the_reduced_MDD, m_the_reduced_extra_MDD, indent, verbose);
	}
	return sRESULT_SUCCESS;
    }    

  
    sResult sMultirobotInstance::to_Stream_MddPlusCNFsat_avoid(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const Arrangements_vector &unfolded_solution, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	reduce_MDD(unfolded_solution, m_the_MDD, m_the_reduced_MDD);
	reduce_MDD(unfolded_solution, m_the_extra_MDD, m_the_reduced_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (!check_Connectivity(m_the_reduced_MDD))
	{
	    return sMULTIROBOT_SOLUTION_COMPRESSOR_MDD_DISCO_INFO;
	}
	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Stream_MddPlusCNFsat(fw, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_reduced_MDD, m_the_reduced_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Stream_MddPlusCNFsat(fw, encoding_context, extra_cost, mdd_depth, m_the_reduced_MDD, m_the_reduced_extra_MDD, indent, verbose);
	}
	return sRESULT_SUCCESS;
    }


    sResult sMultirobotInstance::to_Memory_MddPlusCNFsat_avoid(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const Arrangements_vector &unfolded_solution, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	reduce_MDD(unfolded_solution, m_the_MDD, m_the_reduced_MDD);
	reduce_MDD(unfolded_solution, m_the_extra_MDD, m_the_reduced_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (!check_Connectivity(m_the_reduced_MDD))
	{
	    return sMULTIROBOT_SOLUTION_COMPRESSOR_MDD_DISCO_INFO;
	}
	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Memory_MddPlusCNFsat(solver, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_reduced_MDD, m_the_reduced_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Memory_MddPlusCNFsat(solver, encoding_context, extra_cost, mdd_depth, m_the_reduced_MDD, m_the_reduced_extra_MDD, indent, verbose);
	}
	return sRESULT_SUCCESS;
    }    


    sResult sMultirobotInstance::to_Stream_MddPlusPlusCNFsat_avoid(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const Arrangements_vector &unfolded_solution, const sString &indent, bool verbose)
    {
	int extra_cost;
	
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	reduce_MDD(unfolded_solution, m_the_MDD, m_the_reduced_MDD);
	reduce_MDD(unfolded_solution, m_the_extra_MDD, m_the_reduced_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (!check_Connectivity(m_the_reduced_MDD))
	{
	    return sMULTIROBOT_SOLUTION_COMPRESSOR_MDD_DISCO_INFO;
	}
	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Stream_MddPlusPlusCNFsat(fw, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_reduced_MDD, m_the_reduced_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Stream_MddPlusPlusCNFsat(fw, encoding_context, extra_cost, mdd_depth, m_the_reduced_MDD, m_the_reduced_extra_MDD, indent, verbose);
	}
	return sRESULT_SUCCESS;
    }


    sResult sMultirobotInstance::to_Memory_MddPlusPlusCNFsat_avoid(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const Arrangements_vector &unfolded_solution, const sString &indent, bool verbose)
    {
	int extra_cost;
	
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	reduce_MDD(unfolded_solution, m_the_MDD, m_the_reduced_MDD);
	reduce_MDD(unfolded_solution, m_the_extra_MDD, m_the_reduced_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (!check_Connectivity(m_the_reduced_MDD))
	{
	    return sMULTIROBOT_SOLUTION_COMPRESSOR_MDD_DISCO_INFO;
	}
	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Memory_MddPlusPlusCNFsat(solver, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_reduced_MDD, m_the_reduced_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Memory_MddPlusPlusCNFsat(solver, encoding_context, extra_cost, mdd_depth, m_the_reduced_MDD, m_the_reduced_extra_MDD, indent, verbose);
	}
	return sRESULT_SUCCESS;
    }    
    

    void sMultirobotInstance::to_Stream_MmddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	--encoding_context.m_N_Layers;
	construct_MakespanMDD(encoding_context.m_N_Layers, m_the_MDD);
	
	//s_GlobalPhaseStatistics.leave_Phase();

	to_Stream_MmddCNFsat(fw, encoding_context, m_the_MDD, indent, verbose);
    }


    void sMultirobotInstance::to_Memory_MmddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	--encoding_context.m_N_Layers;
	construct_MakespanMDD(encoding_context.m_N_Layers, m_the_MDD);
	
	//s_GlobalPhaseStatistics.leave_Phase();

	to_Memory_MmddCNFsat(solver, encoding_context, m_the_MDD, indent, verbose);
    }    


    void sMultirobotInstance::to_Stream_RelaxedMmddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	--encoding_context.m_N_Layers;
	construct_MakespanMDD(encoding_context.m_N_Layers, m_the_MDD);
	
	//s_GlobalPhaseStatistics.leave_Phase();

	to_Stream_RelaxedMmddCNFsat(fw, encoding_context, m_the_MDD, indent, verbose);
    }


    void sMultirobotInstance::to_Stream_TokenMmddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	--encoding_context.m_N_Layers;
	construct_MakespanMDD(encoding_context.m_N_Layers, m_the_MDD);
	
	//s_GlobalPhaseStatistics.leave_Phase();

	to_Stream_TokenMmddCNFsat(fw, encoding_context, m_the_MDD, indent, verbose);
    }

    
    void sMultirobotInstance::to_Stream_TokenEmptyMmddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	--encoding_context.m_N_Layers;
	construct_MakespanMDD(encoding_context.m_N_Layers, m_the_MDD);
	
	//s_GlobalPhaseStatistics.leave_Phase();

	to_Stream_TokenEmptyMmddCNFsat(fw, encoding_context, m_the_MDD, indent, verbose);
    }        


    void sMultirobotInstance::to_Stream_PermutationMmddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	--encoding_context.m_N_Layers;
	construct_MakespanMDD(encoding_context.m_N_Layers, m_the_MDD);
	
	//s_GlobalPhaseStatistics.leave_Phase();

	to_Stream_PermutationMmddCNFsat(fw, encoding_context, m_the_MDD, indent, verbose);
    }


    void sMultirobotInstance::to_Stream_CapacitatedPermutationMmddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	--encoding_context.m_N_Layers;
	construct_MakespanMDD(encoding_context.m_N_Layers, m_the_MDD);
	
	//s_GlobalPhaseStatistics.leave_Phase();

	to_Stream_CapacitatedPermutationMmddCNFsat(fw, encoding_context, m_the_MDD, indent, verbose);
    }            

    
    void sMultirobotInstance::to_Memory_RelaxedMmddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	--encoding_context.m_N_Layers;
	construct_MakespanMDD(encoding_context.m_N_Layers, m_the_MDD);
	
	//s_GlobalPhaseStatistics.leave_Phase();

	to_Memory_RelaxedMmddCNFsat(solver, encoding_context, m_the_MDD, indent, verbose);
    }        

    
    void sMultirobotInstance::to_Memory_TokenMmddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	--encoding_context.m_N_Layers;
	construct_MakespanMDD(encoding_context.m_N_Layers, m_the_MDD);
	
	//s_GlobalPhaseStatistics.leave_Phase();

	to_Memory_TokenMmddCNFsat(solver, encoding_context, m_the_MDD, indent, verbose);
    }


    void sMultirobotInstance::to_Memory_TokenEmptyMmddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	--encoding_context.m_N_Layers;
	construct_MakespanMDD(encoding_context.m_N_Layers, m_the_MDD);
	
	//s_GlobalPhaseStatistics.leave_Phase();

	to_Memory_TokenEmptyMmddCNFsat(solver, encoding_context, m_the_MDD, indent, verbose);
    }            
    

    void sMultirobotInstance::to_Memory_PermutationMmddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	--encoding_context.m_N_Layers;
	construct_MakespanMDD(encoding_context.m_N_Layers, m_the_MDD);
	
	//s_GlobalPhaseStatistics.leave_Phase();

	to_Memory_PermutationMmddCNFsat(solver, encoding_context, m_the_MDD, indent, verbose);
    }


    void sMultirobotInstance::to_Memory_CapacitatedPermutationMmddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	--encoding_context.m_N_Layers;
	construct_MakespanMDD(encoding_context.m_N_Layers, m_the_MDD);
	
	//s_GlobalPhaseStatistics.leave_Phase();

	to_Memory_CapacitatedPermutationMmddCNFsat(solver, encoding_context, m_the_MDD, indent, verbose);
    }            
    
    
    sResult sMultirobotInstance::to_Stream_MmddCNFsat_avoid(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const Arrangements_vector &unfolded_solution, const sString &indent, bool verbose)
    {
	--encoding_context.m_N_Layers;
	construct_MakespanMDD(encoding_context.m_N_Layers, m_the_MDD);
	
	reduce_MDD(unfolded_solution, m_the_MDD, m_the_reduced_MDD);

	if (!check_Connectivity(m_the_reduced_MDD))
	{
	    return sMULTIROBOT_SOLUTION_COMPRESSOR_MMDD_DISCO_INFO;
	}
	to_Stream_MmddCNFsat(fw, encoding_context, m_the_reduced_MDD, indent, verbose);
		
	return sRESULT_SUCCESS;
    }


    sResult sMultirobotInstance::to_Memory_MmddCNFsat_avoid(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const Arrangements_vector &unfolded_solution, const sString &indent, bool verbose)
    {
	--encoding_context.m_N_Layers;
	construct_MakespanMDD(encoding_context.m_N_Layers, m_the_MDD);
	
	reduce_MDD(unfolded_solution, m_the_MDD, m_the_reduced_MDD);

	if (!check_Connectivity(m_the_reduced_MDD))
	{
	    return sMULTIROBOT_SOLUTION_COMPRESSOR_MMDD_DISCO_INFO;
	}
	to_Memory_MmddCNFsat(solver, encoding_context, m_the_reduced_MDD, indent, verbose);
		
	return sRESULT_SUCCESS;
    }    


    sResult sMultirobotInstance::to_Stream_MmddPlusCNFsat_avoid(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const Arrangements_vector &unfolded_solution, const sString &indent, bool verbose)
    {
	--encoding_context.m_N_Layers;
	construct_MakespanMDD(encoding_context.m_N_Layers, m_the_MDD);
	
	reduce_MDD(unfolded_solution, m_the_MDD, m_the_reduced_MDD);

	if (!check_Connectivity(m_the_reduced_MDD))
	{
	    return sMULTIROBOT_SOLUTION_COMPRESSOR_MMDD_DISCO_INFO;
	}
	to_Stream_MmddPlusCNFsat(fw, encoding_context, m_the_reduced_MDD, indent, verbose);
	
	return sRESULT_SUCCESS;
    }


    sResult sMultirobotInstance::to_Memory_MmddPlusCNFsat_avoid(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const Arrangements_vector &unfolded_solution, const sString &indent, bool verbose)
    {
	--encoding_context.m_N_Layers;
	construct_MakespanMDD(encoding_context.m_N_Layers, m_the_MDD);
	
	reduce_MDD(unfolded_solution, m_the_MDD, m_the_reduced_MDD);

	if (!check_Connectivity(m_the_reduced_MDD))
	{
	    return sMULTIROBOT_SOLUTION_COMPRESSOR_MMDD_DISCO_INFO;
	}
	to_Memory_MmddPlusCNFsat(solver, encoding_context, m_the_reduced_MDD, indent, verbose);
	
	return sRESULT_SUCCESS;
    }    


    sResult sMultirobotInstance::to_Stream_MmddPlusPlusCNFsat_avoid(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const Arrangements_vector &unfolded_solution, const sString &indent, bool verbose)
    {
	--encoding_context.m_N_Layers;
	construct_MakespanMDD(encoding_context.m_N_Layers, m_the_MDD);
	
	reduce_MDD(unfolded_solution, m_the_MDD, m_the_reduced_MDD);

	if (!check_Connectivity(m_the_reduced_MDD))
	{
	    return sMULTIROBOT_SOLUTION_COMPRESSOR_MMDD_DISCO_INFO;
	}
	to_Stream_MmddCNFsat(fw, encoding_context, m_the_reduced_MDD, indent, verbose);
	
	return sRESULT_SUCCESS;
    }


    sResult sMultirobotInstance::to_Memory_MmddPlusPlusCNFsat_avoid(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const Arrangements_vector &unfolded_solution, const sString &indent, bool verbose)
    {
	--encoding_context.m_N_Layers;
	construct_MakespanMDD(encoding_context.m_N_Layers, m_the_MDD);
	
	reduce_MDD(unfolded_solution, m_the_MDD, m_the_reduced_MDD);

	if (!check_Connectivity(m_the_reduced_MDD))
	{
	    return sMULTIROBOT_SOLUTION_COMPRESSOR_MMDD_DISCO_INFO;
	}
	to_Memory_MmddCNFsat(solver, encoding_context, m_the_reduced_MDD, indent, verbose);
	
	return sRESULT_SUCCESS;
    }        


    void sMultirobotInstance::to_Stream_RXMddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	// s_GlobalPhaseStatistics.leave_Phase();

	to_Stream_RXMddCNFsat(fw, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
    }


    void sMultirobotInstance::to_Memory_RXMddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	// s_GlobalPhaseStatistics.leave_Phase();

	to_Memory_RXMddCNFsat(solver, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
    }    


    void sMultirobotInstance::to_Stream_NoMddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	int mdd_depth = construct_NoMDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Stream_MddCNFsat(fw, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Stream_MddCNFsat(fw, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }


    void sMultirobotInstance::to_Memory_NoMddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	int mdd_depth = construct_NoMDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Memory_MddCNFsat(solver, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Memory_MddCNFsat(solver, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }    


    void sMultirobotInstance::to_Stream_RXNoMddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_NoMDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	// s_GlobalPhaseStatistics.leave_Phase();

	to_Stream_RXMddCNFsat(fw, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
    }


    void sMultirobotInstance::to_Memory_RXNoMddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;

	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_NoMDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	// s_GlobalPhaseStatistics.leave_Phase();

	to_Memory_RXMddCNFsat(solver, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
    }    


    void sMultirobotInstance::to_Stream_MddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int Clause_cnt = 0;
	int aux_Variable_cnt = 0;
	int total_Literal_cnt = 0;

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_MultiConjunctiveImplication(aux_Variable_cnt,
													  total_Literal_cnt,
													  sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													  prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}       
	if (!cardinality_Identifiers.empty())
	{
	    Clause_cnt += encoding_context.m_bit_generator->count_Cardinality(aux_Variable_cnt,total_Literal_cnt, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);

		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														      sIntegerIndex(neighbor_index)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														      sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
											   total_Literal_cnt,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(u)),
											   mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
											 total_Literal_cnt,
											 mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
										     total_Literal_cnt,
										     mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector biangular_Identifiers;
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.begin();
				     conflict != m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.end(); ++conflict)
				{
				    for (int k = 0; k < m_robustness; ++k)
				    {
					if (layer - k >= 0)
					{
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (other_robot_id != robot_id)
						{
						    for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						    {
							if (*conflict == MDD[other_robot_id][layer - k][vv])
							{
							    biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														    sIntegerIndex(vv)));
							}
						    }
						}
					    }
					}
				    }
				}
				for (int k = 0; k < m_robustness; ++k)
				{
				    if (layer - k >= 0)
				    {
					for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					{
					    if (other_robot_id != robot_id)
					    {
						for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						{
						    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer - k][vv])
						    {
							biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														sIntegerIndex(vv)));
						    }
						}
					    }
					}
				    }
				}
				if (!biangular_Identifiers.empty())
				{
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiBiangleMutex(aux_Variable_cnt,
													    total_Literal_cnt,
													    sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																    sIntegerIndex(neighbor_index)),
													    biangular_Identifiers);
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										 total_Literal_cnt,
										 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													 sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}

	int N_cnf_Variables = encoding_context.m_variable_store.get_Last_CNFVariable() + aux_Variable_cnt - 1;

#ifdef sDEBUG
	fprintf(fw, "c %s : multirobot MDD SAT encoding\n", sPRODUCT);
	fprintf(fw, "c %s\n", sCOPYRIGHT);
	fprintf(fw, "c number of layers = %d\n", N_Layers);
	fprintf(fw, "c number of visible variables = %d\n", N_cnf_Variables - aux_Variable_cnt);
	fprintf(fw, "c number of hidden variables = %d\n", aux_Variable_cnt);
	fprintf(fw, "c number of literals = %d\n", total_Literal_cnt);
	fprintf(fw, "c number of clauses = %d\n", Clause_cnt);
	fprintf(fw, "c number of propositional variables = %d\n", N_cnf_Variables);
	fprintf(fw, "c number of clauses / number of variables = %.3f\n", (double)Clause_cnt / N_cnf_Variables);
	fprintf(fw, "c number of literals / number of clauses = %.3f\n", (double)total_Literal_cnt /  Clause_cnt);
	to_Stream(fw, "c ");
#endif
	fprintf(fw, "p cnf %d %d\n", N_cnf_Variables, Clause_cnt);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_MultiConjunctiveImplication(fw,
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													     prev_cardinality_Identifiers);
		    }
		}
	    }
	}
	if (!cardinality_Identifiers.empty())
	{
	    Clause_cnt += encoding_context.m_bit_generator->generate_Cardinality(fw, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															 sIntegerIndex(neighbor_index)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
															 sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
												mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
											    mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
											mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
												mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector biangular_Identifiers;
			    
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.begin();
				     conflict != m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.end(); ++conflict)
				{
				    for (int k = 0; k < m_robustness; ++k)
				    {
					if (layer - k >= 0)
					{
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (other_robot_id != robot_id)
						{
						    for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						    {
							if (*conflict == MDD[other_robot_id][layer - k][vv])
							{
							    biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														    sIntegerIndex(vv)));
							}
						    }
						}
					    }
					}
				    }				    
				}				
				for (int k = 0; k < m_robustness; ++k)
				{
				    if (layer - k >= 0)
				    {
					for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					{
					    if (other_robot_id != robot_id)
					    {
						for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						{
						    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer - k][vv])
						    {
							biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														sIntegerIndex(vv)));
						    }
						}
					    }
					}
				    }
				}
				if (!biangular_Identifiers.empty())
				{
				    encoding_context.m_bit_generator->generate_MultiBiangleMutex(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															 sIntegerIndex(neighbor_index)),
												 biangular_Identifiers);
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													    sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }


    struct Mutex
    {
	Mutex() { /* nothing */ }
	Mutex(int robot_id, int vertex_id, int mdd_idx, int mdd_other_idx)
	    : m_robot_id(robot_id)
	    , m_vertex_id(vertex_id)
	    , m_mdd_idx(mdd_idx)
	    , m_mdd_other_idx(mdd_other_idx)
	{ /* nothing */ }

	bool operator<(const Mutex &mutex) const
	{
	    return (m_robot_id < mutex.m_robot_id || (m_robot_id == mutex.m_robot_id && m_vertex_id < mutex.m_vertex_id));
	}

	int m_robot_id;
	int m_vertex_id;
	int m_mdd_idx;
	int m_mdd_other_idx;
    };

    struct MTX
    {
	MTX() { /* nothing */ }
	MTX(int robot_id, int vertex_id)
	    : m_robot_id(robot_id)
	    , m_vertex_id(vertex_id)
	{ /* nothing */ }
	
	int m_robot_id;
	int m_vertex_id;
    };

    typedef std::pair<MTX, MTX> MTX_pair;

    struct ScheduledMTX
    {
	ScheduledMTX() { /* nothing */ }
	ScheduledMTX(int layer, MTX_pair mtx)
	    : m_layer(layer)
	    , m_mtx(mtx)
	{ /* nothing */ }
	
	int m_layer;
	MTX_pair m_mtx;
    };

    typedef std::list<ScheduledMTX> ScheduledMTXs_list;

    typedef std::vector<Mutex> Mutexes_vector;
    typedef std::set<Mutex, std::less<Mutex> > Mutexes_set;    
    typedef std::unordered_map<int, Mutexes_set> VertexMutexes_umap;
    
    typedef std::vector<VertexMutexes_umap> LayerMutexes_vector;
    typedef std::vector<LayerMutexes_vector> RobotMutexes_vector;
    
    typedef RobotMutexes_vector MDDMutexes_vector;
    

    void sMultirobotInstance::to_Stream_MddUmtexCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int Clause_cnt = 0;
	int aux_Variable_cnt = 0;
	int total_Literal_cnt = 0;

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	InverseMDD_vector inverse_MDD;
	construct_InverseMDD(N_Vertices, MDD, inverse_MDD);

	MDDMutexes_vector Mutexes;
	Mutexes.resize(N_Robots + 1);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);

	    Mutexes[robot_id].resize(N_Layers + 1);
	    
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_MultiConjunctiveImplication(aux_Variable_cnt,
													  total_Literal_cnt,
													  sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													  prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}       
	if (!cardinality_Identifiers.empty())
	{
	    Clause_cnt += encoding_context.m_bit_generator->count_Cardinality(aux_Variable_cnt,total_Literal_cnt, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);

		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														      sIntegerIndex(neighbor_index)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														      sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
											   total_Literal_cnt,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(u)),
											   mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
											 total_Literal_cnt,
											 mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
										     total_Literal_cnt,
										     mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_occupancy_Identifiers);
		}
	    }
	}


	ScheduledMTXs_list scheduled_Mutexes;

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{	   
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
		{
		    if (other_robot_id < robot_id)
		    {
			for (int uu = 0; uu < MDD[robot_id][layer].size(); ++uu)
			{
			    int uu_mdd_idx = inverse_MDD[other_robot_id][layer][MDD[robot_id][layer][uu]];
			    
			    if (uu_mdd_idx >= 0)
			    {
				scheduled_Mutexes.push_back(ScheduledMTX(layer, MTX_pair(MTX(robot_id, MDD[robot_id][layer][uu]), MTX(other_robot_id, MDD[other_robot_id][layer][uu_mdd_idx]))));
			    }
			}
		    }
		}
	    }
	}

	std::vector<VertexIDs_vector> vertex_neighbor_IDs;
	vertex_neighbor_IDs.resize(N_Vertices);

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    sVertex::Neighbors_list &vertex_Neighbors = m_environment.m_Vertices[vertex_id].m_Neighbors;
	    for (sVertex::Neighbors_list::const_iterator vertex_neighbor = vertex_Neighbors.begin(); vertex_neighbor != vertex_Neighbors.end(); ++vertex_neighbor)
	    {
		vertex_neighbor_IDs[vertex_id].push_back((*vertex_neighbor)->m_target->m_id);
	    }
	    vertex_neighbor_IDs[vertex_id].push_back(vertex_id);	    
	}

	while (!scheduled_Mutexes.empty())
	{
//	    printf("Size: %ld\n", scheduled_Mutexes.size()); 
	    const ScheduledMTX &scheduled_MTX = scheduled_Mutexes.front();	    
	    
	    int vertex_u_id = scheduled_MTX.m_mtx.first.m_vertex_id;
	    int vertex_w_id = scheduled_MTX.m_mtx.second.m_vertex_id;

	    int robot_id = scheduled_MTX.m_mtx.first.m_robot_id;
	    int other_robot_id = scheduled_MTX.m_mtx.second.m_robot_id;

	    int layer = scheduled_MTX.m_layer;
	    
	    if (layer < N_Layers)
	    {
		/*
		sVertex::Neighbors_list &u_Neighbors = m_environment.m_Vertices[vertex_u_id].m_Neighbors;
		VertexIDs_vector u_neighbor_IDs;
		for (sVertex::Neighbors_list::const_iterator u_neighbor = u_Neighbors.begin(); u_neighbor != u_Neighbors.end(); ++u_neighbor)
		{
		    u_neighbor_IDs.push_back((*u_neighbor)->m_target->m_id);
		}
		u_neighbor_IDs.push_back(vertex_u_id);
		
		sVertex::Neighbors_list &w_Neighbors = m_environment.m_Vertices[vertex_w_id].m_Neighbors;
		VertexIDs_vector w_neighbor_IDs;
		for (sVertex::Neighbors_list::const_iterator w_neighbor = w_Neighbors.begin(); w_neighbor != w_Neighbors.end(); ++w_neighbor)
		{
		    w_neighbor_IDs.push_back((*w_neighbor)->m_target->m_id);
		}
		w_neighbor_IDs.push_back(vertex_w_id);
		*/
		
		for (VertexIDs_vector::const_iterator v_neighbor = vertex_neighbor_IDs[vertex_u_id].begin(); v_neighbor != vertex_neighbor_IDs[vertex_u_id].end(); ++v_neighbor)
		{
		    sInt_32 v_mdd_idx = inverse_MDD[robot_id][layer + 1][(*v_neighbor)];
						    
		    if (v_mdd_idx >= 0)
		    {
			for (VertexIDs_vector::const_iterator z_neighbor = vertex_neighbor_IDs[vertex_w_id].begin(); z_neighbor != vertex_neighbor_IDs[vertex_w_id].end(); ++z_neighbor)
			{
			    sInt_32 z_mdd_idx = inverse_MDD[other_robot_id][layer + 1][(*z_neighbor)];
			    
			    if (z_mdd_idx >= 0)
			    {			    			    
				if (*v_neighbor < *z_neighbor)
				{
				    int vertex_v_id = *v_neighbor;
				    int vertex_z_id = *z_neighbor;

				    bool all_mutex = true;

				    /*
				    sVertex::Neighbors_list &v_Neighbors = m_environment.m_Vertices[vertex_v_id].m_Neighbors;
				    VertexIDs_vector v_neighbor_IDs;
				    for (sVertex::Neighbors_list::const_iterator v_neighbor = v_Neighbors.begin(); v_neighbor != v_Neighbors.end(); ++v_neighbor)
				    {
					v_neighbor_IDs.push_back((*v_neighbor)->m_target->m_id);
				    }
				    v_neighbor_IDs.push_back(vertex_v_id);
				    */
				    
				    for (VertexIDs_vector::const_iterator v_neighbor = vertex_neighbor_IDs[vertex_v_id].begin(); v_neighbor != vertex_neighbor_IDs[vertex_v_id].end(); ++v_neighbor)
				    {
					sInt_32 u_mdd_idx = inverse_MDD[robot_id][layer][(*v_neighbor)];
					
					if (u_mdd_idx >= 0)
					{
					    bool u_all_mutex = true;

					    /*
					    sVertex::Neighbors_list &z_Neighbors = m_environment.m_Vertices[vertex_z_id].m_Neighbors;
					    VertexIDs_vector z_neighbor_IDs;
					    for (sVertex::Neighbors_list::const_iterator z_neighbor = z_Neighbors.begin(); z_neighbor != z_Neighbors.end(); ++z_neighbor)
					    {
						z_neighbor_IDs.push_back((*z_neighbor)->m_target->m_id);
					    }
					    z_neighbor_IDs.push_back(vertex_z_id);
					    */
					    
					    for (VertexIDs_vector::const_iterator z_neighbor = vertex_neighbor_IDs[vertex_z_id].begin(); z_neighbor != vertex_neighbor_IDs[vertex_z_id].end(); ++z_neighbor)
					    {
						sInt_32 w_mdd_idx = inverse_MDD[other_robot_id][layer][(*z_neighbor)];
						
						if (w_mdd_idx >= 0)
						{
						    bool mutex_found = false;						
						    
						    if (MDD[robot_id][layer][u_mdd_idx] == MDD[other_robot_id][layer][w_mdd_idx])
						    {
							mutex_found = true;
						    }
						    else
						    {
							VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].find(MDD[robot_id][layer][u_mdd_idx]);
							
							if (mutexes_u != Mutexes[robot_id][layer].end())
							{
							    for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
							    {
								if (mutex_u->m_robot_id == other_robot_id && mutex_u->m_vertex_id == MDD[other_robot_id][layer][w_mdd_idx])
								{
								    mutex_found = true;
								    break;
								}
							    }
							}
						    }
						    if (!mutex_found)
						    {
							u_all_mutex = false;
							break;
						    }
						}
					    }
					    if (!u_all_mutex)
					    {
						all_mutex = false;
						break;
					    }
					}
				    }				    
				    if (all_mutex)
				    {
					bool next_first_mutex = Mutexes[robot_id][layer + 1][vertex_v_id].insert(Mutex(other_robot_id, vertex_z_id, z_mdd_idx, v_mdd_idx)).second;
					bool next_second_mutex = Mutexes[other_robot_id][layer + 1][vertex_z_id].insert(Mutex(robot_id, vertex_v_id, v_mdd_idx, z_mdd_idx)).second;

					if (next_first_mutex || next_second_mutex)
					{
					    scheduled_Mutexes.push_back(ScheduledMTX(layer + 1, MTX_pair(MTX(robot_id, vertex_v_id), MTX(other_robot_id, vertex_z_id))));
					}
				    }
				}	    
			    }
			}
		    }
		}
	    }
	    if (layer > 0)
	    {		
		for (VertexIDs_vector::const_iterator v_neighbor = vertex_neighbor_IDs[vertex_u_id].begin(); v_neighbor != vertex_neighbor_IDs[vertex_u_id].end(); ++v_neighbor)
		{
		    sInt_32 v_mdd_idx = inverse_MDD[robot_id][layer - 1][(*v_neighbor)];
						    
		    if (v_mdd_idx >= 0)
		    {
			for (VertexIDs_vector::const_iterator z_neighbor = vertex_neighbor_IDs[vertex_w_id].begin(); z_neighbor != vertex_neighbor_IDs[vertex_w_id].end(); ++z_neighbor)
			{
			    sInt_32 z_mdd_idx = inverse_MDD[other_robot_id][layer - 1][(*z_neighbor)];
			    
			    if (z_mdd_idx >= 0)
			    {			    			    
				if (*v_neighbor < *z_neighbor)
				{
				    int vertex_v_id = *v_neighbor;
				    int vertex_z_id = *z_neighbor;

				    bool all_mutex = true;
				    
				    for (VertexIDs_vector::const_iterator v_neighbor = vertex_neighbor_IDs[vertex_v_id].begin(); v_neighbor != vertex_neighbor_IDs[vertex_v_id].end(); ++v_neighbor)
				    {
					sInt_32 u_mdd_idx = inverse_MDD[robot_id][layer][(*v_neighbor)];
					
					if (u_mdd_idx >= 0)
					{
					    bool u_all_mutex = true;
					    
					    for (VertexIDs_vector::const_iterator z_neighbor = vertex_neighbor_IDs[vertex_z_id].begin(); z_neighbor != vertex_neighbor_IDs[vertex_z_id].end(); ++z_neighbor)
					    {
						sInt_32 w_mdd_idx = inverse_MDD[other_robot_id][layer][(*z_neighbor)];
						
						if (w_mdd_idx >= 0)
						{
						    bool mutex_found = false;						
						    
						    if (MDD[robot_id][layer][u_mdd_idx] == MDD[other_robot_id][layer][w_mdd_idx])
						    {
							mutex_found = true;
						    }
						    else
						    {
							VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].find(MDD[robot_id][layer][u_mdd_idx]);
							
							if (mutexes_u != Mutexes[robot_id][layer].end())
							{
							    for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
							    {
								if (mutex_u->m_robot_id == other_robot_id && mutex_u->m_vertex_id == MDD[other_robot_id][layer][w_mdd_idx])
								{
								    mutex_found = true;
								    break;
								}
							    }
							}
						    }
						    if (!mutex_found)
						    {
							u_all_mutex = false;
							break;
						    }
						}
					    }
					    if (!u_all_mutex)
					    {
						all_mutex = false;
						break;
					    }
					}
				    }				    
				    if (all_mutex)
				    {
					bool next_first_mutex = Mutexes[robot_id][layer - 1][vertex_v_id].insert(Mutex(other_robot_id, vertex_z_id, z_mdd_idx, v_mdd_idx)).second;
					bool next_second_mutex = Mutexes[other_robot_id][layer - 1][vertex_z_id].insert(Mutex(robot_id, vertex_v_id, v_mdd_idx, z_mdd_idx)).second;

					if (next_first_mutex || next_second_mutex)
					{
					    scheduled_Mutexes.push_back(ScheduledMTX(layer - 1, MTX_pair(MTX(robot_id, vertex_v_id), MTX(other_robot_id, vertex_z_id))));
					}
				    }
				}	    
			    }
		        }	
		    }
		}
	    }
	    scheduled_Mutexes.pop_front();
	}
	int N_mutexes = 0;
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{	    
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		for (VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].begin(); mutexes_u != Mutexes[robot_id][layer].end(); ++mutexes_u)
		{
		    int vertex_u_id = mutexes_u->first;

		    for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
		    {			
			int vertex_v_id = mutex_u->m_vertex_id;
			int vertex_v_idx = mutex_u->m_mdd_idx;
			int vertex_u_idx = mutex_u->m_mdd_other_idx;			
			int other_robot_id = mutex_u->m_robot_id;
			
			if (vertex_u_id < vertex_v_id)
			{
			    Clause_cnt += encoding_context.m_bit_generator->count_Mutex(aux_Variable_cnt,
												    total_Literal_cnt,
												    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
															    sIntegerIndex(vertex_u_idx)),
												    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
															    sIntegerIndex(vertex_v_idx)));
//			    printf(" 	 Mutex: at level %d - [%d, %d (%d)] x [%d, %d (%d)]\n", layer, robot_id, vertex_u_id, vertex_u_idx, other_robot_id, vertex_v_id, vertex_v_idx);
			    ++N_mutexes;
			}
		    }
		}
	    }
	}
	printf("Mutexes found in total: %d\n", N_mutexes);			

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector biangular_Identifiers;
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.begin();
				     conflict != m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.end(); ++conflict)
				{
				    for (int k = 0; k < m_robustness; ++k)
				    {
					if (layer - k >= 0)
					{
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (other_robot_id != robot_id)
						{
						    for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						    {
							if (*conflict == MDD[other_robot_id][layer - k][vv])
							{
							    biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														    sIntegerIndex(vv)));
							}
						    }
						}
					    }
					}
				    }
				}
				for (int k = 0; k < m_robustness; ++k)
				{
				    if (layer - k >= 0)
				    {
					for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					{
					    if (other_robot_id != robot_id)
					    {
						for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						{
						    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer - k][vv])
						    {
							biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														sIntegerIndex(vv)));
						    }
						}
					    }
					}
				    }
				}
				if (!biangular_Identifiers.empty())
				{
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiBiangleMutex(aux_Variable_cnt,
													    total_Literal_cnt,
													    sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																    sIntegerIndex(neighbor_index)),
													    biangular_Identifiers);
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										 total_Literal_cnt,
										 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													 sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}

	int N_cnf_Variables = encoding_context.m_variable_store.get_Last_CNFVariable() + aux_Variable_cnt - 1;

#ifdef sDEBUG
	fprintf(fw, "c %s : multirobot MDD SAT encoding\n", sPRODUCT);
	fprintf(fw, "c %s\n", sCOPYRIGHT);
	fprintf(fw, "c number of layers = %d\n", N_Layers);
	fprintf(fw, "c number of visible variables = %d\n", N_cnf_Variables - aux_Variable_cnt);
	fprintf(fw, "c number of hidden variables = %d\n", aux_Variable_cnt);
	fprintf(fw, "c number of literals = %d\n", total_Literal_cnt);
	fprintf(fw, "c number of clauses = %d\n", Clause_cnt);
	fprintf(fw, "c number of propositional variables = %d\n", N_cnf_Variables);
	fprintf(fw, "c number of clauses / number of variables = %.3f\n", (double)Clause_cnt / N_cnf_Variables);
	fprintf(fw, "c number of literals / number of clauses = %.3f\n", (double)total_Literal_cnt /  Clause_cnt);
	to_Stream(fw, "c ");
#endif
	fprintf(fw, "p cnf %d %d\n", N_cnf_Variables, Clause_cnt);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_MultiConjunctiveImplication(fw,
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													     prev_cardinality_Identifiers);
		    }
		}
	    }
	}
	if (!cardinality_Identifiers.empty())
	{
	    Clause_cnt += encoding_context.m_bit_generator->generate_Cardinality(fw, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															 sIntegerIndex(neighbor_index)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
															 sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
												mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
											    mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
											mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
												mutex_occupancy_Identifiers);
		}
	    }
	}

	N_mutexes = 0;
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{	    
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		for (VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].begin(); mutexes_u != Mutexes[robot_id][layer].end(); ++mutexes_u)
		{
		    int vertex_u_id = mutexes_u->first;

		    for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
		    {			
			int vertex_v_id = mutex_u->m_vertex_id;
			/*
			int vertex_v_idx = mutex_u->m_mdd_idx;
			int vertex_u_idx = mutex_u->m_mdd_other_idx;			
			int other_robot_id = mutex_u->m_robot_id;
			*/
			
			if (vertex_u_id < vertex_v_id)
			{
			    /*
			    Clause_cnt += encoding_context.m_bit_generator->generate_Mutex(fw,			    
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(vertex_u_idx)),
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
														   sIntegerIndex(vertex_v_idx)));
			    */
//			    printf(" 	 Mutex: at level %d - [%d, %d (%d)] x [%d, %d (%d)]\n", layer, robot_id, vertex_u_id, vertex_u_idx, other_robot_id, vertex_v_id, vertex_v_idx);
			    ++N_mutexes;
			}
		    }
		}
	    }
	}
	//printf("Mutexes found in total: %d\n", N_mutexes);		

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector biangular_Identifiers;
			    
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.begin();
				     conflict != m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.end(); ++conflict)
				{
				    for (int k = 0; k < m_robustness; ++k)
				    {
					if (layer - k >= 0)
					{
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (other_robot_id != robot_id)
						{
						    for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						    {
							if (*conflict == MDD[other_robot_id][layer - k][vv])
							{
							    biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														    sIntegerIndex(vv)));
							}
						    }
						}
					    }
					}
				    }				    
				}				
				for (int k = 0; k < m_robustness; ++k)
				{
				    if (layer - k >= 0)
				    {
					for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					{
					    if (other_robot_id != robot_id)
					    {
						for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						{
						    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer - k][vv])
						    {
							biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														sIntegerIndex(vv)));
						    }
						}
					    }
					}
				    }
				}
				if (!biangular_Identifiers.empty())
				{
				    encoding_context.m_bit_generator->generate_MultiBiangleMutex(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															 sIntegerIndex(neighbor_index)),
												 biangular_Identifiers);
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													    sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }


    void sMultirobotInstance::to_Stream_MddMutexCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int Clause_cnt = 0;
	int aux_Variable_cnt = 0;
	int total_Literal_cnt = 0;

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	MDDMutexes_vector Mutexes;
	Mutexes.resize(N_Robots + 1);		

	InverseMDD_vector inverse_MDD;
	construct_InverseMDD(N_Vertices, MDD, inverse_MDD);		

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);

	    Mutexes[robot_id].resize(N_Layers + 1);
	    
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_MultiConjunctiveImplication(aux_Variable_cnt,
													  total_Literal_cnt,
													  sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													  prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}       
	if (!cardinality_Identifiers.empty())
	{
	    Clause_cnt += encoding_context.m_bit_generator->count_Cardinality(aux_Variable_cnt,total_Literal_cnt, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);

		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														      sIntegerIndex(neighbor_index)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														      sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
											   total_Literal_cnt,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(u)),
											   mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
											 total_Literal_cnt,
											 mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
										     total_Literal_cnt,
										     mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_occupancy_Identifiers);
		}
	    }
	}


	ScheduledMTXs_list scheduled_Mutexes;

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{	   
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
		{
		    if (other_robot_id < robot_id)
		    {
			for (int uu = 0; uu < MDD[robot_id][layer].size(); ++uu)
			{
			    int uu_mdd_idx = inverse_MDD[other_robot_id][layer][MDD[robot_id][layer][uu]];
			    
			    if (uu_mdd_idx >= 0)
			    {
				scheduled_Mutexes.push_back(ScheduledMTX(layer, MTX_pair(MTX(robot_id, MDD[robot_id][layer][uu]), MTX(other_robot_id, MDD[other_robot_id][layer][uu_mdd_idx]))));
			    }
			}
		    }
		}
	    }
	}

	std::vector<VertexIDs_vector> vertex_neighbor_IDs;
	vertex_neighbor_IDs.resize(N_Vertices);

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    sVertex::Neighbors_list &vertex_Neighbors = m_environment.m_Vertices[vertex_id].m_Neighbors;
	    for (sVertex::Neighbors_list::const_iterator vertex_neighbor = vertex_Neighbors.begin(); vertex_neighbor != vertex_Neighbors.end(); ++vertex_neighbor)
	    {
		vertex_neighbor_IDs[vertex_id].push_back((*vertex_neighbor)->m_target->m_id);
	    }
	    vertex_neighbor_IDs[vertex_id].push_back(vertex_id);	    
	}

	while (!scheduled_Mutexes.empty())
	{
//	    printf("Size: %ld\n", scheduled_Mutexes.size()); 
	    const ScheduledMTX &scheduled_MTX = scheduled_Mutexes.front();	    
	    
	    int vertex_u_id = scheduled_MTX.m_mtx.first.m_vertex_id;
	    int vertex_w_id = scheduled_MTX.m_mtx.second.m_vertex_id;

	    int robot_id = scheduled_MTX.m_mtx.first.m_robot_id;
	    int other_robot_id = scheduled_MTX.m_mtx.second.m_robot_id;

	    int layer = scheduled_MTX.m_layer;
	    
	    if (layer < N_Layers)
	    {
		/*
		sVertex::Neighbors_list &u_Neighbors = m_environment.m_Vertices[vertex_u_id].m_Neighbors;
		VertexIDs_vector u_neighbor_IDs;
		for (sVertex::Neighbors_list::const_iterator u_neighbor = u_Neighbors.begin(); u_neighbor != u_Neighbors.end(); ++u_neighbor)
		{
		    u_neighbor_IDs.push_back((*u_neighbor)->m_target->m_id);
		}
		u_neighbor_IDs.push_back(vertex_u_id);
		
		sVertex::Neighbors_list &w_Neighbors = m_environment.m_Vertices[vertex_w_id].m_Neighbors;
		VertexIDs_vector w_neighbor_IDs;
		for (sVertex::Neighbors_list::const_iterator w_neighbor = w_Neighbors.begin(); w_neighbor != w_Neighbors.end(); ++w_neighbor)
		{
		    w_neighbor_IDs.push_back((*w_neighbor)->m_target->m_id);
		}
		w_neighbor_IDs.push_back(vertex_w_id);
		*/
		
		for (VertexIDs_vector::const_iterator v_neighbor = vertex_neighbor_IDs[vertex_u_id].begin(); v_neighbor != vertex_neighbor_IDs[vertex_u_id].end(); ++v_neighbor)
		{
		    sInt_32 v_mdd_idx = inverse_MDD[robot_id][layer + 1][(*v_neighbor)];
						    
		    if (v_mdd_idx >= 0)
		    {
			for (VertexIDs_vector::const_iterator z_neighbor = vertex_neighbor_IDs[vertex_w_id].begin(); z_neighbor != vertex_neighbor_IDs[vertex_w_id].end(); ++z_neighbor)
			{
			    sInt_32 z_mdd_idx = inverse_MDD[other_robot_id][layer + 1][(*z_neighbor)];
			    
			    if (z_mdd_idx >= 0)
			    {			    			    
				if (*v_neighbor < *z_neighbor)
				{
				    int vertex_v_id = *v_neighbor;
				    int vertex_z_id = *z_neighbor;

				    bool all_mutex = true;

				    /*
				    sVertex::Neighbors_list &v_Neighbors = m_environment.m_Vertices[vertex_v_id].m_Neighbors;
				    VertexIDs_vector v_neighbor_IDs;
				    for (sVertex::Neighbors_list::const_iterator v_neighbor = v_Neighbors.begin(); v_neighbor != v_Neighbors.end(); ++v_neighbor)
				    {
					v_neighbor_IDs.push_back((*v_neighbor)->m_target->m_id);
				    }
				    v_neighbor_IDs.push_back(vertex_v_id);
				    */
				    
				    for (VertexIDs_vector::const_iterator v_neighbor = vertex_neighbor_IDs[vertex_v_id].begin(); v_neighbor != vertex_neighbor_IDs[vertex_v_id].end(); ++v_neighbor)
				    {
					sInt_32 u_mdd_idx = inverse_MDD[robot_id][layer][(*v_neighbor)];
					
					if (u_mdd_idx >= 0)
					{
					    bool u_all_mutex = true;

					    /*
					    sVertex::Neighbors_list &z_Neighbors = m_environment.m_Vertices[vertex_z_id].m_Neighbors;
					    VertexIDs_vector z_neighbor_IDs;
					    for (sVertex::Neighbors_list::const_iterator z_neighbor = z_Neighbors.begin(); z_neighbor != z_Neighbors.end(); ++z_neighbor)
					    {
						z_neighbor_IDs.push_back((*z_neighbor)->m_target->m_id);
					    }
					    z_neighbor_IDs.push_back(vertex_z_id);
					    */
					    
					    for (VertexIDs_vector::const_iterator z_neighbor = vertex_neighbor_IDs[vertex_z_id].begin(); z_neighbor != vertex_neighbor_IDs[vertex_z_id].end(); ++z_neighbor)
					    {
						sInt_32 w_mdd_idx = inverse_MDD[other_robot_id][layer][(*z_neighbor)];
						
						if (w_mdd_idx >= 0)
						{
						    bool mutex_found = false;						
						    
						    if (MDD[robot_id][layer][u_mdd_idx] == MDD[other_robot_id][layer][w_mdd_idx])
						    {
							mutex_found = true;
						    }
						    else
						    {
							VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].find(MDD[robot_id][layer][u_mdd_idx]);
							
							if (mutexes_u != Mutexes[robot_id][layer].end())
							{
							    for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
							    {
								if (mutex_u->m_robot_id == other_robot_id && mutex_u->m_vertex_id == MDD[other_robot_id][layer][w_mdd_idx])
								{
								    mutex_found = true;
								    break;
								}
							    }
							}
						    }
						    if (!mutex_found)
						    {
							u_all_mutex = false;
							break;
						    }
						}
					    }
					    if (!u_all_mutex)
					    {
						all_mutex = false;
						break;
					    }
					}
				    }				    
				    if (all_mutex)
				    {
					bool next_first_mutex = Mutexes[robot_id][layer + 1][vertex_v_id].insert(Mutex(other_robot_id, vertex_z_id, z_mdd_idx, v_mdd_idx)).second;
					bool next_second_mutex = Mutexes[other_robot_id][layer + 1][vertex_z_id].insert(Mutex(robot_id, vertex_v_id, v_mdd_idx, z_mdd_idx)).second;

					if (next_first_mutex || next_second_mutex)
					{
					    scheduled_Mutexes.push_back(ScheduledMTX(layer + 1, MTX_pair(MTX(robot_id, vertex_v_id), MTX(other_robot_id, vertex_z_id))));
					}
				    }
				}	    
			    }
			}
		    }
		}
	    }
	    if (layer > 0)
	    {		
		for (VertexIDs_vector::const_iterator v_neighbor = vertex_neighbor_IDs[vertex_u_id].begin(); v_neighbor != vertex_neighbor_IDs[vertex_u_id].end(); ++v_neighbor)
		{
		    sInt_32 v_mdd_idx = inverse_MDD[robot_id][layer - 1][(*v_neighbor)];
						    
		    if (v_mdd_idx >= 0)
		    {
			for (VertexIDs_vector::const_iterator z_neighbor = vertex_neighbor_IDs[vertex_w_id].begin(); z_neighbor != vertex_neighbor_IDs[vertex_w_id].end(); ++z_neighbor)
			{
			    sInt_32 z_mdd_idx = inverse_MDD[other_robot_id][layer - 1][(*z_neighbor)];
			    
			    if (z_mdd_idx >= 0)
			    {			    			    
				if (*v_neighbor < *z_neighbor)
				{
				    int vertex_v_id = *v_neighbor;
				    int vertex_z_id = *z_neighbor;

				    bool all_mutex = true;
				    
				    for (VertexIDs_vector::const_iterator v_neighbor = vertex_neighbor_IDs[vertex_v_id].begin(); v_neighbor != vertex_neighbor_IDs[vertex_v_id].end(); ++v_neighbor)
				    {
					sInt_32 u_mdd_idx = inverse_MDD[robot_id][layer][(*v_neighbor)];
					
					if (u_mdd_idx >= 0)
					{
					    bool u_all_mutex = true;
					    
					    for (VertexIDs_vector::const_iterator z_neighbor = vertex_neighbor_IDs[vertex_z_id].begin(); z_neighbor != vertex_neighbor_IDs[vertex_z_id].end(); ++z_neighbor)
					    {
						sInt_32 w_mdd_idx = inverse_MDD[other_robot_id][layer][(*z_neighbor)];
						
						if (w_mdd_idx >= 0)
						{
						    bool mutex_found = false;						
						    
						    if (MDD[robot_id][layer][u_mdd_idx] == MDD[other_robot_id][layer][w_mdd_idx])
						    {
							mutex_found = true;
						    }
						    else
						    {
							VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].find(MDD[robot_id][layer][u_mdd_idx]);
							
							if (mutexes_u != Mutexes[robot_id][layer].end())
							{
							    for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
							    {
								if (mutex_u->m_robot_id == other_robot_id && mutex_u->m_vertex_id == MDD[other_robot_id][layer][w_mdd_idx])
								{
								    mutex_found = true;
								    break;
								}
							    }
							}
						    }
						    if (!mutex_found)
						    {
							u_all_mutex = false;
							break;
						    }
						}
					    }
					    if (!u_all_mutex)
					    {
						all_mutex = false;
						break;
					    }
					}
				    }				    
				    if (all_mutex)
				    {
					bool next_first_mutex = Mutexes[robot_id][layer - 1][vertex_v_id].insert(Mutex(other_robot_id, vertex_z_id, z_mdd_idx, v_mdd_idx)).second;
					bool next_second_mutex = Mutexes[other_robot_id][layer - 1][vertex_z_id].insert(Mutex(robot_id, vertex_v_id, v_mdd_idx, z_mdd_idx)).second;

					if (next_first_mutex || next_second_mutex)
					{
					    scheduled_Mutexes.push_back(ScheduledMTX(layer - 1, MTX_pair(MTX(robot_id, vertex_v_id), MTX(other_robot_id, vertex_z_id))));
					}
				    }
				}	    
			    }
		        }	
		    }
		}
	    }
	    scheduled_Mutexes.pop_front();
	}
	int N_mutexes = 0;
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{	    
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		for (VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].begin(); mutexes_u != Mutexes[robot_id][layer].end(); ++mutexes_u)
		{
		    int vertex_u_id = mutexes_u->first;

		    for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
		    {			
			int vertex_v_id = mutex_u->m_vertex_id;
			int vertex_v_idx = mutex_u->m_mdd_idx;
			int vertex_u_idx = mutex_u->m_mdd_other_idx;			
			int other_robot_id = mutex_u->m_robot_id;
			
			if (vertex_u_id < vertex_v_id)
			{
			    Clause_cnt += encoding_context.m_bit_generator->count_Mutex(aux_Variable_cnt,
												    total_Literal_cnt,
												    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
															    sIntegerIndex(vertex_u_idx)),
												    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
															    sIntegerIndex(vertex_v_idx)));
//			    printf(" 	 Mutex: at level %d - [%d, %d (%d)] x [%d, %d (%d)]\n", layer, robot_id, vertex_u_id, vertex_u_idx, other_robot_id, vertex_v_id, vertex_v_idx);
			    ++N_mutexes;
			}
		    }
		}
	    }
	}
	printf("Mutexes found in total: %d\n", N_mutexes);			

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector biangular_Identifiers;
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.begin();
				     conflict != m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.end(); ++conflict)
				{
				    for (int k = 0; k < m_robustness; ++k)
				    {
					if (layer - k >= 0)
					{
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (other_robot_id != robot_id)
						{
						    for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						    {
							if (*conflict == MDD[other_robot_id][layer - k][vv])
							{
							    biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														    sIntegerIndex(vv)));
							}
						    }
						}
					    }
					}
				    }
				}
				for (int k = 0; k < m_robustness; ++k)
				{
				    if (layer - k >= 0)
				    {
					for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					{
					    if (other_robot_id != robot_id)
					    {
						for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						{
						    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer - k][vv])
						    {
							biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														sIntegerIndex(vv)));
						    }
						}
					    }
					}
				    }
				}
				if (!biangular_Identifiers.empty())
				{
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiBiangleMutex(aux_Variable_cnt,
													    total_Literal_cnt,
													    sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																    sIntegerIndex(neighbor_index)),
													    biangular_Identifiers);
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										 total_Literal_cnt,
										 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													 sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}

	int N_cnf_Variables = encoding_context.m_variable_store.get_Last_CNFVariable() + aux_Variable_cnt - 1;

#ifdef sDEBUG
	fprintf(fw, "c %s : multirobot MDD SAT encoding\n", sPRODUCT);
	fprintf(fw, "c %s\n", sCOPYRIGHT);
	fprintf(fw, "c number of layers = %d\n", N_Layers);
	fprintf(fw, "c number of visible variables = %d\n", N_cnf_Variables - aux_Variable_cnt);
	fprintf(fw, "c number of hidden variables = %d\n", aux_Variable_cnt);
	fprintf(fw, "c number of literals = %d\n", total_Literal_cnt);
	fprintf(fw, "c number of clauses = %d\n", Clause_cnt);
	fprintf(fw, "c number of propositional variables = %d\n", N_cnf_Variables);
	fprintf(fw, "c number of clauses / number of variables = %.3f\n", (double)Clause_cnt / N_cnf_Variables);
	fprintf(fw, "c number of literals / number of clauses = %.3f\n", (double)total_Literal_cnt /  Clause_cnt);
	to_Stream(fw, "c ");
#endif
	fprintf(fw, "p cnf %d %d\n", N_cnf_Variables, Clause_cnt);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_MultiConjunctiveImplication(fw,
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													     prev_cardinality_Identifiers);
		    }
		}
	    }
	}
	if (!cardinality_Identifiers.empty())
	{
	    Clause_cnt += encoding_context.m_bit_generator->generate_Cardinality(fw, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															 sIntegerIndex(neighbor_index)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
															 sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
												mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
											    mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
											mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
												mutex_occupancy_Identifiers);
		}
	    }
	}

	N_mutexes = 0;
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{	    
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		for (VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].begin(); mutexes_u != Mutexes[robot_id][layer].end(); ++mutexes_u)
		{
		    int vertex_u_id = mutexes_u->first;

		    for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
		    {			
			int vertex_v_id = mutex_u->m_vertex_id;
			int vertex_v_idx = mutex_u->m_mdd_idx;
			int vertex_u_idx = mutex_u->m_mdd_other_idx;			
			int other_robot_id = mutex_u->m_robot_id;
			
			if (vertex_u_id < vertex_v_id)
			{
			    Clause_cnt += encoding_context.m_bit_generator->generate_Mutex(fw,			    
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(vertex_u_idx)),
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
														   sIntegerIndex(vertex_v_idx)));
//			    printf(" 	 Mutex: at level %d - [%d, %d (%d)] x [%d, %d (%d)]\n", layer, robot_id, vertex_u_id, vertex_u_idx, other_robot_id, vertex_v_id, vertex_v_idx);
			    ++N_mutexes;
			}
		    }
		}
	    }
	}
	//printf("Mutexes found in total: %d\n", N_mutexes);		

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector biangular_Identifiers;
			    
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.begin();
				     conflict != m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.end(); ++conflict)
				{
				    for (int k = 0; k < m_robustness; ++k)
				    {
					if (layer - k >= 0)
					{
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (other_robot_id != robot_id)
						{
						    for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						    {
							if (*conflict == MDD[other_robot_id][layer - k][vv])
							{
							    biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														    sIntegerIndex(vv)));
							}
						    }
						}
					    }
					}
				    }				    
				}				
				for (int k = 0; k < m_robustness; ++k)
				{
				    if (layer - k >= 0)
				    {
					for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					{
					    if (other_robot_id != robot_id)
					    {
						for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						{
						    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer - k][vv])
						    {
							biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														sIntegerIndex(vv)));
						    }
						}
					    }
					}
				    }
				}
				if (!biangular_Identifiers.empty())
				{
				    encoding_context.m_bit_generator->generate_MultiBiangleMutex(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															 sIntegerIndex(neighbor_index)),
												 biangular_Identifiers);
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													    sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }    


    void sMultirobotInstance::to_Stream_GMddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int Clause_cnt = 0;
	int aux_Variable_cnt = 0;
	int total_Literal_cnt = 0;

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_MultiConjunctiveImplication(aux_Variable_cnt,
													  total_Literal_cnt,
													  sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													  prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}       
	if (!cardinality_Identifiers.empty())
	{
	    Clause_cnt += encoding_context.m_bit_generator->count_Cardinality(aux_Variable_cnt,total_Literal_cnt, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);

		}
	    }
	}
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sVertex::Neighbors_list &Neighbors = m_environment.m_Vertices[MDD[robot_id][layer][u]].m_Neighbors;
			    for (sVertex::Neighbors_list::const_iterator neighbor = Neighbors.begin(); neighbor != Neighbors.end(); ++neighbor)
			    {				
				if ((*neighbor)->m_target->m_id == MDD[robot_id][layer + 1][v])
				{
				    if (!(*neighbor)->m_edge->m_Conflicts.empty())
				    {
					sBitClauseGenerator::SpecifiedBitIdentifiers_vector conflict_edge_Identifiers;
				 
					sEdge::Conflicts_vector &Conflicts = (*neighbor)->m_edge->m_Conflicts;
					for (sEdge::Conflicts_vector::const_iterator conflict = Conflicts.begin(); conflict != Conflicts.end(); ++conflict)
					{					    
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (robot_id != other_robot_id)
						{
						    for (int uu = 0; uu < MDD[other_robot_id][layer].size(); ++uu)
						    {
							int neighbor_index = 0;
							for (int vv = 0; vv < MDD[other_robot_id][layer + 1].size(); ++vv)
							{
							    if (   m_environment.is_Adjacent(MDD[other_robot_id][layer][uu], MDD[other_robot_id][layer + 1][vv])
								|| MDD[other_robot_id][layer][uu] == MDD[other_robot_id][layer + 1][vv])
							    {
								if (   (conflict->m_x_ID == MDD[other_robot_id][layer][uu] && conflict->m_y_ID == MDD[other_robot_id][layer + 1][vv])
								    || (conflict->m_y_ID == MDD[other_robot_id][layer][uu] && conflict->m_x_ID == MDD[other_robot_id][layer + 1][vv]))
								{
								    conflict_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][uu],
																sIntegerIndex(neighbor_index)));
								}
								neighbor_index++;
							    }
							}
						    }
						}
					    }
					}
					Clause_cnt += encoding_context.m_bit_generator->count_MultiNegativeImplication(aux_Variable_cnt,
														       total_Literal_cnt,
														       sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	       sIntegerIndex(neighbor_index)),
														       conflict_edge_Identifiers);
				    }
				}
			    }
				
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														      sIntegerIndex(neighbor_index)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														      sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
											   total_Literal_cnt,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(u)),
											   mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
											 total_Literal_cnt,
											 mutex_vertex_Identifiers);
	    }
	}
     
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
										     total_Literal_cnt,
										     mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector biangular_Identifiers;
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.begin();
				     conflict != m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.end(); ++conflict)
				{
				    for (int k = 0; k < m_robustness; ++k)
				    {
					if (layer - k >= 0)
					{
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (other_robot_id != robot_id)
						{
						    for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						    {
							if (*conflict == MDD[other_robot_id][layer - k][vv])
							{
							    biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														    sIntegerIndex(vv)));
							}
						    }
						}
					    }
					}
				    }				    
				}

				for (int k = 0; k < m_robustness; ++k)
				{
				    if (layer - k >= 0)
				    {
					for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					{
					    if (other_robot_id != robot_id)
					    {
						for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						{
						    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer - k][vv])
						    {
							biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														sIntegerIndex(vv)));
						    }
						}
					    }
					}
				    }
				}
				if (!biangular_Identifiers.empty())
				{
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiBiangleMutex(aux_Variable_cnt,
													    total_Literal_cnt,
													    sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																    sIntegerIndex(neighbor_index)),
													    biangular_Identifiers);
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										 total_Literal_cnt,
										 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													 sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}


	int N_cnf_Variables = encoding_context.m_variable_store.get_Last_CNFVariable() + aux_Variable_cnt - 1;

#ifdef sDEBUG
	fprintf(fw, "c %s : multirobot GMDD SAT encoding\n", sPRODUCT);
	fprintf(fw, "c %s\n", sCOPYRIGHT);
	fprintf(fw, "c number of layers = %d\n", N_Layers);
	fprintf(fw, "c number of visible variables = %d\n", N_cnf_Variables - aux_Variable_cnt);
	fprintf(fw, "c number of hidden variables = %d\n", aux_Variable_cnt);
	fprintf(fw, "c number of literals = %d\n", total_Literal_cnt);
	fprintf(fw, "c number of clauses = %d\n", Clause_cnt);
	fprintf(fw, "c number of propositional variables = %d\n", N_cnf_Variables);
	fprintf(fw, "c number of clauses / number of variables = %.3f\n", (double)Clause_cnt / N_cnf_Variables);
	fprintf(fw, "c number of literals / number of clauses = %.3f\n", (double)total_Literal_cnt /  Clause_cnt);
	to_Stream(fw, "c ");
#endif
	fprintf(fw, "p cnf %d %d\n", N_cnf_Variables, Clause_cnt);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_MultiConjunctiveImplication(fw,
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													     prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	if (!cardinality_Identifiers.empty())
	{
	    Clause_cnt += encoding_context.m_bit_generator->generate_Cardinality(fw, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sVertex::Neighbors_list &Neighbors = m_environment.m_Vertices[MDD[robot_id][layer][u]].m_Neighbors;
			    for (sVertex::Neighbors_list::const_iterator neighbor = Neighbors.begin(); neighbor != Neighbors.end(); ++neighbor)
			    {
				if ((*neighbor)->m_target->m_id == MDD[robot_id][layer + 1][v])
				{
				    if (!(*neighbor)->m_edge->m_Conflicts.empty())
				    {
					sBitClauseGenerator::SpecifiedBitIdentifiers_vector conflict_edge_Identifiers;
				 
					sEdge::Conflicts_vector &Conflicts = (*neighbor)->m_edge->m_Conflicts;
					for (sEdge::Conflicts_vector::const_iterator conflict = Conflicts.begin(); conflict != Conflicts.end(); ++conflict)
					{
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (robot_id != other_robot_id)
						{
						    for (int uu = 0; uu < MDD[other_robot_id][layer].size(); ++uu)
						    {
							int neighbor_index = 0;
							for (int vv = 0; vv < MDD[other_robot_id][layer + 1].size(); ++vv)
							{
							    if (   m_environment.is_Adjacent(MDD[other_robot_id][layer][uu], MDD[other_robot_id][layer + 1][vv])
								|| MDD[other_robot_id][layer][uu] == MDD[other_robot_id][layer + 1][vv])
							    {
								if (   (conflict->m_x_ID == MDD[other_robot_id][layer][uu] && conflict->m_y_ID == MDD[other_robot_id][layer + 1][vv])
								    || (conflict->m_y_ID == MDD[other_robot_id][layer][uu] && conflict->m_x_ID == MDD[other_robot_id][layer + 1][vv]))
								{
								    conflict_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][uu],
																sIntegerIndex(neighbor_index)));
								}
								neighbor_index++;
							    }
							}
						    }
						}
					    }
					}
					Clause_cnt += encoding_context.m_bit_generator->generate_MultiNegativeImplication(fw,
															  sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																		  sIntegerIndex(neighbor_index)),
															  conflict_edge_Identifiers);
				    }
				}
			    }
			    
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															 sIntegerIndex(neighbor_index)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
															 sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
												mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
											    mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
											mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
												mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector biangular_Identifiers;
			    
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.begin();
				     conflict != m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.end(); ++conflict)
				{
				    for (int k = 0; k < m_robustness; ++k)
				    {
					if (layer - k >= 0)
					{
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (other_robot_id != robot_id)
						{
						    for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						    {
							if (*conflict == MDD[other_robot_id][layer - k][vv])
							{
							    biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														    sIntegerIndex(vv)));
							}
						    }
						}
					    }
					}
				    }			    
				}

				for (int k = 0; k < m_robustness; ++k)
				{
				    if (layer - k >= 0)
				    {
					for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					{
					    if (other_robot_id != robot_id)
					    {
						for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						{
						    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer - k][vv])
						    {
							biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														sIntegerIndex(vv)));
						    }
						}
					    }
					}
				    }
				}
				
				if (!biangular_Identifiers.empty())
				{
				    encoding_context.m_bit_generator->generate_MultiBiangleMutex(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															 sIntegerIndex(neighbor_index)),
												 biangular_Identifiers);
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													    sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }


    void sMultirobotInstance::to_Stream_GEMddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const RobotMDD_vector &unified_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int Clause_cnt = 0;
	int aux_Variable_cnt = 0;
	int total_Literal_cnt = 0;

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);
	
	encoding_context.m_unified_vertex_occupancy_by_water_.resize(N_Layers + 1);

	MDDIndices_vector MDD_Indices;
	construct_MDDIndices(MDD, MDD_Indices);

	RobotMDDIndices_vector unified_MDD_Indices;
	construct_MDDIndices(unified_MDD, unified_MDD_Indices);

	for (int layer = 0; layer <= N_Layers; ++layer)
	{
	    sIndexableBitIdentifier unified_vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								       "unified_vertex_occupancy_by_water-" + sInt_32_to_String(layer),
								       sIntegerScope(0, unified_MDD[layer].size() - 1));
	    encoding_context.m_unified_vertex_occupancy_by_water_[layer] = unified_vertex_occupancy_by_water_;
	    encoding_context.register_TranslateIdentifier(encoding_context.m_unified_vertex_occupancy_by_water_[layer]);
	}	
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_MultiConjunctiveImplication(aux_Variable_cnt,
													  total_Literal_cnt,
													  sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													  prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
										      total_Literal_cnt,
										      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
										      sSpecifiedBitIdentifier(&encoding_context.m_unified_vertex_occupancy_by_water_[layer],
													      sIntegerIndex(unified_MDD_Indices[layer][MDD[robot_id][layer][u]])));
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}       
	if (!cardinality_Identifiers.empty())
	{
	    Clause_cnt += encoding_context.m_bit_generator->count_Cardinality(aux_Variable_cnt,total_Literal_cnt, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);

		}
	    }
	}

	encoding_context.m_unified_edge_occupancy_by_water__.resize(N_Layers);	

	for (int layer = 0; layer < N_Layers; ++layer)
	{
	    encoding_context.m_unified_edge_occupancy_by_water__[layer].resize(unified_MDD[layer].size());
	    
	    for (int u = 0; u < unified_MDD[layer].size(); ++u)
	    {
		int N_neighbors = 0;
		
		for (int v = 0; v < unified_MDD[layer + 1].size(); ++v)
		{
		    if (m_environment.is_Adjacent(unified_MDD[layer][u], unified_MDD[layer + 1][v]) || unified_MDD[layer][u] == unified_MDD[layer + 1][v])
		    {
			++N_neighbors;
		    }
		}
		sIndexableBitIdentifier unified_edge_occupancy_by_water__(&encoding_context.m_variable_store,
									  "unified_edge_occupancy_by_water-" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(unified_MDD[layer][u]),
									  sIntegerScope(0, N_neighbors - 1));
		encoding_context.m_unified_edge_occupancy_by_water__[layer][u] = unified_edge_occupancy_by_water__;
		encoding_context.register_TranslateIdentifier(encoding_context.m_unified_edge_occupancy_by_water__[layer][u]);		
	    }
	}	
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sVertex::Neighbors_list &Neighbors = m_environment.m_Vertices[MDD[robot_id][layer][u]].m_Neighbors;
			    for (sVertex::Neighbors_list::const_iterator neighbor = Neighbors.begin(); neighbor != Neighbors.end(); ++neighbor)
			    {				
				if ((*neighbor)->m_target->m_id == MDD[robot_id][layer + 1][v])
				{
				    if (!(*neighbor)->m_edge->m_Conflicts.empty())
				    {
					sBitClauseGenerator::SpecifiedBitIdentifiers_vector conflict_edge_Identifiers;
				 
					sEdge::Conflicts_vector &Conflicts = (*neighbor)->m_edge->m_Conflicts;
					for (sEdge::Conflicts_vector::const_iterator conflict = Conflicts.begin(); conflict != Conflicts.end(); ++conflict)
					{					    
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (robot_id != other_robot_id)
						{
						    for (int uu = 0; uu < MDD[other_robot_id][layer].size(); ++uu)
						    {
							int neighbor_index = 0;
							for (int vv = 0; vv < MDD[other_robot_id][layer + 1].size(); ++vv)
							{
							    if (   m_environment.is_Adjacent(MDD[other_robot_id][layer][uu], MDD[other_robot_id][layer + 1][vv])
								|| MDD[other_robot_id][layer][uu] == MDD[other_robot_id][layer + 1][vv])
							    {
								if (   (conflict->m_x_ID == MDD[other_robot_id][layer][uu] && conflict->m_y_ID == MDD[other_robot_id][layer + 1][vv])
								    || (conflict->m_y_ID == MDD[other_robot_id][layer][uu] && conflict->m_x_ID == MDD[other_robot_id][layer + 1][vv]))
								{
								    conflict_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][uu],
																sIntegerIndex(neighbor_index)));
								}
								neighbor_index++;
							    }
							}
						    }
						}
					    }
					}
					Clause_cnt += encoding_context.m_bit_generator->count_MultiNegativeImplication(aux_Variable_cnt,
														       total_Literal_cnt,
														       sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	       sIntegerIndex(neighbor_index)),
														       conflict_edge_Identifiers);
				    }
				}
			    }
				
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														      sIntegerIndex(neighbor_index)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														      sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
											   total_Literal_cnt,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(u)),
											   mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
											 total_Literal_cnt,
											 mutex_vertex_Identifiers);
	    }
	}

	for (int layer = 0; layer < N_Layers; ++layer)
	{		
	    for (int u = 0; u < unified_MDD[layer].size(); ++u)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector biangular_Identifiers;
		
		for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[unified_MDD[layer][u]].m_Conflicts.begin();
		     conflict != m_environment.m_Vertices[unified_MDD[layer][u]].m_Conflicts.end(); ++conflict)
		{
		    for (int k = 0; k < m_robustness; ++k)
		    {
			if (layer - k >= 0)
			{
			    for (int vv = 0; vv < unified_MDD[layer - k].size(); ++vv)
			    {
				if (*conflict == unified_MDD[layer - k][vv] && *conflict != unified_MDD[layer][u])
				{
				    biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_unified_vertex_occupancy_by_water_[layer - k],
											    sIntegerIndex(vv)));
				}
			    }
			}
		    }
		}
		if (!biangular_Identifiers.empty())
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiBiangleMutex(aux_Variable_cnt,
											    total_Literal_cnt,
											    sSpecifiedBitIdentifier(&encoding_context.m_unified_vertex_occupancy_by_water_[layer],
														    sIntegerIndex(u)),
											    biangular_Identifiers);
		}
	    }
	}

	for (int layer = 0; layer < N_Layers; ++layer)
	{		
	    for (int u = 0; u < unified_MDD[layer].size(); ++u)
	    {
		int neighbor_index = 0;
		for (int v = 0; v < unified_MDD[layer + 1].size(); ++v)
		{
		    if (m_environment.is_Adjacent(unified_MDD[layer][u], unified_MDD[layer + 1][v]) || unified_MDD[layer][u] == unified_MDD[layer + 1][v])
		    {
			sBitClauseGenerator::SpecifiedBitIdentifiers_vector biangular_Identifiers;
			if (unified_MDD[layer][u] != unified_MDD[layer + 1][v])
			{
			    for (int k = 0; k < m_robustness; ++k)
			    {
				if (layer - k >= 0)
				{
				    for (int vv = 0; vv < unified_MDD[layer - k].size(); ++vv)
				    {
					if (unified_MDD[layer + 1][v] == unified_MDD[layer - k][vv])
					{
					    biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_unified_vertex_occupancy_by_water_[layer - k],
												    sIntegerIndex(vv)));
					}
				    }
				}
			    }
			    if (!biangular_Identifiers.empty())
			    {
				Clause_cnt += encoding_context.m_bit_generator->count_MultiBiangleMutex(aux_Variable_cnt,
													total_Literal_cnt,
													sSpecifiedBitIdentifier(&encoding_context.m_unified_edge_occupancy_by_water__[layer][u],
																sIntegerIndex(neighbor_index)),
													biangular_Identifiers);
			    }
			}
			++neighbor_index;
		    }
		}
	    }
	}
	
/*
	for (int layer = 0; layer < N_Layers; ++layer)
	{
	    for (int u = 0; u < unified_MDD[layer].size(); ++u)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;
		
		int neighbor_index = 0;
		for (int v = 0; v < unified_MDD[layer + 1].size(); ++v)
		{
		    if (m_environment.is_Adjacent(unified_MDD[layer][u], unified_MDD[layer + 1][v]) || unified_MDD[layer][u] == unified_MDD[layer + 1][v])
		    {				
			mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_unified_edge_occupancy_by_water__[layer][u], sIntegerIndex(neighbor_index)));
			
			Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											  total_Literal_cnt,
											  sSpecifiedBitIdentifier(&encoding_context.m_unified_edge_occupancy_by_water__[layer][u],
														  sIntegerIndex(neighbor_index)),
											  sSpecifiedBitIdentifier(&encoding_context.m_unified_vertex_occupancy_by_water_[layer + 1],
														  sIntegerIndex(v)));
			neighbor_index++;
		    }
		}		
		Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
										       total_Literal_cnt,
										       sSpecifiedBitIdentifier(&encoding_context.m_unified_vertex_occupancy_by_water_[layer],
													       sIntegerIndex(u)),
										       mutex_target_Identifiers);
		
		Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
											 total_Literal_cnt,
											 mutex_target_Identifiers);   
	    }
	}	
*/

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
										     total_Literal_cnt,
										     mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_occupancy_Identifiers);
		}
	    }
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										 total_Literal_cnt,
										 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													 sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}


	int N_cnf_Variables = encoding_context.m_variable_store.get_Last_CNFVariable() + aux_Variable_cnt - 1;

#ifdef sDEBUG
	fprintf(fw, "c %s : multirobot GEMDD SAT encoding\n", sPRODUCT);
	fprintf(fw, "c %s\n", sCOPYRIGHT);
	fprintf(fw, "c number of layers = %d\n", N_Layers);
	fprintf(fw, "c number of visible variables = %d\n", N_cnf_Variables - aux_Variable_cnt);
	fprintf(fw, "c number of hidden variables = %d\n", aux_Variable_cnt);
	fprintf(fw, "c number of literals = %d\n", total_Literal_cnt);
	fprintf(fw, "c number of clauses = %d\n", Clause_cnt);
	fprintf(fw, "c number of propositional variables = %d\n", N_cnf_Variables);
	fprintf(fw, "c number of clauses / number of variables = %.3f\n", (double)Clause_cnt / N_cnf_Variables);
	fprintf(fw, "c number of literals / number of clauses = %.3f\n", (double)total_Literal_cnt /  Clause_cnt);
	to_Stream(fw, "c ");
#endif
	fprintf(fw, "p cnf %d %d\n", N_cnf_Variables, Clause_cnt);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_MultiConjunctiveImplication(fw,
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													     prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
											 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
											 sSpecifiedBitIdentifier(&encoding_context.m_unified_vertex_occupancy_by_water_[layer],
														 sIntegerIndex(unified_MDD_Indices[layer][MDD[robot_id][layer][u]])));
		}
	    }
	}	
	
	if (!cardinality_Identifiers.empty())
	{
	    Clause_cnt += encoding_context.m_bit_generator->generate_Cardinality(fw, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sVertex::Neighbors_list &Neighbors = m_environment.m_Vertices[MDD[robot_id][layer][u]].m_Neighbors;
			    for (sVertex::Neighbors_list::const_iterator neighbor = Neighbors.begin(); neighbor != Neighbors.end(); ++neighbor)
			    {
				if ((*neighbor)->m_target->m_id == MDD[robot_id][layer + 1][v])
				{
				    if (!(*neighbor)->m_edge->m_Conflicts.empty())
				    {
					sBitClauseGenerator::SpecifiedBitIdentifiers_vector conflict_edge_Identifiers;
				 
					sEdge::Conflicts_vector &Conflicts = (*neighbor)->m_edge->m_Conflicts;
					for (sEdge::Conflicts_vector::const_iterator conflict = Conflicts.begin(); conflict != Conflicts.end(); ++conflict)
					{
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (robot_id != other_robot_id)
						{
						    for (int uu = 0; uu < MDD[other_robot_id][layer].size(); ++uu)
						    {
							int neighbor_index = 0;
							for (int vv = 0; vv < MDD[other_robot_id][layer + 1].size(); ++vv)
							{
							    if (   m_environment.is_Adjacent(MDD[other_robot_id][layer][uu], MDD[other_robot_id][layer + 1][vv])
								|| MDD[other_robot_id][layer][uu] == MDD[other_robot_id][layer + 1][vv])
							    {
								if (   (conflict->m_x_ID == MDD[other_robot_id][layer][uu] && conflict->m_y_ID == MDD[other_robot_id][layer + 1][vv])
								    || (conflict->m_y_ID == MDD[other_robot_id][layer][uu] && conflict->m_x_ID == MDD[other_robot_id][layer + 1][vv]))
								{
								    conflict_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][uu],
																sIntegerIndex(neighbor_index)));
								}
								neighbor_index++;
							    }
							}
						    }
						}
					    }
					}
					Clause_cnt += encoding_context.m_bit_generator->generate_MultiNegativeImplication(fw,
															  sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																		  sIntegerIndex(neighbor_index)),
															  conflict_edge_Identifiers);
				    }
				}
			    }
			    
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															 sIntegerIndex(neighbor_index)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
															 sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
												mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
											    mutex_vertex_Identifiers);
	    }
	}
/*
	for (int layer = 0; layer < N_Layers; ++layer)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
	    
	    for (int u = 0; u < unified_MDD[layer].size(); ++u)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;
		
		int neighbor_index = 0;
		for (int v = 0; v < unified_MDD[layer + 1].size(); ++v)
		{
		    if (m_environment.is_Adjacent(unified_MDD[layer][u], unified_MDD[layer + 1][v]) || unified_MDD[layer][u] == unified_MDD[layer + 1][v])
		    {				
			mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_unified_edge_occupancy_by_water__[layer][u], sIntegerIndex(neighbor_index)));
			
			Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
											     sSpecifiedBitIdentifier(&encoding_context.m_unified_edge_occupancy_by_water__[layer][u],
														     sIntegerIndex(neighbor_index)),
											     sSpecifiedBitIdentifier(&encoding_context.m_unified_vertex_occupancy_by_water_[layer + 1],
														     sIntegerIndex(v)));
			neighbor_index++;
		    }
		}		
		Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
											  sSpecifiedBitIdentifier(&encoding_context.m_unified_vertex_occupancy_by_water_[layer],
														  sIntegerIndex(u)),
											  mutex_target_Identifiers);
		Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
											    mutex_target_Identifiers);   
	    }
	}		
*/
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
											mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
												mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int layer = 0; layer < N_Layers; ++layer)
	{		
	    for (int u = 0; u < unified_MDD[layer].size(); ++u)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector biangular_Identifiers;
		
		for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[unified_MDD[layer][u]].m_Conflicts.begin();
		     conflict != m_environment.m_Vertices[unified_MDD[layer][u]].m_Conflicts.end(); ++conflict)
		{
		    for (int k = 0; k < m_robustness; ++k)
		    {
			if (layer - k >= 0)
			{
			    for (int vv = 0; vv < unified_MDD[layer - k].size(); ++vv)
			    {
				if (*conflict == unified_MDD[layer - k][vv] && *conflict != unified_MDD[layer][u])
				{
				    biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_unified_vertex_occupancy_by_water_[layer - k],
											    sIntegerIndex(vv)));
				}
			    }
			}
		    }
		}
		if (!biangular_Identifiers.empty())
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiBiangleMutex(fw,
											       sSpecifiedBitIdentifier(&encoding_context.m_unified_vertex_occupancy_by_water_[layer],
														       sIntegerIndex(u)),
											       biangular_Identifiers);
		}
	    }
	}

	for (int layer = 0; layer < N_Layers; ++layer)
	{		
	    for (int u = 0; u < unified_MDD[layer].size(); ++u)
	    {
		int neighbor_index = 0;
		for (int v = 0; v < unified_MDD[layer + 1].size(); ++v)
		{
		    if (m_environment.is_Adjacent(unified_MDD[layer][u], unified_MDD[layer + 1][v]) || unified_MDD[layer][u] == unified_MDD[layer + 1][v])
		    {
			sBitClauseGenerator::SpecifiedBitIdentifiers_vector biangular_Identifiers;
			if (unified_MDD[layer][u] != unified_MDD[layer + 1][v])
			{
			    for (int k = 0; k < m_robustness; ++k)
			    {
				if (layer - k >= 0)
				{
				    for (int vv = 0; vv < unified_MDD[layer - k].size(); ++vv)
				    {
					if (unified_MDD[layer + 1][v] == unified_MDD[layer - k][vv])
					{
					    biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_unified_vertex_occupancy_by_water_[layer - k],
												    sIntegerIndex(vv)));
					}
				    }
				}
			    }
			    if (!biangular_Identifiers.empty())
			    {
				Clause_cnt += encoding_context.m_bit_generator->generate_MultiBiangleMutex(fw,
													   sSpecifiedBitIdentifier(&encoding_context.m_unified_edge_occupancy_by_water__[layer][u],
																   sIntegerIndex(neighbor_index)),
													   biangular_Identifiers);
			    }
			}
			++neighbor_index;
		    }
		}
	    }
	}
	

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													    sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }        


    void sMultirobotInstance::to_Memory_MddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			encoding_context.m_bit_generator->cast_MultiConjunctiveImplication(solver,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
											   prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}       
	if (!cardinality_Identifiers.empty())
	{
	    encoding_context.m_bit_generator->cast_Cardinality(solver, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);

		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
												       sIntegerIndex(neighbor_index)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
												       sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    encoding_context.m_bit_generator->cast_MultiImplication(solver,
									    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
												    sIntegerIndex(u)),
									    mutex_target_Identifiers);

		    encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
									      mutex_target_Identifiers);   
		}
		encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
									  mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
								      mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
									      mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{		    
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector biangular_Identifiers;
		    
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.begin();
				     conflict != m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.end(); ++conflict)
				{
				    for (int k = 0; k < m_robustness; ++k)
				    {
					if (layer - k >= 0)
					{
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (other_robot_id != robot_id)
						{
						    for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						    {
							if (*conflict == MDD[other_robot_id][layer - k][vv])
							{
							    biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														    sIntegerIndex(vv)));
							}
						    }
						}
					    }
					}
				    }				    
				}

				for (int k = 0; k < m_robustness; ++k)
				{
				    if (layer - k >= 0)
				    {
					for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					{
					    if (other_robot_id != robot_id)
					    {
						for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						{
						    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer - k][vv])
						    {
							biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														sIntegerIndex(vv)));
						    }
						}
					    }
					}
				    }
				}
				if (!biangular_Identifiers.empty())
				{
				    encoding_context.m_bit_generator->cast_MultiBiangleMutex(solver,
											     sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														     sIntegerIndex(neighbor_index)),
											     biangular_Identifiers);
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    encoding_context.m_bit_generator->cast_BitSet(solver,
								  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
											  sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }


    void sMultirobotInstance::to_Memory_MddUmtexCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	MDDMutexes_vector Mutexes;
	Mutexes.resize(N_Robots + 1);

	InverseMDD_vector inverse_MDD;
	construct_InverseMDD(N_Vertices, MDD, inverse_MDD);			

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);

	    Mutexes[robot_id].resize(N_Layers + 1);
	    
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			encoding_context.m_bit_generator->cast_MultiConjunctiveImplication(solver,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
											   prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}       
	if (!cardinality_Identifiers.empty())
	{
	    encoding_context.m_bit_generator->cast_Cardinality(solver, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);

		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
												       sIntegerIndex(neighbor_index)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
												       sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    encoding_context.m_bit_generator->cast_MultiImplication(solver,
									    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
												    sIntegerIndex(u)),
									    mutex_target_Identifiers);

		    encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
									      mutex_target_Identifiers);   
		}
		encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
									  mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
								      mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
									      mutex_occupancy_Identifiers);
		}
	    }
	}


	ScheduledMTXs_list scheduled_Mutexes;

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{	   
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
		{
		    if (other_robot_id < robot_id)
		    {
			for (int uu = 0; uu < MDD[robot_id][layer].size(); ++uu)
			{
			    int uu_mdd_idx = inverse_MDD[other_robot_id][layer][MDD[robot_id][layer][uu]];
			    
			    if (uu_mdd_idx >= 0)
			    {
				scheduled_Mutexes.push_back(ScheduledMTX(layer, MTX_pair(MTX(robot_id, MDD[robot_id][layer][uu]), MTX(other_robot_id, MDD[other_robot_id][layer][uu_mdd_idx]))));
			    }
			}
		    }
		}
	    }
	}

	std::vector<VertexIDs_vector> vertex_neighbor_IDs;
	vertex_neighbor_IDs.resize(N_Vertices);

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    sVertex::Neighbors_list &vertex_Neighbors = m_environment.m_Vertices[vertex_id].m_Neighbors;
	    for (sVertex::Neighbors_list::const_iterator vertex_neighbor = vertex_Neighbors.begin(); vertex_neighbor != vertex_Neighbors.end(); ++vertex_neighbor)
	    {
		vertex_neighbor_IDs[vertex_id].push_back((*vertex_neighbor)->m_target->m_id);
	    }
	    vertex_neighbor_IDs[vertex_id].push_back(vertex_id);	    
	}

	while (!scheduled_Mutexes.empty())
	{
	    const ScheduledMTX &scheduled_MTX = scheduled_Mutexes.front();	    
	    
	    int vertex_u_id = scheduled_MTX.m_mtx.first.m_vertex_id;
	    int vertex_w_id = scheduled_MTX.m_mtx.second.m_vertex_id;

	    int robot_id = scheduled_MTX.m_mtx.first.m_robot_id;
	    int other_robot_id = scheduled_MTX.m_mtx.second.m_robot_id;

	    int layer = scheduled_MTX.m_layer;
	    
	    if (layer < N_Layers)
	    {
		/*
		sVertex::Neighbors_list &u_Neighbors = m_environment.m_Vertices[vertex_u_id].m_Neighbors;
		VertexIDs_vector u_neighbor_IDs;
		for (sVertex::Neighbors_list::const_iterator u_neighbor = u_Neighbors.begin(); u_neighbor != u_Neighbors.end(); ++u_neighbor)
		{
		    u_neighbor_IDs.push_back((*u_neighbor)->m_target->m_id);
		}
		u_neighbor_IDs.push_back(vertex_u_id);
		
		sVertex::Neighbors_list &w_Neighbors = m_environment.m_Vertices[vertex_w_id].m_Neighbors;
		VertexIDs_vector w_neighbor_IDs;
		for (sVertex::Neighbors_list::const_iterator w_neighbor = w_Neighbors.begin(); w_neighbor != w_Neighbors.end(); ++w_neighbor)
		{
		    w_neighbor_IDs.push_back((*w_neighbor)->m_target->m_id);
		}
		w_neighbor_IDs.push_back(vertex_w_id);
		*/
		
		for (VertexIDs_vector::const_iterator v_neighbor = vertex_neighbor_IDs[vertex_u_id].begin(); v_neighbor != vertex_neighbor_IDs[vertex_u_id].end(); ++v_neighbor)
		{
		    sInt_32 v_mdd_idx = inverse_MDD[robot_id][layer + 1][(*v_neighbor)];
						    
		    if (v_mdd_idx >= 0)
		    {
			for (VertexIDs_vector::const_iterator z_neighbor = vertex_neighbor_IDs[vertex_w_id].begin(); z_neighbor != vertex_neighbor_IDs[vertex_w_id].end(); ++z_neighbor)
			{
			    sInt_32 z_mdd_idx = inverse_MDD[other_robot_id][layer + 1][(*z_neighbor)];
			    
			    if (z_mdd_idx >= 0)
			    {			    			    
				if (*v_neighbor < *z_neighbor)
				{
				    int vertex_v_id = *v_neighbor;
				    int vertex_z_id = *z_neighbor;

				    bool all_mutex = true;

				    /*
				    sVertex::Neighbors_list &v_Neighbors = m_environment.m_Vertices[vertex_v_id].m_Neighbors;
				    VertexIDs_vector v_neighbor_IDs;
				    for (sVertex::Neighbors_list::const_iterator v_neighbor = v_Neighbors.begin(); v_neighbor != v_Neighbors.end(); ++v_neighbor)
				    {
					v_neighbor_IDs.push_back((*v_neighbor)->m_target->m_id);
				    }
				    v_neighbor_IDs.push_back(vertex_v_id);
				    */
				    
				    for (VertexIDs_vector::const_iterator v_neighbor = vertex_neighbor_IDs[vertex_v_id].begin(); v_neighbor != vertex_neighbor_IDs[vertex_v_id].end(); ++v_neighbor)
				    {
					sInt_32 u_mdd_idx = inverse_MDD[robot_id][layer][(*v_neighbor)];
					
					if (u_mdd_idx >= 0)
					{
					    bool u_all_mutex = true;

					    /*
					    sVertex::Neighbors_list &z_Neighbors = m_environment.m_Vertices[vertex_z_id].m_Neighbors;
					    VertexIDs_vector z_neighbor_IDs;
					    for (sVertex::Neighbors_list::const_iterator z_neighbor = z_Neighbors.begin(); z_neighbor != z_Neighbors.end(); ++z_neighbor)
					    {
						z_neighbor_IDs.push_back((*z_neighbor)->m_target->m_id);
					    }
					    z_neighbor_IDs.push_back(vertex_z_id);
					    */
					    
					    for (VertexIDs_vector::const_iterator z_neighbor = vertex_neighbor_IDs[vertex_z_id].begin(); z_neighbor != vertex_neighbor_IDs[vertex_z_id].end(); ++z_neighbor)
					    {
						sInt_32 w_mdd_idx = inverse_MDD[other_robot_id][layer][(*z_neighbor)];
						
						if (w_mdd_idx >= 0)
						{
						    bool mutex_found = false;						
						    
						    if (MDD[robot_id][layer][u_mdd_idx] == MDD[other_robot_id][layer][w_mdd_idx])
						    {
							mutex_found = true;
						    }
						    else
						    {
							VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].find(MDD[robot_id][layer][u_mdd_idx]);
							
							if (mutexes_u != Mutexes[robot_id][layer].end())
							{
							    for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
							    {
								if (mutex_u->m_robot_id == other_robot_id && mutex_u->m_vertex_id == MDD[other_robot_id][layer][w_mdd_idx])
								{
								    mutex_found = true;
								    break;
								}
							    }
							}
						    }
						    if (!mutex_found)
						    {
							u_all_mutex = false;
							break;
						    }
						}
					    }
					    if (!u_all_mutex)
					    {
						all_mutex = false;
						break;
					    }
					}
				    }				    
				    if (all_mutex)
				    {
					bool next_first_mutex = Mutexes[robot_id][layer + 1][vertex_v_id].insert(Mutex(other_robot_id, vertex_z_id, z_mdd_idx, v_mdd_idx)).second;
					bool next_second_mutex = Mutexes[other_robot_id][layer + 1][vertex_z_id].insert(Mutex(robot_id, vertex_v_id, v_mdd_idx, z_mdd_idx)).second;

					if (next_first_mutex || next_second_mutex)
					{
					    scheduled_Mutexes.push_back(ScheduledMTX(layer + 1, MTX_pair(MTX(robot_id, vertex_v_id), MTX(other_robot_id, vertex_z_id))));
					}
				    }
				}	    
			    }
			}
		    }
		}
	    }
	    
	    if (layer > 0)
	    {
		/*
		sVertex::Neighbors_list &u_Neighbors = m_environment.m_Vertices[vertex_u_id].m_Neighbors;
		VertexIDs_vector u_neighbor_IDs;
		for (sVertex::Neighbors_list::const_iterator u_neighbor = u_Neighbors.begin(); u_neighbor != u_Neighbors.end(); ++u_neighbor)
		{
		    u_neighbor_IDs.push_back((*u_neighbor)->m_target->m_id);
		}
		u_neighbor_IDs.push_back(vertex_u_id);
		
		sVertex::Neighbors_list &w_Neighbors = m_environment.m_Vertices[vertex_w_id].m_Neighbors;
		VertexIDs_vector w_neighbor_IDs;
		for (sVertex::Neighbors_list::const_iterator w_neighbor = w_Neighbors.begin(); w_neighbor != w_Neighbors.end(); ++w_neighbor)
		{
		    w_neighbor_IDs.push_back((*w_neighbor)->m_target->m_id);
		}
		w_neighbor_IDs.push_back(vertex_w_id);
		*/
		
		for (VertexIDs_vector::const_iterator v_neighbor = vertex_neighbor_IDs[vertex_u_id].begin(); v_neighbor != vertex_neighbor_IDs[vertex_u_id].end(); ++v_neighbor)
		{
		    sInt_32 v_mdd_idx = inverse_MDD[robot_id][layer - 1][(*v_neighbor)];
						    
		    if (v_mdd_idx >= 0)
		    {
			for (VertexIDs_vector::const_iterator z_neighbor = vertex_neighbor_IDs[vertex_w_id].begin(); z_neighbor != vertex_neighbor_IDs[vertex_w_id].end(); ++z_neighbor)
			{
			    sInt_32 z_mdd_idx = inverse_MDD[other_robot_id][layer - 1][(*z_neighbor)];
			    
			    if (z_mdd_idx >= 0)
			    {			    			    
				if (*v_neighbor < *z_neighbor)
				{
				    int vertex_v_id = *v_neighbor;
				    int vertex_z_id = *z_neighbor;

				    bool all_mutex = true;

				    /*
				    sVertex::Neighbors_list &v_Neighbors = m_environment.m_Vertices[vertex_v_id].m_Neighbors;
				    VertexIDs_vector v_neighbor_IDs;
				    for (sVertex::Neighbors_list::const_iterator v_neighbor = v_Neighbors.begin(); v_neighbor != v_Neighbors.end(); ++v_neighbor)
				    {
					v_neighbor_IDs.push_back((*v_neighbor)->m_target->m_id);
				    }
				    v_neighbor_IDs.push_back(vertex_v_id);
				    */
				    
				    for (VertexIDs_vector::const_iterator v_neighbor = vertex_neighbor_IDs[vertex_v_id].begin(); v_neighbor != vertex_neighbor_IDs[vertex_v_id].end(); ++v_neighbor)
				    {
					sInt_32 u_mdd_idx = inverse_MDD[robot_id][layer][(*v_neighbor)];
					
					if (u_mdd_idx >= 0)
					{
					    bool u_all_mutex = true;

					    /*
					    sVertex::Neighbors_list &z_Neighbors = m_environment.m_Vertices[vertex_z_id].m_Neighbors;
					    VertexIDs_vector z_neighbor_IDs;
					    for (sVertex::Neighbors_list::const_iterator z_neighbor = z_Neighbors.begin(); z_neighbor != z_Neighbors.end(); ++z_neighbor)
					    {
						z_neighbor_IDs.push_back((*z_neighbor)->m_target->m_id);
					    }
					    z_neighbor_IDs.push_back(vertex_z_id);
					    */
					    
					    for (VertexIDs_vector::const_iterator z_neighbor = vertex_neighbor_IDs[vertex_z_id].begin(); z_neighbor != vertex_neighbor_IDs[vertex_z_id].end(); ++z_neighbor)
					    {
						sInt_32 w_mdd_idx = inverse_MDD[other_robot_id][layer][(*z_neighbor)];
						
						if (w_mdd_idx >= 0)
						{
						    bool mutex_found = false;						
						    
						    if (MDD[robot_id][layer][u_mdd_idx] == MDD[other_robot_id][layer][w_mdd_idx])
						    {
							mutex_found = true;
						    }
						    else
						    {
							VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].find(MDD[robot_id][layer][u_mdd_idx]);
							
							if (mutexes_u != Mutexes[robot_id][layer].end())
							{
							    for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
							    {
								if (mutex_u->m_robot_id == other_robot_id && mutex_u->m_vertex_id == MDD[other_robot_id][layer][w_mdd_idx])
								{
								    mutex_found = true;
								    break;
								}
							    }
							}
						    }
						    if (!mutex_found)
						    {
							u_all_mutex = false;
							break;
						    }
						}
					    }
					    if (!u_all_mutex)
					    {
						all_mutex = false;
						break;
					    }
					}
				    }				    
				    if (all_mutex)
				    {
					bool next_first_mutex = Mutexes[robot_id][layer - 1][vertex_v_id].insert(Mutex(other_robot_id, vertex_z_id, z_mdd_idx, v_mdd_idx)).second;
					bool next_second_mutex = Mutexes[other_robot_id][layer - 1][vertex_z_id].insert(Mutex(robot_id, vertex_v_id, v_mdd_idx, z_mdd_idx)).second;

					if (next_first_mutex || next_second_mutex)
					{
					    scheduled_Mutexes.push_back(ScheduledMTX(layer - 1, MTX_pair(MTX(robot_id, vertex_v_id), MTX(other_robot_id, vertex_z_id))));
					}
				    }
				}	    
			    }
			}
		    }		    
		}
	    }
	    scheduled_Mutexes.pop_front();
	}
//	printf("Now pre-summarizing ...\n");
	int N_mutexes = 0;
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{	    
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		for (VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].begin(); mutexes_u != Mutexes[robot_id][layer].end(); ++mutexes_u)
		{
		    int vertex_u_id = mutexes_u->first;

		    for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
		    {			
			int vertex_v_id = mutex_u->m_vertex_id;
			/*
			int vertex_v_idx = mutex_u->m_mdd_idx;
			int vertex_u_idx = mutex_u->m_mdd_other_idx;			
			int other_robot_id = mutex_u->m_robot_id;
			*/
			
			if (vertex_u_id < vertex_v_id)
			{
			    /*
			    encoding_context.m_bit_generator->cast_Mutex(solver,
									 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
												 sIntegerIndex(vertex_u_idx)),
									 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
												 sIntegerIndex(vertex_v_idx)));
			    */
//			    printf(" 	 Mutex: at level %d - [%d, %d (%d)] x [%d, %d (%d)]\n", layer, robot_id, vertex_u_id, vertex_u_idx, other_robot_id, vertex_v_id, vertex_v_idx);
			    ++N_mutexes;
			}
		    }
		}
	    }
	}		

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{		    
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector biangular_Identifiers;
		    
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.begin();
				     conflict != m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.end(); ++conflict)
				{
				    for (int k = 0; k < m_robustness; ++k)
				    {
					if (layer - k >= 0)
					{
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (other_robot_id != robot_id)
						{
						    for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						    {
							if (*conflict == MDD[other_robot_id][layer - k][vv])
							{
							    biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														    sIntegerIndex(vv)));
							}
						    }
						}
					    }
					}
				    }				    
				}

				for (int k = 0; k < m_robustness; ++k)
				{
				    if (layer - k >= 0)
				    {
					for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					{
					    if (other_robot_id != robot_id)
					    {
						for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						{
						    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer - k][vv])
						    {
							biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														sIntegerIndex(vv)));
						    }
						}
					    }
					}
				    }
				}
				if (!biangular_Identifiers.empty())
				{
				    encoding_context.m_bit_generator->cast_MultiBiangleMutex(solver,
											     sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														     sIntegerIndex(neighbor_index)),
											     biangular_Identifiers);
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    encoding_context.m_bit_generator->cast_BitSet(solver,
								  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
											  sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }    


    void sMultirobotInstance::to_Memory_MddMutexCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	MDDMutexes_vector Mutexes;
	Mutexes.resize(N_Robots + 1);

	InverseMDD_vector inverse_MDD;
	construct_InverseMDD(N_Vertices, MDD, inverse_MDD);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);

	    Mutexes[robot_id].resize(N_Layers + 1);
	    
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			encoding_context.m_bit_generator->cast_MultiConjunctiveImplication(solver,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
											   prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}       
	if (!cardinality_Identifiers.empty())
	{
	    encoding_context.m_bit_generator->cast_Cardinality(solver, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);

		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
												       sIntegerIndex(neighbor_index)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
												       sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    encoding_context.m_bit_generator->cast_MultiImplication(solver,
									    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
												    sIntegerIndex(u)),
									    mutex_target_Identifiers);

		    encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
									      mutex_target_Identifiers);   
		}
		encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
									  mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
								      mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
									      mutex_occupancy_Identifiers);
		}
	    }
	}


	ScheduledMTXs_list scheduled_Mutexes;

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{	   
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
		{
		    if (other_robot_id < robot_id)
		    {
			for (int uu = 0; uu < MDD[robot_id][layer].size(); ++uu)
			{
			    int uu_mdd_idx = inverse_MDD[other_robot_id][layer][MDD[robot_id][layer][uu]];
			    
			    if (uu_mdd_idx >= 0)
			    {
				scheduled_Mutexes.push_back(ScheduledMTX(layer, MTX_pair(MTX(robot_id, MDD[robot_id][layer][uu]), MTX(other_robot_id, MDD[other_robot_id][layer][uu_mdd_idx]))));
			    }
			}
		    }
		}
	    }
	}

	std::vector<VertexIDs_vector> vertex_neighbor_IDs;
	vertex_neighbor_IDs.resize(N_Vertices);

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    sVertex::Neighbors_list &vertex_Neighbors = m_environment.m_Vertices[vertex_id].m_Neighbors;
	    for (sVertex::Neighbors_list::const_iterator vertex_neighbor = vertex_Neighbors.begin(); vertex_neighbor != vertex_Neighbors.end(); ++vertex_neighbor)
	    {
		vertex_neighbor_IDs[vertex_id].push_back((*vertex_neighbor)->m_target->m_id);
	    }
	    vertex_neighbor_IDs[vertex_id].push_back(vertex_id);	    
	}

	while (!scheduled_Mutexes.empty())
	{
	    const ScheduledMTX &scheduled_MTX = scheduled_Mutexes.front();	    
	    
	    int vertex_u_id = scheduled_MTX.m_mtx.first.m_vertex_id;
	    int vertex_w_id = scheduled_MTX.m_mtx.second.m_vertex_id;

	    int robot_id = scheduled_MTX.m_mtx.first.m_robot_id;
	    int other_robot_id = scheduled_MTX.m_mtx.second.m_robot_id;

	    int layer = scheduled_MTX.m_layer;
	    
	    if (layer < N_Layers)
	    {
		/*
		sVertex::Neighbors_list &u_Neighbors = m_environment.m_Vertices[vertex_u_id].m_Neighbors;
		VertexIDs_vector u_neighbor_IDs;
		for (sVertex::Neighbors_list::const_iterator u_neighbor = u_Neighbors.begin(); u_neighbor != u_Neighbors.end(); ++u_neighbor)
		{
		    u_neighbor_IDs.push_back((*u_neighbor)->m_target->m_id);
		}
		u_neighbor_IDs.push_back(vertex_u_id);
		
		sVertex::Neighbors_list &w_Neighbors = m_environment.m_Vertices[vertex_w_id].m_Neighbors;
		VertexIDs_vector w_neighbor_IDs;
		for (sVertex::Neighbors_list::const_iterator w_neighbor = w_Neighbors.begin(); w_neighbor != w_Neighbors.end(); ++w_neighbor)
		{
		    w_neighbor_IDs.push_back((*w_neighbor)->m_target->m_id);
		}
		w_neighbor_IDs.push_back(vertex_w_id);
		*/
		
		for (VertexIDs_vector::const_iterator v_neighbor = vertex_neighbor_IDs[vertex_u_id].begin(); v_neighbor != vertex_neighbor_IDs[vertex_u_id].end(); ++v_neighbor)
		{
		    sInt_32 v_mdd_idx = inverse_MDD[robot_id][layer + 1][(*v_neighbor)];
						    
		    if (v_mdd_idx >= 0)
		    {
			for (VertexIDs_vector::const_iterator z_neighbor = vertex_neighbor_IDs[vertex_w_id].begin(); z_neighbor != vertex_neighbor_IDs[vertex_w_id].end(); ++z_neighbor)
			{
			    sInt_32 z_mdd_idx = inverse_MDD[other_robot_id][layer + 1][(*z_neighbor)];
			    
			    if (z_mdd_idx >= 0)
			    {			    			    
				if (*v_neighbor < *z_neighbor)
				{
				    int vertex_v_id = *v_neighbor;
				    int vertex_z_id = *z_neighbor;

				    bool all_mutex = true;

				    /*
				    sVertex::Neighbors_list &v_Neighbors = m_environment.m_Vertices[vertex_v_id].m_Neighbors;
				    VertexIDs_vector v_neighbor_IDs;
				    for (sVertex::Neighbors_list::const_iterator v_neighbor = v_Neighbors.begin(); v_neighbor != v_Neighbors.end(); ++v_neighbor)
				    {
					v_neighbor_IDs.push_back((*v_neighbor)->m_target->m_id);
				    }
				    v_neighbor_IDs.push_back(vertex_v_id);
				    */
				    
				    for (VertexIDs_vector::const_iterator v_neighbor = vertex_neighbor_IDs[vertex_v_id].begin(); v_neighbor != vertex_neighbor_IDs[vertex_v_id].end(); ++v_neighbor)
				    {
					sInt_32 u_mdd_idx = inverse_MDD[robot_id][layer][(*v_neighbor)];
					
					if (u_mdd_idx >= 0)
					{
					    bool u_all_mutex = true;

					    /*
					    sVertex::Neighbors_list &z_Neighbors = m_environment.m_Vertices[vertex_z_id].m_Neighbors;
					    VertexIDs_vector z_neighbor_IDs;
					    for (sVertex::Neighbors_list::const_iterator z_neighbor = z_Neighbors.begin(); z_neighbor != z_Neighbors.end(); ++z_neighbor)
					    {
						z_neighbor_IDs.push_back((*z_neighbor)->m_target->m_id);
					    }
					    z_neighbor_IDs.push_back(vertex_z_id);
					    */
					    
					    for (VertexIDs_vector::const_iterator z_neighbor = vertex_neighbor_IDs[vertex_z_id].begin(); z_neighbor != vertex_neighbor_IDs[vertex_z_id].end(); ++z_neighbor)
					    {
						sInt_32 w_mdd_idx = inverse_MDD[other_robot_id][layer][(*z_neighbor)];
						
						if (w_mdd_idx >= 0)
						{
						    bool mutex_found = false;						
						    
						    if (MDD[robot_id][layer][u_mdd_idx] == MDD[other_robot_id][layer][w_mdd_idx])
						    {
							mutex_found = true;
						    }
						    else
						    {
							VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].find(MDD[robot_id][layer][u_mdd_idx]);
							
							if (mutexes_u != Mutexes[robot_id][layer].end())
							{
							    for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
							    {
								if (mutex_u->m_robot_id == other_robot_id && mutex_u->m_vertex_id == MDD[other_robot_id][layer][w_mdd_idx])
								{
								    mutex_found = true;
								    break;
								}
							    }
							}
						    }
						    if (!mutex_found)
						    {
							u_all_mutex = false;
							break;
						    }
						}
					    }
					    if (!u_all_mutex)
					    {
						all_mutex = false;
						break;
					    }
					}
				    }				    
				    if (all_mutex)
				    {
					bool next_first_mutex = Mutexes[robot_id][layer + 1][vertex_v_id].insert(Mutex(other_robot_id, vertex_z_id, z_mdd_idx, v_mdd_idx)).second;
					bool next_second_mutex = Mutexes[other_robot_id][layer + 1][vertex_z_id].insert(Mutex(robot_id, vertex_v_id, v_mdd_idx, z_mdd_idx)).second;

					if (next_first_mutex || next_second_mutex)
					{
					    scheduled_Mutexes.push_back(ScheduledMTX(layer + 1, MTX_pair(MTX(robot_id, vertex_v_id), MTX(other_robot_id, vertex_z_id))));
					}
				    }
				}	    
			    }
			}
		    }
		}
	    }
	    
	    if (layer > 0)
	    {
		/*
		sVertex::Neighbors_list &u_Neighbors = m_environment.m_Vertices[vertex_u_id].m_Neighbors;
		VertexIDs_vector u_neighbor_IDs;
		for (sVertex::Neighbors_list::const_iterator u_neighbor = u_Neighbors.begin(); u_neighbor != u_Neighbors.end(); ++u_neighbor)
		{
		    u_neighbor_IDs.push_back((*u_neighbor)->m_target->m_id);
		}
		u_neighbor_IDs.push_back(vertex_u_id);
		
		sVertex::Neighbors_list &w_Neighbors = m_environment.m_Vertices[vertex_w_id].m_Neighbors;
		VertexIDs_vector w_neighbor_IDs;
		for (sVertex::Neighbors_list::const_iterator w_neighbor = w_Neighbors.begin(); w_neighbor != w_Neighbors.end(); ++w_neighbor)
		{
		    w_neighbor_IDs.push_back((*w_neighbor)->m_target->m_id);
		}
		w_neighbor_IDs.push_back(vertex_w_id);
		*/
		
		for (VertexIDs_vector::const_iterator v_neighbor = vertex_neighbor_IDs[vertex_u_id].begin(); v_neighbor != vertex_neighbor_IDs[vertex_u_id].end(); ++v_neighbor)
		{
		    sInt_32 v_mdd_idx = inverse_MDD[robot_id][layer - 1][(*v_neighbor)];
						    
		    if (v_mdd_idx >= 0)
		    {
			for (VertexIDs_vector::const_iterator z_neighbor = vertex_neighbor_IDs[vertex_w_id].begin(); z_neighbor != vertex_neighbor_IDs[vertex_w_id].end(); ++z_neighbor)
			{
			    sInt_32 z_mdd_idx = inverse_MDD[other_robot_id][layer - 1][(*z_neighbor)];
			    
			    if (z_mdd_idx >= 0)
			    {			    			    
				if (*v_neighbor < *z_neighbor)
				{
				    int vertex_v_id = *v_neighbor;
				    int vertex_z_id = *z_neighbor;

				    bool all_mutex = true;

				    /*
				    sVertex::Neighbors_list &v_Neighbors = m_environment.m_Vertices[vertex_v_id].m_Neighbors;
				    VertexIDs_vector v_neighbor_IDs;
				    for (sVertex::Neighbors_list::const_iterator v_neighbor = v_Neighbors.begin(); v_neighbor != v_Neighbors.end(); ++v_neighbor)
				    {
					v_neighbor_IDs.push_back((*v_neighbor)->m_target->m_id);
				    }
				    v_neighbor_IDs.push_back(vertex_v_id);
				    */
				    
				    for (VertexIDs_vector::const_iterator v_neighbor = vertex_neighbor_IDs[vertex_v_id].begin(); v_neighbor != vertex_neighbor_IDs[vertex_v_id].end(); ++v_neighbor)
				    {
					sInt_32 u_mdd_idx = inverse_MDD[robot_id][layer][(*v_neighbor)];
					
					if (u_mdd_idx >= 0)
					{
					    bool u_all_mutex = true;

					    /*
					    sVertex::Neighbors_list &z_Neighbors = m_environment.m_Vertices[vertex_z_id].m_Neighbors;
					    VertexIDs_vector z_neighbor_IDs;
					    for (sVertex::Neighbors_list::const_iterator z_neighbor = z_Neighbors.begin(); z_neighbor != z_Neighbors.end(); ++z_neighbor)
					    {
						z_neighbor_IDs.push_back((*z_neighbor)->m_target->m_id);
					    }
					    z_neighbor_IDs.push_back(vertex_z_id);
					    */
					    
					    for (VertexIDs_vector::const_iterator z_neighbor = vertex_neighbor_IDs[vertex_z_id].begin(); z_neighbor != vertex_neighbor_IDs[vertex_z_id].end(); ++z_neighbor)
					    {
						sInt_32 w_mdd_idx = inverse_MDD[other_robot_id][layer][(*z_neighbor)];
						
						if (w_mdd_idx >= 0)
						{
						    bool mutex_found = false;						
						    
						    if (MDD[robot_id][layer][u_mdd_idx] == MDD[other_robot_id][layer][w_mdd_idx])
						    {
							mutex_found = true;
						    }
						    else
						    {
							VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].find(MDD[robot_id][layer][u_mdd_idx]);
							
							if (mutexes_u != Mutexes[robot_id][layer].end())
							{
							    for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
							    {
								if (mutex_u->m_robot_id == other_robot_id && mutex_u->m_vertex_id == MDD[other_robot_id][layer][w_mdd_idx])
								{
								    mutex_found = true;
								    break;
								}
							    }
							}
						    }
						    if (!mutex_found)
						    {
							u_all_mutex = false;
							break;
						    }
						}
					    }
					    if (!u_all_mutex)
					    {
						all_mutex = false;
						break;
					    }
					}
				    }				    
				    if (all_mutex)
				    {
					bool next_first_mutex = Mutexes[robot_id][layer - 1][vertex_v_id].insert(Mutex(other_robot_id, vertex_z_id, z_mdd_idx, v_mdd_idx)).second;
					bool next_second_mutex = Mutexes[other_robot_id][layer - 1][vertex_z_id].insert(Mutex(robot_id, vertex_v_id, v_mdd_idx, z_mdd_idx)).second;

					if (next_first_mutex || next_second_mutex)
					{
					    scheduled_Mutexes.push_back(ScheduledMTX(layer - 1, MTX_pair(MTX(robot_id, vertex_v_id), MTX(other_robot_id, vertex_z_id))));
					}
				    }
				}	    
			    }
			}
		    }		    
		}
	    }
	    scheduled_Mutexes.pop_front();
	}
//	printf("Now pre-summarizing ...\n");
	int N_mutexes = 0;
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{	    
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		for (VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].begin(); mutexes_u != Mutexes[robot_id][layer].end(); ++mutexes_u)
		{
		    int vertex_u_id = mutexes_u->first;

		    for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
		    {			
			int vertex_v_id = mutex_u->m_vertex_id;
			int vertex_v_idx = mutex_u->m_mdd_idx;
			int vertex_u_idx = mutex_u->m_mdd_other_idx;			
			int other_robot_id = mutex_u->m_robot_id;
			
			if (vertex_u_id < vertex_v_id)
			{
			    encoding_context.m_bit_generator->cast_Mutex(solver,
									 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
												 sIntegerIndex(vertex_u_idx)),
									 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
												 sIntegerIndex(vertex_v_idx)));
//			    printf(" 	 Mutex: at level %d - [%d, %d (%d)] x [%d, %d (%d)]\n", layer, robot_id, vertex_u_id, vertex_u_idx, other_robot_id, vertex_v_id, vertex_v_idx);
			    ++N_mutexes;
			}
		    }
		}
	    }
	}		

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{		    
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector biangular_Identifiers;
		    
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.begin();
				     conflict != m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.end(); ++conflict)
				{
				    for (int k = 0; k < m_robustness; ++k)
				    {
					if (layer - k >= 0)
					{
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (other_robot_id != robot_id)
						{
						    for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						    {
							if (*conflict == MDD[other_robot_id][layer - k][vv])
							{
							    biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														    sIntegerIndex(vv)));
							}
						    }
						}
					    }
					}
				    }				    
				}

				for (int k = 0; k < m_robustness; ++k)
				{
				    if (layer - k >= 0)
				    {
					for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					{
					    if (other_robot_id != robot_id)
					    {
						for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						{
						    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer - k][vv])
						    {
							biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														sIntegerIndex(vv)));
						    }
						}
					    }
					}
				    }
				}
				if (!biangular_Identifiers.empty())
				{
				    encoding_context.m_bit_generator->cast_MultiBiangleMutex(solver,
											     sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														     sIntegerIndex(neighbor_index)),
											     biangular_Identifiers);
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    encoding_context.m_bit_generator->cast_BitSet(solver,
								  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
											  sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }    
    

    void sMultirobotInstance::to_Memory_GMddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			encoding_context.m_bit_generator->cast_MultiConjunctiveImplication(solver,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
											   prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}       
	if (!cardinality_Identifiers.empty())
	{
	    encoding_context.m_bit_generator->cast_Cardinality(solver, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);

		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sVertex::Neighbors_list &Neighbors = m_environment.m_Vertices[MDD[robot_id][layer][u]].m_Neighbors;
			    for (sVertex::Neighbors_list::const_iterator neighbor = Neighbors.begin(); neighbor != Neighbors.end(); ++neighbor)
			    {				
				if ((*neighbor)->m_target->m_id == MDD[robot_id][layer + 1][v])
				{
				    if (!(*neighbor)->m_edge->m_Conflicts.empty())
				    {
					sBitClauseGenerator::SpecifiedBitIdentifiers_vector conflict_edge_Identifiers;
				 
					sEdge::Conflicts_vector &Conflicts = (*neighbor)->m_edge->m_Conflicts;
					for (sEdge::Conflicts_vector::const_iterator conflict = Conflicts.begin(); conflict != Conflicts.end(); ++conflict)
					{
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (robot_id != other_robot_id)
						{
						    for (int uu = 0; uu < MDD[other_robot_id][layer].size(); ++uu)
						    {
							int neighbor_index = 0;
							for (int vv = 0; vv < MDD[other_robot_id][layer + 1].size(); ++vv)
							{
							    if (   m_environment.is_Adjacent(MDD[other_robot_id][layer][uu], MDD[other_robot_id][layer + 1][vv])
								|| MDD[other_robot_id][layer][uu] == MDD[other_robot_id][layer + 1][vv])
							    {
								if (   (conflict->m_x_ID == MDD[other_robot_id][layer][uu] && conflict->m_y_ID == MDD[other_robot_id][layer + 1][vv])
								    || (conflict->m_y_ID == MDD[other_robot_id][layer][uu] && conflict->m_x_ID == MDD[other_robot_id][layer + 1][vv]))
								{
								    conflict_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][uu],
																sIntegerIndex(neighbor_index)));
								}
								neighbor_index++;
							    }
							}
						    }
						}
					    }
					}
					encoding_context.m_bit_generator->cast_MultiNegativeImplication(solver,
													sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																sIntegerIndex(neighbor_index)),
													conflict_edge_Identifiers);
				    }
				}
			    }
			    
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
												       sIntegerIndex(neighbor_index)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
												       sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    encoding_context.m_bit_generator->cast_MultiImplication(solver,
									    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
												    sIntegerIndex(u)),
									    mutex_target_Identifiers);

		    encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
									      mutex_target_Identifiers);   
		}
		encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
									  mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
								      mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
									      mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{		    
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector biangular_Identifiers;
		    
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.begin();
				     conflict != m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.end(); ++conflict)
				{
				    for (int k = 0; k < m_robustness; ++k)
				    {
					if (layer - k >= 0)
					{
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (other_robot_id != robot_id)
						{
						    for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						    {
							if (*conflict == MDD[other_robot_id][layer - k][vv])
							{
							    biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														    sIntegerIndex(vv)));
							}
						    }
						}
					}
					}
				    }				    
				}				
				for (int k = 0; k < m_robustness; ++k)
				{
				    if (layer - k >= 0)
				    {
					for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					{
					    if (other_robot_id != robot_id)
					    {
						for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						{
						    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer - k][vv])
						    {
							biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														sIntegerIndex(vv)));
						    }
						}
					    }
					}
				    }
				}
				if (!biangular_Identifiers.empty())
				{
				    encoding_context.m_bit_generator->cast_MultiBiangleMutex(solver,
											     sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														     sIntegerIndex(neighbor_index)),
											     biangular_Identifiers);
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    encoding_context.m_bit_generator->cast_BitSet(solver,
								  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
											  sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }


    void sMultirobotInstance::to_Memory_GEMddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const RobotMDD_vector &unified_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	MDDIndices_vector MDD_Indices;
	construct_MDDIndices(MDD, MDD_Indices);

	RobotMDDIndices_vector unified_MDD_Indices;
	construct_MDDIndices(unified_MDD, unified_MDD_Indices);		

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			encoding_context.m_bit_generator->cast_MultiConjunctiveImplication(solver,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
											   prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}       
	if (!cardinality_Identifiers.empty())
	{
	    encoding_context.m_bit_generator->cast_Cardinality(solver, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);

		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sVertex::Neighbors_list &Neighbors = m_environment.m_Vertices[MDD[robot_id][layer][u]].m_Neighbors;
			    for (sVertex::Neighbors_list::const_iterator neighbor = Neighbors.begin(); neighbor != Neighbors.end(); ++neighbor)
			    {				
				if ((*neighbor)->m_target->m_id == MDD[robot_id][layer + 1][v])
				{
				    if (!(*neighbor)->m_edge->m_Conflicts.empty())
				    {
					sBitClauseGenerator::SpecifiedBitIdentifiers_vector conflict_edge_Identifiers;
				 
					sEdge::Conflicts_vector &Conflicts = (*neighbor)->m_edge->m_Conflicts;
					for (sEdge::Conflicts_vector::const_iterator conflict = Conflicts.begin(); conflict != Conflicts.end(); ++conflict)
					{
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (robot_id != other_robot_id)
						{
						    for (int uu = 0; uu < MDD[other_robot_id][layer].size(); ++uu)
						    {
							int neighbor_index = 0;
							for (int vv = 0; vv < MDD[other_robot_id][layer + 1].size(); ++vv)
							{
							    if (   m_environment.is_Adjacent(MDD[other_robot_id][layer][uu], MDD[other_robot_id][layer + 1][vv])
								|| MDD[other_robot_id][layer][uu] == MDD[other_robot_id][layer + 1][vv])
							    {
								if (   (conflict->m_x_ID == MDD[other_robot_id][layer][uu] && conflict->m_y_ID == MDD[other_robot_id][layer + 1][vv])
								    || (conflict->m_y_ID == MDD[other_robot_id][layer][uu] && conflict->m_x_ID == MDD[other_robot_id][layer + 1][vv]))
								{
								    conflict_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][uu],
																sIntegerIndex(neighbor_index)));
								}
								neighbor_index++;
							    }
							}
						    }
						}
					    }
					}
					encoding_context.m_bit_generator->cast_MultiNegativeImplication(solver,
													sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																sIntegerIndex(neighbor_index)),
													conflict_edge_Identifiers);
				    }
				}
			    }
			    
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
												       sIntegerIndex(neighbor_index)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
												       sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    encoding_context.m_bit_generator->cast_MultiImplication(solver,
									    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
												    sIntegerIndex(u)),
									    mutex_target_Identifiers);

		    encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
									      mutex_target_Identifiers);   
		}
		encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
									  mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
								      mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
									      mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{		    
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector biangular_Identifiers;
		    
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.begin();
				     conflict != m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.end(); ++conflict)
				{
				    for (int k = 0; k < m_robustness; ++k)
				    {
					if (layer - k >= 0)
					{
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (other_robot_id != robot_id)
						{
						    for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						    {
							if (*conflict == MDD[other_robot_id][layer - k][vv])
							{
							    biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														    sIntegerIndex(vv)));
							}
						    }
						}
					}
					}
				    }				    
				}				
				for (int k = 0; k < m_robustness; ++k)
				{
				    if (layer - k >= 0)
				    {
					for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					{
					    if (other_robot_id != robot_id)
					    {
						for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						{
						    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer - k][vv])
						    {
							biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														sIntegerIndex(vv)));
						    }
						}
					    }
					}
				    }
				}
				if (!biangular_Identifiers.empty())
				{
				    encoding_context.m_bit_generator->cast_MultiBiangleMutex(solver,
											     sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														     sIntegerIndex(neighbor_index)),
											     biangular_Identifiers);
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    encoding_context.m_bit_generator->cast_BitSet(solver,
								  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
											  sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }        
    

    void sMultirobotInstance::to_Stream_RelaxedMddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int Clause_cnt = 0;
	int aux_Variable_cnt = 0;
	int total_Literal_cnt = 0;

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	#ifdef sVERBOSE
	{
	    printf("Goal specification\n");
	    m_goal_specification.to_Screen_brief();
	}
	#endif

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	//	s_GlobalPhaseStatistics.enter_Phase("Counting");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_MultiConjunctiveImplication(aux_Variable_cnt,
													  total_Literal_cnt,
													  sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													  prev_cardinality_Identifiers);
	    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}
	if (!cardinality_Identifiers.empty())
	{
	    Clause_cnt += encoding_context.m_bit_generator->count_Cardinality(aux_Variable_cnt,total_Literal_cnt, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);

		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														      sIntegerIndex(neighbor_index)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														      sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
											   total_Literal_cnt,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(u)),
											   mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												 total_Literal_cnt,
												 mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_occupancy_Identifiers);
		}
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						
						Clause_cnt += encoding_context.m_bit_generator->count_BiangleMutex(aux_Variable_cnt,
														   total_Literal_cnt,
														   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	   sIntegerIndex(neighbor_index)),
														   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	   sIntegerIndex(vv)));

					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}
*/
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										 total_Literal_cnt,
										 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													 sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}


	int N_cnf_Variables = encoding_context.m_variable_store.get_Last_CNFVariable() + aux_Variable_cnt - 1;

	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.enter_Phase("Writing");

#ifdef sDEBUG
	fprintf(fw, "c %s : multirobot relaxed MDD SAT encoding\n", sPRODUCT);
	fprintf(fw, "c %s\n", sCOPYRIGHT);
	fprintf(fw, "c number of layers = %d\n", N_Layers);
	fprintf(fw, "c number of visible variables = %d\n", N_cnf_Variables - aux_Variable_cnt);
	fprintf(fw, "c number of hidden variables = %d\n", aux_Variable_cnt);
	fprintf(fw, "c number of literals = %d\n", total_Literal_cnt);
	fprintf(fw, "c number of clauses = %d\n", Clause_cnt);
	fprintf(fw, "c number of propositional variables = %d\n", N_cnf_Variables);
	fprintf(fw, "c number of clauses / number of variables = %.3f\n", (double)Clause_cnt / N_cnf_Variables);
	fprintf(fw, "c number of literals / number of clauses = %.3f\n", (double)total_Literal_cnt /  Clause_cnt);
	to_Stream(fw, "c ");
#endif
	fprintf(fw, "p cnf %d %d\n", N_cnf_Variables, Clause_cnt);

	//	s_GlobalPhaseStatistics.enter_Phase("Pregen 1");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {			
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }

		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_MultiConjunctiveImplication(fw,
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													     prev_cardinality_Identifiers);
		    }
		}
	    }
	}
	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.enter_Phase("Pregen 2");

	if (!cardinality_Identifiers.empty())
	{
//	    printf("----> Cardinality: %d, %d, %d <----\n", cardinality_Identifiers.size(), extra_cost, encoding_context.m_max_total_cost);
	    Clause_cnt += encoding_context.m_bit_generator->generate_Cardinality(fw, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															 sIntegerIndex(neighbor_index)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
															 sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												    mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_occupancy_Identifiers);
		}
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						
						Clause_cnt += encoding_context.m_bit_generator->generate_BiangleMutex(fw,
														      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	      sIntegerIndex(neighbor_index)),
														      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	      sIntegerIndex(vv)));						
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}
*/
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													    sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}

	//------ alternative
	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.leave_Phase();
    }


    void sMultirobotInstance::to_Stream_TokenMddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int Clause_cnt = 0;
	int aux_Variable_cnt = 0;
	int total_Literal_cnt = 0;

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	#ifdef sVERBOSE
	{
	    printf("Goal specification\n");
	    m_goal_specification.to_Screen_brief();
	}
	#endif

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	//	s_GlobalPhaseStatistics.enter_Phase("Counting");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_MultiConjunctiveImplication(aux_Variable_cnt,
													  total_Literal_cnt,
													  sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													  prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}
	if (!cardinality_Identifiers.empty())
	{
	    Clause_cnt += encoding_context.m_bit_generator->count_Cardinality(aux_Variable_cnt,total_Literal_cnt, cardinality_Identifiers, extra_cost);
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);

		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		std::vector<sBitClauseGenerator::SpecifiedBitIdentifiers_vector> mutex_source_Identifiers;		
		mutex_source_Identifiers.resize(N_Vertices);

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														      sIntegerIndex(neighbor_index)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														      sIntegerIndex(v)));
			    mutex_source_Identifiers[MDD[robot_id][layer + 1][v]].push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														    sIntegerIndex(neighbor_index)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
											   total_Literal_cnt,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(u)),
											   mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_target_Identifiers);   
		}
		for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_source_Identifiers[MDD[robot_id][layer + 1][v]]);
		}		
		Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												 total_Literal_cnt,
												 mutex_vertex_Identifiers);
	    }
	}
	
	for (int layer = 0; layer < N_Layers; ++layer)
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				sBitClauseGenerator::SpecifiedBitIdentifiers_vector complementary_edge_Identifiers;
				
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (robot_id != other_robot_id)
				    {
					int vv;
					
					for (vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						break;
					    }
					}

					if (vv < MDD[other_robot_id][layer].size())
					{
					    int other_neighbor_index = 0;
					    for (int w = 0; w < MDD[other_robot_id][layer + 1].size(); ++w)
					    {
						if (m_environment.is_Adjacent(MDD[other_robot_id][layer][vv], MDD[other_robot_id][layer + 1][w]) || MDD[other_robot_id][layer][vv] == MDD[other_robot_id][layer + 1][w])
						{
						    if (MDD[other_robot_id][layer][vv] != MDD[other_robot_id][layer + 1][w])
						    {
							if (MDD[other_robot_id][layer + 1][w] == MDD[robot_id][layer][u])
							{
							    complementary_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][vv], sIntegerIndex(other_neighbor_index)));
							}
						    }
						    ++other_neighbor_index;
						}
					    }
					}
				    }
				}
				if (!complementary_edge_Identifiers.empty())
				{
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
													   total_Literal_cnt,
													   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																   sIntegerIndex(neighbor_index)),
													   complementary_edge_Identifiers);
				}
				else
				{
				    Clause_cnt += encoding_context.m_bit_generator->count_BitUnset(aux_Variable_cnt,
												   total_Literal_cnt,
												   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															   sIntegerIndex(neighbor_index)));
				}
			    }
			    neighbor_index++;
			}
		    }
		}
	    }
	}	

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_occupancy_Identifiers);
		}
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						
						Clause_cnt += encoding_context.m_bit_generator->count_BiangleMutex(aux_Variable_cnt,
														   total_Literal_cnt,
														   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	   sIntegerIndex(neighbor_index)),
														   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	   sIntegerIndex(vv)));

					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}
*/
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										 total_Literal_cnt,
										 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													 sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}


	int N_cnf_Variables = encoding_context.m_variable_store.get_Last_CNFVariable() + aux_Variable_cnt - 1;

	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.enter_Phase("Writing");

#ifdef sDEBUG
	fprintf(fw, "c %s : multirobot token MDD SAT encoding\n", sPRODUCT);
	fprintf(fw, "c %s\n", sCOPYRIGHT);
	fprintf(fw, "c number of layers = %d\n", N_Layers);
	fprintf(fw, "c number of visible variables = %d\n", N_cnf_Variables - aux_Variable_cnt);
	fprintf(fw, "c number of hidden variables = %d\n", aux_Variable_cnt);
	fprintf(fw, "c number of literals = %d\n", total_Literal_cnt);
	fprintf(fw, "c number of clauses = %d\n", Clause_cnt);
	fprintf(fw, "c number of propositional variables = %d\n", N_cnf_Variables);
	fprintf(fw, "c number of clauses / number of variables = %.3f\n", (double)Clause_cnt / N_cnf_Variables);
	fprintf(fw, "c number of literals / number of clauses = %.3f\n", (double)total_Literal_cnt /  Clause_cnt);
	to_Stream(fw, "c ");
#endif
	fprintf(fw, "p cnf %d %d\n", N_cnf_Variables, Clause_cnt);

	//	s_GlobalPhaseStatistics.enter_Phase("Pregen 1");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {			
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }

		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_MultiConjunctiveImplication(fw,
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													     prev_cardinality_Identifiers);
		    }
		}
	    }
	}
	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.enter_Phase("Pregen 2");

	if (!cardinality_Identifiers.empty())
	{
//	    printf("----> Cardinality: %d, %d, %d <----\n", cardinality_Identifiers.size(), extra_cost, encoding_context.m_max_total_cost);
	    Clause_cnt += encoding_context.m_bit_generator->generate_Cardinality(fw, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		std::vector<sBitClauseGenerator::SpecifiedBitIdentifiers_vector> mutex_source_Identifiers;		
		mutex_source_Identifiers.resize(N_Vertices);		    		
		    
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															 sIntegerIndex(neighbor_index)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
															 sIntegerIndex(v)));
			    mutex_source_Identifiers[MDD[robot_id][layer + 1][v]].push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														    sIntegerIndex(neighbor_index)));			    
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_target_Identifiers);   
		}
		for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_source_Identifiers[MDD[robot_id][layer + 1][v]]);
		}	       
		Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												    mutex_vertex_Identifiers);
	    }
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				sBitClauseGenerator::SpecifiedBitIdentifiers_vector complementary_edge_Identifiers;
				
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (robot_id != other_robot_id)
				    {
					int vv = -1;
					
					for (vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						break;
					    }
					}

					if (vv < MDD[other_robot_id][layer].size())
					{
					    int other_neighbor_index = 0;
					    for (int w = 0; w < MDD[other_robot_id][layer + 1].size(); ++w)
					    {					    
						if (m_environment.is_Adjacent(MDD[other_robot_id][layer][vv], MDD[other_robot_id][layer + 1][w]) || MDD[other_robot_id][layer][vv] == MDD[other_robot_id][layer + 1][w])
						{
						    if (MDD[other_robot_id][layer][vv] != MDD[other_robot_id][layer + 1][w])
						    {
							if (MDD[other_robot_id][layer + 1][w] == MDD[robot_id][layer][u])
							{
							    complementary_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][vv], sIntegerIndex(other_neighbor_index)));
							}
						    }
						    ++other_neighbor_index;
						}
					    }
					}
				    }
				}
				if (!complementary_edge_Identifiers.empty())
				{
				    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
													      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																      sIntegerIndex(neighbor_index)),
													      complementary_edge_Identifiers);
				}
				else
				{
				    Clause_cnt += encoding_context.m_bit_generator->generate_BitUnset(fw,
												      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															      sIntegerIndex(neighbor_index)));
				}
			    }
			    neighbor_index++;
			}
		    }
		}
	    }
	}		
	

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_occupancy_Identifiers);
		}
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						
						Clause_cnt += encoding_context.m_bit_generator->generate_BiangleMutex(fw,
														      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	      sIntegerIndex(neighbor_index)),
														      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	      sIntegerIndex(vv)));						
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}
*/
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													    sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}

	//------ alternative
	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.leave_Phase();
    }


    void sMultirobotInstance::to_Stream_TokenEmptyMddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int Clause_cnt = 0;
	int aux_Variable_cnt = 0;
	int total_Literal_cnt = 0;

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	#ifdef sVERBOSE
	{
	    printf("Goal specification\n");
	    m_goal_specification.to_Screen_brief();
	}
	#endif

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	//	s_GlobalPhaseStatistics.enter_Phase("Counting");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_MultiConjunctiveImplication(aux_Variable_cnt,
													  total_Literal_cnt,
													  sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													  prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}
	if (!cardinality_Identifiers.empty())
	{
	    Clause_cnt += encoding_context.m_bit_generator->count_Cardinality(aux_Variable_cnt,total_Literal_cnt, cardinality_Identifiers, extra_cost);
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);

		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		std::vector<sBitClauseGenerator::SpecifiedBitIdentifiers_vector> mutex_source_Identifiers;		
		mutex_source_Identifiers.resize(N_Vertices);

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														      sIntegerIndex(neighbor_index)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														      sIntegerIndex(v)));
			    mutex_source_Identifiers[MDD[robot_id][layer + 1][v]].push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														    sIntegerIndex(neighbor_index)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
											   total_Literal_cnt,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(u)),
											   mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_target_Identifiers);   
		}
		for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_source_Identifiers[MDD[robot_id][layer + 1][v]]);
		}		
		Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												 total_Literal_cnt,
												 mutex_vertex_Identifiers);
	    }
	}
	
	for (int layer = 0; layer < N_Layers; ++layer)
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				sBitClauseGenerator::SpecifiedBitIdentifiers_vector complementary_edge_Identifiers, complementary_node_Identifiers, biangular_Identifiers;				
				
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (robot_id != other_robot_id)
				    {
					int vv;
					
					for (vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						break;
					    }
					}
					sASSERT(vv >= 0);

					if (vv < MDD[other_robot_id][layer].size())
					{
					    biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer], sIntegerIndex(vv)));
										    
					    int other_neighbor_index = 0;
					    for (int w = 0; w < MDD[other_robot_id][layer + 1].size(); ++w)
					    {
						if (m_environment.is_Adjacent(MDD[other_robot_id][layer][vv], MDD[other_robot_id][layer + 1][w]) || MDD[other_robot_id][layer][vv] == MDD[other_robot_id][layer + 1][w])
						{
						    if (MDD[other_robot_id][layer][vv] != MDD[other_robot_id][layer + 1][w])
						    {
							if (MDD[other_robot_id][layer + 1][w] == MDD[robot_id][layer][u])
							{
							    complementary_node_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer], sIntegerIndex(vv)));
//							    complementary_node_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer + 1], sIntegerIndex(w)));
							    complementary_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][vv], sIntegerIndex(other_neighbor_index)));
							}
						    }
						    ++other_neighbor_index;
						}
					    }
					}
				    }
				}
				if (!complementary_edge_Identifiers.empty())
				{
				    sASSERT(!complementary_node_Identifiers.empty());
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiImpliedImplication(aux_Variable_cnt,
														     total_Literal_cnt,
														     sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	     sIntegerIndex(neighbor_index)),
														     complementary_node_Identifiers, complementary_edge_Identifiers);
				    /*
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
				                                                                              total_Literal_cnt,	
														     sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	     sIntegerIndex(neighbor_index)),
														     complementary_edge_Identifiers);
				    */				    
				}
				else
				{
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiBiangleMutex(aux_Variable_cnt,
													    total_Literal_cnt,
													    sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																    sIntegerIndex(neighbor_index)),
													    biangular_Identifiers);
				}
			    }
			    neighbor_index++;
			}
		    }
		}
	    }
	}	

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_occupancy_Identifiers);
		}
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						
						Clause_cnt += encoding_context.m_bit_generator->count_BiangleMutex(aux_Variable_cnt,
														   total_Literal_cnt,
														   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	   sIntegerIndex(neighbor_index)),
														   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	   sIntegerIndex(vv)));

					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}
*/
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										 total_Literal_cnt,
										 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													 sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}


	int N_cnf_Variables = encoding_context.m_variable_store.get_Last_CNFVariable() + aux_Variable_cnt - 1;

	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.enter_Phase("Writing");

#ifdef sDEBUG
	fprintf(fw, "c %s : multirobot token empty MDD SAT encoding\n", sPRODUCT);
	fprintf(fw, "c %s\n", sCOPYRIGHT);
	fprintf(fw, "c number of layers = %d\n", N_Layers);
	fprintf(fw, "c number of visible variables = %d\n", N_cnf_Variables - aux_Variable_cnt);
	fprintf(fw, "c number of hidden variables = %d\n", aux_Variable_cnt);
	fprintf(fw, "c number of literals = %d\n", total_Literal_cnt);
	fprintf(fw, "c number of clauses = %d\n", Clause_cnt);
	fprintf(fw, "c number of propositional variables = %d\n", N_cnf_Variables);
	fprintf(fw, "c number of clauses / number of variables = %.3f\n", (double)Clause_cnt / N_cnf_Variables);
	fprintf(fw, "c number of literals / number of clauses = %.3f\n", (double)total_Literal_cnt /  Clause_cnt);
	to_Stream(fw, "c ");
#endif
	fprintf(fw, "p cnf %d %d\n", N_cnf_Variables, Clause_cnt);

	//	s_GlobalPhaseStatistics.enter_Phase("Pregen 1");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {			
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }

		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_MultiConjunctiveImplication(fw,
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													     prev_cardinality_Identifiers);
		    }
		}
	    }
	}
	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.enter_Phase("Pregen 2");

	if (!cardinality_Identifiers.empty())
	{
//	    printf("----> Cardinality: %d, %d, %d <----\n", cardinality_Identifiers.size(), extra_cost, encoding_context.m_max_total_cost);
	    Clause_cnt += encoding_context.m_bit_generator->generate_Cardinality(fw, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		std::vector<sBitClauseGenerator::SpecifiedBitIdentifiers_vector> mutex_source_Identifiers;		
		mutex_source_Identifiers.resize(N_Vertices);		    		
		    
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															 sIntegerIndex(neighbor_index)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
															 sIntegerIndex(v)));
			    mutex_source_Identifiers[MDD[robot_id][layer + 1][v]].push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														    sIntegerIndex(neighbor_index)));			    
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_target_Identifiers);   
		}
		for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_source_Identifiers[MDD[robot_id][layer + 1][v]]);
		}	       
		Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												    mutex_vertex_Identifiers);
	    }
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				sBitClauseGenerator::SpecifiedBitIdentifiers_vector complementary_edge_Identifiers, complementary_node_Identifiers, biangular_Identifiers;
				
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (robot_id != other_robot_id)
				    {
					int vv = -1;
					
					for (vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						break;
					    }
					}
					sASSERT(vv >= 0);
					
					if (vv < MDD[other_robot_id][layer].size())
					{
					    biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer], sIntegerIndex(vv)));
					    
					    int other_neighbor_index = 0;
					    for (int w = 0; w < MDD[other_robot_id][layer + 1].size(); ++w)
					    {					    
						if (m_environment.is_Adjacent(MDD[other_robot_id][layer][vv], MDD[other_robot_id][layer + 1][w]) || MDD[other_robot_id][layer][vv] == MDD[other_robot_id][layer + 1][w])
						{
						    if (MDD[other_robot_id][layer][vv] != MDD[other_robot_id][layer + 1][w])
						    {
							if (MDD[other_robot_id][layer + 1][w] == MDD[robot_id][layer][u])
							{
							    complementary_node_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer], sIntegerIndex(vv)));
//							    complementary_node_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer + 1], sIntegerIndex(w)));
							    complementary_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][vv], sIntegerIndex(other_neighbor_index)));
							}
						    }
						    ++other_neighbor_index;
						}
					    }
					}
				    }
				}
				if (!complementary_edge_Identifiers.empty())
				{
				    sASSERT(!complementary_node_Identifiers.empty());
				    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImpliedImplication(fw,
														     sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	     sIntegerIndex(neighbor_index)),
														     complementary_node_Identifiers, complementary_edge_Identifiers);
				    /*
				    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
														     sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	     sIntegerIndex(neighbor_index)),
														     complementary_edge_Identifiers);
				    */
				}
				else
				{
				    Clause_cnt += encoding_context.m_bit_generator->generate_MultiBiangleMutex(fw,
													       sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																       sIntegerIndex(neighbor_index)),
													       biangular_Identifiers);
				}
			    }
			    neighbor_index++;
			}
		    }
		}
	    }
	}		
	

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_occupancy_Identifiers);
		}
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						
						Clause_cnt += encoding_context.m_bit_generator->generate_BiangleMutex(fw,
														      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	      sIntegerIndex(neighbor_index)),
														      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	      sIntegerIndex(vv)));						
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}
*/
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													    sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}

	//------ alternative
	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.leave_Phase();
    }            


    void sMultirobotInstance::to_Stream_PermutationMddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int Clause_cnt = 0;
	int aux_Variable_cnt = 0;
	int total_Literal_cnt = 0;

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	//	s_GlobalPhaseStatistics.enter_Phase("Counting");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_MultiConjunctiveImplication(aux_Variable_cnt,
													  total_Literal_cnt,
													  sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													  prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}
	if (!cardinality_Identifiers.empty())
	{
	    Clause_cnt += encoding_context.m_bit_generator->count_Cardinality(aux_Variable_cnt,total_Literal_cnt, cardinality_Identifiers, extra_cost);
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		std::vector<sBitClauseGenerator::SpecifiedBitIdentifiers_vector> mutex_source_Identifiers;		
		mutex_source_Identifiers.resize(N_Vertices);

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														      sIntegerIndex(neighbor_index)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														      sIntegerIndex(v)));
			    mutex_source_Identifiers[MDD[robot_id][layer + 1][v]].push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														    sIntegerIndex(neighbor_index)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
											   total_Literal_cnt,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(u)),
											   mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_target_Identifiers);   
		}
		for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_source_Identifiers[MDD[robot_id][layer + 1][v]]);
		}		
		Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												 total_Literal_cnt,
												 mutex_vertex_Identifiers);
	    }
	}
	
	for (int layer = 0; layer < N_Layers; ++layer)
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				sBitClauseGenerator::SpecifiedBitIdentifiers_vector complementary_edge_Identifiers;
				
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (robot_id != other_robot_id)
				    {
					int vv;
					
					for (vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						break;
					    }
					}

					if (vv < MDD[other_robot_id][layer].size())
					{
					    int other_neighbor_index = 0;
					    for (int w = 0; w < MDD[other_robot_id][layer + 1].size(); ++w)
					    {
						if (m_environment.is_Adjacent(MDD[other_robot_id][layer][vv], MDD[other_robot_id][layer + 1][w]) || MDD[other_robot_id][layer][vv] == MDD[other_robot_id][layer + 1][w])
						{
						    if (MDD[other_robot_id][layer][vv] != MDD[other_robot_id][layer + 1][w])
						    {
							if (MDD[other_robot_id][layer + 1][w] == MDD[robot_id][layer][u])
							{
							    complementary_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][vv], sIntegerIndex(other_neighbor_index)));
							}
						    }
						    ++other_neighbor_index;
						}
					    }
					}
				    }
				}
				if (!complementary_edge_Identifiers.empty())
				{
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiNegativeImplication(aux_Variable_cnt,
														   total_Literal_cnt,
														   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	   sIntegerIndex(neighbor_index)),
														   complementary_edge_Identifiers);
				}
				/*
				else
				{
				    Clause_cnt += encoding_context.m_bit_generator->count_BitUnset(aux_Variable_cnt,
												   total_Literal_cnt,
												   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															   sIntegerIndex(neighbor_index)));
				}
				*/
			    }
			    neighbor_index++;
			}
		    }
		}
	    }
	}	

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_occupancy_Identifiers);
		}
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						
						Clause_cnt += encoding_context.m_bit_generator->count_BiangleMutex(aux_Variable_cnt,
														   total_Literal_cnt,
														   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	   sIntegerIndex(neighbor_index)),
														   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	   sIntegerIndex(vv)));

					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}
*/
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										 total_Literal_cnt,
										 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													 sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}


	int N_cnf_Variables = encoding_context.m_variable_store.get_Last_CNFVariable() + aux_Variable_cnt - 1;

	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.enter_Phase("Writing");

#ifdef sDEBUG
	fprintf(fw, "c %s : multirobot permutation MDD SAT encoding\n", sPRODUCT);
	fprintf(fw, "c %s\n", sCOPYRIGHT);
	fprintf(fw, "c number of layers = %d\n", N_Layers);
	fprintf(fw, "c number of visible variables = %d\n", N_cnf_Variables - aux_Variable_cnt);
	fprintf(fw, "c number of hidden variables = %d\n", aux_Variable_cnt);
	fprintf(fw, "c number of literals = %d\n", total_Literal_cnt);
	fprintf(fw, "c number of clauses = %d\n", Clause_cnt);
	fprintf(fw, "c number of propositional variables = %d\n", N_cnf_Variables);
	fprintf(fw, "c number of clauses / number of variables = %.3f\n", (double)Clause_cnt / N_cnf_Variables);
	fprintf(fw, "c number of literals / number of clauses = %.3f\n", (double)total_Literal_cnt /  Clause_cnt);
	to_Stream(fw, "c ");
#endif
	fprintf(fw, "p cnf %d %d\n", N_cnf_Variables, Clause_cnt);

	//	s_GlobalPhaseStatistics.enter_Phase("Pregen 1");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {			
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }

		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_MultiConjunctiveImplication(fw,
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													     prev_cardinality_Identifiers);
		    }
		}
	    }
	}
	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.enter_Phase("Pregen 2");

	if (!cardinality_Identifiers.empty())
	{
//	    printf("----> Cardinality: %d, %d, %d <----\n", cardinality_Identifiers.size(), extra_cost, encoding_context.m_max_total_cost);
	    Clause_cnt += encoding_context.m_bit_generator->generate_Cardinality(fw, cardinality_Identifiers, extra_cost);
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		std::vector<sBitClauseGenerator::SpecifiedBitIdentifiers_vector> mutex_source_Identifiers;		
		mutex_source_Identifiers.resize(N_Vertices);		    		
		    
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															 sIntegerIndex(neighbor_index)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
															 sIntegerIndex(v)));
			    mutex_source_Identifiers[MDD[robot_id][layer + 1][v]].push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														    sIntegerIndex(neighbor_index)));			    
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_target_Identifiers);   
		}
		for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		{		    
		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_source_Identifiers[MDD[robot_id][layer + 1][v]]);		    
		}	       
		Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												    mutex_vertex_Identifiers);
	    }
	}
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				sBitClauseGenerator::SpecifiedBitIdentifiers_vector complementary_edge_Identifiers;
				
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (robot_id != other_robot_id)
				    {
					int vv = -1;
					
					for (vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						break;
					    }
					}

					if (vv < MDD[other_robot_id][layer].size())
					{
					    int other_neighbor_index = 0;
					    for (int w = 0; w < MDD[other_robot_id][layer + 1].size(); ++w)
					    {					    
						if (m_environment.is_Adjacent(MDD[other_robot_id][layer][vv], MDD[other_robot_id][layer + 1][w]) || MDD[other_robot_id][layer][vv] == MDD[other_robot_id][layer + 1][w])
						{
						    if (MDD[other_robot_id][layer][vv] != MDD[other_robot_id][layer + 1][w])
						    {
							if (MDD[other_robot_id][layer + 1][w] == MDD[robot_id][layer][u])
							{
							    complementary_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][vv], sIntegerIndex(other_neighbor_index)));
							}
						    }
						    ++other_neighbor_index;
						}
					    }
					}
				    }
				}
				if (!complementary_edge_Identifiers.empty())
				{
				    Clause_cnt += encoding_context.m_bit_generator->generate_MultiNegativeImplication(fw,
														      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	      sIntegerIndex(neighbor_index)),
														      complementary_edge_Identifiers);
				}
				/*
				else
				{
				    Clause_cnt += encoding_context.m_bit_generator->generate_BitUnset(fw,
												      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															      sIntegerIndex(neighbor_index)));
				}
				*/
			    }
			    neighbor_index++;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_occupancy_Identifiers);
		}
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						
						Clause_cnt += encoding_context.m_bit_generator->generate_BiangleMutex(fw,
														      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	      sIntegerIndex(neighbor_index)),
														      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	      sIntegerIndex(vv)));						
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}
*/
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													    sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}

	//------ alternative
	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.leave_Phase();
    }


    void sMultirobotInstance::to_Stream_CapacitatedPermutationMddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();

	int Clause_cnt = 0;
	int aux_Variable_cnt = 0;
	int total_Literal_cnt = 0;

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	//	s_GlobalPhaseStatistics.enter_Phase("Counting");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_MultiConjunctiveImplication(aux_Variable_cnt,
													  total_Literal_cnt,
													  sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													  prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}
	if (!cardinality_Identifiers.empty())
	{
	    Clause_cnt += encoding_context.m_bit_generator->count_Cardinality(aux_Variable_cnt, total_Literal_cnt, cardinality_Identifiers, extra_cost);
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		std::vector<sBitClauseGenerator::SpecifiedBitIdentifiers_vector> mutex_source_Identifiers;		
		mutex_source_Identifiers.resize(N_Vertices);

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														      sIntegerIndex(neighbor_index)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														      sIntegerIndex(v)));
			    mutex_source_Identifiers[MDD[robot_id][layer + 1][v]].push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														    sIntegerIndex(neighbor_index)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
											   total_Literal_cnt,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(u)),
											   mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_target_Identifiers);   
		}
		for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_source_Identifiers[MDD[robot_id][layer + 1][v]]);
		}
		/*
		Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												 total_Literal_cnt,
												 mutex_vertex_Identifiers);
		*/
	    }
	}

	for (int layer = 0; layer <= N_Layers; ++layer)
	{
	    std::vector<sBitClauseGenerator::SpecifiedBitIdentifiers_vector> vertex_capacity_Identifiers;
	    vertex_capacity_Identifiers.resize(N_Vertices);
	    
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    vertex_capacity_Identifiers[MDD[robot_id][layer][u]].push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
		}
	    }
	    for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	    {
		if (vertex_capacity_Identifiers[vertex_id].size() > m_environment.m_Vertices[vertex_id].m_capacity)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_Cardinality(aux_Variable_cnt,
										      total_Literal_cnt,
										      vertex_capacity_Identifiers[vertex_id],
										      m_environment.m_Vertices[vertex_id].m_capacity);
		}
	    }	    
	}
	
	for (int layer = 0; layer < N_Layers; ++layer)
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				sBitClauseGenerator::SpecifiedBitIdentifiers_vector complementary_edge_Identifiers;
				
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (robot_id != other_robot_id)
				    {
					int vv;
					
					for (vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						break;
					    }
					}

					if (vv < MDD[other_robot_id][layer].size())
					{
					    int other_neighbor_index = 0;
					    for (int w = 0; w < MDD[other_robot_id][layer + 1].size(); ++w)
					    {
						if (m_environment.is_Adjacent(MDD[other_robot_id][layer][vv], MDD[other_robot_id][layer + 1][w]) || MDD[other_robot_id][layer][vv] == MDD[other_robot_id][layer + 1][w])
						{
						    if (MDD[other_robot_id][layer][vv] != MDD[other_robot_id][layer + 1][w])
						    {
							if (MDD[other_robot_id][layer + 1][w] == MDD[robot_id][layer][u])
							{
							    complementary_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][vv], sIntegerIndex(other_neighbor_index)));
							}
						    }
						    ++other_neighbor_index;
						}
					    }
					}
				    }
				}
				if (!complementary_edge_Identifiers.empty())
				{
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiNegativeImplication(aux_Variable_cnt,
														   total_Literal_cnt,
														   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	   sIntegerIndex(neighbor_index)),
														   complementary_edge_Identifiers);
				}
				/*
				else
				{
				    Clause_cnt += encoding_context.m_bit_generator->count_BitUnset(aux_Variable_cnt,
												   total_Literal_cnt,
												   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															   sIntegerIndex(neighbor_index)));
				}
				*/
			    }
			    neighbor_index++;
			}
		    }
		}
	    }
	}	

	/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_vertex_Identifiers);
	}
	*/
/*
	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_occupancy_Identifiers);
		}
	    }
	}
*/
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						
						Clause_cnt += encoding_context.m_bit_generator->count_BiangleMutex(aux_Variable_cnt,
														   total_Literal_cnt,
														   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	   sIntegerIndex(neighbor_index)),
														   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	   sIntegerIndex(vv)));

					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}
*/
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										 total_Literal_cnt,
										 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													 sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}


	int N_cnf_Variables = encoding_context.m_variable_store.get_Last_CNFVariable() + aux_Variable_cnt - 1;

	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.enter_Phase("Writing");

#ifdef sDEBUG
	fprintf(fw, "c %s : multirobot permutation CMDD SAT encoding\n", sPRODUCT);
	fprintf(fw, "c %s\n", sCOPYRIGHT);
	fprintf(fw, "c number of layers = %d\n", N_Layers);
	fprintf(fw, "c number of visible variables = %d\n", N_cnf_Variables - aux_Variable_cnt);
	fprintf(fw, "c number of hidden variables = %d\n", aux_Variable_cnt);
	fprintf(fw, "c number of literals = %d\n", total_Literal_cnt);
	fprintf(fw, "c number of clauses = %d\n", Clause_cnt);
	fprintf(fw, "c number of propositional variables = %d\n", N_cnf_Variables);
	fprintf(fw, "c number of clauses / number of variables = %.3f\n", (double)Clause_cnt / N_cnf_Variables);
	fprintf(fw, "c number of literals / number of clauses = %.3f\n", (double)total_Literal_cnt /  Clause_cnt);
	to_Stream(fw, "c ");
#endif
	fprintf(fw, "p cnf %d %d\n", N_cnf_Variables, Clause_cnt);

	//	s_GlobalPhaseStatistics.enter_Phase("Pregen 1");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {			
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }

		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_MultiConjunctiveImplication(fw,
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													     prev_cardinality_Identifiers);
		    }
		}
	    }
	}
	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.enter_Phase("Pregen 2");

	if (!cardinality_Identifiers.empty())
	{
//	    printf("----> Cardinality: %d, %d, %d <----\n", cardinality_Identifiers.size(), extra_cost, encoding_context.m_max_total_cost);
	    Clause_cnt += encoding_context.m_bit_generator->generate_Cardinality(fw, cardinality_Identifiers, extra_cost);
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		std::vector<sBitClauseGenerator::SpecifiedBitIdentifiers_vector> mutex_source_Identifiers;		
		mutex_source_Identifiers.resize(N_Vertices);		    		
		    
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															 sIntegerIndex(neighbor_index)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
															 sIntegerIndex(v)));
			    mutex_source_Identifiers[MDD[robot_id][layer + 1][v]].push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														    sIntegerIndex(neighbor_index)));			    
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_target_Identifiers);   
		}
		for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		{		    
		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_source_Identifiers[MDD[robot_id][layer + 1][v]]);		    
		}
		/*
		Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												    mutex_vertex_Identifiers);
		*/
	    }
	}

	for (int layer = 0; layer <= N_Layers; ++layer)
	{
	    std::vector<sBitClauseGenerator::SpecifiedBitIdentifiers_vector> vertex_capacity_Identifiers;
	    vertex_capacity_Identifiers.resize(N_Vertices);
	    
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    vertex_capacity_Identifiers[MDD[robot_id][layer][u]].push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
		}
	    }
	    for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	    {
		if (vertex_capacity_Identifiers[vertex_id].size() > m_environment.m_Vertices[vertex_id].m_capacity)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_Cardinality(fw,
											 vertex_capacity_Identifiers[vertex_id],
											 m_environment.m_Vertices[vertex_id].m_capacity);
		}
	    }	    
	}
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				sBitClauseGenerator::SpecifiedBitIdentifiers_vector complementary_edge_Identifiers;
				
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (robot_id != other_robot_id)
				    {
					int vv = -1;
					
					for (vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						break;
					    }
					}

					if (vv < MDD[other_robot_id][layer].size())
					{
					    int other_neighbor_index = 0;
					    for (int w = 0; w < MDD[other_robot_id][layer + 1].size(); ++w)
					    {					    
						if (m_environment.is_Adjacent(MDD[other_robot_id][layer][vv], MDD[other_robot_id][layer + 1][w]) || MDD[other_robot_id][layer][vv] == MDD[other_robot_id][layer + 1][w])
						{
						    if (MDD[other_robot_id][layer][vv] != MDD[other_robot_id][layer + 1][w])
						    {
							if (MDD[other_robot_id][layer + 1][w] == MDD[robot_id][layer][u])
							{
							    complementary_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][vv], sIntegerIndex(other_neighbor_index)));
							}
						    }
						    ++other_neighbor_index;
						}
					    }
					}
				    }
				}
				if (!complementary_edge_Identifiers.empty())
				{
				    Clause_cnt += encoding_context.m_bit_generator->generate_MultiNegativeImplication(fw,
														      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	      sIntegerIndex(neighbor_index)),
														      complementary_edge_Identifiers);
				}
				/*
				else
				{
				    Clause_cnt += encoding_context.m_bit_generator->generate_BitUnset(fw,
												      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															      sIntegerIndex(neighbor_index)));
				}
				*/
			    }
			    neighbor_index++;
			}
		    }
		}
	    }
	}

	/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												mutex_vertex_Identifiers);
	}
	*/

	/*
	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_occupancy_Identifiers);
		}
	    }
	}
	*/
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						
						Clause_cnt += encoding_context.m_bit_generator->generate_BiangleMutex(fw,
														      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	      sIntegerIndex(neighbor_index)),
														      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	      sIntegerIndex(vv)));						
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}
*/
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													    sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}

	//------ alternative
	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.leave_Phase();
    }            
    

    void sMultirobotInstance::to_Memory_RelaxedMddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	//	s_GlobalPhaseStatistics.enter_Phase("Counting");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			encoding_context.m_bit_generator->cast_MultiConjunctiveImplication(solver,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
											   prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}
	if (!cardinality_Identifiers.empty())
	{
	    encoding_context.m_bit_generator->cast_Cardinality(solver, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);

		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
												       sIntegerIndex(neighbor_index)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
												       sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    encoding_context.m_bit_generator->cast_MultiImplication(solver,
									    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
												    sIntegerIndex(u)),
									    mutex_target_Identifiers);

		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										      mutex_target_Identifiers);   
		}
		encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										  mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
											    mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
												    mutex_occupancy_Identifiers);
		}
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						
						encoding_context.m_bit_generator->cast_BiangleMutex(solver,
														   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	   sIntegerIndex(neighbor_index)),
														   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	   sIntegerIndex(vv)));

					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}
*/
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    encoding_context.m_bit_generator->cast_BitSet(solver,
								  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
											  sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }    


    void sMultirobotInstance::to_Memory_TokenMddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	//	s_GlobalPhaseStatistics.enter_Phase("Counting");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    encoding_context.m_bit_generator->cast_Implication(solver,
											     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
											     sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			encoding_context.m_bit_generator->cast_MultiConjunctiveImplication(solver,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
											   prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}
	if (!cardinality_Identifiers.empty())
	{
	    encoding_context.m_bit_generator->cast_Cardinality(solver, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);

		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		std::vector<sBitClauseGenerator::SpecifiedBitIdentifiers_vector> mutex_source_Identifiers;		
		mutex_source_Identifiers.resize(N_Vertices);		    				

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
												       sIntegerIndex(neighbor_index)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
												       sIntegerIndex(v)));
			    mutex_source_Identifiers[MDD[robot_id][layer + 1][v]].push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														    sIntegerIndex(neighbor_index)));			    
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    encoding_context.m_bit_generator->cast_MultiImplication(solver,
									    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
												    sIntegerIndex(u)),
									    mutex_target_Identifiers);

		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										      mutex_target_Identifiers);   
		}
		for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		{
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										      mutex_source_Identifiers[MDD[robot_id][layer + 1][v]]);
		}	       		
		encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										  mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				sBitClauseGenerator::SpecifiedBitIdentifiers_vector complementary_edge_Identifiers;
				
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (robot_id != other_robot_id)
				    {
					int vv;
					
					for (vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						break;
					    }
					}

					if (vv < MDD[other_robot_id][layer].size())
					{
					    int other_neighbor_index = 0;
					    for (int w = 0; w < MDD[other_robot_id][layer + 1].size(); ++w)
					    {					    
						if (m_environment.is_Adjacent(MDD[other_robot_id][layer][vv], MDD[other_robot_id][layer + 1][w]) || MDD[other_robot_id][layer][vv] == MDD[other_robot_id][layer + 1][w])
						{
						    if (MDD[other_robot_id][layer][vv] != MDD[other_robot_id][layer + 1][w])
						    {
							if (MDD[other_robot_id][layer + 1][w] == MDD[robot_id][layer][u])
							{
							    complementary_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][vv], sIntegerIndex(other_neighbor_index)));
							}
						    }
						    ++other_neighbor_index;
						}
					    }
					}
				    }
				}
				if (!complementary_edge_Identifiers.empty())
				{
				    encoding_context.m_bit_generator->cast_MultiImplication(solver,
											    sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														    sIntegerIndex(neighbor_index)),
											    complementary_edge_Identifiers);
				}
				else
				{
				    encoding_context.m_bit_generator->cast_BitUnset(solver,
										    sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
													    sIntegerIndex(neighbor_index)));
				}
			    }
			    neighbor_index++;
			}
		    }
		}
	    }
	}		

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
											    mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
												    mutex_occupancy_Identifiers);
		}
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						
						encoding_context.m_bit_generator->cast_BiangleMutex(solver,
														   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	   sIntegerIndex(neighbor_index)),
														   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	   sIntegerIndex(vv)));

					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}
*/
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    encoding_context.m_bit_generator->cast_BitSet(solver,
										sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													    sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }


    void sMultirobotInstance::to_Memory_TokenEmptyMddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	//	s_GlobalPhaseStatistics.enter_Phase("Counting");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			encoding_context.m_bit_generator->cast_MultiConjunctiveImplication(solver,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
											   prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}
	if (!cardinality_Identifiers.empty())
	{
	    encoding_context.m_bit_generator->cast_Cardinality(solver, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);

		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		std::vector<sBitClauseGenerator::SpecifiedBitIdentifiers_vector> mutex_source_Identifiers;		
		mutex_source_Identifiers.resize(N_Vertices);		    				

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
												       sIntegerIndex(neighbor_index)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
												       sIntegerIndex(v)));
			    mutex_source_Identifiers[MDD[robot_id][layer + 1][v]].push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														    sIntegerIndex(neighbor_index)));			    
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    encoding_context.m_bit_generator->cast_MultiImplication(solver,
									    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
												    sIntegerIndex(u)),
									    mutex_target_Identifiers);

		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										      mutex_target_Identifiers);   
		}
		for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		{
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										      mutex_source_Identifiers[MDD[robot_id][layer + 1][v]]);
		}	       		
		encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										  mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				sBitClauseGenerator::SpecifiedBitIdentifiers_vector complementary_edge_Identifiers, complementary_node_Identifiers, biangular_Identifiers;
				
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (robot_id != other_robot_id)
				    {
					int vv = -1;
					
					for (vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						break;
					    }
					}
					sASSERT(vv >= 0);					

					if (vv < MDD[other_robot_id][layer].size())
					{
					    biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer], sIntegerIndex(vv)));
					    
					    int other_neighbor_index = 0;
					    for (int w = 0; w < MDD[other_robot_id][layer + 1].size(); ++w)
					    {					    
						if (m_environment.is_Adjacent(MDD[other_robot_id][layer][vv], MDD[other_robot_id][layer + 1][w]) || MDD[other_robot_id][layer][vv] == MDD[other_robot_id][layer + 1][w])
						{
						    if (MDD[other_robot_id][layer][vv] != MDD[other_robot_id][layer + 1][w])
						    {
							if (MDD[other_robot_id][layer + 1][w] == MDD[robot_id][layer][u])
							{
							    complementary_node_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer], sIntegerIndex(vv)));
//							    complementary_node_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer + 1], sIntegerIndex(w)));
							    complementary_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][vv], sIntegerIndex(other_neighbor_index)));
							}
						    }
						    ++other_neighbor_index;
						}
					    }
					}
				    }
				}
				if (!complementary_edge_Identifiers.empty())
				{
				    sASSERT(!complementary_node_Identifiers.empty());
				    encoding_context.m_bit_generator->cast_MultiImpliedImplication(solver,
												   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															   sIntegerIndex(neighbor_index)),
												   complementary_node_Identifiers, complementary_edge_Identifiers);
				    /*
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
				                                                                              total_Literal_cnt,	
														     sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	     sIntegerIndex(neighbor_index)),
														     complementary_edge_Identifiers);
				    */				    
				}
				else
				{
				    encoding_context.m_bit_generator->cast_MultiBiangleMutex(solver,
											     sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														     sIntegerIndex(neighbor_index)),
											     biangular_Identifiers);
				}
			    }
			    neighbor_index++;
			}
		    }
		}
	    }
	}		

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
									      mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										      mutex_occupancy_Identifiers);
		}
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						
						encoding_context.m_bit_generator->cast_BiangleMutex(solver,
														   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	   sIntegerIndex(neighbor_index)),
														   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	   sIntegerIndex(vv)));

					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}
*/
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    encoding_context.m_bit_generator->cast_BitSet(solver,
										sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													    sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													    sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }        


    void sMultirobotInstance::to_Memory_PermutationMddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	//	s_GlobalPhaseStatistics.enter_Phase("Counting");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			encoding_context.m_bit_generator->cast_MultiConjunctiveImplication(solver,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
											   prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}
	if (!cardinality_Identifiers.empty())
	{
	    encoding_context.m_bit_generator->cast_Cardinality(solver, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);

		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		std::vector<sBitClauseGenerator::SpecifiedBitIdentifiers_vector> mutex_source_Identifiers;		
		mutex_source_Identifiers.resize(N_Vertices);		    				

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
												       sIntegerIndex(neighbor_index)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
												       sIntegerIndex(v)));
			    mutex_source_Identifiers[MDD[robot_id][layer + 1][v]].push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														    sIntegerIndex(neighbor_index)));			    
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    encoding_context.m_bit_generator->cast_MultiImplication(solver,
									    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
												    sIntegerIndex(u)),
									    mutex_target_Identifiers);

		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										      mutex_target_Identifiers);   
		}
		for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		{
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										      mutex_source_Identifiers[MDD[robot_id][layer + 1][v]]);
		}	       		
		encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										  mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				sBitClauseGenerator::SpecifiedBitIdentifiers_vector complementary_edge_Identifiers;
				
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (robot_id != other_robot_id)
				    {
					int vv;
					
					for (vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						break;
					    }
					}

					if (vv < MDD[other_robot_id][layer].size())
					{
					    int other_neighbor_index = 0;
					    for (int w = 0; w < MDD[other_robot_id][layer + 1].size(); ++w)
					    {					    
						if (m_environment.is_Adjacent(MDD[other_robot_id][layer][vv], MDD[other_robot_id][layer + 1][w]) || MDD[other_robot_id][layer][vv] == MDD[other_robot_id][layer + 1][w])
						{
						    if (MDD[other_robot_id][layer][vv] != MDD[other_robot_id][layer + 1][w])
						    {
							if (MDD[other_robot_id][layer + 1][w] == MDD[robot_id][layer][u])
							{
							    complementary_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][vv], sIntegerIndex(other_neighbor_index)));
							}
						    }
						    ++other_neighbor_index;
						}
					    }
					}
				    }
				}
				if (!complementary_edge_Identifiers.empty())
				{
				    encoding_context.m_bit_generator->cast_MultiNegativeImplication(solver,
												    sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															    sIntegerIndex(neighbor_index)),
												    complementary_edge_Identifiers);
				}
				/*
				else
				{
				    encoding_context.m_bit_generator->cast_BitUnset(solver,
										    sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
													    sIntegerIndex(neighbor_index)));
				}
				*/
			    }
			    neighbor_index++;
			}
		    }
		}
	    }
	}		

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
											    mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
												    mutex_occupancy_Identifiers);
		}
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						
						encoding_context.m_bit_generator->cast_BiangleMutex(solver,
														   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	   sIntegerIndex(neighbor_index)),
														   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	   sIntegerIndex(vv)));

					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}
*/
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    encoding_context.m_bit_generator->cast_BitSet(solver,
										sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													    sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													    sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }


    void sMultirobotInstance::to_Memory_CapacitatedPermutationMddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	//	s_GlobalPhaseStatistics.enter_Phase("Counting");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			encoding_context.m_bit_generator->cast_MultiConjunctiveImplication(solver,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
											   prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}
	if (!cardinality_Identifiers.empty())
	{
	    encoding_context.m_bit_generator->cast_Cardinality(solver, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);

		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		std::vector<sBitClauseGenerator::SpecifiedBitIdentifiers_vector> mutex_source_Identifiers;		
		mutex_source_Identifiers.resize(N_Vertices);		    				

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
												       sIntegerIndex(neighbor_index)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
												       sIntegerIndex(v)));
			    mutex_source_Identifiers[MDD[robot_id][layer + 1][v]].push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														    sIntegerIndex(neighbor_index)));			    
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    encoding_context.m_bit_generator->cast_MultiImplication(solver,
									    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
												    sIntegerIndex(u)),
									    mutex_target_Identifiers);

		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										      mutex_target_Identifiers);   
		}
		for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		{
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										      mutex_source_Identifiers[MDD[robot_id][layer + 1][v]]);
		}
		/*
		encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										  mutex_vertex_Identifiers);
		*/
	    }
	}

	for (int layer = 0; layer <= N_Layers; ++layer)
	{
	    std::vector<sBitClauseGenerator::SpecifiedBitIdentifiers_vector> vertex_capacity_Identifiers;
	    vertex_capacity_Identifiers.resize(N_Vertices);
	    
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    vertex_capacity_Identifiers[MDD[robot_id][layer][u]].push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
		}
	    }
	    for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	    {
		if (vertex_capacity_Identifiers[vertex_id].size() > m_environment.m_Vertices[vertex_id].m_capacity)
		{
		    encoding_context.m_bit_generator->cast_Cardinality(solver,
								       vertex_capacity_Identifiers[vertex_id],
								       m_environment.m_Vertices[vertex_id].m_capacity);
		}
	    }	    
	}	

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				sBitClauseGenerator::SpecifiedBitIdentifiers_vector complementary_edge_Identifiers;
				
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (robot_id != other_robot_id)
				    {
					int vv;
					
					for (vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						break;
					    }
					}

					if (vv < MDD[other_robot_id][layer].size())
					{
					    int other_neighbor_index = 0;
					    for (int w = 0; w < MDD[other_robot_id][layer + 1].size(); ++w)
					    {					    
						if (m_environment.is_Adjacent(MDD[other_robot_id][layer][vv], MDD[other_robot_id][layer + 1][w]) || MDD[other_robot_id][layer][vv] == MDD[other_robot_id][layer + 1][w])
						{
						    if (MDD[other_robot_id][layer][vv] != MDD[other_robot_id][layer + 1][w])
						    {
							if (MDD[other_robot_id][layer + 1][w] == MDD[robot_id][layer][u])
							{
							    complementary_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][vv], sIntegerIndex(other_neighbor_index)));
							}
						    }
						    ++other_neighbor_index;
						}
					    }
					}
				    }
				}
				if (!complementary_edge_Identifiers.empty())
				{
				    encoding_context.m_bit_generator->cast_MultiNegativeImplication(solver,
												    sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															    sIntegerIndex(neighbor_index)),
												    complementary_edge_Identifiers);
				}
				/*
				else
				{
				    encoding_context.m_bit_generator->cast_BitUnset(solver,
										    sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
													    sIntegerIndex(neighbor_index)));
				}
				*/
			    }
			    neighbor_index++;
			}
		    }
		}
	    }
	}		

	/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
	                                                                      mutex_vertex_Identifiers);
	}
	*/

	/*
	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										      mutex_occupancy_Identifiers);
		}
	    }
	}
	*/
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						
						encoding_context.m_bit_generator->cast_BiangleMutex(solver,
														   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	   sIntegerIndex(neighbor_index)),
														   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	   sIntegerIndex(vv)));

					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}
*/
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    encoding_context.m_bit_generator->cast_BitSet(solver,
										sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													    sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													    sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }        
    
    
    void sMultirobotInstance::to_Stream_MmddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const MDD_vector &MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int Clause_cnt = 0;
	int aux_Variable_cnt = 0;
	int total_Literal_cnt = 0;

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = encoding_context.m_N_Layers;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														      sIntegerIndex(neighbor_index)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														      sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
											   total_Literal_cnt,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(u)),
											   mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
											 total_Literal_cnt,
											 mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
										     total_Literal_cnt,
										     mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						Clause_cnt += encoding_context.m_bit_generator->count_BiangleMutex(aux_Variable_cnt,
														   total_Literal_cnt,
														   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	   sIntegerIndex(neighbor_index)),
														   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	   sIntegerIndex(vv)));
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										 total_Literal_cnt,
										 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													 sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}

	int N_cnf_Variables = encoding_context.m_variable_store.get_Last_CNFVariable() + aux_Variable_cnt - 1;

#ifdef sDEBUG
	fprintf(fw, "c %s : multirobot MDD SAT encoding\n", sPRODUCT);
	fprintf(fw, "c %s\n", sCOPYRIGHT);
	fprintf(fw, "c number of layers = %d\n", N_Layers);
	fprintf(fw, "c number of visible variables = %d\n", N_cnf_Variables - aux_Variable_cnt);
	fprintf(fw, "c number of hidden variables = %d\n", aux_Variable_cnt);
	fprintf(fw, "c number of literals = %d\n", total_Literal_cnt);
	fprintf(fw, "c number of clauses = %d\n", Clause_cnt);
	fprintf(fw, "c number of propositional variables = %d\n", N_cnf_Variables);
	fprintf(fw, "c number of clauses / number of variables = %.3f\n", (double)Clause_cnt / N_cnf_Variables);
	fprintf(fw, "c number of literals / number of clauses = %.3f\n", (double)total_Literal_cnt /  Clause_cnt);
	to_Stream(fw, "c ");
#endif
	fprintf(fw, "p cnf %d %d\n", N_cnf_Variables, Clause_cnt);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															 sIntegerIndex(neighbor_index)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
															 sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
												mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
											    mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
											mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
												mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						Clause_cnt += encoding_context.m_bit_generator->generate_BiangleMutex(fw,
														      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	      sIntegerIndex(neighbor_index)),
														      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	      sIntegerIndex(vv)));
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													    sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }


    void sMultirobotInstance::to_Memory_MmddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const MDD_vector &MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = encoding_context.m_N_Layers;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    encoding_context.m_bit_generator->cast_Implication(solver,
											     sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														     sIntegerIndex(neighbor_index)),
											     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														     sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    encoding_context.m_bit_generator->cast_MultiImplication(solver,
											  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														  sIntegerIndex(u)),
											  mutex_target_Identifiers);

		    encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
											    mutex_target_Identifiers);   
		}
		encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
											mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
										    mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
											    mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						encoding_context.m_bit_generator->cast_BiangleMutex(solver,
														  sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	  sIntegerIndex(neighbor_index)),
														  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	  sIntegerIndex(vv)));
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    encoding_context.m_bit_generator->cast_BitSet(solver,
										sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id) // non-anonymous
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
            /*   
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id) // anonymous
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector goal_Identifiers;
		
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    for (int some_robot_id = 1; some_robot_id <= N_Robots; ++some_robot_id)
		    {
		
			if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(some_robot_id).begin())
			{
			    goal_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
									       sIntegerIndex(u)));
			}
		    }
		}
		encoding_context.m_bit_generator->cast_Disjunction(solver, goal_Identifiers);
	    }
            */
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }    


    void sMultirobotInstance::to_Stream_RelaxedMmddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const MDD_vector &MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int Clause_cnt = 0;
	int aux_Variable_cnt = 0;
	int total_Literal_cnt = 0;

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = encoding_context.m_N_Layers;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														      sIntegerIndex(neighbor_index)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														      sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
		    
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
											   total_Literal_cnt,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(u)),
											   mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												 total_Literal_cnt,
												 mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						/*
						Clause_cnt += encoding_context.m_bit_generator->count_BiangleMutex(aux_Variable_cnt,
														   total_Literal_cnt,
														   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	   sIntegerIndex(neighbor_index)),
														   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	   sIntegerIndex(vv)));
						*/
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										 total_Literal_cnt,
										 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													 sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}

	int N_cnf_Variables = encoding_context.m_variable_store.get_Last_CNFVariable() + aux_Variable_cnt - 1;

#ifdef sDEBUG
	fprintf(fw, "c %s : multirobot relaxed MMDD SAT encoding\n", sPRODUCT);
	fprintf(fw, "c %s\n", sCOPYRIGHT);
	fprintf(fw, "c number of layers = %d\n", N_Layers);
	fprintf(fw, "c number of visible variables = %d\n", N_cnf_Variables - aux_Variable_cnt);
	fprintf(fw, "c number of hidden variables = %d\n", aux_Variable_cnt);
	fprintf(fw, "c number of literals = %d\n", total_Literal_cnt);
	fprintf(fw, "c number of clauses = %d\n", Clause_cnt);
	fprintf(fw, "c number of propositional variables = %d\n", N_cnf_Variables);
	fprintf(fw, "c number of clauses / number of variables = %.3f\n", (double)Clause_cnt / N_cnf_Variables);
	fprintf(fw, "c number of literals / number of clauses = %.3f\n", (double)total_Literal_cnt /  Clause_cnt);
	to_Stream(fw, "c ");
#endif
	fprintf(fw, "p cnf %d %d\n", N_cnf_Variables, Clause_cnt);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															 sIntegerIndex(neighbor_index)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
															 sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												    mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						/*
						Clause_cnt += encoding_context.m_bit_generator->generate_BiangleMutex(fw,
														      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	      sIntegerIndex(neighbor_index)),
														      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	      sIntegerIndex(vv)));
						*/
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													    sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }


    void sMultirobotInstance::to_Stream_TokenMmddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const MDD_vector &MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int Clause_cnt = 0;
	int aux_Variable_cnt = 0;
	int total_Literal_cnt = 0;

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = encoding_context.m_N_Layers;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														      sIntegerIndex(neighbor_index)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														      sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
		    
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
											   total_Literal_cnt,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(u)),
											   mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												 total_Literal_cnt,
												 mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				sBitClauseGenerator::SpecifiedBitIdentifiers_vector complementary_edge_Identifiers;
				
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (robot_id != other_robot_id)
				    {
					int vv = -1;
					
					for (vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						break;
					    }
					}
					sASSERT(vv >= 0);					

					if (vv < MDD[other_robot_id][layer].size())
					{
					    int other_neighbor_index = 0;
					    for (int w = 0; w < MDD[other_robot_id][layer + 1].size(); ++w)
					    {					    
						if (m_environment.is_Adjacent(MDD[other_robot_id][layer][vv], MDD[other_robot_id][layer + 1][w]) || MDD[other_robot_id][layer][vv] == MDD[other_robot_id][layer + 1][w])
						{
						    if (MDD[other_robot_id][layer][vv] != MDD[other_robot_id][layer + 1][w])
						    {
							if (MDD[other_robot_id][layer + 1][w] == MDD[robot_id][layer][u])
							{
							    complementary_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][vv], sIntegerIndex(other_neighbor_index)));
							}
						    }
						    ++other_neighbor_index;
						}
					    }
					}
				    }
				}
				if (!complementary_edge_Identifiers.empty())
				{
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
													   total_Literal_cnt,
													   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																   sIntegerIndex(neighbor_index)),
													   complementary_edge_Identifiers);
				}
				else
				{
				    Clause_cnt += encoding_context.m_bit_generator->count_BitUnset(aux_Variable_cnt,
												   total_Literal_cnt,
												   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															   sIntegerIndex(neighbor_index)));
				}
			    }
			    neighbor_index++;
			}
		    }
		}
	    }
	}	
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						/*
						Clause_cnt += encoding_context.m_bit_generator->count_BiangleMutex(aux_Variable_cnt,
														   total_Literal_cnt,
														   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	   sIntegerIndex(neighbor_index)),
														   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	   sIntegerIndex(vv)));
						*/
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										 total_Literal_cnt,
										 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													 sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}

	int N_cnf_Variables = encoding_context.m_variable_store.get_Last_CNFVariable() + aux_Variable_cnt - 1;

#ifdef sDEBUG
	fprintf(fw, "c %s : multirobot token MMDD SAT encoding\n", sPRODUCT);
	fprintf(fw, "c %s\n", sCOPYRIGHT);
	fprintf(fw, "c number of layers = %d\n", N_Layers);
	fprintf(fw, "c number of visible variables = %d\n", N_cnf_Variables - aux_Variable_cnt);
	fprintf(fw, "c number of hidden variables = %d\n", aux_Variable_cnt);
	fprintf(fw, "c number of literals = %d\n", total_Literal_cnt);
	fprintf(fw, "c number of clauses = %d\n", Clause_cnt);
	fprintf(fw, "c number of propositional variables = %d\n", N_cnf_Variables);
	fprintf(fw, "c number of clauses / number of variables = %.3f\n", (double)Clause_cnt / N_cnf_Variables);
	fprintf(fw, "c number of literals / number of clauses = %.3f\n", (double)total_Literal_cnt /  Clause_cnt);
	to_Stream(fw, "c ");
#endif
	fprintf(fw, "p cnf %d %d\n", N_cnf_Variables, Clause_cnt);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															 sIntegerIndex(neighbor_index)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
															 sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												    mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				sBitClauseGenerator::SpecifiedBitIdentifiers_vector complementary_edge_Identifiers;
				
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (robot_id != other_robot_id)
				    {
					int vv = -1;
					
					for (vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						break;
					    }
					}
					sASSERT(vv >= 0);

					if (vv < MDD[other_robot_id][layer].size())
					{
					    int other_neighbor_index = 0;
					    for (int w = 0; w < MDD[other_robot_id][layer + 1].size(); ++w)
					    {					    
						if (m_environment.is_Adjacent(MDD[other_robot_id][layer][vv], MDD[other_robot_id][layer + 1][w]) || MDD[other_robot_id][layer][vv] == MDD[other_robot_id][layer + 1][w])
						{
						    if (MDD[other_robot_id][layer][vv] != MDD[other_robot_id][layer + 1][w])
						    {
							if (MDD[other_robot_id][layer + 1][w] == MDD[robot_id][layer][u])
							{
							    complementary_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][vv], sIntegerIndex(other_neighbor_index)));
							}
						    }
						    ++other_neighbor_index;
						}
					    }
					}
				    }
				}
				if (!complementary_edge_Identifiers.empty())
				{
				    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
													      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																      sIntegerIndex(neighbor_index)),
													      complementary_edge_Identifiers);
				}
				else
				{
				    Clause_cnt += encoding_context.m_bit_generator->generate_BitUnset(fw,
												      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															      sIntegerIndex(neighbor_index)));
				}

			    }
			    neighbor_index++;
			}
		    }
		}
	    }
	}		
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						/*
						Clause_cnt += encoding_context.m_bit_generator->generate_BiangleMutex(fw,
														      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	      sIntegerIndex(neighbor_index)),
														      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	      sIntegerIndex(vv)));
						*/
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													    sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }        


    void sMultirobotInstance::to_Stream_TokenEmptyMmddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const MDD_vector &MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int Clause_cnt = 0;
	int aux_Variable_cnt = 0;
	int total_Literal_cnt = 0;

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = encoding_context.m_N_Layers;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														      sIntegerIndex(neighbor_index)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														      sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
		    
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
											   total_Literal_cnt,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(u)),
											   mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												 total_Literal_cnt,
												 mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				sBitClauseGenerator::SpecifiedBitIdentifiers_vector complementary_edge_Identifiers, complementary_node_Identifiers, biangular_Identifiers;				
				
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (robot_id != other_robot_id)
				    {
					int vv = -1;
					
					for (vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						break;
					    }
					}
					sASSERT(vv >= 0);					

					if (vv < MDD[other_robot_id][layer].size())
					{
					    biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer], sIntegerIndex(vv)));
					    
					    int other_neighbor_index = 0;
					    for (int w = 0; w < MDD[other_robot_id][layer + 1].size(); ++w)
					    {					    
						if (m_environment.is_Adjacent(MDD[other_robot_id][layer][vv], MDD[other_robot_id][layer + 1][w]) || MDD[other_robot_id][layer][vv] == MDD[other_robot_id][layer + 1][w])
						{
						    if (MDD[other_robot_id][layer][vv] != MDD[other_robot_id][layer + 1][w])
						    {
							if (MDD[other_robot_id][layer + 1][w] == MDD[robot_id][layer][u])
							{
							    complementary_node_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer], sIntegerIndex(vv)));
//							    complementary_node_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer + 1], sIntegerIndex(w)));
							    complementary_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][vv], sIntegerIndex(other_neighbor_index)));
							}
						    }
						    ++other_neighbor_index;
						}
					    }
					}
				    }
				}
				if (!complementary_edge_Identifiers.empty())
				{
				    sASSERT(!complementary_node_Identifiers.empty());
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiImpliedImplication(aux_Variable_cnt,
														     total_Literal_cnt,
														     sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	     sIntegerIndex(neighbor_index)),
														     complementary_node_Identifiers, complementary_edge_Identifiers);
				    /*
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
				                                                                              total_Literal_cnt,	
														     sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	     sIntegerIndex(neighbor_index)),
														     complementary_edge_Identifiers);
				    */				    
				}
				else
				{
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiBiangleMutex(aux_Variable_cnt,
													    total_Literal_cnt,
													    sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																    sIntegerIndex(neighbor_index)),
													    biangular_Identifiers);
				}
			    }
			    neighbor_index++;
			}
		    }
		}
	    }
	}	
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						/*
						Clause_cnt += encoding_context.m_bit_generator->count_BiangleMutex(aux_Variable_cnt,
														   total_Literal_cnt,
														   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	   sIntegerIndex(neighbor_index)),
														   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	   sIntegerIndex(vv)));
						*/
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										 total_Literal_cnt,
										 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													 sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}

	int N_cnf_Variables = encoding_context.m_variable_store.get_Last_CNFVariable() + aux_Variable_cnt - 1;

#ifdef sDEBUG
	fprintf(fw, "c %s : multirobot token empty MMDD SAT encoding\n", sPRODUCT);
	fprintf(fw, "c %s\n", sCOPYRIGHT);
	fprintf(fw, "c number of layers = %d\n", N_Layers);
	fprintf(fw, "c number of visible variables = %d\n", N_cnf_Variables - aux_Variable_cnt);
	fprintf(fw, "c number of hidden variables = %d\n", aux_Variable_cnt);
	fprintf(fw, "c number of literals = %d\n", total_Literal_cnt);
	fprintf(fw, "c number of clauses = %d\n", Clause_cnt);
	fprintf(fw, "c number of propositional variables = %d\n", N_cnf_Variables);
	fprintf(fw, "c number of clauses / number of variables = %.3f\n", (double)Clause_cnt / N_cnf_Variables);
	fprintf(fw, "c number of literals / number of clauses = %.3f\n", (double)total_Literal_cnt /  Clause_cnt);
	to_Stream(fw, "c ");
#endif
	fprintf(fw, "p cnf %d %d\n", N_cnf_Variables, Clause_cnt);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															 sIntegerIndex(neighbor_index)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
															 sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												    mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				sBitClauseGenerator::SpecifiedBitIdentifiers_vector complementary_edge_Identifiers, complementary_node_Identifiers, biangular_Identifiers;				
				
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (robot_id != other_robot_id)
				    {
					int vv = -1;
					
					for (vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						break;
					    }
					}
					sASSERT(vv >= 0);

					if (vv < MDD[other_robot_id][layer].size())
					{
					    biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer], sIntegerIndex(vv)));
					    
					    int other_neighbor_index = 0;
					    for (int w = 0; w < MDD[other_robot_id][layer + 1].size(); ++w)
					    {					    
						if (m_environment.is_Adjacent(MDD[other_robot_id][layer][vv], MDD[other_robot_id][layer + 1][w]) || MDD[other_robot_id][layer][vv] == MDD[other_robot_id][layer + 1][w])
						{
						    if (MDD[other_robot_id][layer][vv] != MDD[other_robot_id][layer + 1][w])
						    {
							if (MDD[other_robot_id][layer + 1][w] == MDD[robot_id][layer][u])
							{
							    complementary_node_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer], sIntegerIndex(vv)));
//							    complementary_node_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer + 1], sIntegerIndex(w)));
							    complementary_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][vv], sIntegerIndex(other_neighbor_index)));
							}
						    }
						    ++other_neighbor_index;
						}
					    }
					}
				    }
				}
				if (!complementary_edge_Identifiers.empty())
				{
				    sASSERT(!complementary_node_Identifiers.empty());
				    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImpliedImplication(fw,
														     sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	     sIntegerIndex(neighbor_index)),
														     complementary_node_Identifiers, complementary_edge_Identifiers);
				    /*
				    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
														     sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	     sIntegerIndex(neighbor_index)),
														     complementary_edge_Identifiers);
				    */
				}
				else
				{
				    Clause_cnt += encoding_context.m_bit_generator->generate_MultiBiangleMutex(fw,
													       sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																       sIntegerIndex(neighbor_index)),
													       biangular_Identifiers);				    
				}

			    }
			    neighbor_index++;
			}
		    }
		}
	    }
	}		
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						/*
						Clause_cnt += encoding_context.m_bit_generator->generate_BiangleMutex(fw,
														      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	      sIntegerIndex(neighbor_index)),
														      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	      sIntegerIndex(vv)));
						*/
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													    sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }        
    
    
    void sMultirobotInstance::to_Stream_PermutationMmddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const MDD_vector &MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int Clause_cnt = 0;
	int aux_Variable_cnt = 0;
	int total_Literal_cnt = 0;

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = encoding_context.m_N_Layers;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														      sIntegerIndex(neighbor_index)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														      sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
		    
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
											   total_Literal_cnt,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(u)),
											   mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												 total_Literal_cnt,
												 mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				sBitClauseGenerator::SpecifiedBitIdentifiers_vector complementary_edge_Identifiers;
				
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (robot_id != other_robot_id)
				    {
					int vv;
					
					for (vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						break;
					    }
					}

					if (vv < MDD[other_robot_id][layer].size())
					{
					    int other_neighbor_index = 0;
					    for (int w = 0; w < MDD[other_robot_id][layer + 1].size(); ++w)
					    {					    
						if (m_environment.is_Adjacent(MDD[other_robot_id][layer][vv], MDD[other_robot_id][layer + 1][w]) || MDD[other_robot_id][layer][vv] == MDD[other_robot_id][layer + 1][w])
						{
						    if (MDD[other_robot_id][layer][vv] != MDD[other_robot_id][layer + 1][w])
						    {
							if (MDD[other_robot_id][layer + 1][w] == MDD[robot_id][layer][u])
							{
							    complementary_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][vv], sIntegerIndex(other_neighbor_index)));
							}
						    }
						    ++other_neighbor_index;
						}
					    }
					}
				    }
				}
				if (!complementary_edge_Identifiers.empty())
				{
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiNegativeImplication(aux_Variable_cnt,
														   total_Literal_cnt,
														   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	   sIntegerIndex(neighbor_index)),
														   complementary_edge_Identifiers);
				}
			    }
			    neighbor_index++;
			}
		    }
		}
	    }
	}	
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						/*
						Clause_cnt += encoding_context.m_bit_generator->count_BiangleMutex(aux_Variable_cnt,
														   total_Literal_cnt,
														   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	   sIntegerIndex(neighbor_index)),
														   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	   sIntegerIndex(vv)));
						*/
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										 total_Literal_cnt,
										 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													 sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}

	int N_cnf_Variables = encoding_context.m_variable_store.get_Last_CNFVariable() + aux_Variable_cnt - 1;

#ifdef sDEBUG
	fprintf(fw, "c %s : multirobot permutation MMDD SAT encoding\n", sPRODUCT);
	fprintf(fw, "c %s\n", sCOPYRIGHT);
	fprintf(fw, "c number of layers = %d\n", N_Layers);
	fprintf(fw, "c number of visible variables = %d\n", N_cnf_Variables - aux_Variable_cnt);
	fprintf(fw, "c number of hidden variables = %d\n", aux_Variable_cnt);
	fprintf(fw, "c number of literals = %d\n", total_Literal_cnt);
	fprintf(fw, "c number of clauses = %d\n", Clause_cnt);
	fprintf(fw, "c number of propositional variables = %d\n", N_cnf_Variables);
	fprintf(fw, "c number of clauses / number of variables = %.3f\n", (double)Clause_cnt / N_cnf_Variables);
	fprintf(fw, "c number of literals / number of clauses = %.3f\n", (double)total_Literal_cnt /  Clause_cnt);
	to_Stream(fw, "c ");
#endif
	fprintf(fw, "p cnf %d %d\n", N_cnf_Variables, Clause_cnt);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															 sIntegerIndex(neighbor_index)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
															 sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												    mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				sBitClauseGenerator::SpecifiedBitIdentifiers_vector complementary_edge_Identifiers;
				
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (robot_id != other_robot_id)
				    {
					int vv;
					
					for (vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						break;
					    }
					}

					if (vv < MDD[other_robot_id][layer].size())
					{
					    int other_neighbor_index = 0;
					    for (int w = 0; w < MDD[other_robot_id][layer + 1].size(); ++w)
					    {					    
						if (m_environment.is_Adjacent(MDD[other_robot_id][layer][vv], MDD[other_robot_id][layer + 1][w]) || MDD[other_robot_id][layer][vv] == MDD[other_robot_id][layer + 1][w])
						{
						    if (MDD[other_robot_id][layer][vv] != MDD[other_robot_id][layer + 1][w])
						    {
							if (MDD[other_robot_id][layer + 1][w] == MDD[robot_id][layer][u])
							{
							    complementary_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][vv], sIntegerIndex(other_neighbor_index)));
							}
						    }
						    ++other_neighbor_index;
						}
					    }
					}
				    }
				}
				if (!complementary_edge_Identifiers.empty())
				{
				    Clause_cnt += encoding_context.m_bit_generator->generate_MultiNegativeImplication(fw,
														      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	      sIntegerIndex(neighbor_index)),
														      complementary_edge_Identifiers);
				}
			    }
			    neighbor_index++;
			}
		    }
		}
	    }
	}		
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						/*
						Clause_cnt += encoding_context.m_bit_generator->generate_BiangleMutex(fw,
														      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	      sIntegerIndex(neighbor_index)),
														      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	      sIntegerIndex(vv)));
						*/
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													    sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }        


    void sMultirobotInstance::to_Stream_CapacitatedPermutationMmddCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const MDD_vector &MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int Clause_cnt = 0;
	int aux_Variable_cnt = 0;
	int total_Literal_cnt = 0;

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = encoding_context.m_N_Layers;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														      sIntegerIndex(neighbor_index)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														      sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
		    
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
											   total_Literal_cnt,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(u)),
											   mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_target_Identifiers);   
		}
		/*
		Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												 total_Literal_cnt,
												 mutex_vertex_Identifiers);
		*/
	    }
	}

	for (int layer = 0; layer <= N_Layers; ++layer)
	{
	    std::vector<sBitClauseGenerator::SpecifiedBitIdentifiers_vector> vertex_capacity_Identifiers;
	    vertex_capacity_Identifiers.resize(N_Vertices);
	    
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    vertex_capacity_Identifiers[MDD[robot_id][layer][u]].push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
		}
	    }
	    for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	    {
		if (vertex_capacity_Identifiers[vertex_id].size() > m_environment.m_Vertices[vertex_id].m_capacity)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_Cardinality(aux_Variable_cnt,
										      total_Literal_cnt,
										      vertex_capacity_Identifiers[vertex_id],
										      m_environment.m_Vertices[vertex_id].m_capacity);
		}
	    }	    
	}	
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				sBitClauseGenerator::SpecifiedBitIdentifiers_vector complementary_edge_Identifiers;
				
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (robot_id != other_robot_id)
				    {
					int vv;
					
					for (vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						break;
					    }
					}

					if (vv < MDD[other_robot_id][layer].size())
					{
					    int other_neighbor_index = 0;
					    for (int w = 0; w < MDD[other_robot_id][layer + 1].size(); ++w)
					    {					    
						if (m_environment.is_Adjacent(MDD[other_robot_id][layer][vv], MDD[other_robot_id][layer + 1][w]) || MDD[other_robot_id][layer][vv] == MDD[other_robot_id][layer + 1][w])
						{
						    if (MDD[other_robot_id][layer][vv] != MDD[other_robot_id][layer + 1][w])
						    {
							if (MDD[other_robot_id][layer + 1][w] == MDD[robot_id][layer][u])
							{
							    complementary_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][vv], sIntegerIndex(other_neighbor_index)));
							}
						    }
						    ++other_neighbor_index;
						}
					    }
					}
				    }
				}
				if (!complementary_edge_Identifiers.empty())
				{
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiNegativeImplication(aux_Variable_cnt,
														   total_Literal_cnt,
														   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	   sIntegerIndex(neighbor_index)),
														   complementary_edge_Identifiers);
				}
			    }
			    neighbor_index++;
			}
		    }
		}
	    }
	}	

	/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_vertex_Identifiers);
	}
	*/

	/*
	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_occupancy_Identifiers);
		}
	    }
	}
	*/

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						/*
						Clause_cnt += encoding_context.m_bit_generator->count_BiangleMutex(aux_Variable_cnt,
														   total_Literal_cnt,
														   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	   sIntegerIndex(neighbor_index)),
														   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	   sIntegerIndex(vv)));
						*/
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										 total_Literal_cnt,
										 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													 sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}

	int N_cnf_Variables = encoding_context.m_variable_store.get_Last_CNFVariable() + aux_Variable_cnt - 1;

#ifdef sDEBUG
	fprintf(fw, "c %s : multirobot permutation CMMDD SAT encoding\n", sPRODUCT);
	fprintf(fw, "c %s\n", sCOPYRIGHT);
	fprintf(fw, "c number of layers = %d\n", N_Layers);
	fprintf(fw, "c number of visible variables = %d\n", N_cnf_Variables - aux_Variable_cnt);
	fprintf(fw, "c number of hidden variables = %d\n", aux_Variable_cnt);
	fprintf(fw, "c number of literals = %d\n", total_Literal_cnt);
	fprintf(fw, "c number of clauses = %d\n", Clause_cnt);
	fprintf(fw, "c number of propositional variables = %d\n", N_cnf_Variables);
	fprintf(fw, "c number of clauses / number of variables = %.3f\n", (double)Clause_cnt / N_cnf_Variables);
	fprintf(fw, "c number of literals / number of clauses = %.3f\n", (double)total_Literal_cnt /  Clause_cnt);
	to_Stream(fw, "c ");
#endif
	fprintf(fw, "p cnf %d %d\n", N_cnf_Variables, Clause_cnt);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															 sIntegerIndex(neighbor_index)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
															 sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_target_Identifiers);   
		}
		/*
		Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												    mutex_vertex_Identifiers);
		*/
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				sBitClauseGenerator::SpecifiedBitIdentifiers_vector complementary_edge_Identifiers;
				
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (robot_id != other_robot_id)
				    {
					int vv;
					
					for (vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						break;
					    }
					}

					if (vv < MDD[other_robot_id][layer].size())
					{
					    int other_neighbor_index = 0;
					    for (int w = 0; w < MDD[other_robot_id][layer + 1].size(); ++w)
					    {					    
						if (m_environment.is_Adjacent(MDD[other_robot_id][layer][vv], MDD[other_robot_id][layer + 1][w]) || MDD[other_robot_id][layer][vv] == MDD[other_robot_id][layer + 1][w])
						{
						    if (MDD[other_robot_id][layer][vv] != MDD[other_robot_id][layer + 1][w])
						    {
							if (MDD[other_robot_id][layer + 1][w] == MDD[robot_id][layer][u])
							{
							    complementary_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][vv], sIntegerIndex(other_neighbor_index)));
							}
						    }
						    ++other_neighbor_index;
						}
					    }
					}
				    }
				}
				if (!complementary_edge_Identifiers.empty())
				{
				    Clause_cnt += encoding_context.m_bit_generator->generate_MultiNegativeImplication(fw,
														      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	      sIntegerIndex(neighbor_index)),
														      complementary_edge_Identifiers);
				}
			    }
			    neighbor_index++;
			}
		    }
		}
	    }
	}		

	/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												mutex_vertex_Identifiers);
	}
	*/
        /*
	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_occupancy_Identifiers);
		}
	    }
	}
	*/

	for (int layer = 0; layer <= N_Layers; ++layer)
	{
	    std::vector<sBitClauseGenerator::SpecifiedBitIdentifiers_vector> vertex_capacity_Identifiers;
	    vertex_capacity_Identifiers.resize(N_Vertices);
	    
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    vertex_capacity_Identifiers[MDD[robot_id][layer][u]].push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
		}
	    }
	    for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	    {
		if (vertex_capacity_Identifiers[vertex_id].size() > m_environment.m_Vertices[vertex_id].m_capacity)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_Cardinality(fw,
											 vertex_capacity_Identifiers[vertex_id],
											 m_environment.m_Vertices[vertex_id].m_capacity);
		}
	    }	    
	}		

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						/*
						Clause_cnt += encoding_context.m_bit_generator->generate_BiangleMutex(fw,
														      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	      sIntegerIndex(neighbor_index)),
														      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	      sIntegerIndex(vv)));
						*/
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													    sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }        
    
    
    void sMultirobotInstance::to_Memory_RelaxedMmddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const MDD_vector &MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = encoding_context.m_N_Layers;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
												       sIntegerIndex(neighbor_index)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
												       sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    encoding_context.m_bit_generator->cast_MultiImplication(solver,
									    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
												    sIntegerIndex(u)),
									    mutex_target_Identifiers);
		    
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										      mutex_target_Identifiers);   
		}
		encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										  mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
									      mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										      mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						/*
						encoding_context.m_bit_generator->cast_BiangleMutex(solver,
						sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
						sIntegerIndex(neighbor_index)),
						sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
						sIntegerIndex(vv)));
						*/
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    encoding_context.m_bit_generator->cast_BitSet(solver,
								  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
											  sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }    


    void sMultirobotInstance::to_Memory_TokenMmddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const MDD_vector &MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = encoding_context.m_N_Layers;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
												       sIntegerIndex(neighbor_index)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
												       sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    encoding_context.m_bit_generator->cast_MultiImplication(solver,
									    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
												    sIntegerIndex(u)),
									    mutex_target_Identifiers);
		    
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										      mutex_target_Identifiers);   
		}
		encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										  mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				sBitClauseGenerator::SpecifiedBitIdentifiers_vector complementary_edge_Identifiers;
				
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (robot_id != other_robot_id)
				    {
					int vv;
					
					for (vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						break;
					    }
					}

					if (vv < MDD[other_robot_id][layer].size())
					{
					    int other_neighbor_index = 0;
					    for (int w = 0; w < MDD[other_robot_id][layer + 1].size(); ++w)
					    {					    
						if (m_environment.is_Adjacent(MDD[other_robot_id][layer][vv], MDD[other_robot_id][layer + 1][w]) || MDD[other_robot_id][layer][vv] == MDD[other_robot_id][layer + 1][w])
						{
						    if (MDD[other_robot_id][layer][vv] != MDD[other_robot_id][layer + 1][w])
						    {
							if (MDD[other_robot_id][layer + 1][w] == MDD[robot_id][layer][u])
							{
							    complementary_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][vv], sIntegerIndex(other_neighbor_index)));
							}
						    }
						    ++other_neighbor_index;
						}
					    }
					}
				    }
				}
				if (!complementary_edge_Identifiers.empty())
				{
				    encoding_context.m_bit_generator->cast_MultiImplication(solver,
											    sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														    sIntegerIndex(neighbor_index)),
											    complementary_edge_Identifiers);
				}
				else
				{
				    encoding_context.m_bit_generator->cast_BitUnset(solver,
										    sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
													    sIntegerIndex(neighbor_index)));
				}
			    }
			    neighbor_index++;
			}
		    }
		}
	    }
	}		

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
									      mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										      mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						/*
						encoding_context.m_bit_generator->cast_BiangleMutex(solver,
						sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
						sIntegerIndex(neighbor_index)),
						sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
						sIntegerIndex(vv)));
						*/
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    encoding_context.m_bit_generator->cast_BitSet(solver,
								  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
											  sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }


    void sMultirobotInstance::to_Memory_TokenEmptyMmddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const MDD_vector &MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = encoding_context.m_N_Layers;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
												       sIntegerIndex(neighbor_index)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
												       sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    encoding_context.m_bit_generator->cast_MultiImplication(solver,
									    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
												    sIntegerIndex(u)),
									    mutex_target_Identifiers);
		    
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										      mutex_target_Identifiers);   
		}
		encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										  mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				sBitClauseGenerator::SpecifiedBitIdentifiers_vector complementary_edge_Identifiers, complementary_node_Identifiers, biangular_Identifiers;				
				
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (robot_id != other_robot_id)
				    {
					int vv = -1;
					
					for (vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						break;
					    }
					}
					sASSERT(vv >= 0);

					if (vv < MDD[other_robot_id][layer].size())
					{
					    biangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer], sIntegerIndex(vv)));
					    
					    int other_neighbor_index = 0;
					    for (int w = 0; w < MDD[other_robot_id][layer + 1].size(); ++w)
					    {					    
						if (m_environment.is_Adjacent(MDD[other_robot_id][layer][vv], MDD[other_robot_id][layer + 1][w]) || MDD[other_robot_id][layer][vv] == MDD[other_robot_id][layer + 1][w])
						{
						    if (MDD[other_robot_id][layer][vv] != MDD[other_robot_id][layer + 1][w])
						    {
							if (MDD[other_robot_id][layer + 1][w] == MDD[robot_id][layer][u])
							{
							    complementary_node_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer], sIntegerIndex(vv)));
//							    complementary_node_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer + 1], sIntegerIndex(w)));
							    complementary_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][vv], sIntegerIndex(other_neighbor_index)));
							}
						    }
						    ++other_neighbor_index;
						}
					    }
					}
				    }
				}
				if (!complementary_edge_Identifiers.empty())
				{
				    sASSERT(!complementary_node_Identifiers.empty());
				    encoding_context.m_bit_generator->cast_MultiImpliedImplication(solver,
												   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															   sIntegerIndex(neighbor_index)),
												   complementary_node_Identifiers, complementary_edge_Identifiers);
				    /*
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
				                                                                              total_Literal_cnt,	
														     sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	     sIntegerIndex(neighbor_index)),
														     complementary_edge_Identifiers);
				    */				    
				}
				else
				{
				    encoding_context.m_bit_generator->cast_MultiBiangleMutex(solver,
											     sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														     sIntegerIndex(neighbor_index)),
											     biangular_Identifiers);
				}
			    }
			    neighbor_index++;
			}
		    }
		}
	    }
	}		

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
									      mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										      mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						/*
						encoding_context.m_bit_generator->cast_BiangleMutex(solver,
						sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
						sIntegerIndex(neighbor_index)),
						sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
						sIntegerIndex(vv)));
						*/
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    encoding_context.m_bit_generator->cast_BitSet(solver,
								  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
											  sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }        


    void sMultirobotInstance::to_Memory_PermutationMmddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const MDD_vector &MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = encoding_context.m_N_Layers;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
												       sIntegerIndex(neighbor_index)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
												       sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    encoding_context.m_bit_generator->cast_MultiImplication(solver,
									    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
												    sIntegerIndex(u)),
									    mutex_target_Identifiers);
		    
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										      mutex_target_Identifiers);   
		}
		encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										  mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				sBitClauseGenerator::SpecifiedBitIdentifiers_vector complementary_edge_Identifiers;
				
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (robot_id != other_robot_id)
				    {
					int vv;
					
					for (vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						break;
					    }
					}

					if (vv < MDD[other_robot_id][layer].size())
					{
					    int other_neighbor_index = 0;
					    for (int w = 0; w < MDD[other_robot_id][layer + 1].size(); ++w)
					    {					    
						if (m_environment.is_Adjacent(MDD[other_robot_id][layer][vv], MDD[other_robot_id][layer + 1][w]) || MDD[other_robot_id][layer][vv] == MDD[other_robot_id][layer + 1][w])
						{
						    if (MDD[other_robot_id][layer][vv] != MDD[other_robot_id][layer + 1][w])
						    {
							if (MDD[other_robot_id][layer + 1][w] == MDD[robot_id][layer][u])
							{
							    complementary_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][vv], sIntegerIndex(other_neighbor_index)));
							}
						    }
						    ++other_neighbor_index;
						}
					    }
					}
				    }
				}
				if (!complementary_edge_Identifiers.empty())
				{
				    encoding_context.m_bit_generator->cast_MultiNegativeImplication(solver,
												    sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															    sIntegerIndex(neighbor_index)),
												    complementary_edge_Identifiers);
				}
			    }
			    neighbor_index++;
			}
		    }
		}
	    }
	}		

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
									      mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										      mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						/*
						encoding_context.m_bit_generator->cast_BiangleMutex(solver,
						sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
						sIntegerIndex(neighbor_index)),
						sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
						sIntegerIndex(vv)));
						*/
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    encoding_context.m_bit_generator->cast_BitSet(solver,
								  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
											  sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }


    void sMultirobotInstance::to_Memory_CapacitatedPermutationMmddCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const MDD_vector &MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = encoding_context.m_N_Layers;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
												       sIntegerIndex(neighbor_index)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
												       sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    encoding_context.m_bit_generator->cast_MultiImplication(solver,
									    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
												    sIntegerIndex(u)),
									    mutex_target_Identifiers);
		    
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										      mutex_target_Identifiers);   
		}
		encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										  mutex_vertex_Identifiers);
	    }
	}

	for (int layer = 0; layer <= N_Layers; ++layer)
	{
	    std::vector<sBitClauseGenerator::SpecifiedBitIdentifiers_vector> vertex_capacity_Identifiers;
	    vertex_capacity_Identifiers.resize(N_Vertices);
	    
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    vertex_capacity_Identifiers[MDD[robot_id][layer][u]].push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
		}
	    }
	    for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	    {
		if (vertex_capacity_Identifiers[vertex_id].size() > m_environment.m_Vertices[vertex_id].m_capacity)
		{
		    encoding_context.m_bit_generator->cast_Cardinality(solver,
								       vertex_capacity_Identifiers[vertex_id],
								       m_environment.m_Vertices[vertex_id].m_capacity);
		}
	    }	    
	}			

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				sBitClauseGenerator::SpecifiedBitIdentifiers_vector complementary_edge_Identifiers;
				
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (robot_id != other_robot_id)
				    {
					int vv;
					
					for (vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						break;
					    }
					}

					if (vv < MDD[other_robot_id][layer].size())
					{
					    int other_neighbor_index = 0;
					    for (int w = 0; w < MDD[other_robot_id][layer + 1].size(); ++w)
					    {					    
						if (m_environment.is_Adjacent(MDD[other_robot_id][layer][vv], MDD[other_robot_id][layer + 1][w]) || MDD[other_robot_id][layer][vv] == MDD[other_robot_id][layer + 1][w])
						{
						    if (MDD[other_robot_id][layer][vv] != MDD[other_robot_id][layer + 1][w])
						    {
							if (MDD[other_robot_id][layer + 1][w] == MDD[robot_id][layer][u])
							{
							    complementary_edge_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[other_robot_id][layer][vv], sIntegerIndex(other_neighbor_index)));
							}
						    }
						    ++other_neighbor_index;
						}
					    }
					}
				    }
				}
				if (!complementary_edge_Identifiers.empty())
				{
				    encoding_context.m_bit_generator->cast_MultiNegativeImplication(solver,
												    sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															    sIntegerIndex(neighbor_index)),
												    complementary_edge_Identifiers);
				}
			    }
			    neighbor_index++;
			}
		    }
		}
	    }
	}		

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
									      mutex_vertex_Identifiers);
	}

	/*
	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										      mutex_occupancy_Identifiers);
		}
	    }
	}
	*/

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						/*
						encoding_context.m_bit_generator->cast_BiangleMutex(solver,
						sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
						sIntegerIndex(neighbor_index)),
						sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
						sIntegerIndex(vv)));
						*/
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    encoding_context.m_bit_generator->cast_BitSet(solver,
								  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
											  sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }        
    

    void sMultirobotInstance::to_Stream_RXMddCNFsat(FILE                              *fw,
						    sMultirobotEncodingContext_CNFsat &encoding_context,
						    int                                sUNUSED(extra_cost),
						    int                                mdd_depth,
						    const MDD_vector                  &MDD,
						    const MDD_vector                  &extra_MDD,
						    const sString                     &sUNUSED(indent),
						    bool                               sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int Clause_cnt = 0;
	int aux_Variable_cnt = 0;
	int total_Literal_cnt = 0;

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_MultiConjunctiveImplication(aux_Variable_cnt,
													  total_Literal_cnt,
													  sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													  prev_cardinality_Identifiers);
		    }
		}
	    }
	}
	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}
/*
	if (!cardinality_Identifiers.empty())
	{
	    Clause_cnt += encoding_context.m_bit_generator->count_Cardinality(aux_Variable_cnt,total_Literal_cnt, cardinality_Identifiers, extra_cost);
	}
*/
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														      sIntegerIndex(neighbor_index)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														      sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
											   total_Literal_cnt,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(u)),
											   mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
											 total_Literal_cnt,
											 mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
										     total_Literal_cnt,
										     mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						Clause_cnt += encoding_context.m_bit_generator->count_BiangleMutex(aux_Variable_cnt,
														   total_Literal_cnt,
														   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	   sIntegerIndex(neighbor_index)),
														   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	   sIntegerIndex(vv)));
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										 total_Literal_cnt,
										 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													 sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}

	int N_cnf_Variables = encoding_context.m_variable_store.get_Last_CNFVariable() + aux_Variable_cnt - 1;

#ifdef sDEBUG
	fprintf(fw, "c %s : multirobot MDD SAT encoding\n", sPRODUCT);
	fprintf(fw, "c %s\n", sCOPYRIGHT);
	fprintf(fw, "c number of layers = %d\n", N_Layers);
	fprintf(fw, "c number of visible variables = %d\n", N_cnf_Variables - aux_Variable_cnt);
	fprintf(fw, "c number of hidden variables = %d\n", aux_Variable_cnt);
	fprintf(fw, "c number of literals = %d\n", total_Literal_cnt);
	fprintf(fw, "c number of clauses = %d\n", Clause_cnt);
	fprintf(fw, "c number of propositional variables = %d\n", N_cnf_Variables);
	fprintf(fw, "c number of clauses / number of variables = %.3f\n", (double)Clause_cnt / N_cnf_Variables);
	fprintf(fw, "c number of literals / number of clauses = %.3f\n", (double)total_Literal_cnt /  Clause_cnt);
	to_Stream(fw, "c ");
#endif
	fprintf(fw, "p cnf %d %d\n", N_cnf_Variables, Clause_cnt);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_MultiConjunctiveImplication(fw,
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													     prev_cardinality_Identifiers);
		    }
		}
	    }
	}
/*
	if (!cardinality_Identifiers.empty())
	{
	    printf("----> Cardinality: %d, %d, %d <----\n", cardinality_Identifiers.size(), extra_cost, encoding_context.m_max_total_cost);
	    Clause_cnt += encoding_context.m_bit_generator->generate_Cardinality(fw, cardinality_Identifiers, extra_cost);
	}
*/
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															 sIntegerIndex(neighbor_index)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
															 sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
												mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
											    mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
											mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AllMutexConstraint(fw,
												mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						Clause_cnt += encoding_context.m_bit_generator->generate_BiangleMutex(fw,
														      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	      sIntegerIndex(neighbor_index)),
														      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	      sIntegerIndex(vv)));
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													    sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }


    void sMultirobotInstance::to_Memory_RXMddCNFsat(Glucose::Solver                   *solver,
						    sMultirobotEncodingContext_CNFsat &encoding_context,
						    int                                sUNUSED(extra_cost),
						    int                                mdd_depth,
						    const MDD_vector                  &MDD,
						    const MDD_vector                  &extra_MDD,
						    const sString                     &sUNUSED(indent),
						    bool                               sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    encoding_context.m_bit_generator->cast_Implication(solver,
											     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
											     sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			encoding_context.m_bit_generator->cast_MultiConjunctiveImplication(solver,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
											   prev_cardinality_Identifiers);
		    }
		}
	    }
	}
	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}
/*
	if (!cardinality_Identifiers.empty())
	{
	    encoding_context.m_bit_generator->cast_Cardinality(solver,total_Literal_cnt, cardinality_Identifiers, extra_cost);
	}
*/
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    encoding_context.m_bit_generator->cast_Implication(solver,
											     sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														     sIntegerIndex(neighbor_index)),
											     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														     sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    encoding_context.m_bit_generator->cast_MultiImplication(solver,
											  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														  sIntegerIndex(u)),
											  mutex_target_Identifiers);

		    encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
											    mutex_target_Identifiers);   
		}
		encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
											mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
										    mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    encoding_context.m_bit_generator->cast_AllMutexConstraint(solver,
											    mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						encoding_context.m_bit_generator->cast_BiangleMutex(solver,
														  sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	  sIntegerIndex(neighbor_index)),
														  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	  sIntegerIndex(vv)));
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    encoding_context.m_bit_generator->cast_BitSet(solver,
										sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													    sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													    sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }    


/*----------------------------------------------------------------------------*/
    
    void sMultirobotInstance::to_Stream_MddPlusCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Stream_MddPlusCNFsat(fw, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Stream_MddPlusCNFsat(fw, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }


    void sMultirobotInstance::to_Memory_MddPlusCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Memory_MddPlusCNFsat(solver, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Memory_MddPlusCNFsat(solver, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }    


    void sMultirobotInstance::to_Stream_MmddPlusCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	--encoding_context.m_N_Layers;
	construct_MakespanMDD(encoding_context.m_N_Layers, m_the_MDD);
	
	//s_GlobalPhaseStatistics.leave_Phase();

	to_Stream_MmddPlusCNFsat(fw, encoding_context, m_the_MDD, indent, verbose);
    }


    void sMultirobotInstance::to_Memory_MmddPlusCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	--encoding_context.m_N_Layers;
	construct_MakespanMDD(encoding_context.m_N_Layers, m_the_MDD);
	
	//s_GlobalPhaseStatistics.leave_Phase();

	to_Memory_MmddPlusCNFsat(solver, encoding_context, m_the_MDD, indent, verbose);
    }    


    void sMultirobotInstance::to_Stream_MddPlusPlusCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Stream_MddPlusPlusCNFsat(fw, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Stream_MddPlusPlusCNFsat(fw, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }


    void sMultirobotInstance::to_Stream_MddPlusPlusMutexCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Stream_MddPlusPlusMutexCNFsat(fw, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Stream_MddPlusPlusMutexCNFsat(fw, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }    


    void sMultirobotInstance::to_Stream_MddPlusPlusFuelCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_fuel;
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_FuelMDD(encoding_context.m_max_total_fuel, encoding_context.m_fuel_makespan, m_the_MDD, extra_fuel, m_the_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_fuel >= 0)
	{
	    to_Stream_MddPlusPlusFuelCNFsat(fw, encoding_context, encoding_context.m_extra_fuel, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_fuel = extra_fuel;
	    to_Stream_MddPlusPlusFuelCNFsat(fw, encoding_context, extra_fuel, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }    


    void sMultirobotInstance::to_Stream_LMddPlusPlusCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_LimitedMDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);	
	construct_DisplacementMDD(encoding_context.m_max_total_cost, m_the_LMDD, extra_cost, m_the_extra_LMDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Stream_LMddPlusPlusCNFsat(fw, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_LMDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Stream_LMddPlusPlusCNFsat(fw, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_LMDD, m_the_extra_MDD, indent, verbose);
	}
    }    


    void sMultirobotInstance::to_Memory_MddPlusPlusCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Memory_MddPlusPlusCNFsat(solver, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Memory_MddPlusPlusCNFsat(solver, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }


    void sMultirobotInstance::to_Memory_MddPlusPlusMutexCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_MDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Memory_MddPlusPlusMutexCNFsat(solver, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Memory_MddPlusPlusMutexCNFsat(solver, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }    


    void sMultirobotInstance::to_Memory_MddPlusPlusFuelCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_fuel;
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_FuelMDD(encoding_context.m_max_total_fuel, encoding_context.m_fuel_makespan, m_the_MDD, extra_fuel, m_the_extra_MDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_fuel >= 0)
	{
	    to_Memory_MddPlusPlusFuelCNFsat(solver, encoding_context, encoding_context.m_extra_fuel, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_fuel = extra_fuel;
	    to_Memory_MddPlusPlusFuelCNFsat(solver, encoding_context, extra_fuel, mdd_depth, m_the_MDD, m_the_extra_MDD, indent, verbose);
	}
    }    


    void sMultirobotInstance::to_Memory_LMddPlusPlusCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	int extra_cost;
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	int mdd_depth = construct_LimitedMDD(encoding_context.m_max_total_cost, m_the_MDD, extra_cost, m_the_extra_MDD);	
	construct_DisplacementMDD(encoding_context.m_max_total_cost, m_the_LMDD, extra_cost, m_the_extra_LMDD);
	//s_GlobalPhaseStatistics.leave_Phase();

	if (encoding_context.m_extra_cost >= 0)
	{
	    to_Memory_LMddPlusPlusCNFsat(solver, encoding_context, encoding_context.m_extra_cost, mdd_depth, m_the_MDD, m_the_LMDD, m_the_extra_MDD, indent, verbose);
	}
	else
	{
	    encoding_context.m_extra_cost = extra_cost;
	    to_Memory_LMddPlusPlusCNFsat(solver, encoding_context, extra_cost, mdd_depth, m_the_MDD, m_the_LMDD, m_the_extra_MDD, indent, verbose);
	}
    }        


    void sMultirobotInstance::to_Stream_MmddPlusPlusCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	--encoding_context.m_N_Layers;
	construct_MakespanMDD(encoding_context.m_N_Layers, m_the_MDD);
	
	//s_GlobalPhaseStatistics.leave_Phase();

	to_Stream_MmddPlusPlusCNFsat(fw, encoding_context, m_the_MDD, indent, verbose);
    }


    void sMultirobotInstance::to_Memory_MmddPlusPlusCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const sString &indent, bool verbose)
    {
	//	s_GlobalPhaseStatistics.enter_Phase("MDD build");
	--encoding_context.m_N_Layers;
	construct_MakespanMDD(encoding_context.m_N_Layers, m_the_MDD);
	
	//s_GlobalPhaseStatistics.leave_Phase();

	to_Memory_MmddPlusPlusCNFsat(solver, encoding_context, m_the_MDD, indent, verbose);
    }        


    void sMultirobotInstance::to_Stream_MddPlusCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int Clause_cnt = 0;
	int aux_Variable_cnt = 0;
	int total_Literal_cnt = 0;

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	//	s_GlobalPhaseStatistics.enter_Phase("Counting");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_MultiConjunctiveImplication(aux_Variable_cnt,
													  total_Literal_cnt,
													  sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													  prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}
	if (!cardinality_Identifiers.empty())
	{
	    Clause_cnt += encoding_context.m_bit_generator->count_Cardinality(aux_Variable_cnt,total_Literal_cnt, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);

		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														      sIntegerIndex(neighbor_index)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														      sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
											   total_Literal_cnt,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(u)),
											   mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												   total_Literal_cnt,
												   mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
											       total_Literal_cnt,
											       mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
											   total_Literal_cnt,
											   mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												   total_Literal_cnt,
												   mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						Clause_cnt += encoding_context.m_bit_generator->count_BiangleMutex(aux_Variable_cnt,
														   total_Literal_cnt,
														   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	   sIntegerIndex(neighbor_index)),
														   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	   sIntegerIndex(vv)));
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										 total_Literal_cnt,
										 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													 sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}


	int N_cnf_Variables = encoding_context.m_variable_store.get_Last_CNFVariable() + aux_Variable_cnt - 1;

	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.enter_Phase("Writing");

#ifdef sDEBUG
	fprintf(fw, "c %s : multirobot MDD+ SAT encoding\n", sPRODUCT);
	fprintf(fw, "c %s\n", sCOPYRIGHT);
	fprintf(fw, "c number of layers = %d\n", N_Layers);
	fprintf(fw, "c number of visible variables = %d\n", N_cnf_Variables - aux_Variable_cnt);
	fprintf(fw, "c number of hidden variables = %d\n", aux_Variable_cnt);
	fprintf(fw, "c number of literals = %d\n", total_Literal_cnt);
	fprintf(fw, "c number of clauses = %d\n", Clause_cnt);
	fprintf(fw, "c number of propositional variables = %d\n", N_cnf_Variables);
	fprintf(fw, "c number of clauses / number of variables = %.3f\n", (double)Clause_cnt / N_cnf_Variables);
	fprintf(fw, "c number of literals / number of clauses = %.3f\n", (double)total_Literal_cnt /  Clause_cnt);
	to_Stream(fw, "c ");
#endif
	fprintf(fw, "p cnf %d %d\n", N_cnf_Variables, Clause_cnt);

	//	s_GlobalPhaseStatistics.enter_Phase("Pregen 1");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_MultiConjunctiveImplication(fw,
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													     prev_cardinality_Identifiers);
		    }
		}
	    }
	}
	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.enter_Phase("Pregen 2");

	if (!cardinality_Identifiers.empty())
	{
//	    printf("----> Cardinality: %d, %d, %d <----\n", cardinality_Identifiers.size(), extra_cost, encoding_context.m_max_total_cost);
	    Clause_cnt += encoding_context.m_bit_generator->generate_Cardinality(fw, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															 sIntegerIndex(neighbor_index)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
															 sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
		    
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      mutex_target_Identifiers);		    
		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												    mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												mutex_vertex_Identifiers);
	    
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												      mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {

						Clause_cnt += encoding_context.m_bit_generator->generate_BiangleMutex(fw,
														      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	      sIntegerIndex(neighbor_index)),
														      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	      sIntegerIndex(vv)));
						
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													    sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}

	//------ alternative
	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.leave_Phase();
    }


    void sMultirobotInstance::to_Memory_MddPlusCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	//	s_GlobalPhaseStatistics.enter_Phase("Counting");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    encoding_context.m_bit_generator->cast_Implication(solver,
											     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
											     sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			encoding_context.m_bit_generator->cast_MultiConjunctiveImplication(solver,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
											   prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}
	if (!cardinality_Identifiers.empty())
	{
	    encoding_context.m_bit_generator->cast_Cardinality(solver, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);

		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    encoding_context.m_bit_generator->cast_Implication(solver,
											     sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														     sIntegerIndex(neighbor_index)),
											     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														     sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    encoding_context.m_bit_generator->cast_MultiImplication(solver,
											  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														  sIntegerIndex(u)),
											  mutex_target_Identifiers);

		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
												    mutex_target_Identifiers);   
		}
		encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
												mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
											    mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
												    mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						encoding_context.m_bit_generator->cast_BiangleMutex(solver,
														  sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	  sIntegerIndex(neighbor_index)),
														  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	  sIntegerIndex(vv)));
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    encoding_context.m_bit_generator->cast_BitSet(solver,
										sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													    sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													    sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }    


    void sMultirobotInstance::to_Stream_MmddPlusCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const MDD_vector &MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int Clause_cnt = 0;
	int aux_Variable_cnt = 0;
	int total_Literal_cnt = 0;

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = encoding_context.m_N_Layers;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														      sIntegerIndex(neighbor_index)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														      sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
											   total_Literal_cnt,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(u)),
											   mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												   total_Literal_cnt,
												   mutex_target_Identifiers);   
		}
		Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
											       total_Literal_cnt,
											       mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
											   total_Literal_cnt,
											   mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												   total_Literal_cnt,
												   mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						Clause_cnt += encoding_context.m_bit_generator->count_BiangleMutex(aux_Variable_cnt,
														   total_Literal_cnt,
														   sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	   sIntegerIndex(neighbor_index)),
														   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	   sIntegerIndex(vv)));
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										 total_Literal_cnt,
										 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													 sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}

	int N_cnf_Variables = encoding_context.m_variable_store.get_Last_CNFVariable() + aux_Variable_cnt - 1;

#ifdef sDEBUG
	fprintf(fw, "c %s : multirobot MMDD+ SAT encoding\n", sPRODUCT);
	fprintf(fw, "c %s\n", sCOPYRIGHT);
	fprintf(fw, "c number of layers = %d\n", N_Layers);
	fprintf(fw, "c number of visible variables = %d\n", N_cnf_Variables - aux_Variable_cnt);
	fprintf(fw, "c number of hidden variables = %d\n", aux_Variable_cnt);
	fprintf(fw, "c number of literals = %d\n", total_Literal_cnt);
	fprintf(fw, "c number of clauses = %d\n", Clause_cnt);
	fprintf(fw, "c number of propositional variables = %d\n", N_cnf_Variables);
	fprintf(fw, "c number of clauses / number of variables = %.3f\n", (double)Clause_cnt / N_cnf_Variables);
	fprintf(fw, "c number of literals / number of clauses = %.3f\n", (double)total_Literal_cnt /  Clause_cnt);
	to_Stream(fw, "c ");
#endif
	fprintf(fw, "p cnf %d %d\n", N_cnf_Variables, Clause_cnt);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
															 sIntegerIndex(neighbor_index)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
															 sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      mutex_target_Identifiers);

		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												      mutex_target_Identifiers);   
		}
		
		Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												  mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
											      mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												      mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						Clause_cnt += encoding_context.m_bit_generator->generate_BiangleMutex(fw,
														      sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	      sIntegerIndex(neighbor_index)),
														      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	      sIntegerIndex(vv)));
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													    sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }


    void sMultirobotInstance::to_Memory_MmddPlusCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const MDD_vector &MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = encoding_context.m_N_Layers;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_edge_occupancy_by_water__[robot_id].resize(N_Layers);

	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		encoding_context.m_edge_occupancy_by_water__[robot_id][layer].resize(MDD[robot_id][layer].size());

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int N_neighbors = 0;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    ++N_neighbors;
			}
		    }
		    sIndexableBitIdentifier edge_occupancy_by_water__(&encoding_context.m_variable_store,
								      "edge_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer) + "_" + sInt_32_to_String(MDD[robot_id][layer][u]),
								      sIntegerScope(0, N_neighbors - 1));
		    encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u] = edge_occupancy_by_water__;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u]);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_target_Identifiers;

		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    mutex_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u], sIntegerIndex(neighbor_index)));

			    encoding_context.m_bit_generator->cast_Implication(solver,
											     sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
														     sIntegerIndex(neighbor_index)),
											     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														     sIntegerIndex(v)));
			    neighbor_index++;
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    encoding_context.m_bit_generator->cast_MultiImplication(solver,
											  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														  sIntegerIndex(u)),
											  mutex_target_Identifiers);

		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
												    mutex_target_Identifiers);   
		}
		encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
												mutex_vertex_Identifiers);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
											    mutex_vertex_Identifiers);
	}

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
												    mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    int neighbor_index = 0;
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						encoding_context.m_bit_generator->cast_BiangleMutex(solver,
														  sSpecifiedBitIdentifier(&encoding_context.m_edge_occupancy_by_water__[robot_id][layer][u],
																	  sIntegerIndex(neighbor_index)),
														  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	   sIntegerIndex(vv)));
					    }
					}
				    }
				}
			    }
			    ++neighbor_index;
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    encoding_context.m_bit_generator->cast_BitSet(solver,
										sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													    sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													    sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }
    

    void sMultirobotInstance::to_Stream_MddPlusPlusCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int Clause_cnt = 0;
	int aux_Variable_cnt = 0;
	int total_Literal_cnt = 0;

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
//	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	//	s_GlobalPhaseStatistics.enter_Phase("Counting");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_MultiConjunctiveImplication(aux_Variable_cnt,
													  total_Literal_cnt,
													  sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													  prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}
	if (!cardinality_Identifiers.empty())
	{
	    Clause_cnt += encoding_context.m_bit_generator->count_Cardinality(aux_Variable_cnt,total_Literal_cnt, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector outgo_target_Identifiers;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    outgo_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1], sIntegerIndex(v)));
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
	    
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
											   total_Literal_cnt,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(u)),
											   outgo_target_Identifiers);
		}
		Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												 total_Literal_cnt,
												 mutex_vertex_Identifiers);
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_vertex_Identifiers);
	}
*/
	
	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												   total_Literal_cnt,
												   mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector triangular_Identifiers;
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.begin();
				     conflict != m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.end(); ++conflict)
				{
				    for (int k = 0; k < m_robustness; ++k)
				    {
					if (layer - k >= 0)
					{					
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (other_robot_id != robot_id)
						{
						    for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						    {
							if (*conflict == MDD[other_robot_id][layer - k][vv])
							{
							    triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														     sIntegerIndex(vv)));							    
							}
						    }
						}
					    }
					}
				    }
				}
				for (int k = 0; k < m_robustness; ++k)
				{
				    if (layer - k >= 0)
				    {					
					for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					{
					    if (other_robot_id != robot_id)
					    {
						for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						{
						    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer - k][vv])
						    {
							triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														 sIntegerIndex(vv)));

							/*
							Clause_cnt += encoding_context.m_bit_generator->count_TriangleMutex(aux_Variable_cnt,
															    total_Literal_cnt,
															    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
																		    sIntegerIndex(u)),
															    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																		    sIntegerIndex(v)),
															    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																		    sIntegerIndex(vv)));
							*/
						    }
						}
					    }
					}
				    }
				}
				if (!triangular_Identifiers.empty())
				{
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiBiangleMutex(aux_Variable_cnt,
													    total_Literal_cnt,
													    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																    sIntegerIndex(v)),
													    triangular_Identifiers);				    
				    /*
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiTriangleMutex(aux_Variable_cnt,
													     total_Literal_cnt,
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
																     sIntegerIndex(u)),
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																     sIntegerIndex(v)),
													     triangular_Identifiers);
				    */
				}
			    }
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										 total_Literal_cnt,
										 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													 sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}


	int N_cnf_Variables = encoding_context.m_variable_store.get_Last_CNFVariable() + aux_Variable_cnt - 1;

	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.enter_Phase("Writing");

#ifdef sDEBUG
	fprintf(fw, "c %s : multirobot MDD++ SAT encoding\n", sPRODUCT);
	fprintf(fw, "c %s\n", sCOPYRIGHT);
	fprintf(fw, "c number of layers = %d\n", N_Layers);
	fprintf(fw, "c number of visible variables = %d\n", N_cnf_Variables - aux_Variable_cnt);
	fprintf(fw, "c number of hidden variables = %d\n", aux_Variable_cnt);
	fprintf(fw, "c number of literals = %d\n", total_Literal_cnt);
	fprintf(fw, "c number of clauses = %d\n", Clause_cnt);
	fprintf(fw, "c number of propositional variables = %d\n", N_cnf_Variables);
	fprintf(fw, "c number of clauses / number of variables = %.3f\n", (double)Clause_cnt / N_cnf_Variables);
	fprintf(fw, "c number of literals / number of clauses = %.3f\n", (double)total_Literal_cnt /  Clause_cnt);
	to_Stream(fw, "c ");
#endif
	fprintf(fw, "p cnf %d %d\n", N_cnf_Variables, Clause_cnt);

	//	s_GlobalPhaseStatistics.enter_Phase("Pregen 1");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_MultiConjunctiveImplication(fw,
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													     prev_cardinality_Identifiers);
		    }
		}
	    }
	}
	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.enter_Phase("Pregen 2");

	if (!cardinality_Identifiers.empty())
	{
//	    printf("----> Cardinality: %d, %d, %d <----\n", cardinality_Identifiers.size(), extra_cost, encoding_context.m_max_total_cost);
	    Clause_cnt += encoding_context.m_bit_generator->generate_Cardinality(fw, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector outgo_target_Identifiers;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    outgo_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1], sIntegerIndex(v)));			    
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
		    
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      outgo_target_Identifiers);		    
		}
		Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												    mutex_vertex_Identifiers);
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												mutex_vertex_Identifiers);
	    
	}
*/
	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												      mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector triangular_Identifiers;
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.begin();
				     conflict != m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.end(); ++conflict)
				{
				    for (int k = 0; k < m_robustness; ++k)
				    {
					if (layer - k >= 0)
					{					
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (other_robot_id != robot_id)
						{
						    for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						    {
							if (*conflict == MDD[other_robot_id][layer - k][vv])
							{
							    triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														     sIntegerIndex(vv)));
							}
						    }
						}
					    }
					}
				    }				    
				}				
				for (int k = 0; k < m_robustness; ++k)
				{
				    if (layer - k >= 0)
				    {					
					for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					{
					    if (other_robot_id != robot_id)
					    {
						for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						{
						    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer - k][vv])
						    {
							triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														 sIntegerIndex(vv)));
/*
						Clause_cnt += encoding_context.m_bit_generator->generate_TriangleMutex(fw,
														       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
																	       sIntegerIndex(u)),
														       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																	       sIntegerIndex(v)),
														       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	       sIntegerIndex(vv)));		
*/
						    }
						}
					    }
					}
				    }
				}
				if (!triangular_Identifiers.empty())
				{
				    /*
				    Clause_cnt += encoding_context.m_bit_generator->generate_MultiTriangleMutex(fw,
														sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
																	sIntegerIndex(u)),
														sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																	sIntegerIndex(v)),
														triangular_Identifiers);		
				    */
				    Clause_cnt += encoding_context.m_bit_generator->generate_MultiBiangleMutex(fw,
													       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																       sIntegerIndex(v)),
													       triangular_Identifiers);
				}
			    }
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													    sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}

	//------ alternative
	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.leave_Phase();
    }
  

    void sMultirobotInstance::to_Stream_MddPlusPlusMutexCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int Clause_cnt = 0;
	int aux_Variable_cnt = 0;
	int total_Literal_cnt = 0;

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
//	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	MDDMutexes_vector Mutexes;
	Mutexes.resize(N_Robots + 1);

	InverseMDD_vector inverse_MDD;
	construct_InverseMDD(N_Vertices, MDD, inverse_MDD);	

	//	s_GlobalPhaseStatistics.enter_Phase("Counting");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    
	    Mutexes[robot_id].resize(N_Layers + 1);
	    
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_MultiConjunctiveImplication(aux_Variable_cnt,
													  total_Literal_cnt,
													  sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													  prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}
	if (!cardinality_Identifiers.empty())
	{
	    Clause_cnt += encoding_context.m_bit_generator->count_Cardinality(aux_Variable_cnt,total_Literal_cnt, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector outgo_target_Identifiers;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    outgo_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1], sIntegerIndex(v)));
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
	    
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
											   total_Literal_cnt,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(u)),
											   outgo_target_Identifiers);
		}
		Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												 total_Literal_cnt,
												 mutex_vertex_Identifiers);
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_vertex_Identifiers);
	}
*/
	
	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												   total_Literal_cnt,
												   mutex_occupancy_Identifiers);
		}
	    }
	}


	ScheduledMTXs_list scheduled_Mutexes;

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{	   
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
		{
		    if (other_robot_id < robot_id)
		    {
			for (int uu = 0; uu < MDD[robot_id][layer].size(); ++uu)
			{
			    int uu_mdd_idx = inverse_MDD[other_robot_id][layer][MDD[robot_id][layer][uu]];
			    
			    if (uu_mdd_idx >= 0)
			    {
				scheduled_Mutexes.push_back(ScheduledMTX(layer, MTX_pair(MTX(robot_id, MDD[robot_id][layer][uu]), MTX(other_robot_id, MDD[other_robot_id][layer][uu_mdd_idx]))));
			    }
			}
		    }
		}
	    }
	}

	std::vector<VertexIDs_vector> vertex_neighbor_IDs;
	vertex_neighbor_IDs.resize(N_Vertices);

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    sVertex::Neighbors_list &vertex_Neighbors = m_environment.m_Vertices[vertex_id].m_Neighbors;
	    for (sVertex::Neighbors_list::const_iterator vertex_neighbor = vertex_Neighbors.begin(); vertex_neighbor != vertex_Neighbors.end(); ++vertex_neighbor)
	    {
		vertex_neighbor_IDs[vertex_id].push_back((*vertex_neighbor)->m_target->m_id);
	    }
	    vertex_neighbor_IDs[vertex_id].push_back(vertex_id);	    
	}

	while (!scheduled_Mutexes.empty())
	{
//	    printf("Size: %ld\n", scheduled_Mutexes.size()); 
	    const ScheduledMTX &scheduled_MTX = scheduled_Mutexes.front();	    
	    
	    int vertex_u_id = scheduled_MTX.m_mtx.first.m_vertex_id;
	    int vertex_w_id = scheduled_MTX.m_mtx.second.m_vertex_id;

	    int robot_id = scheduled_MTX.m_mtx.first.m_robot_id;
	    int other_robot_id = scheduled_MTX.m_mtx.second.m_robot_id;

	    int layer = scheduled_MTX.m_layer;
	    
	    if (layer < N_Layers)
	    {
		/*
		sVertex::Neighbors_list &u_Neighbors = m_environment.m_Vertices[vertex_u_id].m_Neighbors;
		VertexIDs_vector u_neighbor_IDs;
		for (sVertex::Neighbors_list::const_iterator u_neighbor = u_Neighbors.begin(); u_neighbor != u_Neighbors.end(); ++u_neighbor)
		{
		    u_neighbor_IDs.push_back((*u_neighbor)->m_target->m_id);
		}
		u_neighbor_IDs.push_back(vertex_u_id);
		
		sVertex::Neighbors_list &w_Neighbors = m_environment.m_Vertices[vertex_w_id].m_Neighbors;
		VertexIDs_vector w_neighbor_IDs;
		for (sVertex::Neighbors_list::const_iterator w_neighbor = w_Neighbors.begin(); w_neighbor != w_Neighbors.end(); ++w_neighbor)
		{
		    w_neighbor_IDs.push_back((*w_neighbor)->m_target->m_id);
		}
		w_neighbor_IDs.push_back(vertex_w_id);
		*/
		
		for (VertexIDs_vector::const_iterator v_neighbor = vertex_neighbor_IDs[vertex_u_id].begin(); v_neighbor != vertex_neighbor_IDs[vertex_u_id].end(); ++v_neighbor)
		{
		    sInt_32 v_mdd_idx = inverse_MDD[robot_id][layer + 1][(*v_neighbor)];
						    
		    if (v_mdd_idx >= 0)
		    {
			for (VertexIDs_vector::const_iterator z_neighbor = vertex_neighbor_IDs[vertex_w_id].begin(); z_neighbor != vertex_neighbor_IDs[vertex_w_id].end(); ++z_neighbor)
			{
			    sInt_32 z_mdd_idx = inverse_MDD[other_robot_id][layer + 1][(*z_neighbor)];
			    
			    if (z_mdd_idx >= 0)
			    {			    			    
				if (*v_neighbor < *z_neighbor)
				{
				    int vertex_v_id = *v_neighbor;
				    int vertex_z_id = *z_neighbor;

				    bool all_mutex = true;

				    /*
				    sVertex::Neighbors_list &v_Neighbors = m_environment.m_Vertices[vertex_v_id].m_Neighbors;
				    VertexIDs_vector v_neighbor_IDs;
				    for (sVertex::Neighbors_list::const_iterator v_neighbor = v_Neighbors.begin(); v_neighbor != v_Neighbors.end(); ++v_neighbor)
				    {
					v_neighbor_IDs.push_back((*v_neighbor)->m_target->m_id);
				    }
				    v_neighbor_IDs.push_back(vertex_v_id);
				    */
				    
				    for (VertexIDs_vector::const_iterator v_neighbor = vertex_neighbor_IDs[vertex_v_id].begin(); v_neighbor != vertex_neighbor_IDs[vertex_v_id].end(); ++v_neighbor)
				    {
					sInt_32 u_mdd_idx = inverse_MDD[robot_id][layer][(*v_neighbor)];
					
					if (u_mdd_idx >= 0)
					{
					    bool u_all_mutex = true;

					    /*
					    sVertex::Neighbors_list &z_Neighbors = m_environment.m_Vertices[vertex_z_id].m_Neighbors;
					    VertexIDs_vector z_neighbor_IDs;
					    for (sVertex::Neighbors_list::const_iterator z_neighbor = z_Neighbors.begin(); z_neighbor != z_Neighbors.end(); ++z_neighbor)
					    {
						z_neighbor_IDs.push_back((*z_neighbor)->m_target->m_id);
					    }
					    z_neighbor_IDs.push_back(vertex_z_id);
					    */
					    
					    for (VertexIDs_vector::const_iterator z_neighbor = vertex_neighbor_IDs[vertex_z_id].begin(); z_neighbor != vertex_neighbor_IDs[vertex_z_id].end(); ++z_neighbor)
					    {
						sInt_32 w_mdd_idx = inverse_MDD[other_robot_id][layer][(*z_neighbor)];
						
						if (w_mdd_idx >= 0)
						{
						    bool mutex_found = false;						
						    
						    if (MDD[robot_id][layer][u_mdd_idx] == MDD[other_robot_id][layer][w_mdd_idx])
						    {
							mutex_found = true;
						    }
						    else
						    {
							VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].find(MDD[robot_id][layer][u_mdd_idx]);
							
							if (mutexes_u != Mutexes[robot_id][layer].end())
							{
							    for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
							    {
								if (mutex_u->m_robot_id == other_robot_id && mutex_u->m_vertex_id == MDD[other_robot_id][layer][w_mdd_idx])
								{
								    mutex_found = true;
								    break;
								}
							    }
							}
						    }
						    if (!mutex_found)
						    {
							u_all_mutex = false;
							break;
						    }
						}
					    }
					    if (!u_all_mutex)
					    {
						all_mutex = false;
						break;
					    }
					}
				    }				    
				    if (all_mutex)
				    {
					bool next_first_mutex = Mutexes[robot_id][layer + 1][vertex_v_id].insert(Mutex(other_robot_id, vertex_z_id, z_mdd_idx, v_mdd_idx)).second;
					bool next_second_mutex = Mutexes[other_robot_id][layer + 1][vertex_z_id].insert(Mutex(robot_id, vertex_v_id, v_mdd_idx, z_mdd_idx)).second;

					if (next_first_mutex || next_second_mutex)
					{
					    scheduled_Mutexes.push_back(ScheduledMTX(layer + 1, MTX_pair(MTX(robot_id, vertex_v_id), MTX(other_robot_id, vertex_z_id))));
					}
				    }
				}	    
			    }
			}
		    }
		}
	    }
	    if (layer > 0)
	    {		
		for (VertexIDs_vector::const_iterator v_neighbor = vertex_neighbor_IDs[vertex_u_id].begin(); v_neighbor != vertex_neighbor_IDs[vertex_u_id].end(); ++v_neighbor)
		{
		    sInt_32 v_mdd_idx = inverse_MDD[robot_id][layer - 1][(*v_neighbor)];
						    
		    if (v_mdd_idx >= 0)
		    {
			for (VertexIDs_vector::const_iterator z_neighbor = vertex_neighbor_IDs[vertex_w_id].begin(); z_neighbor != vertex_neighbor_IDs[vertex_w_id].end(); ++z_neighbor)
			{
			    sInt_32 z_mdd_idx = inverse_MDD[other_robot_id][layer - 1][(*z_neighbor)];
			    
			    if (z_mdd_idx >= 0)
			    {			    			    
				if (*v_neighbor < *z_neighbor)
				{
				    int vertex_v_id = *v_neighbor;
				    int vertex_z_id = *z_neighbor;

				    bool all_mutex = true;
				    
				    for (VertexIDs_vector::const_iterator v_neighbor = vertex_neighbor_IDs[vertex_v_id].begin(); v_neighbor != vertex_neighbor_IDs[vertex_v_id].end(); ++v_neighbor)
				    {
					sInt_32 u_mdd_idx = inverse_MDD[robot_id][layer][(*v_neighbor)];
					
					if (u_mdd_idx >= 0)
					{
					    bool u_all_mutex = true;
					    
					    for (VertexIDs_vector::const_iterator z_neighbor = vertex_neighbor_IDs[vertex_z_id].begin(); z_neighbor != vertex_neighbor_IDs[vertex_z_id].end(); ++z_neighbor)
					    {
						sInt_32 w_mdd_idx = inverse_MDD[other_robot_id][layer][(*z_neighbor)];
						
						if (w_mdd_idx >= 0)
						{
						    bool mutex_found = false;						
						    
						    if (MDD[robot_id][layer][u_mdd_idx] == MDD[other_robot_id][layer][w_mdd_idx])
						    {
							mutex_found = true;
						    }
						    else
						    {
							VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].find(MDD[robot_id][layer][u_mdd_idx]);
							
							if (mutexes_u != Mutexes[robot_id][layer].end())
							{
							    for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
							    {
								if (mutex_u->m_robot_id == other_robot_id && mutex_u->m_vertex_id == MDD[other_robot_id][layer][w_mdd_idx])
								{
								    mutex_found = true;
								    break;
								}
							    }
							}
						    }
						    if (!mutex_found)
						    {
							u_all_mutex = false;
							break;
						    }
						}
					    }
					    if (!u_all_mutex)
					    {
						all_mutex = false;
						break;
					    }
					}
				    }				    
				    if (all_mutex)
				    {
					bool next_first_mutex = Mutexes[robot_id][layer - 1][vertex_v_id].insert(Mutex(other_robot_id, vertex_z_id, z_mdd_idx, v_mdd_idx)).second;
					bool next_second_mutex = Mutexes[other_robot_id][layer - 1][vertex_z_id].insert(Mutex(robot_id, vertex_v_id, v_mdd_idx, z_mdd_idx)).second;

					if (next_first_mutex || next_second_mutex)
					{
					    scheduled_Mutexes.push_back(ScheduledMTX(layer - 1, MTX_pair(MTX(robot_id, vertex_v_id), MTX(other_robot_id, vertex_z_id))));
					}
				    }
				}	    
			    }
		        }	
		    }
		}
	    }
	    scheduled_Mutexes.pop_front();
	}
	int N_mutexes = 0;
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{	    
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		for (VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].begin(); mutexes_u != Mutexes[robot_id][layer].end(); ++mutexes_u)
		{
		    int vertex_u_id = mutexes_u->first;

		    for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
		    {			
			int vertex_v_id = mutex_u->m_vertex_id;
			int vertex_v_idx = mutex_u->m_mdd_idx;
			int vertex_u_idx = mutex_u->m_mdd_other_idx;			
			int other_robot_id = mutex_u->m_robot_id;
			
			if (vertex_u_id < vertex_v_id)
			{
			    Clause_cnt += encoding_context.m_bit_generator->count_Mutex(aux_Variable_cnt,
												    total_Literal_cnt,
												    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
															    sIntegerIndex(vertex_u_idx)),
												    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
															    sIntegerIndex(vertex_v_idx)));
//			    printf(" 	 Mutex: at level %d - [%d, %d (%d)] x [%d, %d (%d)]\n", layer, robot_id, vertex_u_id, vertex_u_idx, other_robot_id, vertex_v_id, vertex_v_idx);
			    ++N_mutexes;
			}
		    }
		}
	    }
	}
	printf("Mutexes found in total: %d\n", N_mutexes);		

	/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		{		    
		    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
		    {
			if (other_robot_id < robot_id)
			{
			    for (int z = 0; z < MDD[other_robot_id][layer + 1].size(); ++z)
			    {				
				bool all_mutex = true;
//				printf("Checking mutex: [%d, %d, %d] and [%d, %d, %d]\n", robot_id, layer + 1, MDD[robot_id][layer + 1][v], other_robot_id, layer + 1, MDD[other_robot_id][layer + 1][z]);

				//----
				sVertex::Neighbors_list &v_Neighbors = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Neighbors;
				VertexIDs_vector v_neighbor_IDs;
				for (sVertex::Neighbors_list::const_iterator v_neighbor = v_Neighbors.begin(); v_neighbor != v_Neighbors.end(); ++v_neighbor)
				{
				    v_neighbor_IDs.push_back((*v_neighbor)->m_target->m_id);
				}
				v_neighbor_IDs.push_back(MDD[robot_id][layer + 1][v]);
				
				for (VertexIDs_vector::const_iterator v_neighbor = v_neighbor_IDs.begin(); v_neighbor != v_neighbor_IDs.end(); ++v_neighbor)
				{
				    sInt_32 u_mdd_idx = inverse_MDD[robot_id][layer][(*v_neighbor)];

				    if (u_mdd_idx >= 0)
				    {
					bool u_all_mutex = true;

					sVertex::Neighbors_list &z_Neighbors = m_environment.m_Vertices[MDD[other_robot_id][layer + 1][z]].m_Neighbors;
					VertexIDs_vector z_neighbor_IDs;
					for (sVertex::Neighbors_list::const_iterator z_neighbor = z_Neighbors.begin(); z_neighbor != z_Neighbors.end(); ++z_neighbor)
					{
					    z_neighbor_IDs.push_back((*z_neighbor)->m_target->m_id);
					}
					z_neighbor_IDs.push_back(MDD[other_robot_id][layer + 1][z]);
					
					for (VertexIDs_vector::const_iterator z_neighbor = z_neighbor_IDs.begin(); z_neighbor != z_neighbor_IDs.end(); ++z_neighbor)
					{
					    sInt_32 w_mdd_idx = inverse_MDD[other_robot_id][layer][(*z_neighbor)];
					    
					    if (w_mdd_idx >= 0)
					    {
						bool mutex_found = false;						

						if (MDD[robot_id][layer][u_mdd_idx] == MDD[other_robot_id][layer][w_mdd_idx])
						{
						    mutex_found = true;
						}
						else
						{
						    VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].find(MDD[robot_id][layer][u_mdd_idx]);
						    
						    if (mutexes_u != Mutexes[robot_id][layer].end())
						    {
							for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
							{
							    if (mutex_u->m_robot_id == other_robot_id && mutex_u->m_vertex_id == MDD[other_robot_id][layer][w_mdd_idx])
							    {
								mutex_found = true;
								break;
							    }
							}
						    }
						}
						if (!mutex_found)
						{
						    u_all_mutex = false;
						    break;
						}
					    }
					}
					if (!u_all_mutex)
					{
					    all_mutex = false;
					    break;
					}
				    }
				}
	*/
                                //----
			
				//----
				/*
				for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
				{ 
				    if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
				    {
					bool u_all_mutex = true;
					for (int w = 0; w < MDD[other_robot_id][layer].size(); ++w)
					{
					    if (   m_environment.is_Adjacent(MDD[other_robot_id][layer][w], MDD[other_robot_id][layer + 1][z])
						|| MDD[other_robot_id][layer][w] == MDD[other_robot_id][layer + 1][z])
					    {
						bool mutex_found = false;

						if (MDD[robot_id][layer][u] == MDD[other_robot_id][layer][w])
						{
						    mutex_found = true;
						}
						else
						{
						    VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].find(MDD[robot_id][layer][u]);

						    if (mutexes_u != Mutexes[robot_id][layer].end())
						    {
							for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
							{
							    if (mutex_u->m_robot_id == other_robot_id && mutex_u->m_vertex_id == MDD[other_robot_id][layer][w])
							    {
								mutex_found = true;
								break;
							    }
							}
						    }
						}
						if (!mutex_found)
						{
						    u_all_mutex = false;
						    break;
						}
					    }					
					}
					if (!u_all_mutex)
					{
					    all_mutex = false;
					    break;
					}
				    }
				}
				*/				
				//----
                                /*
				if (all_mutex)
				{
				    printf("  --> yes Mutex: [%d, %d, %d] and [%d, %d, %d]\n", robot_id, layer + 1, MDD[robot_id][layer + 1][v], other_robot_id, layer + 1, MDD[other_robot_id][layer + 1][z]);
				    Mutexes[robot_id][layer + 1][MDD[robot_id][layer + 1][v]].insert(Mutex(other_robot_id, MDD[other_robot_id][layer + 1][z], z, v));
				    Mutexes[other_robot_id][layer + 1][MDD[other_robot_id][layer + 1][z]].insert(Mutex(robot_id, MDD[robot_id][layer + 1][v], v, z));				    
				}
			    }
			}
		    }
		}
	    }
	}

	printf("Now summarizing ...\n");
	int N_mutexes = 0;
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{	    
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		for (VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].begin(); mutexes_u != Mutexes[robot_id][layer].end(); ++mutexes_u)
		{
		    int vertex_u_id = mutexes_u->first;

		    for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
		    {			
			int vertex_v_id = mutex_u->m_vertex_id;
			int vertex_v_idx = mutex_u->m_mdd_idx;
			int vertex_u_idx = mutex_u->m_mdd_other_idx;			
			int other_robot_id = mutex_u->m_robot_id;
			
			if (vertex_u_id < vertex_v_id)
			{
			    Clause_cnt += encoding_context.m_bit_generator->count_Mutex(aux_Variable_cnt,
												    total_Literal_cnt,
												    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
															    sIntegerIndex(vertex_u_idx)),
												    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
															    sIntegerIndex(vertex_v_idx)));
			    printf(" 	 Mutex: at level %d - [%d, %d (%d)] x [%d, %d (%d)]\n", layer, robot_id, vertex_u_id, vertex_u_idx, other_robot_id, vertex_v_id, vertex_v_idx);
			    ++N_mutexes;
			}
		    }
		}
	    }
	}
	printf("Mutexes found in total: %d\n", N_mutexes);
*/

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector triangular_Identifiers;
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.begin();
				     conflict != m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.end(); ++conflict)
				{
				    for (int k = 0; k < m_robustness; ++k)
				    {
					if (layer - k >= 0)
					{					
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (other_robot_id != robot_id)
						{
						    for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						    {
							if (*conflict == MDD[other_robot_id][layer - k][vv])
							{
							    triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														     sIntegerIndex(vv)));							    
							}
						    }
						}
					    }
					}
				    }
				}
				for (int k = 0; k < m_robustness; ++k)
				{
				    if (layer - k >= 0)
				    {					
					for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					{
					    if (other_robot_id != robot_id)
					    {
						for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						{
						    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer - k][vv])
						    {
							triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														 sIntegerIndex(vv)));

							/*
							Clause_cnt += encoding_context.m_bit_generator->count_TriangleMutex(aux_Variable_cnt,
															    total_Literal_cnt,
															    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
																		    sIntegerIndex(u)),
															    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																		    sIntegerIndex(v)),
															    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																		    sIntegerIndex(vv)));
							*/
						    }
						}
					    }
					}
				    }
				}
				if (!triangular_Identifiers.empty())
				{
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiBiangleMutex(aux_Variable_cnt,
													    total_Literal_cnt,
													    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																    sIntegerIndex(v)),
													    triangular_Identifiers);				    
				    /*
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiTriangleMutex(aux_Variable_cnt,
													     total_Literal_cnt,
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
																     sIntegerIndex(u)),
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																     sIntegerIndex(v)),
													     triangular_Identifiers);
				    */
				}
			    }
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										 total_Literal_cnt,
										 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													 sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}


	int N_cnf_Variables = encoding_context.m_variable_store.get_Last_CNFVariable() + aux_Variable_cnt - 1;

	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.enter_Phase("Writing");

#ifdef sDEBUG
	fprintf(fw, "c %s : multirobot MDD++ SAT encoding\n", sPRODUCT);
	fprintf(fw, "c %s\n", sCOPYRIGHT);
	fprintf(fw, "c number of layers = %d\n", N_Layers);
	fprintf(fw, "c number of visible variables = %d\n", N_cnf_Variables - aux_Variable_cnt);
	fprintf(fw, "c number of hidden variables = %d\n", aux_Variable_cnt);
	fprintf(fw, "c number of literals = %d\n", total_Literal_cnt);
	fprintf(fw, "c number of clauses = %d\n", Clause_cnt);
	fprintf(fw, "c number of propositional variables = %d\n", N_cnf_Variables);
	fprintf(fw, "c number of clauses / number of variables = %.3f\n", (double)Clause_cnt / N_cnf_Variables);
	fprintf(fw, "c number of literals / number of clauses = %.3f\n", (double)total_Literal_cnt /  Clause_cnt);
	to_Stream(fw, "c ");
#endif
	fprintf(fw, "p cnf %d %d\n", N_cnf_Variables, Clause_cnt);

	//	s_GlobalPhaseStatistics.enter_Phase("Pregen 1");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_MultiConjunctiveImplication(fw,
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													     prev_cardinality_Identifiers);
		    }
		}
	    }
	}
	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.enter_Phase("Pregen 2");

	if (!cardinality_Identifiers.empty())
	{
//	    printf("----> Cardinality: %d, %d, %d <----\n", cardinality_Identifiers.size(), extra_cost, encoding_context.m_max_total_cost);
	    Clause_cnt += encoding_context.m_bit_generator->generate_Cardinality(fw, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector outgo_target_Identifiers;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    outgo_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1], sIntegerIndex(v)));			    
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
		    
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      outgo_target_Identifiers);		    
		}
		Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												    mutex_vertex_Identifiers);
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												mutex_vertex_Identifiers);
	    
	}
*/
	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												      mutex_occupancy_Identifiers);
		}
	    }
	}

	N_mutexes = 0;
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{	    
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		for (VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].begin(); mutexes_u != Mutexes[robot_id][layer].end(); ++mutexes_u)
		{
		    int vertex_u_id = mutexes_u->first;

		    for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
		    {			
			int vertex_v_id = mutex_u->m_vertex_id;
			int vertex_v_idx = mutex_u->m_mdd_idx;
			int vertex_u_idx = mutex_u->m_mdd_other_idx;			
			int other_robot_id = mutex_u->m_robot_id;
			
			if (vertex_u_id < vertex_v_id)
			{
			    Clause_cnt += encoding_context.m_bit_generator->generate_Mutex(fw,			    
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(vertex_u_idx)),
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
														   sIntegerIndex(vertex_v_idx)));
//			    printf(" 	 Mutex: at level %d - [%d, %d (%d)] x [%d, %d (%d)]\n", layer, robot_id, vertex_u_id, vertex_u_idx, other_robot_id, vertex_v_id, vertex_v_idx);
			    ++N_mutexes;
			}
		    }
		}
	    }
	}
	//printf("Mutexes found in total: %d\n", N_mutexes);	

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector triangular_Identifiers;
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.begin();
				     conflict != m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.end(); ++conflict)
				{
				    for (int k = 0; k < m_robustness; ++k)
				    {
					if (layer - k >= 0)
					{					
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (other_robot_id != robot_id)
						{
						    for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						    {
							if (*conflict == MDD[other_robot_id][layer - k][vv])
							{
							    triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														     sIntegerIndex(vv)));
							}
						    }
						}
					    }
					}
				    }				    
				}				
				for (int k = 0; k < m_robustness; ++k)
				{
				    if (layer - k >= 0)
				    {					
					for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					{
					    if (other_robot_id != robot_id)
					    {
						for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						{
						    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer - k][vv])
						    {
							triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														 sIntegerIndex(vv)));
/*
						Clause_cnt += encoding_context.m_bit_generator->generate_TriangleMutex(fw,
														       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
																	       sIntegerIndex(u)),
														       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																	       sIntegerIndex(v)),
														       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	       sIntegerIndex(vv)));		
*/
						    }
						}
					    }
					}
				    }
				}
				if (!triangular_Identifiers.empty())
				{
				    /*
				    Clause_cnt += encoding_context.m_bit_generator->generate_MultiTriangleMutex(fw,
														sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
																	sIntegerIndex(u)),
														sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																	sIntegerIndex(v)),
														triangular_Identifiers);		
				    */
				    Clause_cnt += encoding_context.m_bit_generator->generate_MultiBiangleMutex(fw,
													       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																       sIntegerIndex(v)),
													       triangular_Identifiers);
				}
			    }
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													    sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}

	//------ alternative
	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.leave_Phase();
    }    


    void sMultirobotInstance::to_Stream_MddPlusPlusFuelCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, int sUNUSED(extra_fuel), int mdd_depth, const MDD_vector &MDD, const MDD_vector &sUNUSED(extra_MDD), const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int Clause_cnt = 0;
	int aux_Variable_cnt = 0;
	int total_Literal_cnt = 0;

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	/*
	const sUndirectedGraph::Distances_2d_vector &source_Distances = m_environment.get_SourceShortestPaths();
	const sUndirectedGraph::Distances_2d_vector &goal_Distances = m_environment.get_GoalShortestPaths();	
	*/

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
//	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	//	s_GlobalPhaseStatistics.enter_Phase("Counting");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {	
		sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								  "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								  sIntegerScope(0, 0));
		encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]))
			{
			    sASSERT(MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v]);
			    Clause_cnt += encoding_context.m_bit_generator->count_Bimplication(aux_Variable_cnt,
											       total_Literal_cnt,
											       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
											       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1], sIntegerIndex(v)),
											       sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
	    }
	}
	if (!cardinality_Identifiers.empty())
	{
	    Clause_cnt += encoding_context.m_bit_generator->count_Cardinality(aux_Variable_cnt,total_Literal_cnt, cardinality_Identifiers, encoding_context.m_max_total_fuel);
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector outgo_target_Identifiers;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    outgo_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1], sIntegerIndex(v)));
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
	    
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
											   total_Literal_cnt,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(u)),
											   outgo_target_Identifiers);
		}
		Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												 total_Literal_cnt,
												 mutex_vertex_Identifiers);
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_vertex_Identifiers);
	}
*/
	
	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector triangular_Identifiers;
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.begin();
				     conflict != m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.end(); ++conflict)
				{
				    for (int k = 0; k < m_robustness; ++k)
				    {
					if (layer - k >= 0)
					{					
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (other_robot_id != robot_id)
						{
						    for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						    {
							if (*conflict == MDD[other_robot_id][layer - k][vv])
							{
							    triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														     sIntegerIndex(vv)));							    
							}
						    }
						}
					    }
					}
				    }
				}
				for (int k = 0; k < m_robustness; ++k)
				{
				    if (layer - k >= 0)
				    {					
					for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					{
					    if (other_robot_id != robot_id)
					    {
						for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						{
						    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer - k][vv])
						    {
							triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														 sIntegerIndex(vv)));

							/*
							Clause_cnt += encoding_context.m_bit_generator->count_TriangleMutex(aux_Variable_cnt,
															    total_Literal_cnt,
															    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
																		    sIntegerIndex(u)),
															    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																		    sIntegerIndex(v)),
															    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																		    sIntegerIndex(vv)));
							*/
						    }
						}
					    }
					}
				    }
				}
				if (!triangular_Identifiers.empty())
				{
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiBiangleMutex(aux_Variable_cnt,
													    total_Literal_cnt,
													    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																    sIntegerIndex(v)),
													    triangular_Identifiers);				    
				    /*
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiTriangleMutex(aux_Variable_cnt,
													     total_Literal_cnt,
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
																     sIntegerIndex(u)),
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																     sIntegerIndex(v)),
													     triangular_Identifiers);
				    */
				}
			    }
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										 total_Literal_cnt,
										 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													 sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}


	int N_cnf_Variables = encoding_context.m_variable_store.get_Last_CNFVariable() + aux_Variable_cnt - 1;

	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.enter_Phase("Writing");

#ifdef sDEBUG
	fprintf(fw, "c %s : multirobot Fuel MDD++ SAT encoding\n", sPRODUCT);
	fprintf(fw, "c %s\n", sCOPYRIGHT);
	fprintf(fw, "c number of layers = %d\n", N_Layers);
	fprintf(fw, "c number of visible variables = %d\n", N_cnf_Variables - aux_Variable_cnt);
	fprintf(fw, "c number of hidden variables = %d\n", aux_Variable_cnt);
	fprintf(fw, "c number of literals = %d\n", total_Literal_cnt);
	fprintf(fw, "c number of clauses = %d\n", Clause_cnt);
	fprintf(fw, "c number of propositional variables = %d\n", N_cnf_Variables);
	fprintf(fw, "c number of clauses / number of variables = %.3f\n", (double)Clause_cnt / N_cnf_Variables);
	fprintf(fw, "c number of literals / number of clauses = %.3f\n", (double)total_Literal_cnt /  Clause_cnt);
	to_Stream(fw, "c ");
#endif
	fprintf(fw, "p cnf %d %d\n", N_cnf_Variables, Clause_cnt);

	//	s_GlobalPhaseStatistics.enter_Phase("Pregen 1");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]))
			{			    
			    Clause_cnt += encoding_context.m_bit_generator->generate_Bimplication(fw,
												  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
												  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1], sIntegerIndex(v)),
												  sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		}
	    }
	}
	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.enter_Phase("Pregen 2");

	if (!cardinality_Identifiers.empty())
	{
//	    printf("----> Cardinality: %d, %d, %d <----\n", cardinality_Identifiers.size(), encoding_context.m_max_total_fuel, encoding_context.m_fuel_makespan);
	    Clause_cnt += encoding_context.m_bit_generator->generate_Cardinality(fw, cardinality_Identifiers, encoding_context.m_max_total_fuel);
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector outgo_target_Identifiers;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    outgo_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1], sIntegerIndex(v)));			    
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
		    
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      outgo_target_Identifiers);		    
		}
		Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												    mutex_vertex_Identifiers);
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												mutex_vertex_Identifiers);
	    
	}
*/
	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												      mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector triangular_Identifiers;
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.begin();
				     conflict != m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.end(); ++conflict)
				{
				    for (int k = 0; k < m_robustness; ++k)
				    {
					if (layer - k >= 0)
					{					
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (other_robot_id != robot_id)
						{
						    for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						    {
							if (*conflict == MDD[other_robot_id][layer - k][vv])
							{
							    triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														     sIntegerIndex(vv)));
							}
						    }
						}
					    }
					}
				    }				    
				}				
				for (int k = 0; k < m_robustness; ++k)
				{
				    if (layer - k >= 0)
				    {					
					for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					{
					    if (other_robot_id != robot_id)
					    {
						for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						{
						    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer - k][vv])
						    {
							triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														 sIntegerIndex(vv)));
/*
						Clause_cnt += encoding_context.m_bit_generator->generate_TriangleMutex(fw,
														       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
																	       sIntegerIndex(u)),
														       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																	       sIntegerIndex(v)),
														       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	       sIntegerIndex(vv)));		
*/
						    }
						}
					    }
					}
				    }
				}
				if (!triangular_Identifiers.empty())
				{
				    /*
				    Clause_cnt += encoding_context.m_bit_generator->generate_MultiTriangleMutex(fw,
														sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
																	sIntegerIndex(u)),
														sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																	sIntegerIndex(v)),
														triangular_Identifiers);		
				    */
				    Clause_cnt += encoding_context.m_bit_generator->generate_MultiBiangleMutex(fw,
													       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																       sIntegerIndex(v)),
													       triangular_Identifiers);
				}
			    }
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													    sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}

	//------ alternative
	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.leave_Phase();
    }    


    void sMultirobotInstance::to_Stream_LMddPlusPlusCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &LMDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int Clause_cnt = 0;
	int aux_Variable_cnt = 0;
	int total_Literal_cnt = 0;

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	MDDIndices_vector LMDD_Indices;
	construct_MDDIndices(LMDD, LMDD_Indices);

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_occupancy_by_gas_.resize(N_Robots + 1);	
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
//	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	//	s_GlobalPhaseStatistics.enter_Phase("Counting");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_occupancy_by_gas_[robot_id].resize(N_Layers + 1);	    
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);
		
		sIndexableBitIdentifier vertex_occupancy_by_gas_(&encoding_context.m_variable_store,
								 "vertex_occupancy_by_gas-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								 sIntegerScope(0, LMDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_gas_[robot_id][layer] = vertex_occupancy_by_gas_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_gas_[robot_id][layer]);		

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->count_Implication(aux_Variable_cnt,
											      total_Literal_cnt,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    /*
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_MultiConjunctiveImplication(aux_Variable_cnt,
													  total_Literal_cnt,
													  sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													  prev_cardinality_Identifiers);
		    }
		    */
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}
	if (!cardinality_Identifiers.empty())
	{
	    Clause_cnt += encoding_context.m_bit_generator->count_Cardinality(aux_Variable_cnt,total_Literal_cnt, cardinality_Identifiers, extra_cost);
	}
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector gas_displacement_Identifiers;			
		    int robot_size = m_initial_arrangement.m_robot_Sizes[robot_id];

		    for (int dr = 0; dr < robot_size; ++dr)
		    {
			for (int dc = 0; dc < robot_size; ++dc)
			{
			    int next_vertex_id = m_environment.get_GridNeighborVertexID(MDD[robot_id][layer][u], dr, dc);
			    if (next_vertex_id >= 0)
			    {
				int mdd_index = LMDD_Indices[robot_id][layer][next_vertex_id];
				gas_displacement_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_gas_[robot_id][layer], sIntegerIndex(mdd_index)));
			    }
			}
		    }		    
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiConjunctiveImplication(aux_Variable_cnt,
												      total_Literal_cnt,
												      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
												      gas_displacement_Identifiers);
		}
	    }
	}
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector outgo_target_Identifiers;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    outgo_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1], sIntegerIndex(v)));
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
	    
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
											   total_Literal_cnt,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(u)),
											   outgo_target_Identifiers);
		}
		Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												 total_Literal_cnt,
												 mutex_vertex_Identifiers);
	    }
	}

/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
											     total_Literal_cnt,
											     mutex_vertex_Identifiers);
	}
*/
	/*
	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_occupancy_Identifiers);
		}
	    }
	}
	*/
	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < LMDD[robot_id][layer].size(); ++u)
		    {
			if (LMDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_gas_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												     total_Literal_cnt,
												     mutex_occupancy_Identifiers);
		}
	    }
	}	
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector triangular_Identifiers;
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
						sIntegerIndex(vv)));
					    }
					}
				    }
				}
				if (!triangular_Identifiers.empty())
				{
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiBiangleMutex(aux_Variable_cnt,
													    total_Literal_cnt,
													    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																    sIntegerIndex(v)),
													    triangular_Identifiers);				    
				}
			    }
			}
		    }
		}
	    }
	}
*/
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										 total_Literal_cnt,
										 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													 sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}


	int N_cnf_Variables = encoding_context.m_variable_store.get_Last_CNFVariable() + aux_Variable_cnt - 1;

	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.enter_Phase("Writing");

#ifdef sDEBUG
	fprintf(fw, "c %s : multirobot LMDD++ SAT encoding\n", sPRODUCT);
	fprintf(fw, "c %s\n", sCOPYRIGHT);
	fprintf(fw, "c number of layers = %d\n", N_Layers);
	fprintf(fw, "c number of visible variables = %d\n", N_cnf_Variables - aux_Variable_cnt);
	fprintf(fw, "c number of hidden variables = %d\n", aux_Variable_cnt);
	fprintf(fw, "c number of literals = %d\n", total_Literal_cnt);
	fprintf(fw, "c number of clauses = %d\n", Clause_cnt);
	fprintf(fw, "c number of propositional variables = %d\n", N_cnf_Variables);
	fprintf(fw, "c number of clauses / number of variables = %.3f\n", (double)Clause_cnt / N_cnf_Variables);
	fprintf(fw, "c number of literals / number of clauses = %.3f\n", (double)total_Literal_cnt /  Clause_cnt);
	to_Stream(fw, "c ");
#endif
	fprintf(fw, "p cnf %d %d\n", N_cnf_Variables, Clause_cnt);

	//	s_GlobalPhaseStatistics.enter_Phase("Pregen 1");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    Clause_cnt += encoding_context.m_bit_generator->generate_Implication(fw,
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
												 sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_MultiConjunctiveImplication(fw,
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
													     prev_cardinality_Identifiers);
		    }
		}
	    }
	}
	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.enter_Phase("Pregen 2");

	if (!cardinality_Identifiers.empty())
	{
//	    printf("----> Cardinality: %d, %d, %d <----\n", cardinality_Identifiers.size(), extra_cost, encoding_context.m_max_total_cost);
	    Clause_cnt += encoding_context.m_bit_generator->generate_Cardinality(fw, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector gas_displacement_Identifiers;			
		    int robot_size = m_initial_arrangement.m_robot_Sizes[robot_id];

		    for (int dr = 0; dr < robot_size; ++dr)
		    {
			for (int dc = 0; dc < robot_size; ++dc)
			{
			    int next_vertex_id = m_environment.get_GridNeighborVertexID(MDD[robot_id][layer][u], dr, dc);
			    if (next_vertex_id >= 0)
			    {
				int mdd_index = LMDD_Indices[robot_id][layer][next_vertex_id];
				gas_displacement_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_gas_[robot_id][layer], sIntegerIndex(mdd_index)));
			    }
			}
		    }
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiConjunctiveImplication(fw,
													 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
													 gas_displacement_Identifiers);
		}
	    }
	}	
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector outgo_target_Identifiers;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    outgo_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1], sIntegerIndex(v)));			    
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
		    
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      outgo_target_Identifiers);		    
		}
		Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												    mutex_vertex_Identifiers);
	    }
	}

/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												mutex_vertex_Identifiers);
	    
	}
*/
	/*
	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												      mutex_occupancy_Identifiers);
		}
	    }
	}
	*/
	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < LMDD[robot_id][layer].size(); ++u)
		    {
			if (LMDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_gas_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												      mutex_occupancy_Identifiers);
		}
	    }
	}	
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector triangular_Identifiers;
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
													 sIntegerIndex(vv)));
					    }
					}
				    }
				}
				if (!triangular_Identifiers.empty())
				{
				    Clause_cnt += encoding_context.m_bit_generator->generate_MultiBiangleMutex(fw,
													       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																       sIntegerIndex(v)),
													       triangular_Identifiers);
				}
			    }
			}
		    }
		}
	    }
	}
*/
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													    sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}

	//------ alternative
	//	s_GlobalPhaseStatistics.leave_Phase();
	//	s_GlobalPhaseStatistics.leave_Phase();
    }
    

    void sMultirobotInstance::to_Memory_MddPlusPlusCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
//	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	//	s_GlobalPhaseStatistics.enter_Phase("Counting");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    encoding_context.m_bit_generator->cast_Implication(solver,
											     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
											     sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			encoding_context.m_bit_generator->cast_MultiConjunctiveImplication(solver,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
											   prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}
	if (!cardinality_Identifiers.empty())
	{
	    encoding_context.m_bit_generator->cast_Cardinality(solver, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector outgo_target_Identifiers;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    outgo_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1], sIntegerIndex(v)));
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
	    
		    encoding_context.m_bit_generator->cast_MultiImplication(solver,
											  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														  sIntegerIndex(u)),
											  outgo_target_Identifiers);
		}
		encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
												mutex_vertex_Identifiers);
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
											     mutex_vertex_Identifiers);
	}
*/
	
	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
												    mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector triangular_Identifiers;
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.begin();
				     conflict != m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.end(); ++conflict)
				{
				    for (int k = 0; k < m_robustness; ++k)
				    {
					if (layer - k >= 0)
					{
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (other_robot_id != robot_id)
						{
						    for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						    {
							if (*conflict == MDD[other_robot_id][layer - k][vv])
							{
							    triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														     sIntegerIndex(vv)));
							}
						    }
						}
					    }
					}
				    }				    
				}
				for (int k = 0; k < m_robustness; ++k)
				{
				    if (layer - k >= 0)
				    {
					for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					{
					    if (other_robot_id != robot_id)
					    {
						for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						{
						    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer - k][vv])
						    {
							triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														 sIntegerIndex(vv)));
							/*	
						        encoding_context.m_bit_generator->cast_TriangleMutex(solver,
												     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
															     sIntegerIndex(u)),
												     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
															     sIntegerIndex(v)),
												     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
															     sIntegerIndex(vv)));
							*/
						    }
						}
					    }
					}
				    }
				}
				if (!triangular_Identifiers.empty())
				{
				    encoding_context.m_bit_generator->cast_MultiBiangleMutex(solver,
											     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														     sIntegerIndex(v)),
											     triangular_Identifiers);
				    /*
				    encoding_context.m_bit_generator->cast_MultiTriangleMutex(solver,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														      sIntegerIndex(v)),
											      triangular_Identifiers);
				    */
				}
			    }
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    encoding_context.m_bit_generator->cast_BitSet(solver,
								  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
											  sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }

    
    void sMultirobotInstance::to_Memory_MddPlusPlusMutexCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
//	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	MDDMutexes_vector Mutexes;
	Mutexes.resize(N_Robots + 1);

	InverseMDD_vector inverse_MDD;
	construct_InverseMDD(N_Vertices, MDD, inverse_MDD);		
	//	s_GlobalPhaseStatistics.enter_Phase("Counting");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);

	    Mutexes[robot_id].resize(N_Layers + 1);
	    
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			encoding_context.m_bit_generator->cast_MultiConjunctiveImplication(solver,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
											   prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}
	if (!cardinality_Identifiers.empty())
	{
	    encoding_context.m_bit_generator->cast_Cardinality(solver, cardinality_Identifiers, extra_cost);
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector outgo_target_Identifiers;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    outgo_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1], sIntegerIndex(v)));
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
	    
		    encoding_context.m_bit_generator->cast_MultiImplication(solver,
									    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
												    sIntegerIndex(u)),
									    outgo_target_Identifiers);
		}
		encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										  mutex_vertex_Identifiers);
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
											     mutex_vertex_Identifiers);
	}
*/
	
	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
												    mutex_occupancy_Identifiers);
		}
	    }
	}

	ScheduledMTXs_list scheduled_Mutexes;

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{	   
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
		{
		    if (other_robot_id < robot_id)
		    {
			for (int uu = 0; uu < MDD[robot_id][layer].size(); ++uu)
			{
			    int uu_mdd_idx = inverse_MDD[other_robot_id][layer][MDD[robot_id][layer][uu]];
			    
			    if (uu_mdd_idx >= 0)
			    {
				scheduled_Mutexes.push_back(ScheduledMTX(layer, MTX_pair(MTX(robot_id, MDD[robot_id][layer][uu]), MTX(other_robot_id, MDD[other_robot_id][layer][uu_mdd_idx]))));
			    }
			}
		    }
		}
	    }
	}

	std::vector<VertexIDs_vector> vertex_neighbor_IDs;
	vertex_neighbor_IDs.resize(N_Vertices);

	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    sVertex::Neighbors_list &vertex_Neighbors = m_environment.m_Vertices[vertex_id].m_Neighbors;
	    for (sVertex::Neighbors_list::const_iterator vertex_neighbor = vertex_Neighbors.begin(); vertex_neighbor != vertex_Neighbors.end(); ++vertex_neighbor)
	    {
		vertex_neighbor_IDs[vertex_id].push_back((*vertex_neighbor)->m_target->m_id);
	    }
	    vertex_neighbor_IDs[vertex_id].push_back(vertex_id);	    
	}

	while (!scheduled_Mutexes.empty())
	{
	    const ScheduledMTX &scheduled_MTX = scheduled_Mutexes.front();	    
	    
	    int vertex_u_id = scheduled_MTX.m_mtx.first.m_vertex_id;
	    int vertex_w_id = scheduled_MTX.m_mtx.second.m_vertex_id;

	    int robot_id = scheduled_MTX.m_mtx.first.m_robot_id;
	    int other_robot_id = scheduled_MTX.m_mtx.second.m_robot_id;

	    int layer = scheduled_MTX.m_layer;
	    
	    if (layer < N_Layers)
	    {
		/*
		sVertex::Neighbors_list &u_Neighbors = m_environment.m_Vertices[vertex_u_id].m_Neighbors;
		VertexIDs_vector u_neighbor_IDs;
		for (sVertex::Neighbors_list::const_iterator u_neighbor = u_Neighbors.begin(); u_neighbor != u_Neighbors.end(); ++u_neighbor)
		{
		    u_neighbor_IDs.push_back((*u_neighbor)->m_target->m_id);
		}
		u_neighbor_IDs.push_back(vertex_u_id);
		
		sVertex::Neighbors_list &w_Neighbors = m_environment.m_Vertices[vertex_w_id].m_Neighbors;
		VertexIDs_vector w_neighbor_IDs;
		for (sVertex::Neighbors_list::const_iterator w_neighbor = w_Neighbors.begin(); w_neighbor != w_Neighbors.end(); ++w_neighbor)
		{
		    w_neighbor_IDs.push_back((*w_neighbor)->m_target->m_id);
		}
		w_neighbor_IDs.push_back(vertex_w_id);
		*/
		
		for (VertexIDs_vector::const_iterator v_neighbor = vertex_neighbor_IDs[vertex_u_id].begin(); v_neighbor != vertex_neighbor_IDs[vertex_u_id].end(); ++v_neighbor)
		{
		    sInt_32 v_mdd_idx = inverse_MDD[robot_id][layer + 1][(*v_neighbor)];
						    
		    if (v_mdd_idx >= 0)
		    {
			for (VertexIDs_vector::const_iterator z_neighbor = vertex_neighbor_IDs[vertex_w_id].begin(); z_neighbor != vertex_neighbor_IDs[vertex_w_id].end(); ++z_neighbor)
			{
			    sInt_32 z_mdd_idx = inverse_MDD[other_robot_id][layer + 1][(*z_neighbor)];
			    
			    if (z_mdd_idx >= 0)
			    {			    			    
				if (*v_neighbor < *z_neighbor)
				{
				    int vertex_v_id = *v_neighbor;
				    int vertex_z_id = *z_neighbor;

				    bool all_mutex = true;

				    /*
				    sVertex::Neighbors_list &v_Neighbors = m_environment.m_Vertices[vertex_v_id].m_Neighbors;
				    VertexIDs_vector v_neighbor_IDs;
				    for (sVertex::Neighbors_list::const_iterator v_neighbor = v_Neighbors.begin(); v_neighbor != v_Neighbors.end(); ++v_neighbor)
				    {
					v_neighbor_IDs.push_back((*v_neighbor)->m_target->m_id);
				    }
				    v_neighbor_IDs.push_back(vertex_v_id);
				    */
				    
				    for (VertexIDs_vector::const_iterator v_neighbor = vertex_neighbor_IDs[vertex_v_id].begin(); v_neighbor != vertex_neighbor_IDs[vertex_v_id].end(); ++v_neighbor)
				    {
					sInt_32 u_mdd_idx = inverse_MDD[robot_id][layer][(*v_neighbor)];
					
					if (u_mdd_idx >= 0)
					{
					    bool u_all_mutex = true;

					    /*
					    sVertex::Neighbors_list &z_Neighbors = m_environment.m_Vertices[vertex_z_id].m_Neighbors;
					    VertexIDs_vector z_neighbor_IDs;
					    for (sVertex::Neighbors_list::const_iterator z_neighbor = z_Neighbors.begin(); z_neighbor != z_Neighbors.end(); ++z_neighbor)
					    {
						z_neighbor_IDs.push_back((*z_neighbor)->m_target->m_id);
					    }
					    z_neighbor_IDs.push_back(vertex_z_id);
					    */
					    
					    for (VertexIDs_vector::const_iterator z_neighbor = vertex_neighbor_IDs[vertex_z_id].begin(); z_neighbor != vertex_neighbor_IDs[vertex_z_id].end(); ++z_neighbor)
					    {
						sInt_32 w_mdd_idx = inverse_MDD[other_robot_id][layer][(*z_neighbor)];
						
						if (w_mdd_idx >= 0)
						{
						    bool mutex_found = false;						
						    
						    if (MDD[robot_id][layer][u_mdd_idx] == MDD[other_robot_id][layer][w_mdd_idx])
						    {
							mutex_found = true;
						    }
						    else
						    {
							VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].find(MDD[robot_id][layer][u_mdd_idx]);
							
							if (mutexes_u != Mutexes[robot_id][layer].end())
							{
							    for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
							    {
								if (mutex_u->m_robot_id == other_robot_id && mutex_u->m_vertex_id == MDD[other_robot_id][layer][w_mdd_idx])
								{
								    mutex_found = true;
								    break;
								}
							    }
							}
						    }
						    if (!mutex_found)
						    {
							u_all_mutex = false;
							break;
						    }
						}
					    }
					    if (!u_all_mutex)
					    {
						all_mutex = false;
						break;
					    }
					}
				    }				    
				    if (all_mutex)
				    {
					bool next_first_mutex = Mutexes[robot_id][layer + 1][vertex_v_id].insert(Mutex(other_robot_id, vertex_z_id, z_mdd_idx, v_mdd_idx)).second;
					bool next_second_mutex = Mutexes[other_robot_id][layer + 1][vertex_z_id].insert(Mutex(robot_id, vertex_v_id, v_mdd_idx, z_mdd_idx)).second;

					if (next_first_mutex || next_second_mutex)
					{
					    scheduled_Mutexes.push_back(ScheduledMTX(layer + 1, MTX_pair(MTX(robot_id, vertex_v_id), MTX(other_robot_id, vertex_z_id))));
					}
				    }
				}	    
			    }
			}
		    }
		}
	    }
	    
	    if (layer > 0)
	    {
		/*
		sVertex::Neighbors_list &u_Neighbors = m_environment.m_Vertices[vertex_u_id].m_Neighbors;
		VertexIDs_vector u_neighbor_IDs;
		for (sVertex::Neighbors_list::const_iterator u_neighbor = u_Neighbors.begin(); u_neighbor != u_Neighbors.end(); ++u_neighbor)
		{
		    u_neighbor_IDs.push_back((*u_neighbor)->m_target->m_id);
		}
		u_neighbor_IDs.push_back(vertex_u_id);
		
		sVertex::Neighbors_list &w_Neighbors = m_environment.m_Vertices[vertex_w_id].m_Neighbors;
		VertexIDs_vector w_neighbor_IDs;
		for (sVertex::Neighbors_list::const_iterator w_neighbor = w_Neighbors.begin(); w_neighbor != w_Neighbors.end(); ++w_neighbor)
		{
		    w_neighbor_IDs.push_back((*w_neighbor)->m_target->m_id);
		}
		w_neighbor_IDs.push_back(vertex_w_id);
		*/
		
		for (VertexIDs_vector::const_iterator v_neighbor = vertex_neighbor_IDs[vertex_u_id].begin(); v_neighbor != vertex_neighbor_IDs[vertex_u_id].end(); ++v_neighbor)
		{
		    sInt_32 v_mdd_idx = inverse_MDD[robot_id][layer - 1][(*v_neighbor)];
						    
		    if (v_mdd_idx >= 0)
		    {
			for (VertexIDs_vector::const_iterator z_neighbor = vertex_neighbor_IDs[vertex_w_id].begin(); z_neighbor != vertex_neighbor_IDs[vertex_w_id].end(); ++z_neighbor)
			{
			    sInt_32 z_mdd_idx = inverse_MDD[other_robot_id][layer - 1][(*z_neighbor)];
			    
			    if (z_mdd_idx >= 0)
			    {			    			    
				if (*v_neighbor < *z_neighbor)
				{
				    int vertex_v_id = *v_neighbor;
				    int vertex_z_id = *z_neighbor;

				    bool all_mutex = true;

				    /*
				    sVertex::Neighbors_list &v_Neighbors = m_environment.m_Vertices[vertex_v_id].m_Neighbors;
				    VertexIDs_vector v_neighbor_IDs;
				    for (sVertex::Neighbors_list::const_iterator v_neighbor = v_Neighbors.begin(); v_neighbor != v_Neighbors.end(); ++v_neighbor)
				    {
					v_neighbor_IDs.push_back((*v_neighbor)->m_target->m_id);
				    }
				    v_neighbor_IDs.push_back(vertex_v_id);
				    */
				    
				    for (VertexIDs_vector::const_iterator v_neighbor = vertex_neighbor_IDs[vertex_v_id].begin(); v_neighbor != vertex_neighbor_IDs[vertex_v_id].end(); ++v_neighbor)
				    {
					sInt_32 u_mdd_idx = inverse_MDD[robot_id][layer][(*v_neighbor)];
					
					if (u_mdd_idx >= 0)
					{
					    bool u_all_mutex = true;

					    /*
					    sVertex::Neighbors_list &z_Neighbors = m_environment.m_Vertices[vertex_z_id].m_Neighbors;
					    VertexIDs_vector z_neighbor_IDs;
					    for (sVertex::Neighbors_list::const_iterator z_neighbor = z_Neighbors.begin(); z_neighbor != z_Neighbors.end(); ++z_neighbor)
					    {
						z_neighbor_IDs.push_back((*z_neighbor)->m_target->m_id);
					    }
					    z_neighbor_IDs.push_back(vertex_z_id);
					    */
					    
					    for (VertexIDs_vector::const_iterator z_neighbor = vertex_neighbor_IDs[vertex_z_id].begin(); z_neighbor != vertex_neighbor_IDs[vertex_z_id].end(); ++z_neighbor)
					    {
						sInt_32 w_mdd_idx = inverse_MDD[other_robot_id][layer][(*z_neighbor)];
						
						if (w_mdd_idx >= 0)
						{
						    bool mutex_found = false;						
						    
						    if (MDD[robot_id][layer][u_mdd_idx] == MDD[other_robot_id][layer][w_mdd_idx])
						    {
							mutex_found = true;
						    }
						    else
						    {
							VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].find(MDD[robot_id][layer][u_mdd_idx]);
							
							if (mutexes_u != Mutexes[robot_id][layer].end())
							{
							    for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
							    {
								if (mutex_u->m_robot_id == other_robot_id && mutex_u->m_vertex_id == MDD[other_robot_id][layer][w_mdd_idx])
								{
								    mutex_found = true;
								    break;
								}
							    }
							}
						    }
						    if (!mutex_found)
						    {
							u_all_mutex = false;
							break;
						    }
						}
					    }
					    if (!u_all_mutex)
					    {
						all_mutex = false;
						break;
					    }
					}
				    }				    
				    if (all_mutex)
				    {
					bool next_first_mutex = Mutexes[robot_id][layer - 1][vertex_v_id].insert(Mutex(other_robot_id, vertex_z_id, z_mdd_idx, v_mdd_idx)).second;
					bool next_second_mutex = Mutexes[other_robot_id][layer - 1][vertex_z_id].insert(Mutex(robot_id, vertex_v_id, v_mdd_idx, z_mdd_idx)).second;

					if (next_first_mutex || next_second_mutex)
					{
					    scheduled_Mutexes.push_back(ScheduledMTX(layer - 1, MTX_pair(MTX(robot_id, vertex_v_id), MTX(other_robot_id, vertex_z_id))));
					}
				    }
				}	    
			    }
			}
		    }		    
		}
	    }
	    scheduled_Mutexes.pop_front();
	}
//	printf("Now pre-summarizing ...\n");
	int N_mutexes = 0;
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{	    
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		for (VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].begin(); mutexes_u != Mutexes[robot_id][layer].end(); ++mutexes_u)
		{
		    int vertex_u_id = mutexes_u->first;

		    for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
		    {			
			int vertex_v_id = mutex_u->m_vertex_id;
			int vertex_v_idx = mutex_u->m_mdd_idx;
			int vertex_u_idx = mutex_u->m_mdd_other_idx;			
			int other_robot_id = mutex_u->m_robot_id;
			
			if (vertex_u_id < vertex_v_id)
			{
			    encoding_context.m_bit_generator->cast_Mutex(solver,
									 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
												 sIntegerIndex(vertex_u_idx)),
									 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
												 sIntegerIndex(vertex_v_idx)));
//			    printf(" 	 Mutex: at level %d - [%d, %d (%d)] x [%d, %d (%d)]\n", layer, robot_id, vertex_u_id, vertex_u_idx, other_robot_id, vertex_v_id, vertex_v_idx);
			    ++N_mutexes;
			}
		    }
		}
	    }
	}

	/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		{		    
		    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
		    {
			if (other_robot_id < robot_id)
			{
			    for (int z = 0; z < MDD[other_robot_id][layer + 1].size(); ++z)
			    {
				bool all_mutex = true;
//				printf("Checking mutex: [%d, %d, %d] and [%d, %d, %d]\n", robot_id, layer + 1, MDD[robot_id][layer + 1][v], other_robot_id, layer + 1, MDD[other_robot_id][layer + 1][z]);

				//----
				sVertex::Neighbors_list &v_Neighbors = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Neighbors;
				VertexIDs_vector v_neighbor_IDs;
				for (sVertex::Neighbors_list::const_iterator v_neighbor = v_Neighbors.begin(); v_neighbor != v_Neighbors.end(); ++v_neighbor)
				{
				    v_neighbor_IDs.push_back((*v_neighbor)->m_target->m_id);
				}
				v_neighbor_IDs.push_back(MDD[robot_id][layer + 1][v]);
				
				for (VertexIDs_vector::const_iterator v_neighbor = v_neighbor_IDs.begin(); v_neighbor != v_neighbor_IDs.end(); ++v_neighbor)
				{
				    sInt_32 u_mdd_idx = inverse_MDD[robot_id][layer][(*v_neighbor)];

				    if (u_mdd_idx >= 0)
				    {
					bool u_all_mutex = true;

					sVertex::Neighbors_list &z_Neighbors = m_environment.m_Vertices[MDD[other_robot_id][layer + 1][z]].m_Neighbors;
					VertexIDs_vector z_neighbor_IDs;
					for (sVertex::Neighbors_list::const_iterator z_neighbor = z_Neighbors.begin(); z_neighbor != z_Neighbors.end(); ++z_neighbor)
					{
					    z_neighbor_IDs.push_back((*z_neighbor)->m_target->m_id);
					}
					z_neighbor_IDs.push_back(MDD[other_robot_id][layer + 1][z]);
					
					for (VertexIDs_vector::const_iterator z_neighbor = z_neighbor_IDs.begin(); z_neighbor != z_neighbor_IDs.end(); ++z_neighbor)
					{
					    sInt_32 w_mdd_idx = inverse_MDD[other_robot_id][layer][(*z_neighbor)];
					    
					    if (w_mdd_idx >= 0)
					    {
						bool mutex_found = false;						

						if (MDD[robot_id][layer][u_mdd_idx] == MDD[other_robot_id][layer][w_mdd_idx])
						{
						    mutex_found = true;
						}
						else
						{
						    VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].find(MDD[robot_id][layer][u_mdd_idx]);
						    
						    if (mutexes_u != Mutexes[robot_id][layer].end())
						    {
							for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
							{
							    if (mutex_u->m_robot_id == other_robot_id && mutex_u->m_vertex_id == MDD[other_robot_id][layer][w_mdd_idx])
							    {
								mutex_found = true;
								break;
							    }
							}
						    }
						}
						if (!mutex_found)
						{
						    u_all_mutex = false;
						    break;
						}
					    }
					}
					if (!u_all_mutex)
					{
					    all_mutex = false;
					    break;
					}
				    }
				}
				//----
				
				//----
				for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
				{				    
				    if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
				    {
					bool u_all_mutex = true;
					
					for (int w = 0; w < MDD[other_robot_id][layer].size(); ++w)
					{
					    if (   m_environment.is_Adjacent(MDD[other_robot_id][layer][w], MDD[other_robot_id][layer + 1][z])
						|| MDD[other_robot_id][layer][w] == MDD[other_robot_id][layer + 1][z])
					    {
						bool mutex_found = false;

						if (MDD[robot_id][layer][u] == MDD[other_robot_id][layer][w])
						{
						    mutex_found = true;
						}
						else
						{
						    VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].find(MDD[robot_id][layer][u]);

						    if (mutexes_u != Mutexes[robot_id][layer].end())
						    {
							for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
							{
							    if (mutex_u->m_robot_id == other_robot_id && mutex_u->m_vertex_id == MDD[other_robot_id][layer][w])
							    {
								mutex_found = true;
								break;
							    }
							}
						    }
						}
						if (!mutex_found)
						{
						    u_all_mutex = false;
						    break;
						}
					    }					
					}
					if (!u_all_mutex)
					{
					    all_mutex = false;
					    break;
					}
				    }
				}
                                //----

				if (all_mutex)
				{
				    printf("  --> yes Mutex: [%d, %d, %d] and [%d, %d, %d]\n", robot_id, layer + 1, MDD[robot_id][layer + 1][v], other_robot_id, layer + 1, MDD[other_robot_id][layer + 1][z]);
				    Mutexes[robot_id][layer + 1][MDD[robot_id][layer + 1][v]].insert(Mutex(other_robot_id, MDD[other_robot_id][layer + 1][z], z, v));
				    Mutexes[other_robot_id][layer + 1][MDD[other_robot_id][layer + 1][z]].insert(Mutex(robot_id, MDD[robot_id][layer + 1][v], v, z));				    
				}
			    }
			}
		    }
		}
	    }
	}

	printf("Now summarizing ...\n");
	int N_mutexes = 0;
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{	    
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		for (VertexMutexes_umap::const_iterator mutexes_u = Mutexes[robot_id][layer].begin(); mutexes_u != Mutexes[robot_id][layer].end(); ++mutexes_u)
		{
		    int vertex_u_id = mutexes_u->first;

		    for (Mutexes_set::const_iterator mutex_u = mutexes_u->second.begin(); mutex_u != mutexes_u->second.end(); ++mutex_u)
		    {			
			int vertex_v_id = mutex_u->m_vertex_id;
			int vertex_v_idx = mutex_u->m_mdd_idx;
			int vertex_u_idx = mutex_u->m_mdd_other_idx;			
			int other_robot_id = mutex_u->m_robot_id;
			if (vertex_u_id < vertex_v_id)
			{
			    encoding_context.m_bit_generator->cast_Mutex(solver,
									 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
												 sIntegerIndex(vertex_u_idx)),
									 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
												 sIntegerIndex(vertex_v_idx)));
			    printf(" 	 Mutex: at level %d - [%d, %d (%d)] x [%d, %d (%d)]\n", layer, robot_id, vertex_u_id, vertex_u_idx, other_robot_id, vertex_v_id, vertex_v_idx);
			    ++N_mutexes;
			}
		    }
		}
	    }
	}
	printf("Mutexes found in total: %d\n", N_mutexes);
	*/
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector triangular_Identifiers;
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.begin();
				     conflict != m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.end(); ++conflict)
				{
				    for (int k = 0; k < m_robustness; ++k)
				    {
					if (layer - k >= 0)
					{
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (other_robot_id != robot_id)
						{
						    for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						    {
							if (*conflict == MDD[other_robot_id][layer - k][vv])
							{
							    triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														     sIntegerIndex(vv)));
							}
						    }
						}
					    }
					}
				    }				    
				}
				for (int k = 0; k < m_robustness; ++k)
				{
				    if (layer - k >= 0)
				    {
					for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					{
					    if (other_robot_id != robot_id)
					    {
						for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						{
						    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer - k][vv])
						    {
							triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														 sIntegerIndex(vv)));
							/*	
						        encoding_context.m_bit_generator->cast_TriangleMutex(solver,
												     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
															     sIntegerIndex(u)),
												     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
															     sIntegerIndex(v)),
												     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
															     sIntegerIndex(vv)));
							*/
						    }
						}
					    }
					}
				    }
				}
				if (!triangular_Identifiers.empty())
				{
				    encoding_context.m_bit_generator->cast_MultiBiangleMutex(solver,
											     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														     sIntegerIndex(v)),
											     triangular_Identifiers);
				    /*
				    encoding_context.m_bit_generator->cast_MultiTriangleMutex(solver,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														      sIntegerIndex(v)),
											      triangular_Identifiers);
				    */
				}
			    }
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    encoding_context.m_bit_generator->cast_BitSet(solver,
								  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
											  sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }    


    void sMultirobotInstance::to_Memory_MddPlusPlusFuelCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, int sUNUSED(extra_fuel), int mdd_depth, const MDD_vector &MDD, const MDD_vector &sUNUSED(extra_MDD), const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
//	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	//	s_GlobalPhaseStatistics.enter_Phase("Counting");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								  "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								  sIntegerScope(0, 0));
		encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);
		
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]))
			{
			    encoding_context.m_bit_generator->cast_Bimplication(solver,
										sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
										sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1], sIntegerIndex(v)),
										sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
	    }
	}
	if (!cardinality_Identifiers.empty())
	{
	    encoding_context.m_bit_generator->cast_Cardinality(solver, cardinality_Identifiers, encoding_context.m_max_total_fuel);
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector outgo_target_Identifiers;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    outgo_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1], sIntegerIndex(v)));
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
	    
		    encoding_context.m_bit_generator->cast_MultiImplication(solver,
											  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														  sIntegerIndex(u)),
											  outgo_target_Identifiers);
		}
		encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
												mutex_vertex_Identifiers);
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
											     mutex_vertex_Identifiers);
	}
*/
	
	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										      mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector triangular_Identifiers;
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.begin();
				     conflict != m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.end(); ++conflict)
				{
				    for (int k = 0; k < m_robustness; ++k)
				    {
					if (layer - k >= 0)
					{
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (other_robot_id != robot_id)
						{
						    for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						    {
							if (*conflict == MDD[other_robot_id][layer - k][vv])
							{
							    triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														     sIntegerIndex(vv)));
							}
						    }
						}
					    }
					}
				    }				    
				}
				for (int k = 0; k < m_robustness; ++k)
				{
				    if (layer - k >= 0)
				    {
					for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					{
					    if (other_robot_id != robot_id)
					    {
						for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						{
						    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer - k][vv])
						    {
							triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														 sIntegerIndex(vv)));
							/*	
						        encoding_context.m_bit_generator->cast_TriangleMutex(solver,
												     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
															     sIntegerIndex(u)),
												     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
															     sIntegerIndex(v)),
												     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
															     sIntegerIndex(vv)));
							*/
						    }
						}
					    }
					}
				    }
				}
				if (!triangular_Identifiers.empty())
				{
				    encoding_context.m_bit_generator->cast_MultiBiangleMutex(solver,
											     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														     sIntegerIndex(v)),
											     triangular_Identifiers);
				    /*
				    encoding_context.m_bit_generator->cast_MultiTriangleMutex(solver,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														      sIntegerIndex(v)),
											      triangular_Identifiers);
				    */
				}
			    }
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    encoding_context.m_bit_generator->cast_BitSet(solver,
								  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
											  sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }        


    void sMultirobotInstance::to_Memory_LMddPlusPlusCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, int extra_cost, int mdd_depth, const MDD_vector &MDD, const MDD_vector &LMDD, const MDD_vector &extra_MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = mdd_depth;

	MDDIndices_vector LMDD_Indices;
	construct_MDDIndices(LMDD, LMDD_Indices);	

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
	encoding_context.m_vertex_occupancy_by_gas_.resize(N_Robots + 1);	
	encoding_context.m_vertex_water_cardinality_.resize(N_Robots + 1);
//	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	//	s_GlobalPhaseStatistics.enter_Phase("Counting");

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    encoding_context.m_vertex_occupancy_by_gas_[robot_id].resize(N_Layers + 1);	    
	    encoding_context.m_vertex_water_cardinality_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);

		sIndexableBitIdentifier vertex_occupancy_by_gas_(&encoding_context.m_variable_store,
								 "vertex_occupancy_by_gas-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								 sIntegerScope(0, LMDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_gas_[robot_id][layer] = vertex_occupancy_by_gas_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_gas_[robot_id][layer]);				

		if (!extra_MDD[robot_id][layer].empty())
		{
		    sASSERT(extra_MDD[robot_id][layer].size() == 1);

		    sIndexableBitIdentifier vertex_water_cardinality_(&encoding_context.m_variable_store,
								      "vertex_water_cardinality-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								      sIntegerScope(0, 0));
		    encoding_context.m_vertex_water_cardinality_[robot_id][layer] = vertex_water_cardinality_;
		    encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_water_cardinality_[robot_id][layer]);

		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (extra_MDD[robot_id][layer][0] != MDD[robot_id][layer][u])
			{
			    encoding_context.m_bit_generator->cast_Implication(solver,
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
									       sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
			}
		    }
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector prev_cardinality_Identifiers;

		    for (int prev_layer = 0; prev_layer < layer; ++prev_layer)
		    {
			if (!extra_MDD[robot_id][prev_layer].empty())
			{
			    prev_cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][prev_layer], sIntegerIndex(0)));
			}
		    }
		    if (!prev_cardinality_Identifiers.empty())
		    {
			encoding_context.m_bit_generator->cast_MultiConjunctiveImplication(solver,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)),
											   prev_cardinality_Identifiers);
		    }
		}
	    }
	}

	sBitClauseGenerator::SpecifiedBitIdentifiers_vector cardinality_Identifiers;
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		if (!extra_MDD[robot_id][layer].empty())
		{
		    cardinality_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_water_cardinality_[robot_id][layer], sIntegerIndex(0)));
		}
	    }
	}
	if (!cardinality_Identifiers.empty())
	{
	    encoding_context.m_bit_generator->cast_Cardinality(solver, cardinality_Identifiers, extra_cost);
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector gas_displacement_Identifiers;			
		    int robot_size = m_initial_arrangement.m_robot_Sizes[robot_id];

		    for (int dr = 0; dr < robot_size; ++dr)
		    {
			for (int dc = 0; dc < robot_size; ++dc)
			{
			    int next_vertex_id = m_environment.get_GridNeighborVertexID(MDD[robot_id][layer][u], dr, dc);
			    if (next_vertex_id >= 0)
			    {
				int mdd_index = LMDD_Indices[robot_id][layer][next_vertex_id];
				gas_displacement_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_gas_[robot_id][layer], sIntegerIndex(mdd_index)));
			    }
			}
		    }
		    encoding_context.m_bit_generator->cast_MultiConjunctiveImplication(solver,
										       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)),
										       gas_displacement_Identifiers);
		}
	    }
	}		
	
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector outgo_target_Identifiers;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    outgo_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1], sIntegerIndex(v)));
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
	    
		    encoding_context.m_bit_generator->cast_MultiImplication(solver,
									    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
												    sIntegerIndex(u)),
									    outgo_target_Identifiers);
		}
		encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										  mutex_vertex_Identifiers);
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
											     mutex_vertex_Identifiers);
	}
*/
	
	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < LMDD[robot_id][layer].size(); ++u)
		    {
			if (LMDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_gas_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										      mutex_occupancy_Identifiers);
		}
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector triangular_Identifiers;
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
				{
				    if (other_robot_id != robot_id)
				    {
					for (int vv = 0; vv < MDD[other_robot_id][layer].size(); ++vv)
					{
					    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer][vv])
					    {
						triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
													 sIntegerIndex(vv)));
					    }
					}
				    }
				}
				if (!triangular_Identifiers.empty())
				{
				    encoding_context.m_bit_generator->cast_MultiBiangleMutex(solver,
											     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														     sIntegerIndex(v)),
											     triangular_Identifiers);
				}
			    }
			}
		    }
		}
	    }
	}
*/
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    encoding_context.m_bit_generator->cast_BitSet(solver,
								  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
											  sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
								      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
											      sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }    
    

    void sMultirobotInstance::to_Stream_MmddPlusPlusCNFsat(FILE *fw, sMultirobotEncodingContext_CNFsat &encoding_context, const MDD_vector &MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int Clause_cnt = 0;
	int aux_Variable_cnt = 0;
	int total_Literal_cnt = 0;

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = encoding_context.m_N_Layers;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
//	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);
	    }
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector outgo_target_Identifiers;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    outgo_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1], sIntegerIndex(v)));
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    Clause_cnt += encoding_context.m_bit_generator->count_MultiImplication(aux_Variable_cnt,
											   total_Literal_cnt,
											   sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														   sIntegerIndex(u)),
											   outgo_target_Identifiers);
		}
		Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
											       total_Literal_cnt,
											       mutex_vertex_Identifiers);
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
											   total_Literal_cnt,
											   mutex_vertex_Identifiers);
	}
*/
	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_AdaptiveAllMutexConstraint(aux_Variable_cnt,
												   total_Literal_cnt,
												   mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector triangular_Identifiers;
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.begin();
				     conflict != m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.end(); ++conflict)
				{
				    for (int k = 0; k < m_robustness; ++k)
				    {
					if (layer - k >= 0)
					{
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (other_robot_id != robot_id)
						{
						    for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						    {
							if (*conflict == MDD[other_robot_id][layer - k][vv])
							{
							    triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														     sIntegerIndex(vv)));
							}
						    }
					    }
					    }
					}
				    }				    
				}				
				for (int k = 0; k < m_robustness; ++k)
				{
				    if (layer - k >= 0)
				    {
					for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					{
					    if (other_robot_id != robot_id)
					    {
						for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						{
						    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer - k][vv])
						    {
							triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														 sIntegerIndex(vv)));
							/*
							Clause_cnt += encoding_context.m_bit_generator->count_TriangleMutex(aux_Variable_cnt,
															    total_Literal_cnt,
															    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
																		    sIntegerIndex(u)),
															    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																		    sIntegerIndex(v)),
															    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																		    sIntegerIndex(vv)));
							*/							
						    }
						}
					    }
					}
				    }
				}
				if (!triangular_Identifiers.empty())
				{
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiBiangleMutex(aux_Variable_cnt,
													    total_Literal_cnt,
													    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																    sIntegerIndex(v)),
													    triangular_Identifiers);				    
/*				    
				    Clause_cnt += encoding_context.m_bit_generator->count_MultiTriangleMutex(aux_Variable_cnt,
													     total_Literal_cnt,
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
																     sIntegerIndex(u)),
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																     sIntegerIndex(v)),
													     triangular_Identifiers);
*/
				}
			    }
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										 total_Literal_cnt,
										 sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													 sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->count_BitSet(aux_Variable_cnt,
										     total_Literal_cnt,
										     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													     sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}

	int N_cnf_Variables = encoding_context.m_variable_store.get_Last_CNFVariable() + aux_Variable_cnt - 1;

#ifdef sDEBUG
	fprintf(fw, "c %s : multirobot MMDD++ SAT encoding\n", sPRODUCT);
	fprintf(fw, "c %s\n", sCOPYRIGHT);
	fprintf(fw, "c number of layers = %d\n", N_Layers);
	fprintf(fw, "c number of visible variables = %d\n", N_cnf_Variables - aux_Variable_cnt);
	fprintf(fw, "c number of hidden variables = %d\n", aux_Variable_cnt);
	fprintf(fw, "c number of literals = %d\n", total_Literal_cnt);
	fprintf(fw, "c number of clauses = %d\n", Clause_cnt);
	fprintf(fw, "c number of propositional variables = %d\n", N_cnf_Variables);
	fprintf(fw, "c number of clauses / number of variables = %.3f\n", (double)Clause_cnt / N_cnf_Variables);
	fprintf(fw, "c number of literals / number of clauses = %.3f\n", (double)total_Literal_cnt /  Clause_cnt);
	to_Stream(fw, "c ");
#endif
	fprintf(fw, "p cnf %d %d\n", N_cnf_Variables, Clause_cnt);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector outgo_target_Identifiers;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    outgo_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1], sIntegerIndex(v)));

			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));		    
	    
		    Clause_cnt += encoding_context.m_bit_generator->generate_MultiImplication(fw,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      outgo_target_Identifiers);
		}
		
		Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
												    mutex_vertex_Identifiers);
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
											      mutex_vertex_Identifiers);
	}
*/
	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_AdaptiveAllMutexConstraint(fw,
													mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector triangular_Identifiers;			    
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.begin();
				     conflict != m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.end(); ++conflict)
				{
				    for (int k = 0; k < m_robustness; ++k)
				    {
					if (layer - k >= 0)
					{
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (other_robot_id != robot_id)
						{
						    for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						    {
							if (*conflict == MDD[other_robot_id][layer - k][vv])
							{
							    triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														     sIntegerIndex(vv)));
							}
						    }
						}					    
					    }
					}
				    }				    
				}
				for (int k = 0; k < m_robustness; ++k)
				{
				    if (layer - k >= 0)
				    {
					for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					{
					    if (other_robot_id != robot_id)
					    {
						for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						{
						    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer - k][vv])
						    {
							triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														 sIntegerIndex(vv)));
						/*
						Clause_cnt += encoding_context.m_bit_generator->generate_TriangleMutex(fw,
														       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
																	       sIntegerIndex(u)),
														       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																	       sIntegerIndex(v)),
														       sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																	       sIntegerIndex(vv)));
						*/
						    }
						}
					    }					    
					}
				    }
				}
				if (!triangular_Identifiers.empty())
				{
				    Clause_cnt += encoding_context.m_bit_generator->generate_MultiBiangleMutex(fw,
														sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																	sIntegerIndex(v)),
														triangular_Identifiers);				    
				    /*
				    Clause_cnt += encoding_context.m_bit_generator->generate_MultiTriangleMutex(fw,
														sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
																	sIntegerIndex(u)),
														sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																	sIntegerIndex(v)),
														triangular_Identifiers);
				    */
				}				    
			    }
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
													    sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			Clause_cnt += encoding_context.m_bit_generator->generate_BitSet(fw,
											sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
														sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }


    void sMultirobotInstance::to_Memory_MmddPlusPlusCNFsat(Glucose::Solver *solver, sMultirobotEncodingContext_CNFsat &encoding_context, const MDD_vector &MDD, const sString &sUNUSED(indent), bool sUNUSED(verbose))
    {
	encoding_context.switchTo_AdvancedGeneratingMode();	

	int N_Vertices = m_environment.get_VertexCount();
	int N_Robots = m_initial_arrangement.get_RobotCount();
	int N_Layers = encoding_context.m_N_Layers;

	encoding_context.m_vertex_occupancy_by_water_.resize(N_Robots + 1);
//	encoding_context.m_edge_occupancy_by_water__.resize(N_Robots + 1);

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    encoding_context.m_vertex_occupancy_by_water_[robot_id].resize(N_Layers + 1);
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sIndexableBitIdentifier vertex_occupancy_by_water_(&encoding_context.m_variable_store,
								   "vertex_occupancy_by_water-" + sInt_32_to_String(robot_id) + "_" + sInt_32_to_String(layer),
								   sIntegerScope(0, MDD[robot_id][layer].size() - 1));
		encoding_context.m_vertex_occupancy_by_water_[robot_id][layer] = vertex_occupancy_by_water_;
		encoding_context.register_TranslateIdentifier(encoding_context.m_vertex_occupancy_by_water_[robot_id][layer]);
	    }
	}


	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;

		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    sBitClauseGenerator::SpecifiedBitIdentifiers_vector outgo_target_Identifiers;

		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    outgo_target_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1], sIntegerIndex(v)));
			}
		    }
		    mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));	
	    
		    encoding_context.m_bit_generator->cast_MultiImplication(solver,
											  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														  sIntegerIndex(u)),
											  outgo_target_Identifiers);
		}
		encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
												mutex_vertex_Identifiers);
	    }
	}
/*
	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_vertex_Identifiers;
		    
	    for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
	    {
		mutex_vertex_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers], sIntegerIndex(u)));
	    }
	    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
											   mutex_vertex_Identifiers);
	}
*/
	for (int vertex_id = 0; vertex_id < N_Vertices; ++vertex_id)
	{
	    for (int layer = 0; layer <= N_Layers; ++layer)
	    {
		sBitClauseGenerator::SpecifiedBitIdentifiers_vector mutex_occupancy_Identifiers;

		for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
		{
		    for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		    {
			if (MDD[robot_id][layer][u] == vertex_id)
			{
			    mutex_occupancy_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer], sIntegerIndex(u)));
			}
		    }
		}
		if (mutex_occupancy_Identifiers.size() > 1)
		{
		    encoding_context.m_bit_generator->cast_AdaptiveAllMutexConstraint(solver,
										      mutex_occupancy_Identifiers);
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int layer = 0; layer < N_Layers; ++layer)
	    {
		for (int u = 0; u < MDD[robot_id][layer].size(); ++u)
		{
		    for (int v = 0; v < MDD[robot_id][layer + 1].size(); ++v)
		    {
			if (m_environment.is_Adjacent(MDD[robot_id][layer][u], MDD[robot_id][layer + 1][v]) || MDD[robot_id][layer][u] == MDD[robot_id][layer + 1][v])
			{
			    sBitClauseGenerator::SpecifiedBitIdentifiers_vector triangular_Identifiers;
			    if (MDD[robot_id][layer][u] != MDD[robot_id][layer + 1][v])
			    {
				for (sVertex::VertexIDs_vector::const_iterator conflict = m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.begin();
				     conflict != m_environment.m_Vertices[MDD[robot_id][layer + 1][v]].m_Conflicts.end(); ++conflict)
				{
				    for (int k = 0; k < m_robustness; ++k)
				    {
					if (layer - k >= 0)
					{
					    for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					    {
						if (other_robot_id != robot_id)
						{
						    for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						    {
							if (*conflict == MDD[other_robot_id][layer - k][vv])
							{
							    triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														     sIntegerIndex(vv)));
							}
						    }
						}
					    }
					}
				    }				    
				}
				for (int k = 0; k < m_robustness; ++k)
				{
				    if (layer - k >= 0)
				    {
					for (int other_robot_id = 1; other_robot_id <= N_Robots; ++other_robot_id)
					{
					    if (other_robot_id != robot_id)
					    {
						for (int vv = 0; vv < MDD[other_robot_id][layer - k].size(); ++vv)
						{
						    if (MDD[robot_id][layer + 1][v] == MDD[other_robot_id][layer - k][vv])
						    {
							triangular_Identifiers.push_back(sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer - k],
														 sIntegerIndex(vv)));
							/*
							encoding_context.m_bit_generator->cast_TriangleMutex(solver,
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
																     sIntegerIndex(u)),
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
																     sIntegerIndex(v)),								   
													     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[other_robot_id][layer],
																     sIntegerIndex(vv)));
							*/
						    }
						}
					    }
					}
				    }
				}
				if (!triangular_Identifiers.empty())
				{
				    encoding_context.m_bit_generator->cast_MultiBiangleMutex(solver,
											     sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														     sIntegerIndex(v)),
											     triangular_Identifiers);				    
				    /*
				    encoding_context.m_bit_generator->cast_MultiTriangleMutex(solver,
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer],
														      sIntegerIndex(u)),
											      sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][layer + 1],
														      sIntegerIndex(v)),
											      triangular_Identifiers);
				    */
				}
			    }
			}
		    }
		}
	    }
	}

	for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	{
	    for (int u = 0; u < MDD[robot_id][0].size(); ++u)
	    {
		if (MDD[robot_id][0][u] == m_initial_arrangement.get_RobotLocation(robot_id))
		{
		    encoding_context.m_bit_generator->cast_BitSet(solver,
								  sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][0],
											  sIntegerIndex(u)));
		}
	    }
	}
	switch (m_goal_type)
	{
	case GOAL_TYPE_ARRANGEMENT:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    if (MDD[robot_id][N_Layers][u] == m_goal_arrangement.get_RobotLocation(robot_id))
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													    sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	case GOAL_TYPE_SPECIFICATION:
	{
	    for (int robot_id = 1; robot_id <= N_Robots; ++robot_id)
	    {
		for (int u = 0; u < MDD[robot_id][N_Layers].size(); ++u)
		{
		    sASSERT(m_goal_specification.get_RobotGoal(robot_id).size() == 1);

		    if (MDD[robot_id][N_Layers][u] == *m_goal_specification.get_RobotGoal(robot_id).begin())
		    {
			encoding_context.m_bit_generator->cast_BitSet(solver,
										    sSpecifiedBitIdentifier(&encoding_context.m_vertex_occupancy_by_water_[robot_id][N_Layers],
													    sIntegerIndex(u)));
		    }
		}
	    }
	    break;
	}
	default:
	{
	    sASSERT(false);
	    break;
	}
	}
    }
    
    
/*----------------------------------------------------------------------------*/

} // namespace sReloc
#endif
