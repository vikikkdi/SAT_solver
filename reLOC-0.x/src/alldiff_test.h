/*============================================================================*/
/*                                                                            */
/*                                                                            */
/*                              reLOC 0.20-kruh                               */
/*                                                                            */
/*                      (C) Copyright 2019 Pavel Surynek                      */
/*                http://www.surynek.com | <pavel@surynek.com>                */
/*                                                                            */
/*                                                                            */
/*============================================================================*/
<<<<<<< HEAD
/* alldiff_test.h / 0.20-kruh_055                                             */
=======
/* alldiff_test.h / 0.20-kruh_051                                             */
>>>>>>> fa5fdfe3b98f4658d47e231f3f04e086da930ff8
/*----------------------------------------------------------------------------*/
//
// Dimacs CNF production tools - testing program.
//
/*----------------------------------------------------------------------------*/


#ifndef __ALLDIFF_TEST_H__
#define __ALLDIFF_TEST_H__

#include "reloc.h"

using namespace sReloc;


/*----------------------------------------------------------------------------*/

namespace sReloc
{


/*----------------------------------------------------------------------------*/

    void test_all_different_Standard(int N_Variables, int N_States, int range_size);
    void test_all_different_Bijection(int N_Variables, int N_States, int range_size);

    
/*----------------------------------------------------------------------------*/

} // namespace sReloc


#endif /* __ALLDIFF_TEST_H__ */
