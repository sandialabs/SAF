/*
 * Copyright(C) 1999 The Regents of the University of California.
 *     This work  was produced, in  part, at the  University of California, Lawrence Livermore National
 *     Laboratory    (UC LLNL)  under    contract number   W-7405-ENG-48 (Contract    48)   between the
 *     U.S. Department of Energy (DOE) and The Regents of the University of California (University) for
 *     the  operation of UC LLNL.  Copyright  is reserved to  the University for purposes of controlled
 *     dissemination, commercialization  through formal licensing, or other  disposition under terms of
 *     Contract 48; DOE policies, regulations and orders; and U.S. statutes.  The rights of the Federal
 *     Government  are reserved under  Contract 48 subject  to the restrictions agreed  upon by DOE and
 *     University.
 * 
 * Copyright(C) 1999 Sandia Corporation.
 *     Under terms of Contract DE-AC04-94AL85000, there is a non-exclusive license for use of this work
 *     on behalf of the U.S. Government.  Export  of this program may require a license from the United
 *     States Government.
 * 
 * Disclaimer:
 *     This document was  prepared as an account of  work sponsored by an agency  of  the United States
 *     Government. Neither the United States  Government nor the United States Department of Energy nor 
 *     the  University  of  California  nor  Sandia  Corporation nor any  of their employees  makes any 
 *     warranty, expressed  or  implied, or  assumes   any  legal liability  or responsibility  for the 
 *     accuracy,  completeness,  or  usefulness  of  any  information, apparatus,  product,  or process 
 *     disclosed,  or  represents that its  use would   not infringe  privately owned rights. Reference 
 *     herein  to any  specific commercial  product,  process,  or  service by  trade  name, trademark, 
 *     manufacturer,  or  otherwise,  does  not   necessarily  constitute  or  imply  its  endorsement, 
 *     recommendation, or favoring by the  United States Government   or the University of  California.  
 *     The views and opinions of authors expressed herein do not necessarily state  or reflect those of
 *     the  United  States Government or  the   University of California   and shall  not be  used  for
 *     advertising or product endorsement purposes.
 * 
 * Authors:
 * 	William J. Arrighi	LLNL
 * 	Peter K. Espen		SNL
 * 	Ray T. Hitt 		SNL
 * 	Robb P. Matzke 		LLNL
 * 	Mark C. Miller 		LLNL
 * 	James F. Reus 		LLNL
 * 	Larry A. Schoof 	SNL
 * 
 * Acknowledgements:
 * 	Marty L. Barnaby	SNL - Red parallel perf. study/tuning
 * 	David M. Butler		LPS - Data model design/implementation Spec.
 * 	Albert K. Cheng		NCSA - Parallel HDF5 support
 * 	Nancy Collins		IBM - Alpha/Beta user
 * 	Linnea M. Cook		LLNL - Management advocate
 * 	Michael J. Folk		NCSA - Management advocate 
 * 	Richard M. Hedges	LLNL - Blue-Pacific parallel perf. study/tuning 
 * 	Quincey A. Koziol	NCSA - Serial HDF5 Support 
 * 	Celeste M. Matarazzo	LLNL - Management advocate
 * 	Tom H. Robey 		SNL - Early developer
 * 	Greg D. Sjaardema	SNL - Alpha/Beta user
 * 	Reinhard W. Stotzer	SNL - Early developer
 * 	Judy Sturtevant		SNL - Red parallel perf. study/tuning 
 * 	Robert K. Yates		LLNL - Blue-Pacific parallel perf. study/tuning
 * 
 */
/*-------------------------------------------------------------------------- - -
|
|       globals.c
|
|       This file contains C/ANSI-C code used to implement an exception
|       handling mechanism.  The following functions are provided...
|
|
|               except_t *except_stack;
|
|           This global variable points to the topmost exception
|           catching packet on the stack.  Note that catching
|           packets are not allocated via malloc but are created
|           by the C compiler as automatic variables (on the stack)
|           within the scope started by the except_try macro and
|           terminated by the except_end macro.
|
|
|               char except_theDepth[1];
|
|           This global variable is used in the computation of try
|           nesting depth.  See the except_try macro in except.h for
|           the clever scheme used to determine nesting depth.  Basically
|           the except_try macro defines a new (automatic) array named
|           except_theDepth whose size is 1 greater than the currently
|           visible except_theDepth array.
|
|
|               char except_tag[except_seg_outside];
|
|           This global variable is used to dermine the nature of the
|           scope.  This variable will be masked by other definitions
|           where the size may be different.  The size of the visible
|           definition indicates which section: outsize, in try section
|           or in a catch section.
|
+--------------------------------------------------------------------------- - -
|
|       Author:
|
|           Dr. James F. Reus, Lawrence Livermore National Laboratory
|
|           This work is based on previous work outside the Laboratory
|           and the University of California by the author and has been
|           released to the Laboratory and the University of California
|           for free distribution only.  The author makes no
|           representations as to the suitability and operability of
|           this software for any purpose whatsoever.  It is provided
|           "as is" without express or implied warranty.  This software
|           is distributed in the hope that it will be useful, but
|           WITHOUT ANY WARRANTY; without even the implied warranty
|           of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
| */

#include <except.h>

char      except_tag[except_seg_outside];
char      except_staticDepth[1];
except_t *except_stack = 0;

